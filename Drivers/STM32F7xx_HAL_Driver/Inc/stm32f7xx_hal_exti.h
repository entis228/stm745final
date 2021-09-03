


#ifndef STM32F7xx_HAL_EXTI_H
#define STM32F7xx_HAL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f7xx_hal_def.h"








typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U
} EXTI_CallbackIDTypeDef;


typedef struct
{
  uint32_t Line;                    
  void (* PendingCallback)(void);   
} EXTI_HandleTypeDef;


typedef struct
{
  uint32_t Line;      
  uint32_t Mode;      
  uint32_t Trigger;   
  uint32_t GPIOSel;   
} EXTI_ConfigTypeDef;







#define EXTI_LINE_0                          (EXTI_GPIO       | 0x00u)    
#define EXTI_LINE_1                          (EXTI_GPIO       | 0x01u)    
#define EXTI_LINE_2                          (EXTI_GPIO       | 0x02u)    
#define EXTI_LINE_3                          (EXTI_GPIO       | 0x03u)    
#define EXTI_LINE_4                          (EXTI_GPIO       | 0x04u)    
#define EXTI_LINE_5                          (EXTI_GPIO       | 0x05u)    
#define EXTI_LINE_6                          (EXTI_GPIO       | 0x06u)    
#define EXTI_LINE_7                          (EXTI_GPIO       | 0x07u)    
#define EXTI_LINE_8                          (EXTI_GPIO       | 0x08u)    
#define EXTI_LINE_9                          (EXTI_GPIO       | 0x09u)    
#define EXTI_LINE_10                         (EXTI_GPIO       | 0x0Au)    
#define EXTI_LINE_11                         (EXTI_GPIO       | 0x0Bu)    
#define EXTI_LINE_12                         (EXTI_GPIO       | 0x0Cu)    
#define EXTI_LINE_13                         (EXTI_GPIO       | 0x0Du)    
#define EXTI_LINE_14                         (EXTI_GPIO       | 0x0Eu)    
#define EXTI_LINE_15                         (EXTI_GPIO       | 0x0Fu)    
#define EXTI_LINE_16                         (EXTI_CONFIG     | 0x10u)    
#define EXTI_LINE_17                         (EXTI_CONFIG     | 0x11u)    
#define EXTI_LINE_18                         (EXTI_CONFIG     | 0x12u)    
#if defined(ETH)
#define EXTI_LINE_19                         (EXTI_CONFIG     | 0x13u)    
#else
#define EXTI_LINE_19                         (EXTI_RESERVED   | 0x13u)    
#endif 
#define EXTI_LINE_20                         (EXTI_CONFIG     | 0x14u)    
#define EXTI_LINE_21                         (EXTI_CONFIG     | 0x15u)    
#define EXTI_LINE_22                         (EXTI_CONFIG     | 0x16u)    
#define EXTI_LINE_23                         (EXTI_CONFIG     | 0x17u)    
#if defined(EXTI_IMR_IM24)
#define EXTI_LINE_24                         (EXTI_CONFIG     | 0x18u)    
#endif 



#define EXTI_MODE_NONE                      0x00000000u
#define EXTI_MODE_INTERRUPT                 0x00000001u
#define EXTI_MODE_EVENT                     0x00000002u




#define EXTI_TRIGGER_NONE                   0x00000000u
#define EXTI_TRIGGER_RISING                 0x00000001u
#define EXTI_TRIGGER_FALLING                0x00000002u
#define EXTI_TRIGGER_RISING_FALLING         (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)



#define EXTI_GPIOA                          0x00000000u
#define EXTI_GPIOB                          0x00000001u
#define EXTI_GPIOC                          0x00000002u
#define EXTI_GPIOD                          0x00000003u
#define EXTI_GPIOE                          0x00000004u
#define EXTI_GPIOF                          0x00000005u
#define EXTI_GPIOG                          0x00000006u
#define EXTI_GPIOH                          0x00000007u
#define EXTI_GPIOI                          0x00000008u
#define EXTI_GPIOJ                          0x00000009u
#if defined (GPIOK)
#define EXTI_GPIOK                          0x0000000Au
#endif 











#define EXTI_PROPERTY_SHIFT                  24u
#define EXTI_CONFIG                         (0x02uL << EXTI_PROPERTY_SHIFT)
#define EXTI_GPIO                           ((0x04uL << EXTI_PROPERTY_SHIFT) | EXTI_CONFIG)
#define EXTI_RESERVED                       (0x08uL << EXTI_PROPERTY_SHIFT)
#define EXTI_PROPERTY_MASK                  (EXTI_CONFIG | EXTI_GPIO)


#define EXTI_PIN_MASK                       0x0000001Fu


#define EXTI_MODE_MASK                      (EXTI_MODE_EVENT | EXTI_MODE_INTERRUPT)


#define EXTI_TRIGGER_MASK                   (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)


#if defined(EXTI_IMR_IM24)
#define EXTI_LINE_NB                        25u
#else
#define EXTI_LINE_NB                        24u
#endif 






#define IS_EXTI_LINE(__EXTI_LINE__)          ((((__EXTI_LINE__) & ~(EXTI_PROPERTY_MASK | EXTI_PIN_MASK)) == 0x00u) && \
                                             ((((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_CONFIG)   || \
                                              (((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_GPIO))    && \
                                              (((__EXTI_LINE__) & EXTI_PIN_MASK) < EXTI_LINE_NB))

#define IS_EXTI_MODE(__EXTI_LINE__)          ((((__EXTI_LINE__) & EXTI_MODE_MASK) != 0x00u) && \
                                              (((__EXTI_LINE__) & ~EXTI_MODE_MASK) == 0x00u))

#define IS_EXTI_TRIGGER(__EXTI_LINE__)       (((__EXTI_LINE__)  & ~EXTI_TRIGGER_MASK) == 0x00u)

#define IS_EXTI_PENDING_EDGE(__EXTI_LINE__)  (((__EXTI_LINE__) == EXTI_TRIGGER_FALLING) || \
                                              ((__EXTI_LINE__) == EXTI_TRIGGER_RISING)  || \
                                              ((__EXTI_LINE__) == EXTI_TRIGGER_RISING_FALLING))

#define IS_EXTI_CONFIG_LINE(__EXTI_LINE__)   (((__EXTI_LINE__) & EXTI_CONFIG) != 0x00u)

#if defined (GPIOK)
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF) || \
                                         ((__PORT__) == EXTI_GPIOG) || \
                                         ((__PORT__) == EXTI_GPIOH) || \
                                         ((__PORT__) == EXTI_GPIOI) || \
                                         ((__PORT__) == EXTI_GPIOJ) || \
                                         ((__PORT__) == EXTI_GPIOK))
#else
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF) || \
                                         ((__PORT__) == EXTI_GPIOG) || \
                                         ((__PORT__) == EXTI_GPIOH) || \
                                         ((__PORT__) == EXTI_GPIOI) || \
                                         ((__PORT__) == EXTI_GPIOJ))
#endif 

#define IS_EXTI_GPIO_PIN(__PIN__)       ((__PIN__) < 16U)







HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);




void HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);
uint32_t HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti);









#ifdef __cplusplus
}
#endif

#endif 


