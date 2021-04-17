/*
 * main.c
 *
 *  Created on: Feb 1, 2021
 *      Author: zas
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "NVIC_Interface.h"
#include "DMA_Interface.h"
#include "DMA_Private.h"


u32 arr1[1000] ={0};
u32 arr2[1000] ={0};
u32 arr3[1000] ={0};
u32 arr4[1000] ;

int main(void)
{


	RCC_vidInit();
	RCC_vidEnableClock(RCC_AHB , DMA1_RCC);

	MNVIC_vidEnableInterrupt( 11 );

	MDMA_vidChannelInit();
	MDMA_vidChannelStart(arr1 , arr2 , 1000);

	for(u16 i=0; i<1000; i++)
	{
		arr4[i] = arr3[i];
	}

	while(1);


	return 0;

}

void DMA1_Channel1_IRQHandler(void)
{
	DMA -> DMA_IFCR = (1 << 0);
	DMA -> DMA_IFCR = (1 << 1);
}


