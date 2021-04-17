/*
 *********** SevenSeg_Interface.h
 *********** Author			: 	Heba Ramadan Taha
 *********** Created on	:  29 / 11 / 2020
 *********** Version			:  1
 */
 
#include "Std_types.h"
#include "Bit_math.h"
#include "DIO_Interface.h"
#include "SevenSeg_Config.h"
#include "SevenSeg_Interface.h"



void SevenSeg_vidInit()
{
	
	GPIO_vidSetPortDirection( SEVENSEGMENT_PORT  ,  SEVENSEGMENT_PIN , GPIO_OUTPUT_10MHZ_PP );
	
}


void SevenSeg_vidTurnOff()
{
	#if  SEVENSEGMENT ==  COMMEN_ANODE
		GPIO_vidSetPortValue( SEVENSEGMENT_PORT  ,  SEVENSEGMENT_PIN   ,  0xFF	);
		
	#elif  SEVENSEGMENT ==  COMMEN_CATHOD
		GPIO_vidSetPortValue( SEVENSEGMENT_PORT  ,  SEVENSEGMENT_PIN   ,  0x00	);
		
	#endif
}


void SevenSeg_vidDisplayNum( u8 NUM)
{
	#if  SEVENSEGMENT ==  COMMEN_ANODE
		u8 Seg[10] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};
		
	#elif  SEVENSEGMENT ==  COMMEN_CATHOD
		u8 Seg[10] = { 0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111 };

	#endif
	
	u8 temp = Seg[NUM];
	GPIO_vidSetPortValue( SEVENSEGMENT_PORT  ,  SEVENSEGMENT_PIN   ,  temp	);
}
	
