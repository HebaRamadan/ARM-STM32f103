/*
 * FPEC_Program.c
 *
 *  Created on: Feb 19, 2021
 *      Author: zas
 */

#ifndef PARSE_H_
#define PARSE_H_


u8 AsciToHex(u8 Copy_u8Asci);
void ParseData(u8* Copy_u8BufData);
void FPEC_vidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);
void Parser_vidParseRecord(u8* Copy_u8BufData);


#endif /* PARSE_H_ */
