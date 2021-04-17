/*
 * RCC_Private.h
 *
 *  Created on: Jan 17, 2021
 *      Author: Heba Ramadan Taha
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/***************************************************************
#define RCC_BASE_ADD     (0X40021000)
#define RCC_CR           (*(volatile u32 *)(RCC_BASE_ADD + 0x00))
#define RCC_CFGR         (*(volatile u32 *)(RCC_BASE_ADD + 0x04))
#define RCC_CIR          (*(volatile u32 *)(RCC_BASE_ADD + 0x08))
#define RCC_APB2RSTR     (*(volatile u32 *)(RCC_BASE_ADD + 0x0C))
#define RCC_APB1RSTR     (*(volatile u32 *)(RCC_BASE_ADD + 0x10))
#define RCC_AHBENR       (*(volatile u32 *)(RCC_BASE_ADD + 0x14))
#define RCC_APB2ENR      (*(volatile u32 *)(RCC_BASE_ADD + 0x18))
#define RCC_APB1ENR      (*(volatile u32 *)(RCC_BASE_ADD + 0x1C))
#define RCC_BDCR         (*(volatile u32 *)(RCC_BASE_ADD + 0x20))
#define RCC_CSR          (*(volatile u32 *)(RCC_BASE_ADD + 0x24))
****************************************************************/

typedef struct
{
	volatile u32 RCC_CR      ;
	volatile u32 RCC_CFGR    ;
	volatile u32 RCC_CIR     ;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_AHBENR  ;
	volatile u32 RCC_APB2ENR ;
	volatile u32 RCC_APB1ENR ;
	volatile u32 RCC_BDCR    ;
	volatile u32 RCC_CSR     ;
}RCC;

#define PTR_RCC     ((RCC *)0X40021000)


/************************RCC_CR Register************************/
#define HSI_ON 						  0
#define RDY HSION					  1
#define HSE_ON						  16
#define HSE_RDY						  17
#define HSE_BYP						  18
#define CSS_ON						  19
#define PLL_ON						  24
#define PLL_RDY						  25



/************************RCC_CFGR Register************************/
#define SW0 						  0
#define SW1 						  1
#define PLL_SRC					      16
#define PLL_XTPRE					  17
#define PLLMUL					      18




/************************System Clock***************************/
#define RCC_HSE_CRYSTAL               0
#define RCC_HSE_RC                    1
#define RCC_HSI                       2
#define RCC_PLL                       3


/************************PLL_SOURRCE****************************/
#define PLL_HSI_DIVIDED_BY_2          0
#define PLL_HSE_DIVIDED_BY_2          1
#define PLL_HSI                       2



/*******************PLL Multiplication Factor*******************/
#define PLL_CLOCK_MULTIPLED_BY_2      0b0000
#define PLL_CLOCK_MULTIPLED_BY_3	  0b0001
#define PLL_CLOCK_MULTIPLED_BY_4      0b0010
#define PLL_CLOCK_MULTIPLED_BY_5      0b0011
#define PLL_CLOCK_MULTIPLED_BY_6      0b0100
#define PLL_CLOCK_MULTIPLED_BY_7      0b0101
#define PLL_CLOCK_MULTIPLED_BY_8      0b0110
#define PLL_CLOCK_MULTIPLED_BY_9      0b0111
#define PLL_CLOCK_MULTIPLED_BY_10     0b0000
#define PLL_CLOCK_MULTIPLED_BY_11     0b1001
#define PLL_CLOCK_MULTIPLED_BY_12     0b1010
#define PLL_CLOCK_MULTIPLED_BY_13     0b1011
#define PLL_CLOCK_MULTIPLED_BY_14     0b1100
#define PLL_CLOCK_MULTIPLED_BY_15     0b1101
#define PLL_CLOCK_MULTIPLED_BY_16     0b1110


/*******************RCC_Clock Security System******************/
#define RCC_CSS_ON_ENABLE              0
#define RCC_CSS_ON_DISABLE             1


#endif /* RCC_PRIVATE_H_ */
