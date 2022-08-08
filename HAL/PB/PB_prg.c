/*
 * PB_prg.c
 *
 *  Created on: Jul 7, 2022
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "PB_private.h"
#include "PB_config.h"
#include "PB_int.h"
#include <avr/delay.h>

void H_PB_void_Init(PB_t copy_PB )
{
 
  M_DIO_void_setPinDirection(copy_PB.PB_port, copy_PB.PB_pin, INPUT);

}
u8 H_PB_u8_PBread(PB_t copy_PB )
{
   u8 Local_u8Reading;
   if(copy_PB.PB_ActiveMode == ACTIVE_LOW)
   {
	   
	   Local_u8Reading = ACTIVE_LOW_REALESED;
	  
	   M_DIO_void_getPinValue(copy_PB.PB_port, copy_PB.PB_pin,&Local_u8Reading);
	   
	   if(Local_u8Reading == ACTIVE_LOW_PRESSED)
	   {
          
		   _delay_ms(200);
		 
		   M_DIO_void_getPinValue(copy_PB.PB_port, copy_PB.PB_pin,&Local_u8Reading);
		  
		   if(Local_u8Reading == ACTIVE_LOW_PRESSED)
		   {
			   
              while(Local_u8Reading == ACTIVE_LOW_PRESSED)
              {
            	  
            	  M_DIO_void_getPinValue(copy_PB.PB_port, copy_PB.PB_pin,&Local_u8Reading);
              }//while
             Local_u8Reading = ACTIVE_LOW_PRESSED;
		   }//if inner
	   }//if outer
   }//if

   else if(copy_PB.PB_ActiveMode == ACTIVE_HIGH) 
   {
      
	   Local_u8Reading = ACTIVE_HIGH_REALESED;
	  
	   M_DIO_void_getPinValue(copy_PB.PB_port, copy_PB.PB_pin,&Local_u8Reading);
	   
	   if(Local_u8Reading == ACTIVE_HIGH_PRESSED)
	   {
			
		   _delay_ms(200);
		   
		   M_DIO_void_getPinValue(copy_PB.PB_port, copy_PB.PB_pin,&Local_u8Reading);
		 
		   if(Local_u8Reading == ACTIVE_HIGH_PRESSED)
		   {
			  
				while(Local_u8Reading == ACTIVE_HIGH_PRESSED)
				{
				 
				  M_DIO_void_getPinValue(copy_PB.PB_port, copy_PB.PB_pin,&Local_u8Reading);
				}//while
			   Local_u8Reading = ACTIVE_HIGH_PRESSED;
		   }//if inner
	   }//if outer

   }//else if
   return Local_u8Reading;
}
