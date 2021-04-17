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
#include "DIO_Interface.h"
#include "sno.h"

void SetDAC(void);
u16 counter = 0;

int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC);

	GPIO_vidSetPortDirection( PORTA , PORT_LSB , GPIO_OUTPUT_2MHZ_PP);

	MSTK_vidInit();
	MSTK_vidSetIntervalPeriodic(125 , SetDAC);

	while(1)
	{

	}

	return 0;
}
void SetDAC(void)
{
	GPIO_vidSetPortValue(PORTA , PORT_LSB , sno_raw[counter]);
	counter++;
	if(counter == 49319)
	{
		counter = 0;
	}
}


