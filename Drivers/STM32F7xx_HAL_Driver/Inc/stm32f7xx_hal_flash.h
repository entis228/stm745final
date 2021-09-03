


#ifndef __STM32F7xx_HAL_FLASH_H
#define __STM32F7xx_HAL_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"









typedef enum
{
  FLASH_PROC_NONE = 0U,
  FLASH_PROC_SECTERASE,
  FLASH_PROC_MASSERASE,
  FLASH_PROC_PROGRAM
} FLASH_ProcedureTypeDef;



typedef struct
{
  __IO FLASH_ProcedureTypeDef ProcedureOnGoing;   

  __IO uint32_t               NbSectorsToErase;   

  __IO uint8_t                VoltageForErase;    

  __IO uint32_t               Sector;             

  __IO uint32_t               Address;            

  HAL_LockTypeDef             Lock;               

  __IO uint32_t               ErrorCode;          

}FLASH_ProcessTypeDef;







#define HAL_FLASH_ERROR_NONE         ((uint32_t)0x00000000U)    
#define HAL_FLASH_ERROR_ERS          ((uint32_t)0x00000002U)    
#define HAL_FLASH_ERROR_PGP          ((uint32_t)0x00000004U)    
#define HAL_FLASH_ERROR_PGA          ((uint32_t)0x00000008U)    
#define HAL_FLASH_ERROR_WRP          ((uint32_t)0x00000010U)    
#define HAL_FLASH_ERROR_OPERATION    ((uint32_t)0x00000020U)    
#define HAL_FLASH_ERROR_RD           ((uint32_t)0x00000040U)    



#define FLASH_TYPEPROGRAM_BYTE        ((uint32_t)0x00U)  
#define FLASH_TYPEPROGRAM_HALFWORD    ((uint32_t)0x01U)  
#define FLASH_TYPEPROGRAM_WORD        ((uint32_t)0x02U)  
#define FLASH_TYPEPROGRAM_DOUBLEWORD  ((uint32_t)0x03U)  



#define FLASH_FLAG_EOP                 FLASH_SR_EOP            
#define FLASH_FLAG_OPERR               FLASH_SR_OPERR          
#define FLASH_FLAG_WRPERR              FLASH_SR_WRPERR         
#define FLASH_FLAG_PGAERR              FLASH_SR_PGAERR         
#define FLASH_FLAG_PGPERR              FLASH_SR_PGPERR         
#define FLASH_FLAG_ERSERR              FLASH_SR_ERSERR         
#define FLASH_FLAG_BSY                 FLASH_SR_BSY            

#if defined (FLASH_OPTCR2_PCROP)
#define FLASH_FLAG_RDERR               FLASH_SR_RDERR          
#define FLASH_FLAG_ALL_ERRORS     (FLASH_FLAG_OPERR   | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | \
                                   FLASH_FLAG_PGPERR  | FLASH_FLAG_ERSERR | FLASH_FLAG_RDERR)
#else
#define FLASH_FLAG_ALL_ERRORS     (FLASH_FLAG_OPERR   | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | \
                                   FLASH_FLAG_PGPERR  | FLASH_FLAG_ERSERR)
#endif 



#define FLASH_IT_EOP                   FLASH_CR_EOPIE          
#define FLASH_IT_ERR                   ((uint32_t)0x02000000U)  



#define FLASH_PSIZE_BYTE           ((uint32_t)0x00000000U)
#define FLASH_PSIZE_HALF_WORD      ((uint32_t)FLASH_CR_PSIZE_0)
#define FLASH_PSIZE_WORD           ((uint32_t)FLASH_CR_PSIZE_1)
#define FLASH_PSIZE_DOUBLE_WORD    ((uint32_t)FLASH_CR_PSIZE)
#define CR_PSIZE_MASK              ((uint32_t)0xFFFFFCFFU)



#define FLASH_KEY1               ((uint32_t)0x45670123U)
#define FLASH_KEY2               ((uint32_t)0xCDEF89ABU)
#define FLASH_OPT_KEY1           ((uint32_t)0x08192A3BU)
#define FLASH_OPT_KEY2           ((uint32_t)0x4C5D6E7FU)



#if (FLASH_SECTOR_TOTAL == 2)
#define FLASH_SECTOR_0           ((uint32_t)0U) 
#define FLASH_SECTOR_1           ((uint32_t)1U) 
#elif (FLASH_SECTOR_TOTAL == 4)
#define FLASH_SECTOR_0           ((uint32_t)0U) 
#define FLASH_SECTOR_1           ((uint32_t)1U) 
#define FLASH_SECTOR_2           ((uint32_t)2U) 
#define FLASH_SECTOR_3           ((uint32_t)3U) 
#else
#define FLASH_SECTOR_0           ((uint32_t)0U) 
#define FLASH_SECTOR_1           ((uint32_t)1U) 
#define FLASH_SECTOR_2           ((uint32_t)2U) 
#define FLASH_SECTOR_3           ((uint32_t)3U) 
#define FLASH_SECTOR_4           ((uint32_t)4U) 
#define FLASH_SECTOR_5           ((uint32_t)5U) 
#define FLASH_SECTOR_6           ((uint32_t)6U) 
#define FLASH_SECTOR_7           ((uint32_t)7U) 
#endif 







#define __HAL_FLASH_SET_LATENCY(__LATENCY__) \
                  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, (uint32_t)(__LATENCY__))


#define __HAL_FLASH_GET_LATENCY()     (READ_BIT((FLASH->ACR), FLASH_ACR_LATENCY))


#define __HAL_FLASH_PREFETCH_BUFFER_ENABLE()  (FLASH->ACR |= FLASH_ACR_PRFTEN)


#define __HAL_FLASH_PREFETCH_BUFFER_DISABLE()   (FLASH->ACR &= (~FLASH_ACR_PRFTEN))


#define __HAL_FLASH_ART_ENABLE()  SET_BIT(FLASH->ACR, FLASH_ACR_ARTEN)


#define __HAL_FLASH_ART_DISABLE()   CLEAR_BIT(FLASH->ACR, FLASH_ACR_ARTEN)


#define __HAL_FLASH_ART_RESET()  (FLASH->ACR |= FLASH_ACR_ARTRST)


#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  (FLASH->CR |= (__INTERRUPT__))


#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)  (FLASH->CR &= ~(uint32_t)(__INTERRUPT__))


#define __HAL_FLASH_GET_FLAG(__FLAG__)   ((FLASH->SR & (__FLAG__)))


#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)   (FLASH->SR = (__FLAG__))



#include "stm32f7xx_hal_flash_ex.h"





HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);

void HAL_FLASH_IRQHandler(void);

void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);




HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);

HAL_StatusTypeDef HAL_FLASH_OB_Launch(void);




uint32_t HAL_FLASH_GetError(void);
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout);












#define OPTCR_BYTE1_ADDRESS         ((uint32_t)0x40023C15)







#define IS_FLASH_TYPEPROGRAM(VALUE)(((VALUE) == FLASH_TYPEPROGRAM_BYTE) || \
                                    ((VALUE) == FLASH_TYPEPROGRAM_HALFWORD) || \
                                    ((VALUE) == FLASH_TYPEPROGRAM_WORD) || \
                                    ((VALUE) == FLASH_TYPEPROGRAM_DOUBLEWORD))













#ifdef __cplusplus
}
#endif

#endif 


