/*
 * LCD_int.h
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_


void H_LCD_void_Init(void);
void H_LCD_void_sendData(u8 copy_u8data);
void H_LCD_void_sendCommand(u8 copy_u8Command);
void H_LCD_void_sendString(u8 * copy_str);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_GotoXY(u8 copy_u8row,u8 copy_u8col);
void H_LCD_void_Clear(void);
// this fn stores custom char in CGRAM
void H_LCD_void_setCustomChar(u8 * Arr_pattern,u8 char_Code);
// this fn display Custom char from DDRAM
void H_LCD_void_displayCustomChar(u8 char_Code);
#endif /* LCD_LCD_INT_H_ */
