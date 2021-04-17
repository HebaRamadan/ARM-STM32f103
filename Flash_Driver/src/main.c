/*
 * main.c
 *
 *  Created on: Feb 19, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "FPEC_Interface.h"

#define ADDRESS   (0x1FFFF804)

u16 arr[1] = {2} ;

int main(void)
{

	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC );
	RCC_vidEnableClock(RCC_APB2 , USART1_RCC);
	RCC_vidEnableClock(RCC_AHB  , FLITF_RCC );

	GPIO_vidSetPinDirection(PORTA , PIN9  , GPIO_OUTPUT_50MHZ_AF_PP );
	GPIO_vidSetPinDirection(PORTA , PIN10 , GPIO_INPUT_FLOATING     );

	GPIO_vidSetPinDirection(PORTA , PIN0  , GPIO_OUTPUT_50MHZ_PP    );

	MUSART1_vidInit();

	volatile u8 x = *((u8 *)ADDRESS);

	x = 5;

	*((u8 *)ADDRESS) = x;

	volatile u8 y = *((u8 *)ADDRESS);
	while(1)
	{
		//MUSART1_vidTransmitString("ON");

	}

	return 0;
}
