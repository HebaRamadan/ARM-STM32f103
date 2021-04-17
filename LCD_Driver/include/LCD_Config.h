/*
 * LCD_Config.h
 *
 *  Created on: Nov 30, 2020
 *      Author: zas
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* Configure LCD PINS */
#define Data_Port    PORTB
#define Data_Pin     PORT_MSB
#define Control_Port PORTA

#define RS           PIN0
#define RW           PIN1
#define EN           PIN2

/* LCD Mode */
#define LCD_4BITMODE    0
#define LCD_8BITMODE    1
#define LCD_MODE   LCD_8BITMODE

/* Function Set */
#define NUM_LINE_1 		0
#define NUM_LINE_2 		1

#define PIXELS_5_7 		0
#define PIXELS_5_10 	1

#define LINES           NUM_LINE_2
#define PIXELS          PIXELS_5_7


/* Display On LCD */
#define DISPLAY_OFF    0
#define DISPLAY_ON     1

#define CURSOR_OFF     0
#define CURSOR_ON      1

#define BLINK_OFF      0
#define BLINK_ON       1

#define DISPLAY_MODE   DISPLAY_ON
#define CURSOR_MODE    CURSOR_ON
#define BLINK_MODE     BLINK_ON


/*CLEAR DISPLAY*/
#define CLRDISPLAY  1



#endif /* LCD_CONFIG_H_ */
