


#ifndef __STM32F7xx_HAL_FLASH_EX_H
#define __STM32F7xx_HAL_FLASH_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"









typedef struct
{
  uint32_t TypeErase;   

#if defined (FLASH_OPTCR_nDBANK)
  uint32_t Banks;       
#endif 

  uint32_t Sector;      

  uint32_t NbSectors;   

  uint32_t VoltageRange;

} FLASH_EraseInitTypeDef;


typedef struct
{
  uint32_t OptionType;   

  uint32_t WRPState;     

  uint32_t WRPSector;    

  uint32_t RDPLevel;     

  uint32_t BORLevel;     

  uint32_t USERConfig;   

  uint32_t BootAddr0;    

  uint32_t BootAddr1;    

#if defined (FLASH_OPTCR2_PCROP)
  uint32_t PCROPSector;  

  uint32_t PCROPRdp;    
#endif 

} FLASH_OBProgramInitTypeDef;







#define FLASH_TYPEERASE_SECTORS         ((uint32_t)0x00U)  
#define FLASH_TYPEERASE_MASSERASE       ((uint32_t)0x01U)  



#define FLASH_VOLTAGE_RANGE_1        ((uint32_t)0x00U)  
#define FLASH_VOLTAGE_RANGE_2        ((uint32_t)0x01U)  
#define FLASH_VOLTAGE_RANGE_3        ((uint32_t)0x02U)  
#define FLASH_VOLTAGE_RANGE_4        ((uint32_t)0x03U)  



#define OB_WRPSTATE_DISABLE       ((uint32_t)0x00U)  
#define OB_WRPSTATE_ENABLE        ((uint32_t)0x01U)  



#define OPTIONBYTE_WRP         ((uint32_t)0x01U)  
#define OPTIONBYTE_RDP         ((uint32_t)0x02U)  
#define OPTIONBYTE_USER        ((uint32_t)0x04U)  
#define OPTIONBYTE_BOR         ((uint32_t)0x08U)  
#define OPTIONBYTE_BOOTADDR_0  ((uint32_t)0x10U)  
#define OPTIONBYTE_BOOTADDR_1  ((uint32_t)0x20U)  
#if defined (FLASH_OPTCR2_PCROP)
#define OPTIONBYTE_PCROP       ((uint32_t)0x40U)  
#define OPTIONBYTE_PCROP_RDP   ((uint32_t)0x80U)  
#endif 



#define OB_RDP_LEVEL_0       ((uint8_t)0xAAU)
#define OB_RDP_LEVEL_1       ((uint8_t)0x55U)
#define OB_RDP_LEVEL_2       ((uint8_t)0xCCU)   



#define OB_WWDG_SW           ((uint32_t)0x10U)  
#define OB_WWDG_HW           ((uint32_t)0x00U)  




#define OB_IWDG_SW           ((uint32_t)0x20U)  
#define OB_IWDG_HW           ((uint32_t)0x00U)  



#define OB_STOP_NO_RST       ((uint32_t)0x40U) 
#define OB_STOP_RST          ((uint32_t)0x00U) 



#define OB_STDBY_NO_RST      ((uint32_t)0x80U) 
#define OB_STDBY_RST         ((uint32_t)0x00U) 



#define OB_IWDG_STOP_FREEZE      ((uint32_t)0x00000000U) 
#define OB_IWDG_STOP_ACTIVE      ((uint32_t)0x80000000U) 



#define OB_IWDG_STDBY_FREEZE      ((uint32_t)0x00000000U) 
#define OB_IWDG_STDBY_ACTIVE      ((uint32_t)0x40000000U) 



#define OB_BOR_LEVEL3          ((uint32_t)0x00U)  
#define OB_BOR_LEVEL2          ((uint32_t)0x04U)  
#define OB_BOR_LEVEL1          ((uint32_t)0x08U)  
#define OB_BOR_OFF             ((uint32_t)0x0CU)  


#if defined (FLASH_OPTCR_nDBOOT)

#define OB_DUAL_BOOT_DISABLE      ((uint32_t)0x10000000U) 
#define OB_DUAL_BOOT_ENABLE       ((uint32_t)0x00000000U) 

#endif 

#if defined (FLASH_OPTCR_nDBANK)

#define OB_NDBANK_SINGLE_BANK      ((uint32_t)0x20000000U) 
#define OB_NDBANK_DUAL_BANK        ((uint32_t)0x00000000U) 

#endif 


#define OB_BOOTADDR_ITCM_RAM         ((uint32_t)0x0000U)  
#define OB_BOOTADDR_SYSTEM           ((uint32_t)0x0040U)  
#define OB_BOOTADDR_ITCM_FLASH       ((uint32_t)0x0080U)  
#define OB_BOOTADDR_AXIM_FLASH       ((uint32_t)0x2000U)  
#define OB_BOOTADDR_DTCM_RAM         ((uint32_t)0x8000U)  
#define OB_BOOTADDR_SRAM1            ((uint32_t)0x8004U)  
#if (SRAM2_BASE == 0x2003C000U)
#define OB_BOOTADDR_SRAM2            ((uint32_t)0x800FU)  
#else
#define OB_BOOTADDR_SRAM2            ((uint32_t)0x8013U)  
#endif 



#define FLASH_LATENCY_0                FLASH_ACR_LATENCY_0WS   
#define FLASH_LATENCY_1                FLASH_ACR_LATENCY_1WS   
#define FLASH_LATENCY_2                FLASH_ACR_LATENCY_2WS   
#define FLASH_LATENCY_3                FLASH_ACR_LATENCY_3WS   
#define FLASH_LATENCY_4                FLASH_ACR_LATENCY_4WS   
#define FLASH_LATENCY_5                FLASH_ACR_LATENCY_5WS   
#define FLASH_LATENCY_6                FLASH_ACR_LATENCY_6WS   
#define FLASH_LATENCY_7                FLASH_ACR_LATENCY_7WS   
#define FLASH_LATENCY_8                FLASH_ACR_LATENCY_8WS   
#define FLASH_LATENCY_9                FLASH_ACR_LATENCY_9WS   
#define FLASH_LATENCY_10               FLASH_ACR_LATENCY_10WS  
#define FLASH_LATENCY_11               FLASH_ACR_LATENCY_11WS  
#define FLASH_LATENCY_12               FLASH_ACR_LATENCY_12WS  
#define FLASH_LATENCY_13               FLASH_ACR_LATENCY_13WS  
#define FLASH_LATENCY_14               FLASH_ACR_LATENCY_14WS  
#define FLASH_LATENCY_15               FLASH_ACR_LATENCY_15WS  


#if defined (FLASH_OPTCR_nDBANK)

#define FLASH_BANK_1                       ((uint32_t)0x01U)                          
#define FLASH_BANK_2                       ((uint32_t)0x02U)                          
#define FLASH_BANK_BOTH                    ((uint32_t)(FLASH_BANK_1 | FLASH_BANK_2)) 

#endif 


#if defined (FLASH_OPTCR_nDBANK)
#define FLASH_MER_BIT     (FLASH_CR_MER1 | FLASH_CR_MER2) 
#else
#define FLASH_MER_BIT     (FLASH_CR_MER) 
#endif 



#if (FLASH_SECTOR_TOTAL == 24)
#define FLASH_SECTOR_8     ((uint32_t)8U)  
#define FLASH_SECTOR_9     ((uint32_t)9U)  
#define FLASH_SECTOR_10    ((uint32_t)10U) 
#define FLASH_SECTOR_11    ((uint32_t)11U) 
#define FLASH_SECTOR_12    ((uint32_t)12U) 
#define FLASH_SECTOR_13    ((uint32_t)13U) 
#define FLASH_SECTOR_14    ((uint32_t)14U) 
#define FLASH_SECTOR_15    ((uint32_t)15U) 
#define FLASH_SECTOR_16    ((uint32_t)16U) 
#define FLASH_SECTOR_17    ((uint32_t)17U) 
#define FLASH_SECTOR_18    ((uint32_t)18U) 
#define FLASH_SECTOR_19    ((uint32_t)19U) 
#define FLASH_SECTOR_20    ((uint32_t)20U) 
#define FLASH_SECTOR_21    ((uint32_t)21U) 
#define FLASH_SECTOR_22    ((uint32_t)22U) 
#define FLASH_SECTOR_23    ((uint32_t)23U) 
#endif 


#if (FLASH_SECTOR_TOTAL == 24)


#define OB_WRP_SECTOR_0       ((uint32_t)0x00010000U) 
#define OB_WRP_SECTOR_1       ((uint32_t)0x00020000U) 
#define OB_WRP_SECTOR_2       ((uint32_t)0x00040000U) 
#define OB_WRP_SECTOR_3       ((uint32_t)0x00080000U) 
#define OB_WRP_SECTOR_4       ((uint32_t)0x00100000U) 
#define OB_WRP_SECTOR_5       ((uint32_t)0x00200000U) 
#define OB_WRP_SECTOR_6       ((uint32_t)0x00400000U) 
#define OB_WRP_SECTOR_7       ((uint32_t)0x00800000U) 
#define OB_WRP_SECTOR_8       ((uint32_t)0x01000000U) 
#define OB_WRP_SECTOR_9       ((uint32_t)0x02000000U) 
#define OB_WRP_SECTOR_10      ((uint32_t)0x04000000U) 
#define OB_WRP_SECTOR_11      ((uint32_t)0x08000000U) 
#define OB_WRP_SECTOR_All     ((uint32_t)0x0FFF0000U) 


#define OB_WRP_DB_SECTOR_0    ((uint32_t)0x00010000U) 
#define OB_WRP_DB_SECTOR_1    ((uint32_t)0x00010000U) 
#define OB_WRP_DB_SECTOR_2    ((uint32_t)0x00020000U) 
#define OB_WRP_DB_SECTOR_3    ((uint32_t)0x00020000U) 
#define OB_WRP_DB_SECTOR_4    ((uint32_t)0x00040000U) 
#define OB_WRP_DB_SECTOR_5    ((uint32_t)0x00040000U) 
#define OB_WRP_DB_SECTOR_6    ((uint32_t)0x00080000U) 
#define OB_WRP_DB_SECTOR_7    ((uint32_t)0x00080000U) 
#define OB_WRP_DB_SECTOR_8    ((uint32_t)0x00100000U) 
#define OB_WRP_DB_SECTOR_9    ((uint32_t)0x00100000U) 
#define OB_WRP_DB_SECTOR_10   ((uint32_t)0x00200000U) 
#define OB_WRP_DB_SECTOR_11   ((uint32_t)0x00200000U) 
#define OB_WRP_DB_SECTOR_12   ((uint32_t)0x00400000U) 
#define OB_WRP_DB_SECTOR_13   ((uint32_t)0x00400000U) 
#define OB_WRP_DB_SECTOR_14   ((uint32_t)0x00800000U) 
#define OB_WRP_DB_SECTOR_15   ((uint32_t)0x00800000U) 
#define OB_WRP_DB_SECTOR_16   ((uint32_t)0x01000000U) 
#define OB_WRP_DB_SECTOR_17   ((uint32_t)0x01000000U) 
#define OB_WRP_DB_SECTOR_18   ((uint32_t)0x02000000U) 
#define OB_WRP_DB_SECTOR_19   ((uint32_t)0x02000000U) 
#define OB_WRP_DB_SECTOR_20   ((uint32_t)0x04000000U) 
#define OB_WRP_DB_SECTOR_21   ((uint32_t)0x04000000U) 
#define OB_WRP_DB_SECTOR_22   ((uint32_t)0x08000000U) 
#define OB_WRP_DB_SECTOR_23   ((uint32_t)0x08000000U) 
#define OB_WRP_DB_SECTOR_All  ((uint32_t)0x0FFF0000U) 

#endif 

#if (FLASH_SECTOR_TOTAL == 8)

#define OB_WRP_SECTOR_0       ((uint32_t)0x00010000U) 
#define OB_WRP_SECTOR_1       ((uint32_t)0x00020000U) 
#define OB_WRP_SECTOR_2       ((uint32_t)0x00040000U) 
#define OB_WRP_SECTOR_3       ((uint32_t)0x00080000U) 
#define OB_WRP_SECTOR_4       ((uint32_t)0x00100000U) 
#define OB_WRP_SECTOR_5       ((uint32_t)0x00200000U) 
#define OB_WRP_SECTOR_6       ((uint32_t)0x00400000U) 
#define OB_WRP_SECTOR_7       ((uint32_t)0x00800000U) 
#define OB_WRP_SECTOR_All     ((uint32_t)0x00FF0000U) 

#endif 

#if (FLASH_SECTOR_TOTAL == 4)

#define OB_WRP_SECTOR_0       ((uint32_t)0x00010000U) 
#define OB_WRP_SECTOR_1       ((uint32_t)0x00020000U) 
#define OB_WRP_SECTOR_2       ((uint32_t)0x00040000U) 
#define OB_WRP_SECTOR_3       ((uint32_t)0x00080000U) 
#define OB_WRP_SECTOR_All     ((uint32_t)0x000F0000U) 

#endif 

#if (FLASH_SECTOR_TOTAL == 2)

#define OB_WRP_SECTOR_0       ((uint32_t)0x00010000U) 
#define OB_WRP_SECTOR_1       ((uint32_t)0x00020000U) 
#define OB_WRP_SECTOR_All     ((uint32_t)0x00030000U) 

#endif 

#if defined (FLASH_OPTCR2_PCROP)
#if (FLASH_SECTOR_TOTAL == 8)

#define OB_PCROP_SECTOR_0     ((uint32_t)0x00000001U) 
#define OB_PCROP_SECTOR_1     ((uint32_t)0x00000002U) 
#define OB_PCROP_SECTOR_2     ((uint32_t)0x00000004U) 
#define OB_PCROP_SECTOR_3     ((uint32_t)0x00000008U) 
#define OB_PCROP_SECTOR_4     ((uint32_t)0x00000010U) 
#define OB_PCROP_SECTOR_5     ((uint32_t)0x00000020U) 
#define OB_PCROP_SECTOR_6     ((uint32_t)0x00000040U) 
#define OB_PCROP_SECTOR_7     ((uint32_t)0x00000080U) 
#define OB_PCROP_SECTOR_All   ((uint32_t)0x000000FFU) 

#endif 

#if (FLASH_SECTOR_TOTAL == 4)

#define OB_PCROP_SECTOR_0     ((uint32_t)0x00000001U) 
#define OB_PCROP_SECTOR_1     ((uint32_t)0x00000002U) 
#define OB_PCROP_SECTOR_2     ((uint32_t)0x00000004U) 
#define OB_PCROP_SECTOR_3     ((uint32_t)0x00000008U) 
#define OB_PCROP_SECTOR_All   ((uint32_t)0x0000000FU) 

#endif 


#define OB_PCROP_RDP_ENABLE   ((uint32_t)0x80000000U) 
#define OB_PCROP_RDP_DISABLE  ((uint32_t)0x00000000U) 

#endif 






#define __HAL_FLASH_CALC_BOOT_BASE_ADR(__ADDRESS__) ((__ADDRESS__) >> 14)
 






HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void              HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);












#define IS_FLASH_TYPEERASE(VALUE)(((VALUE) == FLASH_TYPEERASE_SECTORS) || \
                                  ((VALUE) == FLASH_TYPEERASE_MASSERASE))

#define IS_VOLTAGERANGE(RANGE)(((RANGE) == FLASH_VOLTAGE_RANGE_1) || \
                               ((RANGE) == FLASH_VOLTAGE_RANGE_2) || \
                               ((RANGE) == FLASH_VOLTAGE_RANGE_3) || \
                               ((RANGE) == FLASH_VOLTAGE_RANGE_4))

#define IS_WRPSTATE(VALUE)(((VALUE) == OB_WRPSTATE_DISABLE) || \
                           ((VALUE) == OB_WRPSTATE_ENABLE))

#if defined (FLASH_OPTCR2_PCROP)
#define IS_OPTIONBYTE(VALUE)(((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP        | OPTIONBYTE_USER |\
                                          OPTIONBYTE_BOR | OPTIONBYTE_BOOTADDR_0 | OPTIONBYTE_BOOTADDR_1 |\
                                          OPTIONBYTE_PCROP | OPTIONBYTE_PCROP_RDP)))
#else
#define IS_OPTIONBYTE(VALUE)(((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP        | OPTIONBYTE_USER |\
                                          OPTIONBYTE_BOR | OPTIONBYTE_BOOTADDR_0 | OPTIONBYTE_BOOTADDR_1)))
#endif 

#define IS_OB_BOOT_ADDRESS(ADDRESS) ((ADDRESS) <= 0x8013)

#define IS_OB_RDP_LEVEL(LEVEL) (((LEVEL) == OB_RDP_LEVEL_0)   ||\
                                ((LEVEL) == OB_RDP_LEVEL_1)   ||\
                                ((LEVEL) == OB_RDP_LEVEL_2))

#define IS_OB_WWDG_SOURCE(SOURCE) (((SOURCE) == OB_WWDG_SW) || ((SOURCE) == OB_WWDG_HW))

#define IS_OB_IWDG_SOURCE(SOURCE) (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

#define IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == OB_STOP_NO_RST) || ((SOURCE) == OB_STOP_RST))

#define IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == OB_STDBY_NO_RST) || ((SOURCE) == OB_STDBY_RST))

#define IS_OB_IWDG_STOP_FREEZE(FREEZE) (((FREEZE) == OB_IWDG_STOP_FREEZE) || ((FREEZE) == OB_IWDG_STOP_ACTIVE))

#define IS_OB_IWDG_STDBY_FREEZE(FREEZE) (((FREEZE) == OB_IWDG_STDBY_FREEZE) || ((FREEZE) == OB_IWDG_STDBY_ACTIVE))

#define IS_OB_BOR_LEVEL(LEVEL) (((LEVEL) == OB_BOR_LEVEL1) || ((LEVEL) == OB_BOR_LEVEL2) ||\
                                ((LEVEL) == OB_BOR_LEVEL3) || ((LEVEL) == OB_BOR_OFF))

#define IS_FLASH_LATENCY(LATENCY) (((LATENCY) == FLASH_LATENCY_0)  || \
                                   ((LATENCY) == FLASH_LATENCY_1)  || \
                                   ((LATENCY) == FLASH_LATENCY_2)  || \
                                   ((LATENCY) == FLASH_LATENCY_3)  || \
                                   ((LATENCY) == FLASH_LATENCY_4)  || \
                                   ((LATENCY) == FLASH_LATENCY_5)  || \
                                   ((LATENCY) == FLASH_LATENCY_6)  || \
                                   ((LATENCY) == FLASH_LATENCY_7)  || \
                                   ((LATENCY) == FLASH_LATENCY_8)  || \
                                   ((LATENCY) == FLASH_LATENCY_9)  || \
                                   ((LATENCY) == FLASH_LATENCY_10) || \
                                   ((LATENCY) == FLASH_LATENCY_11) || \
                                   ((LATENCY) == FLASH_LATENCY_12) || \
                                   ((LATENCY) == FLASH_LATENCY_13) || \
                                   ((LATENCY) == FLASH_LATENCY_14) || \
                                   ((LATENCY) == FLASH_LATENCY_15))

#define IS_FLASH_ADDRESS(ADDRESS) ((((ADDRESS) >= FLASH_BASE) && ((ADDRESS) <= FLASH_END)) || \
                                   (((ADDRESS) >= FLASH_OTP_BASE) && ((ADDRESS) <= FLASH_OTP_END)))
#define IS_FLASH_NBSECTORS(NBSECTORS) (((NBSECTORS) != 0U) && ((NBSECTORS) <= FLASH_SECTOR_TOTAL))

#if (FLASH_SECTOR_TOTAL == 8)
#define IS_FLASH_SECTOR(SECTOR) (((SECTOR) == FLASH_SECTOR_0)   || ((SECTOR) == FLASH_SECTOR_1)   ||\
                                 ((SECTOR) == FLASH_SECTOR_2)   || ((SECTOR) == FLASH_SECTOR_3)   ||\
                                 ((SECTOR) == FLASH_SECTOR_4)   || ((SECTOR) == FLASH_SECTOR_5)   ||\
                                 ((SECTOR) == FLASH_SECTOR_6)   || ((SECTOR) == FLASH_SECTOR_7))

#define IS_OB_WRP_SECTOR(SECTOR)  ((((SECTOR) & 0xFF00FFFFU) == 0x00000000U) && ((SECTOR) != 0x00000000U))
#endif 

#if (FLASH_SECTOR_TOTAL == 24)
#define IS_FLASH_SECTOR(SECTOR) (((SECTOR) == FLASH_SECTOR_0)   || ((SECTOR) == FLASH_SECTOR_1)   ||\
                                 ((SECTOR) == FLASH_SECTOR_2)   || ((SECTOR) == FLASH_SECTOR_3)   ||\
                                 ((SECTOR) == FLASH_SECTOR_4)   || ((SECTOR) == FLASH_SECTOR_5)   ||\
                                 ((SECTOR) == FLASH_SECTOR_6)   || ((SECTOR) == FLASH_SECTOR_7)   ||\
                                 ((SECTOR) == FLASH_SECTOR_8)   || ((SECTOR) == FLASH_SECTOR_9)   ||\
                                 ((SECTOR) == FLASH_SECTOR_10)  || ((SECTOR) == FLASH_SECTOR_11)  ||\
                                 ((SECTOR) == FLASH_SECTOR_12)  || ((SECTOR) == FLASH_SECTOR_13)  ||\
                                 ((SECTOR) == FLASH_SECTOR_14)  || ((SECTOR) == FLASH_SECTOR_15)  ||\
                                 ((SECTOR) == FLASH_SECTOR_16)  || ((SECTOR) == FLASH_SECTOR_17)  ||\
                                 ((SECTOR) == FLASH_SECTOR_18)  || ((SECTOR) == FLASH_SECTOR_19)  ||\
                                 ((SECTOR) == FLASH_SECTOR_20)  || ((SECTOR) == FLASH_SECTOR_21)  ||\
                                 ((SECTOR) == FLASH_SECTOR_22)  || ((SECTOR) == FLASH_SECTOR_23))

#define IS_OB_WRP_SECTOR(SECTOR)  ((((SECTOR) & 0xF000FFFFU) == 0x00000000U) && ((SECTOR) != 0x00000000U))
#endif 

#if (FLASH_SECTOR_TOTAL == 4)
#define IS_FLASH_SECTOR(SECTOR) (((SECTOR) == FLASH_SECTOR_0)   || ((SECTOR) == FLASH_SECTOR_1)   ||\
                                 ((SECTOR) == FLASH_SECTOR_2)   || ((SECTOR) == FLASH_SECTOR_3))

#define IS_OB_WRP_SECTOR(SECTOR)  ((((SECTOR) & 0xFFF0FFFFU) == 0x00000000U) && ((SECTOR) != 0x00000000U))
#endif 

#if (FLASH_SECTOR_TOTAL == 2)
#define IS_FLASH_SECTOR(SECTOR) (((SECTOR) == FLASH_SECTOR_0)   || ((SECTOR) == FLASH_SECTOR_1))

#define IS_OB_WRP_SECTOR(SECTOR)  ((((SECTOR) & 0xFFFCFFFFU) == 0x00000000U) && ((SECTOR) != 0x00000000U))
#endif 

#if defined (FLASH_OPTCR_nDBANK)
#define IS_OB_NDBANK(VALUE)        (((VALUE) == OB_NDBANK_SINGLE_BANK) || \
                                    ((VALUE) == OB_NDBANK_DUAL_BANK))

#define IS_FLASH_BANK(BANK)        (((BANK) == FLASH_BANK_1)  || \
                                    ((BANK) == FLASH_BANK_2)  || \
                                    ((BANK) == FLASH_BANK_BOTH))
#endif 

#if defined (FLASH_OPTCR_nDBOOT)
#define IS_OB_NDBOOT(VALUE)        (((VALUE) == OB_DUAL_BOOT_DISABLE) || \
                                    ((VALUE) == OB_DUAL_BOOT_ENABLE))
#endif 

#if defined (FLASH_OPTCR2_PCROP)
#define IS_OB_PCROP_SECTOR(SECTOR)   (((SECTOR) & (uint32_t)0xFFFFFF00U) == 0x00000000U)
#define IS_OB_PCROP_RDP_VALUE(VALUE) (((VALUE) == OB_PCROP_RDP_DISABLE) || \
                                      ((VALUE) == OB_PCROP_RDP_ENABLE))
#endif 







void FLASH_Erase_Sector(uint32_t Sector, uint8_t VoltageRange);






#ifdef __cplusplus
}
#endif

#endif 


