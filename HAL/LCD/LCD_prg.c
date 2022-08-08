/*
 * LCD_prg.c
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include <avr/delay.h>
void H_LCD_void_Init(void)
{
  
  M_DIO_void_setPinDirection(RS_PORT,RS_PIN, OUTPUT);
  M_DIO_void_setPinDirection(RW_PORT,RW_PIN, OUTPUT);
  M_DIO_void_setPinDirection(EN_PORT, EN_PIN, OUTPUT);
  
   M_DIO_void_setPinDirection(D4_PORT,D4_PIN,OUTPUT);
   M_DIO_void_setPinDirection(D5_PORT,D5_PIN,OUTPUT);
   M_DIO_void_setPinDirection(D6_PORT,D6_PIN,OUTPUT);
   M_DIO_void_setPinDirection(D7_PORT,D7_PIN,OUTPUT);
#if(LCD_MODE == EIGHT_BIT)
   
   M_DIO_void_setPinDirection(D0_PORT,D0_PIN,OUTPUT);
   M_DIO_void_setPinDirection(D1_PORT,D1_PIN,OUTPUT);
   M_DIO_void_setPinDirection(D2_PORT,D2_PIN,OUTPUT);
   M_DIO_void_setPinDirection(D3_PORT,D3_PIN,OUTPUT);

   _delay_ms(35);
   M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
   H_LCD_void_writeNlatch(FUNCTION_SET_8BIT_2LINES_5X7_DOTS);
#elif (LCD_MODE == FOUR_BIT)

  
   M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
  
   M_DIO_void_setPinValue(RW_PORT,RW_PIN, LOW);
  
    M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW);

   
   M_DIO_void_setPinValue(D7_PORT,D7_PIN, 0);
   M_DIO_void_setPinValue(D6_PORT,D6_PIN, 0);
   M_DIO_void_setPinValue(D5_PORT,D5_PIN, 1);
   M_DIO_void_setPinValue(D4_PORT,D4_PIN, 0);

   
   M_DIO_void_setPinValue(EN_PORT,EN_PIN, HIGH);
   _delay_ms(1); 
   M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW); 
   _delay_ms(30); 

   M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
  
   H_LCD_void_writeNlatch(FUNCTION_SET_4BIT_2LINES_5X7_DOTS);

#endif

 
   M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
  
   H_LCD_void_writeNlatch(DISPLAY_ON_CURSOR_ON_BLink_OFF);

   
   
   M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
   
   H_LCD_void_writeNlatch(DISPLAY_CLEAR);

   
   M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
   
   H_LCD_void_writeNlatch(ENTRY_MODE_SET  );
}
void H_LCD_void_sendData(u8 copy_u8data)
{
	
	M_DIO_void_setPinValue(RS_PORT,RS_PIN,HIGH);
	
	H_LCD_void_writeNlatch(copy_u8data);
}
void H_LCD_void_sendCommand(u8 copy_u8Command)
{
   
	M_DIO_void_setPinValue(RS_PORT,RS_PIN,LOW);
	
	H_LCD_void_writeNlatch(copy_u8Command);
}
void H_LCD_void_sendString(u8 * copy_str)
{
   u32 i= 0;
   while(copy_str[i] != '\0')
   {
	   H_LCD_void_sendData(copy_str[i]);
	   i++;
   }
}
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
     u8 Arr[10] = {0};
     s32 Loc_counter = 0;
     if(copy_s32Num == 0)
     {
    	 H_LCD_void_sendData('0');
    	 return ;
     }

     if(copy_s32Num < 0)
     {
    	 H_LCD_void_sendData('-'); 
    	 copy_s32Num *= -1;       
     }
     while(copy_s32Num != 0)
     {
    	 Arr[Loc_counter] = copy_s32Num % 10; 
    	 copy_s32Num =  copy_s32Num / 10;    
    	 Loc_counter++;
     }

     Loc_counter--;
     do{
    	 H_LCD_void_sendData( Arr[Loc_counter] + '0');
    	 Loc_counter--;
     }while(Loc_counter >= 0);
}
void H_LCD_void_GotoXY(u8 copy_u8row,u8 copy_u8col)
{
  if(copy_u8row >= 0 && copy_u8row <= 1  && copy_u8col >= 0 && copy_u8col <= 15)
  {
	  u8 Arr[2]= {SET_R0_C0_ , SET_R1_C0_};
	  H_LCD_void_sendCommand(Arr[copy_u8row]+ copy_u8col);
	/*  if(copy_u8row == 0)
	  {
		  H_LCD_void_sendCommand(SET_R0_C0_  + copy_u8col);
	  }
	  else
	  {
		  H_LCD_void_sendCommand(SET_R1_C0_ + copy_u8col);
	  }*/
  }
}
void H_LCD_void_Clear(void)
{
	H_LCD_void_sendCommand( DISPLAY_CLEAR);
}

static void H_LCD_void_writeNlatch(u8 copy_u8Byte)
{

#if(LCD_MODE == EIGHT_BIT)

	
	M_DIO_void_setPinValue(RW_PORT,RW_PIN, LOW);
	
    M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW);

   
    M_DIO_void_setPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 7) & 1);
    M_DIO_void_setPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 6) & 1);
    M_DIO_void_setPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 5) & 1);
    M_DIO_void_setPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 4) & 1);
    M_DIO_void_setPinValue(D3_PORT,D3_PIN, (copy_u8Byte>> 3) & 1);
    M_DIO_void_setPinValue(D2_PORT,D2_PIN, (copy_u8Byte>> 2) & 1);
    M_DIO_void_setPinValue(D1_PORT,D1_PIN, (copy_u8Byte>> 1) & 1);
    M_DIO_void_setPinValue(D0_PORT,D0_PIN, (copy_u8Byte>> 0) & 1);

    
    M_DIO_void_setPinValue(EN_PORT,EN_PIN, HIGH);
    _delay_ms(1); 
    M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW); 
    _delay_ms(30); 

#elif(LCD_MODE == FOUR_BIT)
    
	M_DIO_void_setPinValue(RW_PORT,RW_PIN, LOW);
	
	M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW);

	
	 M_DIO_void_setPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 7) & 1);
	 M_DIO_void_setPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 6) & 1);
	 M_DIO_void_setPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 5) & 1);
	 M_DIO_void_setPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 4) & 1);

	 M_DIO_void_setPinValue(EN_PORT,EN_PIN, HIGH);
	 _delay_ms(1); 
	 M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW); 
	 _delay_ms(30); 
	 
	 M_DIO_void_setPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 3) & 1);
	 M_DIO_void_setPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 2) & 1);
	 M_DIO_void_setPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 1) & 1);
	 M_DIO_void_setPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 0) & 1);

	 M_DIO_void_setPinValue(EN_PORT,EN_PIN, HIGH);
	 _delay_ms(1); 
	 M_DIO_void_setPinValue(EN_PORT,EN_PIN, LOW);
	 _delay_ms(30); 

#else
  #error("wrong LCD MODE")
#endif

}
void H_LCD_void_setCustomChar(u8 * Arr_pattern,u8 char_Code)
{
	u8 i;

	H_LCD_void_sendCommand(SET_CGRAM_ADDRESS + char_Code * 8);
    
	for(i=0;i<8;i++)
	{
		H_LCD_void_sendData(Arr_pattern[i]);
	}
	
	H_LCD_void_sendCommand(SET_DDRAM_ADDRESS);
}
void H_LCD_void_displayCustomChar(u8 char_Code)
{
	H_LCD_void_sendData(char_Code);
}
