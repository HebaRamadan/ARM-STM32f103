/*
 * RCC_Program.c
 *
 *  Created on: Jan 17, 2021
 *      Author: Heba Ramadan Taha
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"


void RCC_vidInit(void)
{
	u32 LOC_u32TimeOut  = 0;

	PTR_RCC -> RCC_CR   = 0x00000080;
	PTR_RCC -> RCC_CFGR = 0x00000000;

	/* Select System Clock */
	#if   RCC_CLOCK_TYPE    ==  RCC_HSI

		/* HSI Selected As A System Clock By Default      */
		/* Enable The HSI Clock                           */
		SET_BIT(PTR_RCC -> RCC_CR , HSI_ON );

		/* Wait Till HSI Clock Is Stable                  */
		while( (GET_BIT( PTR_RCC -> RCC_CR , HSI_RDY) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{
			LOC_u32TimeOut++;
		}

	#elif RCC_CLOCK_TYPE    ==  RCC_HSE_CRYSTAL

		/* HSE Selected As A System Clock                */
		SET_BIT(PTR_RCC -> RCC_CFGR , SW0   );
		CLR_BIT(PTR_RCC -> RCC_CFGR , SW1   );

		/* Enable The HSE Clock                           */
		SET_BIT(PTR_RCC -> RCC_CR   , HSE_ON);

		/* Wait Till HSE Clock Is Stable                  */
		while( (GET_BIT( PTR_RCC -> RCC_CR , HSE_RDY) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{
			LOC_u32TimeOut++;
		}

	#elif RCC_CLOCK_TYPE  ==  RCC_HSE_RC

		/* HSE_RC(BYPASS) Selected As A System Clock      */
		SET_BIT(PTR_RCC -> RCC_CFGR , SW0    );
		CLR_BIT(PTR_RCC -> RCC_CFGR , SW1    );

		/* Enable The HSE Clock                           */
		SET_BIT(PTR_RCC -> RCC_CR   , HSE_ON );

		/* Enable The HSE_BYPASS Clock                    */
		SET_BIT(PTR_RCC -> RCC_CR   , HSE_BYP);

		/* Wait Till HSE Clock Is Stable                  */
		while( (GET_BIT( PTR_RCC -> RCC_CR , HSE_RDY) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{
			LOC_u32TimeOut++;
		}

	#elif RCC_CLOCK_TYPE  ==  RCC_PLL

		/* HSE_RC(BYPASS) Selected As A System Clock      */
		CLR_BIT(PTR_RCC -> RCC_CFGR , SW0    );
		SET_BIT(PTR_RCC -> RCC_CFGR , SW1    );

		/* Select PLL Multiplication Factor                */
		#if (RCC_PLL_FACTOR  >=  PLL_CLOCK_MULTIPLED_BY_2)  && (RCC_PLL_FACTOR  <=  PLL_CLOCK_MULTIPLED_BY_16)
			(PTR_RCC -> RCC_CFGR) |= (RCC_PLL_FACTOR << PLLMUL);

		#endif

		/* Select PLL Source                              */
		#if RCC_PLL_INPUT  ==  PLL_HSI_DIVIDED_BY_2

			/* Enable The HSI Clock                       */
			SET_BIT(PTR_RCC -> RCC_CR   , HSI_ON );

			/* The HSI Clock Divided By 2                  */
			CLR_BIT(PTR_RCC -> RCC_CFGR , PLL_SRC);


		#elif RCC_PLL_INPUT  ==  PLL_HSE

			/* Enable The HSE Clock                       */
			SET_BIT(PTR_RCC -> RCC_CR   , HSE_ON );

			/* The HSE Clock Source                       */
			SET_BIT(PTR_RCC -> RCC_CFGR , PLL_SRC);

			/* The HSE Clock Not Divided                  */
			CLR_BIT(PTR_RCC -> RCC_CFGR , PLL_XTPRE);


		#elif RCC_PLL_INPUT  ==  PLL_HSE_DIVIDED_BY_2

			/* Enable The HSE Clock                       */
			SET_BIT(PTR_RCC -> RCC_CR   , HSE_ON );

			/* The HSE Clock Source                       */
			SET_BIT(PTR_RCC -> RCC_CFGR , PLL_SRC);

			/* The HSE Clock Not Divided                  */
			SET_BIT(PTR_RCC -> RCC_CFGR , PLL_XTPRE);

		#endif


		/* Wait Till HSE Clock Is Stable                  */
		while( (GET_BIT( PTR_RCC -> RCC_CR , HSE_RDY) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{
			LOC_u32TimeOut++;
		}

	#endif

}

void RCC_vidEnableClock (u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	/* Enable RCC For Peripheral = Enable Peripheral Clock */
	/* Range Check                                         */
	if(Copy_u8PeripheralID < 32)
	{
		switch( Copy_u8BusID )
		{
			case RCC_AHB  :  SET_BIT( PTR_RCC -> RCC_AHBENR  , Copy_u8PeripheralID); break;
			case RCC_APB1 :  SET_BIT( PTR_RCC -> RCC_APB1ENR , Copy_u8PeripheralID); break;
			case RCC_APB2 :  SET_BIT( PTR_RCC -> RCC_APB2ENR , Copy_u8PeripheralID); break;
		}
	}
	else
	{
	}

}

void RCC_vidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	if(Copy_u8PeripheralID < 32)
	{
		switch( Copy_u8BusID )
		{
			case RCC_AHB  :  CLR_BIT( PTR_RCC -> RCC_AHBENR  , Copy_u8PeripheralID); break;
			case RCC_APB1 :  CLR_BIT( PTR_RCC -> RCC_APB1ENR , Copy_u8PeripheralID); break;
			case RCC_APB2 :  CLR_BIT( PTR_RCC -> RCC_APB2ENR , Copy_u8PeripheralID); break;
		}
	}
	else
	{

	}
}





