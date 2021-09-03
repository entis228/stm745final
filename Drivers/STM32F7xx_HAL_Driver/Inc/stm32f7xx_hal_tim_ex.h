


#ifndef STM32F7xx_HAL_TIM_EX_H
#define STM32F7xx_HAL_TIM_EX_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f7xx_hal_def.h"










typedef struct
{
  uint32_t IC1Polarity;         

  uint32_t IC1Prescaler;        

  uint32_t IC1Filter;           

  uint32_t Commutation_Delay;   
} TIM_HallSensor_InitTypeDef;
#if defined(TIM_BREAK_INPUT_SUPPORT)


typedef struct
{
  uint32_t Source;         
  uint32_t Enable;         
  uint32_t Polarity;       
}
TIMEx_BreakInputConfigTypeDef;

#endif 







#define TIM_TIM2_TIM8_TRGO                     (0x00000000U)
#define TIM_TIM2_ETH_PTP                       (0x00000400U)
#define TIM_TIM2_USBFS_SOF                     (0x00000800U)
#define TIM_TIM2_USBHS_SOF                     (0x00000C00U)
#define TIM_TIM5_GPIO                          (0x00000000U)
#define TIM_TIM5_LSI                           (0x00000040U)
#define TIM_TIM5_LSE                           (0x00000080U)
#define TIM_TIM5_RTC                           (0x000000C0U)
#define TIM_TIM11_GPIO                         (0x00000000U)
#define TIM_TIM11_SPDIFRX                      (0x00000001U)
#define TIM_TIM11_HSE                          (0x00000002U)
#define TIM_TIM11_MCO1                         (0x00000003U)

#if defined(TIM_BREAK_INPUT_SUPPORT)


#define TIM_BREAKINPUT_BRK     0x00000001U                                      
#define TIM_BREAKINPUT_BRK2    0x00000002U                                      



#define TIM_BREAKINPUTSOURCE_BKIN     (0x00000001U)                  
#define TIM_BREAKINPUTSOURCE_DFSDM1   (0x00000008U)                  



#define TIM_BREAKINPUTSOURCE_DISABLE     0x00000000U                            
#define TIM_BREAKINPUTSOURCE_ENABLE      0x00000001U                            



#define TIM_BREAKINPUTSOURCE_POLARITY_LOW     0x00000001U                       
#define TIM_BREAKINPUTSOURCE_POLARITY_HIGH    0x00000000U                       

#endif 












#define IS_TIM_REMAP(__TIM_REMAP__)  (((__TIM_REMAP__) == TIM_TIM2_TIM8_TRGO)||\
                                      ((__TIM_REMAP__) == TIM_TIM2_ETH_PTP)  ||\
                                      ((__TIM_REMAP__) == TIM_TIM2_USBFS_SOF)||\
                                      ((__TIM_REMAP__) == TIM_TIM2_USBHS_SOF)||\
                                      ((__TIM_REMAP__) == TIM_TIM5_GPIO)     ||\
                                      ((__TIM_REMAP__) == TIM_TIM5_LSI)      ||\
                                      ((__TIM_REMAP__) == TIM_TIM5_LSE)      ||\
                                      ((__TIM_REMAP__) == TIM_TIM5_RTC)      ||\
                                      ((__TIM_REMAP__) == TIM_TIM11_GPIO)    ||\
                                      ((__TIM_REMAP__) == TIM_TIM11_SPDIFRX) ||\
                                      ((__TIM_REMAP__) == TIM_TIM11_HSE)     ||\
                                      ((__TIM_REMAP__) == TIM_TIM11_MCO1))
#if defined(TIM_BREAK_INPUT_SUPPORT)

#define IS_TIM_BREAKINPUT(__BREAKINPUT__)  (((__BREAKINPUT__) == TIM_BREAKINPUT_BRK)  || \
                                            ((__BREAKINPUT__) == TIM_BREAKINPUT_BRK2))

#define IS_TIM_BREAKINPUTSOURCE(__SOURCE__)  (((__SOURCE__) == TIM_BREAKINPUTSOURCE_BKIN)  || \
                                              ((__SOURCE__) == TIM_BREAKINPUTSOURCE_DFSDM))

#define IS_TIM_BREAKINPUTSOURCE_STATE(__STATE__)  (((__STATE__) == TIM_BREAKINPUTSOURCE_DISABLE)  || \
                                                   ((__STATE__) == TIM_BREAKINPUTSOURCE_ENABLE))

#define IS_TIM_BREAKINPUTSOURCE_POLARITY(__POLARITY__)  (((__POLARITY__) == TIM_BREAKINPUTSOURCE_POLARITY_LOW)  || \
                                                         ((__POLARITY__) == TIM_BREAKINPUTSOURCE_POLARITY_HIGH))
#endif 









HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, TIM_HallSensor_InitTypeDef *sConfig);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim);

void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim);


HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim);





HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);


HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);


HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);





HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);


HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);





HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);


HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);




HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                              uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                 uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_DMA(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                  uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim,
                                                        TIM_MasterConfigTypeDef *sMasterConfig);
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim,
                                                TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig);
#if defined(TIM_BREAK_INPUT_SUPPORT)
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakInput(TIM_HandleTypeDef *htim, uint32_t BreakInput,
                                             TIMEx_BreakInputConfigTypeDef *sBreakInputConfig);
#endif 
HAL_StatusTypeDef HAL_TIMEx_GroupChannel5(TIM_HandleTypeDef *htim, uint32_t Channels);
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap);




void HAL_TIMEx_CommutCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_CommutHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_Break2Callback(TIM_HandleTypeDef *htim);




HAL_TIM_StateTypeDef HAL_TIMEx_HallSensor_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_ChannelStateTypeDef HAL_TIMEx_GetChannelNState(TIM_HandleTypeDef *htim,  uint32_t ChannelN);







void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma);
void TIMEx_DMACommutationHalfCplt(DMA_HandleTypeDef *hdma);







#ifdef __cplusplus
}
#endif


#endif 


