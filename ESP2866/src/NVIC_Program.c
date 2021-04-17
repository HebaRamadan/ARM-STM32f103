/*
 * NVIC_Program.c
 *
 *  Created on: Jan 26, 2021
 *      Author:Heba Ramadan Taha
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"


void MNVIC_vidInit(void)
{

	/*    Number Of Groups and Sub
    #ifndef SCB_AIRCR
	#define SCB_AIRCR   *((u32 *)(0xE000ED00 + 0x0C))
	#endif*/

	SCB->AIRCR = MNVIC_GROUPS_SUBS ;

}


void MNVIC_vidSetPriority( u8 Copy_u8IntNumber , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group )
{

	/* Range Check                       */
	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;

    //External Peripheral
	if( Copy_u8IntNumber < 0 ){

		MNVIC->IPR[ Copy_u8IntNumber ] = Priority << 4 ;

	}
	else
	{

	}

	SCB->AIRCR = Copy_u8Group ;
}

/*    Peripheral interrupt NVIC Enable   */
void MNVIC_vidEnableInterrupt(u8 Copy_u8IntNumber)
{

	/* Range Check                       */
	if( Copy_u8IntNumber < 60 )
	{
		MNVIC->ISER[ Copy_u8IntNumber / 32 ] = 1 << ( Copy_u8IntNumber % 32 ) ;
	}
	else
	{
		/* ERROR STATE */
	}
}


void MNVIC_vidDisableInterrupt(u8 Copy_u8IntNumber)
{

	/* Range Check                       */
	if( Copy_u8IntNumber < 60 )
	{
		MNVIC->ICER[ Copy_u8IntNumber / 32 ] = 1 << ( Copy_u8IntNumber % 32 ) ;
	}
	else
	{
		/* ERROR STATE */
	}

}


void MNVIC_vidSetPendingFlag(u8 Copy_u8IntNumber)
{
	/* Range Check                       */
	if( Copy_u8IntNumber < 60 )
	{
		MNVIC->ISPR[ Copy_u8IntNumber / 32 ] = 1 << ( Copy_u8IntNumber % 32 ) ;
	}
	else
	{
		/* ERROR STATE */
	}
}


void MNVIC_vidClrPendingFlag(u8 Copy_u8IntNumber)
{
	/* Range Check                       */
	if( Copy_u8IntNumber < 60 )
	{
		MNVIC->ICPR[ Copy_u8IntNumber / 32 ] = 1 << ( Copy_u8IntNumber % 32 ) ;
	}
	else
	{
		/* ERROR STATE */
	}
}


u8   MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{

	u8 Loc_u8ActiveValue = 0xff;

	/* Range Check                               */
	if( Copy_u8IntNumber < 32 )
	{
		Loc_u8ActiveValue = GET_BIT( (MNVIC->IAPR[ Copy_u8IntNumber/32 ]) , ( Copy_u8IntNumber % 32 ) );
	}
	else
	{
		/* return error state */
	}

	return Loc_u8ActiveValue;
}


/*
ErrorStatus  MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber , u8 Copy_PuActiveValue)
{
	return  ErrorStatus;
}
*/
