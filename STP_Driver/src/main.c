/*
 * main.c
 *
 *  Created on: Feb 9, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "SyStick_Interface.h"
#include "STP_Intrerface.h"


int main(void)
{
	RCC_vidInit();
	RCC_vidEnableClock( RCC_APB2 , GPIOA_RCC );

	MSTK_vidInit();
	STP_vidInit();

	while(1)
	{
		for(u8 i = 0 ; i < 8; i++)
		{
			u8 SendValue = 0;
			SendValue    |= ( 1 << i );
			STP_vidSendSynchronus(  SendValue , STP_IC1_ID );
			MSTK_vidSetBusyWait(100000);
		}

	}

	return 0;
}





