//Calc.h
#include "Data.h"

//////////////////////////////////////////////
//������ ��������� ����������  Uab � ���� Iab
ValueAB_float CalcUab(Vector_float A_U, Vector_float B_U, Vector_float A_I, Vector_float B_I);
//////////////////////////////////////////////
//������ ��������� ����������  Ubc � ���� Ibc
ValueBC_float CalcUbc(Vector_float B_U, Vector_float C_U, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//������ ��������� ����������  Uca � ���� Ica
ValueCA_float CalcUca(Vector_float C_U, Vector_float A_U, Vector_float C_I, Vector_float A_I);
//////////////////////////////////////////////
//������ ������������ ������������ 
//������� ������������������
ValueA0_float CalcA0(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//������ ������������ ������������ 
//������ ������������������
ValueA1_float CalcA1(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//������ ������������ ������������ 
//�������� ������������������
ValueA2_float CalcA2(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//������ ���������
//�������� �� ����� A, B, C
ValueSabc_float CalcSabc(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//������ ���������
//�������� ������������������� 0, 1, 2
ValueS012_float CalcS012(Vector_float vA0_U, Vector_float vA1_U, Vector_float vA2_U, Vector_float vA0_I, Vector_float vA1_I, Vector_float vA2_I);
//////////////////////////////////////////////
//������ ���������
//������ �������� 
ValueS_float CalcS(ValueSabc_float valSabc);
//////////////////////////////////////////////
//������ �������������
//������������� �� ����� AB
Vector_float CalcZab(ValueAB_float valAB);
//////////////////////////////////////////////
//������ �������������
//������������� �� ����� BC
Vector_float CalcZbc(ValueBC_float valBC);
//////////////////////////////////////////////
//������ �������������
//������������� �� ����� CA
Vector_float CalcZca(ValueCA_float valCA);
//////////////////////////////////////////////
//������ �������
ValueF CalcF(Vector_float A_U);
