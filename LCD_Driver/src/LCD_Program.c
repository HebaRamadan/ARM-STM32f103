/*
 * LCD_Program.c
 *
 *  Created on: Nov 30, 2020
 *      Author: Heba Ramadan
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"


void LCD_vidInit(void)
{

	GPIO_vidSetPortDirection(Data_Port   , Data_Pin , GPIO_OUTPUT_10MHZ_PP);

	GPIO_vidSetPinDirection(Control_Port , RS , GPIO_OUTPUT_10MHZ_PP);  //RS
	GPIO_vidSetPinDirection(Control_Port , RW , GPIO_OUTPUT_10MHZ_PP);  //RW
	GPIO_vidSetPinDirection(Control_Port , EN , GPIO_OUTPUT_10MHZ_PP);	//EN


	LCD_vidSendCommand( FUNCTION_SET   );

	LCD_vidSendCommand( DISPLAY_ON_LCD );

	LCD_vidSendCommand( CLEAR_DISPLAY  );


}

void LCD_vidSendCommand(u8 Cmd)
{

	GPIO_vidSetPinValue(Control_Port , RS , GPIO_u8LOW);
	GPIO_vidSetPinValue(Control_Port , RW , GPIO_u8LOW);

	GPIO_vidSetPortValue(Data_Port   , Data_Pin , Cmd );


	GPIO_vidSetPinValue(Control_Port , EN , GPIO_u8HIGH);

	for(u8 i=0; i<200; i++)
	{
		for(u8 i=0; i<200; i++)
		{
			asm("NOP");
		}
	}

	GPIO_vidSetPinValue(Control_Port , EN , GPIO_u8LOW);


}

void LCD_vidSendData(u8 Char)
{
	GPIO_vidSetPinValue(Control_Port , RS , GPIO_u8HIGH);
	GPIO_vidSetPinValue(Control_Port , RW , GPIO_u8LOW );


	GPIO_vidSetPortValue(Data_Port   , Data_Pin , Char );


	GPIO_vidSetPinValue(Control_Port , EN , GPIO_u8HIGH);

	for(u8 i=0; i<50; i++)
	{
		for(u8 i=0; i<50; i++)
		{
			asm("NOP");
		}
	}

	GPIO_vidSetPinValue(Control_Port , EN , GPIO_u8LOW);

}

void LCD_vidSendString(u8 * Str)
{
	u8 i =0;
	while(Str[i] !=  '\0' )
	{
		LCD_vidSendData(Str[i]);
		i++;
	}
}

void LCD_vidWriteNumber(u16 Number)
{
	u16 Rev = 1;
	do
	{
		Rev    = (Rev * 10) + (Number % 10);
		Number =  Number / 10;

	}while(Number != 0);


	while( (Rev / 10) != 0)
	{
		LCD_vidSendData((Rev % 10) + '0');
		Rev = Rev / 10 ;
	}

}

void LCD_vidSavePattern(u8 *Pattern , u8 Pattern_Adress)
{
	u8 CGRAM_Adress;

	if(Pattern_Adress < 8)
	{
		CGRAM_Adress = Pattern_Adress * 8;

		SET_BIT(CGRAM_Adress , 6);          //Move AC To CGRAM
		LCD_vidSendCommand(CGRAM_Adress);

		for(u8 i=0; i<8; i++)
		{
			LCD_vidSendData(Pattern[i]);
		}
	}

	//LCD_vidSendCommand(LCD_u8CMD_RETURN_AC);    //Move AC to DDRAM
}

/*void LCDC_vidClearScreen(void)
{
	//LCD_vidSendCommand( LCD_u8CMD_CLR_Display  );
	_delay_ms(1);
}*/

void Lcd_vidSetPosition(u8 Row , u8 Col)
{
	if(Row == 0)
	{
		LCD_vidSendCommand(128 + Col);
	}
	else if(Row == 1)
	{
		LCD_vidSendCommand(128 + 64 + Col);
	}
}



