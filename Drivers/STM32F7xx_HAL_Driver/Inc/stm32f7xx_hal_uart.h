


#ifndef STM32F7xx_HAL_UART_H
#define STM32F7xx_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f7xx_hal_def.h"









typedef struct
{
  uint32_t BaudRate;                

  uint32_t WordLength;              

  uint32_t StopBits;                

  uint32_t Parity;                  

  uint32_t Mode;                    

  uint32_t HwFlowCtl;               

  uint32_t OverSampling;            

  uint32_t OneBitSampling;          


} UART_InitTypeDef;


typedef struct
{
  uint32_t AdvFeatureInit;        

  uint32_t TxPinLevelInvert;      

  uint32_t RxPinLevelInvert;      

  uint32_t DataInvert;            

  uint32_t Swap;                  

  uint32_t OverrunDisable;        

  uint32_t DMADisableonRxError;   

  uint32_t AutoBaudRateEnable;    

  uint32_t AutoBaudRateMode;      

  uint32_t MSBFirst;              
} UART_AdvFeatureInitTypeDef;


typedef uint32_t HAL_UART_StateTypeDef;


typedef enum
{
  UART_CLOCKSOURCE_PCLK1      = 0x00U,    
  UART_CLOCKSOURCE_PCLK2      = 0x01U,    
  UART_CLOCKSOURCE_HSI        = 0x02U,    
  UART_CLOCKSOURCE_SYSCLK     = 0x04U,    
  UART_CLOCKSOURCE_LSE        = 0x08U,    
  UART_CLOCKSOURCE_UNDEFINED  = 0x10U     
} UART_ClockSourceTypeDef;


typedef uint32_t HAL_UART_RxTypeTypeDef;


typedef struct __UART_HandleTypeDef
{
  USART_TypeDef            *Instance;                

  UART_InitTypeDef         Init;                     

  UART_AdvFeatureInitTypeDef AdvancedInit;           

  uint8_t                  *pTxBuffPtr;              

  uint16_t                 TxXferSize;               

  __IO uint16_t            TxXferCount;              

  uint8_t                  *pRxBuffPtr;              

  uint16_t                 RxXferSize;               

  __IO uint16_t            RxXferCount;              

  uint16_t                 Mask;                     

  __IO HAL_UART_RxTypeTypeDef ReceptionType;         

  void (*RxISR)(struct __UART_HandleTypeDef *huart); 

  void (*TxISR)(struct __UART_HandleTypeDef *huart); 

  DMA_HandleTypeDef        *hdmatx;                  

  DMA_HandleTypeDef        *hdmarx;                  

  HAL_LockTypeDef           Lock;                    

  __IO HAL_UART_StateTypeDef    gState;              

  __IO HAL_UART_StateTypeDef    RxState;             

  __IO uint32_t                 ErrorCode;           

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            
  void (* RxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); 
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  
#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
  void (* WakeupCallback)(struct __UART_HandleTypeDef *huart);            
#endif 
#endif 
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); 

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         
#endif  

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)

typedef enum
{
  HAL_UART_TX_HALFCOMPLETE_CB_ID         = 0x00U,    
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    
  HAL_UART_RX_HALFCOMPLETE_CB_ID         = 0x02U,    
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    
  HAL_UART_ERROR_CB_ID                   = 0x04U,    
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    
  HAL_UART_WAKEUP_CB_ID                  = 0x08U,    

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU     

} HAL_UART_CallbackIDTypeDef;


typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart); 
typedef  void (*pUART_RxEventCallbackTypeDef)
(struct __UART_HandleTypeDef *huart, uint16_t Pos); 

#endif 







#define  HAL_UART_STATE_RESET         0x00000000U    
#define  HAL_UART_STATE_READY         0x00000020U    
#define  HAL_UART_STATE_BUSY          0x00000024U    
#define  HAL_UART_STATE_BUSY_TX       0x00000021U    
#define  HAL_UART_STATE_BUSY_RX       0x00000022U    
#define  HAL_UART_STATE_BUSY_TX_RX    0x00000023U    
#define  HAL_UART_STATE_TIMEOUT       0x000000A0U    
#define  HAL_UART_STATE_ERROR         0x000000E0U    



#define  HAL_UART_ERROR_NONE             (0x00000000U)    
#define  HAL_UART_ERROR_PE               (0x00000001U)    
#define  HAL_UART_ERROR_NE               (0x00000002U)    
#define  HAL_UART_ERROR_FE               (0x00000004U)    
#define  HAL_UART_ERROR_ORE              (0x00000008U)    
#define  HAL_UART_ERROR_DMA              (0x00000010U)    
#define  HAL_UART_ERROR_RTO              (0x00000020U)    

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK (0x00000040U)    
#endif 



#define UART_STOPBITS_0_5                    USART_CR2_STOP_0                     
#define UART_STOPBITS_1                     0x00000000U                           
#define UART_STOPBITS_1_5                   (USART_CR2_STOP_0 | USART_CR2_STOP_1) 
#define UART_STOPBITS_2                      USART_CR2_STOP_1                     



#define UART_PARITY_NONE                    0x00000000U                        
#define UART_PARITY_EVEN                    USART_CR1_PCE                      
#define UART_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)     



#define UART_HWCONTROL_NONE                  0x00000000U                          
#define UART_HWCONTROL_RTS                   USART_CR3_RTSE                       
#define UART_HWCONTROL_CTS                   USART_CR3_CTSE                       
#define UART_HWCONTROL_RTS_CTS               (USART_CR3_RTSE | USART_CR3_CTSE)    



#define UART_MODE_RX                        USART_CR1_RE                    
#define UART_MODE_TX                        USART_CR1_TE                    
#define UART_MODE_TX_RX                     (USART_CR1_TE |USART_CR1_RE)    



#define UART_STATE_DISABLE                  0x00000000U         
#define UART_STATE_ENABLE                   USART_CR1_UE        



#define UART_OVERSAMPLING_16                0x00000000U         
#define UART_OVERSAMPLING_8                 USART_CR1_OVER8     



#define UART_ONE_BIT_SAMPLE_DISABLE         0x00000000U         
#define UART_ONE_BIT_SAMPLE_ENABLE          USART_CR3_ONEBIT    



#define UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT    0x00000000U           
#define UART_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE USART_CR2_ABRMODE_0   
#define UART_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME   USART_CR2_ABRMODE_1   
#define UART_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME   USART_CR2_ABRMODE     



#define UART_RECEIVER_TIMEOUT_DISABLE       0x00000000U                
#define UART_RECEIVER_TIMEOUT_ENABLE        USART_CR2_RTOEN            



#define UART_LIN_DISABLE                    0x00000000U                
#define UART_LIN_ENABLE                     USART_CR2_LINEN            



#define UART_LINBREAKDETECTLENGTH_10B       0x00000000U                
#define UART_LINBREAKDETECTLENGTH_11B       USART_CR2_LBDL             



#define UART_DMA_TX_DISABLE                 0x00000000U                
#define UART_DMA_TX_ENABLE                  USART_CR3_DMAT             



#define UART_DMA_RX_DISABLE                 0x00000000U                 
#define UART_DMA_RX_ENABLE                  USART_CR3_DMAR              



#define UART_HALF_DUPLEX_DISABLE            0x00000000U                 
#define UART_HALF_DUPLEX_ENABLE             USART_CR3_HDSEL             



#define UART_WAKEUPMETHOD_IDLELINE          0x00000000U                 
#define UART_WAKEUPMETHOD_ADDRESSMARK       USART_CR1_WAKE              



#define UART_AUTOBAUD_REQUEST               USART_RQR_ABRRQ        
#define UART_SENDBREAK_REQUEST              USART_RQR_SBKRQ        
#define UART_MUTE_MODE_REQUEST              USART_RQR_MMRQ         
#define UART_RXDATA_FLUSH_REQUEST           USART_RQR_RXFRQ        
#define UART_TXDATA_FLUSH_REQUEST           USART_RQR_TXFRQ        



#define UART_ADVFEATURE_NO_INIT                 0x00000000U          
#define UART_ADVFEATURE_TXINVERT_INIT           0x00000001U          
#define UART_ADVFEATURE_RXINVERT_INIT           0x00000002U          
#define UART_ADVFEATURE_DATAINVERT_INIT         0x00000004U          
#define UART_ADVFEATURE_SWAP_INIT               0x00000008U          
#define UART_ADVFEATURE_RXOVERRUNDISABLE_INIT   0x00000010U          
#define UART_ADVFEATURE_DMADISABLEONERROR_INIT  0x00000020U          
#define UART_ADVFEATURE_AUTOBAUDRATE_INIT       0x00000040U          
#define UART_ADVFEATURE_MSBFIRST_INIT           0x00000080U          



#define UART_ADVFEATURE_TXINV_DISABLE       0x00000000U             
#define UART_ADVFEATURE_TXINV_ENABLE        USART_CR2_TXINV         



#define UART_ADVFEATURE_RXINV_DISABLE       0x00000000U             
#define UART_ADVFEATURE_RXINV_ENABLE        USART_CR2_RXINV         



#define UART_ADVFEATURE_DATAINV_DISABLE     0x00000000U             
#define UART_ADVFEATURE_DATAINV_ENABLE      USART_CR2_DATAINV       



#define UART_ADVFEATURE_SWAP_DISABLE        0x00000000U             
#define UART_ADVFEATURE_SWAP_ENABLE         USART_CR2_SWAP          



#define UART_ADVFEATURE_OVERRUN_ENABLE      0x00000000U             
#define UART_ADVFEATURE_OVERRUN_DISABLE     USART_CR3_OVRDIS        



#define UART_ADVFEATURE_AUTOBAUDRATE_DISABLE   0x00000000U          
#define UART_ADVFEATURE_AUTOBAUDRATE_ENABLE    USART_CR2_ABREN      



#define UART_ADVFEATURE_DMA_ENABLEONRXERROR    0x00000000U          
#define UART_ADVFEATURE_DMA_DISABLEONRXERROR   USART_CR3_DDRE       



#define UART_ADVFEATURE_MSBFIRST_DISABLE    0x00000000U             
#define UART_ADVFEATURE_MSBFIRST_ENABLE     USART_CR2_MSBFIRST      

#if defined(USART_CR1_UESM)


#define UART_ADVFEATURE_STOPMODE_DISABLE    0x00000000U             
#define UART_ADVFEATURE_STOPMODE_ENABLE     USART_CR1_UESM          

#endif 


#define UART_ADVFEATURE_MUTEMODE_DISABLE    0x00000000U             
#define UART_ADVFEATURE_MUTEMODE_ENABLE     USART_CR1_MME           



#define UART_CR2_ADDRESS_LSB_POS             24U             

#if defined(USART_CR1_UESM)


#if defined(USART_CR3_WUS)
#define UART_WAKEUP_ON_ADDRESS              0x00000000U             
#define UART_WAKEUP_ON_STARTBIT             USART_CR3_WUS_1         
#define UART_WAKEUP_ON_READDATA_NONEMPTY    USART_CR3_WUS           
#else
#define UART_WAKEUP_ON_ADDRESS              0x00000000U             
#define UART_WAKEUP_ON_READDATA_NONEMPTY    0x00000001U             
#endif 

#endif 


#define UART_DE_POLARITY_HIGH               0x00000000U             
#define UART_DE_POLARITY_LOW                USART_CR3_DEP           



#define UART_CR1_DEAT_ADDRESS_LSB_POS       21U      



#define UART_CR1_DEDT_ADDRESS_LSB_POS       16U      



#define UART_IT_MASK                        0x001FU  



#define HAL_UART_TIMEOUT_VALUE              0x1FFFFFFU  



#if defined(USART_ISR_REACK)
#define UART_FLAG_REACK                     USART_ISR_REACK         
#endif 
#define UART_FLAG_TEACK                     USART_ISR_TEACK         
#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
#define UART_FLAG_WUF                       USART_ISR_WUF           
#endif 
#endif 
#define UART_FLAG_RWU                       USART_ISR_RWU           
#define UART_FLAG_SBKF                      USART_ISR_SBKF          
#define UART_FLAG_CMF                       USART_ISR_CMF           
#define UART_FLAG_BUSY                      USART_ISR_BUSY          
#define UART_FLAG_ABRF                      USART_ISR_ABRF          
#define UART_FLAG_ABRE                      USART_ISR_ABRE          
#define UART_FLAG_RTOF                      USART_ISR_RTOF          
#define UART_FLAG_CTS                       USART_ISR_CTS           
#define UART_FLAG_CTSIF                     USART_ISR_CTSIF         
#define UART_FLAG_LBDF                      USART_ISR_LBDF          
#define UART_FLAG_TXE                       USART_ISR_TXE           
#define UART_FLAG_TC                        USART_ISR_TC            
#define UART_FLAG_RXNE                      USART_ISR_RXNE          
#define UART_FLAG_IDLE                      USART_ISR_IDLE          
#define UART_FLAG_ORE                       USART_ISR_ORE           
#define UART_FLAG_NE                        USART_ISR_NE            
#define UART_FLAG_FE                        USART_ISR_FE            
#define UART_FLAG_PE                        USART_ISR_PE            



#define UART_IT_PE                          0x0028U              
#define UART_IT_TXE                         0x0727U              
#define UART_IT_TC                          0x0626U              
#define UART_IT_RXNE                        0x0525U              
#define UART_IT_IDLE                        0x0424U              
#define UART_IT_LBD                         0x0846U              
#define UART_IT_CTS                         0x096AU              
#define UART_IT_CM                          0x112EU              
#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
#define UART_IT_WUF                         0x1476U              
#endif 
#endif 
#define UART_IT_RTO                         0x0B3AU              

#define UART_IT_ERR                         0x0060U              

#define UART_IT_ORE                         0x0300U              
#define UART_IT_NE                          0x0200U              
#define UART_IT_FE                          0x0100U              



#define UART_CLEAR_PEF                       USART_ICR_PECF            
#define UART_CLEAR_FEF                       USART_ICR_FECF            
#define UART_CLEAR_NEF                       USART_ICR_NCF             
#define UART_CLEAR_OREF                      USART_ICR_ORECF           
#define UART_CLEAR_IDLEF                     USART_ICR_IDLECF          
#define UART_CLEAR_TCF                       USART_ICR_TCCF            
#define UART_CLEAR_LBDF                      USART_ICR_LBDCF           
#define UART_CLEAR_CTSF                      USART_ICR_CTSCF           
#define UART_CLEAR_CMF                       USART_ICR_CMCF            
#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
#define UART_CLEAR_WUF                       USART_ICR_WUCF            
#endif 
#endif 
#define UART_CLEAR_RTOF                      USART_ICR_RTOCF           



#define HAL_UART_RECEPTION_STANDARD          (0x00000000U)             
#define HAL_UART_RECEPTION_TOIDLE            (0x00000001U)             
#define HAL_UART_RECEPTION_TORTO             (0x00000002U)             
#define HAL_UART_RECEPTION_TOCHARMATCH       (0x00000003U)             








#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                       (__HANDLE__)->MspInitCallback = NULL;             \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                     } while(0U)
#else
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                     } while(0U)
#endif 


#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__)  \
  do{                \
    SET_BIT((__HANDLE__)->Instance->RQR, UART_RXDATA_FLUSH_REQUEST); \
    SET_BIT((__HANDLE__)->Instance->RQR, UART_TXDATA_FLUSH_REQUEST); \
  }  while(0U)


#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))


#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_PEF)


#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_FEF)


#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__)  __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_NEF)


#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_OREF)


#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_UART_CLEAR_FLAG((__HANDLE__), UART_CLEAR_IDLEF)



#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))


#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (\
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U)?\
                                                           ((__HANDLE__)->Instance->CR1 |= (1U <<\
                                                               ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U)?\
                                                           ((__HANDLE__)->Instance->CR2 |= (1U <<\
                                                               ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 |= (1U <<\
                                                               ((__INTERRUPT__) & UART_IT_MASK))))


#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (\
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U)?\
                                                           ((__HANDLE__)->Instance->CR1 &= ~ (1U <<\
                                                               ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U)?\
                                                           ((__HANDLE__)->Instance->CR2 &= ~ (1U <<\
                                                               ((__INTERRUPT__) & UART_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ (1U <<\
                                                               ((__INTERRUPT__) & UART_IT_MASK))))


#define __HAL_UART_GET_IT(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->ISR\
                                                        & (1U << ((__INTERRUPT__)>> 8U))) != RESET) ? SET : RESET)


#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((((((uint8_t)(__INTERRUPT__)) >> 5U) == 1U) ?\
                                                                (__HANDLE__)->Instance->CR1 : \
                                                                (((((uint8_t)(__INTERRUPT__)) >> 5U) == 2U) ?\
                                                                 (__HANDLE__)->Instance->CR2 : \
                                                                 (__HANDLE__)->Instance->CR3)) & (1U <<\
                                                                     (((uint16_t)(__INTERRUPT__)) &\
                                                                      UART_IT_MASK)))  != RESET) ? SET : RESET)


#define __HAL_UART_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR = (uint32_t)(__IT_CLEAR__))


#define __HAL_UART_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint16_t)(__REQ__))


#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)


#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3 &= ~USART_CR3_ONEBIT)


#define __HAL_UART_ENABLE(__HANDLE__)                   ((__HANDLE__)->Instance->CR1 |= USART_CR1_UE)


#define __HAL_UART_DISABLE(__HANDLE__)                  ((__HANDLE__)->Instance->CR1 &= ~USART_CR1_UE)


#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \
  } while(0U)


#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \
  } while(0U)


#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \
  } while(0U)


#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \
  } while(0U)







#define UART_DIV_SAMPLING8(__PCLK__, __BAUD__)   ((((__PCLK__)*2U) + ((__BAUD__)/2U)) / (__BAUD__))


#define UART_DIV_SAMPLING16(__PCLK__, __BAUD__)  (((__PCLK__) + ((__BAUD__)/2U)) / (__BAUD__))



#define IS_UART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 27000001U)


#define IS_UART_ASSERTIONTIME(__TIME__)    ((__TIME__) <= 0x1FU)


#define IS_UART_DEASSERTIONTIME(__TIME__) ((__TIME__) <= 0x1FU)


#define IS_UART_STOPBITS(__STOPBITS__) (((__STOPBITS__) == UART_STOPBITS_0_5) || \
                                        ((__STOPBITS__) == UART_STOPBITS_1)   || \
                                        ((__STOPBITS__) == UART_STOPBITS_1_5) || \
                                        ((__STOPBITS__) == UART_STOPBITS_2))



#define IS_UART_PARITY(__PARITY__) (((__PARITY__) == UART_PARITY_NONE) || \
                                    ((__PARITY__) == UART_PARITY_EVEN) || \
                                    ((__PARITY__) == UART_PARITY_ODD))


#define IS_UART_HARDWARE_FLOW_CONTROL(__CONTROL__)\
  (((__CONTROL__) == UART_HWCONTROL_NONE) || \
   ((__CONTROL__) == UART_HWCONTROL_RTS)  || \
   ((__CONTROL__) == UART_HWCONTROL_CTS)  || \
   ((__CONTROL__) == UART_HWCONTROL_RTS_CTS))


#define IS_UART_MODE(__MODE__) ((((__MODE__) & (~((uint32_t)(UART_MODE_TX_RX)))) == 0x00U) && ((__MODE__) != 0x00U))


#define IS_UART_STATE(__STATE__) (((__STATE__) == UART_STATE_DISABLE) || \
                                  ((__STATE__) == UART_STATE_ENABLE))


#define IS_UART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == UART_OVERSAMPLING_16) || \
                                            ((__SAMPLING__) == UART_OVERSAMPLING_8))


#define IS_UART_ONE_BIT_SAMPLE(__ONEBIT__) (((__ONEBIT__) == UART_ONE_BIT_SAMPLE_DISABLE) || \
                                            ((__ONEBIT__) == UART_ONE_BIT_SAMPLE_ENABLE))


#define IS_UART_ADVFEATURE_AUTOBAUDRATEMODE(__MODE__)  (((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT)    || \
                                                        ((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE) || \
                                                        ((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME)   || \
                                                        ((__MODE__) == UART_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME))


#define IS_UART_RECEIVER_TIMEOUT(__TIMEOUT__)  (((__TIMEOUT__) == UART_RECEIVER_TIMEOUT_DISABLE) || \
                                                ((__TIMEOUT__) == UART_RECEIVER_TIMEOUT_ENABLE))


#define IS_UART_RECEIVER_TIMEOUT_VALUE(__TIMEOUTVALUE__)  ((__TIMEOUTVALUE__) <= 0xFFFFFFU)


#define IS_UART_LIN(__LIN__)        (((__LIN__) == UART_LIN_DISABLE) || \
                                     ((__LIN__) == UART_LIN_ENABLE))


#define IS_UART_LIN_BREAK_DETECT_LENGTH(__LENGTH__) (((__LENGTH__) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                     ((__LENGTH__) == UART_LINBREAKDETECTLENGTH_11B))


#define IS_UART_DMA_TX(__DMATX__)     (((__DMATX__) == UART_DMA_TX_DISABLE) || \
                                       ((__DMATX__) == UART_DMA_TX_ENABLE))


#define IS_UART_DMA_RX(__DMARX__)     (((__DMARX__) == UART_DMA_RX_DISABLE) || \
                                       ((__DMARX__) == UART_DMA_RX_ENABLE))


#define IS_UART_HALF_DUPLEX(__HDSEL__)     (((__HDSEL__) == UART_HALF_DUPLEX_DISABLE) || \
                                            ((__HDSEL__) == UART_HALF_DUPLEX_ENABLE))


#define IS_UART_WAKEUPMETHOD(__WAKEUP__) (((__WAKEUP__) == UART_WAKEUPMETHOD_IDLELINE) || \
                                          ((__WAKEUP__) == UART_WAKEUPMETHOD_ADDRESSMARK))


#define IS_UART_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == UART_AUTOBAUD_REQUEST)     || \
                                              ((__PARAM__) == UART_SENDBREAK_REQUEST)    || \
                                              ((__PARAM__) == UART_MUTE_MODE_REQUEST)    || \
                                              ((__PARAM__) == UART_RXDATA_FLUSH_REQUEST) || \
                                              ((__PARAM__) == UART_TXDATA_FLUSH_REQUEST))


#define IS_UART_ADVFEATURE_INIT(__INIT__)   ((__INIT__) <= (UART_ADVFEATURE_NO_INIT                | \
                                                            UART_ADVFEATURE_TXINVERT_INIT          | \
                                                            UART_ADVFEATURE_RXINVERT_INIT          | \
                                                            UART_ADVFEATURE_DATAINVERT_INIT        | \
                                                            UART_ADVFEATURE_SWAP_INIT              | \
                                                            UART_ADVFEATURE_RXOVERRUNDISABLE_INIT  | \
                                                            UART_ADVFEATURE_DMADISABLEONERROR_INIT | \
                                                            UART_ADVFEATURE_AUTOBAUDRATE_INIT      | \
                                                            UART_ADVFEATURE_MSBFIRST_INIT))


#define IS_UART_ADVFEATURE_TXINV(__TXINV__) (((__TXINV__) == UART_ADVFEATURE_TXINV_DISABLE) || \
                                             ((__TXINV__) == UART_ADVFEATURE_TXINV_ENABLE))


#define IS_UART_ADVFEATURE_RXINV(__RXINV__) (((__RXINV__) == UART_ADVFEATURE_RXINV_DISABLE) || \
                                             ((__RXINV__) == UART_ADVFEATURE_RXINV_ENABLE))


#define IS_UART_ADVFEATURE_DATAINV(__DATAINV__) (((__DATAINV__) == UART_ADVFEATURE_DATAINV_DISABLE) || \
                                                 ((__DATAINV__) == UART_ADVFEATURE_DATAINV_ENABLE))


#define IS_UART_ADVFEATURE_SWAP(__SWAP__) (((__SWAP__) == UART_ADVFEATURE_SWAP_DISABLE) || \
                                           ((__SWAP__) == UART_ADVFEATURE_SWAP_ENABLE))


#define IS_UART_OVERRUN(__OVERRUN__)     (((__OVERRUN__) == UART_ADVFEATURE_OVERRUN_ENABLE) || \
                                          ((__OVERRUN__) == UART_ADVFEATURE_OVERRUN_DISABLE))


#define IS_UART_ADVFEATURE_AUTOBAUDRATE(__AUTOBAUDRATE__) (((__AUTOBAUDRATE__) == \
                                                            UART_ADVFEATURE_AUTOBAUDRATE_DISABLE) || \
                                                           ((__AUTOBAUDRATE__) == UART_ADVFEATURE_AUTOBAUDRATE_ENABLE))


#define IS_UART_ADVFEATURE_DMAONRXERROR(__DMA__)  (((__DMA__) == UART_ADVFEATURE_DMA_ENABLEONRXERROR) || \
                                                   ((__DMA__) == UART_ADVFEATURE_DMA_DISABLEONRXERROR))


#define IS_UART_ADVFEATURE_MSBFIRST(__MSBFIRST__) (((__MSBFIRST__) == UART_ADVFEATURE_MSBFIRST_DISABLE) || \
                                                   ((__MSBFIRST__) == UART_ADVFEATURE_MSBFIRST_ENABLE))

#if defined(USART_CR1_UESM)

#define IS_UART_ADVFEATURE_STOPMODE(__STOPMODE__) (((__STOPMODE__) == UART_ADVFEATURE_STOPMODE_DISABLE) || \
                                                   ((__STOPMODE__) == UART_ADVFEATURE_STOPMODE_ENABLE))

#endif 

#define IS_UART_MUTE_MODE(__MUTE__)       (((__MUTE__) == UART_ADVFEATURE_MUTEMODE_DISABLE) || \
                                           ((__MUTE__) == UART_ADVFEATURE_MUTEMODE_ENABLE))
#if defined(USART_CR1_UESM)


#if defined(USART_CR3_WUFIE)
#define IS_UART_WAKEUP_SELECTION(__WAKE__) (((__WAKE__) == UART_WAKEUP_ON_ADDRESS)           || \
                                            ((__WAKE__) == UART_WAKEUP_ON_STARTBIT)          || \
                                            ((__WAKE__) == UART_WAKEUP_ON_READDATA_NONEMPTY))
#else
#define IS_UART_WAKEUP_SELECTION(__WAKE__) (((__WAKE__) == UART_WAKEUP_ON_ADDRESS)           || \
                                            ((__WAKE__) == UART_WAKEUP_ON_READDATA_NONEMPTY))
#endif 
#endif 


#define IS_UART_DE_POLARITY(__POLARITY__)    (((__POLARITY__) == UART_DE_POLARITY_HIGH) || \
                                              ((__POLARITY__) == UART_DE_POLARITY_LOW))





#include "stm32f7xx_hal_uart_ex.h"







HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);


#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart);
#endif 






HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);






void HAL_UART_ReceiverTimeout_Config(UART_HandleTypeDef *huart, uint32_t TimeoutValue);
HAL_StatusTypeDef HAL_UART_EnableReceiverTimeout(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DisableReceiverTimeout(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_EnableMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_DisableMuteMode(UART_HandleTypeDef *huart);
void HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);






HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(UART_HandleTypeDef *huart);







#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
void              UART_InitCallbacksToDefault(UART_HandleTypeDef *huart);
#endif 
HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout);
void              UART_AdvFeatureConfig(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);







#ifdef __cplusplus
}
#endif

#endif 


