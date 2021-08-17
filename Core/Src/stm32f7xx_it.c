/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f7xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f7xx_it.h"
#include "Data.h"
#include "BaseWork.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M7 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

void TIM3_Init(void)
{  // 1 us

	TIM_HandleTypeDef   TimHandle;
  /* TIM3 Peripheral clock enable */
  __HAL_RCC_TIM3_CLK_ENABLE();

  TimHandle.Instance = TIM3;
  TimHandle.Init.Period            = 999;
  TimHandle.Init.Prescaler         = 107;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;

  if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
  /* Set the TIMx priority */
  HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIM3_IRQn);

	TIM3->SR &= ~(TIM_SR_UIF);
	TIM3->DIER |= TIM_IT_UPDATE;
	START_TIM3();
}
//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void TIM4_Init(void)
{  // 1 us

	TIM_HandleTypeDef   Tim4Handle;
  /* TIM3 Peripheral clock enable */
  __HAL_RCC_TIM4_CLK_ENABLE();

  Tim4Handle.Instance = TIM4;
  Tim4Handle.Init.Period            = 70;
  Tim4Handle.Init.Prescaler         = 107;
  Tim4Handle.Init.ClockDivision     = 0;
  Tim4Handle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  Tim4Handle.Init.RepetitionCounter = 0;

  if (HAL_TIM_Base_Init(&Tim4Handle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Set the TIMx priority */
  HAL_NVIC_SetPriority(TIM4_IRQn, 0, 2);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIM4_IRQn);

	TIM4->SR &= ~(TIM_SR_UIF);
	TIM4->DIER |= TIM_IT_UPDATE;
	STOP_TIM4();
}
data_PSTN array_data;
const uint16_t V0 = 2240;
//uint8_t statADCBuffRefresh = 0;
void readADC()
{
	//uint16_t rezultOnDispley=0;
				int last_idx;
				int ch_idx;

				//SCB_CleanInvalidateDCache();
				statADCBuffRefresh &= ~ADCBuffRefresh;

	//
				U1Cod = getADC(0);
				U2Cod = getADC(1);
				U3Cod = getADC(2);
				U4Cod = getADC(3);

				array_data.ValueADC_PSTN.IADC[0] = U1Cod - V0;
				array_data.ValueADC_PSTN.IADC[1] = U2Cod - V0;
				array_data.ValueADC_PSTN.IADC[2] = U3Cod - V0;
				array_data.ValueADC_PSTN.IADC[3] = U4Cod - V0;

				if(++ADC_Values1.idx == ADC_CH_BUF_LEN)
				{
					ADC_Values1.idx = 0;
				}
				last_idx = ADC_Values1.idx;

				for(ch_idx = 0; ch_idx < ZSEM_CHANNEL_NUM; ch_idx++)
							{
								int32_t new_val1;


								new_val1 = array_data.ValueADC_PSTN.IADC[ch_idx];
								ADC_Values1.data[ch_idx][last_idx] = new_val1;
							}
}
/**
  * @brief This function handles Hard fault interrupt.
  */

void TIM3_IRQHandler(void)
{
	readADC();
	TIM3->SR &= ~(TIM_SR_UIF);
	SET_PILOT1;
  TIM4->ARR = I_PWM.I_PWM_FaseA*10;
	START_TIM4();
	statADCBuffRefresh |= ADCBuffRefresh;
	//ReadIntADC();
}

void TIM4_IRQHandler(void)
{
	TIM4->SR &= ~(TIM_SR_UIF);
	STOP_TIM4();
	RESET_PILOT1;

}
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f7xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
