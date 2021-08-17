/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32f7xx_ll_gpio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
void demo(uint16_t vol1, uint16_t vol2,uint16_t tok1,uint16_t tok2);

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#define START_TIM3()  TIM3->CR1 |= TIM_CR1_CEN
#define STOP_TIM3()   TIM3->CR1 &= ~(TIM_CR1_CEN)
#define START_TIM4()  TIM4->CR1 |= TIM_CR1_CEN
#define STOP_TIM4()   TIM4->CR1 &= ~(TIM_CR1_CEN)
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
//#define UP121_Pin GPIO_PIN_2
//#define UP121_GPIO_Port GPIOE
//#define UP11_Pin GPIO_PIN_3
//#define UP11_GPIO_Port GPIOE
//#define UP21_Pin GPIO_PIN_4
//#define UP21_GPIO_Port GPIOE
//#define UP31_Pin GPIO_PIN_5
//#define UP31_GPIO_Port GPIOE
//#define UP41_Pin GPIO_PIN_6
//#define UP41_GPIO_Port GPIOE
//#define KL1_Pin GPIO_PIN_9
//#define KL1_GPIO_Port GPIOE
//#define KL2_Pin GPIO_PIN_10
//#define KL2_GPIO_Port GPIOE
//#define CE_Pin GPIO_PIN_8
//#define CE_GPIO_Port GPIOD
//#define RS_Pin GPIO_PIN_10
//#define RS_GPIO_Port GPIOA
//#define RST_Pin GPIO_PIN_11
//#define RST_GPIO_Port GPIOA
//#define CS_Pin GPIO_PIN_12
//#define CS_GPIO_Port GPIOA
//#define KONT1_Pin GPIO_PIN_1
//#define KONT1_GPIO_Port GPIOD
//#define PILOT_Pin GPIO_PIN_4
//#define PILOT_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */
enum
{
 StateU12_1 = 0,
 StateU9_1,
 StateU6_1,
 StateU3_1,
 StateU0_1,
 StateU_Minus12_1,
};

typedef  struct
{
	__packed union
	{
		uint32_t bStateU12_1 : 1;
		uint32_t bStateU9_1 : 1;
		uint32_t bStateU6_1 : 1;
		uint32_t bStateU3_1 : 1;
		uint32_t bStateU0_1 : 1;
		uint32_t bStateU_Minus12_1 : 1;
/////////////////
		uint32_t bStateU12_2 : 1;
		uint32_t bStateU9_2 : 1;
		uint32_t bStateU6_2 : 1;
		uint32_t bStateU3_2 : 1;
		uint32_t bStateU0_2 : 1;
		uint32_t bStateU_Minus12_2 : 1;
/////////////////
		uint32_t bStateU12_3 : 1;
		uint32_t bStateU9_3 : 1;
		uint32_t bStateU6_3 : 1;
		uint32_t bStateU3_3 : 1;
		uint32_t bStateU0_3 : 1;
		uint32_t bStateU_Minus12_3 : 1;
//////////////////
		uint32_t reserv : 14;
	}bit;
	uint32_t StateU;
}CompareSelectU;
#define TEST_OK 1
#define TEST_FAULT 0
#define TRUE 1
#define FALSE 0
/* Private defines -----------------------------------------------------------*/
#define UP121_Pin LL_GPIO_PIN_2//входы для определенияпилот сигнала
#define UP121_GPIO_Port GPIOE

#define UP11_Pin LL_GPIO_PIN_3//
#define UP11_GPIO_Port GPIOE

#define UP21_Pin LL_GPIO_PIN_4//
#define UP21_GPIO_Port GPIOE

#define UP31_Pin LL_GPIO_PIN_5//
#define UP31_GPIO_Port GPIOE

#define UP41_Pin LL_GPIO_PIN_6//
#define UP41_GPIO_Port GPIOE

#define KL1_Pin LL_GPIO_PIN_9//выводы на светодиод VD1
#define KL1_GPIO_Port GPIOE

#define KL2_Pin LL_GPIO_PIN_10//выводы на светодиод VD1
#define KL2_GPIO_Port GPIOE

#define CE_Pin LL_GPIO_PIN_8//cs сигнал для 2 spi
#define CE_GPIO_Port GPIOD

#define RS_Pin LL_GPIO_PIN_10//rs сигнал для дисплея
#define RS_GPIO_Port GPIOA

#define RST_Pin LL_GPIO_PIN_11//rst сигнал для диспея
#define RST_GPIO_Port GPIOA

#define CS_Pin LL_GPIO_PIN_12//CS сигнал для диспея
#define CS_GPIO_Port GPIOA

#define KONT1_Pin LL_GPIO_PIN_1//сигнал управлеия контактером
#define KONT1_GPIO_Port GPIOD

#define PILOT_Pin LL_GPIO_PIN_4//для формирования пилот сигнала на фазу А
#define PILOT_GPIO_Port GPIOD

#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif
//×òåíèå ñîñòîÿíèÿ íàïðÿæåíèÿ ïëîò ñèãíàëà êàíàë 1
#define CP_MINUS_12_1_PIN_STATE (GPIOE->IDR & GPIO_PIN_2)
#define CP12_1_PIN_STATE (GPIOE->IDR & GPIO_PIN_3)
#define CP9_1_PIN_STATE (GPIOE->IDR & LL_GPIO_PIN_4)
#define CP6_1_PIN_STATE (GPIOE->IDR & LL_GPIO_PIN_5)
#define CP3_1_PIN_STATE (GPIOE->IDR & LL_GPIO_PIN_6)

//Óïðàâëåíèå êîíòàêòîðàìè
#define SET_KONT1 (GPIOF->ODR |= GPIO_PIN_1)
#define RESET_KONT1 (GPIOF->ODR &= ~GPIO_PIN_1)

//Óïðàâëåíèå PILOT ñèãíàëàìè
#define SET_PILOT1 (GPIOD->ODR &= ~LL_GPIO_PIN_4)
#define RESET_PILOT1 (GPIOD->ODR |= LL_GPIO_PIN_4)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
