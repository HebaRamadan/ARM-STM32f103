/*
 * ESP_Interface.h
 *
 *  Created on: Feb 24, 2021
 *      Author: zas
 */

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_

void ESP_vidInit(void);
void ESP_vidConnectWiFi      ( u8* Copy_u8Name      ,  u8* Copy_u8Pasword );
void ESP_vidConnectServerTCP ( u8 * Copy_u8ServerIP , u8 * Copy_u8Port    );
u8 * ESP_vidGetFileFromServer( u8* Copy_u8FilePath );

void ESP_vidClearBuffer (void);
void MUSART1_CallBackFunction(void);





#endif /* ESP_INTERFACE_H_ */
