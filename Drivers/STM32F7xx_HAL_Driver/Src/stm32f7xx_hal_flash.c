 


#include "stm32f7xx_hal.h"





#ifdef HAL_FLASH_MODULE_ENABLED




#define SECTOR_MASK               ((uint32_t)0xFFFFFF07U)
#define FLASH_TIMEOUT_VALUE       ((uint32_t)50000U)
         




FLASH_ProcessTypeDef pFlash;





static void   FLASH_Program_DoubleWord(uint32_t Address, uint64_t Data);
static void   FLASH_Program_Word(uint32_t Address, uint32_t Data);
static void   FLASH_Program_HalfWord(uint32_t Address, uint16_t Data);
static void   FLASH_Program_Byte(uint32_t Address, uint8_t Data);
static void   FLASH_SetErrorCode(void);

HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout);




  



HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  
  
  __HAL_LOCK(&pFlash);

  
  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));

  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    switch(TypeProgram)
    {
      case FLASH_TYPEPROGRAM_BYTE :
      {
        
        FLASH_Program_Byte(Address, (uint8_t) Data);
        break;
      }
      
      case FLASH_TYPEPROGRAM_HALFWORD :
      {
        
        FLASH_Program_HalfWord(Address, (uint16_t) Data);
        break;
      }
      
      case FLASH_TYPEPROGRAM_WORD :
      {
        
        FLASH_Program_Word(Address, (uint32_t) Data);
        break;
      }
      
      case FLASH_TYPEPROGRAM_DOUBLEWORD :
      {
        
        FLASH_Program_DoubleWord(Address, Data);
        break;
      }
      default :
        break;
    }
    
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
    
    
    FLASH->CR &= (~FLASH_CR_PG);
  }

  
  __HAL_UNLOCK(&pFlash);

  return status;
}


HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  __HAL_LOCK(&pFlash);

  
  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));

  
  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP);
  
  
  __HAL_FLASH_ENABLE_IT(FLASH_IT_ERR);
  
    
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP    | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |\
                         FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR| FLASH_FLAG_ERSERR);  

  pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAM;
  pFlash.Address = Address;
  
  switch(TypeProgram)
  {
    case FLASH_TYPEPROGRAM_BYTE :
    {
      
      FLASH_Program_Byte(Address, (uint8_t) Data);
      break;
    }
    
    case FLASH_TYPEPROGRAM_HALFWORD :
    {
      
      FLASH_Program_HalfWord(Address, (uint16_t) Data);
      break;
    }
    
    case FLASH_TYPEPROGRAM_WORD :
    {
      
      FLASH_Program_Word(Address, (uint32_t) Data);
      break;
    }
    
    case FLASH_TYPEPROGRAM_DOUBLEWORD :
    {
      
      FLASH_Program_DoubleWord(Address, Data);
      break;
    }
    default :
      break;
  }
  return status;
}


void HAL_FLASH_IRQHandler(void)
{
  uint32_t temp = 0;
  
  
  FLASH->CR &= (~FLASH_CR_PG);

  
  FLASH->CR &= (~FLASH_CR_SER);
  FLASH->CR &= SECTOR_MASK; 

  
  FLASH->CR &= (~FLASH_MER_BIT);

  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP) != RESET)
  {
    
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
    
    switch (pFlash.ProcedureOnGoing)
    {
      case FLASH_PROC_SECTERASE :
      {
        
        pFlash.NbSectorsToErase--;

        
        if(pFlash.NbSectorsToErase != 0)
        {
          temp = pFlash.Sector;
          
          HAL_FLASH_EndOfOperationCallback(temp);

          
          temp = ++pFlash.Sector;
          FLASH_Erase_Sector(temp, pFlash.VoltageForErase);
        }
        else
        {
          
          
          pFlash.Sector = temp = 0xFFFFFFFFU;
          
          HAL_FLASH_EndOfOperationCallback(temp);
          
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
        break;
      }
    
      case FLASH_PROC_MASSERASE :
      {
        
        
        HAL_FLASH_EndOfOperationCallback(0);
        
        pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        break;
      }

      case FLASH_PROC_PROGRAM :
      {
        
        
        HAL_FLASH_EndOfOperationCallback(pFlash.Address);
        
        pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        break;
      }
      default :
        break;
    }
  }
  
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_ALL_ERRORS) != RESET)
  {
    switch (pFlash.ProcedureOnGoing)
    {
      case FLASH_PROC_SECTERASE :
      {
        
        temp = pFlash.Sector;
        pFlash.Sector = 0xFFFFFFFFU;
        break;
      }
      case FLASH_PROC_MASSERASE :
      {
        
        temp = 0;
        break;
      }
      case FLASH_PROC_PROGRAM :
      {
        
        temp = pFlash.Address;
        break;
      }
    default :
      break;
    }
    
    FLASH_SetErrorCode();

    
    HAL_FLASH_OperationErrorCallback(temp);

    
    pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
  }
  
  if(pFlash.ProcedureOnGoing == FLASH_PROC_NONE)
  {
    
    __HAL_FLASH_DISABLE_IT(FLASH_IT_EOP);

    
    __HAL_FLASH_DISABLE_IT(FLASH_IT_ERR);

    
    __HAL_UNLOCK(&pFlash);
  }
  
}


__weak void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue)
{
  
  UNUSED(ReturnValue);
   
}


__weak void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{
  
  UNUSED(ReturnValue);
   
}






HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
  {
    
    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR, FLASH_KEY2);

    
    if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }

  return status;
}


HAL_StatusTypeDef HAL_FLASH_Lock(void)
{
  
  FLASH->CR |= FLASH_CR_LOCK;
  
  return HAL_OK;  
}


HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void)
{
  if((FLASH->OPTCR & FLASH_OPTCR_OPTLOCK) != RESET)
  {
    
    FLASH->OPTKEYR = FLASH_OPT_KEY1;
    FLASH->OPTKEYR = FLASH_OPT_KEY2;
  }
  else
  {
    return HAL_ERROR;
  }  
  
  return HAL_OK;  
}


HAL_StatusTypeDef HAL_FLASH_OB_Lock(void)
{
  
  FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK;
  
  return HAL_OK;  
}


HAL_StatusTypeDef HAL_FLASH_OB_Launch(void)
{
  
  FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;

  
  return(FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE)); 
}






uint32_t HAL_FLASH_GetError(void)
{ 
   return pFlash.ErrorCode;
}  
  
    


HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout)
{ 
  uint32_t tickstart = 0;
  
  
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;
  
  
  
  tickstart = HAL_GetTick();

  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY) != RESET) 
  { 
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    } 
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_ALL_ERRORS) != RESET)
  {
    
    FLASH_SetErrorCode();
    return HAL_ERROR;
  }
  
  
  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP) != RESET)
  {
    
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
  }

  
  return HAL_OK;
  
}  


static void FLASH_Program_DoubleWord(uint32_t Address, uint64_t Data)
{
  
  assert_param(IS_FLASH_ADDRESS(Address));
  
  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= FLASH_PSIZE_DOUBLE_WORD;
  FLASH->CR |= FLASH_CR_PG;

  
  *(__IO uint32_t*)Address = (uint32_t)Data;
  
  __ISB();

  
  *(__IO uint32_t*)(Address+4) = (uint32_t)(Data >> 32);

  
  __DSB();
}



static void FLASH_Program_Word(uint32_t Address, uint32_t Data)
{
  
  assert_param(IS_FLASH_ADDRESS(Address));
  
  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= FLASH_PSIZE_WORD;
  FLASH->CR |= FLASH_CR_PG;

  *(__IO uint32_t*)Address = Data;
  
  
  __DSB();
}


static void FLASH_Program_HalfWord(uint32_t Address, uint16_t Data)
{
  
  assert_param(IS_FLASH_ADDRESS(Address));
  
  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= FLASH_PSIZE_HALF_WORD;
  FLASH->CR |= FLASH_CR_PG;

  *(__IO uint16_t*)Address = Data;

  
  __DSB();
  
}


static void FLASH_Program_Byte(uint32_t Address, uint8_t Data)
{
  
  assert_param(IS_FLASH_ADDRESS(Address));
  
  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= FLASH_PSIZE_BYTE;
  FLASH->CR |= FLASH_CR_PG;

  *(__IO uint8_t*)Address = Data;

  
  __DSB();
}


static void FLASH_SetErrorCode(void)
{
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_OPERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_OPERATION;
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) != RESET)
  {
   pFlash.ErrorCode |= HAL_FLASH_ERROR_WRP;
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGAERR) != RESET)
  {
   pFlash.ErrorCode |= HAL_FLASH_ERROR_PGA;
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGPERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PGP;
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_ERSERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_ERS;
  }
  
#if defined (FLASH_OPTCR2_PCROP)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_RDERR) != RESET)
  { 
   pFlash.ErrorCode |= HAL_FLASH_ERROR_RD;
  }  
#endif 
  
  
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
}



#endif 






