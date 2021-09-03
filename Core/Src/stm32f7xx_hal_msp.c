
#include "main.h"

void HAL_MspInit(void) {

	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_RCC_SYSCFG_CLK_ENABLE();

}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	if (huart->Instance == USART2) {

		__HAL_RCC_USART2_CLK_ENABLE();

		__HAL_RCC_GPIOD_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(USART2_IRQn);

	}

}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {

		__HAL_RCC_USART2_CLK_DISABLE();

		HAL_GPIO_DeInit(GPIOD, GPIO_PIN_5 | GPIO_PIN_6);

		HAL_NVIC_DisableIRQ(USART2_IRQn);

	}

}

