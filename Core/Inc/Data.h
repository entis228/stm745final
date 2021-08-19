//Data.h
//------------------------------------------------------------------------------------
#ifndef __DATA_H
#define __DATA_H
#include "main.h"
#include <stdint.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------
#define ADCBuffRefresh	1
#define ZSEM_CHANNEL_NUM	4
//typedef struct _ADC_Buf_t {
//	volatile uint32_t	stat;
//	int16_t	data[ZSEM_CHANNEL_NUM];
//} ADC_Buf_t;

#define ADC_CH_BUF_LEN	20
//////////////////////////////////////////////////////////////////
//�������� ������������ ����
//////////////////////////////////////////////////////////////////
			typedef  struct {
						//////////////////////////////////////////
					//������ ����1
					//������� ���������
					 struct __packed{
						uint8_t stateTV : 1;
						uint8_t stateTOR : 1;
						uint8_t stateOR : 1;
						uint8_t reserve : 5;
					} StatePSTN;

					//������� �����������
					 struct __packed{
						uint16_t flash_OK : 1;
						uint16_t RAM_OK : 1;
						uint16_t ADC1_OK : 1;
						uint16_t ADC2_OK : 1;
						uint16_t RS485_OK : 1;
						uint16_t AdrRS_OK : 1;
						uint16_t BQ1_OK : 1;
						uint16_t CRC_OK : 1; //������� 
						uint16_t intADC_OK : 1; //2.5 V OK
						uint16_t extADC1_OK : 1; //2.5 V OK
						uint16_t extADC2_OK : 1; //2.5 V OK
						uint16_t extADC1_0_Ok : 1; //0 V OK
						uint16_t extADC2_0_Ok : 1;//0V OK
						uint16_t ref_OK : 1; //���� ���� �� ���� �� -> Ref OK
						uint16_t V_OK: 1;	//5� - ��
						uint16_t T_OK : 1; //����������� >110 �������� - ��������
					} DiagPSTN;
					
					//�������� ���� ������� 1�8 ��� 1, 1�8 ��� 2	
					 struct __packed {
						__IO int16_t IADC[14];
					} ValueADC_PSTN;

					//������������ ����������
					float k1[8];
					float k2[8];
					short b1[8];
					short b2[8];
			}	data_PSTN;
//----------------------------------------------------------------------------
typedef struct _I_PWM_Percent_vt {
	uint8_t I_PWM_FaseA;
	uint8_t I_PWM_FaseB;
	uint8_t I_PWM_FaseC;
} I_PWM_Percent_vt;
//----------------------------------------------------------------------------
typedef struct _ADC_Value_vt {
	unsigned short	Ud_kodInt[ZSEM_CHANNEL_NUM];		 //2*8=16//���������� ���� 1 ���������
	short	Ud_kodKonstInt[ZSEM_CHANNEL_NUM];		 //2*8=16//���������� ���� 1 ���������
	uint32_t	idx;
	short	data[ZSEM_CHANNEL_NUM][ADC_CH_BUF_LEN];
} ADC_Value_vt;
//----------------------------------------------------------------------------
typedef  struct
{
	float Re;
	float Im;
}Vector_float;
//----------------------------------------------------------------------------
typedef  struct
{
	float Re;
	float Im;
}VectorS_float;
//----------------------------------------------------------------------------
typedef  struct
{
	float   Uab;
	Vector_float vUab;//������ ��������� ���������� a b
	float   Iab;
	Vector_float vIab;//������ ��������� ���� b c

}ValueAB_float;
//----------------------------------------------------------------------------
typedef  struct
{
	float   Ubc;
	Vector_float vUbc;//������ ��������� ���������� b c
	float   Ibc;
	Vector_float vIbc;//������ ��������� ���� b c 

}ValueBC_float;
//----------------------------------------------------------------------------
typedef  struct
{
	float   Uca;
	Vector_float vUca;//������ ��������� ���������� c a
	float   Ica;
	Vector_float vIca;//������ ��������� ���� c a 
}ValueCA_float;
//----------------------------------------------------------------------------
typedef  struct
{
	Vector_float vU_A0;//������� ������������������ �� ����������
	Vector_float vI_A0;//������� ������������������ �� ����
}ValueA0_float;
//----------------------------------------------------------------------------
typedef  struct
{
	Vector_float vU_A1;//������ ������������������ �� ����������
	Vector_float vI_A1;//������ ������������������ �� ����
}ValueA1_float;
//----------------------------------------------------------------------------
typedef  struct
{
	Vector_float vU_A2;//������ ������������������ �� ����������
	Vector_float vI_A2;//������ ������������������ �� ����
}ValueA2_float;

//----------------------------------------------------------------------------
typedef  struct
{
	VectorS_float Sa; //�������� �� ���� A
	VectorS_float Sb; //�������� �� ���� B
	VectorS_float Sc; //�������� �� ���� C
}ValueSabc_float;
//----------------------------------------------------------------------------
typedef  struct
{
	VectorS_float S0; //�������� ������������������ 0 �������
	VectorS_float S1; //�������� ������������������ 1 ������
	VectorS_float S2; //�������� ������������������ 2 ��������
}ValueS012_float;
//----------------------------------------------------------------------------
typedef  struct
{
	VectorS_float S; //�������� ������
}ValueS_float;
//----------------------------------------------------------------------------
typedef  struct
{
	unsigned short FInt;  //�������
	unsigned short FFrac; //������� �������� ����� �������
	short AlfaNew;
	short AlfaOld;
	short DeltaAlfa;
}ValueF;

//----------------------------------------------------------------------------
typedef  struct _Param_Value_vt {
	Vector_float 		KoefFourie[8];//������������ ����� A � B �� ������� ������
	ValueAB_float 	valAB; //�������� ���������� AB
	ValueBC_float		valBC; //�������� ���������� BC
	ValueCA_float		valCA; //�������� ���������� CA
	ValueA0_float 	valA0; //������������ ������������ A0 - ������� ������������������
	ValueA1_float 	valA1; //������������ ������������ A1 - ������ ������������������
	ValueA2_float 	valA2; //������������ ������������ A2 - �������� ������������������
	ValueSabc_float 	valSabc; //������ ��������
	ValueS012_float 	valS012; //�������� �������������������
	ValueS_float 		valS; //������ ��������
	Vector_float 		valZab; //������������� �� ����� AB
	Vector_float 		valZbc;	//������������� �� ����� BC
	Vector_float 		valZca;	//������������� �� ����� CA
	ValueF      valF;   //�������
} Param_Value_vt;
//----------------------------------------------------------------------------
//typedef struct Tech_Read_t
//{
//	uint8_t SetTechnRead :1;
//	uint8_t TechnReadKoefKalibr :1;
//	uint8_t TechnReadRegConfig :1;
//	uint8_t ReadVersionSW :1;
//}Tech_Read;		

extern Param_Value_vt Value_vt1;
extern ADC_Value_vt ADC_Values1;
extern Param_Value_vt Value_vt2;
extern ADC_Value_vt ADC_Values2;
extern uint8_t statADCBuffRefresh;
extern uint16_t U1Cod;
extern uint16_t U2Cod;
extern uint16_t U3Cod;
extern uint16_t U4Cod;
extern I_PWM_Percent_vt I_PWM;

void EraseFlashSST25Init(void);
void WriteArhiveToFlash(uint8_t *dat, uint8_t cnt_bytes);


#endif
