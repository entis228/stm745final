 


#include "stm32f7xx_hal.h"





#ifdef HAL_PWR_MODULE_ENABLED



    
#define PWR_OVERDRIVE_TIMEOUT_VALUE  1000
#define PWR_UDERDRIVE_TIMEOUT_VALUE  1000
#define PWR_BKPREG_TIMEOUT_VALUE     1000
#define PWR_VOSRDY_TIMEOUT_VALUE     1000

    









HAL_StatusTypeDef HAL_PWREx_EnableBkUpReg(void)
{
  uint32_t tickstart = 0;

  
  PWR->CSR1 |= PWR_CSR1_BRE;
    
  
  
  PWR->CSR1 |= PWR_CSR1_EIWUP;

  
  tickstart = HAL_GetTick();

    
  while(__HAL_PWR_GET_FLAG(PWR_FLAG_BRR) == RESET)
  {
    if((HAL_GetTick() - tickstart ) > PWR_BKPREG_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    } 
  }
  return HAL_OK;
}


HAL_StatusTypeDef HAL_PWREx_DisableBkUpReg(void)
{
  uint32_t tickstart = 0;
  
  
  PWR->CSR1 &= (uint32_t)~((uint32_t)PWR_CSR1_BRE);
  
  
  
  PWR->CSR1 |= PWR_CSR1_EIWUP;

  
  tickstart = HAL_GetTick();

    
  while(__HAL_PWR_GET_FLAG(PWR_FLAG_BRR) != RESET)
  {
    if((HAL_GetTick() - tickstart ) > PWR_BKPREG_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    } 
  }
  return HAL_OK;
}


void HAL_PWREx_EnableFlashPowerDown(void)
{
  
  PWR->CR1 |= PWR_CR1_FPDS;
}


void HAL_PWREx_DisableFlashPowerDown(void)
{
  
  PWR->CR1 &= (uint32_t)~((uint32_t)PWR_CR1_FPDS);
}


void HAL_PWREx_EnableMainRegulatorLowVoltage(void)
{
  
  PWR->CR1 |= PWR_CR1_MRUDS;
}


void HAL_PWREx_DisableMainRegulatorLowVoltage(void)
{  
  
  PWR->CR1 &= (uint32_t)~((uint32_t)PWR_CR1_MRUDS);
}


void HAL_PWREx_EnableLowRegulatorLowVoltage(void)
{
  
  PWR->CR1 |= PWR_CR1_LPUDS;
}


void HAL_PWREx_DisableLowRegulatorLowVoltage(void)
{
  
  PWR->CR1 &= (uint32_t)~((uint32_t)PWR_CR1_LPUDS);
}


HAL_StatusTypeDef HAL_PWREx_EnableOverDrive(void)
{
  uint32_t tickstart = 0;

  __HAL_RCC_PWR_CLK_ENABLE();
  
  
  __HAL_PWR_OVERDRIVE_ENABLE();

  
  tickstart = HAL_GetTick();

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_ODRDY))
  {
    if((HAL_GetTick() - tickstart ) > PWR_OVERDRIVE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
  
  
  __HAL_PWR_OVERDRIVESWITCHING_ENABLE();

  
  tickstart = HAL_GetTick();

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_ODSWRDY))
  {
    if((HAL_GetTick() - tickstart ) > PWR_OVERDRIVE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  } 
  return HAL_OK;
}


HAL_StatusTypeDef HAL_PWREx_DisableOverDrive(void)
{
  uint32_t tickstart = 0;
  
  __HAL_RCC_PWR_CLK_ENABLE();
    
  
  __HAL_PWR_OVERDRIVESWITCHING_DISABLE();
  
  
  tickstart = HAL_GetTick();
 
  while(__HAL_PWR_GET_FLAG(PWR_FLAG_ODSWRDY))
  {
    if((HAL_GetTick() - tickstart ) > PWR_OVERDRIVE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  } 
  
  
  __HAL_PWR_OVERDRIVE_DISABLE();

  
  tickstart = HAL_GetTick();

  while(__HAL_PWR_GET_FLAG(PWR_FLAG_ODRDY))
  {
    if((HAL_GetTick() - tickstart ) > PWR_OVERDRIVE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
  
  return HAL_OK;
}


HAL_StatusTypeDef HAL_PWREx_EnterUnderDriveSTOPMode(uint32_t Regulator, uint8_t STOPEntry)
{
  uint32_t tempreg = 0;
  uint32_t tickstart = 0;
  
  
  assert_param(IS_PWR_REGULATOR_UNDERDRIVE(Regulator));
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));
  
  
  __HAL_RCC_PWR_CLK_ENABLE();
  
  
  __HAL_PWR_CLEAR_ODRUDR_FLAG();
  
   
  __HAL_PWR_UNDERDRIVE_ENABLE();

  
  tickstart = HAL_GetTick();

  
  while(__HAL_PWR_GET_FLAG(PWR_FLAG_UDRDY))
  {
    if((HAL_GetTick() - tickstart ) > PWR_UDERDRIVE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
  
  
  tempreg = PWR->CR1;
  
  tempreg &= (uint32_t)~(PWR_CR1_PDDS | PWR_CR1_LPDS | PWR_CR1_LPUDS | PWR_CR1_MRUDS);
  
  
  tempreg |= Regulator;
  
  
  PWR->CR1 = tempreg;
  
  
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
  
  
  if(STOPEntry == PWR_SLEEPENTRY_WFI)
  {   
    
    __WFI();
  }
  else
  {
    
    __WFE();
  }
  
  SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP_Msk);

  return HAL_OK;  
}

  
uint32_t HAL_PWREx_GetVoltageRange(void)
{
  return  (PWR->CR1 & PWR_CR1_VOS);
}


HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling)
{
  uint32_t tickstart = 0;

  assert_param(IS_PWR_REGULATOR_VOLTAGE(VoltageScaling));

  
  __HAL_RCC_PWR_CLK_ENABLE();

  
  if(__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_CFGR_SWS_PLL)
  {
    
    __HAL_RCC_PLL_DISABLE();
    
    
    tickstart = HAL_GetTick();    
      
    while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY) != RESET)
    {
      if((HAL_GetTick() - tickstart ) > PLL_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
    
    
    __HAL_PWR_VOLTAGESCALING_CONFIG(VoltageScaling);
    
    
    __HAL_RCC_PLL_ENABLE();
    
    
    tickstart = HAL_GetTick();
      
    while(__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY) == RESET)
    {
      if((HAL_GetTick() - tickstart ) > PLL_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      } 
    }
    
    
    tickstart = HAL_GetTick();
    while((__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY) == RESET))
    {
      if((HAL_GetTick() - tickstart ) > PWR_VOSRDY_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      } 
    }
  }
  else
  {
    return HAL_ERROR;
  }
  return HAL_OK;
}





#endif 





