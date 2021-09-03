


#ifndef STM32F7xx_HAL_I2C_EX_H
#define STM32F7xx_HAL_I2C_EX_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f7xx_hal_def.h"










#define I2C_ANALOGFILTER_ENABLE         0x00000000U
#define I2C_ANALOGFILTER_DISABLE        I2C_CR1_ANFOFF



#define I2C_FMP_NOT_SUPPORTED           0xAAAA0000U                                     
#if defined(SYSCFG_PMC_I2C_PB6_FMP)
#define I2C_FASTMODEPLUS_PB6            SYSCFG_PMC_I2C_PB6_FMP                        
#define I2C_FASTMODEPLUS_PB7            SYSCFG_PMC_I2C_PB7_FMP                        
#else
#define I2C_FASTMODEPLUS_PB6            (uint32_t)(0x00000004U | I2C_FMP_NOT_SUPPORTED) 
#define I2C_FASTMODEPLUS_PB7            (uint32_t)(0x00000008U | I2C_FMP_NOT_SUPPORTED) 
#endif
#if defined(SYSCFG_PMC_I2C_PB8_FMP)
#define I2C_FASTMODEPLUS_PB8            SYSCFG_PMC_I2C_PB8_FMP                        
#define I2C_FASTMODEPLUS_PB9            SYSCFG_PMC_I2C_PB9_FMP                        
#else
#define I2C_FASTMODEPLUS_PB8            (uint32_t)(0x00000010U | I2C_FMP_NOT_SUPPORTED) 
#define I2C_FASTMODEPLUS_PB9            (uint32_t)(0x00000012U | I2C_FMP_NOT_SUPPORTED) 
#endif
#if defined(SYSCFG_PMC_I2C1_FMP)
#define I2C_FASTMODEPLUS_I2C1           SYSCFG_PMC_I2C1_FMP                           
#else
#define I2C_FASTMODEPLUS_I2C1           (uint32_t)(0x00000100U | I2C_FMP_NOT_SUPPORTED) 
#endif
#if defined(SYSCFG_PMC_I2C2_FMP)
#define I2C_FASTMODEPLUS_I2C2           SYSCFG_PMC_I2C2_FMP                           
#else
#define I2C_FASTMODEPLUS_I2C2           (uint32_t)(0x00000200U | I2C_FMP_NOT_SUPPORTED) 
#endif
#if defined(SYSCFG_PMC_I2C3_FMP)
#define I2C_FASTMODEPLUS_I2C3           SYSCFG_PMC_I2C3_FMP                           
#else
#define I2C_FASTMODEPLUS_I2C3           (uint32_t)(0x00000400U | I2C_FMP_NOT_SUPPORTED) 
#endif
#if defined(SYSCFG_PMC_I2C4_FMP)
#define I2C_FASTMODEPLUS_I2C4           SYSCFG_PMC_I2C4_FMP                           
#else
#define I2C_FASTMODEPLUS_I2C4           (uint32_t)(0x00000800U | I2C_FMP_NOT_SUPPORTED) 
#endif














HAL_StatusTypeDef HAL_I2CEx_ConfigAnalogFilter(I2C_HandleTypeDef *hi2c, uint32_t AnalogFilter);
HAL_StatusTypeDef HAL_I2CEx_ConfigDigitalFilter(I2C_HandleTypeDef *hi2c, uint32_t DigitalFilter);






#if  (defined(SYSCFG_PMC_I2C_PB6_FMP) || defined(SYSCFG_PMC_I2C_PB7_FMP)) || (defined(SYSCFG_PMC_I2C_PB8_FMP) || defined(SYSCFG_PMC_I2C_PB9_FMP)) || (defined(SYSCFG_PMC_I2C1_FMP)) || (defined(SYSCFG_PMC_I2C2_FMP)) || defined(SYSCFG_PMC_I2C3_FMP) || defined(SYSCFG_PMC_I2C4_FMP)
void HAL_I2CEx_EnableFastModePlus(uint32_t ConfigFastModePlus);
void HAL_I2CEx_DisableFastModePlus(uint32_t ConfigFastModePlus);
#endif












#define IS_I2C_ANALOG_FILTER(FILTER)    (((FILTER) == I2C_ANALOGFILTER_ENABLE) || \
                                         ((FILTER) == I2C_ANALOGFILTER_DISABLE))

#define IS_I2C_DIGITAL_FILTER(FILTER)   ((FILTER) <= 0x0000000FU)

#if (defined(SYSCFG_PMC_I2C1_FMP) && defined(SYSCFG_PMC_I2C2_FMP) && defined(SYSCFG_PMC_I2C3_FMP) && defined(SYSCFG_PMC_I2C4_FMP))
#define IS_I2C_FASTMODEPLUS(__CONFIG__) ((((__CONFIG__) & I2C_FASTMODEPLUS_PB6)  == I2C_FASTMODEPLUS_PB6)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB7)  == I2C_FASTMODEPLUS_PB7)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB8)  == I2C_FASTMODEPLUS_PB8)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB9)  == I2C_FASTMODEPLUS_PB9)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C1) == I2C_FASTMODEPLUS_I2C1) || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C2) == I2C_FASTMODEPLUS_I2C2) || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C3) == I2C_FASTMODEPLUS_I2C3) || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C4) == I2C_FASTMODEPLUS_I2C4))
#elif defined(SYSCFG_PMC_I2C1_FMP) && defined(SYSCFG_PMC_I2C2_FMP) && defined(SYSCFG_PMC_I2C3_FMP)
#define IS_I2C_FASTMODEPLUS(__CONFIG__) ((((__CONFIG__) & I2C_FASTMODEPLUS_PB6)  == I2C_FASTMODEPLUS_PB6)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB7)  == I2C_FASTMODEPLUS_PB7)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB8)  == I2C_FASTMODEPLUS_PB8)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB9)  == I2C_FASTMODEPLUS_PB9)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C1) == I2C_FASTMODEPLUS_I2C1) || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C2) == I2C_FASTMODEPLUS_I2C2) || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C3) == I2C_FASTMODEPLUS_I2C3))
#elif defined(SYSCFG_PMC_I2C1_FMP) && defined(SYSCFG_PMC_I2C2_FMP)
#define IS_I2C_FASTMODEPLUS(__CONFIG__) ((((__CONFIG__) & I2C_FASTMODEPLUS_PB6)  == I2C_FASTMODEPLUS_PB6)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB7)  == I2C_FASTMODEPLUS_PB7)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB8)  == I2C_FASTMODEPLUS_PB8)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB9)  == I2C_FASTMODEPLUS_PB9)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C1) == I2C_FASTMODEPLUS_I2C1) || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C2) == I2C_FASTMODEPLUS_I2C2))
#elif defined(SYSCFG_PMC_I2C1_FMP)
#define IS_I2C_FASTMODEPLUS(__CONFIG__) ((((__CONFIG__) & I2C_FASTMODEPLUS_PB6)  == I2C_FASTMODEPLUS_PB6)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB7)  == I2C_FASTMODEPLUS_PB7)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB8)  == I2C_FASTMODEPLUS_PB8)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_PB9)  == I2C_FASTMODEPLUS_PB9)  || \
                                         (((__CONFIG__) & I2C_FASTMODEPLUS_I2C1) == I2C_FASTMODEPLUS_I2C1))
#endif 











#ifdef __cplusplus
}
#endif

#endif 


