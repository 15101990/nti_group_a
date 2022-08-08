/*
 * LCD_private.h
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */

#ifndef LCD_LCD_PRIVATE_H_
#define LCD_LCD_PRIVATE_H_


#define FOUR_BIT   0
#define EIGHT_BIT  1

#define FUNCTION_SET_8BIT_2LINES_5X7_DOTS  0x38
#define FUNCTION_SET_4BIT_2LINES_5X7_DOTS  0x28

#define DISPLAY_ON_CURSOR_ON_BLink_OFF     0x0E

#define DISPLAY_CLEAR                      0x01

#define ENTRY_MODE_SET                     0x06

#define SET_R0_C0_        0x80
#define SET_R1_C0_        0xC0

#define SET_CGRAM_ADDRESS  0b01000000
#define SET_DDRAM_ADDRESS  0x80
static void H_LCD_void_writeNlatch(u8 copy_u8Byte);
#endif /* LCD_LCD_PRIVATE_H_ */
