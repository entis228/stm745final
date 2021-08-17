//Calc.h
#include "Data.h"

//////////////////////////////////////////////
//Расчет линейного напряжения  Uab и тока Iab
ValueAB_float CalcUab(Vector_float A_U, Vector_float B_U, Vector_float A_I, Vector_float B_I);
//////////////////////////////////////////////
//Расчет линейного напряжения  Ubc и тока Ibc
ValueBC_float CalcUbc(Vector_float B_U, Vector_float C_U, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//Расчет линейного напряжения  Uca и тока Ica
ValueCA_float CalcUca(Vector_float C_U, Vector_float A_U, Vector_float C_I, Vector_float A_I);
//////////////////////////////////////////////
//Расчет симметричной составляющей 
//нулевая последовательность
ValueA0_float CalcA0(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//Расчет симметричной составляющей 
//Прямая последовательность
ValueA1_float CalcA1(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//Расчет симметричной составляющей 
//Обратная последовательность
ValueA2_float CalcA2(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//Расчет мощностей
//Мощность на фазах A, B, C
ValueSabc_float CalcSabc(Vector_float A_U, Vector_float B_U, Vector_float C_U, Vector_float A_I, Vector_float B_I, Vector_float C_I);
//////////////////////////////////////////////
//Расчет мощностей
//Мощность последовательностей 0, 1, 2
ValueS012_float CalcS012(Vector_float vA0_U, Vector_float vA1_U, Vector_float vA2_U, Vector_float vA0_I, Vector_float vA1_I, Vector_float vA2_I);
//////////////////////////////////////////////
//Расчет мощностей
//Полная мощность 
ValueS_float CalcS(ValueSabc_float valSabc);
//////////////////////////////////////////////
//Расчет сопротивлений
//Сопротивление на линии AB
Vector_float CalcZab(ValueAB_float valAB);
//////////////////////////////////////////////
//Расчет сопротивлений
//Сопротивление на линии BC
Vector_float CalcZbc(ValueBC_float valBC);
//////////////////////////////////////////////
//Расчет сопротивлений
//Сопротивление на линии CA
Vector_float CalcZca(ValueCA_float valCA);
//////////////////////////////////////////////
//Расчет частоты
ValueF CalcF(Vector_float A_U);
