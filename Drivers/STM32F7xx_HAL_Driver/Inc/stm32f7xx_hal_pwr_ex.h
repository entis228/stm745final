 


#ifndef __STM32F7xx_HAL_PWR_EX_H
#define __STM32F7xx_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"



 

 



#define PWR_WAKEUP_PIN1                PWR_CSR2_EWUP1
#define PWR_WAKEUP_PIN2                PWR_CSR2_EWUP2
#define PWR_WAKEUP_PIN3                PWR_CSR2_EWUP3
#define PWR_WAKEUP_PIN4                PWR_CSR2_EWUP4
#define PWR_WAKEUP_PIN5                PWR_CSR2_EWUP5
#define PWR_WAKEUP_PIN6                PWR_CSR2_EWUP6
#define PWR_WAKEUP_PIN1_HIGH           PWR_CSR2_EWUP1
#define PWR_WAKEUP_PIN2_HIGH           PWR_CSR2_EWUP2
#define PWR_WAKEUP_PIN3_HIGH           PWR_CSR2_EWUP3
#define PWR_WAKEUP_PIN4_HIGH           PWR_CSR2_EWUP4
#define PWR_WAKEUP_PIN5_HIGH           PWR_CSR2_EWUP5
#define PWR_WAKEUP_PIN6_HIGH           PWR_CSR2_EWUP6
#define PWR_WAKEUP_PIN1_LOW            (uint32_t)((PWR_CR2_WUPP1<<6) | PWR_CSR2_EWUP1)
#define PWR_WAKEUP_PIN2_LOW            (uint32_t)((PWR_CR2_WUPP2<<6) | PWR_CSR2_EWUP2)
#define PWR_WAKEUP_PIN3_LOW            (uint32_t)((PWR_CR2_WUPP3<<6) | PWR_CSR2_EWUP3)
#define PWR_WAKEUP_PIN4_LOW            (uint32_t)((PWR_CR2_WUPP4<<6) | PWR_CSR2_EWUP4)
#define PWR_WAKEUP_PIN5_LOW            (uint32_t)((PWR_CR2_WUPP5<<6) | PWR_CSR2_EWUP5)
#define PWR_WAKEUP_PIN6_LOW            (uint32_t)((PWR_CR2_WUPP6<<6) | PWR_CSR2_EWUP6)


	

#define PWR_MAINREGULATOR_UNDERDRIVE_ON                       PWR_CR1_MRUDS
#define PWR_LOWPOWERREGULATOR_UNDERDRIVE_ON                   ((uint32_t)(PWR_CR1_LPDS | PWR_CR1_LPUDS))
 
  

#define PWR_FLAG_ODRDY                  PWR_CSR1_ODRDY
#define PWR_FLAG_ODSWRDY                PWR_CSR1_ODSWRDY
#define PWR_FLAG_UDRDY                  PWR_CSR1_UDRDY

	

#define PWR_WAKEUP_PIN_FLAG1            PWR_CSR2_WUPF1
#define PWR_WAKEUP_PIN_FLAG2            PWR_CSR2_WUPF2
#define PWR_WAKEUP_PIN_FLAG3            PWR_CSR2_WUPF3
#define PWR_WAKEUP_PIN_FLAG4            PWR_CSR2_WUPF4
#define PWR_WAKEUP_PIN_FLAG5            PWR_CSR2_WUPF5
#define PWR_WAKEUP_PIN_FLAG6            PWR_CSR2_WUPF6


 
  



#define __HAL_PWR_OVERDRIVE_ENABLE() (PWR->CR1 |= (uint32_t)PWR_CR1_ODEN)
#define __HAL_PWR_OVERDRIVE_DISABLE() (PWR->CR1 &= (uint32_t)(~PWR_CR1_ODEN))


#define __HAL_PWR_OVERDRIVESWITCHING_ENABLE() (PWR->CR1 |= (uint32_t)PWR_CR1_ODSWEN)
#define __HAL_PWR_OVERDRIVESWITCHING_DISABLE() (PWR->CR1 &= (uint32_t)(~PWR_CR1_ODSWEN))


#define __HAL_PWR_UNDERDRIVE_ENABLE() (PWR->CR1 |= (uint32_t)PWR_CR1_UDEN)
#define __HAL_PWR_UNDERDRIVE_DISABLE() (PWR->CR1 &= (uint32_t)(~PWR_CR1_UDEN))


#define __HAL_PWR_GET_ODRUDR_FLAG(__FLAG__) ((PWR->CSR1 & (__FLAG__)) == (__FLAG__))


#define __HAL_PWR_CLEAR_ODRUDR_FLAG() (PWR->CSR1 |= (PWR_FLAG_UDRDY | PWR_CSR1_EIWUP))


#define __HAL_PWR_GET_WAKEUP_FLAG(__WUFLAG__) (PWR->CSR2 & (__WUFLAG__))


#define __HAL_PWR_CLEAR_WAKEUP_FLAG(__WUFLAG__) (PWR->CR2 |=  (__WUFLAG__))



 

uint32_t HAL_PWREx_GetVoltageRange(void);
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);

void HAL_PWREx_EnableFlashPowerDown(void);
void HAL_PWREx_DisableFlashPowerDown(void); 
HAL_StatusTypeDef HAL_PWREx_EnableBkUpReg(void);
HAL_StatusTypeDef HAL_PWREx_DisableBkUpReg(void); 

void HAL_PWREx_EnableMainRegulatorLowVoltage(void);
void HAL_PWREx_DisableMainRegulatorLowVoltage(void);
void HAL_PWREx_EnableLowRegulatorLowVoltage(void);
void HAL_PWREx_DisableLowRegulatorLowVoltage(void);

HAL_StatusTypeDef HAL_PWREx_EnableOverDrive(void);
HAL_StatusTypeDef HAL_PWREx_DisableOverDrive(void);
HAL_StatusTypeDef HAL_PWREx_EnterUnderDriveSTOPMode(uint32_t Regulator, uint8_t STOPEntry);











#define IS_PWR_REGULATOR_UNDERDRIVE(REGULATOR) (((REGULATOR) == PWR_MAINREGULATOR_UNDERDRIVE_ON) || \
                                                ((REGULATOR) == PWR_LOWPOWERREGULATOR_UNDERDRIVE_ON))
#define IS_PWR_WAKEUP_PIN(__PIN__)         (((__PIN__) == PWR_WAKEUP_PIN1)       || \
                                            ((__PIN__) == PWR_WAKEUP_PIN2)       || \
                                            ((__PIN__) == PWR_WAKEUP_PIN3)       || \
                                            ((__PIN__) == PWR_WAKEUP_PIN4)       || \
                                            ((__PIN__) == PWR_WAKEUP_PIN5)       || \
                                            ((__PIN__) == PWR_WAKEUP_PIN6)  		 || \
                                            ((__PIN__) == PWR_WAKEUP_PIN1_HIGH)  || \
                                            ((__PIN__) == PWR_WAKEUP_PIN2_HIGH)  || \
                                            ((__PIN__) == PWR_WAKEUP_PIN3_HIGH)  || \
                                            ((__PIN__) == PWR_WAKEUP_PIN4_HIGH)  || \
                                            ((__PIN__) == PWR_WAKEUP_PIN5_HIGH)  || \
                                            ((__PIN__) == PWR_WAKEUP_PIN6_HIGH)  || \
                                            ((__PIN__) == PWR_WAKEUP_PIN1_LOW)   || \
                                            ((__PIN__) == PWR_WAKEUP_PIN2_LOW)   || \
                                            ((__PIN__) == PWR_WAKEUP_PIN3_LOW)   || \
                                            ((__PIN__) == PWR_WAKEUP_PIN4_LOW)   || \
                                            ((__PIN__) == PWR_WAKEUP_PIN5_LOW)	 || \
                                            ((__PIN__) == PWR_WAKEUP_PIN6_LOW))




 


  
#ifdef __cplusplus
}
#endif


#endif 


