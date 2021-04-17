/*
 * main.c
 *
 *  Created on: Feb 24, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "NVIC_Interface.h"
#include "SyStick_Interface.h"
#include "ESP_Interface.h"

u8 * ptr;
u8 i = 0;

int main(void)
{

	RCC_vidInit();
	RCC_vidEnableClock(RCC_APB2 , GPIOA_RCC );
	RCC_vidEnableClock(RCC_APB2 , USART1_RCC);

	GPIO_vidSetPinDirection(PORTA , PIN9  , GPIO_OUTPUT_2MHZ_AF_PP );
	GPIO_vidSetPinDirection(PORTA , PIN10 , GPIO_INPUT_FLOATING    );

	GPIO_vidSetPinDirection(PORTA , PIN0  , GPIO_OUTPUT_2MHZ_PP   );

	MUSART1_vidInit();
	//MNVIC_vidInit();
	MSTK_vidInit();

	MNVIC_vidSetPriority( 37 , 1 , NO_SUB_PRIORITY , MNVIC_GROUP4_SUB_0 );
	MNVIC_vidEnableInterrupt(37);

	ESP_vidInit();
	ESP_vidConnectWiFi((u8 *)"mahmoud" , (u8 *)"Ramadan@1011");
	ESP_vidConnectServerTCP((u8 *)"162.253.155.226" , (u8 *)"80");
	ptr = ESP_vidGetFileFromServer((u8 *)"http://itiarm.freevar.com/hardware.txt");

	u8 i = 0;

	while(ptr[i] != ':')
	{
		i++;
	}
	if( ptr[i+2] == 'h')
	{
		GPIO_vidSetPinValue( PORTA , PIN0 , GPIO_u8HIGH );
	}
	while(1)
	{
		//GPIO_vidSetPinValue( PORTA , PIN0 , GPIO_u8HIGH );
	}

	return 0;
}

