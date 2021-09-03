
#include "stm32f7xx_hal.h"

#ifdef HAL_UART_MODULE_ENABLED

#define USART_CR1_FIELDS  ((uint32_t)(USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | USART_CR1_RE | \
                                      USART_CR1_OVER8)) 

#define USART_CR3_FIELDS  ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE |\
                            USART_CR3_ONEBIT)) 

#define UART_BRR_MIN    0x10U        
#define UART_BRR_MAX    0x0000FFFFU  

static void UART_EndTxTransfer(UART_HandleTypeDef *huart);
static void UART_EndRxTransfer(UART_HandleTypeDef *huart);
static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void UART_DMARxHalfCplt(DMA_HandleTypeDef *hdma);
static void UART_DMATxHalfCplt(DMA_HandleTypeDef *hdma);
static void UART_DMAError(DMA_HandleTypeDef *hdma);
static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_TxISR_8BIT(UART_HandleTypeDef *huart);
static void UART_TxISR_16BIT(UART_HandleTypeDef *huart);
static void UART_EndTransmit_IT(UART_HandleTypeDef *huart);
static void UART_RxISR_8BIT(UART_HandleTypeDef *huart);
static void UART_RxISR_16BIT(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart) {

	if (huart == NULL) {
		return HAL_ERROR;
	}

	if (huart->Init.HwFlowCtl != UART_HWCONTROL_NONE) {

		assert_param(IS_UART_HWFLOW_INSTANCE(huart->Instance));
	} else {

		assert_param(IS_UART_INSTANCE(huart->Instance));
	}

	if (huart->gState == HAL_UART_STATE_RESET) {

		huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

    
    huart->MspInitCallback(huart);
#else

		HAL_UART_MspInit(huart);
#endif 
	}

	huart->gState = HAL_UART_STATE_BUSY;

	__HAL_UART_DISABLE(huart);

	if (UART_SetConfig(huart) == HAL_ERROR) {
		return HAL_ERROR;
	}

	if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT) {
		UART_AdvFeatureConfig(huart);
	}

	CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
	CLEAR_BIT(huart->Instance->CR3,
			(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

	__HAL_UART_ENABLE(huart);

	return (UART_CheckIdleState(huart));
}

HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart) {

	if (huart == NULL) {
		return HAL_ERROR;
	}

	assert_param(IS_UART_HALFDUPLEX_INSTANCE(huart->Instance));

	if (huart->gState == HAL_UART_STATE_RESET) {

		huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

    
    huart->MspInitCallback(huart);
#else

		HAL_UART_MspInit(huart);
#endif 
	}

	huart->gState = HAL_UART_STATE_BUSY;

	__HAL_UART_DISABLE(huart);

	if (UART_SetConfig(huart) == HAL_ERROR) {
		return HAL_ERROR;
	}

	if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT) {
		UART_AdvFeatureConfig(huart);
	}

	CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
	CLEAR_BIT(huart->Instance->CR3, (USART_CR3_IREN | USART_CR3_SCEN));

	SET_BIT(huart->Instance->CR3, USART_CR3_HDSEL);

	__HAL_UART_ENABLE(huart);

	return (UART_CheckIdleState(huart));
}

HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart,
		uint32_t BreakDetectLength) {

	if (huart == NULL) {
		return HAL_ERROR;
	}

	assert_param(IS_UART_LIN_INSTANCE(huart->Instance));

	assert_param(IS_UART_LIN_BREAK_DETECT_LENGTH(BreakDetectLength));

	if (huart->Init.OverSampling == UART_OVERSAMPLING_8) {
		return HAL_ERROR;
	}

	if (huart->Init.WordLength != UART_WORDLENGTH_8B) {
		return HAL_ERROR;
	}

	if (huart->gState == HAL_UART_STATE_RESET) {

		huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

    
    huart->MspInitCallback(huart);
#else

		HAL_UART_MspInit(huart);
#endif 
	}

	huart->gState = HAL_UART_STATE_BUSY;

	__HAL_UART_DISABLE(huart);

	if (UART_SetConfig(huart) == HAL_ERROR) {
		return HAL_ERROR;
	}

	if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT) {
		UART_AdvFeatureConfig(huart);
	}

	CLEAR_BIT(huart->Instance->CR2, USART_CR2_CLKEN);
	CLEAR_BIT(huart->Instance->CR3,
			(USART_CR3_HDSEL | USART_CR3_IREN | USART_CR3_SCEN));

	SET_BIT(huart->Instance->CR2, USART_CR2_LINEN);

	MODIFY_REG(huart->Instance->CR2, USART_CR2_LBDL, BreakDetectLength);

	__HAL_UART_ENABLE(huart);

	return (UART_CheckIdleState(huart));
}

HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart,
		uint8_t Address, uint32_t WakeUpMethod) {

	if (huart == NULL) {
		return HAL_ERROR;
	}

	assert_param(IS_UART_WAKEUPMETHOD(WakeUpMethod));

	if (huart->gState == HAL_UART_STATE_RESET) {

		huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

    
    huart->MspInitCallback(huart);
#else

		HAL_UART_MspInit(huart);
#endif 
	}

	huart->gState = HAL_UART_STATE_BUSY;

	__HAL_UART_DISABLE(huart);

	if (UART_SetConfig(huart) == HAL_ERROR) {
		return HAL_ERROR;
	}

	if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT) {
		UART_AdvFeatureConfig(huart);
	}

	CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
	CLEAR_BIT(huart->Instance->CR3,
			(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

	if (WakeUpMethod == UART_WAKEUPMETHOD_ADDRESSMARK) {

		MODIFY_REG(huart->Instance->CR2, USART_CR2_ADD,
				((uint32_t)Address << UART_CR2_ADDRESS_LSB_POS));
	}

	MODIFY_REG(huart->Instance->CR1, USART_CR1_WAKE, WakeUpMethod);

	__HAL_UART_ENABLE(huart);

	return (UART_CheckIdleState(huart));
}

HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart) {

	if (huart == NULL) {
		return HAL_ERROR;
	}

	assert_param(IS_UART_INSTANCE(huart->Instance));

	huart->gState = HAL_UART_STATE_BUSY;

	__HAL_UART_DISABLE(huart);

	huart->Instance->CR1 = 0x0U;
	huart->Instance->CR2 = 0x0U;
	huart->Instance->CR3 = 0x0U;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  if (huart->MspDeInitCallback == NULL)
  {
    huart->MspDeInitCallback = HAL_UART_MspDeInit;
  }
  
  huart->MspDeInitCallback(huart);
#else

	HAL_UART_MspDeInit(huart);
#endif 

	huart->ErrorCode = HAL_UART_ERROR_NONE;
	huart->gState = HAL_UART_STATE_RESET;
	huart->RxState = HAL_UART_STATE_RESET;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

__weak void HAL_UART_MspInit(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)

HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_UART_TX_HALFCOMPLETE_CB_ID :
        huart->TxHalfCpltCallback = pCallback;
        break;

      case HAL_UART_TX_COMPLETE_CB_ID :
        huart->TxCpltCallback = pCallback;
        break;

      case HAL_UART_RX_HALFCOMPLETE_CB_ID :
        huart->RxHalfCpltCallback = pCallback;
        break;

      case HAL_UART_RX_COMPLETE_CB_ID :
        huart->RxCpltCallback = pCallback;
        break;

      case HAL_UART_ERROR_CB_ID :
        huart->ErrorCallback = pCallback;
        break;

      case HAL_UART_ABORT_COMPLETE_CB_ID :
        huart->AbortCpltCallback = pCallback;
        break;

      case HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID :
        huart->AbortTransmitCpltCallback = pCallback;
        break;

      case HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID :
        huart->AbortReceiveCpltCallback = pCallback;
        break;

#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
      case HAL_UART_WAKEUP_CB_ID :
        huart->WakeupCallback = pCallback;
        break;

#endif 
#endif 

      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = pCallback;
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = pCallback;
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else if (huart->gState == HAL_UART_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = pCallback;
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = pCallback;
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  __HAL_UNLOCK(huart);

  return status;
}


HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  __HAL_LOCK(huart);

  if (HAL_UART_STATE_READY == huart->gState)
  {
    switch (CallbackID)
    {
      case HAL_UART_TX_HALFCOMPLETE_CB_ID :
        huart->TxHalfCpltCallback = HAL_UART_TxHalfCpltCallback;               
        break;

      case HAL_UART_TX_COMPLETE_CB_ID :
        huart->TxCpltCallback = HAL_UART_TxCpltCallback;                       
        break;

      case HAL_UART_RX_HALFCOMPLETE_CB_ID :
        huart->RxHalfCpltCallback = HAL_UART_RxHalfCpltCallback;               
        break;

      case HAL_UART_RX_COMPLETE_CB_ID :
        huart->RxCpltCallback = HAL_UART_RxCpltCallback;                       
        break;

      case HAL_UART_ERROR_CB_ID :
        huart->ErrorCallback = HAL_UART_ErrorCallback;                         
        break;

      case HAL_UART_ABORT_COMPLETE_CB_ID :
        huart->AbortCpltCallback = HAL_UART_AbortCpltCallback;                 
        break;

      case HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID :
        huart->AbortTransmitCpltCallback = HAL_UART_AbortTransmitCpltCallback; 
        break;

      case HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID :
        huart->AbortReceiveCpltCallback = HAL_UART_AbortReceiveCpltCallback;   
        break;

#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
      case HAL_UART_WAKEUP_CB_ID :
        huart->WakeupCallback = HAL_UARTEx_WakeupCallback;                     
        break;

#endif 
#endif 
      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = HAL_UART_MspInit;                             
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = HAL_UART_MspDeInit;                         
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_UART_STATE_RESET == huart->gState)
  {
    switch (CallbackID)
    {
      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = HAL_UART_MspInit;
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = HAL_UART_MspDeInit;
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  __HAL_UNLOCK(huart);

  return status;
}


HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  
  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    huart->RxEventCallback = pCallback;
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  
  __HAL_UNLOCK(huart);

  return status;
}


HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart)
{
  HAL_StatusTypeDef status = HAL_OK;

  
  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    huart->RxEventCallback = HAL_UARTEx_RxEventCallback; 
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  
  __HAL_UNLOCK(huart);
  return status;
}

#endif 

HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData,
		uint16_t Size, uint32_t Timeout) {
	uint8_t *pdata8bits;
	uint16_t *pdata16bits;
	uint32_t tickstart;

	if (huart->gState == HAL_UART_STATE_READY) {
		if ((pData == NULL) || (Size == 0U)) {
			return HAL_ERROR;
		}

		__HAL_LOCK(huart);

		huart->ErrorCode = HAL_UART_ERROR_NONE;
		huart->gState = HAL_UART_STATE_BUSY_TX;

		tickstart = HAL_GetTick();

		huart->TxXferSize = Size;
		huart->TxXferCount = Size;

		if ((huart->Init.WordLength == UART_WORDLENGTH_9B)
				&& (huart->Init.Parity == UART_PARITY_NONE)) {
			pdata8bits = NULL;
			pdata16bits = (uint16_t*) pData;
		} else {
			pdata8bits = pData;
			pdata16bits = NULL;
		}

		__HAL_UNLOCK(huart);

		while (huart->TxXferCount > 0U) {
			if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TXE, RESET,
					tickstart, Timeout) != HAL_OK) {
				return HAL_TIMEOUT;
			}
			if (pdata8bits == NULL) {
				huart->Instance->TDR = (uint16_t) (*pdata16bits & 0x01FFU);
				pdata16bits++;
			} else {
				huart->Instance->TDR = (uint8_t) (*pdata8bits & 0xFFU);
				pdata8bits++;
			}
			huart->TxXferCount--;
		}

		if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_TC, RESET, tickstart,
				Timeout) != HAL_OK) {
			return HAL_TIMEOUT;
		}

		huart->gState = HAL_UART_STATE_READY;

		return HAL_OK;
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData,
		uint16_t Size, uint32_t Timeout) {
	uint8_t *pdata8bits;
	uint16_t *pdata16bits;
	uint16_t uhMask;
	uint32_t tickstart;

	if (huart->RxState == HAL_UART_STATE_READY) {
		if ((pData == NULL) || (Size == 0U)) {
			return HAL_ERROR;
		}

		__HAL_LOCK(huart);

		huart->ErrorCode = HAL_UART_ERROR_NONE;
		huart->RxState = HAL_UART_STATE_BUSY_RX;
		huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

		tickstart = HAL_GetTick();

		huart->RxXferSize = Size;
		huart->RxXferCount = Size;

		UART_MASK_COMPUTATION(huart);
		uhMask = huart->Mask;

		if ((huart->Init.WordLength == UART_WORDLENGTH_9B)
				&& (huart->Init.Parity == UART_PARITY_NONE)) {
			pdata8bits = NULL;
			pdata16bits = (uint16_t*) pData;
		} else {
			pdata8bits = pData;
			pdata16bits = NULL;
		}

		__HAL_UNLOCK(huart);

		while (huart->RxXferCount > 0U) {
			if (UART_WaitOnFlagUntilTimeout(huart, UART_FLAG_RXNE, RESET,
					tickstart, Timeout) != HAL_OK) {
				return HAL_TIMEOUT;
			}
			if (pdata8bits == NULL) {
				*pdata16bits = (uint16_t) (huart->Instance->RDR & uhMask);
				pdata16bits++;
			} else {
				*pdata8bits =
						(uint8_t) (huart->Instance->RDR & (uint8_t) uhMask);
				pdata8bits++;
			}
			huart->RxXferCount--;
		}

		huart->RxState = HAL_UART_STATE_READY;

		return HAL_OK;
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart,
		uint8_t *pData, uint16_t Size) {

	if (huart->gState == HAL_UART_STATE_READY) {
		if ((pData == NULL) || (Size == 0U)) {
			return HAL_ERROR;
		}

		__HAL_LOCK(huart);

		huart->pTxBuffPtr = pData;
		huart->TxXferSize = Size;
		huart->TxXferCount = Size;
		huart->TxISR = NULL;

		huart->ErrorCode = HAL_UART_ERROR_NONE;
		huart->gState = HAL_UART_STATE_BUSY_TX;

		if ((huart->Init.WordLength == UART_WORDLENGTH_9B)
				&& (huart->Init.Parity == UART_PARITY_NONE)) {
			huart->TxISR = UART_TxISR_16BIT;
		} else {
			huart->TxISR = UART_TxISR_8BIT;
		}

		__HAL_UNLOCK(huart);

		SET_BIT(huart->Instance->CR1, USART_CR1_TXEIE);

		return HAL_OK;
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData,
		uint16_t Size) {

	if (huart->RxState == HAL_UART_STATE_READY) {
		if ((pData == NULL) || (Size == 0U)) {
			return HAL_ERROR;
		}

		__HAL_LOCK(huart);

		huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

		if (READ_BIT(huart->Instance->CR2, USART_CR2_RTOEN) != 0U) {

			SET_BIT(huart->Instance->CR1, USART_CR1_RTOIE);
		}

		return (UART_Start_Receive_IT(huart, pData, Size));
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart,
		uint8_t *pData, uint16_t Size) {

	if (huart->gState == HAL_UART_STATE_READY) {
		if ((pData == NULL) || (Size == 0U)) {
			return HAL_ERROR;
		}

		__HAL_LOCK(huart);

		huart->pTxBuffPtr = pData;
		huart->TxXferSize = Size;
		huart->TxXferCount = Size;

		huart->ErrorCode = HAL_UART_ERROR_NONE;
		huart->gState = HAL_UART_STATE_BUSY_TX;

		if (huart->hdmatx != NULL) {

			huart->hdmatx->XferCpltCallback = UART_DMATransmitCplt;

			huart->hdmatx->XferHalfCpltCallback = UART_DMATxHalfCplt;

			huart->hdmatx->XferErrorCallback = UART_DMAError;

			huart->hdmatx->XferAbortCallback = NULL;

			if (HAL_DMA_Start_IT(huart->hdmatx, (uint32_t) huart->pTxBuffPtr,
					(uint32_t) &huart->Instance->TDR, Size) != HAL_OK) {

				huart->ErrorCode = HAL_UART_ERROR_DMA;

				__HAL_UNLOCK(huart);

				huart->gState = HAL_UART_STATE_READY;

				return HAL_ERROR;
			}
		}

		__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_TCF);

		__HAL_UNLOCK(huart);

		SET_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		return HAL_OK;
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart,
		uint8_t *pData, uint16_t Size) {

	if (huart->RxState == HAL_UART_STATE_READY) {
		if ((pData == NULL) || (Size == 0U)) {
			return HAL_ERROR;
		}

		__HAL_LOCK(huart);

		huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

		if (READ_BIT(huart->Instance->CR2, USART_CR2_RTOEN) != 0U) {

			SET_BIT(huart->Instance->CR1, USART_CR1_RTOIE);
		}

		return (UART_Start_Receive_DMA(huart, pData, Size));
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart) {
	const HAL_UART_StateTypeDef gstate = huart->gState;
	const HAL_UART_StateTypeDef rxstate = huart->RxState;

	__HAL_LOCK(huart);

	if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
			&& (gstate == HAL_UART_STATE_BUSY_TX)) {

		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);
	}
	if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
			&& (rxstate == HAL_UART_STATE_BUSY_RX)) {

		CLEAR_BIT(huart->Instance->CR1, USART_CR1_PEIE);
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);
	}

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart) {
	__HAL_LOCK(huart);

	if (huart->gState == HAL_UART_STATE_BUSY_TX) {

		SET_BIT(huart->Instance->CR3, USART_CR3_DMAT);
	}
	if (huart->RxState == HAL_UART_STATE_BUSY_RX) {

		__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF);

		SET_BIT(huart->Instance->CR1, USART_CR1_PEIE);
		SET_BIT(huart->Instance->CR3, USART_CR3_EIE);

		SET_BIT(huart->Instance->CR3, USART_CR3_DMAR);
	}

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart) {

	const HAL_UART_StateTypeDef gstate = huart->gState;
	const HAL_UART_StateTypeDef rxstate = huart->RxState;

	if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
			&& (gstate == HAL_UART_STATE_BUSY_TX)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		if (huart->hdmatx != NULL) {
			if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK) {
				if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT) {

					huart->ErrorCode = HAL_UART_ERROR_DMA;

					return HAL_TIMEOUT;
				}
			}
		}

		UART_EndTxTransfer(huart);
	}

	if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
			&& (rxstate == HAL_UART_STATE_BUSY_RX)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		if (huart->hdmarx != NULL) {
			if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK) {
				if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT) {

					huart->ErrorCode = HAL_UART_ERROR_DMA;

					return HAL_TIMEOUT;
				}
			}
		}

		UART_EndRxTransfer(huart);
	}

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1,
			(USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE | USART_CR1_TCIE));
	CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
		CLEAR_BIT(huart->Instance->CR1, (USART_CR1_IDLEIE));
	}

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		if (huart->hdmatx != NULL) {

			huart->hdmatx->XferAbortCallback = NULL;

			if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK) {
				if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT) {

					huart->ErrorCode = HAL_UART_ERROR_DMA;

					return HAL_TIMEOUT;
				}
			}
		}
	}

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		if (huart->hdmarx != NULL) {

			huart->hdmarx->XferAbortCallback = NULL;

			if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK) {
				if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT) {

					huart->ErrorCode = HAL_UART_ERROR_DMA;

					return HAL_TIMEOUT;
				}
			}
		}
	}

	huart->TxXferCount = 0U;
	huart->RxXferCount = 0U;

	__HAL_UART_CLEAR_FLAG(huart,
			UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

	__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

	huart->gState = HAL_UART_STATE_READY;
	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

	huart->ErrorCode = HAL_UART_ERROR_NONE;

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		if (huart->hdmatx != NULL) {

			huart->hdmatx->XferAbortCallback = NULL;

			if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK) {
				if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT) {

					huart->ErrorCode = HAL_UART_ERROR_DMA;

					return HAL_TIMEOUT;
				}
			}
		}
	}

	huart->TxXferCount = 0U;

	huart->gState = HAL_UART_STATE_READY;

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
	CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
		CLEAR_BIT(huart->Instance->CR1, (USART_CR1_IDLEIE));
	}

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		if (huart->hdmarx != NULL) {

			huart->hdmarx->XferAbortCallback = NULL;

			if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK) {
				if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT) {

					huart->ErrorCode = HAL_UART_ERROR_DMA;

					return HAL_TIMEOUT;
				}
			}
		}
	}

	huart->RxXferCount = 0U;

	__HAL_UART_CLEAR_FLAG(huart,
			UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

	__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart) {
	uint32_t abortcplt = 1U;

	CLEAR_BIT(huart->Instance->CR1,
			(USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE | USART_CR1_TCIE));
	CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
		CLEAR_BIT(huart->Instance->CR1, (USART_CR1_IDLEIE));
	}

	if (huart->hdmatx != NULL) {

		if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) {
			huart->hdmatx->XferAbortCallback = UART_DMATxAbortCallback;
		} else {
			huart->hdmatx->XferAbortCallback = NULL;
		}
	}

	if (huart->hdmarx != NULL) {

		if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {
			huart->hdmarx->XferAbortCallback = UART_DMARxAbortCallback;
		} else {
			huart->hdmarx->XferAbortCallback = NULL;
		}
	}

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) {

		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		if (huart->hdmatx != NULL) {

			if (HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK) {
				huart->hdmatx->XferAbortCallback = NULL;
			} else {
				abortcplt = 0U;
			}
		}
	}

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		if (huart->hdmarx != NULL) {

			if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK) {
				huart->hdmarx->XferAbortCallback = NULL;
				abortcplt = 1U;
			} else {
				abortcplt = 0U;
			}
		}
	}

	if (abortcplt == 1U) {

		huart->TxXferCount = 0U;
		huart->RxXferCount = 0U;

		huart->RxISR = NULL;
		huart->TxISR = NULL;

		huart->ErrorCode = HAL_UART_ERROR_NONE;

		__HAL_UART_CLEAR_FLAG(huart,
				UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

		__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

		huart->gState = HAL_UART_STATE_READY;
		huart->RxState = HAL_UART_STATE_READY;
		huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->AbortCpltCallback(huart);
#else

		HAL_UART_AbortCpltCallback(huart);
#endif 
	}

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		if (huart->hdmatx != NULL) {

			huart->hdmatx->XferAbortCallback = UART_DMATxOnlyAbortCallback;

			if (HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK) {

				huart->hdmatx->XferAbortCallback(huart->hdmatx);
			}
		} else {

			huart->TxXferCount = 0U;

			huart->TxISR = NULL;

			huart->gState = HAL_UART_STATE_READY;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
      
      huart->AbortTransmitCpltCallback(huart);
#else

			HAL_UART_AbortTransmitCpltCallback(huart);
#endif 
		}
	} else {

		huart->TxXferCount = 0U;

		huart->TxISR = NULL;

		huart->gState = HAL_UART_STATE_READY;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->AbortTransmitCpltCallback(huart);
#else

		HAL_UART_AbortTransmitCpltCallback(huart);
#endif 
	}

	return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
	CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
		CLEAR_BIT(huart->Instance->CR1, (USART_CR1_IDLEIE));
	}

	if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		if (huart->hdmarx != NULL) {

			huart->hdmarx->XferAbortCallback = UART_DMARxOnlyAbortCallback;

			if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK) {

				huart->hdmarx->XferAbortCallback(huart->hdmarx);
			}
		} else {

			huart->RxXferCount = 0U;

			huart->pRxBuffPtr = NULL;

			__HAL_UART_CLEAR_FLAG(huart,
					UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

			__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

			huart->RxState = HAL_UART_STATE_READY;
			huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
      
      huart->AbortReceiveCpltCallback(huart);
#else

			HAL_UART_AbortReceiveCpltCallback(huart);
#endif 
		}
	} else {

		huart->RxXferCount = 0U;

		huart->pRxBuffPtr = NULL;

		__HAL_UART_CLEAR_FLAG(huart,
				UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

		huart->RxState = HAL_UART_STATE_READY;
		huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->AbortReceiveCpltCallback(huart);
#else

		HAL_UART_AbortReceiveCpltCallback(huart);
#endif 
	}

	return HAL_OK;
}

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart) {
	uint32_t isrflags = READ_REG(huart->Instance->ISR);
	uint32_t cr1its = READ_REG(huart->Instance->CR1);
	uint32_t cr3its = READ_REG(huart->Instance->CR3);

	uint32_t errorflags;
	uint32_t errorcode;

	errorflags = (isrflags
			& (uint32_t) (USART_ISR_PE | USART_ISR_FE | USART_ISR_ORE
					| USART_ISR_NE | USART_ISR_RTOF));
	if (errorflags == 0U) {

		if (((isrflags & USART_ISR_RXNE) != 0U)
				&& ((cr1its & USART_CR1_RXNEIE) != 0U)) {
			if (huart->RxISR != NULL) {
				huart->RxISR(huart);
			}
			return;
		}
	}

	if ((errorflags != 0U)
			&& (((cr3its & USART_CR3_EIE) != 0U)
					|| ((cr1its
							& (USART_CR1_RXNEIE | USART_CR1_PEIE
									| USART_CR1_RTOIE)) != 0U))) {

		if (((isrflags & USART_ISR_PE) != 0U)
				&& ((cr1its & USART_CR1_PEIE) != 0U)) {
			__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_PEF);

			huart->ErrorCode |= HAL_UART_ERROR_PE;
		}

		if (((isrflags & USART_ISR_FE) != 0U)
				&& ((cr3its & USART_CR3_EIE) != 0U)) {
			__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_FEF);

			huart->ErrorCode |= HAL_UART_ERROR_FE;
		}

		if (((isrflags & USART_ISR_NE) != 0U)
				&& ((cr3its & USART_CR3_EIE) != 0U)) {
			__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_NEF);

			huart->ErrorCode |= HAL_UART_ERROR_NE;
		}

		if (((isrflags & USART_ISR_ORE) != 0U)
				&& (((cr1its & USART_CR1_RXNEIE) != 0U)
						|| ((cr3its & USART_CR3_EIE) != 0U))) {
			__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF);

			huart->ErrorCode |= HAL_UART_ERROR_ORE;
		}

		if (((isrflags & USART_ISR_RTOF) != 0U)
				&& ((cr1its & USART_CR1_RTOIE) != 0U)) {
			__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_RTOF);

			huart->ErrorCode |= HAL_UART_ERROR_RTO;
		}

		if (huart->ErrorCode != HAL_UART_ERROR_NONE) {

			if (((isrflags & USART_ISR_RXNE) != 0U)
					&& ((cr1its & USART_CR1_RXNEIE) != 0U)) {
				if (huart->RxISR != NULL) {
					huart->RxISR(huart);
				}
			}

			errorcode = huart->ErrorCode;
			if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
					|| ((errorcode & (HAL_UART_ERROR_RTO | HAL_UART_ERROR_ORE))
							!= 0U)) {

				UART_EndRxTransfer(huart);

				if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {
					CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

					if (huart->hdmarx != NULL) {

						huart->hdmarx->XferAbortCallback = UART_DMAAbortOnError;

						if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK) {

							huart->hdmarx->XferAbortCallback(huart->hdmarx);
						}
					} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
            
            huart->ErrorCallback(huart);
#else

						HAL_UART_ErrorCallback(huart);
#endif 

					}
				} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
          
          huart->ErrorCallback(huart);
#else

					HAL_UART_ErrorCallback(huart);
#endif 
				}
			} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->ErrorCallback(huart);
#else

				HAL_UART_ErrorCallback(huart);
#endif 
				huart->ErrorCode = HAL_UART_ERROR_NONE;
			}
		}
		return;

	}

	if ((huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
			&& ((isrflags & USART_ISR_IDLE) != 0U)
			&& ((cr1its & USART_ISR_IDLE) != 0U)) {
		__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);

		if (HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) {

			uint16_t nb_remaining_rx_data = (uint16_t) __HAL_DMA_GET_COUNTER(
					huart->hdmarx);
			if ((nb_remaining_rx_data > 0U)
					&& (nb_remaining_rx_data < huart->RxXferSize)) {

				huart->RxXferCount = nb_remaining_rx_data;

				if (huart->hdmarx->Init.Mode != DMA_CIRCULAR) {

					CLEAR_BIT(huart->Instance->CR1, USART_CR1_PEIE);
					CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

					CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

					huart->RxState = HAL_UART_STATE_READY;
					huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

					CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);

					(void) HAL_DMA_Abort(huart->hdmarx);
				}
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->RxEventCallback(huart, (huart->RxXferSize - huart->RxXferCount));
#else

				HAL_UARTEx_RxEventCallback(huart,
						(huart->RxXferSize - huart->RxXferCount));
#endif 
			}
			return;
		} else {

			uint16_t nb_rx_data = huart->RxXferSize - huart->RxXferCount;
			if ((huart->RxXferCount > 0U) && (nb_rx_data > 0U)) {

				CLEAR_BIT(huart->Instance->CR1,
						(USART_CR1_RXNEIE | USART_CR1_PEIE));

				CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

				huart->RxState = HAL_UART_STATE_READY;
				huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

				huart->RxISR = NULL;

				CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->RxEventCallback(huart, nb_rx_data);
#else

				HAL_UARTEx_RxEventCallback(huart, nb_rx_data);
#endif 
			}
			return;
		}
	}
#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)

  
  if (((isrflags & USART_ISR_WUF) != 0U) && ((cr3its & USART_CR3_WUFIE) != 0U))
  {
    __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_WUF);

    

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->WakeupCallback(huart);
#else
    
    HAL_UARTEx_WakeupCallback(huart);
#endif 
    return;
  }
#endif 
#endif 

	if (((isrflags & USART_ISR_TXE) != 0U)
			&& ((cr1its & USART_CR1_TXEIE) != 0U)) {
		if (huart->TxISR != NULL) {
			huart->TxISR(huart);
		}
		return;
	}

	if (((isrflags & USART_ISR_TC) != 0U)
			&& ((cr1its & USART_CR1_TCIE) != 0U)) {
		UART_EndTransmit_IT(huart);
		return;
	}

}

__weak void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart) {

	UNUSED(huart);

}

__weak void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {

	UNUSED(huart);
	UNUSED(Size);

}

#if defined(USART_CR1_UESM)

__weak void HAL_UARTEx_WakeupCallback(UART_HandleTypeDef *huart)
{
  
  UNUSED(huart);

  
}

#endif 

void HAL_UART_ReceiverTimeout_Config(UART_HandleTypeDef *huart,
		uint32_t TimeoutValue) {
	assert_param(IS_UART_RECEIVER_TIMEOUT_VALUE(TimeoutValue));
	MODIFY_REG(huart->Instance->RTOR, USART_RTOR_RTO, TimeoutValue);
}

HAL_StatusTypeDef HAL_UART_EnableReceiverTimeout(UART_HandleTypeDef *huart) {
	if (huart->gState == HAL_UART_STATE_READY) {

		__HAL_LOCK(huart);

		huart->gState = HAL_UART_STATE_BUSY;

		SET_BIT(huart->Instance->CR2, USART_CR2_RTOEN);

		huart->gState = HAL_UART_STATE_READY;

		__HAL_UNLOCK(huart);

		return HAL_OK;
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_UART_DisableReceiverTimeout(UART_HandleTypeDef *huart) {
	if (huart->gState == HAL_UART_STATE_READY) {

		__HAL_LOCK(huart);

		huart->gState = HAL_UART_STATE_BUSY;

		CLEAR_BIT(huart->Instance->CR2, USART_CR2_RTOEN);

		huart->gState = HAL_UART_STATE_READY;

		__HAL_UNLOCK(huart);

		return HAL_OK;
	} else {
		return HAL_BUSY;
	}
}

HAL_StatusTypeDef HAL_MultiProcessor_EnableMuteMode(UART_HandleTypeDef *huart) {
	__HAL_LOCK(huart);

	huart->gState = HAL_UART_STATE_BUSY;

	SET_BIT(huart->Instance->CR1, USART_CR1_MME);

	huart->gState = HAL_UART_STATE_READY;

	return (UART_CheckIdleState(huart));
}

HAL_StatusTypeDef HAL_MultiProcessor_DisableMuteMode(UART_HandleTypeDef *huart) {
	__HAL_LOCK(huart);

	huart->gState = HAL_UART_STATE_BUSY;

	CLEAR_BIT(huart->Instance->CR1, USART_CR1_MME);

	huart->gState = HAL_UART_STATE_READY;

	return (UART_CheckIdleState(huart));
}

void HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart) {
	__HAL_UART_SEND_REQ(huart, UART_MUTE_MODE_REQUEST);
}

HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart) {
	__HAL_LOCK(huart);
	huart->gState = HAL_UART_STATE_BUSY;

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

	SET_BIT(huart->Instance->CR1, USART_CR1_TE);

	huart->gState = HAL_UART_STATE_READY;

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart) {
	__HAL_LOCK(huart);
	huart->gState = HAL_UART_STATE_BUSY;

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

	SET_BIT(huart->Instance->CR1, USART_CR1_RE);

	huart->gState = HAL_UART_STATE_READY;

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart) {

	assert_param(IS_UART_LIN_INSTANCE(huart->Instance));

	__HAL_LOCK(huart);

	huart->gState = HAL_UART_STATE_BUSY;

	__HAL_UART_SEND_REQ(huart, UART_SENDBREAK_REQUEST);

	huart->gState = HAL_UART_STATE_READY;

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart) {
	uint32_t temp1;
	uint32_t temp2;
	temp1 = huart->gState;
	temp2 = huart->RxState;

	return (HAL_UART_StateTypeDef) (temp1 | temp2);
}

uint32_t HAL_UART_GetError(UART_HandleTypeDef *huart) {
	return huart->ErrorCode;
}

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
void UART_InitCallbacksToDefault(UART_HandleTypeDef *huart)
{
  
  huart->TxHalfCpltCallback        = HAL_UART_TxHalfCpltCallback;        
  huart->TxCpltCallback            = HAL_UART_TxCpltCallback;            
  huart->RxHalfCpltCallback        = HAL_UART_RxHalfCpltCallback;        
  huart->RxCpltCallback            = HAL_UART_RxCpltCallback;            
  huart->ErrorCallback             = HAL_UART_ErrorCallback;             
  huart->AbortCpltCallback         = HAL_UART_AbortCpltCallback;         
  huart->AbortTransmitCpltCallback = HAL_UART_AbortTransmitCpltCallback; 
  huart->AbortReceiveCpltCallback  = HAL_UART_AbortReceiveCpltCallback;  
#if defined(USART_CR1_UESM)
#if defined(USART_CR3_WUFIE)
  huart->WakeupCallback            = HAL_UARTEx_WakeupCallback;          
#endif 
#endif 
  huart->RxEventCallback           = HAL_UARTEx_RxEventCallback;         

}
#endif 

HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart) {
	uint32_t tmpreg;
	uint16_t brrtemp;
	UART_ClockSourceTypeDef clocksource;
	uint32_t usartdiv;
	HAL_StatusTypeDef ret = HAL_OK;
	uint32_t pclk;

	assert_param(IS_UART_BAUDRATE(huart->Init.BaudRate));
	assert_param(IS_UART_WORD_LENGTH(huart->Init.WordLength));
	assert_param(IS_UART_STOPBITS(huart->Init.StopBits));
	assert_param(IS_UART_ONE_BIT_SAMPLE(huart->Init.OneBitSampling));

	assert_param(IS_UART_PARITY(huart->Init.Parity));
	assert_param(IS_UART_MODE(huart->Init.Mode));
	assert_param(IS_UART_HARDWARE_FLOW_CONTROL(huart->Init.HwFlowCtl));
	assert_param(IS_UART_OVERSAMPLING(huart->Init.OverSampling));

	tmpreg = (uint32_t) huart->Init.WordLength | huart->Init.Parity
			| huart->Init.Mode | huart->Init.OverSampling;
	MODIFY_REG(huart->Instance->CR1, USART_CR1_FIELDS, tmpreg);

	MODIFY_REG(huart->Instance->CR2, USART_CR2_STOP, huart->Init.StopBits);

	tmpreg = (uint32_t) huart->Init.HwFlowCtl;

	tmpreg |= huart->Init.OneBitSampling;
	MODIFY_REG(huart->Instance->CR3, USART_CR3_FIELDS, tmpreg);

	UART_GETCLOCKSOURCE(huart, clocksource);

	if (huart->Init.OverSampling == UART_OVERSAMPLING_8) {
		switch (clocksource) {
			case UART_CLOCKSOURCE_PCLK1:
				pclk = HAL_RCC_GetPCLK1Freq();
			break;
			case UART_CLOCKSOURCE_PCLK2:
				pclk = HAL_RCC_GetPCLK2Freq();
			break;
			case UART_CLOCKSOURCE_HSI:
				pclk = (uint32_t) HSI_VALUE;
			break;
			case UART_CLOCKSOURCE_SYSCLK:
				pclk = HAL_RCC_GetSysClockFreq();
			break;
			case UART_CLOCKSOURCE_LSE:
				pclk = (uint32_t) LSE_VALUE;
			break;
			default:
				pclk = 0U;
				ret = HAL_ERROR;
			break;
		}

		if (pclk != 0U) {
			usartdiv = (uint16_t) (UART_DIV_SAMPLING8(pclk,
					huart->Init.BaudRate));
			if ((usartdiv >= UART_BRR_MIN) && (usartdiv <= UART_BRR_MAX)) {
				brrtemp = (uint16_t) (usartdiv & 0xFFF0U);
				brrtemp |= (uint16_t) ((usartdiv & (uint16_t) 0x000FU) >> 1U);
				huart->Instance->BRR = brrtemp;
			} else {
				ret = HAL_ERROR;
			}
		}
	} else {
		switch (clocksource) {
			case UART_CLOCKSOURCE_PCLK1:
				pclk = HAL_RCC_GetPCLK1Freq();
			break;
			case UART_CLOCKSOURCE_PCLK2:
				pclk = HAL_RCC_GetPCLK2Freq();
			break;
			case UART_CLOCKSOURCE_HSI:
				pclk = (uint32_t) HSI_VALUE;
			break;
			case UART_CLOCKSOURCE_SYSCLK:
				pclk = HAL_RCC_GetSysClockFreq();
			break;
			case UART_CLOCKSOURCE_LSE:
				pclk = (uint32_t) LSE_VALUE;
			break;
			default:
				pclk = 0U;
				ret = HAL_ERROR;
			break;
		}

		if (pclk != 0U) {

			usartdiv = (uint16_t) (UART_DIV_SAMPLING16(pclk,
					huart->Init.BaudRate));
			if ((usartdiv >= UART_BRR_MIN) && (usartdiv <= UART_BRR_MAX)) {
				huart->Instance->BRR = usartdiv;
			} else {
				ret = HAL_ERROR;
			}
		}
	}

	huart->RxISR = NULL;
	huart->TxISR = NULL;

	return ret;
}

void UART_AdvFeatureConfig(UART_HandleTypeDef *huart) {

	assert_param(IS_UART_ADVFEATURE_INIT(huart->AdvancedInit.AdvFeatureInit));

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_TXINVERT_INIT)) {
		assert_param(
				IS_UART_ADVFEATURE_TXINV(huart->AdvancedInit.TxPinLevelInvert));
		MODIFY_REG(huart->Instance->CR2, USART_CR2_TXINV,
				huart->AdvancedInit.TxPinLevelInvert);
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_RXINVERT_INIT)) {
		assert_param(
				IS_UART_ADVFEATURE_RXINV(huart->AdvancedInit.RxPinLevelInvert));
		MODIFY_REG(huart->Instance->CR2, USART_CR2_RXINV,
				huart->AdvancedInit.RxPinLevelInvert);
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_DATAINVERT_INIT)) {
		assert_param(
				IS_UART_ADVFEATURE_DATAINV(huart->AdvancedInit.DataInvert));
		MODIFY_REG(huart->Instance->CR2, USART_CR2_DATAINV,
				huart->AdvancedInit.DataInvert);
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_SWAP_INIT)) {
		assert_param(IS_UART_ADVFEATURE_SWAP(huart->AdvancedInit.Swap));
		MODIFY_REG(huart->Instance->CR2, USART_CR2_SWAP,
				huart->AdvancedInit.Swap);
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_RXOVERRUNDISABLE_INIT)) {
		assert_param(IS_UART_OVERRUN(huart->AdvancedInit.OverrunDisable));
		MODIFY_REG(huart->Instance->CR3, USART_CR3_OVRDIS,
				huart->AdvancedInit.OverrunDisable);
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_DMADISABLEONERROR_INIT)) {
		assert_param(
				IS_UART_ADVFEATURE_DMAONRXERROR(huart->AdvancedInit.DMADisableonRxError));
		MODIFY_REG(huart->Instance->CR3, USART_CR3_DDRE,
				huart->AdvancedInit.DMADisableonRxError);
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_AUTOBAUDRATE_INIT)) {
		assert_param(IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(huart->Instance));
		assert_param(
				IS_UART_ADVFEATURE_AUTOBAUDRATE(huart->AdvancedInit.AutoBaudRateEnable));
		MODIFY_REG(huart->Instance->CR2, USART_CR2_ABREN,
				huart->AdvancedInit.AutoBaudRateEnable);

		if (huart->AdvancedInit.AutoBaudRateEnable
				== UART_ADVFEATURE_AUTOBAUDRATE_ENABLE) {
			assert_param(
					IS_UART_ADVFEATURE_AUTOBAUDRATEMODE(huart->AdvancedInit.AutoBaudRateMode));
			MODIFY_REG(huart->Instance->CR2, USART_CR2_ABRMODE,
					huart->AdvancedInit.AutoBaudRateMode);
		}
	}

	if (HAL_IS_BIT_SET(huart->AdvancedInit.AdvFeatureInit,
			UART_ADVFEATURE_MSBFIRST_INIT)) {
		assert_param(IS_UART_ADVFEATURE_MSBFIRST(huart->AdvancedInit.MSBFirst));
		MODIFY_REG(huart->Instance->CR2, USART_CR2_MSBFIRST,
				huart->AdvancedInit.MSBFirst);
	}
}

HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart) {
	uint32_t tickstart;

	huart->ErrorCode = HAL_UART_ERROR_NONE;

	tickstart = HAL_GetTick();

	if ((huart->Instance->CR1 & USART_CR1_TE) == USART_CR1_TE) {

		if (UART_WaitOnFlagUntilTimeout(huart, USART_ISR_TEACK, RESET,
				tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK) {

			return HAL_TIMEOUT;
		}
	}
#if defined(USART_ISR_REACK)

  
  if ((huart->Instance->CR1 & USART_CR1_RE) == USART_CR1_RE)
  {
    
    if (UART_WaitOnFlagUntilTimeout(huart, USART_ISR_REACK, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
    {
      
      return HAL_TIMEOUT;
    }
  }
#endif

	huart->gState = HAL_UART_STATE_READY;
	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

	__HAL_UNLOCK(huart);

	return HAL_OK;
}

HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart,
		uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout) {

	while ((__HAL_UART_GET_FLAG(huart, Flag) ? SET : RESET) == Status) {

		if (Timeout != HAL_MAX_DELAY) {
			if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U)) {

				CLEAR_BIT(huart->Instance->CR1,
						(USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
				CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

				huart->gState = HAL_UART_STATE_READY;
				huart->RxState = HAL_UART_STATE_READY;

				__HAL_UNLOCK(huart);

				return HAL_TIMEOUT;
			}

			if (READ_BIT(huart->Instance->CR1, USART_CR1_RE) != 0U) {
				if (__HAL_UART_GET_FLAG(huart, UART_FLAG_RTOF) == SET) {

					__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_RTOF);

					CLEAR_BIT(huart->Instance->CR1,
							(USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
					CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

					huart->gState = HAL_UART_STATE_READY;
					huart->RxState = HAL_UART_STATE_READY;
					huart->ErrorCode = HAL_UART_ERROR_RTO;

					__HAL_UNLOCK(huart);

					return HAL_TIMEOUT;
				}
			}
		}
	}
	return HAL_OK;
}

HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart,
		uint8_t *pData, uint16_t Size) {
	huart->pRxBuffPtr = pData;
	huart->RxXferSize = Size;
	huart->RxXferCount = Size;
	huart->RxISR = NULL;

	UART_MASK_COMPUTATION(huart);

	huart->ErrorCode = HAL_UART_ERROR_NONE;
	huart->RxState = HAL_UART_STATE_BUSY_RX;

	SET_BIT(huart->Instance->CR3, USART_CR3_EIE);

	if ((huart->Init.WordLength == UART_WORDLENGTH_9B)
			&& (huart->Init.Parity == UART_PARITY_NONE)) {
		huart->RxISR = UART_RxISR_16BIT;
	} else {
		huart->RxISR = UART_RxISR_8BIT;
	}

	__HAL_UNLOCK(huart);

	SET_BIT(huart->Instance->CR1, USART_CR1_PEIE | USART_CR1_RXNEIE);
	return HAL_OK;
}

HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart,
		uint8_t *pData, uint16_t Size) {
	huart->pRxBuffPtr = pData;
	huart->RxXferSize = Size;

	huart->ErrorCode = HAL_UART_ERROR_NONE;
	huart->RxState = HAL_UART_STATE_BUSY_RX;

	if (huart->hdmarx != NULL) {

		huart->hdmarx->XferCpltCallback = UART_DMAReceiveCplt;

		huart->hdmarx->XferHalfCpltCallback = UART_DMARxHalfCplt;

		huart->hdmarx->XferErrorCallback = UART_DMAError;

		huart->hdmarx->XferAbortCallback = NULL;

		if (HAL_DMA_Start_IT(huart->hdmarx, (uint32_t) &huart->Instance->RDR,
				(uint32_t) huart->pRxBuffPtr, Size) != HAL_OK) {

			huart->ErrorCode = HAL_UART_ERROR_DMA;

			__HAL_UNLOCK(huart);

			huart->gState = HAL_UART_STATE_READY;

			return HAL_ERROR;
		}
	}
	__HAL_UNLOCK(huart);

	SET_BIT(huart->Instance->CR1, USART_CR1_PEIE);

	SET_BIT(huart->Instance->CR3, USART_CR3_EIE);

	SET_BIT(huart->Instance->CR3, USART_CR3_DMAR);

	return HAL_OK;
}

static void UART_EndTxTransfer(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE | USART_CR1_TCIE));

	huart->gState = HAL_UART_STATE_READY;
}

static void UART_EndRxTransfer(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
	CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
		CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
	}

	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

	huart->RxISR = NULL;
}

static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	if (hdma->Init.Mode != DMA_CIRCULAR) {
		huart->TxXferCount = 0U;

		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

		SET_BIT(huart->Instance->CR1, USART_CR1_TCIE);
	}

	else {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->TxCpltCallback(huart);
#else

		HAL_UART_TxCpltCallback(huart);
#endif 
	}
}

static void UART_DMATxHalfCplt(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->TxHalfCpltCallback(huart);
#else

	HAL_UART_TxHalfCpltCallback(huart);
#endif 
}

static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	if (hdma->Init.Mode != DMA_CIRCULAR) {
		huart->RxXferCount = 0U;

		CLEAR_BIT(huart->Instance->CR1, USART_CR1_PEIE);
		CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

		CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		huart->RxState = HAL_UART_STATE_READY;

		if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
			CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
		}
	}

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->RxEventCallback(huart, huart->RxXferSize);
#else

		HAL_UARTEx_RxEventCallback(huart, huart->RxXferSize);
#endif 
	} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->RxCpltCallback(huart);
#else

		HAL_UART_RxCpltCallback(huart);
#endif 
	}
}

static void UART_DMARxHalfCplt(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->RxEventCallback(huart, huart->RxXferSize / 2U);
#else

		HAL_UARTEx_RxEventCallback(huart, huart->RxXferSize / 2U);
#endif 
	} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    
    huart->RxHalfCpltCallback(huart);
#else

		HAL_UART_RxHalfCpltCallback(huart);
#endif 
	}
}

static void UART_DMAError(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	const HAL_UART_StateTypeDef gstate = huart->gState;
	const HAL_UART_StateTypeDef rxstate = huart->RxState;

	if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT))
			&& (gstate == HAL_UART_STATE_BUSY_TX)) {
		huart->TxXferCount = 0U;
		UART_EndTxTransfer(huart);
	}

	if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR))
			&& (rxstate == HAL_UART_STATE_BUSY_RX)) {
		huart->RxXferCount = 0U;
		UART_EndRxTransfer(huart);
	}

	huart->ErrorCode |= HAL_UART_ERROR_DMA;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->ErrorCallback(huart);
#else

	HAL_UART_ErrorCallback(huart);
#endif 
}

static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);
	huart->RxXferCount = 0U;
	huart->TxXferCount = 0U;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->ErrorCallback(huart);
#else

	HAL_UART_ErrorCallback(huart);
#endif 
}

static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	huart->hdmatx->XferAbortCallback = NULL;

	if (huart->hdmarx != NULL) {
		if (huart->hdmarx->XferAbortCallback != NULL) {
			return;
		}
	}

	huart->TxXferCount = 0U;
	huart->RxXferCount = 0U;

	huart->ErrorCode = HAL_UART_ERROR_NONE;

	__HAL_UART_CLEAR_FLAG(huart,
			UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

	huart->gState = HAL_UART_STATE_READY;
	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->AbortCpltCallback(huart);
#else

	HAL_UART_AbortCpltCallback(huart);
#endif 
}

static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	huart->hdmarx->XferAbortCallback = NULL;

	if (huart->hdmatx != NULL) {
		if (huart->hdmatx->XferAbortCallback != NULL) {
			return;
		}
	}

	huart->TxXferCount = 0U;
	huart->RxXferCount = 0U;

	huart->ErrorCode = HAL_UART_ERROR_NONE;

	__HAL_UART_CLEAR_FLAG(huart,
			UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

	__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

	huart->gState = HAL_UART_STATE_READY;
	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->AbortCpltCallback(huart);
#else

	HAL_UART_AbortCpltCallback(huart);
#endif 
}

static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart = (UART_HandleTypeDef*) (hdma->Parent);

	huart->TxXferCount = 0U;

	huart->gState = HAL_UART_STATE_READY;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->AbortTransmitCpltCallback(huart);
#else

	HAL_UART_AbortTransmitCpltCallback(huart);
#endif 
}

static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma) {
	UART_HandleTypeDef *huart =
			(UART_HandleTypeDef*) ((DMA_HandleTypeDef*) hdma)->Parent;

	huart->RxXferCount = 0U;

	__HAL_UART_CLEAR_FLAG(huart,
			UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

	__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

	huart->RxState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->AbortReceiveCpltCallback(huart);
#else

	HAL_UART_AbortReceiveCpltCallback(huart);
#endif 
}

static void UART_TxISR_8BIT(UART_HandleTypeDef *huart) {

	if (huart->gState == HAL_UART_STATE_BUSY_TX) {
		if (huart->TxXferCount == 0U) {

			CLEAR_BIT(huart->Instance->CR1, USART_CR1_TXEIE);

			SET_BIT(huart->Instance->CR1, USART_CR1_TCIE);
		} else {
			huart->Instance->TDR = (uint8_t) (*huart->pTxBuffPtr
					& (uint8_t) 0xFF);
			huart->pTxBuffPtr++;
			huart->TxXferCount--;
		}
	}
}

static void UART_TxISR_16BIT(UART_HandleTypeDef *huart) {
	uint16_t *tmp;

	if (huart->gState == HAL_UART_STATE_BUSY_TX) {
		if (huart->TxXferCount == 0U) {

			CLEAR_BIT(huart->Instance->CR1, USART_CR1_TXEIE);

			SET_BIT(huart->Instance->CR1, USART_CR1_TCIE);
		} else {
			tmp = (uint16_t*) huart->pTxBuffPtr;
			huart->Instance->TDR = (((uint32_t) (*tmp)) & 0x01FFUL);
			huart->pTxBuffPtr += 2U;
			huart->TxXferCount--;
		}
	}
}

static void UART_EndTransmit_IT(UART_HandleTypeDef *huart) {

	CLEAR_BIT(huart->Instance->CR1, USART_CR1_TCIE);

	huart->gState = HAL_UART_STATE_READY;

	huart->TxISR = NULL;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  
  huart->TxCpltCallback(huart);
#else

	HAL_UART_TxCpltCallback(huart);
#endif 
}

static void UART_RxISR_8BIT(UART_HandleTypeDef *huart) {
	uint16_t uhMask = huart->Mask;
	uint16_t uhdata;

	if (huart->RxState == HAL_UART_STATE_BUSY_RX) {
		uhdata = (uint16_t) READ_REG(huart->Instance->RDR);
		*huart->pRxBuffPtr = (uint8_t) (uhdata & (uint8_t) uhMask);
		huart->pRxBuffPtr++;
		huart->RxXferCount--;

		if (huart->RxXferCount == 0U) {

			CLEAR_BIT(huart->Instance->CR1,
					(USART_CR1_RXNEIE | USART_CR1_PEIE));

			CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

			huart->RxState = HAL_UART_STATE_READY;

			huart->RxISR = NULL;

			if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {

				CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->RxEventCallback(huart, huart->RxXferSize);
#else

				HAL_UARTEx_RxEventCallback(huart, huart->RxXferSize);
#endif 
			} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->RxCpltCallback(huart);
#else

				HAL_UART_RxCpltCallback(huart);
#endif 
			}
			huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;
		}
	} else {

		__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);
	}
}

static void UART_RxISR_16BIT(UART_HandleTypeDef *huart) {
	uint16_t *tmp;
	uint16_t uhMask = huart->Mask;
	uint16_t uhdata;

	if (huart->RxState == HAL_UART_STATE_BUSY_RX) {
		uhdata = (uint16_t) READ_REG(huart->Instance->RDR);
		tmp = (uint16_t*) huart->pRxBuffPtr;
		*tmp = (uint16_t) (uhdata & uhMask);
		huart->pRxBuffPtr += 2U;
		huart->RxXferCount--;

		if (huart->RxXferCount == 0U) {

			CLEAR_BIT(huart->Instance->CR1,
					(USART_CR1_RXNEIE | USART_CR1_PEIE));

			CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

			huart->RxState = HAL_UART_STATE_READY;

			huart->RxISR = NULL;

			if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE) {

				CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->RxEventCallback(huart, huart->RxXferSize);
#else

				HAL_UARTEx_RxEventCallback(huart, huart->RxXferSize);
#endif 
			} else {

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        
        huart->RxCpltCallback(huart);
#else

				HAL_UART_RxCpltCallback(huart);
#endif 
			}
			huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;
		}
	} else {

		__HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);
	}
}

#endif 

