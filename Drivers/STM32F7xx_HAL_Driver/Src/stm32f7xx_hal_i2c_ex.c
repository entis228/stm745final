


#include "stm32f7xx_hal.h"





#ifdef HAL_I2C_MODULE_ENABLED













HAL_StatusTypeDef HAL_I2CEx_ConfigAnalogFilter(I2C_HandleTypeDef *hi2c, uint32_t AnalogFilter)
{
  
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_ANALOG_FILTER(AnalogFilter));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    
    __HAL_I2C_DISABLE(hi2c);

    
    hi2c->Instance->CR1 &= ~(I2C_CR1_ANFOFF);

    
    hi2c->Instance->CR1 |= AnalogFilter;

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}


HAL_StatusTypeDef HAL_I2CEx_ConfigDigitalFilter(I2C_HandleTypeDef *hi2c, uint32_t DigitalFilter)
{
  uint32_t tmpreg;

  
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_DIGITAL_FILTER(DigitalFilter));

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    
    __HAL_LOCK(hi2c);

    hi2c->State = HAL_I2C_STATE_BUSY;

    
    __HAL_I2C_DISABLE(hi2c);

    
    tmpreg = hi2c->Instance->CR1;

    
    tmpreg &= ~(I2C_CR1_DNF);

    
    tmpreg |= DigitalFilter << 8U;

    
    hi2c->Instance->CR1 = tmpreg;

    __HAL_I2C_ENABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;

    
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

#if  (defined(SYSCFG_PMC_I2C_PB6_FMP) || defined(SYSCFG_PMC_I2C_PB7_FMP)) || (defined(SYSCFG_PMC_I2C_PB8_FMP) || defined(SYSCFG_PMC_I2C_PB9_FMP)) || (defined(SYSCFG_PMC_I2C1_FMP)) || (defined(SYSCFG_PMC_I2C2_FMP)) || defined(SYSCFG_PMC_I2C3_FMP) || defined(SYSCFG_PMC_I2C4_FMP)

void HAL_I2CEx_EnableFastModePlus(uint32_t ConfigFastModePlus)
{
  
  assert_param(IS_I2C_FASTMODEPLUS(ConfigFastModePlus));

  
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  
  SET_BIT(SYSCFG->PMC, (uint32_t)ConfigFastModePlus);
}


void HAL_I2CEx_DisableFastModePlus(uint32_t ConfigFastModePlus)
{
  
  assert_param(IS_I2C_FASTMODEPLUS(ConfigFastModePlus));

  
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  
  CLEAR_BIT(SYSCFG->PMC, (uint32_t)ConfigFastModePlus);
}

#endif




#endif 





