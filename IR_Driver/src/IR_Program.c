/*
 * IR_Program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Heba Ramadan
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "SyStick_Interface.h"

#include "IR_Interface.h"
#include "IR_Private.h"
#include "IR_Config.h"

volatile u8 BUTTON = 0xFF;

static volatile u8  flag    =  0 ;
static volatile u32 arr[50] = {0};
volatile u8  counter =  0 ;

volatile u8  data    = 0xff;

static void CallBackFunction_ExtI   (void);
static void CallBackFunction_Systick(void);

void IR_vidInit(void)
{
	GPIO_vidSetPinDirection( IR_PORT , IR_PIN  , GPIO_INPUT_FLOATING);

	MEXTI0_vidSetCallBack(CallBackFunction_ExtI);

	MNVIC_vidInit();
	MEXTI_vidInit();

	MEXTI_vidEnableEXTILine( MEXTI_LINE0 );

	MNVIC_vidEnableInterrupt(EXTI0);
}



static void IR_GetButtonValue(void)
{
	if( data != 0xff)
	{
		for(volatile u8 i = 0; i < 21; i++)
		{
			if( ButtonValue[i] == data)
			{
				BUTTON    = i ;
				data      = 0xff ;

			}

		}

	}
}


static void CallBackFunction_ExtI(void)
{
	if( flag == 0 )
	{
		MSTK_vidSetIntervalSingle( 1000000 , CallBackFunction_Systick );
		flag = 1;
	}
	else
	{
		arr[counter] = MSTK_u32GetElapsed();
		counter++;
		MSTK_vidSetIntervalSingle( 1000000 , CallBackFunction_Systick );
	}


}

static void CallBackFunction_Systick(void)
{
	u8 x = 0;

	for( u8 i=0; i<8; i++)
	{
		if( (arr[17+i] > 2200) && (arr[17+i] < 2300) )
		{
			SET_BIT( x , i);
		}
		else
		{
			CLR_BIT( x , i);
		}
	}
	data    = x ;
	flag    = 0 ;
	arr[0]  = 0 ;
	counter = 0 ;

	IR_GetButtonValue();
}

