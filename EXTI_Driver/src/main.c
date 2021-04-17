/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: zas
 */

#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"


void delay_1s( void );
void CallBackFunction0(void);
void CallBackFunction1(void);

int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , AFIO_RCC );
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC);
	RCC_vidEnableClock(RCC_APB2 , GPIOB_RCC);

	GPIO_vidSetPinDirection( PORTB , PIN0 , GPIO_INPUT_PULL_UD );
	GPIO_vidSetPinValue    ( PORTB , PIN0 , GPIO_u8HIGH        );


	GPIO_vidSetPinDirection( PORTA , PIN1 , GPIO_INPUT_PULL_UD );
	GPIO_vidSetPinValue    ( PORTA , PIN1 , GPIO_u8HIGH        );

	GPIO_vidSetPinDirection( PORTA , PIN3 , GPIO_OUTPUT_2MHZ_PP);
	GPIO_vidSetPinDirection( PORTA , PIN4 , GPIO_OUTPUT_2MHZ_PP);
	GPIO_vidSetPinDirection( PORTA , PIN5 , GPIO_OUTPUT_2MHZ_PP);

	MEXTI0_vidSetCallBack(CallBackFunction0);
	MEXTI1_vidSetCallBack(CallBackFunction1);

	MNVIC_vidInit();
	MEXTI_vidInit();

	MEXTI_vidEnableEXTILine( MEXTI_LINE0 );
	MEXTI_vidEnableEXTILine( MEXTI_LINE1 );

	MNVIC_vidSetPriority( 6  , 1 , 1 );
	MNVIC_vidSetPriority( 7  , 0 , 1 );

	MNVIC_vidEnableInterrupt(6);
	MNVIC_vidEnableInterrupt(7);

	while(1);

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

void CallBackFunction0(void)
{
	GPIO_vidTogglePin(PORTA , PIN3);
	delay_1s();
	delay_1s();
	delay_1s();
	MNVIC_vidSetPendingFlag(7);
	GPIO_vidTogglePin(PORTA , PIN4);
}

void CallBackFunction1(void)
{
	GPIO_vidTogglePin(PORTA , PIN5);
	delay_1s();
	delay_1s();
	delay_1s();
}
