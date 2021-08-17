//FT_float.c
#include "FT_float.h"
#include <math.h>


float coskoefFT[20] = { 0.0999999, 0.09510565, 0.080901, 0.058778, 0.0309, 0.,
												-0.0309, -0.058778, -0.080901, -0.09510565, -0.0999999,
                        -0.09510565, -0.080901, -0.058778, -0.0309, 0.,
                         0.0309, 0.058778, 0.080901,0.09510565};
float sinkoefFT[20] = { 0., 0.0309, 0.058778, 0.080901,0.09510565, 0.0999999, 
												0.09510565, 0.080901, 0.058778, 0.0309, 0.,
												-0.0309, -0.058778, -0.080901, -0.09510565, -0.0999999,
                        -0.09510565, -0.080901, -0.058778, -0.0309 };
        
float KoefSin[5] = { 0.0309,
                     0.058778,
                     0.080901,     
		                 0.09510565,   
		                 0.0999999     
                        };

//---------------------------------------------------------------------------
//Функция быстрого преобразования Фурье по 20 выборкам.
CoeffFourie_float FFT20_float(short *InZn)
{
   CoeffFourie_float st;
 	 register float Re = 0;
   register float Im = 0;

   Re = (InZn[4] - InZn[14]) * KoefSin[4];
   Im = (InZn[19] - InZn[9]) * KoefSin[4];

   Re += ((InZn[0] - InZn[10]) + (InZn[8] - InZn[18]))* KoefSin[0];
   Im += ((InZn[0] - InZn[10]) - (InZn[8] - InZn[18]))* KoefSin[3];
   Re += ((InZn[1] - InZn[11]) + (InZn[7] - InZn[17]))* KoefSin[1];
   Im += ((InZn[1] - InZn[11]) - (InZn[7] - InZn[17]))* KoefSin[2];
   Re += ((InZn[2] - InZn[12]) + (InZn[6] - InZn[16]))* KoefSin[2];
   Im += ((InZn[2] - InZn[12]) - (InZn[6] - InZn[16]))* KoefSin[1];
   Re += ((InZn[3] - InZn[13]) + (InZn[5] - InZn[15]))* KoefSin[3];
   Im += ((InZn[3] - InZn[13]) - (InZn[5] - InZn[15]))* KoefSin[0];

   st.CoeffFourieA = Re;
   st.CoeffFourieB = Im;

   return st;
}
///////////////////////////////////////////////////////////////////////
//Функция дискретного преобразования Фурье по 20 выборкам.

CoeffFourie_float FT_float(short *MasIn, unsigned char Garmonic)
{
   unsigned char i = 0;
   CoeffFourie_float st;
   register float A;
   register float B;

   A = 0;
   B = 0;
   if(Garmonic == 1)
   {
	   	for(i = 0; i < 20; i++)
   		{
      	A += ((MasIn[i])*coskoefFT[i]);
      	B -= ((MasIn[i])*sinkoefFT[i]);
   		}
		st.CoeffFourieA = A;
    st.CoeffFourieB = B;
   }
   else
   if(Garmonic == 0)
   { 
	   	for(i = 0; i < 20; i++)
   		{
      		A += MasIn[i];
    	}  
			st.CoeffFourieA = A;
			st.CoeffFourieB = B; 
   }


   return st;
}  
/////////////////////////////////////////////////////////////////////////
//Функция вычисления корня квадратного из целого числа c округлением
//Время выполнения ~ 2 мкс
unsigned int SquareRootRounded(unsigned int a_nInput)
{
    unsigned int op  = a_nInput;
    unsigned int res = 0;
    unsigned int one = 1uL << 30; // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for uint32_t type


    // "one" starts at the highest power of four <= than the argument.
    while (one > op)
    {
        one >>= 2;
    }

    while (one != 0)
    {
        if (op >= res + one)
        {
            op = op - (res + one);
            res = res +  2 * one;
        }
        res >>= 1;
        one >>= 2;
    }

    /* Do arithmetic rounding to nearest integer */
    if (op > res)
    {
        res++;
    }

    return res;
}
