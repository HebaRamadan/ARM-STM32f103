/*
 * main.c
 *
 *  Created on: Mar 12, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "NVIC_Interface.h"
#include "Timer_Interface.h"


void CallBackFunction1(void);
void CallBackFunction2(void);
void CallBackFunction3(void);

static u8 flag = 0;

int main(void)
{
	MRCC_vidInit();
	MRCC_vidEnablePeripheralClock( APB2_BUS , AFIO_RCC   );
	MRCC_vidEnablePeripheralClock( APB2_BUS , GPIOA_RCC  );
	MRCC_vidEnablePeripheralClock( APB2_BUS , GPIOB_RCC  );
	MRCC_vidEnablePeripheralClock( APB1_BUS , TIM4_RCC   );


	GPIO_vidSetPinDirection(PORTA , PIN0  , GPIO_OUTPUT_2MHZ_PP    );
	GPIO_vidSetPinDirection(PORTA , PIN1  , GPIO_OUTPUT_2MHZ_PP    );
	GPIO_vidSetPinDirection(PORTA , PIN2  , GPIO_OUTPUT_2MHZ_PP    );
	GPIO_vidSetPinDirection(PORTA , PIN3  , GPIO_OUTPUT_2MHZ_PP    );

	GPIO_vidSetPinDirection(PORTB , PIN7  , GPIO_INPUT_PULL_UD     );  //TIM4 CHANNEL_2 PIN
	GPIO_vidSetPinValue    (PORTB , PIN7  , GPIO_u8HIGH            );

	MTIMER_vidSetCallBackCMP(CallBackFunction1);
	MTIMER_vidSetCallBackOVF(CallBackFunction2);
	MTIMER_vidSetCallBackICP(CallBackFunction3);


	MNVIC_vidEnableInterrupt(30);
	MNVIC_vidInit();
	MTIMER_vidInit();

	while(1);
}


void CallBackFunction1(void)
{
	if( flag == 0 )
	{
		GPIO_vidSetPinValue(PORTA , PIN0 , GPIO_u8HIGH );
		GPIO_vidSetPinValue(PORTA , PIN1 , GPIO_u8LOW  );
		MTIMER_vidSetCompareReg( 40000 );

		flag = 1;
	}
	else
	{
		GPIO_vidSetPinValue(PORTA , PIN0 , GPIO_u8LOW );
		GPIO_vidSetPinValue(PORTA , PIN3 , GPIO_u8HIGH  );
		MTIMER_vidSetCompareReg( 20000 );
		flag = 0;
	}


}

void CallBackFunction2(void)
{
	GPIO_vidSetPinValue(PORTA , PIN3 , GPIO_u8LOW  );
	GPIO_vidSetPinValue(PORTA , PIN1 , GPIO_u8HIGH );

}
void CallBackFunction3(void)
{
	GPIO_vidTogglePin(PORTA , PIN2);
}


