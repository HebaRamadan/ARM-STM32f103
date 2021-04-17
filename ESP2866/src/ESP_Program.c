/*
 * ESP_Program.c
 *
 *  Created on: Feb 24, 2021
 *      Author: Heba Ramadan Taha
 */
#include "Std_types.h"
#include "Bit_math.h"

#include "UART_Interface.h"
#include "SyStick_Interface.h"
#include "ESP_Interface.h"
#include "ESP_Config.h"
#include "ESP_Private.h"


static u8  DataBuffer[255] = {0};
static u16 Counter = 0;


void MUSART1_CallBackFunction(void)
{
	u8 data = MUSART1_u8ReceiveChar();

	DataBuffer[Counter] = data;
	Counter++;
	MUSART1_vidClearFlag();
}

void ESP_vidInit(void)
{
	MUSART1_vidSetCallBack(MUSART1_CallBackFunction);

	ESP_vidClearBuffer();
	MUSART1_vidTransmitString( (u8 *)"AT+RST\r\n" );
	MSTK_vidSetBusyWait(2000000);

	do
	{
		ESP_vidClearBuffer();
		MUSART1_vidTransmitString( (u8 *)"ATE0\r\n" );
		MSTK_vidSetBusyWait(2000000);
	}while( (DataBuffer[Counter - 4] != 'O')  &&  (DataBuffer[Counter - 3] != 'K') );


	do
	{
		ESP_vidClearBuffer();
		MUSART1_vidTransmitString((u8 *)"AT+CWMODE=1\r\n");
		MSTK_vidSetBusyWait(2000000);
	}while( (DataBuffer[Counter - 4] != 'O')  &&  (DataBuffer[Counter - 3] != 'K')  );

}


void ESP_vidConnectWiFi( u8* Copy_u8Name  ,  u8* Copy_u8Pasword    )
{

	ESP_vidClearBuffer();
	MUSART1_vidTransmitString( (u8 *)"AT+CWJAP_CUR=\"" );
	MUSART1_vidTransmitString( (u8 *)Copy_u8Name       );
	MUSART1_vidTransmitString( (u8 *)"\",\""           );
	MUSART1_vidTransmitString( (u8 *)Copy_u8Pasword    );
	MUSART1_vidTransmitString( (u8 *)"\"\r\n"          );
	MSTK_vidSetBusyWait(5000000);
	MSTK_vidSetBusyWait(5000000);


}


void ESP_vidConnectServerTCP ( u8 * Copy_u8ServerIP , u8 * Copy_u8Port )
{

	ESP_vidClearBuffer();
	MUSART1_vidTransmitString((u8 *) "AT+CIPSTART=\"TCP\",\"");
	MUSART1_vidTransmitString((u8 *)  Copy_u8ServerIP        );
	MUSART1_vidTransmitString((u8 *)  "\","                  );
	MUSART1_vidTransmitString((u8 *)  Copy_u8Port            );
	MUSART1_vidTransmitString((u8 *)  "\r\n"                 );
	MSTK_vidSetBusyWait(2000000);


}


u8 * ESP_vidGetFileFromServer( u8* Copy_u8FilePath )
{
	/* FilePath >>> http://itiarm.freevar.com/DIO_Driver.txt */
	/*u8 i    = 0;
	u8 Size = 0;
	while( Copy_u8FilePath[i] != '\0')
	{
		i++;
	}
	Size = i + 6 ;*/
	MUSART1_vidTransmitString((u8 *)"AT+CIPSEND=44\r\n");
	/*MUSART1_vidTransmitChar((Size /10) + '0');
	MUSART1_vidTransmitChar((Size %10) + '0');
	MUSART1_vidTransmitString((u8 *)"\r\n");*/
	MSTK_vidSetBusyWait(2000000);
	ESP_vidClearBuffer();

	MUSART1_vidTransmitString((u8 *)"GET http://itiarm.freevar.com/hardware.txt\r\n");
	//MUSART1_vidTransmitString((u8 *) Copy_u8FilePath);
	//MUSART1_vidTransmitString((u8 *)"\r\n");

	MSTK_vidSetBusyWait(5000000);
	MSTK_vidSetBusyWait(5000000);

	return DataBuffer;
}


/* Function To Clear Buffer */
void ESP_vidClearBuffer (void)
{

	for(u16 i=0; i<Counter; i++)
	{
		DataBuffer[i] = 0 ;
	}
	Counter = 0;
}



