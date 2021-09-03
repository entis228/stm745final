


#include "stm32f7xx_hal.h"





#ifdef HAL_UART_MODULE_ENABLED








#if defined(USART_CR1_UESM)
static void UARTEx_Wakeup_AddressConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection);
#endif 









HAL_StatusTypeDef HAL_RS485Ex_Init(UART_HandleTypeDef *huart, uint32_t Polarity, uint32_t AssertionTime,
                                   uint32_t DeassertionTime)
{
  uint32_t temp;

  
  if (huart == NULL)
  {
    return HAL_ERROR;
  }
  
  assert_param(IS_UART_DRIVER_ENABLE_INSTANCE(huart->Instance));

  
  assert_param(IS_UART_DE_POLARITY(Polarity));

  
  assert_param(IS_UART_ASSERTIONTIME(AssertionTime));

  
  assert_param(IS_UART_DEASSERTIONTIME(DeassertionTime));

  if (huart->gState == HAL_UART_STATE_RESET)
  {
    
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

  
  if (UART_SetConfig(huart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }

  
  SET_BIT(huart->Instance->CR3, USART_CR3_DEM);

  
  MODIFY_REG(huart->Instance->CR3, USART_CR3_DEP, Polarity);

  
  temp = (AssertionTime << UART_CR1_DEAT_ADDRESS_LSB_POS);
  temp |= (DeassertionTime << UART_CR1_DEDT_ADDRESS_LSB_POS);
  MODIFY_REG(huart->Instance->CR1, (USART_CR1_DEDT | USART_CR1_DEAT), temp);

  
  __HAL_UART_ENABLE(huart);

  
  return (UART_CheckIdleState(huart));
}






#if defined(USART_CR3_UCESM)

HAL_StatusTypeDef HAL_UARTEx_EnableClockStopMode(UART_HandleTypeDef *huart)
{
  
  __HAL_LOCK(huart);

  
  SET_BIT(huart->Instance->CR3, USART_CR3_UCESM);

  
  __HAL_UNLOCK(huart);

  return HAL_OK;
}


HAL_StatusTypeDef HAL_UARTEx_DisableClockStopMode(UART_HandleTypeDef *huart)
{
  
  __HAL_LOCK(huart);

  
  CLEAR_BIT(huart->Instance->CR3, USART_CR3_UCESM);

  
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

#endif 

HAL_StatusTypeDef HAL_MultiProcessorEx_AddressLength_Set(UART_HandleTypeDef *huart, uint32_t AddressLength)
{
  
  if (huart == NULL)
  {
    return HAL_ERROR;
  }

  
  assert_param(IS_UART_ADDRESSLENGTH_DETECT(AddressLength));

  huart->gState = HAL_UART_STATE_BUSY;

  
  __HAL_UART_DISABLE(huart);

  
  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADDM7, AddressLength);

  
  __HAL_UART_ENABLE(huart);

  
  return (UART_CheckIdleState(huart));
}

#if defined(USART_CR1_UESM)

HAL_StatusTypeDef HAL_UARTEx_StopModeWakeUpSourceConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart;

  
  assert_param(IS_UART_WAKEUP_FROMSTOP_INSTANCE(huart->Instance));
  
  assert_param(IS_UART_WAKEUP_SELECTION(WakeUpSelection.WakeUpEvent));

  
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  
  __HAL_UART_DISABLE(huart);

#if defined(USART_CR3_WUS)
  
  MODIFY_REG(huart->Instance->CR3, USART_CR3_WUS, WakeUpSelection.WakeUpEvent);
#endif 

  if (WakeUpSelection.WakeUpEvent == UART_WAKEUP_ON_ADDRESS)
  {
    UARTEx_Wakeup_AddressConfig(huart, WakeUpSelection);
  }

  
  __HAL_UART_ENABLE(huart);

  
  tickstart = HAL_GetTick();

  
  if (UART_WaitOnFlagUntilTimeout(huart, USART_ISR_REACK, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
  {
    status = HAL_TIMEOUT;
  }
  else
  {
    
    huart->gState = HAL_UART_STATE_READY;
  }

  
  __HAL_UNLOCK(huart);

  return status;
}


HAL_StatusTypeDef HAL_UARTEx_EnableStopMode(UART_HandleTypeDef *huart)
{
  
  __HAL_LOCK(huart);

  
  SET_BIT(huart->Instance->CR1, USART_CR1_UESM);

  
  __HAL_UNLOCK(huart);

  return HAL_OK;
}


HAL_StatusTypeDef HAL_UARTEx_DisableStopMode(UART_HandleTypeDef *huart)
{
  
  __HAL_LOCK(huart);

  
  CLEAR_BIT(huart->Instance->CR1, USART_CR1_UESM);

  
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

#endif 

HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint16_t uhMask;
  uint32_t tickstart;

  
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;

    
    tickstart = HAL_GetTick();

    huart->RxXferSize  = Size;
    huart->RxXferCount = Size;

    
    UART_MASK_COMPUTATION(huart);
    uhMask = huart->Mask;

    
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.Parity == UART_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }

    __HAL_UNLOCK(huart);

    
    *RxLen = 0U;

    
    while (huart->RxXferCount > 0U)
    {
      
      if (__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE))
      {
        
        __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);

        
        
        if (*RxLen > 0U)
        {
          huart->RxState = HAL_UART_STATE_READY;

          return HAL_OK;
        }
      }

      
      if (__HAL_UART_GET_FLAG(huart, UART_FLAG_RXNE))
      {
        if (pdata8bits == NULL)
        {
          *pdata16bits = (uint16_t)(huart->Instance->RDR & uhMask);
          pdata16bits++;
        }
        else
        {
          *pdata8bits = (uint8_t)(huart->Instance->RDR & (uint8_t)uhMask);
          pdata8bits++;
        }
        
        *RxLen += 1U;
        huart->RxXferCount--;
      }

      
      if (Timeout != HAL_MAX_DELAY)
      {
        if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
        {
          huart->RxState = HAL_UART_STATE_READY;

          return HAL_TIMEOUT;
        }
      }
    }

    
    *RxLen = huart->RxXferSize - huart->RxXferCount;
    
    huart->RxState = HAL_UART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}


HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef status;

  
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;

    status =  UART_Start_Receive_IT(huart, pData, Size);

    
    if (status == HAL_OK)
    {
      if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
      {
        __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);
        SET_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
      }
      else
      {
        
        status = HAL_ERROR;
      }
    }

    return status;
  }
  else
  {
    return HAL_BUSY;
  }
}


HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef status;

  
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;

    status =  UART_Start_Receive_DMA(huart, pData, Size);

    
    if (status == HAL_OK)
    {
      if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
      {
        __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);
        SET_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
      }
      else
      {
        
        status = HAL_ERROR;
      }
    }

    return status;
  }
  else
  {
    return HAL_BUSY;
  }
}






#if defined(USART_CR1_UESM)


static void UARTEx_Wakeup_AddressConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection)
{
  assert_param(IS_UART_ADDRESSLENGTH_DETECT(WakeUpSelection.AddressLength));

  
  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADDM7, WakeUpSelection.AddressLength);

  
  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADD, ((uint32_t)WakeUpSelection.Address << UART_CR2_ADDRESS_LSB_POS));
}
#endif 



#endif 






