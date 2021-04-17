/*
 * DMA_Program.c
 *
 *  Created on: Feb 1, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "DMA_Interface.h"
#include "DMA_Private.h"
#include "DMA_Config.h"

void MDMA_vidChannelInit(void)
{
	#if CHANNEL_ID == CHANNEL_1
	DMA -> Channels[CHANNEL_ID].CCR = 0x00007AD3;
	#endif
}


void MDMA_vidChannelStart( u32* Copy_u32SourceAdress , u32* Copy_u32Destination , u16 Copy_u16BlockSize)
{
	CLR_BIT( DMA -> Channels[CHANNEL_ID].CCR , CHANNEL_ID );

	DMA -> Channels[CHANNEL_ID].CPAR  = (u32)Copy_u32SourceAdress;

	DMA -> Channels[CHANNEL_ID].CMAR  = (u32)Copy_u32Destination ;

	DMA -> Channels[CHANNEL_ID].CNDTR =      Copy_u16BlockSize   ;

}


