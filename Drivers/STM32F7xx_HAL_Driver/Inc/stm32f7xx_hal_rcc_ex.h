


#ifndef __STM32F7xx_HAL_RCC_EX_H
#define __STM32F7xx_HAL_RCC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"









typedef struct
{
  uint32_t PLLState;   

  uint32_t PLLSource;  

  uint32_t PLLM;       

  uint32_t PLLN;       

  uint32_t PLLP;       

  uint32_t PLLQ;       
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
  uint32_t PLLR;       
#endif 

}RCC_PLLInitTypeDef;


typedef struct
{
  uint32_t PLLI2SN;    

  uint32_t PLLI2SR;    

  uint32_t PLLI2SQ;    

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) || defined (STM32F767xx) || \
    defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
  uint32_t PLLI2SP;    
#endif 
}RCC_PLLI2SInitTypeDef;


typedef struct
{
  uint32_t PLLSAIN;    

  uint32_t PLLSAIQ;    

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) || defined (STM32F767xx) || \
    defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
  uint32_t PLLSAIR;    
#endif 

  uint32_t PLLSAIP;    
}RCC_PLLSAIInitTypeDef;


typedef struct
{
  uint32_t PeriphClockSelection; 

  RCC_PLLI2SInitTypeDef PLLI2S;  

  RCC_PLLSAIInitTypeDef PLLSAI;  

  uint32_t PLLI2SDivQ;           

  uint32_t PLLSAIDivQ;           

  uint32_t PLLSAIDivR;           

  uint32_t RTCClockSelection;      

  uint32_t I2sClockSelection;      

  uint32_t TIMPresSelection;      

  uint32_t Sai1ClockSelection;     

  uint32_t Sai2ClockSelection;     

  uint32_t Usart1ClockSelection; 

  uint32_t Usart2ClockSelection; 

  uint32_t Usart3ClockSelection; 

  uint32_t Uart4ClockSelection;  

  uint32_t Uart5ClockSelection;  

  uint32_t Usart6ClockSelection;  

  uint32_t Uart7ClockSelection;  

  uint32_t Uart8ClockSelection;  

  uint32_t I2c1ClockSelection;   

  uint32_t I2c2ClockSelection;   

  uint32_t I2c3ClockSelection;   

  uint32_t I2c4ClockSelection;   

  uint32_t Lptim1ClockSelection;   

  uint32_t CecClockSelection;      

  uint32_t Clk48ClockSelection;    

  uint32_t Sdmmc1ClockSelection;     

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
  uint32_t Sdmmc2ClockSelection;     
#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
  uint32_t Dfsdm1ClockSelection;     

  uint32_t Dfsdm1AudioClockSelection; 
#endif 
}RCC_PeriphCLKInitTypeDef;






#define RCC_PERIPHCLK_I2S             ((uint32_t)0x00000001U)
#if defined(STM32F746xx) || defined(STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define RCC_PERIPHCLK_LTDC            ((uint32_t)0x00000008U)
#endif 
#define RCC_PERIPHCLK_TIM             ((uint32_t)0x00000010U)
#define RCC_PERIPHCLK_RTC             ((uint32_t)0x00000020U)
#define RCC_PERIPHCLK_USART1          ((uint32_t)0x00000040U)
#define RCC_PERIPHCLK_USART2          ((uint32_t)0x00000080U)
#define RCC_PERIPHCLK_USART3          ((uint32_t)0x00000100U)
#define RCC_PERIPHCLK_UART4           ((uint32_t)0x00000200U)
#define RCC_PERIPHCLK_UART5           ((uint32_t)0x00000400U)
#define RCC_PERIPHCLK_USART6          ((uint32_t)0x00000800U)
#define RCC_PERIPHCLK_UART7           ((uint32_t)0x00001000U)
#define RCC_PERIPHCLK_UART8           ((uint32_t)0x00002000U)
#define RCC_PERIPHCLK_I2C1            ((uint32_t)0x00004000U)
#define RCC_PERIPHCLK_I2C2            ((uint32_t)0x00008000U)
#define RCC_PERIPHCLK_I2C3            ((uint32_t)0x00010000U)
#define RCC_PERIPHCLK_I2C4            ((uint32_t)0x00020000U)
#define RCC_PERIPHCLK_LPTIM1          ((uint32_t)0x00040000U)
#define RCC_PERIPHCLK_SAI1            ((uint32_t)0x00080000U)
#define RCC_PERIPHCLK_SAI2            ((uint32_t)0x00100000U)
#define RCC_PERIPHCLK_CLK48           ((uint32_t)0x00200000U)
#define RCC_PERIPHCLK_CEC             ((uint32_t)0x00400000U)
#define RCC_PERIPHCLK_SDMMC1          ((uint32_t)0x00800000U)
#define RCC_PERIPHCLK_SPDIFRX         ((uint32_t)0x01000000U)
#define RCC_PERIPHCLK_PLLI2S          ((uint32_t)0x02000000U)
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define RCC_PERIPHCLK_SDMMC2          ((uint32_t)0x04000000U)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define RCC_PERIPHCLK_DFSDM1           ((uint32_t)0x08000000U)
#define RCC_PERIPHCLK_DFSDM1_AUDIO     ((uint32_t)0x10000000U)
#endif 



#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) || defined (STM32F767xx) || \
    defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)

#define RCC_PLLI2SP_DIV2                  ((uint32_t)0x00000000U)
#define RCC_PLLI2SP_DIV4                  ((uint32_t)0x00000001U)
#define RCC_PLLI2SP_DIV6                  ((uint32_t)0x00000002U)
#define RCC_PLLI2SP_DIV8                  ((uint32_t)0x00000003U)

#endif 


#define RCC_PLLSAIP_DIV2                  ((uint32_t)0x00000000U)
#define RCC_PLLSAIP_DIV4                  ((uint32_t)0x00000001U)
#define RCC_PLLSAIP_DIV6                  ((uint32_t)0x00000002U)
#define RCC_PLLSAIP_DIV8                  ((uint32_t)0x00000003U)



#define RCC_PLLSAIDIVR_2                ((uint32_t)0x00000000U)
#define RCC_PLLSAIDIVR_4                RCC_DCKCFGR1_PLLSAIDIVR_0
#define RCC_PLLSAIDIVR_8                RCC_DCKCFGR1_PLLSAIDIVR_1
#define RCC_PLLSAIDIVR_16               RCC_DCKCFGR1_PLLSAIDIVR



#define RCC_I2SCLKSOURCE_PLLI2S             ((uint32_t)0x00000000U)
#define RCC_I2SCLKSOURCE_EXT                RCC_CFGR_I2SSRC




#define RCC_SAI1CLKSOURCE_PLLSAI             ((uint32_t)0x00000000U)
#define RCC_SAI1CLKSOURCE_PLLI2S             RCC_DCKCFGR1_SAI1SEL_0
#define RCC_SAI1CLKSOURCE_PIN                RCC_DCKCFGR1_SAI1SEL_1
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define RCC_SAI1CLKSOURCE_PLLSRC             RCC_DCKCFGR1_SAI1SEL
#endif 



#define RCC_SAI2CLKSOURCE_PLLSAI             ((uint32_t)0x00000000U)
#define RCC_SAI2CLKSOURCE_PLLI2S             RCC_DCKCFGR1_SAI2SEL_0
#define RCC_SAI2CLKSOURCE_PIN                RCC_DCKCFGR1_SAI2SEL_1
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define RCC_SAI2CLKSOURCE_PLLSRC             RCC_DCKCFGR1_SAI2SEL
#endif 



#define RCC_CECCLKSOURCE_LSE             ((uint32_t)0x00000000U)
#define RCC_CECCLKSOURCE_HSI             RCC_DCKCFGR2_CECSEL 



#define RCC_USART1CLKSOURCE_PCLK2      ((uint32_t)0x00000000U)
#define RCC_USART1CLKSOURCE_SYSCLK     RCC_DCKCFGR2_USART1SEL_0
#define RCC_USART1CLKSOURCE_HSI        RCC_DCKCFGR2_USART1SEL_1
#define RCC_USART1CLKSOURCE_LSE        RCC_DCKCFGR2_USART1SEL



#define RCC_USART2CLKSOURCE_PCLK1       ((uint32_t)0x00000000U)
#define RCC_USART2CLKSOURCE_SYSCLK     RCC_DCKCFGR2_USART2SEL_0
#define RCC_USART2CLKSOURCE_HSI        RCC_DCKCFGR2_USART2SEL_1
#define RCC_USART2CLKSOURCE_LSE        RCC_DCKCFGR2_USART2SEL



#define RCC_USART3CLKSOURCE_PCLK1       ((uint32_t)0x00000000U)
#define RCC_USART3CLKSOURCE_SYSCLK     RCC_DCKCFGR2_USART3SEL_0
#define RCC_USART3CLKSOURCE_HSI        RCC_DCKCFGR2_USART3SEL_1
#define RCC_USART3CLKSOURCE_LSE        RCC_DCKCFGR2_USART3SEL



#define RCC_UART4CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_UART4CLKSOURCE_SYSCLK       RCC_DCKCFGR2_UART4SEL_0
#define RCC_UART4CLKSOURCE_HSI          RCC_DCKCFGR2_UART4SEL_1
#define RCC_UART4CLKSOURCE_LSE          RCC_DCKCFGR2_UART4SEL



#define RCC_UART5CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_UART5CLKSOURCE_SYSCLK       RCC_DCKCFGR2_UART5SEL_0
#define RCC_UART5CLKSOURCE_HSI          RCC_DCKCFGR2_UART5SEL_1
#define RCC_UART5CLKSOURCE_LSE          RCC_DCKCFGR2_UART5SEL



#define RCC_USART6CLKSOURCE_PCLK2       ((uint32_t)0x00000000U)
#define RCC_USART6CLKSOURCE_SYSCLK      RCC_DCKCFGR2_USART6SEL_0
#define RCC_USART6CLKSOURCE_HSI         RCC_DCKCFGR2_USART6SEL_1
#define RCC_USART6CLKSOURCE_LSE         RCC_DCKCFGR2_USART6SEL



#define RCC_UART7CLKSOURCE_PCLK1       ((uint32_t)0x00000000U)
#define RCC_UART7CLKSOURCE_SYSCLK      RCC_DCKCFGR2_UART7SEL_0
#define RCC_UART7CLKSOURCE_HSI         RCC_DCKCFGR2_UART7SEL_1
#define RCC_UART7CLKSOURCE_LSE         RCC_DCKCFGR2_UART7SEL



#define RCC_UART8CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_UART8CLKSOURCE_SYSCLK      RCC_DCKCFGR2_UART8SEL_0
#define RCC_UART8CLKSOURCE_HSI         RCC_DCKCFGR2_UART8SEL_1
#define RCC_UART8CLKSOURCE_LSE         RCC_DCKCFGR2_UART8SEL



#define RCC_I2C1CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_I2C1CLKSOURCE_SYSCLK       RCC_DCKCFGR2_I2C1SEL_0
#define RCC_I2C1CLKSOURCE_HSI          RCC_DCKCFGR2_I2C1SEL_1



#define RCC_I2C2CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_I2C2CLKSOURCE_SYSCLK       RCC_DCKCFGR2_I2C2SEL_0
#define RCC_I2C2CLKSOURCE_HSI          RCC_DCKCFGR2_I2C2SEL_1




#define RCC_I2C3CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_I2C3CLKSOURCE_SYSCLK       RCC_DCKCFGR2_I2C3SEL_0
#define RCC_I2C3CLKSOURCE_HSI          RCC_DCKCFGR2_I2C3SEL_1



#define RCC_I2C4CLKSOURCE_PCLK1        ((uint32_t)0x00000000U)
#define RCC_I2C4CLKSOURCE_SYSCLK       RCC_DCKCFGR2_I2C4SEL_0
#define RCC_I2C4CLKSOURCE_HSI          RCC_DCKCFGR2_I2C4SEL_1



#define RCC_LPTIM1CLKSOURCE_PCLK1       ((uint32_t)0x00000000U)
#define RCC_LPTIM1CLKSOURCE_LSI        RCC_DCKCFGR2_LPTIM1SEL_0
#define RCC_LPTIM1CLKSOURCE_HSI        RCC_DCKCFGR2_LPTIM1SEL_1
#define RCC_LPTIM1CLKSOURCE_LSE        RCC_DCKCFGR2_LPTIM1SEL




#define RCC_CLK48SOURCE_PLL         ((uint32_t)0x00000000U)
#define RCC_CLK48SOURCE_PLLSAIP     RCC_DCKCFGR2_CK48MSEL



#define RCC_TIMPRES_DESACTIVATED        ((uint32_t)0x00000000U)
#define RCC_TIMPRES_ACTIVATED           RCC_DCKCFGR1_TIMPRE



#define RCC_SDMMC1CLKSOURCE_CLK48              ((uint32_t)0x00000000U)
#define RCC_SDMMC1CLKSOURCE_SYSCLK             RCC_DCKCFGR2_SDMMC1SEL


#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)

#define RCC_SDMMC2CLKSOURCE_CLK48              ((uint32_t)0x00000000U)
#define RCC_SDMMC2CLKSOURCE_SYSCLK             RCC_DCKCFGR2_SDMMC2SEL

#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)

#define RCC_DFSDM1CLKSOURCE_PCLK2             ((uint32_t)0x00000000U)
#define RCC_DFSDM1CLKSOURCE_SYSCLK           RCC_DCKCFGR1_DFSDM1SEL



#define RCC_DFSDM1AUDIOCLKSOURCE_SAI1        ((uint32_t)0x00000000U)
#define RCC_DFSDM1AUDIOCLKSOURCE_SAI2        RCC_DCKCFGR1_ADFSDM1SEL

#endif 

#if defined (STM32F769xx) || defined (STM32F779xx)

#define RCC_DSICLKSOURCE_DSIPHY             ((uint32_t)0x00000000U)
#define RCC_DSICLKSOURCE_PLLR               ((uint32_t)RCC_DCKCFGR2_DSISEL)

#endif 








#define __HAL_RCC_BKPSRAM_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_BKPSRAMEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_BKPSRAMEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_DTCMRAMEN_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DTCMRAMEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DTCMRAMEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USB_OTG_HS_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_OTGHSEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_OTGHSEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_OTGHSULPIEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_OTGHSULPIEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOD_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOH_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOI_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOIEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOIEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_GPIOJ_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOJEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOJEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_GPIOK_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOKEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOKEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_DMA2D_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#define __HAL_RCC_BKPSRAM_CLK_DISABLE()         (RCC->AHB1ENR &= ~(RCC_AHB1ENR_BKPSRAMEN))
#define __HAL_RCC_DTCMRAMEN_CLK_DISABLE()       (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DTCMRAMEN))
#define __HAL_RCC_DMA2_CLK_DISABLE()            (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2EN))
#define __HAL_RCC_USB_OTG_HS_CLK_DISABLE()      (RCC->AHB1ENR &= ~(RCC_AHB1ENR_OTGHSEN))
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE() (RCC->AHB1ENR &= ~(RCC_AHB1ENR_OTGHSULPIEN))
#define __HAL_RCC_GPIOA_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN))
#define __HAL_RCC_GPIOB_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOBEN))
#define __HAL_RCC_GPIOC_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOCEN))
#define __HAL_RCC_GPIOD_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIODEN))
#define __HAL_RCC_GPIOE_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOEEN))
#define __HAL_RCC_GPIOF_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOFEN))
#define __HAL_RCC_GPIOG_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOGEN))
#define __HAL_RCC_GPIOH_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOHEN))
#define __HAL_RCC_GPIOI_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOIEN))
#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_GPIOJ_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOJEN))
#define __HAL_RCC_GPIOK_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOKEN))
#define __HAL_RCC_DMA2D_CLK_DISABLE()           (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2DEN))
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)

#define __HAL_RCC_ETHMAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_ETHMACTX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACTXEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACTXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_ETHMACRX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACRXEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACRXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_ETHMACPTP_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACPTPEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETHMACPTPEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_ETH_CLK_ENABLE()       do {                            \
                                     __HAL_RCC_ETHMAC_CLK_ENABLE();      \
                                     __HAL_RCC_ETHMACTX_CLK_ENABLE();    \
                                     __HAL_RCC_ETHMACRX_CLK_ENABLE();    \
                                    } while(0)

#define __HAL_RCC_ETHMAC_CLK_DISABLE()    (RCC->AHB1ENR &= ~(RCC_AHB1ENR_ETHMACEN))
#define __HAL_RCC_ETHMACTX_CLK_DISABLE()  (RCC->AHB1ENR &= ~(RCC_AHB1ENR_ETHMACTXEN))
#define __HAL_RCC_ETHMACRX_CLK_DISABLE()  (RCC->AHB1ENR &= ~(RCC_AHB1ENR_ETHMACRXEN))
#define __HAL_RCC_ETHMACPTP_CLK_DISABLE() (RCC->AHB1ENR &= ~(RCC_AHB1ENR_ETHMACPTPEN))
#define __HAL_RCC_ETH_CLK_DISABLE()       do {                             \
                                      __HAL_RCC_ETHMACTX_CLK_DISABLE();    \
                                      __HAL_RCC_ETHMACRX_CLK_DISABLE();    \
                                      __HAL_RCC_ETHMAC_CLK_DISABLE();      \
                                     } while(0)
#endif 


#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DCMI_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#define __HAL_RCC_DCMI_CLK_DISABLE()  (RCC->AHB2ENR &= ~(RCC_AHB2ENR_DCMIEN))
#endif 

#if defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_JPEG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_JPEGEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_JPEGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#define __HAL_RCC_JPEG_CLK_DISABLE()  (RCC->AHB2ENR &= ~(RCC_AHB2ENR_JPEGEN))
#endif 

#define __HAL_RCC_RNG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN);\
                                        UNUSED(tmpreg); \
                                        __HAL_RCC_SYSCFG_CLK_ENABLE();\
                                      } while(0)

#define __HAL_RCC_RNG_CLK_DISABLE()   (RCC->AHB2ENR &= ~(RCC_AHB2ENR_RNGEN))

#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE() (RCC->AHB2ENR &= ~(RCC_AHB2ENR_OTGFSEN))
#if defined(STM32F756xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_CRYP_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_CRYPEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_CRYPEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_HASH_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_CRYP_CLK_DISABLE()  (RCC->AHB2ENR &= ~(RCC_AHB2ENR_CRYPEN))
#define __HAL_RCC_HASH_CLK_DISABLE()  (RCC->AHB2ENR &= ~(RCC_AHB2ENR_HASHEN))
#endif 

#if defined(STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_AES_CLK_ENABLE()    do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_AES_CLK_DISABLE()  (RCC->AHB2ENR &= ~(RCC_AHB2ENR_AESEN))
#endif 


#define __HAL_RCC_FMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_QSPI_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_FMC_CLK_DISABLE()   (RCC->AHB3ENR &= ~(RCC_AHB3ENR_FMCEN))
#define __HAL_RCC_QSPI_CLK_DISABLE()  (RCC->AHB3ENR &= ~(RCC_AHB3ENR_QSPIEN))


#define __HAL_RCC_TIM2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_LPTIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_LPTIM1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_LPTIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_RTC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_RTCEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_RTCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN3EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USART2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_I2C1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_I2C3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_UART7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART7EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_UART8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART8EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPDIFRX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPDIFRXEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPDIFRXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_I2C4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C4EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_CAN2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_CEC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#define __HAL_RCC_TIM2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2EN))
#define __HAL_RCC_TIM3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN))
#define __HAL_RCC_TIM4_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
#define __HAL_RCC_TIM5_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_TIM6_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
#define __HAL_RCC_TIM7_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
#define __HAL_RCC_TIM12_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#define __HAL_RCC_LPTIM1_CLK_DISABLE() (RCC->APB1ENR &= ~(RCC_APB1ENR_LPTIM1EN))
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_RTC_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_RTCEN))
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN3EN))
#endif 
#define __HAL_RCC_SPI2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_USART2_CLK_DISABLE() (RCC->APB1ENR &= ~(RCC_APB1ENR_USART2EN))
#define __HAL_RCC_USART3_CLK_DISABLE() (RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN))
#define __HAL_RCC_UART4_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
#define __HAL_RCC_UART5_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#define __HAL_RCC_I2C1_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C1EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#define __HAL_RCC_I2C3_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C3EN))
#define __HAL_RCC_CAN1_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN1EN))
#define __HAL_RCC_DAC_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#define __HAL_RCC_UART7_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_UART7EN))
#define __HAL_RCC_UART8_CLK_DISABLE()  (RCC->APB1ENR &= ~(RCC_APB1ENR_UART8EN))
#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPDIFRX_CLK_DISABLE()(RCC->APB1ENR &= ~(RCC_APB1ENR_SPDIFRXEN))
#define __HAL_RCC_I2C4_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C4EN))
#define __HAL_RCC_CAN2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN2EN))
#define __HAL_RCC_CEC_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_CECEN))
#endif 


#define __HAL_RCC_TIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_USART6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_ADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_ADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SDMMC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SPI4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM9_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM10_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_TIM11_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SPI5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI5EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SPI6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI6EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SAI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_SAI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0)

#define __HAL_RCC_MDIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_MDIOEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_MDIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 
#if defined (STM32F723xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_OTGPHYC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_OTGPHYCEN);\
                                         \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_OTGPHYCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0)
#endif 

#define __HAL_RCC_TIM1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN))
#define __HAL_RCC_TIM8_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
#define __HAL_RCC_USART1_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN))
#define __HAL_RCC_USART6_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_USART6EN))
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_SDMMC2EN))
#endif 
#define __HAL_RCC_ADC1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN))
#define __HAL_RCC_ADC2_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC2EN))
#define __HAL_RCC_ADC3_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC3EN))
#define __HAL_RCC_SDMMC1_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_SDMMC1EN))
#define __HAL_RCC_SPI1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#define __HAL_RCC_SPI4_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI4EN))
#define __HAL_RCC_TIM9_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
#define __HAL_RCC_TIM10_CLK_DISABLE()  (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM10EN))
#define __HAL_RCC_TIM11_CLK_DISABLE()  (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
#define __HAL_RCC_SPI5_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI5EN))
#define __HAL_RCC_SPI6_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI6EN))
#define __HAL_RCC_SAI1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SAI1EN))
#define __HAL_RCC_SAI2_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SAI2EN))
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_LTDCEN))
#endif 
#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_DSIEN))
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_DFSDM1EN))
#define __HAL_RCC_MDIO_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_MDIOEN))
#endif 
#if defined (STM32F723xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_OTGPHYC_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_OTGPHYCEN))
#endif 






#define __HAL_RCC_BKPSRAM_IS_CLK_ENABLED()          ((RCC->AHB1ENR & (RCC_AHB1ENR_BKPSRAMEN)) != RESET)
#define __HAL_RCC_DTCMRAMEN_IS_CLK_ENABLED()        ((RCC->AHB1ENR & (RCC_AHB1ENR_DTCMRAMEN)) != RESET)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()             ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA2EN)) != RESET)
#define __HAL_RCC_USB_OTG_HS_IS_CLK_ENABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_OTGHSEN)) != RESET)
#define __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_ENABLED()  ((RCC->AHB1ENR & (RCC_AHB1ENR_OTGHSULPIEN)) != RESET)
#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOAEN)) != RESET)
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOBEN)) != RESET)
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOCEN)) != RESET)
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIODEN)) != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOEEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOFEN)) != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOGEN)) != RESET)
#define __HAL_RCC_GPIOH_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOHEN)) != RESET)
#define __HAL_RCC_GPIOI_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOIEN)) != RESET)
#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_GPIOJ_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOJEN)) != RESET)
#define __HAL_RCC_GPIOK_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOKEN)) != RESET)
#define __HAL_RCC_DMA2D_IS_CLK_ENABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA2DEN)) != RESET)
#endif 

#define __HAL_RCC_BKPSRAM_IS_CLK_DISABLED()         ((RCC->AHB1ENR & (RCC_AHB1ENR_BKPSRAMEN)) == RESET)
#define __HAL_RCC_DTCMRAMEN_IS_CLK_DISABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_DTCMRAMEN)) == RESET)
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()            ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA2EN)) == RESET)
#define __HAL_RCC_USB_OTG_HS_IS_CLK_DISABLED()      ((RCC->AHB1ENR & (RCC_AHB1ENR_OTGHSEN)) == RESET)
#define __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_DISABLED() ((RCC->AHB1ENR & (RCC_AHB1ENR_OTGHSULPIEN)) == RESET)
#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOAEN)) == RESET)
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOBEN)) == RESET)
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOCEN)) == RESET)
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIODEN)) == RESET)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOEEN)) == RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOFEN)) == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOGEN)) == RESET)
#define __HAL_RCC_GPIOH_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOHEN)) == RESET)
#define __HAL_RCC_GPIOI_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOIEN)) == RESET)
#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_GPIOJ_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOJEN)) == RESET)
#define __HAL_RCC_GPIOK_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_GPIOKEN)) == RESET)
#define __HAL_RCC_DMA2D_IS_CLK_DISABLED()           ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA2DEN)) == RESET)
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)

#define __HAL_RCC_ETHMAC_IS_CLK_ENABLED()     ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACEN)) != RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_ENABLED()   ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACTXEN)) != RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_ENABLED()   ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACRXEN)) != RESET)
#define __HAL_RCC_ETHMACPTP_IS_CLK_ENABLED()  ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACPTPEN)) != RESET)
#define __HAL_RCC_ETH_IS_CLK_ENABLED()        (__HAL_RCC_ETHMAC_IS_CLK_ENABLED()   && \
                                               __HAL_RCC_ETHMACTX_IS_CLK_ENABLED() && \
                                               __HAL_RCC_ETHMACRX_IS_CLK_ENABLED())


#define __HAL_RCC_ETHMAC_IS_CLK_DISABLED()    ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACEN)) == RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_DISABLED()  ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACTXEN)) == RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_DISABLED()  ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACRXEN)) == RESET)
#define __HAL_RCC_ETHMACPTP_IS_CLK_DISABLED() ((RCC->AHB1ENR & (RCC_AHB1ENR_ETHMACPTPEN)) == RESET)
#define __HAL_RCC_ETH_IS_CLK_DISABLED()        (__HAL_RCC_ETHMAC_IS_CLK_DISABLED()   && \
                                                __HAL_RCC_ETHMACTX_IS_CLK_DISABLED() && \
                                                __HAL_RCC_ETHMACRX_IS_CLK_DISABLED())
#endif 


#define __HAL_RCC_RNG_IS_CLK_ENABLED()         ((RCC->AHB2ENR & (RCC_AHB2ENR_RNGEN)) != RESET)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()  ((RCC->AHB2ENR & (RCC_AHB2ENR_OTGFSEN)) != RESET)

#define __HAL_RCC_RNG_IS_CLK_DISABLED()        ((RCC->AHB2ENR & (RCC_AHB2ENR_RNGEN)) == RESET)
#define __HAL_RCC_USB_IS_OTG_FS_CLK_DISABLED() ((RCC->AHB2ENR & (RCC_AHB2ENR_OTGFSEN)) == RESET)

#if defined(STM32F756xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_CRYP_IS_CLK_ENABLED()   ((RCC->AHB2ENR & (RCC_AHB2ENR_CRYPEN)) != RESET)
#define __HAL_RCC_HASH_IS_CLK_ENABLED()   ((RCC->AHB2ENR & (RCC_AHB2ENR_HASHEN)) != RESET)
#define __HAL_RCC_CRYP_IS_CLK_DISABLED()  ((RCC->AHB2ENR & (RCC_AHB2ENR_CRYPEN)) == RESET)
#define __HAL_RCC_HASH_IS_CLK_DISABLED()  ((RCC->AHB2ENR & (RCC_AHB2ENR_HASHEN)) == RESET)
#endif 

#if defined(STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_AES_IS_CLK_ENABLED()   ((RCC->AHB2ENR & (RCC_AHB2ENR_AESEN)) != RESET)
#define __HAL_RCC_AES_IS_CLK_DISABLED()  ((RCC->AHB2ENR & (RCC_AHB2ENR_AESEN)) == RESET)
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DCMI_IS_CLK_ENABLED()        ((RCC->AHB2ENR & (RCC_AHB2ENR_DCMIEN)) != RESET)
#define __HAL_RCC_DCMI_IS_CLK_DISABLED()       ((RCC->AHB2ENR & (RCC_AHB2ENR_DCMIEN)) == RESET)
#endif 

#if defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_JPEG_IS_CLK_ENABLED()        ((RCC->AHB2ENR & (RCC_AHB2ENR_JPEGEN)) != RESET)
#define __HAL_RCC_JPEG_IS_CLK_DISABLED()       ((RCC->AHB2ENR & (RCC_AHB2ENR_JPEGEN)) == RESET)
#endif 


#define __HAL_RCC_FMC_IS_CLK_ENABLED()   ((RCC->AHB3ENR & (RCC_AHB3ENR_FMCEN)) != RESET)
#define __HAL_RCC_QSPI_IS_CLK_ENABLED()  ((RCC->AHB3ENR & (RCC_AHB3ENR_QSPIEN)) != RESET)

#define __HAL_RCC_FMC_IS_CLK_DISABLED()   ((RCC->AHB3ENR & (RCC_AHB3ENR_FMCEN)) == RESET)
#define __HAL_RCC_QSPI_IS_CLK_DISABLED()  ((RCC->AHB3ENR & (RCC_AHB3ENR_QSPIEN)) == RESET)


#define __HAL_RCC_TIM2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) != RESET)
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) != RESET)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
#define __HAL_RCC_LPTIM1_IS_CLK_ENABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_LPTIM1EN)) != RESET)
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_CAN3EN)) != RESET)
#endif 
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
#define __HAL_RCC_USART2_IS_CLK_ENABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) != RESET)
#define __HAL_RCC_USART3_IS_CLK_ENABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) != RESET)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
#define __HAL_RCC_I2C3_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C3EN)) != RESET)
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
#define __HAL_RCC_UART7_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_UART7EN)) != RESET)
#define __HAL_RCC_UART8_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_UART8EN)) != RESET)

#define __HAL_RCC_TIM2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) == RESET)
#define __HAL_RCC_TIM3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) == RESET)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) == RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#define __HAL_RCC_LPTIM1_IS_CLK_DISABLED() ((RCC->APB1ENR & (RCC_APB1ENR_LPTIM1EN)) == RESET)
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_CAN3EN)) == RESET)
#endif 
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
#define __HAL_RCC_USART2_IS_CLK_DISABLED() ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) == RESET)
#define __HAL_RCC_USART3_IS_CLK_DISABLED() ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) == RESET)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#define __HAL_RCC_I2C3_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C3EN)) == RESET)
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#define __HAL_RCC_UART7_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_UART7EN)) == RESET)
#define __HAL_RCC_UART8_IS_CLK_DISABLED()  ((RCC->APB1ENR & (RCC_APB1ENR_UART8EN)) == RESET)
#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPDIFRX_IS_CLK_ENABLED() ((RCC->APB1ENR & (RCC_APB1ENR_SPDIFRXEN)) != RESET)
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) != RESET)
#define __HAL_RCC_CEC_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) != RESET)
#define __HAL_RCC_I2C4_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_I2C4EN)) != RESET)

#define __HAL_RCC_SPDIFRX_IS_CLK_DISABLED()((RCC->APB1ENR & (RCC_APB1ENR_SPDIFRXEN)) == RESET)
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) == RESET)
#define __HAL_RCC_CEC_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) == RESET)
#define __HAL_RCC_I2C4_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C4EN)) == RESET)
#endif 

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_RTC_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_RTCEN)) != RESET)
#define __HAL_RCC_RTC_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_RTCEN)) == RESET)
#endif 


#define __HAL_RCC_TIM1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET)
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)
#define __HAL_RCC_USART1_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) != RESET)
#define __HAL_RCC_USART6_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_USART6EN)) != RESET)
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) != RESET)
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
#define __HAL_RCC_ADC3_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) != RESET)
#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_SDMMC1EN)) != RESET)
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)
#define __HAL_RCC_SPI4_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SPI4EN)) != RESET)
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
#define __HAL_RCC_TIM10_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) != RESET)
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)
#define __HAL_RCC_SPI5_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SPI5EN)) != RESET)
#define __HAL_RCC_SPI6_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SPI6EN)) != RESET)
#define __HAL_RCC_SAI1_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SAI1EN)) != RESET)
#define __HAL_RCC_SAI2_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SAI2EN)) != RESET)
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_LTDCEN)) != RESET)
#endif 
#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_DSIEN)) != RESET)
#endif 
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_SDMMC2EN)) != RESET)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_DFSDM1EN)) != RESET)
#define __HAL_RCC_MDIO_IS_CLK_ENABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_MDIOEN)) != RESET)
#endif 
#if defined (STM32F723xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_OTGPHYC_IS_CLK_ENABLED() ((RCC->APB2ENR & (RCC_APB2ENR_OTGPHYCEN)) != RESET)
#endif 

#define __HAL_RCC_TIM1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET)
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
#define __HAL_RCC_USART1_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) == RESET)
#define __HAL_RCC_USART6_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART6EN)) == RESET)
#define __HAL_RCC_ADC1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) == RESET)
#define __HAL_RCC_ADC2_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) == RESET)
#define __HAL_RCC_ADC3_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) == RESET)
#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_SDMMC1EN)) == RESET)
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
#define __HAL_RCC_SPI4_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI4EN)) == RESET)
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
#define __HAL_RCC_TIM10_IS_CLK_DISABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) == RESET)
#define __HAL_RCC_TIM11_IS_CLK_DISABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) == RESET)
#define __HAL_RCC_SPI5_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI5EN)) == RESET)
#define __HAL_RCC_SPI6_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI6EN)) == RESET)
#define __HAL_RCC_SAI1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SAI1EN)) == RESET)
#define __HAL_RCC_SAI2_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SAI2EN)) == RESET)
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_LTDCEN)) == RESET)
#endif 
#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_DSIEN)) == RESET)
#endif 
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_SDMMC2EN)) == RESET)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_DFSDM1EN)) == RESET)
#define __HAL_RCC_MDIO_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_MDIOEN)) == RESET)
#endif 
#if defined (STM32F723xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_OTGPHYC_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_OTGPHYCEN)) == RESET)
#endif 






#define __HAL_RCC_DMA2_FORCE_RESET()    (RCC->AHB1RSTR |= (RCC_AHB1RSTR_DMA2RST))
#define __HAL_RCC_USB_OTG_HS_FORCE_RESET()    (RCC->AHB1RSTR |= (RCC_AHB1RSTR_OTGHRST))
#define __HAL_RCC_GPIOA_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOARST))
#define __HAL_RCC_GPIOB_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOBRST))
#define __HAL_RCC_GPIOC_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOCRST))
#define __HAL_RCC_GPIOD_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIODRST))
#define __HAL_RCC_GPIOE_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOERST))
#define __HAL_RCC_GPIOF_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOFRST))
#define __HAL_RCC_GPIOG_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOGRST))
#define __HAL_RCC_GPIOH_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOHRST))
#define __HAL_RCC_GPIOI_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOIRST))

#define __HAL_RCC_DMA2_RELEASE_RESET()  (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_DMA2RST))
#define __HAL_RCC_USB_OTG_HS_RELEASE_RESET()  (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_OTGHRST))
#define __HAL_RCC_GPIOA_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOARST))
#define __HAL_RCC_GPIOB_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOBRST))
#define __HAL_RCC_GPIOC_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOCRST))
#define __HAL_RCC_GPIOD_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIODRST))
#define __HAL_RCC_GPIOE_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOERST))
#define __HAL_RCC_GPIOF_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOFRST))
#define __HAL_RCC_GPIOG_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOGRST))
#define __HAL_RCC_GPIOH_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOHRST))
#define __HAL_RCC_GPIOI_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOIRST))

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DMA2D_FORCE_RESET()    (RCC->AHB1RSTR |= (RCC_AHB1RSTR_DMA2DRST))
#define __HAL_RCC_ETHMAC_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_ETHMACRST))
#define __HAL_RCC_GPIOJ_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOJRST))
#define __HAL_RCC_GPIOK_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOKRST))

#define __HAL_RCC_DMA2D_RELEASE_RESET()  (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_DMA2DRST))
#define __HAL_RCC_ETHMAC_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_ETHMACRST))
#define __HAL_RCC_GPIOJ_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOJRST))
#define __HAL_RCC_GPIOK_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOKRST))
#endif 


#define __HAL_RCC_AHB2_FORCE_RESET()    (RCC->AHB2RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_RNG_FORCE_RESET()    (RCC->AHB2RSTR |= (RCC_AHB2RSTR_RNGRST))
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()   (RCC->AHB2RSTR |= (RCC_AHB2RSTR_OTGFSRST))

#define __HAL_RCC_AHB2_RELEASE_RESET()  (RCC->AHB2RSTR = 0x00U)
#define __HAL_RCC_RNG_RELEASE_RESET()  (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_RNGRST))
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET() (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_OTGFSRST))

#if defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_JPEG_FORCE_RESET()   (RCC->AHB2RSTR |= (RCC_AHB2RSTR_JPEGRST))
#define __HAL_RCC_JPEG_RELEASE_RESET() (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_JPEGRST))
#endif 

#if defined(STM32F756xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_CRYP_FORCE_RESET()   (RCC->AHB2RSTR |= (RCC_AHB2RSTR_CRYPRST))
#define __HAL_RCC_HASH_FORCE_RESET()   (RCC->AHB2RSTR |= (RCC_AHB2RSTR_HASHRST))
#define __HAL_RCC_CRYP_RELEASE_RESET() (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_CRYPRST))
#define __HAL_RCC_HASH_RELEASE_RESET() (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_HASHRST))
#endif 

#if defined(STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_AES_FORCE_RESET()   (RCC->AHB2RSTR |= (RCC_AHB2RSTR_AESRST))
#define __HAL_RCC_AES_RELEASE_RESET() (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_AESRST))
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DCMI_FORCE_RESET()   (RCC->AHB2RSTR |= (RCC_AHB2RSTR_DCMIRST))
#define __HAL_RCC_DCMI_RELEASE_RESET() (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_DCMIRST))
#endif 


#define __HAL_RCC_AHB3_FORCE_RESET()   (RCC->AHB3RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_FMC_FORCE_RESET()    (RCC->AHB3RSTR |= (RCC_AHB3RSTR_FMCRST))
#define __HAL_RCC_QSPI_FORCE_RESET()   (RCC->AHB3RSTR |= (RCC_AHB3RSTR_QSPIRST))

#define __HAL_RCC_AHB3_RELEASE_RESET() (RCC->AHB3RSTR = 0x00U)
#define __HAL_RCC_FMC_RELEASE_RESET()  (RCC->AHB3RSTR &= ~(RCC_AHB3RSTR_FMCRST))
#define __HAL_RCC_QSPI_RELEASE_RESET() (RCC->AHB3RSTR &= ~(RCC_AHB3RSTR_QSPIRST))


#define __HAL_RCC_TIM2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM2RST))
#define __HAL_RCC_TIM3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_TIM4_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_TIM5_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM6_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_TIM12_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_LPTIM1_FORCE_RESET()   (RCC->APB1RSTR |= (RCC_APB1RSTR_LPTIM1RST))
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN3RST))
#endif 
#define __HAL_RCC_SPI2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_USART2_FORCE_RESET()   (RCC->APB1RSTR |= (RCC_APB1RSTR_USART2RST))
#define __HAL_RCC_USART3_FORCE_RESET()   (RCC->APB1RSTR |= (RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_UART4_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_I2C1_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C1RST))
#define __HAL_RCC_I2C2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_I2C3_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C3RST))
#define __HAL_RCC_CAN1_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN1RST))
#define __HAL_RCC_DAC_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))
#define __HAL_RCC_UART7_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_UART7RST))
#define __HAL_RCC_UART8_FORCE_RESET()    (RCC->APB1RSTR |= (RCC_APB1RSTR_UART8RST))

#define __HAL_RCC_TIM2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM2RST))
#define __HAL_RCC_TIM3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST))
#define __HAL_RCC_TIM4_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_TIM5_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM6_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_TIM12_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_LPTIM1_RELEASE_RESET() (RCC->APB1RSTR &= ~(RCC_APB1RSTR_LPTIM1RST))
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN3RST))
#endif 
#define __HAL_RCC_SPI2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_USART2_RELEASE_RESET() (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST))
#define __HAL_RCC_USART3_RELEASE_RESET() (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_UART4_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_I2C1_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C1RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_I2C3_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C3RST))
#define __HAL_RCC_CAN1_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN1RST))
#define __HAL_RCC_DAC_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#define __HAL_RCC_UART7_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART7RST))
#define __HAL_RCC_UART8_RELEASE_RESET()  (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART8RST))

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPDIFRX_FORCE_RESET()  (RCC->APB1RSTR |= (RCC_APB1RSTR_SPDIFRXRST))
#define __HAL_RCC_I2C4_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C4RST))
#define __HAL_RCC_CAN2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN2RST))
#define __HAL_RCC_CEC_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_CECRST))

#define __HAL_RCC_SPDIFRX_RELEASE_RESET()(RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPDIFRXRST))
#define __HAL_RCC_I2C4_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C4RST))
#define __HAL_RCC_CAN2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN2RST))
#define __HAL_RCC_CEC_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CECRST))
#endif 


#define __HAL_RCC_TIM1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST))
#define __HAL_RCC_TIM8_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_USART1_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST))
#define __HAL_RCC_USART6_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_USART6RST))
#define __HAL_RCC_ADC_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_ADCRST))
#define __HAL_RCC_SDMMC1_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SDMMC1RST))
#define __HAL_RCC_SPI1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_SPI4_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI4RST))
#define __HAL_RCC_TIM9_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))
#define __HAL_RCC_SPI5_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI5RST))
#define __HAL_RCC_SPI6_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI6RST))
#define __HAL_RCC_SAI1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SAI1RST))
#define __HAL_RCC_SAI2_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SAI2RST))
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_LTDCRST))
#endif 
#if defined (STM32F723xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_OTGPHYC_FORCE_RESET()  (RCC->APB2RSTR |= (RCC_APB2RSTR_OTGPHYCRST))
#endif 

#define __HAL_RCC_TIM1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST))
#define __HAL_RCC_TIM8_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_USART1_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST))
#define __HAL_RCC_USART6_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART6RST))
#define __HAL_RCC_ADC_RELEASE_RESET()    (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADCRST))
#define __HAL_RCC_SDMMC1_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SDMMC1RST))
#define __HAL_RCC_SPI1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_SPI4_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI4RST))
#define __HAL_RCC_TIM9_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM11RST))
#define __HAL_RCC_SPI5_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI5RST))
#define __HAL_RCC_SPI6_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI6RST))
#define __HAL_RCC_SAI1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SAI1RST))
#define __HAL_RCC_SAI2_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SAI2RST))
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_LTDCRST))
#endif 
#if defined (STM32F723xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_OTGPHYC_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_OTGPHYCRST))
#endif 

#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_DSIRST))
#define __HAL_RCC_DSI_RELEASE_RESET()    (RCC->APB2RSTR &= ~(RCC_APB2RSTR_DSIRST))
#endif 

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SDMMC2RST))
#define __HAL_RCC_SDMMC2_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SDMMC2RST))
#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_DFSDM1RST))
#define __HAL_RCC_MDIO_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_MDIORST))
#define __HAL_RCC_DFSDM1_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_DFSDM1RST))
#define __HAL_RCC_MDIO_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_MDIORST))
#endif 





#define __HAL_RCC_FLITF_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_FLITFLPEN))
#define __HAL_RCC_AXI_CLK_SLEEP_ENABLE()        (RCC->AHB1LPENR |= (RCC_AHB1LPENR_AXILPEN))
#define __HAL_RCC_SRAM1_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_SRAM1LPEN))
#define __HAL_RCC_SRAM2_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_SRAM2LPEN))
#define __HAL_RCC_BKPSRAM_CLK_SLEEP_ENABLE()    (RCC->AHB1LPENR |= (RCC_AHB1LPENR_BKPSRAMLPEN))
#define __HAL_RCC_DTCM_CLK_SLEEP_ENABLE()       (RCC->AHB1LPENR |= (RCC_AHB1LPENR_DTCMLPEN))
#define __HAL_RCC_DMA2_CLK_SLEEP_ENABLE()       (RCC->AHB1LPENR |= (RCC_AHB1LPENR_DMA2LPEN))
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_OTGHSLPEN))
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE() (RCC->AHB1LPENR |= (RCC_AHB1LPENR_OTGHSULPILPEN))
#define __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOALPEN))
#define __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOBLPEN))
#define __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOCLPEN))
#define __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIODLPEN))
#define __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOELPEN))
#define __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOFLPEN))
#define __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOGLPEN))
#define __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOHLPEN))
#define __HAL_RCC_GPIOI_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOILPEN))

#define __HAL_RCC_FLITF_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_FLITFLPEN))
#define __HAL_RCC_AXI_CLK_SLEEP_DISABLE()       (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_AXILPEN))
#define __HAL_RCC_SRAM1_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_SRAM1LPEN))
#define __HAL_RCC_SRAM2_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_SRAM2LPEN))
#define __HAL_RCC_BKPSRAM_CLK_SLEEP_DISABLE()   (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_BKPSRAMLPEN))
#define __HAL_RCC_DTCM_CLK_SLEEP_DISABLE()      (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_DTCMLPEN))
#define __HAL_RCC_DMA2_CLK_SLEEP_DISABLE()      (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_DMA2LPEN))
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE()      (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_OTGHSLPEN))
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE() (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_OTGHSULPILPEN))
#define __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOALPEN))
#define __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOBLPEN))
#define __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOCLPEN))
#define __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIODLPEN))
#define __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOELPEN))
#define __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOFLPEN))
#define __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOGLPEN))
#define __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOHLPEN))
#define __HAL_RCC_GPIOI_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOILPEN))

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DMA2D_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_DMA2DLPEN))
#define __HAL_RCC_ETHMAC_CLK_SLEEP_ENABLE()     (RCC->AHB1LPENR |= (RCC_AHB1LPENR_ETHMACLPEN))
#define __HAL_RCC_ETHMACTX_CLK_SLEEP_ENABLE()   (RCC->AHB1LPENR |= (RCC_AHB1LPENR_ETHMACTXLPEN))
#define __HAL_RCC_ETHMACRX_CLK_SLEEP_ENABLE()   (RCC->AHB1LPENR |= (RCC_AHB1LPENR_ETHMACRXLPEN))
#define __HAL_RCC_ETHMACPTP_CLK_SLEEP_ENABLE()  (RCC->AHB1LPENR |= (RCC_AHB1LPENR_ETHMACPTPLPEN))
#define __HAL_RCC_GPIOJ_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOJLPEN))
#define __HAL_RCC_GPIOK_CLK_SLEEP_ENABLE()      (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOKLPEN))

#define __HAL_RCC_DMA2D_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_DMA2DLPEN))
#define __HAL_RCC_ETHMAC_CLK_SLEEP_DISABLE()    (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_ETHMACLPEN))
#define __HAL_RCC_ETHMACTX_CLK_SLEEP_DISABLE()  (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_ETHMACTXLPEN))
#define __HAL_RCC_ETHMACRX_CLK_SLEEP_DISABLE()  (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_ETHMACRXLPEN))
#define __HAL_RCC_ETHMACPTP_CLK_SLEEP_DISABLE() (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_ETHMACPTPLPEN))
#define __HAL_RCC_GPIOJ_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOJLPEN))
#define __HAL_RCC_GPIOK_CLK_SLEEP_DISABLE()     (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOKLPEN))
#endif 


#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DCMI_CLK_SLEEP_ENABLE()        (RCC->AHB2LPENR |= (RCC_AHB2LPENR_DCMILPEN))
#define __HAL_RCC_DCMI_CLK_SLEEP_DISABLE()       (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_DCMILPEN))
#endif 

#if defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_JPEG_CLK_SLEEP_ENABLE()        (RCC->AHB2LPENR |= (RCC_AHB2LPENR_JPEGLPEN))
#define __HAL_RCC_JPEG_CLK_SLEEP_DISABLE()       (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_JPEGLPEN))
#endif 

#define __HAL_RCC_RNG_CLK_SLEEP_ENABLE()         (RCC->AHB2LPENR |= (RCC_AHB2LPENR_RNGLPEN))
#define __HAL_RCC_RNG_CLK_SLEEP_DISABLE()        (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_RNGLPEN))

#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()  (RCC->AHB2LPENR |= (RCC_AHB2LPENR_OTGFSLPEN))
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE() (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_OTGFSLPEN))

#if defined(STM32F756xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_CRYP_CLK_SLEEP_ENABLE()        (RCC->AHB2LPENR |= (RCC_AHB2LPENR_CRYPLPEN))
#define __HAL_RCC_HASH_CLK_SLEEP_ENABLE()        (RCC->AHB2LPENR |= (RCC_AHB2LPENR_HASHLPEN))

#define __HAL_RCC_CRYP_CLK_SLEEP_DISABLE()       (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_CRYPLPEN))
#define __HAL_RCC_HASH_CLK_SLEEP_DISABLE()       (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_HASHLPEN))
#endif 

#if defined(STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_AES_CLK_SLEEP_ENABLE()        (RCC->AHB2LPENR |= (RCC_AHB2LPENR_AESLPEN))
#define __HAL_RCC_AES_CLK_SLEEP_DISABLE()       (RCC->AHB2LPENR &= ~(RCC_AHB2LPENR_AESLPEN))
#endif 


#define __HAL_RCC_FMC_CLK_SLEEP_ENABLE()  (RCC->AHB3LPENR |= (RCC_AHB3LPENR_FMCLPEN))
#define __HAL_RCC_FMC_CLK_SLEEP_DISABLE() (RCC->AHB3LPENR &= ~(RCC_AHB3LPENR_FMCLPEN))

#define __HAL_RCC_QSPI_CLK_SLEEP_ENABLE()  (RCC->AHB3LPENR |= (RCC_AHB3LPENR_QSPILPEN))
#define __HAL_RCC_QSPI_CLK_SLEEP_DISABLE() (RCC->AHB3LPENR &= ~(RCC_AHB3LPENR_QSPILPEN))


#define __HAL_RCC_TIM2_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM2LPEN))
#define __HAL_RCC_TIM3_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM3LPEN))
#define __HAL_RCC_TIM4_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM4LPEN))
#define __HAL_RCC_TIM5_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM5LPEN))
#define __HAL_RCC_TIM6_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM6LPEN))
#define __HAL_RCC_TIM7_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM7LPEN))
#define __HAL_RCC_TIM12_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM12LPEN))
#define __HAL_RCC_TIM13_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM13LPEN))
#define __HAL_RCC_TIM14_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM14LPEN))
#define __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE()  (RCC->APB1LPENR |= (RCC_APB1LPENR_LPTIM1LPEN))
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_CAN3LPEN))
#endif 
#define __HAL_RCC_SPI2_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_SPI2LPEN))
#define __HAL_RCC_SPI3_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_SPI3LPEN))
#define __HAL_RCC_USART2_CLK_SLEEP_ENABLE()  (RCC->APB1LPENR |= (RCC_APB1LPENR_USART2LPEN))
#define __HAL_RCC_USART3_CLK_SLEEP_ENABLE()  (RCC->APB1LPENR |= (RCC_APB1LPENR_USART3LPEN))
#define __HAL_RCC_UART4_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_UART4LPEN))
#define __HAL_RCC_UART5_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_UART5LPEN))
#define __HAL_RCC_I2C1_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_I2C1LPEN))
#define __HAL_RCC_I2C2_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_I2C2LPEN))
#define __HAL_RCC_I2C3_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_I2C3LPEN))
#define __HAL_RCC_CAN1_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_CAN1LPEN))
#define __HAL_RCC_DAC_CLK_SLEEP_ENABLE()     (RCC->APB1LPENR |= (RCC_APB1LPENR_DACLPEN))
#define __HAL_RCC_UART7_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_UART7LPEN))
#define __HAL_RCC_UART8_CLK_SLEEP_ENABLE()   (RCC->APB1LPENR |= (RCC_APB1LPENR_UART8LPEN))

#define __HAL_RCC_TIM2_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM2LPEN))
#define __HAL_RCC_TIM3_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM3LPEN))
#define __HAL_RCC_TIM4_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM4LPEN))
#define __HAL_RCC_TIM5_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM5LPEN))
#define __HAL_RCC_TIM6_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM6LPEN))
#define __HAL_RCC_TIM7_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM7LPEN))
#define __HAL_RCC_TIM12_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM12LPEN))
#define __HAL_RCC_TIM13_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM13LPEN))
#define __HAL_RCC_TIM14_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM14LPEN))
#define __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE() (RCC->APB1LPENR &= ~(RCC_APB1LPENR_LPTIM1LPEN))
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_CAN3LPEN))
#endif 
#define __HAL_RCC_SPI2_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_SPI2LPEN))
#define __HAL_RCC_SPI3_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_SPI3LPEN))
#define __HAL_RCC_USART2_CLK_SLEEP_DISABLE() (RCC->APB1LPENR &= ~(RCC_APB1LPENR_USART2LPEN))
#define __HAL_RCC_USART3_CLK_SLEEP_DISABLE() (RCC->APB1LPENR &= ~(RCC_APB1LPENR_USART3LPEN))
#define __HAL_RCC_UART4_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_UART4LPEN))
#define __HAL_RCC_UART5_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_UART5LPEN))
#define __HAL_RCC_I2C1_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_I2C1LPEN))
#define __HAL_RCC_I2C2_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_I2C2LPEN))
#define __HAL_RCC_I2C3_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_I2C3LPEN))
#define __HAL_RCC_CAN1_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_CAN1LPEN))
#define __HAL_RCC_DAC_CLK_SLEEP_DISABLE()    (RCC->APB1LPENR &= ~(RCC_APB1LPENR_DACLPEN))
#define __HAL_RCC_UART7_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_UART7LPEN))
#define __HAL_RCC_UART8_CLK_SLEEP_DISABLE()  (RCC->APB1LPENR &= ~(RCC_APB1LPENR_UART8LPEN))

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_RTC_CLK_SLEEP_ENABLE()     (RCC->APB1LPENR |= (RCC_APB1LPENR_RTCLPEN))
#define __HAL_RCC_RTC_CLK_SLEEP_DISABLE()    (RCC->APB1LPENR &= ~(RCC_APB1LPENR_RTCLPEN))
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPDIFRX_CLK_SLEEP_ENABLE() (RCC->APB1LPENR |= (RCC_APB1LPENR_SPDIFRXLPEN))
#define __HAL_RCC_I2C4_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_I2C4LPEN))
#define __HAL_RCC_CAN2_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_CAN2LPEN))
#define __HAL_RCC_CEC_CLK_SLEEP_ENABLE()     (RCC->APB1LPENR |= (RCC_APB1LPENR_CECLPEN))

#define __HAL_RCC_SPDIFRX_CLK_SLEEP_DISABLE()(RCC->APB1LPENR &= ~(RCC_APB1LPENR_SPDIFRXLPEN))
#define __HAL_RCC_I2C4_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_I2C4LPEN))
#define __HAL_RCC_CAN2_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_CAN2LPEN))
#define __HAL_RCC_CEC_CLK_SLEEP_DISABLE()    (RCC->APB1LPENR &= ~(RCC_APB1LPENR_CECLPEN))
#endif 


#define __HAL_RCC_TIM1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM1LPEN))
#define __HAL_RCC_TIM8_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM8LPEN))
#define __HAL_RCC_USART1_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_USART1LPEN))
#define __HAL_RCC_USART6_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_USART6LPEN))
#define __HAL_RCC_ADC1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_ADC1LPEN))
#define __HAL_RCC_ADC2_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_ADC2LPEN))
#define __HAL_RCC_ADC3_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_ADC3LPEN))
#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_SDMMC1LPEN))
#define __HAL_RCC_SPI1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SPI1LPEN))
#define __HAL_RCC_SPI4_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SPI4LPEN))
#define __HAL_RCC_TIM9_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM9LPEN))
#define __HAL_RCC_TIM10_CLK_SLEEP_ENABLE()   (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM10LPEN))
#define __HAL_RCC_TIM11_CLK_SLEEP_ENABLE()   (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM11LPEN))
#define __HAL_RCC_SPI5_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SPI5LPEN))
#define __HAL_RCC_SAI1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SAI1LPEN))
#define __HAL_RCC_SAI2_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SAI2LPEN))
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_LTDCLPEN))
#endif 

#define __HAL_RCC_TIM1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM1LPEN))
#define __HAL_RCC_TIM8_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM8LPEN))
#define __HAL_RCC_USART1_CLK_SLEEP_DISABLE() (RCC->APB2LPENR &= ~(RCC_APB2LPENR_USART1LPEN))
#define __HAL_RCC_USART6_CLK_SLEEP_DISABLE() (RCC->APB2LPENR &= ~(RCC_APB2LPENR_USART6LPEN))
#define __HAL_RCC_ADC1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_ADC1LPEN))
#define __HAL_RCC_ADC2_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_ADC2LPEN))
#define __HAL_RCC_ADC3_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_ADC3LPEN))
#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE()  (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SDMMC1LPEN))
#define __HAL_RCC_SPI1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SPI1LPEN))
#define __HAL_RCC_SPI4_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SPI4LPEN))
#define __HAL_RCC_TIM9_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM9LPEN))
#define __HAL_RCC_TIM10_CLK_SLEEP_DISABLE()  (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM10LPEN))
#define __HAL_RCC_TIM11_CLK_SLEEP_DISABLE()  (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM11LPEN))
#define __HAL_RCC_SPI5_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SPI5LPEN))
#define __HAL_RCC_SAI1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SAI1LPEN))
#define __HAL_RCC_SAI2_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SAI2LPEN))
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)|| defined (STM32F750xx)
#define __HAL_RCC_LTDC_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_LTDCLPEN))
#endif 
#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_CLK_SLEEP_ENABLE()     (RCC->APB2LPENR |= (RCC_APB2LPENR_DSILPEN))
#define __HAL_RCC_DSI_CLK_SLEEP_DISABLE()    (RCC->APB2LPENR &= ~(RCC_APB2LPENR_DSILPEN))
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_CLK_SLEEP_ENABLE()   (RCC->APB2LPENR |= (RCC_APB2LPENR_DFSDM1LPEN))
#define __HAL_RCC_MDIO_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_MDIOLPEN))
#define __HAL_RCC_DFSDM1_CLK_SLEEP_DISABLE()  (RCC->APB2LPENR &= ~(RCC_APB2LPENR_DFSDM1LPEN))
#define __HAL_RCC_MDIO_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_MDIOLPEN))
#endif 
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_SDMMC2LPEN))
#define __HAL_RCC_SDMMC2_CLK_SLEEP_DISABLE() (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SDMMC2LPEN))
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPI6_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SPI6LPEN))
#define __HAL_RCC_SPI6_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SPI6LPEN))
#endif 





#define __HAL_RCC_FLITF_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_FLITFLPEN)) != RESET)
#define __HAL_RCC_AXI_IS_CLK_SLEEP_ENABLED()        ((RCC->AHB1LPENR & (RCC_AHB1LPENR_AXILPEN)) != RESET)
#define __HAL_RCC_SRAM1_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_SRAM1LPEN)) != RESET)
#define __HAL_RCC_SRAM2_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_SRAM2LPEN)) != RESET)
#define __HAL_RCC_BKPSRAM_IS_CLK_SLEEP_ENABLED()    ((RCC->AHB1LPENR & (RCC_AHB1LPENR_BKPSRAMLPEN)) != RESET)
#define __HAL_RCC_DTCM_IS_CLK_SLEEP_ENABLED()       ((RCC->AHB1LPENR & (RCC_AHB1LPENR_DTCMLPEN)) != RESET)
#define __HAL_RCC_DMA2_IS_CLK_SLEEP_ENABLED()       ((RCC->AHB1LPENR & (RCC_AHB1LPENR_DMA2LPEN)) != RESET)
#define __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_ENABLED() ((RCC->AHB1LPENR & (RCC_AHB1LPENR_OTGHSLPEN)) != RESET)
#define __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_ENABLED() ((RCC->AHB1LPENR & (RCC_AHB1LPENR_OTGHSULPILPEN)) != RESET)
#define __HAL_RCC_GPIOA_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOALPEN)) != RESET)
#define __HAL_RCC_GPIOB_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOBLPEN)) != RESET)
#define __HAL_RCC_GPIOC_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOCLPEN)) != RESET)
#define __HAL_RCC_GPIOD_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIODLPEN)) != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOELPEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOFLPEN)) != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOGLPEN)) != RESET)
#define __HAL_RCC_GPIOH_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOHLPEN)) != RESET)
#define __HAL_RCC_GPIOI_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOILPEN)) != RESET)

#define __HAL_RCC_FLITF_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_FLITFLPEN)) == RESET)
#define __HAL_RCC_AXI_IS_CLK_SLEEP_DISABLED()       ((RCC->AHB1LPENR & (RCC_AHB1LPENR_AXILPEN)) == RESET)
#define __HAL_RCC_SRAM1_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_SRAM1LPEN)) == RESET)
#define __HAL_RCC_SRAM2_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_SRAM2LPEN)) == RESET)
#define __HAL_RCC_BKPSRAM_IS_CLK_SLEEP_DISABLED()   ((RCC->AHB1LPENR & (RCC_AHB1LPENR_BKPSRAMLPEN)) == RESET)
#define __HAL_RCC_DTCM_IS_CLK_SLEEP_DISABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_DTCMLPEN)) == RESET)
#define __HAL_RCC_DMA2_IS_CLK_SLEEP_DISABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_DMA2LPEN)) == RESET)
#define __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_DISABLED() ((RCC->AHB1LPENR & (RCC_AHB1LPENR_OTGHSLPEN)) == RESET)
#define __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_DISABLED() ((RCC->AHB1LPENR & (RCC_AHB1LPENR_OTGHSULPILPEN)) == RESET)
#define __HAL_RCC_GPIOA_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOALPEN)) == RESET)
#define __HAL_RCC_GPIOB_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOBLPEN)) == RESET)
#define __HAL_RCC_GPIOC_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOCLPEN)) == RESET)
#define __HAL_RCC_GPIOD_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIODLPEN)) == RESET)
#define __HAL_RCC_GPIOE_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOELPEN)) == RESET)
#define __HAL_RCC_GPIOF_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOFLPEN)) == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOGLPEN)) == RESET)
#define __HAL_RCC_GPIOH_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOHLPEN)) == RESET)
#define __HAL_RCC_GPIOI_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOILPEN)) == RESET)

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DMA2D_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_DMA2DLPEN)) != RESET)
#define __HAL_RCC_ETHMAC_IS_CLK_SLEEP_ENABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACLPEN)) != RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_SLEEP_ENABLED()   ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACTXLPEN)) != RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_SLEEP_ENABLED()   ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACRXLPEN)) != RESET)
#define __HAL_RCC_ETHMACPTP_IS_CLK_SLEEP_ENABLED()  ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACPTPLPEN)) != RESET)
#define __HAL_RCC_GPIOJ_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOJLPEN)) != RESET)
#define __HAL_RCC_GPIOK_IS_CLK_SLEEP_ENABLED()      ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOKLPEN)) != RESET)

#define __HAL_RCC_DMA2D_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_DMA2DLPEN)) == RESET)
#define __HAL_RCC_ETHMAC_IS_CLK_SLEEP_DISABLED()    ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACLPEN)) == RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_SLEEP_DISABLED()  ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACTXLPEN)) == RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_SLEEP_DISABLED()  ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACRXLPEN)) == RESET)
#define __HAL_RCC_ETHMACPTP_IS_CLK_SLEEP_DISABLED() ((RCC->AHB1LPENR & (RCC_AHB1LPENR_ETHMACPTPLPEN)) == RESET)
#define __HAL_RCC_GPIOJ_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOJLPEN)) == RESET)
#define __HAL_RCC_GPIOK_IS_CLK_SLEEP_DISABLED()     ((RCC->AHB1LPENR & (RCC_AHB1LPENR_GPIOKLPEN)) == RESET)
#endif 


#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_DCMI_IS_CLK_SLEEP_ENABLED()        ((RCC->AHB2LPENR & (RCC_AHB2LPENR_DCMILPEN)) != RESET)
#define __HAL_RCC_DCMI_IS_CLK_SLEEP_DISABLED()       ((RCC->AHB2LPENR & (RCC_AHB2LPENR_DCMILPEN)) == RESET)
#endif 

#if defined(STM32F767xx) || defined(STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_JPEG_IS_CLK_SLEEP_ENABLED()        ((RCC->AHB2LPENR & (RCC_AHB2LPENR_JPEGLPEN)) != RESET)
#define __HAL_RCC_JPEG_IS_CLK_SLEEP_DISABLED()       ((RCC->AHB2LPENR & (RCC_AHB2LPENR_JPEGLPEN)) == RESET)
#endif 

#define __HAL_RCC_RNG_IS_CLK_SLEEP_ENABLED()         ((RCC->AHB2LPENR & (RCC_AHB2LPENR_RNGLPEN)) != RESET)
#define __HAL_RCC_RNG_IS_CLK_SLEEP_DISABLED()        ((RCC->AHB2LPENR & (RCC_AHB2LPENR_RNGLPEN)) == RESET)

#define __HAL_RCC_USB_OTG_FS_IS_CLK_SLEEP_ENABLED()  ((RCC->AHB2LPENR & (RCC_AHB2LPENR_OTGFSLPEN)) != RESET)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_SLEEP_DISABLED() ((RCC->AHB2LPENR & (RCC_AHB2LPENR_OTGFSLPEN)) == RESET)

#if defined(STM32F756xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_CRYP_IS_CLK_SLEEP_ENABLED()        ((RCC->AHB2LPENR & (RCC_AHB2LPENR_CRYPLPEN)) != RESET)
#define __HAL_RCC_HASH_IS_CLK_SLEEP_ENABLED()        ((RCC->AHB2LPENR & (RCC_AHB2LPENR_HASHLPEN)) != RESET)

#define __HAL_RCC_CRYP_IS_CLK_SLEEP_DISABLED()       ((RCC->AHB2LPENR & (RCC_AHB2LPENR_CRYPLPEN)) == RESET)
#define __HAL_RCC_HASH_IS_CLK_SLEEP_DISABLED()       ((RCC->AHB2LPENR & (RCC_AHB2LPENR_HASHLPEN)) == RESET)
#endif 

#if defined(STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define __HAL_RCC_AES_IS_CLK_SLEEP_ENABLED()        ((RCC->AHB2LPENR & (RCC_AHB2LPENR_AESLPEN)) != RESET)
#define __HAL_RCC_AES_IS_CLK_SLEEP_DISABLED()       ((RCC->AHB2LPENR & (RCC_AHB2LPENR_AESLPEN)) == RESET)
#endif 


#define __HAL_RCC_FMC_IS_CLK_SLEEP_ENABLED()  ((RCC->AHB3LPENR & (RCC_AHB3LPENR_FMCLPEN)) != RESET)
#define __HAL_RCC_FMC_IS_CLK_SLEEP_DISABLED() ((RCC->AHB3LPENR & (RCC_AHB3LPENR_FMCLPEN)) == RESET)

#define __HAL_RCC_QSPI_IS_CLK_SLEEP_ENABLED()  ((RCC->AHB3LPENR & (RCC_AHB3LPENR_QSPILPEN)) != RESET)
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_DISABLED() ((RCC->AHB3LPENR & (RCC_AHB3LPENR_QSPILPEN)) == RESET)


#define __HAL_RCC_TIM2_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM2LPEN)) != RESET)
#define __HAL_RCC_TIM3_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM3LPEN)) != RESET)
#define __HAL_RCC_TIM4_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM4LPEN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM5LPEN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM6LPEN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM7LPEN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM12LPEN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM13LPEN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM14LPEN)) != RESET)
#define __HAL_RCC_LPTIM1_IS_CLK_SLEEP_ENABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_LPTIM1LPEN)) != RESET)
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_RTC_IS_CLK_SLEEP_ENABLED()     ((RCC->APB1LPENR & (RCC_APB1LPENR_RTCLPEN)) != RESET)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_CAN3LPEN)) != RESET)
#endif 
#define __HAL_RCC_SPI2_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_SPI2LPEN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_SPI3LPEN)) != RESET)
#define __HAL_RCC_USART2_IS_CLK_SLEEP_ENABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_USART2LPEN)) != RESET)
#define __HAL_RCC_USART3_IS_CLK_SLEEP_ENABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_USART3LPEN)) != RESET)
#define __HAL_RCC_UART4_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_UART4LPEN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_UART5LPEN)) != RESET)
#define __HAL_RCC_I2C1_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C1LPEN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C2LPEN)) != RESET)
#define __HAL_RCC_I2C3_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C3LPEN)) != RESET)
#define __HAL_RCC_CAN1_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_CAN1LPEN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_SLEEP_ENABLED()     ((RCC->APB1LPENR & (RCC_APB1LPENR_DACLPEN)) != RESET)
#define __HAL_RCC_UART7_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_UART7LPEN)) != RESET)
#define __HAL_RCC_UART8_IS_CLK_SLEEP_ENABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_UART8LPEN)) != RESET)

#define __HAL_RCC_TIM2_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM2LPEN)) == RESET)
#define __HAL_RCC_TIM3_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM3LPEN)) == RESET)
#define __HAL_RCC_TIM4_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM4LPEN)) == RESET)
#define __HAL_RCC_TIM5_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM5LPEN)) == RESET)
#define __HAL_RCC_TIM6_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM6LPEN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM7LPEN)) == RESET)
#define __HAL_RCC_TIM12_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM12LPEN)) == RESET)
#define __HAL_RCC_TIM13_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM13LPEN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_TIM14LPEN)) == RESET)
#define __HAL_RCC_LPTIM1_IS_CLK_SLEEP_DISABLED() ((RCC->APB1LPENR & (RCC_APB1LPENR_LPTIM1LPEN)) == RESET)
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_RTC_IS_CLK_SLEEP_DISABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_RTCLPEN)) == RESET)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_CAN3_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_CAN3LPEN)) == RESET)
#endif 
#define __HAL_RCC_SPI2_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_SPI2LPEN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_SPI3LPEN)) == RESET)
#define __HAL_RCC_USART2_IS_CLK_SLEEP_DISABLED() ((RCC->APB1LPENR & (RCC_APB1LPENR_USART2LPEN)) == RESET)
#define __HAL_RCC_USART3_IS_CLK_SLEEP_DISABLED() ((RCC->APB1LPENR & (RCC_APB1LPENR_USART3LPEN)) == RESET)
#define __HAL_RCC_UART4_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_UART4LPEN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_UART5LPEN)) == RESET)
#define __HAL_RCC_I2C1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C1LPEN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C2LPEN)) == RESET)
#define __HAL_RCC_I2C3_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C3LPEN)) == RESET)
#define __HAL_RCC_CAN1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_CAN1LPEN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_SLEEP_DISABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_DACLPEN)) == RESET)
#define __HAL_RCC_UART7_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_UART7LPEN)) == RESET)
#define __HAL_RCC_UART8_IS_CLK_SLEEP_DISABLED()  ((RCC->APB1LPENR & (RCC_APB1LPENR_UART8LPEN)) == RESET)

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPDIFRX_IS_CLK_SLEEP_ENABLED() ((RCC->APB1LPENR & (RCC_APB1LPENR_SPDIFRXLPEN)) != RESET)
#define __HAL_RCC_I2C4_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C4LPEN)) != RESET)
#define __HAL_RCC_CAN2_IS_CLK_SLEEP_ENABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_CAN2LPEN)) != RESET)
#define __HAL_RCC_CEC_IS_CLK_SLEEP_ENABLED()     ((RCC->APB1LPENR & (RCC_APB1LPENR_CECLPEN)) != RESET)

#define __HAL_RCC_SPDIFRX_IS_CLK_SLEEP_DISABLED()((RCC->APB1LPENR & (RCC_APB1LPENR_SPDIFRXLPEN)) == RESET)
#define __HAL_RCC_I2C4_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_I2C4LPEN)) == RESET)
#define __HAL_RCC_CAN2_IS_CLK_SLEEP_DISABLED()   ((RCC->APB1LPENR & (RCC_APB1LPENR_CAN2LPEN)) == RESET)
#define __HAL_RCC_CEC_IS_CLK_SLEEP_DISABLED()    ((RCC->APB1LPENR & (RCC_APB1LPENR_CECLPEN)) == RESET)
#endif 


#define __HAL_RCC_TIM1_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM1LPEN)) != RESET)
#define __HAL_RCC_TIM8_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM8LPEN)) != RESET)
#define __HAL_RCC_USART1_IS_CLK_SLEEP_ENABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_USART1LPEN)) != RESET)
#define __HAL_RCC_USART6_IS_CLK_SLEEP_ENABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_USART6LPEN)) != RESET)
#define __HAL_RCC_ADC1_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_ADC1LPEN)) != RESET)
#define __HAL_RCC_ADC2_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_ADC2LPEN)) != RESET)
#define __HAL_RCC_ADC3_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_ADC3LPEN)) != RESET)
#define __HAL_RCC_SDMMC1_IS_CLK_SLEEP_ENABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_SDMMC1LPEN)) != RESET)
#define __HAL_RCC_SPI1_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI1LPEN)) != RESET)
#define __HAL_RCC_SPI4_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI4LPEN)) != RESET)
#define __HAL_RCC_TIM9_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM9LPEN)) != RESET)
#define __HAL_RCC_TIM10_IS_CLK_SLEEP_ENABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM10LPEN)) != RESET)
#define __HAL_RCC_TIM11_IS_CLK_SLEEP_ENABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM11LPEN)) != RESET)
#define __HAL_RCC_SPI5_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI5LPEN)) != RESET)
#define __HAL_RCC_SAI1_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_SAI1LPEN)) != RESET)
#define __HAL_RCC_SAI2_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_SAI2LPEN)) != RESET)
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_LTDCLPEN)) != RESET)
#endif 
#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_IS_CLK_SLEEP_ENABLED()     ((RCC->APB2LPENR & (RCC_APB2LPENR_DSILPEN)) != RESET)
#endif 
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_IS_CLK_SLEEP_ENABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_SDMMC2LPEN)) != RESET)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_IS_CLK_SLEEP_ENABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_DFSDM1LPEN)) != RESET)
#define __HAL_RCC_MDIO_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_MDIOLPEN)) != RESET)
#endif 

#define __HAL_RCC_TIM1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM1LPEN)) == RESET)
#define __HAL_RCC_TIM8_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM8LPEN)) == RESET)
#define __HAL_RCC_USART1_IS_CLK_SLEEP_DISABLED() ((RCC->APB2LPENR & (RCC_APB2LPENR_USART1LPEN)) == RESET)
#define __HAL_RCC_USART6_IS_CLK_SLEEP_DISABLED() ((RCC->APB2LPENR & (RCC_APB2LPENR_USART6LPEN)) == RESET)
#define __HAL_RCC_ADC1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_ADC1LPEN)) == RESET)
#define __HAL_RCC_ADC2_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_ADC2LPEN)) == RESET)
#define __HAL_RCC_ADC3_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_ADC3LPEN)) == RESET)
#define __HAL_RCC_SDMMC1_IS_CLK_SLEEP_DISABLED() ((RCC->APB2LPENR & (RCC_APB2LPENR_SDMMC1LPEN)) == RESET)
#define __HAL_RCC_SPI1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI1LPEN)) == RESET)
#define __HAL_RCC_SPI4_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI4LPEN)) == RESET)
#define __HAL_RCC_TIM9_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM9LPEN)) == RESET)
#define __HAL_RCC_TIM10_IS_CLK_SLEEP_DISABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM10LPEN)) == RESET)
#define __HAL_RCC_TIM11_IS_CLK_SLEEP_DISABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_TIM11LPEN)) == RESET)
#define __HAL_RCC_SPI5_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI5LPEN)) == RESET)
#define __HAL_RCC_SAI1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_SAI1LPEN)) == RESET)
#define __HAL_RCC_SAI2_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_SAI2LPEN)) == RESET)
#if defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define __HAL_RCC_LTDC_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_LTDCLPEN)) == RESET)
#endif 
#if defined (STM32F769xx) || defined (STM32F779xx)
#define __HAL_RCC_DSI_IS_CLK_SLEEP_DISABLED()     ((RCC->APB2LPENR & (RCC_APB2LPENR_DSILPEN)) == RESET)
#endif 
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define __HAL_RCC_SDMMC2_IS_CLK_SLEEP_DISABLED()  ((RCC->APB2LPENR & (RCC_APB2LPENR_SDMMC2LPEN)) == RESET)
#endif 
#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define __HAL_RCC_DFSDM1_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_DFSDM1LPEN)) == RESET)
#define __HAL_RCC_MDIO_IS_CLK_SLEEP_DISABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_MDIOLPEN)) == RESET)
#endif 

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)
#define __HAL_RCC_SPI6_IS_CLK_SLEEP_ENABLED()    ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI6LPEN)) != RESET)
#define __HAL_RCC_SPI6_IS_CLK_SLEEP_DISABLED()   ((RCC->APB2LPENR & (RCC_APB2LPENR_SPI6LPEN)) == RESET)
#endif 



#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)

#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSource__, __PLLM__, __PLLN__, __PLLP__, __PLLQ__,__PLLR__)  \
                            (RCC->PLLCFGR = ((__RCC_PLLSource__) | (__PLLM__)                   | \
                            ((__PLLN__) << RCC_PLLCFGR_PLLN_Pos)                      | \
                            ((((__PLLP__) >> 1) -1) << RCC_PLLCFGR_PLLP_Pos)          | \
                            ((__PLLQ__) << RCC_PLLCFGR_PLLQ_Pos)                      | \
                            ((__PLLR__) << RCC_PLLCFGR_PLLR_Pos)))
#else

#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSource__, __PLLM__, __PLLN__, __PLLP__, __PLLQ__)     \
                            (RCC->PLLCFGR = (0x20000000 | (__RCC_PLLSource__) | (__PLLM__)| \
                            ((__PLLN__) << RCC_PLLCFGR_PLLN_Pos)                          | \
                            ((((__PLLP__) >> 1) -1) << RCC_PLLCFGR_PLLP_Pos)              | \
                            ((__PLLQ__) << RCC_PLLCFGR_PLLQ_Pos)))
#endif 



#define __HAL_RCC_TIMCLKPRESCALER(__PRESC__) do {RCC->DCKCFGR1 &= ~(RCC_DCKCFGR1_TIMPRE);\
                                                 RCC->DCKCFGR1 |= (__PRESC__);           \
                                                }while(0)


#define __HAL_RCC_PLLSAI_ENABLE() (RCC->CR |= (RCC_CR_PLLSAION))
#define __HAL_RCC_PLLSAI_DISABLE() (RCC->CR &= ~(RCC_CR_PLLSAION))

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)

#define __HAL_RCC_PLLSAI_CONFIG(__PLLSAIN__, __PLLSAIP__, __PLLSAIQ__)                        \
                               (RCC->PLLSAICFGR = ((__PLLSAIN__) << RCC_PLLSAICFGR_PLLSAIN_Pos) |\
                               ((__PLLSAIP__) << RCC_PLLSAICFGR_PLLSAIP_Pos)                    |\
                               ((__PLLSAIQ__) << RCC_PLLSAICFGR_PLLSAIQ_Pos))


#define __HAL_RCC_PLLI2S_CONFIG(__PLLI2SN__, __PLLI2SQ__, __PLLI2SR__)                        \
                               (RCC->PLLI2SCFGR = ((__PLLI2SN__) << RCC_PLLI2SCFGR_PLLI2SN_Pos) |\
                               ((__PLLI2SQ__) << RCC_PLLI2SCFGR_PLLI2SQ_Pos)                    |\
                               ((__PLLI2SR__) << RCC_PLLI2SCFGR_PLLI2SR_Pos))
#else

#define __HAL_RCC_PLLSAI_CONFIG(__PLLSAIN__, __PLLSAIP__, __PLLSAIQ__, __PLLSAIR__)              \
                               (RCC->PLLSAICFGR = ((__PLLSAIN__) << RCC_PLLSAICFGR_PLLSAIN_Pos) |\
                               ((__PLLSAIP__) << RCC_PLLSAICFGR_PLLSAIP_Pos)                    |\
                               ((__PLLSAIQ__) << RCC_PLLSAICFGR_PLLSAIQ_Pos)                    |\
                               ((__PLLSAIR__) << RCC_PLLSAICFGR_PLLSAIR_Pos))


#define __HAL_RCC_PLLI2S_CONFIG(__PLLI2SN__, __PLLI2SP__, __PLLI2SQ__, __PLLI2SR__)              \
                               (RCC->PLLI2SCFGR = ((__PLLI2SN__) << RCC_PLLI2SCFGR_PLLI2SN_Pos) |\
                               ((__PLLI2SP__) << RCC_PLLI2SCFGR_PLLI2SP_Pos)                    |\
                               ((__PLLI2SQ__) << RCC_PLLI2SCFGR_PLLI2SQ_Pos)                    |\
                               ((__PLLI2SR__) << RCC_PLLI2SCFGR_PLLI2SR_Pos))
#endif 


#define __HAL_RCC_PLLI2S_PLLSAICLKDIVQ_CONFIG(__PLLI2SDivQ__) (MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_PLLI2SDIVQ, (__PLLI2SDivQ__)-1))


#define __HAL_RCC_PLLSAI_PLLSAICLKDIVQ_CONFIG(__PLLSAIDivQ__) (MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_PLLSAIDIVQ, ((__PLLSAIDivQ__)-1)<<8))

#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) ||\
    defined (STM32F750xx)

#define __HAL_RCC_PLLSAI_PLLSAICLKDIVR_CONFIG(__PLLSAIDivR__)\
                            MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_PLLSAIDIVR, (uint32_t)(__PLLSAIDivR__))
#endif 


#define __HAL_RCC_SAI1_CONFIG(__SOURCE__)\
                             MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_SAI1SEL, (uint32_t)(__SOURCE__))


#define __HAL_RCC_GET_SAI1_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR1, RCC_DCKCFGR1_SAI1SEL)))


#define __HAL_RCC_SAI2_CONFIG(__SOURCE__)\
                            MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_SAI2SEL, (uint32_t)(__SOURCE__))



#define __HAL_RCC_GET_SAI2_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR1, RCC_DCKCFGR1_SAI2SEL)))



#define __HAL_RCC_PLLSAI_ENABLE_IT() (RCC->CIR |= (RCC_CIR_PLLSAIRDYIE))


#define __HAL_RCC_PLLSAI_DISABLE_IT() (RCC->CIR &= ~(RCC_CIR_PLLSAIRDYIE))


#define __HAL_RCC_PLLSAI_CLEAR_IT() (RCC->CIR |= (RCC_CIR_PLLSAIRDYF))


#define __HAL_RCC_PLLSAI_GET_IT() ((RCC->CIR & (RCC_CIR_PLLSAIRDYIE)) == (RCC_CIR_PLLSAIRDYIE))


#define __HAL_RCC_PLLSAI_GET_FLAG() ((RCC->CR & (RCC_CR_PLLSAIRDY)) == (RCC_CR_PLLSAIRDY))


#define __HAL_RCC_GET_I2SCLKSOURCE() (READ_BIT(RCC->CFGR, RCC_CFGR_I2SSRC))


#define __HAL_RCC_I2C1_CONFIG(__I2C1_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C1SEL, (uint32_t)(__I2C1_CLKSOURCE__))


#define __HAL_RCC_GET_I2C1_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C1SEL)))


#define __HAL_RCC_I2C2_CONFIG(__I2C2_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C2SEL, (uint32_t)(__I2C2_CLKSOURCE__))


#define __HAL_RCC_GET_I2C2_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C2SEL)))


#define __HAL_RCC_I2C3_CONFIG(__I2C3_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C3SEL, (uint32_t)(__I2C3_CLKSOURCE__))


#define __HAL_RCC_GET_I2C3_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C3SEL)))


#define __HAL_RCC_I2C4_CONFIG(__I2C4_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C4SEL, (uint32_t)(__I2C4_CLKSOURCE__))


#define __HAL_RCC_GET_I2C4_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C4SEL)))


#define __HAL_RCC_USART1_CONFIG(__USART1_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_USART1SEL, (uint32_t)(__USART1_CLKSOURCE__))


#define __HAL_RCC_GET_USART1_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_USART1SEL)))


#define __HAL_RCC_USART2_CONFIG(__USART2_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_USART2SEL, (uint32_t)(__USART2_CLKSOURCE__))


#define __HAL_RCC_GET_USART2_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_USART2SEL)))


#define __HAL_RCC_USART3_CONFIG(__USART3_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_USART3SEL, (uint32_t)(__USART3_CLKSOURCE__))


#define __HAL_RCC_GET_USART3_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_USART3SEL)))

 
#define __HAL_RCC_UART4_CONFIG(__UART4_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_UART4SEL, (uint32_t)(__UART4_CLKSOURCE__))


#define __HAL_RCC_GET_UART4_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_UART4SEL)))

 
#define __HAL_RCC_UART5_CONFIG(__UART5_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_UART5SEL, (uint32_t)(__UART5_CLKSOURCE__))


#define __HAL_RCC_GET_UART5_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_UART5SEL)))

 
#define __HAL_RCC_USART6_CONFIG(__USART6_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_USART6SEL, (uint32_t)(__USART6_CLKSOURCE__))


#define __HAL_RCC_GET_USART6_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_USART6SEL)))

 
#define __HAL_RCC_UART7_CONFIG(__UART7_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_UART7SEL, (uint32_t)(__UART7_CLKSOURCE__))


#define __HAL_RCC_GET_UART7_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_UART7SEL)))


#define __HAL_RCC_UART8_CONFIG(__UART8_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_UART8SEL, (uint32_t)(__UART8_CLKSOURCE__))


#define __HAL_RCC_GET_UART8_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_UART8SEL)))


#define __HAL_RCC_LPTIM1_CONFIG(__LPTIM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_LPTIM1SEL, (uint32_t)(__LPTIM1_CLKSOURCE__))


#define __HAL_RCC_GET_LPTIM1_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_LPTIM1SEL)))


#define __HAL_RCC_CEC_CONFIG(__CEC_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_CECSEL, (uint32_t)(__CEC_CLKSOURCE__))


#define __HAL_RCC_GET_CEC_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_CECSEL)))


#define __HAL_RCC_CLK48_CONFIG(__CLK48_SOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_CK48MSEL, (uint32_t)(__CLK48_SOURCE__))


#define __HAL_RCC_GET_CLK48_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_CK48MSEL)))


#define __HAL_RCC_SDMMC1_CONFIG(__SDMMC1_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_SDMMC1SEL, (uint32_t)(__SDMMC1_CLKSOURCE__))


#define __HAL_RCC_GET_SDMMC1_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_SDMMC1SEL)))

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)

#define __HAL_RCC_SDMMC2_CONFIG(__SDMMC2_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_SDMMC2SEL, (uint32_t)(__SDMMC2_CLKSOURCE__))


#define __HAL_RCC_GET_SDMMC2_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_SDMMC2SEL)))
#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)

#define __HAL_RCC_DFSDM1_CONFIG(__DFSDM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_DFSDM1SEL, (uint32_t)(__DFSDM1_CLKSOURCE__))


#define __HAL_RCC_GET_DFSDM1_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR1, RCC_DCKCFGR1_DFSDM1SEL)))


#define __HAL_RCC_DFSDM1AUDIO_CONFIG(__DFSDM1AUDIO_CLKSOURCE__) \
                  MODIFY_REG(RCC->DCKCFGR1, RCC_DCKCFGR1_ADFSDM1SEL, (uint32_t)(__DFSDM1AUDIO_CLKSOURCE__))


#define __HAL_RCC_GET_DFSDM1AUDIO_SOURCE() ((uint32_t)(READ_BIT(RCC->DCKCFGR1, RCC_DCKCFGR1_ADFSDM1SEL)))
#endif 

#if defined (STM32F769xx) || defined (STM32F779xx)

#define __HAL_RCC_DSI_CONFIG(__DSI_CLKSOURCE__) (MODIFY_REG(RCC->DCKCFGR2, RCC_DCKCFGR2_DSISEL, (uint32_t)(__DSI_CLKSOURCE__)))


#define __HAL_RCC_GET_DSI_SOURCE() (READ_BIT(RCC->DCKCFGR2, RCC_DCKCFGR2_DSISEL))
#endif 




HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);
HAL_StatusTypeDef HAL_RCCEx_EnablePLLSAI(RCC_PLLSAIInitTypeDef  *PLLSAIInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLSAI(void);




#if defined(STM32F756xx) || defined(STM32F746xx) || defined(STM32F750xx)
#define IS_RCC_PERIPHCLOCK(SELECTION)  \
               ((((SELECTION) & RCC_PERIPHCLK_I2S)         == RCC_PERIPHCLK_I2S)     || \
                (((SELECTION) & RCC_PERIPHCLK_LTDC)        == RCC_PERIPHCLK_LTDC)    || \
                (((SELECTION) & RCC_PERIPHCLK_TIM)         == RCC_PERIPHCLK_TIM)     || \
                (((SELECTION) & RCC_PERIPHCLK_USART1)      == RCC_PERIPHCLK_USART1)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART2)      == RCC_PERIPHCLK_USART2)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART3)      == RCC_PERIPHCLK_USART3)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART4)       == RCC_PERIPHCLK_UART4)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART5)       == RCC_PERIPHCLK_UART5)   || \
                (((SELECTION) & RCC_PERIPHCLK_USART6)      == RCC_PERIPHCLK_USART6)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART7)       == RCC_PERIPHCLK_UART7)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART8)       == RCC_PERIPHCLK_UART8)   || \
                (((SELECTION) & RCC_PERIPHCLK_I2C1)        == RCC_PERIPHCLK_I2C1)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C2)        == RCC_PERIPHCLK_I2C2)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C3)        == RCC_PERIPHCLK_I2C3)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C4)        == RCC_PERIPHCLK_I2C4)    || \
                (((SELECTION) & RCC_PERIPHCLK_LPTIM1)      == RCC_PERIPHCLK_LPTIM1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SAI1)        == RCC_PERIPHCLK_SAI1)    || \
                (((SELECTION) & RCC_PERIPHCLK_SAI2)        == RCC_PERIPHCLK_SAI2)    || \
                (((SELECTION) & RCC_PERIPHCLK_CLK48)       == RCC_PERIPHCLK_CLK48)   || \
                (((SELECTION) & RCC_PERIPHCLK_CEC)         == RCC_PERIPHCLK_CEC)     || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC1)      == RCC_PERIPHCLK_SDMMC1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SPDIFRX)     == RCC_PERIPHCLK_SPDIFRX) || \
                (((SELECTION) & RCC_PERIPHCLK_RTC)         == RCC_PERIPHCLK_RTC))
#elif defined(STM32F745xx)
#define IS_RCC_PERIPHCLOCK(SELECTION)  \
               ((((SELECTION) & RCC_PERIPHCLK_I2S)         == RCC_PERIPHCLK_I2S)     || \
                (((SELECTION) & RCC_PERIPHCLK_TIM)         == RCC_PERIPHCLK_TIM)     || \
                (((SELECTION) & RCC_PERIPHCLK_USART1)      == RCC_PERIPHCLK_USART1)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART2)      == RCC_PERIPHCLK_USART2)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART3)      == RCC_PERIPHCLK_USART3)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART4)       == RCC_PERIPHCLK_UART4)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART5)       == RCC_PERIPHCLK_UART5)   || \
                (((SELECTION) & RCC_PERIPHCLK_USART6)      == RCC_PERIPHCLK_USART6)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART7)       == RCC_PERIPHCLK_UART7)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART8)       == RCC_PERIPHCLK_UART8)   || \
                (((SELECTION) & RCC_PERIPHCLK_I2C1)        == RCC_PERIPHCLK_I2C1)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C2)        == RCC_PERIPHCLK_I2C2)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C3)        == RCC_PERIPHCLK_I2C3)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C4)        == RCC_PERIPHCLK_I2C4)    || \
                (((SELECTION) & RCC_PERIPHCLK_LPTIM1)      == RCC_PERIPHCLK_LPTIM1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SAI1)        == RCC_PERIPHCLK_SAI1)    || \
                (((SELECTION) & RCC_PERIPHCLK_SAI2)        == RCC_PERIPHCLK_SAI2)    || \
                (((SELECTION) & RCC_PERIPHCLK_CLK48)       == RCC_PERIPHCLK_CLK48)   || \
                (((SELECTION) & RCC_PERIPHCLK_CEC)         == RCC_PERIPHCLK_CEC)     || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC1)      == RCC_PERIPHCLK_SDMMC1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SPDIFRX)     == RCC_PERIPHCLK_SPDIFRX) || \
                (((SELECTION) & RCC_PERIPHCLK_RTC)         == RCC_PERIPHCLK_RTC))
#elif defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define IS_RCC_PERIPHCLOCK(SELECTION)  \
               ((((SELECTION) & RCC_PERIPHCLK_I2S)         == RCC_PERIPHCLK_I2S)     || \
                (((SELECTION) & RCC_PERIPHCLK_LTDC)        == RCC_PERIPHCLK_LTDC)    || \
                (((SELECTION) & RCC_PERIPHCLK_TIM)         == RCC_PERIPHCLK_TIM)     || \
                (((SELECTION) & RCC_PERIPHCLK_USART1)      == RCC_PERIPHCLK_USART1)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART2)      == RCC_PERIPHCLK_USART2)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART3)      == RCC_PERIPHCLK_USART3)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART4)       == RCC_PERIPHCLK_UART4)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART5)       == RCC_PERIPHCLK_UART5)   || \
                (((SELECTION) & RCC_PERIPHCLK_USART6)      == RCC_PERIPHCLK_USART6)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART7)       == RCC_PERIPHCLK_UART7)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART8)       == RCC_PERIPHCLK_UART8)   || \
                (((SELECTION) & RCC_PERIPHCLK_I2C1)        == RCC_PERIPHCLK_I2C1)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C2)        == RCC_PERIPHCLK_I2C2)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C3)        == RCC_PERIPHCLK_I2C3)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C4)        == RCC_PERIPHCLK_I2C4)    || \
                (((SELECTION) & RCC_PERIPHCLK_LPTIM1)      == RCC_PERIPHCLK_LPTIM1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SAI1)        == RCC_PERIPHCLK_SAI1)    || \
                (((SELECTION) & RCC_PERIPHCLK_SAI2)        == RCC_PERIPHCLK_SAI2)    || \
                (((SELECTION) & RCC_PERIPHCLK_CLK48)       == RCC_PERIPHCLK_CLK48)   || \
                (((SELECTION) & RCC_PERIPHCLK_CEC)         == RCC_PERIPHCLK_CEC)     || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC1)      == RCC_PERIPHCLK_SDMMC1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC2)      == RCC_PERIPHCLK_SDMMC2)  || \
                (((SELECTION) & RCC_PERIPHCLK_DFSDM1)       == RCC_PERIPHCLK_DFSDM1)   || \
                (((SELECTION) & RCC_PERIPHCLK_DFSDM1_AUDIO) == RCC_PERIPHCLK_DFSDM1_AUDIO) || \
                (((SELECTION) & RCC_PERIPHCLK_SPDIFRX)     == RCC_PERIPHCLK_SPDIFRX) || \
                (((SELECTION) & RCC_PERIPHCLK_RTC)         == RCC_PERIPHCLK_RTC))
#elif defined (STM32F765xx)
#define IS_RCC_PERIPHCLOCK(SELECTION)  \
               ((((SELECTION) & RCC_PERIPHCLK_I2S)         == RCC_PERIPHCLK_I2S)     || \
                (((SELECTION) & RCC_PERIPHCLK_TIM)         == RCC_PERIPHCLK_TIM)     || \
                (((SELECTION) & RCC_PERIPHCLK_USART1)      == RCC_PERIPHCLK_USART1)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART2)      == RCC_PERIPHCLK_USART2)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART3)      == RCC_PERIPHCLK_USART3)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART4)       == RCC_PERIPHCLK_UART4)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART5)       == RCC_PERIPHCLK_UART5)   || \
                (((SELECTION) & RCC_PERIPHCLK_USART6)      == RCC_PERIPHCLK_USART6)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART7)       == RCC_PERIPHCLK_UART7)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART8)       == RCC_PERIPHCLK_UART8)   || \
                (((SELECTION) & RCC_PERIPHCLK_I2C1)        == RCC_PERIPHCLK_I2C1)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C2)        == RCC_PERIPHCLK_I2C2)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C3)        == RCC_PERIPHCLK_I2C3)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C4)        == RCC_PERIPHCLK_I2C4)    || \
                (((SELECTION) & RCC_PERIPHCLK_LPTIM1)      == RCC_PERIPHCLK_LPTIM1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SAI1)        == RCC_PERIPHCLK_SAI1)    || \
                (((SELECTION) & RCC_PERIPHCLK_SAI2)        == RCC_PERIPHCLK_SAI2)    || \
                (((SELECTION) & RCC_PERIPHCLK_CLK48)       == RCC_PERIPHCLK_CLK48)   || \
                (((SELECTION) & RCC_PERIPHCLK_CEC)         == RCC_PERIPHCLK_CEC)     || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC1)      == RCC_PERIPHCLK_SDMMC1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC2)      == RCC_PERIPHCLK_SDMMC2)  || \
                (((SELECTION) & RCC_PERIPHCLK_DFSDM1)       == RCC_PERIPHCLK_DFSDM1)   || \
                (((SELECTION) & RCC_PERIPHCLK_DFSDM1_AUDIO) == RCC_PERIPHCLK_DFSDM1_AUDIO) || \
                (((SELECTION) & RCC_PERIPHCLK_SPDIFRX)     == RCC_PERIPHCLK_SPDIFRX) || \
                (((SELECTION) & RCC_PERIPHCLK_RTC)         == RCC_PERIPHCLK_RTC))
#elif defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F730xx)
#define IS_RCC_PERIPHCLOCK(SELECTION)  \
               ((((SELECTION) & RCC_PERIPHCLK_I2S)         == RCC_PERIPHCLK_I2S)     || \
                (((SELECTION) & RCC_PERIPHCLK_TIM)         == RCC_PERIPHCLK_TIM)     || \
                (((SELECTION) & RCC_PERIPHCLK_USART1)      == RCC_PERIPHCLK_USART1)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART2)      == RCC_PERIPHCLK_USART2)  || \
                (((SELECTION) & RCC_PERIPHCLK_USART3)      == RCC_PERIPHCLK_USART3)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART4)       == RCC_PERIPHCLK_UART4)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART5)       == RCC_PERIPHCLK_UART5)   || \
                (((SELECTION) & RCC_PERIPHCLK_USART6)      == RCC_PERIPHCLK_USART6)  || \
                (((SELECTION) & RCC_PERIPHCLK_UART7)       == RCC_PERIPHCLK_UART7)   || \
                (((SELECTION) & RCC_PERIPHCLK_UART8)       == RCC_PERIPHCLK_UART8)   || \
                (((SELECTION) & RCC_PERIPHCLK_I2C1)        == RCC_PERIPHCLK_I2C1)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C2)        == RCC_PERIPHCLK_I2C2)    || \
                (((SELECTION) & RCC_PERIPHCLK_I2C3)        == RCC_PERIPHCLK_I2C3)    || \
                (((SELECTION) & RCC_PERIPHCLK_LPTIM1)      == RCC_PERIPHCLK_LPTIM1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SAI1)        == RCC_PERIPHCLK_SAI1)    || \
                (((SELECTION) & RCC_PERIPHCLK_SAI2)        == RCC_PERIPHCLK_SAI2)    || \
                (((SELECTION) & RCC_PERIPHCLK_CLK48)       == RCC_PERIPHCLK_CLK48)   || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC1)      == RCC_PERIPHCLK_SDMMC1)  || \
                (((SELECTION) & RCC_PERIPHCLK_SDMMC2)      == RCC_PERIPHCLK_SDMMC2)  || \
                (((SELECTION) & RCC_PERIPHCLK_RTC)         == RCC_PERIPHCLK_RTC))
#endif 
#define IS_RCC_PLLI2SN_VALUE(VALUE) ((50 <= (VALUE)) && ((VALUE) <= 432))
#if defined (STM32F745xx) || defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F765xx) || defined (STM32F767xx) || \
    defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F750xx)
#define IS_RCC_PLLI2SP_VALUE(VALUE) (((VALUE) == RCC_PLLI2SP_DIV2) ||\
                                     ((VALUE) == RCC_PLLI2SP_DIV4) ||\
                                     ((VALUE) == RCC_PLLI2SP_DIV6) ||\
                                     ((VALUE) == RCC_PLLI2SP_DIV8))
#endif 
#define IS_RCC_PLLI2SQ_VALUE(VALUE) ((2 <= (VALUE)) && ((VALUE) <= 15))
#define IS_RCC_PLLI2SR_VALUE(VALUE) ((2 <= (VALUE)) && ((VALUE) <= 7))

#define IS_RCC_PLLSAIN_VALUE(VALUE) ((50 <= (VALUE)) && ((VALUE) <= 432))
#define IS_RCC_PLLSAIP_VALUE(VALUE) (((VALUE) == RCC_PLLSAIP_DIV2) ||\
                                     ((VALUE) == RCC_PLLSAIP_DIV4) ||\
                                     ((VALUE) == RCC_PLLSAIP_DIV6) ||\
                                     ((VALUE) == RCC_PLLSAIP_DIV8))
#define IS_RCC_PLLSAIQ_VALUE(VALUE) ((2 <= (VALUE)) && ((VALUE) <= 15))
#define IS_RCC_PLLSAIR_VALUE(VALUE) ((2 <= (VALUE)) && ((VALUE) <= 7))

#define IS_RCC_PLLSAI_DIVQ_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 32))

#define IS_RCC_PLLI2S_DIVQ_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 32))

#define IS_RCC_PLLSAI_DIVR_VALUE(VALUE) (((VALUE) == RCC_PLLSAIDIVR_2) ||\
                                         ((VALUE) == RCC_PLLSAIDIVR_4) ||\
                                         ((VALUE) == RCC_PLLSAIDIVR_8) ||\
                                         ((VALUE) == RCC_PLLSAIDIVR_16))
#define IS_RCC_I2SCLKSOURCE(SOURCE)  (((SOURCE) == RCC_I2SCLKSOURCE_PLLI2S) || \
                                      ((SOURCE) == RCC_I2SCLKSOURCE_EXT))

#define IS_RCC_SDMMC1CLKSOURCE(SOURCE) (((SOURCE) == RCC_SDMMC1CLKSOURCE_SYSCLK) || \
                                        ((SOURCE) == RCC_SDMMC1CLKSOURCE_CLK48))

#define IS_RCC_CECCLKSOURCE(SOURCE)  (((SOURCE) == RCC_CECCLKSOURCE_HSI) || \
                                      ((SOURCE) == RCC_CECCLKSOURCE_LSE))
#define IS_RCC_USART1CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_USART1CLKSOURCE_PCLK2)  || \
                ((SOURCE) == RCC_USART1CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_USART1CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_USART1CLKSOURCE_HSI))

#define IS_RCC_USART2CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_USART2CLKSOURCE_PCLK1)  || \
                ((SOURCE) == RCC_USART2CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_USART2CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_USART2CLKSOURCE_HSI))
#define IS_RCC_USART3CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_USART3CLKSOURCE_PCLK1)  || \
                ((SOURCE) == RCC_USART3CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_USART3CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_USART3CLKSOURCE_HSI))

#define IS_RCC_UART4CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_UART4CLKSOURCE_PCLK1)  || \
                ((SOURCE) == RCC_UART4CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_UART4CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_UART4CLKSOURCE_HSI))

#define IS_RCC_UART5CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_UART5CLKSOURCE_PCLK1)  || \
                ((SOURCE) == RCC_UART5CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_UART5CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_UART5CLKSOURCE_HSI))

#define IS_RCC_USART6CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_USART6CLKSOURCE_PCLK2)  || \
                ((SOURCE) == RCC_USART6CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_USART6CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_USART6CLKSOURCE_HSI))

#define IS_RCC_UART7CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_UART7CLKSOURCE_PCLK1)  || \
                ((SOURCE) == RCC_UART7CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_UART7CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_UART7CLKSOURCE_HSI))

#define IS_RCC_UART8CLKSOURCE(SOURCE)  \
               (((SOURCE) == RCC_UART8CLKSOURCE_PCLK1)  || \
                ((SOURCE) == RCC_UART8CLKSOURCE_SYSCLK) || \
                ((SOURCE) == RCC_UART8CLKSOURCE_LSE)    || \
                ((SOURCE) == RCC_UART8CLKSOURCE_HSI))
#define IS_RCC_I2C1CLKSOURCE(SOURCE)   \
               (((SOURCE) == RCC_I2C1CLKSOURCE_PCLK1) || \
                ((SOURCE) == RCC_I2C1CLKSOURCE_SYSCLK)|| \
                ((SOURCE) == RCC_I2C1CLKSOURCE_HSI))
#define IS_RCC_I2C2CLKSOURCE(SOURCE)   \
               (((SOURCE) == RCC_I2C2CLKSOURCE_PCLK1) || \
                ((SOURCE) == RCC_I2C2CLKSOURCE_SYSCLK)|| \
                ((SOURCE) == RCC_I2C2CLKSOURCE_HSI))

#define IS_RCC_I2C3CLKSOURCE(SOURCE)   \
               (((SOURCE) == RCC_I2C3CLKSOURCE_PCLK1) || \
                ((SOURCE) == RCC_I2C3CLKSOURCE_SYSCLK)|| \
                ((SOURCE) == RCC_I2C3CLKSOURCE_HSI))
#define IS_RCC_I2C4CLKSOURCE(SOURCE)   \
               (((SOURCE) == RCC_I2C4CLKSOURCE_PCLK1) || \
                ((SOURCE) == RCC_I2C4CLKSOURCE_SYSCLK)|| \
                ((SOURCE) == RCC_I2C4CLKSOURCE_HSI))
#define IS_RCC_LPTIM1CLK(SOURCE)  \
               (((SOURCE) == RCC_LPTIM1CLKSOURCE_PCLK1) || \
                ((SOURCE) == RCC_LPTIM1CLKSOURCE_LSI)  || \
                ((SOURCE) == RCC_LPTIM1CLKSOURCE_HSI)  || \
                ((SOURCE) == RCC_LPTIM1CLKSOURCE_LSE))
#define IS_RCC_CLK48SOURCE(SOURCE)  \
               (((SOURCE) == RCC_CLK48SOURCE_PLLSAIP) || \
                ((SOURCE) == RCC_CLK48SOURCE_PLL))
#define IS_RCC_TIMPRES(VALUE)  \
               (((VALUE) == RCC_TIMPRES_DESACTIVATED) || \
                ((VALUE) == RCC_TIMPRES_ACTIVATED))

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F745xx) ||\
    defined (STM32F746xx) || defined (STM32F756xx) || defined (STM32F730xx) || defined (STM32F750xx)
#define IS_RCC_SAI1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_SAI1CLKSOURCE_PLLSAI) || \
                                       ((SOURCE) == RCC_SAI1CLKSOURCE_PLLI2S) || \
                                       ((SOURCE) == RCC_SAI1CLKSOURCE_PIN))
#define IS_RCC_SAI2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_SAI2CLKSOURCE_PLLSAI) || \
                                       ((SOURCE) == RCC_SAI2CLKSOURCE_PLLI2S) || \
                                       ((SOURCE) == RCC_SAI2CLKSOURCE_PIN))
#endif 

#if defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define IS_RCC_PLLR_VALUE(VALUE)            ((2 <= (VALUE)) && ((VALUE) <= 7))

#define IS_RCC_SAI1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_SAI1CLKSOURCE_PLLSAI) || \
                                       ((SOURCE) == RCC_SAI1CLKSOURCE_PLLI2S) || \
                                       ((SOURCE) == RCC_SAI1CLKSOURCE_PIN)    || \
                                       ((SOURCE) == RCC_SAI1CLKSOURCE_PLLSRC))

#define IS_RCC_SAI2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_SAI2CLKSOURCE_PLLSAI) || \
                                       ((SOURCE) == RCC_SAI2CLKSOURCE_PLLI2S) || \
                                       ((SOURCE) == RCC_SAI2CLKSOURCE_PIN)    || \
                                       ((SOURCE) == RCC_SAI2CLKSOURCE_PLLSRC))

#define IS_RCC_DFSDM1CLKSOURCE(SOURCE)  (((SOURCE) == RCC_DFSDM1CLKSOURCE_PCLK2) || \
                                        ((SOURCE) == RCC_DFSDM1CLKSOURCE_SYSCLK))

#define IS_RCC_DFSDM1AUDIOCLKSOURCE(SOURCE)  (((SOURCE) == RCC_DFSDM1AUDIOCLKSOURCE_SAI1) || \
                                             ((SOURCE) == RCC_DFSDM1AUDIOCLKSOURCE_SAI2))
#endif 

#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) || defined (STM32F765xx) ||\
    defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F730xx)
#define IS_RCC_SDMMC2CLKSOURCE(SOURCE)  (((SOURCE) == RCC_SDMMC2CLKSOURCE_SYSCLK) || \
                                         ((SOURCE) == RCC_SDMMC2CLKSOURCE_CLK48))
#endif 

#if defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx)
#define IS_RCC_DSIBYTELANECLKSOURCE(SOURCE) (((SOURCE) == RCC_DSICLKSOURCE_PLLR)  ||\
                                             ((SOURCE) == RCC_DSICLKSOURCE_DSIPHY))
#endif 








#ifdef __cplusplus
}
#endif

#endif 


