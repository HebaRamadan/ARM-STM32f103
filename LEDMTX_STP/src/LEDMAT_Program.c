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
#include "STP_Intrerface.h"
#include "LEDMAT_Interface.h"
#include "LEDMAT_Private.h"
#include "LEDMAT_Config.h"

void LEDMRX_vidInit(void)
{
	/* Initiate ROWS and COL as OUTPUT*/
	STP_vidInit();
	STP_vidSendSynchronus2ICS( 0xff00  , STP_IC1_ID);

}


void LEDMRX_vidDisplay( u8* ptr  , u8 NumOfPattern )
{
	STP_vidSendSynchronus2ICS( 0xff00  , STP_IC1_ID);
	MSTK_vidSetBusyWait(1000);

    for(u8 j=0 ; j < 20; j++)
    {
    	for(u8 i = 0; i < NumOfPattern ; i++)
    	{

    		u8 COL_ENABLE = 0xff ;
    		u16 SendData  = 0    ;

    		CLR_BIT(COL_ENABLE , i);
    		SendData = (COL_ENABLE << 8) | ptr[i] ;
    		STP_vidSendSynchronus2ICS( SendData  , STP_IC1_ID);
    		MSTK_vidSetBusyWait(100);
    		STP_vidSendSynchronus2ICS( 0xff00  , STP_IC1_ID);


    	}
    }

}

void LEDMRX_vidCLRDisplay(void)
{
	GPIO_vidSetPortValue( LEDMRX_COL_PORT , LEDMRX_COL_PIN , 0xff );
}


