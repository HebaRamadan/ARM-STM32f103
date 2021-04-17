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
#include "IR_Interface.h"


extern u8 BUTTON ;

u8 arr[8] = {0};
u8 Start_Arr[24] = { 38, 73, 50, 0, 1, 127, 1, 0, 126, 9, 9, 126, 0, 127, 25, 41, 70, 0, 1, 127, 1, 0, 0, 0 };


int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , AFIO_RCC);
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC);
	RCC_vidEnableClock(RCC_APB2 , GPIOB_RCC);

	/*LEDMRX_vidInit();*/
	MSTK_vidInit();
	//LEDMRX_vidInit();
	IR_vidInit();

	while(1)
	{


	}

	return 0;
}
