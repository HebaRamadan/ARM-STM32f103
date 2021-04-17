/*
 * STP_Program.c
 *
 *  Created on: Feb 9, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO_Interface.h"
#include "SyStick_Interface.h"

#include "STP_Intrerface.h"
#include "STP_Private.h"
#include "STP_Config.h"



void STP_vidInit(void)
{
#if STP_IC1 == ENABLE
	GPIO_vidSetPinDirection( STP_IC1_DATA_SERIAL , GPIO_OUTPUT_2MHZ_PP );
	GPIO_vidSetPinDirection( STP_IC1_STORAGE_CLK , GPIO_OUTPUT_2MHZ_PP );
	GPIO_vidSetPinDirection( STP_IC1_SHIFT_CLK   , GPIO_OUTPUT_2MHZ_PP );
#endif

#if STP_IC2 == ENABLE
	GPIO_vidSetPinDirection( STP_IC2_DATA_SERIAL , GPIO_OUTPUT_2MHZ_PP );
	GPIO_vidSetPinDirection( STP_IC2_STORAGE_CLK , GPIO_OUTPUT_2MHZ_PP );
	GPIO_vidSetPinDirection( STP_IC2_SHIFT_CLK   , GPIO_OUTPUT_2MHZ_PP );
#endif

}


void STP_vidSendSynchronus( u8 Copy_u8DataToSend , u8 Copy_u8ID )
{
#if STP_IC1 == ENABLE
	if( Copy_u8ID == STP_IC1_ID )
	{
		for( u8 DataCounter = 8 ; DataCounter > 0 ; DataCounter-- )
		{
			u8 SendBit = GET_BIT(Copy_u8DataToSend   , (DataCounter-1) );
			GPIO_vidSetPinValue( STP_IC1_DATA_SERIAL ,   SendBit       );

			GPIO_vidSetPinValue( STP_IC1_SHIFT_CLK   , GPIO_u8HIGH);
			MSTK_vidSetBusyWait(1);
			GPIO_vidSetPinValue( STP_IC1_SHIFT_CLK   , GPIO_u8LOW );
			MSTK_vidSetBusyWait(1);
		}

		GPIO_vidSetPinValue( STP_IC1_STORAGE_CLK   , GPIO_u8HIGH);
		MSTK_vidSetBusyWait(1);
		GPIO_vidSetPinValue( STP_IC1_STORAGE_CLK   , GPIO_u8LOW );
		MSTK_vidSetBusyWait(1);
	}
#endif

#if STP_IC2 == ENABLE
	else if( Copy_u8ID == STP_IC2_ID )
	{
		for( u8 DataCounter = 8 ; DataCounter > 0 ; DataCounter-- )
		{
			u8 SendBit = GET_BIT(Copy_u8DataToSend   , (DataCounter-1) );
			GPIO_vidSetPinValue( STP_IC2_DATA_SERIAL ,   SendBit       );

			GPIO_vidSetPinValue( STP_IC2_SHIFT_CLK   , GPIO_u8HIGH);
			MSTK_vidSetBusyWait(1);
			GPIO_vidSetPinValue( STP_IC2_SHIFT_CLK   , GPIO_u8LOW );
			MSTK_vidSetBusyWait(1);
		}

		GPIO_vidSetPinValue( STP_IC2_STORAGE_CLK   , GPIO_u8HIGH);
		MSTK_vidSetBusyWait(1);
		GPIO_vidSetPinValue( STP_IC2_STORAGE_CLK   , GPIO_u8LOW );
		MSTK_vidSetBusyWait(1);
	}
#endif

}


void STP_vidSendSynchronus2ICS( u16 Copy_u8DataToSend , u8 Copy_u8ID )
{
#if STP_IC1 == ENABLE
	if( Copy_u8ID == STP_IC1_ID )
	{
		for( u8 DataCounter = 16 ; DataCounter > 0 ; DataCounter-- )
		{

			u8 SendBit = GET_BIT(Copy_u8DataToSend   , (DataCounter-1) );
			GPIO_vidSetPinValue( STP_IC1_DATA_SERIAL ,   SendBit       );

			GPIO_vidSetPinValue( STP_IC1_SHIFT_CLK   , GPIO_u8HIGH);
			MSTK_vidSetBusyWait(1);
			GPIO_vidSetPinValue( STP_IC1_SHIFT_CLK   , GPIO_u8LOW );
			MSTK_vidSetBusyWait(1);
		}

		GPIO_vidSetPinValue( STP_IC1_STORAGE_CLK   , GPIO_u8HIGH);
		MSTK_vidSetBusyWait(1);
		GPIO_vidSetPinValue( STP_IC1_STORAGE_CLK   , GPIO_u8LOW );
		MSTK_vidSetBusyWait(1);
	}
#endif

#if STP_IC2 == ENABLE
	else if( Copy_u8ID == STP_IC2_ID )
	{
		for( u8 DataCounter = 16 ; DataCounter > 0 ; DataCounter-- )
		{
			u8 SendBit = GET_BIT(Copy_u8DataToSend   , (DataCounter-1) );
			GPIO_vidSetPinValue( STP_IC2_DATA_SERIAL ,   SendBit       );

			GPIO_vidSetPinValue( STP_IC2_SHIFT_CLK   , GPIO_u8HIGH);
			MSTK_vidSetBusyWait(1);
			GPIO_vidSetPinValue( STP_IC2_SHIFT_CLK   , GPIO_u8LOW );
			MSTK_vidSetBusyWait(1);
		}

		GPIO_vidSetPinValue( STP_IC2_STORAGE_CLK   , GPIO_u8HIGH);
		MSTK_vidSetBusyWait(1);
		GPIO_vidSetPinValue( STP_IC2_STORAGE_CLK   , GPIO_u8LOW );
		MSTK_vidSetBusyWait(1);
	}
#endif

}
