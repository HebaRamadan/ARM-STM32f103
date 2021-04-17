/*
 * LEDMAT_Program.c
 *
 *  Created on: Feb 4, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "DIO_Interface.h"
#include "SyStick_Interface.h"
#include "LEDMAT_Interface.h"
#include "LEDMAT_Private.h"
#include "LEDMAT_Config.h"

void LEDMRX_vidInit(void)
{
	/* Initiate ROWS and COL as OUTPUT*/
	GPIO_vidSetPortDirection( LEDMRX_ROW_PORT , LEDMRX_ROW_PIN , GPIO_OUTPUT_2MHZ_PP );
	GPIO_vidSetPortDirection( LEDMRX_COL_PORT , LEDMRX_COL_PIN , GPIO_OUTPUT_2MHZ_PP );

	GPIO_vidSetPortValue( LEDMRX_COL_PORT , LEDMRX_COL_PIN , 0xff );
	GPIO_vidSetPortValue( LEDMRX_ROW_PORT , LEDMRX_ROW_PIN , 0x00 );
}


void LEDMRX_vidDisplay( u8* ptr  , u8 NumOfPattern )
{
	GPIO_vidSetPortValue( LEDMRX_COL_PORT , LEDMRX_COL_PIN , 0xff );
	MSTK_vidSetBusyWait(1000);

    for(u8 j=0 ; j < 50; j++)
    {
    	for(u8 i = 0; i < NumOfPattern ; i++)
    	{
    		u8 COL_ENABLE = 0xff ;
    		GPIO_vidSetPortValue( LEDMRX_ROW_PORT , LEDMRX_ROW_PIN , ptr[i] );
    		CLR_BIT(COL_ENABLE , i);
    		GPIO_vidSetPortValue( LEDMRX_COL_PORT , LEDMRX_COL_PIN , COL_ENABLE );
    		MSTK_vidSetBusyWait(100);
    		GPIO_vidSetPortValue( LEDMRX_COL_PORT , LEDMRX_COL_PIN , 0xff );
    		MSTK_vidSetBusyWait(1000);

    	}
    }

}

void LEDMRX_vidCLRDisplay(void)
{
	GPIO_vidSetPortValue( LEDMRX_COL_PORT , LEDMRX_COL_PIN , 0xff );
}


