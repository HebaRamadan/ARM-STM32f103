/*
 * main.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Heba Ramadan Taha
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "NVIC_Interface.h"
#include "SyStick_Interface.h"

void CallBack_function(void);

u8 Counter = 45;

int main(void)
{

	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC );
	RCC_vidEnableClock(RCC_APB2 , USART1_RCC);

	GPIO_vidSetPinDirection(PORTA , PIN9  , GPIO_OUTPUT_50MHZ_AF_PP );
	GPIO_vidSetPinDirection(PORTA , PIN10 , GPIO_INPUT_FLOATING    );

	GPIO_vidSetPinDirection(PORTA , PIN0  , GPIO_OUTPUT_50MHZ_PP   );

	MUSART1_vidSetCallBack(CallBack_function);
	MNVIC_vidEnableInterrupt(37);

	MUSART1_vidInit();
	MNVIC_vidInit();
	MSTK_vidInit();

	MUSART1_vidTransmitString((u8 *)"GGGGGGGG");
	MUSART1_vidTransmitChar( (Counter/10) + '0');
	MUSART1_vidTransmitChar( (Counter%10) + '0');

	while(1);

	return 0;
}

void CallBack_function(void)
{
	u8 data = 0;
	data = MUSART1_u8ReceiveChar();

	if(data == 'n')
	{
		GPIO_vidSetPinValue(PORTA , PIN0 , GPIO_u8HIGH);
		MUSART1_vidTransmitString( (u8 *)"LED_ON" );
		MUSART1_vidNewLine();

	}
	if(data == 'f')
	{
		GPIO_vidSetPinValue(PORTA , PIN0 , GPIO_u8LOW);
		MUSART1_vidTransmitString( (u8 *)"LED_OFF" );
		MUSART1_vidNewLine();

	}
	else if(data == 'b')
	{
		MUSART1_vidTransmitString((u8 *)"LED_BLINK");
		MUSART1_vidNewLine();
		for(volatile u16 i= 0; i<10; i++)
		{
			GPIO_vidSetPinValue(PORTA , PIN0 , GPIO_u8HIGH);
			MSTK_vidSetBusyWait(100000);
			GPIO_vidSetPinValue(PORTA , PIN0 , GPIO_u8LOW);
			MSTK_vidSetBusyWait(100000);
		}


	}

}


