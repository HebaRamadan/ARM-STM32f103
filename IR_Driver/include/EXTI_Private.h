/*
 * EXTI_Private.h
 *
 *  Created on: Jan 26, 2021
 *      Author: zas
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADD      0x40010400

typedef struct
{
	volatile u32 IMR  ;
	volatile u32 EMR  ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER;
	volatile u32 PR   ;

}EXTI_Type;


#define  EXTI            ((EXTI_Type *)(0x40010400))
#define  AFIO_EXTICR1   *((volatile u32 *)(0x40010008))



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

#endif /* EXTI_PRIVATE_H_ */
