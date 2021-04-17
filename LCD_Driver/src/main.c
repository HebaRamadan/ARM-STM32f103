/*
 * main.c
 *
 *  Created on: Jan 23, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"

void delay_1s( void );


int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC);
	RCC_vidEnableClock(RCC_APB2 , GPIOB_RCC);
	RCC_vidEnableClock(RCC_APB2 , GPIOC_RCC);

	LCD_vidInit();



	while(1)
	{
		LCD_vidSendCommand(0x01);
		delay_1s();
		LCD_vidSendString("   The Gang   ");
		delay_1s();
		delay_1s();
		delay_1s();
		delay_1s();
		delay_1s();
		LCD_vidSendCommand(0x01);
		delay_1s();
		delay_1s();
		delay_1s();
		delay_1s();
		delay_1s();
		LCD_vidSendString("BootLoader");
		delay_1s();
		delay_1s();
		delay_1s();
		delay_1s();
		delay_1s();
	}


	return 0;
}

void delay_1s( void )
{
	for(u16 i=0; i<=660; i++)
	{
		for(u16 j=0; j<=660; j++)
		{
			asm("NOP");
		}
	}
}


