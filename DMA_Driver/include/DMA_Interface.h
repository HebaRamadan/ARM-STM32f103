/*
 * DMA_Interface.h
 *
 *  Created on: Feb 1, 2021
 *      Author: zas
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void MDMA_vidChannelInit(void);
void MDMA_vidChannelStart( u32* Copy_u32SourceAdress , u32* Copy_u32Destination , u16 Copy_u16BlockSize);



#endif /* DMA_INTERFACE_H_ */
