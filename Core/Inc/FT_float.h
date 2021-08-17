//FT_float.h
#ifndef __FT_FLOAT_H
#define __FT_FLOAT_H

typedef  struct
{
	float CoeffFourieA;
	float CoeffFourieB;
}CoeffFourie_float;

CoeffFourie_float FFT20_float(short *InZn);
CoeffFourie_float FT_float(short *MasIn, unsigned char Garmonic);
unsigned int SquareRootRounded(unsigned int a_nInput);

#endif
