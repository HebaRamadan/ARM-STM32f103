/*
 * STP_Config.h
 *
 *  Created on: Feb 9, 2021
 *      Author: zas
 */

#ifndef STP_CONFIG_H_
#define STP_CONFIG_H_


/**************************************
 *Select State Of IC
 *ENABLE
 *DISABLE
 **************************************/

#define STP_IC1      ENABLE
#define STP_IC2      DISABLE

#if STP_IC1 == ENABLE

	#define STP_IC1_DATA_SERIAL      PORTA  ,  PIN0
	#define STP_IC1_SHIFT_CLK        PORTA  ,  PIN1
	#define STP_IC1_STORAGE_CLK      PORTA  ,  PIN2

#endif


#if STP_IC2 == ENABLE

	#define STP_IC2_DATA_SERIAL      PORTB  ,  PIN0
	#define STP_IC2_SHIFT_CLK        PORTB  ,  PIN1
	#define STP_IC2_STORAGE_CLK      PORTB  ,  PIN2

#endif

#endif /* STP_CONFIG_H_ */
