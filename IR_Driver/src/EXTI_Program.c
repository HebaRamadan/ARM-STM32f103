/*
 * EXTI_Program.c
 *
 *  Created on: Jan 26, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

#define NULL    (void *)(0)

static  void(*EXTI0_CallBack)(void) = NULL ;
static  void(*EXTI1_CallBack)(void) = NULL ;

void MEXTI_vidInit(void)
{
	AFIO_EXTICR1 = 1;
	/* Disable All Interrupts     */
	EXTI -> IMR  = 0;

	/* Clear All Interrupts Flag  */
	EXTI -> PR   = 0Xffffffff;

   /*     SENSE MODE   */
	#if SENSE_MODE == MEXTI_RISING
		SET_BIT( EXTI -> RTSR  , MEXTI_LINE);

	#elif SENSE_MODE == MEXTI_FALLING
		SET_BIT( EXTI -> FTSR  , MEXTI_LINE);

	#elif SENSE_MODE == MEXTI_IOC
		SET_BIT( EXTI -> RTSR  , MEXTI_LINE);
		SET_BIT( EXTI -> FTSR  , MEXTI_LINE);

	#endif
}

void MEXTI_vidEnableEXTILine(u8 Copy_u8EXTILine )
{
	if( Copy_u8EXTILine < 16 )
	{
		SET_BIT( EXTI -> IMR , Copy_u8EXTILine );
	}
	else
	{
		/* ERROR STATE */
	}

}

void MEXTI_vidDisableEXTILine(u8 Copy_u8EXTILine )
{
	if( Copy_u8EXTILine < 16 )
	{
		CLR_BIT( EXTI -> IMR , Copy_u8EXTILine );
	}
	else
	{
		/* ERROR STATE */
	}

}

void MEXTI_vidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8SenseMode )
{
	switch( Copy_u8SenseMode )
	{
		case MEXTI_RISINING :	SET_BIT( EXTI -> RTSR  , Copy_u8EXTILine);
								CLR_BIT( EXTI -> FTSR  , Copy_u8EXTILine);	break;

		case MEXTI_FALLING  :	SET_BIT( EXTI -> FTSR  , Copy_u8EXTILine);
								CLR_BIT( EXTI -> RTSR  , Copy_u8EXTILine);	break;

		case MEXTI_IOC      :	SET_BIT( EXTI -> RTSR  , Copy_u8EXTILine);
								SET_BIT( EXTI -> FTSR  , Copy_u8EXTILine);	break;
	}
}

void MEXTI0_vidSetCallBack(void (*pf)(void) )
{
	if( pf != NULL )
	{
		EXTI0_CallBack = pf ;
	}
}

void MEXTI1_vidSetCallBack(void (*pf)(void) )
{
	if( pf != NULL )
	{
		EXTI1_CallBack = pf ;
	}
}



void EXTI0_IRQHandler(void)
{

	EXTI0_CallBack();
	SET_BIT( EXTI -> PR , 0);
}


void EXTI1_IRQHandler(void)
{

	EXTI1_CallBack();
	SET_BIT( EXTI -> PR , 1);
}


