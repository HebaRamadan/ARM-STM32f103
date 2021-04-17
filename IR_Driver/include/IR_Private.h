/*
 * IR_Private.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Heba Ramadan
 */

#ifndef IR_PRIVATE_H_
#define IR_PRIVATE_H_

static void IR_GetButtonValue(void);

u8 ButtonValue[21] =

					{
					//  0  ,   1   ,  2    ,   3   ,  4   ,
					   22  ,   12  ,  24   ,   94  ,  8   ,

					// 5   ,   6   ,  7    ,   8   ,  9   ,
					   28  ,   90  ,  66   ,   82  ,  74  ,

					// OFF ,  MODE ,  NS   , PUASE ,  TL  ,
					   69  ,   70  ,  71   ,   68  ,  64  ,

					// TR  ,   EQ  ,  VOL- ,  VOL+ ,  RPT ,
					    67 ,    7  ,  43   ,   9   ,  25  ,

					// U/SD
						13
					};




#endif /* IR_PRIVATE_H_ */
