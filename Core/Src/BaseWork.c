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
////  tmp = SPI_ReadWriteWord(0x18 | channel);                              // SPI communication using 8-bit segments
//////  channel = channel << 14;                        // Bits 7 & 6 define ADC input
////  tmp = SPI_ReadWriteWord(0);

	SPI_ReadWriteByte(0x6);                              // SPI communication using 8-bit segments
  channel = channel << 6;                        // Bits 7 & 6 define ADC input
	tmp = 0;
  tmp = SPI_ReadWriteByte(channel) & 0x0F;
  tmp = tmp << 8;                                // Get ADC value
  tmp |= SPI_ReadWriteByte(0);
  SET_CE;
  return tmp;
}//~

float32_t temp = 0;
void BaseWork(void)
{
		if(statADCBuffRefresh & ADCBuffRefresh)//0&1/////////////////
		{
//			uint16_t rezultOnDispley=0;
//			int last_idx;
			int ch_idx;
//
//			//SCB_CleanInvalidateDCache();
//			statADCBuffRefresh &= ~ADCBuffRefresh;
//			uint16_t ta=1000;
////
//			U1Cod = getADC(0);
//			U2Cod = getADC(1);
//			U3Cod = getADC(2);
//			U4Cod = getADC(3);
//
//			array_data.ValueADC_PSTN.IADC[0] = U1Cod - V0;
//			array_data.ValueADC_PSTN.IADC[1] = U2Cod - V0;
//			array_data.ValueADC_PSTN.IADC[2] = U3Cod - V0;
//			array_data.ValueADC_PSTN.IADC[3] = U4Cod - V0;
//
//			if(++ADC_Values1.idx == ADC_CH_BUF_LEN)
//			{
//				ADC_Values1.idx = 0;
//			}
//			last_idx = ADC_Values1.idx;

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
			}

//			ComparSelectU_Ch1();
//			ComparSelectU_Ch2();
//			ComparSelectU_Ch3();
//			StateU_FA = (uint16_t)((GPIOE->IDR>>2)) & 0x1f ;
//			StateU_FB = (uint16_t)((GPIOE->IDR>>7)) & 0x1f ;
//			StateU_FC = (uint16_t)((GPIOE->IDR>>12) & 0x1f) | ((uint32_t)(CP3_3_PIN_STATE & 0x1) << 4);
			float voltPN  = 0;
			float voltGN  = 0;
			float AmperPh = 0;
			float AmperN  = 0;
			voltPN = (ADC_Values1.Ud_kodInt[0] * 0.40625);
			voltGN =  (ADC_Values1.Ud_kodInt[1] * 0.40625);// * 0.195 * 10);
			AmperPh =  (ADC_Values1.Ud_kodInt[2] * 0.015285);// * 0.0303835 * 10);
			AmperN =  (ADC_Values1.Ud_kodInt[3] * 0.015285);
			uint16_t TempOkrug;
			TempOkrug = (uint16_t)temp;
			demofloat(voltPN,voltGN,AmperPh,AmperN);
			//demo(array_data.ValueADC_PSTN.IADC[0] ,array_data.ValueADC_PSTN.IADC[1],array_data.ValueADC_PSTN.IADC[2],array_data.ValueADC_PSTN.IADC[3]);
			masRezult +=TempOkrug;
			//masRezult +=array_data.ValueADC_PSTN.IADC[3];
			//k++;
//			if(k==100)
//				{k=0;
//				rezultOnDispley =masRezult / 100;
//				demo(array_data.ValueADC_PSTN.IADC[0] ,array_data.ValueADC_PSTN.IADC[1],array_data.ValueADC_PSTN.IADC[2],rezultOnDispley);
//				masRezult=0;
//				}
//			array_data.ValueADC_PSTN.IADC[4] =  (uint16_t)(ADC_Values1.Ud_kodInt[4] * 0.0303835 * 10);
//			array_data.ValueADC_PSTN.IADC[5] =  (uint16_t)(ADC_Values1.Ud_kodInt[5] * 0.0303835 * 10);
//			array_data.ValueADC_PSTN.IADC[6] =  (uint16_t)(ADC_Values1.Ud_kodInt[6] * 0.0303835 * 10);
//			array_data.ValueADC_PSTN.IADC[7] =  (uint16_t)(ADC_Values1.Ud_kodInt[7] * 0.0303835 * 10);
//			array_data.ValueADC_PSTN.IADC[8] =  (uint16_t)(ADC_Values1.Ud_kodInt[8] * 0.0303835 * 100);
//			array_data.name_param.data_PSTN[0].ValueADC_PSTN.IADC[9] =  (uint16_t)(ADC_Values1.Ud_kodInt[9] * 0.0303835 * 100);
//			array_data.name_param.data_PSTN[0].ValueADC_PSTN.IADC[10] =  (uint16_t)(ADC_Values1.Ud_kodInt[10] * 0.0303835 * 100);
//			array_data.name_param.data_PSTN[0].ValueADC_PSTN.IADC[11] =  (uint16_t)(ADC_Values1.Ud_kodInt[11] * (3.3/4096) * 100);

		}

		if(GPIOF->ODR & GPIO_PIN_4/*RESET_PILOT1*/)
		{
			ComparSelectU_Ch1();
			StateU_FA = ((GPIOE->IDR>>2)) & 0x1f ;
		}
//
//		if(GPIOF->ODR & GPIO_PIN_5/*RESET_PILOT2*/)
//		{
//			ComparSelectU_Ch2();
//			compareSelectU.StateU_FB = (~(GPIOE->IDR>>7)) & 0x1f ;
//		}

//		if(GPIOF->ODR & GPIO_PIN_6/*RESET_PILOT3*/)
//		{
//			ComparSelectU_Ch3();
//			compareSelectU.StateU_FC = (~(GPIOE->IDR>>12)) & 0x1f | ((uint32_t)(~CP3_3_PIN_STATE & 0x1) << 4);
//		}
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

