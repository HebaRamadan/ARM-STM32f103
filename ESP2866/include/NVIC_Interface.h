/*
 * NVIC_Interface.h
 *
 *  Created on: Jan 26, 2021
 *      Author: Heba Ramadan Taha
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


void MNVIC_vidInit(void);
void MNVIC_vidSetPriority( u8 Copy_u8IntNumber , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group );
void MNVIC_vidEnableInterrupt ( u8 Copy_u8IntNumber );
void MNVIC_vidDisableInterrupt( u8 Copy_u8IntNumber );
void MNVIC_vidSetPendingFlag  ( u8 Copy_u8IntNumber );
void MNVIC_vidClrPendingFlag  ( u8 Copy_u8IntNumber );

u8   MNVIC_u8GetActiveFlag    ( u8 Copy_u8IntNumber );


#define NO_SUB_PRIORITY  0

#define MNVIC_GROUP4_SUB_0   0x05FA0300
#define MNVIC_GROUP3_SUB_1   0x05FA0400
#define MNVIC_GROUP2_SUB_2   0x05FA0500
#define MNVIC_GROUP1_SUB_3   0x05FA0600
#define MNVIC_GROUP0_SUB_4   0x05FA0700

#endif /* NVIC_INTERFACE_H_ */
