/*
 * SSD_prg.c
 *
 *  Created on: Jul 6, 2022
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_int.h"
#include <math.h>
#include <avr/delay.h>
void H_SSD_void_Init(void)
{
	
   M_DIO_void_setPinDirection(SSD_LED_A_PORT , SSD_LED_A_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_LED_B_PORT , SSD_LED_B_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_LED_C_PORT , SSD_LED_C_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_LED_D_PORT , SSD_LED_D_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_LED_E_PORT , SSD_LED_E_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_LED_F_PORT , SSD_LED_F_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_LED_G_PORT , SSD_LED_G_PIN, OUTPUT);

   M_DIO_void_setPinDirection(SSD_DOT_PORT,SSD_DOT_PIN,OUTPUT);
  
   M_DIO_void_setPinDirection(SSD_E1_PORT , SSD_E1_PIN, OUTPUT);
   M_DIO_void_setPinDirection(SSD_E2_PORT , SSD_E2_PIN, OUTPUT);
}
void H_SSD_void_DisplayNumber(u8 copy_u8Number)
{
   u8 Local_u8Units = copy_u8Number % 10;
   u8 Local_u8Tens  = copy_u8Number / 10;
   u16 i;
   for(i= 0;i<250;i++) // loop instead of while(1)
   {
	   switch(Local_u8Units)
	      {
	      case 0:
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
	   	   break ;
	      case 1 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
	   	   break;
	      case 2:
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	   break;
	      case 3 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	 break;
	      case 4 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	   break;
	      case 5 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	break;
	      case 6 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	   break;
	      case 7 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
	      	   break;
	      case 8 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	  break;
	      case 9 :
	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	   	  break;
	      }
	      M_DIO_void_setPinValue(SSD_E1_PORT,SSD_E1_PIN ,HIGH); 
	      M_DIO_void_setPinValue(SSD_E2_PORT,SSD_E2_PIN ,LOW); 
	      _delay_ms(1);
	      M_DIO_void_setPinValue(SSD_E1_PORT,SSD_E1_PIN ,LOW);


	      switch(Local_u8Tens)
	         {
	         case 0:
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
	      	   break ;
	         case 1 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
	      	   break;
	         case 2:
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	   break;
	         case 3 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	 break;
	         case 4 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	   break;
	         case 5 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	break;
	         case 6 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	   break;
	         case 7 :
	         	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	         	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	         	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	         	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
	         	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	         	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
	         	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
	         	   break;
	         case 8 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	  break;
	         case 9 :
	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
	      	  break;
	         }//switch
	      M_DIO_void_setPinValue(SSD_E1_PORT,SSD_E1_PIN ,LOW); 
	      M_DIO_void_setPinValue(SSD_E2_PORT,SSD_E2_PIN ,HIGH); 
	      _delay_ms(1);
	      M_DIO_void_setPinValue(SSD_E2_PORT,SSD_E2_PIN ,LOW);
   }//for


}//fn
void H_SSD_void_DisplayFloatNumber(f32 copy_f32Number)
{
   u8 Local_u8IntNum = (u8)copy_f32Number;
   u8 Local_u8FloatNum = fmod((copy_f32Number*10),10);
   u16 i;

     for(i= 0;i<500;i++) // loop instead of while(1)
     {
    	 M_DIO_void_setPinValue(SSD_DOT_PORT,SSD_DOT_PIN,LOW);
  	   switch(Local_u8FloatNum)
  	      {
  	      case 0:
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
  	   	   break ;
  	      case 1 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
  	   	   break;
  	      case 2:
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	   break;
  	      case 3 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	 break;
  	      case 4 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	   break;
  	      case 5 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	break;
  	      case 6 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	   break;
  	      case 7 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
  	      	   break;
  	      case 8 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	  break;
  	      case 9 :
  	   	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	   	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	   	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	   	  break;
  	      }
  	      M_DIO_void_setPinValue(SSD_E1_PORT,SSD_E1_PIN ,HIGH); 
  	      M_DIO_void_setPinValue(SSD_E2_PORT,SSD_E2_PIN ,LOW); 
  	      _delay_ms(1);
  	      M_DIO_void_setPinValue(SSD_E1_PORT,SSD_E1_PIN ,LOW);


  	      switch(Local_u8IntNum)
  	         {
  	         case 0:
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
  	      	   break ;
  	         case 1 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
  	      	   break;
  	         case 2:
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	   break;
  	         case 3 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	 break;
  	         case 4 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	   break;
  	         case 5 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	break;
  	         case 6 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	   break;
  	         case 7 :
  	         	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	         	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	         	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	         	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, LOW);
  	         	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	         	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, LOW);
  	         	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, LOW);
  	         	   break;
  	         case 8 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	  break;
  	         case 9 :
  	      	   M_DIO_void_setPinValue(SSD_LED_A_PORT , SSD_LED_A_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_B_PORT , SSD_LED_B_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_C_PORT , SSD_LED_C_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_D_PORT , SSD_LED_D_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_E_PORT , SSD_LED_E_PIN, LOW);
  	      	   M_DIO_void_setPinValue(SSD_LED_F_PORT , SSD_LED_F_PIN, HIGH);
  	      	   M_DIO_void_setPinValue(SSD_LED_G_PORT , SSD_LED_G_PIN, HIGH);
  	      	  break;
  	         }//switch
  	      M_DIO_void_setPinValue(SSD_DOT_PORT,SSD_DOT_PIN,HIGH);
  	      M_DIO_void_setPinValue(SSD_E1_PORT,SSD_E1_PIN ,LOW); 
  	      M_DIO_void_setPinValue(SSD_E2_PORT,SSD_E2_PIN ,HIGH); 

  	      _delay_ms(1);
  	      M_DIO_void_setPinValue(SSD_E2_PORT,SSD_E2_PIN ,LOW);
     }//for

}
