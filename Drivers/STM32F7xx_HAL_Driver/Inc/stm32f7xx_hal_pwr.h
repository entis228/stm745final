 


#ifndef __STM32F7xx_HAL_PWR_H
#define __STM32F7xx_HAL_PWR_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"



 




   

typedef struct
{
  uint32_t PVDLevel;   

  uint32_t Mode;      
}PWR_PVDTypeDef;






 
#define PWR_PVDLEVEL_0                  PWR_CR1_PLS_LEV0
#define PWR_PVDLEVEL_1                  PWR_CR1_PLS_LEV1
#define PWR_PVDLEVEL_2                  PWR_CR1_PLS_LEV2
#define PWR_PVDLEVEL_3                  PWR_CR1_PLS_LEV3
#define PWR_PVDLEVEL_4                  PWR_CR1_PLS_LEV4
#define PWR_PVDLEVEL_5                  PWR_CR1_PLS_LEV5
#define PWR_PVDLEVEL_6                  PWR_CR1_PLS_LEV6
#define PWR_PVDLEVEL_7                  PWR_CR1_PLS_LEV7

   
 

#define PWR_PVD_MODE_NORMAL                 ((uint32_t)0x00000000U)   
#define PWR_PVD_MODE_IT_RISING              ((uint32_t)0x00010001U)   
#define PWR_PVD_MODE_IT_FALLING             ((uint32_t)0x00010002U)   
#define PWR_PVD_MODE_IT_RISING_FALLING      ((uint32_t)0x00010003U)   
#define PWR_PVD_MODE_EVENT_RISING           ((uint32_t)0x00020001U)   
#define PWR_PVD_MODE_EVENT_FALLING          ((uint32_t)0x00020002U)   
#define PWR_PVD_MODE_EVENT_RISING_FALLING   ((uint32_t)0x00020003U)   



#define PWR_MAINREGULATOR_ON                        ((uint32_t)0x00000000U)
#define PWR_LOWPOWERREGULATOR_ON                    PWR_CR1_LPDS

    

#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01U)
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02U)



#define PWR_STOPENTRY_WFI               ((uint8_t)0x01U)
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02U)



#define PWR_REGULATOR_VOLTAGE_SCALE1         PWR_CR1_VOS
#define PWR_REGULATOR_VOLTAGE_SCALE2         PWR_CR1_VOS_1
#define PWR_REGULATOR_VOLTAGE_SCALE3         PWR_CR1_VOS_0



#define PWR_FLAG_WU                     PWR_CSR1_WUIF
#define PWR_FLAG_SB                     PWR_CSR1_SBF
#define PWR_FLAG_PVDO                   PWR_CSR1_PVDO
#define PWR_FLAG_BRR                    PWR_CSR1_BRR
#define PWR_FLAG_VOSRDY                 PWR_CSR1_VOSRDY


 
  




#define __HAL_PWR_VOLTAGESCALING_CONFIG(__REGULATOR__) do {                                                     \
                                                            __IO uint32_t tmpreg;                               \
                                                            MODIFY_REG(PWR->CR1, PWR_CR1_VOS, (__REGULATOR__)); \
                                                              \
                                                            tmpreg = READ_BIT(PWR->CR1, PWR_CR1_VOS);           \
                                                            UNUSED(tmpreg);                                     \
				                                                	} while(0)


#define __HAL_PWR_GET_FLAG(__FLAG__) ((PWR->CSR1 & (__FLAG__)) == (__FLAG__))


#define __HAL_PWR_CLEAR_FLAG(__FLAG__) (PWR->CR1 |=  (__FLAG__) << 2)


#define __HAL_PWR_PVD_EXTI_ENABLE_IT()   (EXTI->IMR |= (PWR_EXTI_LINE_PVD))


#define __HAL_PWR_PVD_EXTI_DISABLE_IT()  (EXTI->IMR &= ~(PWR_EXTI_LINE_PVD))


#define __HAL_PWR_PVD_EXTI_ENABLE_EVENT()   (EXTI->EMR |= (PWR_EXTI_LINE_PVD))


#define __HAL_PWR_PVD_EXTI_DISABLE_EVENT()  (EXTI->EMR &= ~(PWR_EXTI_LINE_PVD))


#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)


#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)


#define __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE()   SET_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)



#define __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)



#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_FALLING_EDGE()   __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();


#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_FALLING_EDGE()  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();


#define __HAL_PWR_PVD_EXTI_GET_FLAG()  (EXTI->PR & (PWR_EXTI_LINE_PVD))


#define __HAL_PWR_PVD_EXTI_CLEAR_FLAG()  (EXTI->PR = (PWR_EXTI_LINE_PVD))


#define __HAL_PWR_PVD_EXTI_GENERATE_SWIT() (EXTI->SWIER |= (PWR_EXTI_LINE_PVD))




#include "stm32f7xx_hal_pwr_ex.h"



  


void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);





void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);


void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinPolarity);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);


void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(void);


void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);


void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);










#define PWR_EXTI_LINE_PVD  ((uint32_t)EXTI_IMR_IM16)  







#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLEVEL_0) || ((LEVEL) == PWR_PVDLEVEL_1)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_2) || ((LEVEL) == PWR_PVDLEVEL_3)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_4) || ((LEVEL) == PWR_PVDLEVEL_5)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_6) || ((LEVEL) == PWR_PVDLEVEL_7))
#define IS_PWR_PVD_MODE(MODE) (((MODE) == PWR_PVD_MODE_IT_RISING)|| ((MODE) == PWR_PVD_MODE_IT_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_IT_RISING_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING) || \
                              ((MODE) == PWR_PVD_MODE_EVENT_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_NORMAL))
#define IS_PWR_REGULATOR(REGULATOR) (((REGULATOR) == PWR_MAINREGULATOR_ON) || \
                                     ((REGULATOR) == PWR_LOWPOWERREGULATOR_ON))
#define IS_PWR_SLEEP_ENTRY(ENTRY) (((ENTRY) == PWR_SLEEPENTRY_WFI) || ((ENTRY) == PWR_SLEEPENTRY_WFE))
#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPENTRY_WFI) || ((ENTRY) == PWR_STOPENTRY_WFE))
#define IS_PWR_REGULATOR_VOLTAGE(VOLTAGE) (((VOLTAGE) == PWR_REGULATOR_VOLTAGE_SCALE1) || \
                                           ((VOLTAGE) == PWR_REGULATOR_VOLTAGE_SCALE2) || \
                                           ((VOLTAGE) == PWR_REGULATOR_VOLTAGE_SCALE3))





 


  
#ifdef __cplusplus
}
#endif


#endif 


