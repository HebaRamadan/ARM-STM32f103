/*
 * RCC_Config.h
 *
 *  Created on: Jan 17, 2021
 *      Author: Heba Ramadan Taha
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* RCC Can be :
 *              1- RCC_HSE_CRYSTAL
 *              2- RCC_HSE_RC
 *              3- RCC_HSI
 *              4- RCC_PLL
 * EX: RCC_CLOCK_TYPE    RCC_HSE_RC
 * */

#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


#if RCC_CLOCK_TYPE  ==   RCC_PLL

   /* PLL Input  Can be :
	*              1- PLL_HSI_DIVIDED_BY_2
	*              2- PLL_HSE_DIVIDED_BY_2
	*              3- PLL_HSE
	*
 	* EX: RCC_PLL_INPUT    PLL_HSI_DIVIDED_BY_2
 	**/

	#define RCC_PLL_INPUT    PLL_HSE_DIVIDED_BY_2

   /* PLL Multiplication Factor  Can be :
	*              1 - PLL_CLOCK_MULTIPLED_BY_2
	*              2 - PLL_CLOCK_MULTIPLED_BY_3
	*              3 - PLL_CLOCK_MULTIPLED_BY_4
	*              4 - PLL_CLOCK_MULTIPLED_BY_5
	*              5 - PLL_CLOCK_MULTIPLED_BY_6
	*              6 - PLL_CLOCK_MULTIPLED_BY_7
	*              7 - PLL_CLOCK_MULTIPLED_BY_8
	*              8 - PLL_CLOCK_MULTIPLED_BY_9
	*              9 - PLL_CLOCK_MULTIPLED_BY_10
	*              10- PLL_CLOCK_MULTIPLED_BY_11
	*              11- PLL_CLOCK_MULTIPLED_BY_12
	*              12- PLL_CLOCK_MULTIPLED_BY_13
	*              13- PLL_CLOCK_MULTIPLED_BY_14
	*			   14- PLL_CLOCK_MULTIPLED_BY_15
	*			   15- PLL_CLOCK_MULTIPLED_BY_16
	*
 	* EX: RCC_PLL_FACTOR    PLL_CLOCK_MULTIPLED_BY_8
 	**/
	#define RCC_PLL_FACTOR    PLL_CLOCK_MULTIPLED_BY_2
#endif


#endif /* RCC_CONFIG_H_ */
