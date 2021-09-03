 


#ifndef __STM32F7xx_HAL_GPIO_EX_H
#define __STM32F7xx_HAL_GPIO_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"



 





  
  

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) || defined (STM32F767xx) ||\
    defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)   
 
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  

 
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF1_UART5         ((uint8_t)0x01U)  
#define GPIO_AF1_I2C4          ((uint8_t)0x01U)     
#endif 

 
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  
#define GPIO_AF2_TIM4          ((uint8_t)0x02U)  
#define GPIO_AF2_TIM5          ((uint8_t)0x02U)  

 
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  
#define GPIO_AF3_TIM9          ((uint8_t)0x03U)  
#define GPIO_AF3_TIM10         ((uint8_t)0x03U)  
#define GPIO_AF3_TIM11         ((uint8_t)0x03U)  
#define GPIO_AF3_LPTIM1        ((uint8_t)0x03U)  
#define GPIO_AF3_CEC           ((uint8_t)0x03U)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF3_DFSDM1         ((uint8_t)0x03U)  
#endif 
 
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  
#define GPIO_AF4_I2C4          ((uint8_t)0x04U)  
#define GPIO_AF4_CEC           ((uint8_t)0x04U)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF4_USART1        ((uint8_t)0x04)  
#endif    

 
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI4          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI5          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI6          ((uint8_t)0x05U)  

 
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  
#define GPIO_AF6_SAI1          ((uint8_t)0x06U)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF6_UART4         ((uint8_t)0x06U)      
#define GPIO_AF6_DFSDM1        ((uint8_t)0x06U)  
#endif    

 
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  
#define GPIO_AF7_UART5         ((uint8_t)0x07U)  
#define GPIO_AF7_SPDIFRX       ((uint8_t)0x07U)  
#define GPIO_AF7_SPI2          ((uint8_t)0x07U)  
#define GPIO_AF7_SPI3          ((uint8_t)0x07U)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF7_SPI6          ((uint8_t)0x07U)  
#define GPIO_AF7_DFSDM1         ((uint8_t)0x07U) 
#endif   

 
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  
#define GPIO_AF8_UART5         ((uint8_t)0x08U)  
#define GPIO_AF8_USART6        ((uint8_t)0x08U)  
#define GPIO_AF8_UART7         ((uint8_t)0x08U)  
#define GPIO_AF8_UART8         ((uint8_t)0x08U)  
#define GPIO_AF8_SPDIFRX       ((uint8_t)0x08U)  
#define GPIO_AF8_SAI2          ((uint8_t)0x08U)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF8_SPI6          ((uint8_t)0x08U)    
#endif     


 
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  
#define GPIO_AF9_CAN2          ((uint8_t)0x09U)  
#define GPIO_AF9_TIM12         ((uint8_t)0x09U)  
#define GPIO_AF9_TIM13         ((uint8_t)0x09U)  
#define GPIO_AF9_TIM14         ((uint8_t)0x09U)  
#define GPIO_AF9_QUADSPI       ((uint8_t)0x09U)  
#if defined(STM32F746xx) || defined(STM32F756xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx) || defined(STM32F750xx)
#define GPIO_AF9_LTDC          ((uint8_t)0x09U)  
#endif 
#if defined(STM32F746xx) || defined(STM32F756xx) || defined(STM32F765xx) || defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx) || defined(STM32F750xx)
#define GPIO_AF9_FMC           ((uint8_t)0x09U)   
#endif 
 
#define GPIO_AF10_OTG_FS        ((uint8_t)0xAU)  
#define GPIO_AF10_OTG_HS        ((uint8_t)0xAU)  
#define GPIO_AF10_QUADSPI       ((uint8_t)0xAU)  
#define GPIO_AF10_SAI2          ((uint8_t)0xAU)  
#if defined (STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define GPIO_AF10_DFSDM1         ((uint8_t)0x0AU)  
#define GPIO_AF10_SDMMC2         ((uint8_t)0x0AU)     
#define GPIO_AF10_LTDC           ((uint8_t)0x0AU)  
#endif    

 
#define GPIO_AF11_ETH           ((uint8_t)0x0BU)  
#if defined(STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define GPIO_AF11_CAN3          ((uint8_t)0x0BU)  
#define GPIO_AF11_SDMMC2        ((uint8_t)0x0BU)  
#define GPIO_AF11_I2C4          ((uint8_t)0x0BU)     
#endif 
   
 
#define GPIO_AF12_FMC           ((uint8_t)0xCU)  
#define GPIO_AF12_OTG_HS_FS     ((uint8_t)0xCU)  
#define GPIO_AF12_SDMMC1        ((uint8_t)0xCU)  
#if defined(STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)   
#define GPIO_AF12_MDIOS        ((uint8_t)0xCU)  
#define GPIO_AF12_UART7        ((uint8_t)0xCU)     
#endif 
   
 
#define GPIO_AF13_DCMI          ((uint8_t)0x0DU)  
#if defined (STM32F769xx) || defined (STM32F779xx)   
#define GPIO_AF13_DSI           ((uint8_t)0x0DU)  
#endif    
#if defined(STM32F746xx) || defined(STM32F756xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx) || defined(STM32F750xx)
#define GPIO_AF13_LTDC          ((uint8_t)0x0DU)     
   

#define GPIO_AF14_LTDC          ((uint8_t)0x0EU)  
#endif 
 
#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)  
#endif 


      
#if defined(STM32F722xx) || defined(STM32F723xx) || defined(STM32F732xx) || defined(STM32F733xx) || defined(STM32F730xx)
  
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  

 
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  

 
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  
#define GPIO_AF2_TIM4          ((uint8_t)0x02U)  
#define GPIO_AF2_TIM5          ((uint8_t)0x02U)  

 
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  
#define GPIO_AF3_TIM9          ((uint8_t)0x03U)  
#define GPIO_AF3_TIM10         ((uint8_t)0x03U)  
#define GPIO_AF3_TIM11         ((uint8_t)0x03U)  
#define GPIO_AF3_LPTIM1        ((uint8_t)0x03U)  

 
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)   

 
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI4          ((uint8_t)0x05U)  
#define GPIO_AF5_SPI5          ((uint8_t)0x05U)  

 
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  
#define GPIO_AF6_SAI1          ((uint8_t)0x06U)  

 
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  
#define GPIO_AF7_UART5         ((uint8_t)0x07U)  
#define GPIO_AF7_SPI2          ((uint8_t)0x07U)  
#define GPIO_AF7_SPI3          ((uint8_t)0x07U)   

 
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  
#define GPIO_AF8_UART5         ((uint8_t)0x08U)  
#define GPIO_AF8_USART6        ((uint8_t)0x08U)  
#define GPIO_AF8_UART7         ((uint8_t)0x08U)  
#define GPIO_AF8_UART8         ((uint8_t)0x08U)  
#define GPIO_AF8_SAI2          ((uint8_t)0x08U)  

 
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  
#define GPIO_AF9_TIM12         ((uint8_t)0x09U)  
#define GPIO_AF9_TIM13         ((uint8_t)0x09U)  
#define GPIO_AF9_TIM14         ((uint8_t)0x09U)  
#define GPIO_AF9_QUADSPI       ((uint8_t)0x09U)  

 
#define GPIO_AF10_OTG_FS        ((uint8_t)0xAU)  
#define GPIO_AF10_OTG_HS        ((uint8_t)0xAU)  
#define GPIO_AF10_QUADSPI       ((uint8_t)0xAU)  
#define GPIO_AF10_SAI2          ((uint8_t)0xAU)  
#define GPIO_AF10_SDMMC2        ((uint8_t)0x0AU)    

 
#define GPIO_AF11_SDMMC2        ((uint8_t)0x0BU) 
   
 
#define GPIO_AF12_FMC           ((uint8_t)0xCU)  
#define GPIO_AF12_OTG_HS_FS     ((uint8_t)0xCU)  
#define GPIO_AF12_SDMMC1        ((uint8_t)0xCU)  
   
 
#define GPIO_AF13_RNG           ((uint8_t)0x0DU)     
   
 
#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)       
#endif 


 







 









#define GPIOA_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOB_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOC_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOD_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOE_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOF_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOG_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOI_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOJ_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOH_PIN_AVAILABLE  GPIO_PIN_All
#define GPIOK_PIN_AVAILABLE  (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | \
                              GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)






#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define GPIO_GET_INDEX(__GPIOx__)   (uint8_t)(((__GPIOx__) == (GPIOA))? 0U :\
                                              ((__GPIOx__) == (GPIOB))? 1U :\
                                              ((__GPIOx__) == (GPIOC))? 2U :\
                                              ((__GPIOx__) == (GPIOD))? 3U :\
                                              ((__GPIOx__) == (GPIOE))? 4U :\
                                              ((__GPIOx__) == (GPIOF))? 5U :\
                                              ((__GPIOx__) == (GPIOG))? 6U :\
                                              ((__GPIOx__) == (GPIOH))? 7U :\
                                              ((__GPIOx__) == (GPIOI))? 8U :\
                                              ((__GPIOx__) == (GPIOJ))? 9U : 10U)
#endif 

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define GPIO_GET_INDEX(__GPIOx__)   (uint8_t)(((__GPIOx__) == (GPIOA))? 0U :\
                                              ((__GPIOx__) == (GPIOB))? 1U :\
                                              ((__GPIOx__) == (GPIOC))? 2U :\
                                              ((__GPIOx__) == (GPIOD))? 3U :\
                                              ((__GPIOx__) == (GPIOE))? 4U :\
                                              ((__GPIOx__) == (GPIOF))? 5U :\
                                              ((__GPIOx__) == (GPIOG))? 6U :\
                                              ((__GPIOx__) == (GPIOH))? 7U : 8U)
#endif 


#define IS_GPIO_PIN_AVAILABLE(__INSTANCE__,__PIN__)  \
           ((((__INSTANCE__) == GPIOA) && (((__PIN__) & (GPIOA_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOA_PIN_AVAILABLE)) == (GPIOA_PIN_AVAILABLE))) || \
            (((__INSTANCE__) == GPIOB) && (((__PIN__) & (GPIOB_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOB_PIN_AVAILABLE)) == (GPIOB_PIN_AVAILABLE))) || \
            (((__INSTANCE__) == GPIOC) && (((__PIN__) & (GPIOC_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOC_PIN_AVAILABLE)) == (GPIOC_PIN_AVAILABLE))) || \
            (((__INSTANCE__) == GPIOD) && (((__PIN__) & (GPIOD_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOD_PIN_AVAILABLE)) == (GPIOD_PIN_AVAILABLE))) || \
            (((__INSTANCE__) == GPIOE) && (((__PIN__) & (GPIOE_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOE_PIN_AVAILABLE)) == (GPIOE_PIN_AVAILABLE))) || \
            (((__INSTANCE__) == GPIOF) && (((__PIN__) & (GPIOF_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOF_PIN_AVAILABLE)) == (GPIOF_PIN_AVAILABLE))) || \
			(((__INSTANCE__) == GPIOG) && (((__PIN__) & (GPIOG_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOG_PIN_AVAILABLE)) == (GPIOG_PIN_AVAILABLE))) || \
			(((__INSTANCE__) == GPIOI) && (((__PIN__) & (GPIOI_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOI_PIN_AVAILABLE)) == (GPIOI_PIN_AVAILABLE))) || \
			(((__INSTANCE__) == GPIOJ) && (((__PIN__) & (GPIOJ_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOJ_PIN_AVAILABLE)) == (GPIOJ_PIN_AVAILABLE))) || \
			(((__INSTANCE__) == GPIOK) && (((__PIN__) & (GPIOK_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOK_PIN_AVAILABLE)) == (GPIOK_PIN_AVAILABLE))) || \
			(((__INSTANCE__) == GPIOH) && (((__PIN__) & (GPIOH_PIN_AVAILABLE)) != 0) && (((__PIN__) | (GPIOH_PIN_AVAILABLE)) == (GPIOH_PIN_AVAILABLE))))

#if defined(STM32F756xx) || defined(STM32F746xx)  || defined(STM32F750xx)
#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF0_RTC_50Hz)   || ((AF) == GPIO_AF1_TIM1)        || \
                          ((AF) == GPIO_AF0_SWJ)        || ((AF) == GPIO_AF0_TRACE)      || \
                          ((AF) == GPIO_AF0_MCO)       || ((AF) == GPIO_AF1_TIM2)       || \
                          ((AF) == GPIO_AF2_TIM3)       || ((AF) == GPIO_AF2_TIM4)       || \
                          ((AF) == GPIO_AF2_TIM5)       || ((AF) == GPIO_AF3_TIM8)       || \
                          ((AF) == GPIO_AF3_TIM9)       || ((AF) == GPIO_AF3_TIM10)      || \
                          ((AF) == GPIO_AF3_TIM11)      || ((AF) == GPIO_AF3_LPTIM1)     || \
                          ((AF) == GPIO_AF3_CEC)        || ((AF) == GPIO_AF4_CEC)        || \
                          ((AF) == GPIO_AF4_I2C1)       || ((AF) == GPIO_AF4_I2C2)       || \
                          ((AF) == GPIO_AF4_I2C3)       || ((AF) == GPIO_AF4_I2C4)       || \
                          ((AF) == GPIO_AF5_SPI1)       || ((AF) == GPIO_AF5_SPI2)       || \
                          ((AF) == GPIO_AF5_SPI3)       || ((AF) == GPIO_AF5_SPI4)       || \
                          ((AF) == GPIO_AF5_SPI5)       || ((AF) == GPIO_AF5_SPI6)       || \
                          ((AF) == GPIO_AF6_SPI3)       || ((AF) == GPIO_AF6_SAI1)       || \
                          ((AF) == GPIO_AF7_SPI3)       || ((AF) == GPIO_AF7_SPI2)        || \
                          ((AF) == GPIO_AF7_USART1)     || ((AF) == GPIO_AF7_USART2)      || \
                          ((AF) == GPIO_AF7_USART3)     || ((AF) == GPIO_AF7_UART5)       || \
                          ((AF) == GPIO_AF7_SPDIFRX)    || ((AF) == GPIO_AF8_SPDIFRX)     || \
                          ((AF) == GPIO_AF8_SAI2)       || ((AF) == GPIO_AF8_USART6)      || \
                          ((AF) == GPIO_AF8_UART4)      || ((AF) == GPIO_AF8_UART5)       || \
                          ((AF) == GPIO_AF8_UART7)      || ((AF) == GPIO_AF8_UART8)       || \
                          ((AF) == GPIO_AF9_CAN1)       || ((AF) == GPIO_AF9_CAN2)        || \
                          ((AF) == GPIO_AF9_TIM12)      || ((AF) == GPIO_AF9_TIM12)      || \
                          ((AF) == GPIO_AF9_TIM14)      || ((AF) == GPIO_AF9_QUADSPI)    || \
                          ((AF) == GPIO_AF9_LTDC)       || ((AF) == GPIO_AF10_OTG_FS)    || \
                          ((AF) == GPIO_AF10_OTG_HS)    || ((AF) == GPIO_AF10_SAI2)      || \
                          ((AF) == GPIO_AF10_QUADSPI)   || ((AF) == GPIO_AF11_ETH)       || \
                          ((AF) == GPIO_AF12_OTG_HS_FS) || ((AF) == GPIO_AF12_SDMMC1)     || \
                          ((AF) == GPIO_AF12_FMC)       || ((AF) == GPIO_AF15_EVENTOUT)  || \
                          ((AF) == GPIO_AF13_DCMI)      || ((AF) == GPIO_AF14_LTDC))
#elif defined(STM32F745xx)
#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF0_RTC_50Hz)   || ((AF) == GPIO_AF1_TIM1)       || \
                          ((AF) == GPIO_AF0_SWJ)        || ((AF) == GPIO_AF0_TRACE)      || \
                          ((AF) == GPIO_AF0_MCO)       || ((AF) == GPIO_AF1_TIM2)        || \
                          ((AF) == GPIO_AF2_TIM3)       || ((AF) == GPIO_AF2_TIM4)       || \
                          ((AF) == GPIO_AF2_TIM5)       || ((AF) == GPIO_AF3_TIM8)       || \
                          ((AF) == GPIO_AF3_TIM9)       || ((AF) == GPIO_AF3_TIM10)      || \
                          ((AF) == GPIO_AF3_TIM11)      || ((AF) == GPIO_AF3_LPTIM1)     || \
                          ((AF) == GPIO_AF3_CEC)        || ((AF) == GPIO_AF4_CEC)        || \
                          ((AF) == GPIO_AF4_I2C1)       || ((AF) == GPIO_AF4_I2C2)       || \
                          ((AF) == GPIO_AF4_I2C3)       || ((AF) == GPIO_AF4_I2C4)       || \
                          ((AF) == GPIO_AF5_SPI1)       || ((AF) == GPIO_AF5_SPI2)       || \
                          ((AF) == GPIO_AF5_SPI3)       || ((AF) == GPIO_AF5_SPI4)       || \
                          ((AF) == GPIO_AF5_SPI5)       || ((AF) == GPIO_AF5_SPI6)       || \
                          ((AF) == GPIO_AF6_SPI3)       || ((AF) == GPIO_AF6_SAI1)       || \
                          ((AF) == GPIO_AF7_SPI3)       || ((AF) == GPIO_AF7_SPI2)        || \
                          ((AF) == GPIO_AF7_USART1)     || ((AF) == GPIO_AF7_USART2)      || \
                          ((AF) == GPIO_AF7_USART3)     || ((AF) == GPIO_AF7_UART5)       || \
                          ((AF) == GPIO_AF7_SPDIFRX)    || ((AF) == GPIO_AF8_SPDIFRX)     || \
                          ((AF) == GPIO_AF8_SAI2)       || ((AF) == GPIO_AF8_USART6)      || \
                          ((AF) == GPIO_AF8_UART4)      || ((AF) == GPIO_AF8_UART5)       || \
                          ((AF) == GPIO_AF8_UART7)      || ((AF) == GPIO_AF8_UART8)       || \
                          ((AF) == GPIO_AF9_CAN1)       || ((AF) == GPIO_AF9_CAN2)        || \
                          ((AF) == GPIO_AF9_TIM12)      || ((AF) == GPIO_AF9_TIM12)      || \
                          ((AF) == GPIO_AF9_TIM14)      || ((AF) == GPIO_AF9_QUADSPI)    || \
                          ((AF) == GPIO_AF13_DCMI)      || ((AF) == GPIO_AF10_OTG_FS)    || \
                          ((AF) == GPIO_AF10_OTG_HS)    || ((AF) == GPIO_AF10_SAI2)      || \
                          ((AF) == GPIO_AF10_QUADSPI)   || ((AF) == GPIO_AF11_ETH)       || \
                          ((AF) == GPIO_AF12_OTG_HS_FS) || ((AF) == GPIO_AF12_SDMMC1)    || \
                          ((AF) == GPIO_AF12_FMC)       || ((AF) == GPIO_AF15_EVENTOUT))
#elif defined(STM32F767xx) || defined(STM32F777xx)
#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF0_RTC_50Hz)   || ((AF) == GPIO_AF1_TIM1)        || \
                          ((AF) == GPIO_AF0_SWJ)        || ((AF) == GPIO_AF0_TRACE)      || \
                          ((AF) == GPIO_AF0_MCO)       || ((AF) == GPIO_AF1_TIM2)       || \
                          ((AF) == GPIO_AF2_TIM3)       || ((AF) == GPIO_AF2_TIM4)       || \
                          ((AF) == GPIO_AF2_TIM5)       || ((AF) == GPIO_AF3_TIM8)       || \
                          ((AF) == GPIO_AF3_TIM9)       || ((AF) == GPIO_AF3_TIM10)      || \
                          ((AF) == GPIO_AF3_TIM11)      || ((AF) == GPIO_AF3_LPTIM1)     || \
                          ((AF) == GPIO_AF3_CEC)        || ((AF) == GPIO_AF4_CEC)        || \
                          ((AF) == GPIO_AF4_I2C1)       || ((AF) == GPIO_AF4_I2C2)       || \
                          ((AF) == GPIO_AF4_I2C3)       || ((AF) == GPIO_AF4_I2C4)       || \
                          ((AF) == GPIO_AF5_SPI1)       || ((AF) == GPIO_AF5_SPI2)       || \
                          ((AF) == GPIO_AF5_SPI3)       || ((AF) == GPIO_AF5_SPI4)       || \
                          ((AF) == GPIO_AF5_SPI5)       || ((AF) == GPIO_AF5_SPI6)       || \
                          ((AF) == GPIO_AF6_SPI3)       || ((AF) == GPIO_AF6_SAI1)       || \
                          ((AF) == GPIO_AF7_SPI3)       || ((AF) == GPIO_AF7_SPI2)       || \
                          ((AF) == GPIO_AF7_USART1)     || ((AF) == GPIO_AF7_USART2)     || \
                          ((AF) == GPIO_AF7_USART3)     || ((AF) == GPIO_AF7_UART5)      || \
                          ((AF) == GPIO_AF7_SPDIFRX)    || ((AF) == GPIO_AF8_SPDIFRX)    || \
                          ((AF) == GPIO_AF8_SAI2)       || ((AF) == GPIO_AF8_USART6)     || \
                          ((AF) == GPIO_AF8_UART4)      || ((AF) == GPIO_AF8_UART5)      || \
                          ((AF) == GPIO_AF8_UART7)      || ((AF) == GPIO_AF8_UART8)      || \
                          ((AF) == GPIO_AF9_CAN1)       || ((AF) == GPIO_AF9_CAN2)       || \
                          ((AF) == GPIO_AF9_TIM12)      || ((AF) == GPIO_AF9_TIM12)      || \
                          ((AF) == GPIO_AF9_TIM14)      || ((AF) == GPIO_AF9_QUADSPI)    || \
                          ((AF) == GPIO_AF10_OTG_FS)    || ((AF) == GPIO_AF9_LTDC)       || \
                          ((AF) == GPIO_AF10_OTG_HS)    || ((AF) == GPIO_AF10_SAI2)      || \
                          ((AF) == GPIO_AF10_QUADSPI)   || ((AF) == GPIO_AF11_ETH)       || \
                          ((AF) == GPIO_AF10_SDMMC2)    || ((AF) == GPIO_AF11_SDMMC2)    || \
                          ((AF) == GPIO_AF11_CAN3)      || ((AF) == GPIO_AF12_OTG_HS_FS) || \
                          ((AF) == GPIO_AF12_SDMMC1)    || ((AF) == GPIO_AF12_FMC)       || \
                          ((AF) == GPIO_AF15_EVENTOUT)  || ((AF) == GPIO_AF13_DCMI)      || \
		                  ((AF) == GPIO_AF14_LTDC))
#elif defined(STM32F769xx) || defined(STM32F779xx)
#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF0_RTC_50Hz)   || ((AF) == GPIO_AF1_TIM1)        || \
                          ((AF) == GPIO_AF0_SWJ)        || ((AF) == GPIO_AF0_TRACE)      || \
                          ((AF) == GPIO_AF0_MCO)        || ((AF) == GPIO_AF1_TIM2)       || \
                          ((AF) == GPIO_AF2_TIM3)       || ((AF) == GPIO_AF2_TIM4)       || \
                          ((AF) == GPIO_AF2_TIM5)       || ((AF) == GPIO_AF3_TIM8)       || \
                          ((AF) == GPIO_AF3_TIM9)       || ((AF) == GPIO_AF3_TIM10)      || \
                          ((AF) == GPIO_AF3_TIM11)      || ((AF) == GPIO_AF3_LPTIM1)     || \
                          ((AF) == GPIO_AF3_CEC)        || ((AF) == GPIO_AF4_CEC)        || \
                          ((AF) == GPIO_AF4_I2C1)       || ((AF) == GPIO_AF4_I2C2)       || \
                          ((AF) == GPIO_AF4_I2C3)       || ((AF) == GPIO_AF4_I2C4)       || \
                          ((AF) == GPIO_AF5_SPI1)       || ((AF) == GPIO_AF5_SPI2)       || \
                          ((AF) == GPIO_AF5_SPI3)       || ((AF) == GPIO_AF5_SPI4)       || \
                          ((AF) == GPIO_AF5_SPI5)       || ((AF) == GPIO_AF5_SPI6)       || \
                          ((AF) == GPIO_AF6_SPI3)       || ((AF) == GPIO_AF6_SAI1)       || \
                          ((AF) == GPIO_AF7_SPI3)       || ((AF) == GPIO_AF7_SPI2)       || \
                          ((AF) == GPIO_AF7_USART1)     || ((AF) == GPIO_AF7_USART2)     || \
                          ((AF) == GPIO_AF7_USART3)     || ((AF) == GPIO_AF7_UART5)      || \
                          ((AF) == GPIO_AF7_SPDIFRX)    || ((AF) == GPIO_AF8_SPDIFRX)    || \
                          ((AF) == GPIO_AF8_SAI2)       || ((AF) == GPIO_AF8_USART6)     || \
                          ((AF) == GPIO_AF8_UART4)      || ((AF) == GPIO_AF8_UART5)      || \
                          ((AF) == GPIO_AF8_UART7)      || ((AF) == GPIO_AF8_UART8)      || \
                          ((AF) == GPIO_AF9_CAN1)       || ((AF) == GPIO_AF9_CAN2)       || \
                          ((AF) == GPIO_AF9_TIM12)      || ((AF) == GPIO_AF9_TIM12)      || \
                          ((AF) == GPIO_AF9_TIM14)      || ((AF) == GPIO_AF9_QUADSPI)    || \
                          ((AF) == GPIO_AF9_LTDC)       || ((AF) == GPIO_AF10_OTG_FS)    || \
                          ((AF) == GPIO_AF10_OTG_HS)    || ((AF) == GPIO_AF10_SAI2)      || \
                          ((AF) == GPIO_AF10_QUADSPI)   || ((AF) == GPIO_AF11_ETH)       || \
                          ((AF) == GPIO_AF10_SDMMC2)    || ((AF) == GPIO_AF11_SDMMC2)    || \
                          ((AF) == GPIO_AF11_CAN3)      || ((AF) == GPIO_AF12_OTG_HS_FS) || \
                          ((AF) == GPIO_AF12_SDMMC1)    || ((AF) == GPIO_AF12_FMC)       || \
                          ((AF) == GPIO_AF15_EVENTOUT)  || ((AF) == GPIO_AF13_DCMI)      || \
                          ((AF) == GPIO_AF14_LTDC)      || ((AF) == GPIO_AF13_DSI))
#elif defined(STM32F765xx)
#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF0_RTC_50Hz)   || ((AF) == GPIO_AF1_TIM1)        || \
                          ((AF) == GPIO_AF0_SWJ)        || ((AF) == GPIO_AF0_TRACE)      || \
                          ((AF) == GPIO_AF0_MCO)        || ((AF) == GPIO_AF1_TIM2)       || \
                          ((AF) == GPIO_AF2_TIM3)       || ((AF) == GPIO_AF2_TIM4)       || \
                          ((AF) == GPIO_AF2_TIM5)       || ((AF) == GPIO_AF3_TIM8)       || \
                          ((AF) == GPIO_AF3_TIM9)       || ((AF) == GPIO_AF3_TIM10)      || \
                          ((AF) == GPIO_AF3_TIM11)      || ((AF) == GPIO_AF3_LPTIM1)     || \
                          ((AF) == GPIO_AF3_CEC)        || ((AF) == GPIO_AF4_CEC)        || \
                          ((AF) == GPIO_AF4_I2C1)       || ((AF) == GPIO_AF4_I2C2)       || \
                          ((AF) == GPIO_AF4_I2C3)       || ((AF) == GPIO_AF4_I2C4)       || \
                          ((AF) == GPIO_AF5_SPI1)       || ((AF) == GPIO_AF5_SPI2)       || \
                          ((AF) == GPIO_AF5_SPI3)       || ((AF) == GPIO_AF5_SPI4)       || \
                          ((AF) == GPIO_AF5_SPI5)       || ((AF) == GPIO_AF5_SPI6)       || \
                          ((AF) == GPIO_AF6_SPI3)       || ((AF) == GPIO_AF6_SAI1)       || \
                          ((AF) == GPIO_AF7_SPI3)       || ((AF) == GPIO_AF7_SPI2)       || \
                          ((AF) == GPIO_AF7_USART1)     || ((AF) == GPIO_AF7_USART2)     || \
                          ((AF) == GPIO_AF7_USART3)     || ((AF) == GPIO_AF7_UART5)      || \
                          ((AF) == GPIO_AF7_SPDIFRX)    || ((AF) == GPIO_AF8_SPDIFRX)    || \
                          ((AF) == GPIO_AF8_SAI2)       || ((AF) == GPIO_AF8_USART6)     || \
                          ((AF) == GPIO_AF8_UART4)      || ((AF) == GPIO_AF8_UART5)      || \
                          ((AF) == GPIO_AF8_UART7)      || ((AF) == GPIO_AF8_UART8)      || \
                          ((AF) == GPIO_AF9_CAN1)       || ((AF) == GPIO_AF9_CAN2)       || \
                          ((AF) == GPIO_AF9_TIM12)      || ((AF) == GPIO_AF9_TIM12)      || \
                          ((AF) == GPIO_AF9_TIM14)      || ((AF) == GPIO_AF9_QUADSPI)    || \
                          ((AF) == GPIO_AF10_OTG_HS)    || ((AF) == GPIO_AF10_SAI2)      || \
                          ((AF) == GPIO_AF10_QUADSPI)   || ((AF) == GPIO_AF11_ETH)       || \
                          ((AF) == GPIO_AF10_SDMMC2)    || ((AF) == GPIO_AF11_SDMMC2)    || \
                          ((AF) == GPIO_AF11_CAN3)      || ((AF) == GPIO_AF12_OTG_HS_FS) || \
                          ((AF) == GPIO_AF12_SDMMC1)    || ((AF) == GPIO_AF12_FMC)       || \
                          ((AF) == GPIO_AF15_EVENTOUT)  || ((AF) == GPIO_AF13_DCMI)      || \
                          ((AF) == GPIO_AF10_OTG_FS))
#elif defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF0_RTC_50Hz)   || ((AF) == GPIO_AF1_TIM1)        || \
                          ((AF) == GPIO_AF0_SWJ)        || ((AF) == GPIO_AF0_TRACE)      || \
                          ((AF) == GPIO_AF0_MCO)        || ((AF) == GPIO_AF1_TIM2)       || \
                          ((AF) == GPIO_AF2_TIM3)       || ((AF) == GPIO_AF2_TIM4)       || \
                          ((AF) == GPIO_AF2_TIM5)       || ((AF) == GPIO_AF3_TIM8)       || \
                          ((AF) == GPIO_AF3_TIM9)       || ((AF) == GPIO_AF3_TIM10)      || \
                          ((AF) == GPIO_AF3_TIM11)      || ((AF) == GPIO_AF3_LPTIM1)     || \
                          ((AF) == GPIO_AF4_I2C1)       || ((AF) == GPIO_AF4_I2C2)       || \
                          ((AF) == GPIO_AF4_I2C3)       || ((AF) == GPIO_AF5_SPI1)       || \
                          ((AF) == GPIO_AF5_SPI2)       || ((AF) == GPIO_AF5_SPI3)       || \
                          ((AF) == GPIO_AF5_SPI4)       || ((AF) == GPIO_AF5_SPI5)       || \
                          ((AF) == GPIO_AF6_SPI3)       || ((AF) == GPIO_AF6_SAI1)       || \
                          ((AF) == GPIO_AF7_SPI3)       || ((AF) == GPIO_AF7_SPI2)       || \
                          ((AF) == GPIO_AF7_USART1)     || ((AF) == GPIO_AF7_USART2)     || \
                          ((AF) == GPIO_AF7_USART3)     || ((AF) == GPIO_AF7_UART5)      || \
                          ((AF) == GPIO_AF8_SAI2)       || ((AF) == GPIO_AF8_USART6)     || \
                          ((AF) == GPIO_AF8_UART4)      || ((AF) == GPIO_AF8_UART5)      || \
                          ((AF) == GPIO_AF8_UART7)      || ((AF) == GPIO_AF8_UART8)      || \
                          ((AF) == GPIO_AF9_CAN1)       || ((AF) == GPIO_AF9_TIM12)      || \
                          ((AF) == GPIO_AF9_TIM12)      || ((AF) == GPIO_AF9_TIM14)      || \
                          ((AF) == GPIO_AF9_QUADSPI)    || ((AF) == GPIO_AF10_OTG_HS)    || \
                          ((AF) == GPIO_AF10_SAI2)      || ((AF) == GPIO_AF10_QUADSPI)   || \
                          ((AF) == GPIO_AF10_SDMMC2)    || ((AF) == GPIO_AF11_SDMMC2)    || \
                          ((AF) == GPIO_AF12_OTG_HS_FS) || ((AF) == GPIO_AF12_SDMMC1)    || \
                          ((AF) == GPIO_AF12_FMC)       || ((AF) == GPIO_AF15_EVENTOUT)  || \
                          ((AF) == GPIO_AF10_OTG_FS))
#endif 
 








 

 
  
#ifdef __cplusplus
}
#endif

#endif 


