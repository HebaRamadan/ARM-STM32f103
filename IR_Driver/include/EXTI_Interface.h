/*
 * EXTI_Interface.h
 *
 *  Created on: Jan 26, 2021
 *      Author: zas
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


void MEXTI_vidInit(void);
void MEXTI_vidEnableEXTILine(u8 Copy_u8EXTILine );
void MEXTI_vidDisableEXTILine(u8 Copy_u8EXTILine );
void MEXTI_vidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8SenseMode );

void MEXTI0_vidSetCallBack(void (*pf)(void) );
void MEXTI1_vidSetCallBack(void (*pf)(void) );

#define EXTI0    6
#define EXTI1    7

#define  MEXTI_LINE0           0
#define  MEXTI_LINE1           1
#define  MEXTI_LINE2           2
#define  MEXTI_LINE3           3
#define  MEXTI_LINE4           4
#define  MEXTI_LINE5           5
#define  MEXTI_LINE6           6
#define  MEXTI_LINE7           7
#define  MEXTI_LINE8           8
#define  MEXTI_LINE9           9
#define  MEXTI_LINE10          10
#define  MEXTI_LINE11          11
#define  MEXTI_LINE12          12
#define  MEXTI_LINE13          13
#define  MEXTI_LINE14          14
#define  MEXTI_LINE15          15


#define  MEXTI_RISINING        0
#define  MEXTI_FALLING         1
#define  MEXTI_IOC             2
#endif /* EXTI_INTERFACE_H_ */
