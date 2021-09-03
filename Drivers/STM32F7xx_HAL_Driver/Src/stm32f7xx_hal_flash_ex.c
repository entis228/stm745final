 


#include "stm32f7xx_hal.h"





#ifdef HAL_FLASH_MODULE_ENABLED



    
#define SECTOR_MASK               0xFFFFFF07U
#define FLASH_TIMEOUT_VALUE       50000U

    


    
extern FLASH_ProcessTypeDef pFlash;





static HAL_StatusTypeDef  FLASH_OB_EnableWRP(uint32_t WRPSector);
static HAL_StatusTypeDef  FLASH_OB_DisableWRP(uint32_t WRPSector);
static HAL_StatusTypeDef  FLASH_OB_RDP_LevelConfig(uint8_t Level);
static HAL_StatusTypeDef  FLASH_OB_BOR_LevelConfig(uint8_t Level);
static HAL_StatusTypeDef  FLASH_OB_BootAddressConfig(uint32_t BootOption, uint32_t Address);
static uint32_t           FLASH_OB_GetUser(void);
static uint32_t           FLASH_OB_GetWRP(void);
static uint8_t            FLASH_OB_GetRDP(void);
static uint32_t           FLASH_OB_GetBOR(void);
static uint32_t           FLASH_OB_GetBootAddress(uint32_t BootOption);

#if defined (FLASH_OPTCR_nDBANK)
static void               FLASH_MassErase(uint8_t VoltageRange, uint32_t Banks);
static HAL_StatusTypeDef  FLASH_OB_UserConfig(uint32_t Wwdg, uint32_t Iwdg, uint32_t Stop, uint32_t Stdby, uint32_t Iwdgstop, \
                                              uint32_t Iwdgstdby, uint32_t NDBank, uint32_t NDBoot);
#else
static void               FLASH_MassErase(uint8_t VoltageRange);
static HAL_StatusTypeDef  FLASH_OB_UserConfig(uint32_t Wwdg, uint32_t Iwdg, uint32_t Stop, uint32_t Stdby, uint32_t Iwdgstop, uint32_t Iwdgstdby);
#endif 

#if defined (FLASH_OPTCR2_PCROP)
static HAL_StatusTypeDef  FLASH_OB_PCROP_Config(uint32_t PCROPSector);
static HAL_StatusTypeDef  FLASH_OB_PCROP_RDP_Config(uint32_t Pcrop_Rdp);
static uint32_t           FLASH_OB_GetPCROP(void);
static uint32_t           FLASH_OB_GetPCROPRDP(void);
#endif 

extern HAL_StatusTypeDef  FLASH_WaitForLastOperation(uint32_t Timeout);







HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  uint32_t index = 0;
  
  
  __HAL_LOCK(&pFlash);

  
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
    
    *SectorError = 0xFFFFFFFFU;
    
    if(pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
    {
      
#if defined (FLASH_OPTCR_nDBANK)      
      FLASH_MassErase((uint8_t) pEraseInit->VoltageRange, pEraseInit->Banks);
#else
      FLASH_MassErase((uint8_t) pEraseInit->VoltageRange);      
#endif 
                      
      
      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      
      
      FLASH->CR &= (~FLASH_MER_BIT);
    }
    else
    {
      
      assert_param(IS_FLASH_NBSECTORS(pEraseInit->NbSectors + pEraseInit->Sector));

      
      for(index = pEraseInit->Sector; index < (pEraseInit->NbSectors + pEraseInit->Sector); index++)
      {
        FLASH_Erase_Sector(index, (uint8_t) pEraseInit->VoltageRange);

        
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
        
        
        CLEAR_BIT(FLASH->CR, (FLASH_CR_SER | FLASH_CR_SNB)); 

        if(status != HAL_OK) 
        {
          
          *SectorError = index;
          break;
        }
      }
    }
  }

  
  __HAL_UNLOCK(&pFlash);

  return status;
}


HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit)
{
  HAL_StatusTypeDef status = HAL_OK;

  
  __HAL_LOCK(&pFlash);

  
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  
  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP);
  
  
  __HAL_FLASH_ENABLE_IT(FLASH_IT_ERR);
  
    
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP    | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |\
                         FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR| FLASH_FLAG_ERSERR);  
  
  if(pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
  {
    
    pFlash.ProcedureOnGoing = FLASH_PROC_MASSERASE;
#if defined (FLASH_OPTCR_nDBANK)    
    FLASH_MassErase((uint8_t) pEraseInit->VoltageRange, pEraseInit->Banks);
#else
    FLASH_MassErase((uint8_t) pEraseInit->VoltageRange);      
#endif     
  }
  else
  {
    

    
    assert_param(IS_FLASH_NBSECTORS(pEraseInit->NbSectors + pEraseInit->Sector));

    pFlash.ProcedureOnGoing = FLASH_PROC_SECTERASE;
    pFlash.NbSectorsToErase = pEraseInit->NbSectors;
    pFlash.Sector = pEraseInit->Sector;
    pFlash.VoltageForErase = (uint8_t)pEraseInit->VoltageRange;

    
    FLASH_Erase_Sector(pEraseInit->Sector, pEraseInit->VoltageRange);
  }

  return status;
}


HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  
  
  __HAL_LOCK(&pFlash);

  
  assert_param(IS_OPTIONBYTE(pOBInit->OptionType));

  
  if((pOBInit->OptionType & OPTIONBYTE_WRP) == OPTIONBYTE_WRP)
  {
    assert_param(IS_WRPSTATE(pOBInit->WRPState));
    if(pOBInit->WRPState == OB_WRPSTATE_ENABLE)
    {
      
      status = FLASH_OB_EnableWRP(pOBInit->WRPSector);
    }
    else
    {
      
      status = FLASH_OB_DisableWRP(pOBInit->WRPSector);
    }
  }

  
  if((pOBInit->OptionType & OPTIONBYTE_RDP) == OPTIONBYTE_RDP)
  {
    status = FLASH_OB_RDP_LevelConfig(pOBInit->RDPLevel);
  }

  
  if((pOBInit->OptionType & OPTIONBYTE_USER) == OPTIONBYTE_USER)
  {
#if defined (FLASH_OPTCR_nDBANK)
    status = FLASH_OB_UserConfig(pOBInit->USERConfig & OB_WWDG_SW, 
                                 pOBInit->USERConfig & OB_IWDG_SW,
                                 pOBInit->USERConfig & OB_STOP_NO_RST,
                                 pOBInit->USERConfig & OB_STDBY_NO_RST, 
                                 pOBInit->USERConfig & OB_IWDG_STOP_ACTIVE,
                                 pOBInit->USERConfig & OB_IWDG_STDBY_ACTIVE,
                                 pOBInit->USERConfig & OB_NDBANK_SINGLE_BANK,
                                 pOBInit->USERConfig & OB_DUAL_BOOT_DISABLE);
#else
    status = FLASH_OB_UserConfig(pOBInit->USERConfig & OB_WWDG_SW, 
                                 pOBInit->USERConfig & OB_IWDG_SW,
                                 pOBInit->USERConfig & OB_STOP_NO_RST,
                                 pOBInit->USERConfig & OB_STDBY_NO_RST, 
                                 pOBInit->USERConfig & OB_IWDG_STOP_ACTIVE,
                                 pOBInit->USERConfig & OB_IWDG_STDBY_ACTIVE);    
#endif 
  }
  
  
  if((pOBInit->OptionType & OPTIONBYTE_BOR) == OPTIONBYTE_BOR)
  {
    status = FLASH_OB_BOR_LevelConfig(pOBInit->BORLevel);
  }
  
  
  if((pOBInit->OptionType & OPTIONBYTE_BOOTADDR_0) == OPTIONBYTE_BOOTADDR_0)
  {
    status = FLASH_OB_BootAddressConfig(OPTIONBYTE_BOOTADDR_0, pOBInit->BootAddr0);
  }
  
  
  if((pOBInit->OptionType & OPTIONBYTE_BOOTADDR_1) == OPTIONBYTE_BOOTADDR_1)
  {
    status = FLASH_OB_BootAddressConfig(OPTIONBYTE_BOOTADDR_1, pOBInit->BootAddr1);
  }
  
#if defined (FLASH_OPTCR2_PCROP)
  
  if((pOBInit->OptionType & OPTIONBYTE_PCROP) == OPTIONBYTE_PCROP)
  {
    status = FLASH_OB_PCROP_Config(pOBInit->PCROPSector);
  }
  
  
  if((pOBInit->OptionType & OPTIONBYTE_PCROP_RDP) == OPTIONBYTE_PCROP_RDP)
  {
    status = FLASH_OB_PCROP_RDP_Config(pOBInit->PCROPRdp);
  }
#endif 

  
  __HAL_UNLOCK(&pFlash);

  return status;
}


void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit)
{
  pOBInit->OptionType = OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER |\
	                OPTIONBYTE_BOR | OPTIONBYTE_BOOTADDR_0 | OPTIONBYTE_BOOTADDR_1;

  
  pOBInit->WRPSector = FLASH_OB_GetWRP();

  
  pOBInit->RDPLevel = FLASH_OB_GetRDP();

  
  pOBInit->USERConfig = FLASH_OB_GetUser();

  
  pOBInit->BORLevel = FLASH_OB_GetBOR();
  
  
  pOBInit->BootAddr0 = FLASH_OB_GetBootAddress(OPTIONBYTE_BOOTADDR_0);
  
  
  pOBInit->BootAddr1 = FLASH_OB_GetBootAddress(OPTIONBYTE_BOOTADDR_1);

#if defined (FLASH_OPTCR2_PCROP)
  
  pOBInit->PCROPSector = FLASH_OB_GetPCROP();
  
  
  pOBInit->PCROPRdp = FLASH_OB_GetPCROPRDP();
#endif 
}


#if defined (FLASH_OPTCR_nDBANK)

static void FLASH_MassErase(uint8_t VoltageRange, uint32_t Banks)
{
  
  assert_param(IS_VOLTAGERANGE(VoltageRange));
  assert_param(IS_FLASH_BANK(Banks));

  
  FLASH->CR &= CR_PSIZE_MASK;
  if(Banks == FLASH_BANK_BOTH)
  {
    
    FLASH->CR |= FLASH_MER_BIT;
  }
  else if(Banks == FLASH_BANK_2)
  {
    
    FLASH->CR |= FLASH_CR_MER2;
  }
  else
  {
    
    FLASH->CR |= FLASH_CR_MER1;    
  }
  FLASH->CR |= FLASH_CR_STRT | ((uint32_t)VoltageRange <<8);
  
  __DSB();
}


void FLASH_Erase_Sector(uint32_t Sector, uint8_t VoltageRange)
{
  uint32_t tmp_psize = 0;

  
  assert_param(IS_FLASH_SECTOR(Sector));
  assert_param(IS_VOLTAGERANGE(VoltageRange));
  
  if(VoltageRange == FLASH_VOLTAGE_RANGE_1)
  {
     tmp_psize = FLASH_PSIZE_BYTE;
  }
  else if(VoltageRange == FLASH_VOLTAGE_RANGE_2)
  {
    tmp_psize = FLASH_PSIZE_HALF_WORD;
  }
  else if(VoltageRange == FLASH_VOLTAGE_RANGE_3)
  {
    tmp_psize = FLASH_PSIZE_WORD;
  }
  else
  {
    tmp_psize = FLASH_PSIZE_DOUBLE_WORD;
  }
  
  
  if(Sector > FLASH_SECTOR_11) 
  {
    Sector += 4;
  }  

  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= tmp_psize;
  CLEAR_BIT(FLASH->CR, FLASH_CR_SNB);
  FLASH->CR |= FLASH_CR_SER | (Sector << FLASH_CR_SNB_Pos);
  FLASH->CR |= FLASH_CR_STRT;
  
  
  __DSB();
}


static uint32_t FLASH_OB_GetWRP(void)
{
  
  return ((uint32_t)(FLASH->OPTCR & 0x0FFF0000));
}


static HAL_StatusTypeDef FLASH_OB_UserConfig(uint32_t Wwdg, uint32_t Iwdg, uint32_t Stop, uint32_t Stdby, uint32_t Iwdgstop, \
                                             uint32_t Iwdgstdby, uint32_t NDBank, uint32_t NDBoot)
{
  uint32_t useroptionmask = 0x00;
  uint32_t useroptionvalue = 0x00;

  HAL_StatusTypeDef status = HAL_OK;

  
  assert_param(IS_OB_WWDG_SOURCE(Wwdg));
  assert_param(IS_OB_IWDG_SOURCE(Iwdg));
  assert_param(IS_OB_STOP_SOURCE(Stop));
  assert_param(IS_OB_STDBY_SOURCE(Stdby));
  assert_param(IS_OB_IWDG_STOP_FREEZE(Iwdgstop));
  assert_param(IS_OB_IWDG_STDBY_FREEZE(Iwdgstdby));
  assert_param(IS_OB_NDBANK(NDBank));
  assert_param(IS_OB_NDBOOT(NDBoot));
  
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    useroptionmask = (FLASH_OPTCR_WWDG_SW | FLASH_OPTCR_IWDG_SW | FLASH_OPTCR_nRST_STOP | \
                      FLASH_OPTCR_nRST_STDBY | FLASH_OPTCR_IWDG_STOP | FLASH_OPTCR_IWDG_STDBY | \
                      FLASH_OPTCR_nDBOOT | FLASH_OPTCR_nDBANK);
                      
    useroptionvalue = (Iwdg | Wwdg | Stop | Stdby | Iwdgstop | Iwdgstdby | NDBoot | NDBank);
        
                   
    MODIFY_REG(FLASH->OPTCR, useroptionmask, useroptionvalue);
  }
  
  return status; 
}


static uint32_t FLASH_OB_GetUser(void)
{
  
  return ((uint32_t)(FLASH->OPTCR & 0xF00000F0U));
}
#else


static void FLASH_MassErase(uint8_t VoltageRange)
{
  
  assert_param(IS_VOLTAGERANGE(VoltageRange));

  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= FLASH_CR_MER;
  FLASH->CR |= FLASH_CR_STRT | ((uint32_t)VoltageRange <<8);
  
  __DSB();
}


void FLASH_Erase_Sector(uint32_t Sector, uint8_t VoltageRange)
{
  uint32_t tmp_psize = 0;

  
  assert_param(IS_FLASH_SECTOR(Sector));
  assert_param(IS_VOLTAGERANGE(VoltageRange));
  
  if(VoltageRange == FLASH_VOLTAGE_RANGE_1)
  {
     tmp_psize = FLASH_PSIZE_BYTE;
  }
  else if(VoltageRange == FLASH_VOLTAGE_RANGE_2)
  {
    tmp_psize = FLASH_PSIZE_HALF_WORD;
  }
  else if(VoltageRange == FLASH_VOLTAGE_RANGE_3)
  {
    tmp_psize = FLASH_PSIZE_WORD;
  }
  else
  {
    tmp_psize = FLASH_PSIZE_DOUBLE_WORD;
  }

  
  FLASH->CR &= CR_PSIZE_MASK;
  FLASH->CR |= tmp_psize;
  FLASH->CR &= SECTOR_MASK;
  FLASH->CR |= FLASH_CR_SER | (Sector << FLASH_CR_SNB_Pos);
  FLASH->CR |= FLASH_CR_STRT;
  
  
  __DSB();
}


static uint32_t FLASH_OB_GetWRP(void)
{
  
  return ((uint32_t)(FLASH->OPTCR & 0x00FF0000));
}


static HAL_StatusTypeDef FLASH_OB_UserConfig(uint32_t Wwdg, uint32_t Iwdg, uint32_t Stop, uint32_t Stdby, uint32_t Iwdgstop, uint32_t Iwdgstdby)
{
  uint32_t useroptionmask = 0x00;
  uint32_t useroptionvalue = 0x00;

  HAL_StatusTypeDef status = HAL_OK;

  
  assert_param(IS_OB_WWDG_SOURCE(Wwdg));
  assert_param(IS_OB_IWDG_SOURCE(Iwdg));
  assert_param(IS_OB_STOP_SOURCE(Stop));
  assert_param(IS_OB_STDBY_SOURCE(Stdby));
  assert_param(IS_OB_IWDG_STOP_FREEZE(Iwdgstop));
  assert_param(IS_OB_IWDG_STDBY_FREEZE(Iwdgstdby));

  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    useroptionmask = (FLASH_OPTCR_WWDG_SW | FLASH_OPTCR_IWDG_SW | FLASH_OPTCR_nRST_STOP | \
                      FLASH_OPTCR_nRST_STDBY | FLASH_OPTCR_IWDG_STOP | FLASH_OPTCR_IWDG_STDBY);
                      
    useroptionvalue = (Iwdg | Wwdg | Stop | Stdby | Iwdgstop | Iwdgstdby);
        
                   
    MODIFY_REG(FLASH->OPTCR, useroptionmask, useroptionvalue);
  }
  
  return status; 

}


static uint32_t FLASH_OB_GetUser(void)
{
  
  return ((uint32_t)(FLASH->OPTCR & 0xC00000F0U));
}
#endif 


static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WRPSector)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  assert_param(IS_OB_WRP_SECTOR(WRPSector));
    
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
    
    FLASH->OPTCR &= (~WRPSector);  
  }
  
  return status;
}


static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WRPSector)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  assert_param(IS_OB_WRP_SECTOR(WRPSector));
    
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
    
    FLASH->OPTCR |= (WRPSector); 
  }

  return status;
}


static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t Level)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  assert_param(IS_OB_RDP_LEVEL(Level));
    
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    *(__IO uint8_t*)OPTCR_BYTE1_ADDRESS = Level;
  }
  
  return status;
}


static HAL_StatusTypeDef FLASH_OB_BOR_LevelConfig(uint8_t Level)
{
  
  assert_param(IS_OB_BOR_LEVEL(Level));

  
  MODIFY_REG(FLASH->OPTCR, FLASH_OPTCR_BOR_LEV, Level);
  
  return HAL_OK;
  
}


static HAL_StatusTypeDef FLASH_OB_BootAddressConfig(uint32_t BootOption, uint32_t Address)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  assert_param(IS_OB_BOOT_ADDRESS(Address));
    
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    if(BootOption == OPTIONBYTE_BOOTADDR_0)
    {			
      MODIFY_REG(FLASH->OPTCR1, FLASH_OPTCR1_BOOT_ADD0, Address);
    }
    else
    {
      MODIFY_REG(FLASH->OPTCR1, FLASH_OPTCR1_BOOT_ADD1, (Address << 16));
    }
  }
  
  return status;
}


static uint8_t FLASH_OB_GetRDP(void)
{
  uint8_t readstatus = OB_RDP_LEVEL_0;
  
  if ((*(__IO uint8_t*)(OPTCR_BYTE1_ADDRESS)) == OB_RDP_LEVEL_0)
  {
    readstatus = OB_RDP_LEVEL_0;
  }
  else if ((*(__IO uint8_t*)(OPTCR_BYTE1_ADDRESS)) == OB_RDP_LEVEL_2)
  {
    readstatus = OB_RDP_LEVEL_2;
  }
  else 
  {
    readstatus = OB_RDP_LEVEL_1;
  }

  return readstatus;
}


static uint32_t FLASH_OB_GetBOR(void)
{
  
  return ((uint32_t)(FLASH->OPTCR & 0x0C));
}


static uint32_t FLASH_OB_GetBootAddress(uint32_t BootOption)
{  
  uint32_t Address = 0;
    
	
  if(BootOption == OPTIONBYTE_BOOTADDR_0)
  {			
    Address = FLASH->OPTCR1 & FLASH_OPTCR1_BOOT_ADD0;
	}
  else
	{
		Address = ((FLASH->OPTCR1 & FLASH_OPTCR1_BOOT_ADD1) >> 16);
	}

  return Address;
}

#if defined (FLASH_OPTCR2_PCROP)

static HAL_StatusTypeDef FLASH_OB_PCROP_Config(uint32_t PCROPSector)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  assert_param(IS_OB_PCROP_SECTOR(PCROPSector));
    
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    MODIFY_REG(FLASH->OPTCR2, FLASH_OPTCR2_PCROP, PCROPSector);
  }
  
  return status;
}


static HAL_StatusTypeDef FLASH_OB_PCROP_RDP_Config(uint32_t Pcrop_Rdp)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  
  assert_param(IS_OB_PCROP_RDP_VALUE(Pcrop_Rdp));
    
  
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    MODIFY_REG(FLASH->OPTCR2, FLASH_OPTCR2_PCROP_RDP, Pcrop_Rdp);
  }
  
  return status;
}


static uint32_t FLASH_OB_GetPCROP(void)
{
  
  return ((uint32_t)(FLASH->OPTCR2 & FLASH_OPTCR2_PCROP));
}


static uint32_t FLASH_OB_GetPCROPRDP(void)
{
  
  return ((uint32_t)(FLASH->OPTCR2 & FLASH_OPTCR2_PCROP_RDP));
}
#endif 


  
#endif 






