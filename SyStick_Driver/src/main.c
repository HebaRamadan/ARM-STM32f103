/*
 * main.c
 *
 *  Created on: Feb 2, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO_Interface.h"
#include "RCC_Interface.h"
#include "SyStick_Interface.h"

void Function_Toggle(void);

int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC);

	GPIO_vidSetPinDirection( PORTA , PIN0 , GPIO_OUTPUT_2MHZ_PP);

	MSTK_vidInit();

	while(1)
	{
		GPIO_vidTogglePin( PORTA , PIN0 );
		MSTK_vidSetBusyWait(1000000);
	}

	return 0;
}

void Function_Toggle(void)
{
	GPIO_vidTogglePin( PORTA , PIN0 );
}


