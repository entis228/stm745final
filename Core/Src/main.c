#include "main.h"
#include "stm32f7xx_ll_bus.h"
#include "stm32f7xx_ll_gpio.h"
#include "st7735.h"
#include "testimg.h"
#include "image1preview.h"
#include "image2ChargeIsOver.h"
#include "image3ConnectorRemoved.h"
#include "image4PlagIn.h"
#include "image5WaitForTheStart.h"
#include "image6ChargeStart.h"
#include "Data.h"
#include <stdlib.h>
#include "BaseWork.h"
#include "stm32f7xx_it.h"
#include "FlashSST25.h"
#include "string.h"
/* Private includes ----------------------------------------------------------*/
#define EnableTim               (TIM3->CR1 |= TIM_CR1_CEN)
#define DisableTim              (TIM3->CR1 &= (0b1111111111111110))
#define ClearTimCount           (TIM3->CNT = 0)
#define ClearTimeFlag           (TIM3->SR = (0b1111111111111110))
#define EnableTimA               (TIM4->CR1 |= TIM_CR1_CEN)
#define DisableTimA             (TIM4->CR1 &= 0b1111111111111110)
#define ClearTimCountA         (TIM4->CNT = 0)
#define ClearTimeFlagA           (TIM4->SR = (0b1111111111111110))
/* USER CODE BEGIN Includes */

DMA_HandleTypeDef hdma_spi1_tx;
uint16_t U1Cod = 0;
uint16_t U2Cod = 0;
uint16_t U3Cod = 0;
uint16_t U4Cod = 0;

uint8_t r = 0;

/* USER CODE END Includes */



/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
void demoView(void)
{
//char sd[] = "  Portable         charging          station";


		ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) fon_img_160x128);
		HAL_Delay(3000);
		ST7735_FillScreen(0x07E0);
		ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) imege1peview_160x128);
		//ST7735_DrawString(0, 0, sd , Font_11x18, ST7735_BLACK, 0x07E0);
		HAL_Delay(3000);
		ST7735_FillScreen(0x07E0);

}


void StopTimer()
{
	DisableTim;
	ClearTimCount;
	ClearTimeFlag;
	DisableTimA;
	ClearTimCountA;
	ClearTimeFlagA;
	SET_PILOT1;
}


SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart2;



/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);

uint16_t pilotSignal= 00000;
uint16_t pilotSave=00000;
int counter121=0;
int counterPilot[4];
uint8_t flagGround=0;
uint8_t Statusflag=0;
uint8_t PreviousState=0;
uint8_t rezult = 0;
uint16_t counterTok=0;
uint8_t VoltPilotStatus=9;
uint16_t counterLength=100;//переменная для
uint16_t circle=0;
uint32_t startChrgeTime;//переменная для хранения начала заряда
uint32_t finishChrgeTime;//переменная для хранения конца заряда
uint32_t currentOneTimeperiod;
float koof =0.1;

void checkPilot121()
{
	// pilotSignal= 00000;
//	pilotSignal=pilotSignal | (( GPIOE ->IDR & (1<<2))  >= 1);
//	circle=pilotSignal;
if((GPIOE ->IDR & (1<<2))  >= 1)
	{
			counter121++;
			if(counter121>=500)
			{	flagGround=0;
				pilotSignal = pilotSignal | 0b00001;
			}
			if(counter121>=510)
			{   flagGround=0;
				counter121=510;
			}
	 }
	else
		{
		counter121--;
		if(counter121<=10)
		{	flagGround=1;
			pilotSignal = pilotSignal & 0b11110;
		}
		if(counter121<0)
		{	flagGround=1;
			counter121=0;
		}
		}
}
void checkPilot()
{
	uint8_t i=0;
uint8_t flagg=0;
//		pilotSignal = 	pilotSignal | (((GPIOE ->IDR & (1<<3))  >= 1)<< 1);
//		pilotSignal = 	pilotSignal | (((GPIOE ->IDR & (1<<4))  >= 1)<< 2);
//		pilotSignal = 	pilotSignal | (((GPIOE ->IDR & (1<<5))  >= 1)<< 3);
//		pilotSignal = 	pilotSignal | (((GPIOE ->IDR & (1<<6))  >= 1)<< 4);
	for(i=0;i<4;i++)
	{
	if((GPIOE ->IDR & (1<<(3+i)))  >= 1)
		{
				counterPilot[i]++;
				if(counterPilot[i]>=500)
				{
					pilotSignal = pilotSignal | (0b00010<<i);
				}
				if(counterPilot[i]>=510)
				{
					counterPilot[i]=510;
				}
		 }
		else
			{
			counterPilot[i]--;
			if(counterPilot[i]<=10)
			{flagg=0b11111 ^ (0b00010<<i);
				pilotSignal = pilotSignal & (flagg);
			}
			if(counterPilot[i]<0)
			{
				counterPilot[i]=0;
			}
			}
	}

}
void demoPilotSignal()
{char V0Char[10];
//sprintf(V0Char,"%3.2f",pilotSignal);
	itoa(pilotSignal,V0Char,2);
		ST7735_DrawString(100,100, V0Char , Font_11x18, ST7735_BLACK, 0x07E0);



}

float expRunningAverage(float newVal)
{
  static float filVal = 0;
  filVal += (newVal - filVal) * koof;
  return filVal;
}
void demofloat(float  voltPN, float voltGN, float AmperPh, float AmperN)
{

	char voltPNChar[10];
	char voltGNChar[10];
	char AmperPhChar[10];
	char AmperNChar[10];
	char EnergyRez[10];
	char PowerRez[10];
	float Energy=0;
	float SPower=0;

	voltPN=expRunningAverage(voltPN);//Экспоненциальный фильтр

	currentOneTimeperiod=HAL_GetTick();
	SPower=voltPN*AmperPh;
	Energy=SPower*(currentOneTimeperiod-startChrgeTime)/3600000000;//подкоректировать с учетом частоты микроконтроллераа



	sprintf(voltPNChar,"%3.2f",voltPN);
	//sprintf(voltGNChar,"%3.2f",voltGN);
	sprintf(AmperPhChar,"%3.2f",AmperPh);
	//sprintf(AmperNChar,"%3.2f",AmperN);
	sprintf(PowerRez,"%3.2f",SPower);
	sprintf(EnergyRez,"%3.2f",Energy);

	ST7735_DrawString(80,0,  voltPNChar  , Font_11x18, ST7735_BLACK, 0x07E0);
//	ST7735_DrawString(80,20, voltGNChar , Font_11x18, ST7735_BLACK, 0x07E0);
	ST7735_DrawString(80,20,  AmperPhChar , Font_11x18, ST7735_BLACK, 0x07E0);
//	ST7735_DrawString(80,60, AmperNChar , Font_11x18, ST7735_BLACK, 0x07E0);
	ST7735_DrawString(80,40, PowerRez , Font_11x18, ST7735_BLACK, 0x07E0);
	ST7735_DrawString(80,60,  EnergyRez , Font_11x18, ST7735_BLACK, 0x07E0);

}
void interface()
{
	ST7735_DrawString(0,0,  "V" , Font_11x18, ST7735_BLACK, 0x07E0);
	ST7735_DrawString(0,20, "A" , Font_11x18, ST7735_BLACK, 0x07E0);
	ST7735_DrawString(0,40, "P "   , Font_11x18, ST7735_BLACK, 0x07E0);
	ST7735_DrawString(0,60, "E "  , Font_11x18, ST7735_BLACK, 0x07E0);
}
void demoV0(uint16_t demo)
{char V0Char[5];
itoa(demo,V0Char,10);
	ST7735_DrawString(0,100, V0Char , Font_11x18, ST7735_BLACK, 0x07E0);
}
void contactor(uint8_t OnOrOff)
{
	if(OnOrOff == 1 )
	{
		GPIOD->ODR |= (1<<1);
	}
	else
	{
		GPIOD->ODR &= ~(1<<1);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
void CheckPilotStart()
{
	if(((GPIOE ->IDR & (1<<3))  >= 1) && VoltPilotStatus == 9)
	{
		MX_TIM3_Init();
		HAL_TIM_Base_Start_IT(&htim3);
		 VoltPilotStatus = 6;
	}
}
uint8_t hargeflagg=0;
void CheckSensorParameters(uint16_t PilotStatus)
{
	ReadSensor();

     if(voltGN  < 20 && AmperN < 1 && voltPN<250 && (PilotStatus==0b110||PilotStatus==0b1110))//change amperN coof
		 {	   contactor(1);  //add function contact closures

    	 	 Statusflag=11;

    	 	 if(voltPN>200 )
    	 	 {	circle++;
    	 		 if(circle>counterLength)
    	 		 {circle=0;
    	 			 I_PWM.I_PWM_FaseA+=3;
    	 				if(I_PWM.I_PWM_FaseA>=54)
    	 				{
    	 					I_PWM.I_PWM_FaseA=54;
    	 				} 							//add function increase ampers
    	 		 }
    	 	 }
    	 	 else
    	 	 {
    	 		I_PWM.I_PWM_FaseA-=3;
    	 				if(I_PWM.I_PWM_FaseA<=10)
    	 				{I_PWM.I_PWM_FaseA=0;}
    	 												//add function reduction ampers
    	 	 }
		 }
     else
     {I_PWM.I_PWM_FaseA=7;
    	 contactor(0); 	 //add function opening contacts
    	Statusflag=1;//error ground
     }





}
void ProgramCycle()
{
	pilotSave=pilotSignal;
CheckSensorParameters(pilotSave);

	if((hargeflagg==1) && (pilotSave==0b10))
			{
		startChrgeTime=0;
		finishChrgeTime=HAL_GetTick();
		ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) ChargeIsOver_160x128);
				//ST7735_DrawString(0,0, "Charging is   over. Remove  the connector" , Font_11x18, ST7735_BLACK, 0x07E0);
				HAL_Delay(1000);
				PreviousState = 0b10;
				rezult=0;

				return;

			}



	switch(pilotSave)
	{
	case 0b00:

			if(PreviousState!=0b00)
			{	ST7735_FillScreen(0x07E0);
			hargeflagg=0;

			ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) ConnectorRemoved_160x128);
			//	ST7735_DrawString(0,0, "Connector removed" , Font_11x18, ST7735_BLACK, 0x07E0);
				StopTimer();
				HAL_Delay(1000);

				VoltPilotStatus=9;

			}
			else
			{
				ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) PlagInConnector_160x128);
				//ST7735_DrawString(0,0, "Plug in the   connector of  the charging   station" , Font_11x18, ST7735_BLACK, 0x07E0);
			}

		break;
	case 0b10:
			ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) WaitStart_160x128);
			//ST7735_DrawString(0,0, "Wait for the  start of the  charge" , Font_11x18, ST7735_BLACK, 0x07E0);

//		}
		break;
	case 0b110:

			if(PreviousState==0b110)
					{hargeflagg=1;

						interface();
						PreviousState=0b0110;
						rezult=0;
						demofloat(voltPN, voltGN, AmperPh, AmperN);

					return;
					}

				if(Statusflag==11)
				{hargeflagg=1;
				startChrgeTime  =HAL_GetTick();
				finishChrgeTime =startChrgeTime;
				ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) ChargeStart_160x128);
				//ST7735_DrawString(0,0, "Charging start" , Font_11x18, ST7735_BLACK, 0x07E0);
				}
				else
				{
				ST7735_DrawString(0,0, "Error ground" , Font_11x18, ST7735_BLACK, 0x07E0);
				PreviousState=0;
				return;
				}

				HAL_Delay(1000);
				ST7735_FillScreen(0x07E0);
		break;

	case 0b1110:

		if(PreviousState==0b110||PreviousState==0b1110)
				{hargeflagg=1;
					interface();
					PreviousState=0b01110;
					rezult=0;
					demofloat(voltPN, voltGN, AmperPh, AmperN);

				return;
				}

			if(Statusflag==11)
			{hargeflagg=1;
			ST7735_DrawImage(0, 0, 160, 128, (uint16_t*) ChargeStart_160x128);
			//ST7735_DrawString(0,0, "Charging start" , Font_11x18, ST7735_BLACK, 0x07E0);
			}
			else
			{
			ST7735_DrawString(0,0, "Error ground" , Font_11x18, ST7735_BLACK, 0x07E0);
			PreviousState=0;
			return;
			}

			HAL_Delay(1000);
			ST7735_FillScreen(0x07E0);
			ST7735_DrawString(0,0, "Error#1" , Font_11x18, ST7735_BLACK, 0x07E0);

		break;




	case 0b1111:

	contactor(0);
		ST7735_DrawString(0,0, "Error ground" , Font_11x18, ST7735_BLACK, 0x07E0);


			break;



	default:
		ST7735_DrawString(0,0, "Unknown error contact       manufacturer" , Font_11x18, ST7735_BLACK, 0x07E0);
		hargeflagg=0;
		break;


	}
	 if(PreviousState == pilotSave)
	{rezult=0;}
	 PreviousState = pilotSave;


}
////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
  HAL_Init();
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  SystemClock_Config();
  MX_GPIO_Init();
  MX_SPI1_Init();
  ST7735_Init();
  demoView();
  InitSPI2();
  MX_TIM4_Init();
 // MX_TIM3_Init();
  I_PWM.I_PWM_FaseA = 7;	//7% заполнения Ш�?М
  HAL_TIM_Base_Start_IT(&htim3);



  while (1)
  {
	  CheckPilotStart();
	  ProgramCycle();
	  demoPilotSignal();

	  if(rezult!=0)
	  {
		  ST7735_FillScreen(0x07E0);
	  }



  }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInitStruct.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi2.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 7;
  hspi2.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi2.Init.NSSPMode = SPI_NSS_PULSE_DISABLED;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{
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

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{
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

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
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
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, KL1_Pin|KL2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, CE_Pin|KONT1_Pin|PILOT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RS_Pin|RST_Pin|CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : UP121_Pin UP11_Pin UP21_Pin UP31_Pin
                           UP41_Pin */
  GPIO_InitStruct.Pin = UP121_Pin|UP11_Pin|UP21_Pin|UP31_Pin
                          |UP41_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : KL1_Pin KL2_Pin */
  GPIO_InitStruct.Pin = KL1_Pin|KL2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : CE_Pin KONT1_Pin PILOT_Pin */
  GPIO_InitStruct.Pin = CE_Pin|KONT1_Pin|PILOT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : RS_Pin RST_Pin CS_Pin */
  GPIO_InitStruct.Pin = RS_Pin|RST_Pin|CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
