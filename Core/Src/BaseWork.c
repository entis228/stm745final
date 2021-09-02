//BaseWork.c

#include "BaseWork.h"
#include <math.h>
#include "FT_float.h"
#include "Calc.h"
//#include <stdio.h>
#include <string.h>
//#include "Koef.h"
#include "arm_math.h"
#include "Data.h"
#include "main.h"
#include "FlashSST25.h"
uint16_t k=0;
uint16_t masRezult;
//const uint16_t V0 = 2241;
int16_t BufADC1[20] = {0,
309,
587,
809,
951,
999,
951,
809,
587,
309,
0,
-309,
-587,
-809,
-951,
-999,
-951,
-809,
-587,
-309
};

data_PSTN array_data;
uint8_t statADCBuffRefresh = 0;
Param_Value_vt Value_vt1;
ADC_Value_vt ADC_Values1;
Param_Value_vt Value_vt2;
ADC_Value_vt ADC_Values2;
I_PWM_Percent_vt I_PWM;
uint16_t StateU_FA; 
uint8_t CounterErrADC = 0;
CompareSelectU compareSelectU;


/////////////////////////////////////////////////////////////////////////
uint8_t ComparSelectU_Ch1(void)
{
	uint8_t RetState = 0;
	
	if((CP12_1_PIN_STATE == 1) && (CP9_1_PIN_STATE == 1) && (CP6_1_PIN_STATE == 1) && (CP3_1_PIN_STATE == 1))
	{	
		compareSelectU.StateU &= ~0x00003f;
		compareSelectU.bit.bStateU12_1 = 1;
		RetState = StateU12_1;
	}
	else
	if((CP12_1_PIN_STATE == 0) && (CP9_1_PIN_STATE == 1) && (CP6_1_PIN_STATE == 1) && (CP3_1_PIN_STATE == 1))
	{	
		compareSelectU.StateU &= ~0x00003f;
		compareSelectU.bit.bStateU9_1 = 1;
		RetState = StateU9_1;
	}
	else
	if((CP12_1_PIN_STATE == 0) && (CP9_1_PIN_STATE == 0) && (CP6_1_PIN_STATE == 1) && (CP3_1_PIN_STATE == 1))
	{	
		compareSelectU.StateU &= ~0x00003f;
		compareSelectU.bit.bStateU6_1 = 1;
		RetState = StateU6_1;
	}
	else
	if((CP12_1_PIN_STATE == 0) && (CP9_1_PIN_STATE == 0) && (CP6_1_PIN_STATE == 0) && (CP3_1_PIN_STATE == 1))
	{	
		compareSelectU.StateU &= ~0x00003f;
		compareSelectU.bit.bStateU3_1 = 1;
		RetState = StateU3_1;
	}
	else
	if(CP_MINUS_12_1_PIN_STATE == 1)
	{	
		compareSelectU.StateU &= ~0x00003f;
		compareSelectU.bit.bStateU_Minus12_1 = 1;
		RetState = StateU_Minus12_1;
	}		
	if((CP12_1_PIN_STATE == 0) && (CP9_1_PIN_STATE == 0) && (CP6_1_PIN_STATE == 0) && (CP3_1_PIN_STATE == 0))
	{	
		compareSelectU.StateU &= ~0x00003f;
		compareSelectU.bit.bStateU0_1 = 1;
		RetState = StateU0_1;
	}
	
	return RetState;
}
////////////////////////////////////////////////////////////////////////////
uint16_t getADC(uint16_t channel) 
{
  uint16_t tmp = 0;
 CLR_CE;                              // Select MCP3204 // сброс CS в ноль

 tmp = 0;
 uint16_t channel1=0;
 channel1=0b000001100000 | (channel << 2);
  SPI_ReadWriteByte(channel1);
  tmp = SPI_ReadWriteByte(0b0);

  SET_CE;
  return tmp;
}//~

float32_t temp = 0;
float voltPN  = 0;
float voltGN  = 0;
float AmperPh = 0;
float AmperN  = 0;
void ReadSensor()
{
	if(statADCBuffRefresh & ADCBuffRefresh)//0&1/////////////////
			{

				int ch_idx;


				for(ch_idx = 0; ch_idx < ZSEM_CHANNEL_NUM; ch_idx++)
				{

					CoeffFourie_float ft;
					CoeffFourie_float ft0;
					//
					ft = FFT20_float((short*)&ADC_Values1.data[ch_idx]);
					ft0 = FT_float((short*)&ADC_Values1.data[ch_idx],0);
					Value_vt1.KoefFourie[ch_idx].Re = ft.CoeffFourieA;
					Value_vt1.KoefFourie[ch_idx].Im = ft.CoeffFourieB;
					arm_sqrt_f32((float32_t)((ft.CoeffFourieA*ft.CoeffFourieA + ft.CoeffFourieB*ft.CoeffFourieB)* (float32_t)0.5),&temp);
					ADC_Values1.Ud_kodInt[ch_idx] = (uint32_t)temp;
					ADC_Values1.Ud_kodKonstInt[ch_idx] = (int16_t)ft0.CoeffFourieA;
					if(ch_idx == 4)
					{
						ADC_Values1.Ud_kodKonstInt[ch_idx] = 0;//V0;
					}
					statADCBuffRefresh = 0;
				}

				voltPN = (ADC_Values1.Ud_kodInt[0] * 0.385416667);//0.385416667       0.40625
				voltGN =  (ADC_Values1.Ud_kodInt[1] * 0.385416667);// * 0.195 * 10);
				AmperPh =  (ADC_Values1.Ud_kodInt[2] * 0.015285);// * 0.0303835 * 10);
				AmperN =  (ADC_Values1.Ud_kodInt[3] * 0.015285);
			}
	if(GPIOF->ODR & GPIO_PIN_4/*RESET_PILOT1*/)
		{
			ComparSelectU_Ch1();
			StateU_FA = ((GPIOE->IDR>>2)) & 0x1f ;
		}
}
void BaseWork(void)
{
		if(statADCBuffRefresh & ADCBuffRefresh)//0&1/////////////////
		{

			int ch_idx;


			for(ch_idx = 0; ch_idx < ZSEM_CHANNEL_NUM; ch_idx++)
			{

				CoeffFourie_float ft;
				CoeffFourie_float ft0;
				//
				ft = FFT20_float((short*)&ADC_Values1.data[ch_idx]);
				ft0 = FT_float((short*)&ADC_Values1.data[ch_idx],0);
				Value_vt1.KoefFourie[ch_idx].Re = ft.CoeffFourieA;
				Value_vt1.KoefFourie[ch_idx].Im = ft.CoeffFourieB;
				arm_sqrt_f32((float32_t)((ft.CoeffFourieA*ft.CoeffFourieA + ft.CoeffFourieB*ft.CoeffFourieB)* (float32_t)0.5),&temp);
				ADC_Values1.Ud_kodInt[ch_idx] = (uint32_t)temp;
				ADC_Values1.Ud_kodKonstInt[ch_idx] = (int16_t)ft0.CoeffFourieA;
				if(ch_idx == 4)
				{
					ADC_Values1.Ud_kodKonstInt[ch_idx] = 0;//V0;
				}
				statADCBuffRefresh = 0;
			}
			float voltPN  = 0;
			float voltGN  = 0;
			float AmperPh = 0;
			float AmperN  = 0;
			voltPN = (ADC_Values1.Ud_kodInt[0] * 0.385416667);//0.385416667       0.40625
			voltGN =  (ADC_Values1.Ud_kodInt[1] * 0.385416667);// * 0.195 * 10);
			AmperPh =  (ADC_Values1.Ud_kodInt[2] * 0.015285);// * 0.0303835 * 10);
			AmperN =  (ADC_Values1.Ud_kodInt[3] * 0.015285);
			uint16_t TempOkrug;
			TempOkrug = (uint16_t)temp;
			demofloat(voltPN,voltGN,AmperPh,AmperN);
			demoV0(U2Cod);
			masRezult +=TempOkrug;


		}

		if(GPIOF->ODR & GPIO_PIN_4/*RESET_PILOT1*/)
		{
			ComparSelectU_Ch1();
			StateU_FA = ((GPIOE->IDR>>2)) & 0x1f ;
		}

}
////////////////////////////////////////////////
void ReadADCValue(unsigned char comnum)
{
	uint8_t Buf[80];
	
 	memcpy(Buf,(unsigned char*)ADC_Values1.Ud_kodInt,9*2); 
	memcpy((void*)&Buf[18], (unsigned char*)ADC_Values1.Ud_kodKonstInt, 9*2);
// 	memcpy(&Buf[16],(unsigned char*)ADC_Values2.Ud_kodInt,8*2);

//	PackToHDLC(0, (uint8_t*)Buf ,36, cmReadADCValue, comnum);
}
/////////////////////////////////////////////////
void	ReadADCKoefFourie(uint8_t adr, unsigned char comnum)
{	
	uint8_t Buf[80];

	if(adr == 1)
	{
		//���1 ����1
		memcpy(Buf,(unsigned char*)&Value_vt1,64); 
	}
	else
	if(adr == 2)
	{
		//���2 ����1
		memcpy(Buf,(unsigned char*)&Value_vt2,64); 
	}
	else
	if(adr == 3)
	{
		//���1 ����2
//		memcpy(Buf,(unsigned char*)&Value_vt3,64); 
	}
	else
	if(adr == 4)
	{
		//���2 ����2
//		memcpy(Buf,(unsigned char*)&Value_vt4,64); 
	}
	
//		PackToHDLC(adr, (uint8_t*)Buf ,64, cmReadADCKoefAB, comnum);
}
///////////////////////////////////////////////
void ReadValue_vt1(unsigned char comnum)
{
//		uint8_t Buf[sizeof(Value_vt1)+20];
//	
//		memcpy(Buf,(unsigned char*)&Value_vt1, sizeof(Value_vt1)); 
//		PackToHDLC(0, (uint8_t*)Buf ,sizeof(Value_vt1), cmReadValue_vt1, comnum);
}
///////////////////////////////////////////////
void ReadValue_vt2(unsigned char comnum)
{
//		uint8_t Buf[sizeof(Value_vt2)+20];
//	
//		memcpy(Buf,(unsigned char*)&Value_vt2, sizeof(Value_vt2)); 
//		PackToHDLC(0, (uint8_t*)Buf ,sizeof(Value_vt2), cmReadValue_vt2, comnum);
}

