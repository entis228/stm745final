//BaseWork.h
#ifndef BASE_WORK_H
#define BASE_WORK_H


float voltPN;
float voltGN;
float AmperPh;
float AmperN;
void BaseWork(void);
void ReadSensor();
void ReadADCValue(unsigned char comnum);
void ReadValue_vt1(unsigned char comnum);
void ReadValue_vt2(unsigned char comnum);
void	ReadADCKoefFourie(unsigned char adr, unsigned char comnum);
#endif
#include "stm32f7xx_hal.h"
uint16_t getADC(uint16_t channel);
