/*
 * main.c
 *
 *  Created on: Feb 4, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"

#include "SyStick_Interface.h"
#include "IR_Interface.h"



extern u8 BUTTON ;





int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , AFIO_RCC);
	RCC_vidEnableClock(RCC_APB2 , GPIOB_RCC);

	/*LEDMRX_vidInit();*/
	MSTK_vidInit();
	IR_vidInit();




	while(1)
	{

	}

	return 0;
}

