/*
 * DMA_Private.h
 *
 *  Created on: Feb 1, 2021
 *      Author: zas
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{
	volatile u32 CCR  ;
	volatile u32 CNDTR;
	volatile u32 CPAR ;
	volatile u32 CMAR ;
	volatile u32 Reserved;
}DMA_channel;


typedef struct
{
	volatile u32 DMA_ISR ;
	volatile u32 DMA_IFCR;
	DMA_channel  Channels[7];
}DMA_t;

#define DMA  ((DMA_t*)(0x40020000))

#endif /* DMA_PRIVATE_H_ */
