#include "main.h"
#include <stdlib.h>
#include "string.h"

UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

void usartTransmitStringWithSize(char *string, uint16_t size) {
	while (HAL_UART_Transmit_IT(&huart2, (uint8_t*) string, size) == HAL_BUSY);
//	while (HAL_UART_Transmit(&huart2, (uint8_t*) string, size, 1000) == HAL_BUSY);
}

void usartTransmitString(char *string) {
	uint16_t size = strlen(string);
	usartTransmitStringWithSize(string, size);
}

uint8_t stringIsStartWith(char *string, char *compare) {
	uint16_t size = sizeof(compare) / 4;
	for (int i = 0; i < size; i++) {
		if (string[i] != compare[i]) {
			return 0;
		}
	}
	return 1;
}

uint8_t stringIsEndWith(char *string, char *compare) {
	for (int i = 0; i < sizeof(compare) / 4; i++) {
		if (string[i] != compare[i]) {
			return 0;
		}
	}
	return 1;
}

uint8_t stringContains(char *string, char *content) {
	uint16_t compareCounter = 0;
	for (int i = 0; string[i] != 0; i++) {
		if (string[i] == content[compareCounter]) {
			compareCounter++;
			if (content[compareCounter] == 0) return 1;
		} else
			compareCounter = 0;
	}
	return 0;
}

uint8_t stringEquals(char *string1, char *string2) {
	for (int i = 0;; i++) {
		if ((string1[i] != 0 && string2[i] == 0)
				|| (string1[i] == 0 && string2[i] != 0)) return 0;
		if (string1[i] != 0 && string2[i] != 0) {
			if (string1[i] != string2[i]) return 0;
		} else
			break;
	}
	return 1;
}

char*
floatToString(float value) {
	int begin = value * 10;
	int lastNumber = begin % 10;
	int firstNumbers = begin / 10;
	char *result;
	char numberBuffer[10];
	for (int i = 0; i < 10; i++)
		numberBuffer[i] = 0;
	itoa(firstNumbers, numberBuffer, 10);
	int temp = 0;
	for (int i = 0; numberBuffer[i] != 0; i++) {
		temp++;
	}
	result = malloc(temp + 3);
	for (int i = 0; i < temp; i++) {
		result[i] = numberBuffer[i];
	}
	result[temp] = '.';
	for (int i = 0; i < 10; i++)
		numberBuffer[i] = 0;
	itoa(lastNumber, numberBuffer, 10);
	result[temp + 1] = numberBuffer[0];
	result[temp + 2] = 0;
	return result;
}

void usartSendParamsToConnectedUser(uint8_t idUser, float amperes,
		float voltage, float energy) {
	char beginCommand[] = "AT+CIPSEND=";
	char amperesString[] = "Amperes: ";
	char voltageString[] = " Voltage: ";
	char consumptionString[] = " Consumption: ";
	char *amperesStringValue = floatToString(amperes);
	char *voltageStringValue = floatToString(voltage);
	char *consumptionStringValue = floatToString(energy);
	int commandLength = strlen(beginCommand) + 2;
	int stringParamsLength = strlen(amperesString) + strlen(voltageString)
			+ strlen(consumptionString) + (strlen(amperesStringValue))
			+ (strlen(voltageStringValue)) + (strlen(consumptionStringValue))
			+ 2;
	char stringParamsLengthStringValue[10];
	for (int i = 0; i < 10; i++) {
		stringParamsLengthStringValue[i] = 0;
	}
	itoa(stringParamsLength - 1, stringParamsLengthStringValue, 10);
	for (int i = 0; stringParamsLengthStringValue[i] != 0; i++) {
		commandLength++;
	}
	commandLength += 3;
	char *command = malloc(commandLength);
	int commandIterrator = 0;
	for (int i = 0; i < strlen(beginCommand); i++) {
		command[commandIterrator] = beginCommand[i];
		commandIterrator++;
	}
	char userIdStringValue[1];
	itoa(idUser, userIdStringValue, 10);
	command[commandIterrator] = userIdStringValue[0];
	command[commandIterrator + 1] = ',';
	commandIterrator += 2;
	for (int i = 0; stringParamsLengthStringValue[i] != 0; i++) {
		command[commandIterrator] = stringParamsLengthStringValue[i];
		commandIterrator++;
	}
	command[commandIterrator] = '\r';
	command[commandIterrator + 1] = '\n';
	command[commandIterrator + 2] = 0;
	char *stringParams = malloc(stringParamsLength);
	commandIterrator = 0;
	for (int i = 0; i < strlen(amperesString); i++) {
		stringParams[commandIterrator] = amperesString[i];
		commandIterrator++;
	}
	for (int i = 0; amperesStringValue[i] != 0; i++) {
		stringParams[commandIterrator] = amperesStringValue[i];
		commandIterrator++;
	}
	for (int i = 0; i < strlen(voltageString); i++) {
		stringParams[commandIterrator] = voltageString[i];
		commandIterrator++;
	}
	for (int i = 0; voltageStringValue[i] != 0; i++) {
		stringParams[commandIterrator] = voltageStringValue[i];
		commandIterrator++;
	}
	for (int i = 0; i < strlen(consumptionString); i++) {
		stringParams[commandIterrator] = consumptionString[i];
		commandIterrator++;
	}
	for (int i = 0; consumptionStringValue[i] != 0; i++) {
		stringParams[commandIterrator] = consumptionStringValue[i];
		commandIterrator++;
	}
	stringParams[commandIterrator] = '\n';
	stringParams[commandIterrator + 1] = 0;
//	usartTransmitStringWithSize(command, sizeof(command)/4);
//	usartTransmitStringWithSize(stringParams, sizeof(stringParams)/4);
	usartTransmitString(command);
	usartTransmitString(stringParams);
	free(amperesStringValue);
	free(voltageStringValue);
	free(consumptionStringValue);
	free(command);
	free(stringParams);
}

char*
buildedResult(uint8_t isConnect, int userId) {
	char idBuf[2];
	itoa(userId, idBuf, 10);
	char *result;
	if (isConnect) {
		result = malloc(12);
		result[0] = idBuf[0];
		result[1] = ',';
		result[2] = 'C';
		result[3] = 'O';
		result[4] = 'N';
		result[5] = 'N';
		result[6] = 'E';
		result[7] = 'C';
		result[8] = 'T';
		result[9] = '\r';
		result[10] = '\n';
		result[11] = 0;

	} else {
		result = malloc(11);
		result[0] = idBuf[0];
		result[1] = ',';
		result[2] = 'C';
		result[3] = 'L';
		result[4] = 'O';
		result[5] = 'S';
		result[6] = 'E';
		result[7] = 'D';
		result[8] = '\r';
		result[9] = '\n';
		result[10] = 0;
	}
	return result;
}

uint8_t receiveByteBuffer[5];
char buildedString[15];
int activeUsers[10];
uint16_t buildedStringIterator = 0;
uint8_t isBuilded = 0;
int receivedId = -1;
uint8_t receivedIdCharValue = 0;

//заменить, это для наглядности
float amperes = 10;
float volts = 220;
float consumption = 12.3;
//0,CONNECT\r\n

void resetBuildedParams() {
	for (int i = 0; i < 12; i++)
		buildedString[i] = 0;
	isBuilded = 0;
	buildedStringIterator = 0;
	receivedId = -1;
	receivedIdCharValue = 0;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart == &huart2) {
		if (!isBuilded) {
			resetBuildedParams();
			for (int i = 48; i < 58; i++) {
				if (receiveByteBuffer[0] == i) {
					receivedId = atoi((const char*) receiveByteBuffer);
					receiveByteBuffer[0] = 0;
					isBuilded = 1;
					buildedString[buildedStringIterator] = i;
					receivedIdCharValue = i;
					buildedStringIterator++;
					break;
				}
			}
		} else {
			if (buildedStringIterator < 11) {
				buildedString[buildedStringIterator] = receiveByteBuffer[0];
				buildedStringIterator++;
			} else {
				if (buildedStringIterator == 11) {
					buildedString[buildedStringIterator] = 0;
				}
			}
			char *buildedCompare = buildedResult(1, receivedId);
			char *buildedCompareDis = buildedResult(0, receivedId);
			if ((!stringIsStartWith(buildedCompare, buildedString))
					&& (!stringIsStartWith(buildedCompareDis, buildedString))) {
				resetBuildedParams();
			} else {
				if (stringContains(buildedString, buildedCompare)) {
					activeUsers[receivedId] = 1;
					resetBuildedParams();
				}
				if (stringContains(buildedString, buildedCompareDis)) {
					activeUsers[receivedId] = 0;
					resetBuildedParams();
				}
			}
			free(buildedCompare);
			free(buildedCompareDis);
		}
		for (int i = 0; i < 10; i++) {
			if (activeUsers[i] == 1) {
//					usartSendParamsToConnectedUser(i, amperes, volts, consumption);//после этой раскомментированой строки контроллер больше не принимает
				//но если вызвать эту команду перед основным циклом, то значения передадутся
			}
		}

		HAL_UART_Receive_IT(&huart2, receiveByteBuffer, 1);
	}
}

void usartSendArrayOfCommands(char *commands[], uint16_t size) {
	for (int i = 0; i < size; i++) {
		usartTransmitString(commands[i]);
		if (stringEquals(commands[i], "AT+RST\r\n")
				|| stringEquals(commands[i], "AT+RESTORE\r\n")) {
			HAL_Delay(500);
		}
		HAL_Delay(60);
	}
}

void wifiAndServerConfigure() {
	char *commands[] =
			{ "ATE0\r\n", "AT+CWMODE_CUR=3\r\n",
					"AT+CIPAPMAC_CUR=\"1a:fe:36:97:d5:7b\"\r\n",
					"AT+CWDHCP_CUR=2,1\r\n",
					"AT+CWSAP_CUR=\"PortativeChargeWifi\",\"\",5,0\r\n",
					"AT+CIPMUX=1\r\n", "AT+CIPSERVER=1,25565\r\n",
					"AT+CIPSTO=1800\r\n" };
	usartSendArrayOfCommands(commands, sizeof(commands) / 4);
}

void activeUsersReset() {
	for (int i = 0; i < 10; i++)
		activeUsers[i] = 0;
	for (int i = 0; i < 12; i++)
		buildedString[i] = 0;
}

int main(void) {

	HAL_Init();

	SystemClock_Config();

	MX_GPIO_Init();
	MX_USART2_UART_Init();

	wifiAndServerConfigure();
		activeUsersReset();
		HAL_UART_Receive_IT(&huart2, receiveByteBuffer, 1);
	//	int a = 0;
	//	usartSendParamsToConnectedUser(0, amperes, volts, consumption);
		while (1) {
	//		a = 1;
	//		HAL_Delay(5000);
	//		usartSendParamsToConnectedUser(0, amperes, volts, consumption);
		}
}

void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };

	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART2;
	PeriphClkInitStruct.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
		Error_Handler();
	}
}

static void MX_USART2_UART_Init(void) {

	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart2) != HAL_OK) {
		Error_Handler();
	}

}

static void MX_GPIO_Init(void) {

	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

}

void Error_Handler(void) {

	__disable_irq();
	while (1) {
	}

}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{



}
#endif

