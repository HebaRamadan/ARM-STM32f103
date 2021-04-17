/*
 * main.c
 *
 *  Created on: Feb 4, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "LEDMAT_Interface.h"
#include "SyStick_Interface.h"


u8 arr[8] = {0};
u8 Start_Arr[24] = { 38, 73, 50, 0, 1, 127, 1, 0, 126, 9, 9, 126, 0, 127, 25, 41, 70, 0, 1, 127, 1, 0, 0, 0 };
u8 ArrayOfPattern[40] = {
		              	  56 , 36 , 50 , 42 , 50  , 32 , 184 , 32 ,
						  32 , 60 , 20 ,  8 ,  0  , 28 ,  32 , 64 ,
						  64 , 64 ,  0 , 48 ,  80 , 48 ,  32 , 56 ,
						  40 , 40 , 40 , 48 , 36  , 48 ,  32 , 62 ,
						  0  , 24 , 32 , 36 , 32  , 24 ,   0 ,  0
					 	};

/*u8 ArrayOfPattern_1[8]	= {0  , 0  ,  0 ,  0 ,  0 ,  0 ,  0  , 62 };
u8 ArrayOfPattern_2[8]	= {0  , 0  ,  0 ,  0 ,  0 ,  0 ,  62 ,  8 };
u8 ArrayOfPattern_3[8]	= {0  , 0  ,  0 ,  0 ,  0 , 62 ,  8  ,  8 };
u8 ArrayOfPattern_4[8]	= {0  , 0  ,  0 ,  0 , 62 ,  8 ,  8  ,  8 };
u8 ArrayOfPattern_5[8]	= {0  , 0  ,  0 , 62 ,  8 ,  8 ,  8  , 62 };
u8 ArrayOfPattern_6[8]	= {0  , 0  , 62 ,  8 ,  8 ,  8 ,  62 ,  0 };
u8 ArrayOfPattern_7[8]  = {0  , 62 ,  8 ,  8 ,  8 , 62 ,  0  ,  0 };
u8 ArrayOfPattern_8[8]  = {62 ,  8 ,  8 ,  8 , 62 ,  0 ,  0  ,  0 };
u8 ArrayOfPattern_9[8]	= {8  ,  8 ,  8 , 62 ,  0 ,  0 ,  0  ,  0 };
u8 ArrayOfPattern_10[8]	= {8  ,  8 , 62 ,  0 ,  0 ,  0 ,  0  ,  0 };
u8 ArrayOfPattern_11[8]	= {8  , 62 ,  0 ,  0 ,  0 ,  0 ,  0  ,  0 };
u8 ArrayOfPattern_12[8]	= {62 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0  ,  0 };*/

int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC);

	/*LEDMRX_vidInit();*/
	MSTK_vidInit();
	LEDMRX_vidInit();

	while(1)
	{
		for(u8 i = 0 ; i<40 ; i++)
		{
			for(u8 j=7 ; j>0 ; j--)
			{
				arr[j] = arr[j-1];
			}
			arr[0] = ArrayOfPattern[i];

			LEDMRX_vidDisplay( arr , 8);

		}


/*		for(u8 i = 0 ; i<40 ; i++)
		{
			for(u8 j=7 ; j>0 ; j--)
			{
				arr[j] = arr[j-1];
			}
			arr[0] = ArrayOfPattern[i];

			LEDMRX_vidDisplay( arr , 8);


		}*/


/*		LEDMRX_vidDisplay( ArrayOfPattern_1 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_2 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_3 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_4 , 8);
		delay();


		LEDMRX_vidDisplay( ArrayOfPattern_5 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_6 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_7 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_8 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_9 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_10 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_11 , 8);
		delay();

		LEDMRX_vidDisplay( ArrayOfPattern_12 , 8);
		delay();*/

	}

	return 0;
}
