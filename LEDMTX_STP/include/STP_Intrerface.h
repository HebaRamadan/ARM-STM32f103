/*
 * STP_Intrerface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: zas
 */

#ifndef STP_INTRERFACE_H_
#define STP_INTRERFACE_H_


#define STP_IC1_ID         1
#define STP_IC2_ID         2


void STP_vidInit(void);
void STP_vidSendSynchronus    ( u8  Copy_u8DataToSend , u8 Copy_u8ID );
void STP_vidSendSynchronus2ICS( u16 Copy_u8DataToSend , u8 Copy_u8ID );

#endif /* STP_INTRERFACE_H_ */
