


#ifndef __STM32F7xx_HAL_DMA_EX_H
#define __STM32F7xx_HAL_DMA_EX_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f7xx_hal_def.h"



 



   
 
typedef enum
{
  MEMORY0      = 0x00U,    
  MEMORY1      = 0x01U,    

}HAL_DMA_MemoryTypeDef;


  




 
#define DMA_CHANNEL_0                     0x00000000U  
#define DMA_CHANNEL_1                     0x02000000U  
#define DMA_CHANNEL_2                     0x04000000U  
#define DMA_CHANNEL_3                     0x06000000U  
#define DMA_CHANNEL_4                     0x08000000U  
#define DMA_CHANNEL_5                     0x0A000000U  
#define DMA_CHANNEL_6                     0x0C000000U  
#define DMA_CHANNEL_7                     0x0E000000U  
#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define DMA_CHANNEL_8                     0x10000000U  
#define DMA_CHANNEL_9                     0x12000000U  
#define DMA_CHANNEL_10                    0x14000000U  
#define DMA_CHANNEL_11                    0x16000000U  
#define DMA_CHANNEL_12                    0x18000000U  
#define DMA_CHANNEL_13                    0x1A000000U  
#define DMA_CHANNEL_14                    0x1C000000U  
#define DMA_CHANNEL_15                    0x1E000000U  
#endif 


  
  







HAL_StatusTypeDef HAL_DMAEx_MultiBufferStart(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t SecondMemAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMAEx_MultiBufferStart_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t SecondMemAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMAEx_ChangeMemory(DMA_HandleTypeDef *hdma, uint32_t Address, HAL_DMA_MemoryTypeDef memory);



  


#if defined (STM32F722xx) || defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx) ||\
    defined (STM32F765xx) || defined (STM32F767xx) || defined (STM32F769xx) || defined (STM32F777xx) ||\
    defined (STM32F779xx) || defined (STM32F730xx)
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == DMA_CHANNEL_0)  || \
                                 ((CHANNEL) == DMA_CHANNEL_1)  || \
                                 ((CHANNEL) == DMA_CHANNEL_2)  || \
                                 ((CHANNEL) == DMA_CHANNEL_3)  || \
                                 ((CHANNEL) == DMA_CHANNEL_4)  || \
                                 ((CHANNEL) == DMA_CHANNEL_5)  || \
                                 ((CHANNEL) == DMA_CHANNEL_6)  || \
                                 ((CHANNEL) == DMA_CHANNEL_7)  || \
                                 ((CHANNEL) == DMA_CHANNEL_8)  || \
                                 ((CHANNEL) == DMA_CHANNEL_9)  || \
                                 ((CHANNEL) == DMA_CHANNEL_10) || \
                                 ((CHANNEL) == DMA_CHANNEL_11) || \
                                 ((CHANNEL) == DMA_CHANNEL_12) || \
                                 ((CHANNEL) == DMA_CHANNEL_13) || \
                                 ((CHANNEL) == DMA_CHANNEL_14) || \
                                 ((CHANNEL) == DMA_CHANNEL_15)) 
#else
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == DMA_CHANNEL_0) || \
                                 ((CHANNEL) == DMA_CHANNEL_1) || \
                                 ((CHANNEL) == DMA_CHANNEL_2) || \
                                 ((CHANNEL) == DMA_CHANNEL_3) || \
                                 ((CHANNEL) == DMA_CHANNEL_4) || \
                                 ((CHANNEL) == DMA_CHANNEL_5) || \
                                 ((CHANNEL) == DMA_CHANNEL_6) || \
                                 ((CHANNEL) == DMA_CHANNEL_7))
#endif 
  
         








#ifdef __cplusplus
}
#endif

#endif 


