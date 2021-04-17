/*
 * LEDMAT_Interface.h
 *
 *  Created on: Feb 4, 2021
 *      Author: zas
 */

#ifndef LEDMAT_INTERFACE_H_
#define LEDMAT_INTERFACE_H_

void LEDMRX_vidInit   (void);

void LEDMRX_vidDisplay( u8* ptr  , u8 NumOfPattern );

void LEDMRX_vidCLRDisplay(void);



#endif /* LEDMAT_INTERFACE_H_ */
