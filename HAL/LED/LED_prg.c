/*
 * LED_prg.c
 *
 *  Created on: Jul 6, 2022
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"
void H_Led_void_LedInit(u8 copy_u8LedID)
{
  switch(copy_u8LedID)
  {
  case RED_LED :
	  M_DIO_void_setPinDirection(RED_LED_PORT, RED_LED_PIN, OUTPUT);
	  break;
  case GRN_LED:
	  M_DIO_void_setPinDirection(GRN_LED_PORT, GRN_LED_PIN, OUTPUT);
	  break;
  case BLUE_LED:
	  M_DIO_void_setPinDirection(BLUE_LED_PORT, BLUE_LED_PIN, OUTPUT);
	  break;
  default : break;

  }
}
void H_Led_void_LedSetON(u8 copy_u8LedID)
{
	switch(copy_u8LedID)
	  {
	  case RED_LED :
#if(RED_LED_MODE == LED_FORWARD)
		  M_DIO_void_setPinValue(RED_LED_PORT, RED_LED_PIN, HIGH);
#elif(RED_LED_MODE == LED_REVERSE)
		  M_DIO_void_setPinValue(RED_LED_PORT, RED_LED_PIN, LOW);
#else
  #error ("wrong LED mode")
#endif
		  break;
	  case GRN_LED:
#if(GRN_LED_MODE == LED_FORWARD)
		  M_DIO_void_setPinValue(GRN_LED_PORT, GRN_LED_PIN, HIGH);
#elif(GRN_LED_MODE == LED_REVERSE)
		  M_DIO_void_setPinValue(GRN_LED_PORT, GRN_LED_PIN, LOW);
#else
  #error ("wrong LED mode")
#endif
		  break;
	  case BLUE_LED:
#if(BLUE_LED_MODE == LED_FORWARD)
		  M_DIO_void_setPinValue(BLUE_LED_PORT, BLUE_LED_PIN, HIGH);
#elif(BLUE_LED_MODE == LED_REVERSE)
		  M_DIO_void_setPinValue(BLUE_LED_PORT, BLUE_LED_PIN, LOW);
#else
  #error ("wrong LED mode")
#endif
		  break;
	  default : break;

	  }

}
void H_Led_void_LedSetOFF(u8 copy_u8LedID)
{
	switch(copy_u8LedID)
	  {
	  case RED_LED :

#if(RED_LED_MODE == LED_FORWARD)
		  M_DIO_void_setPinValue(RED_LED_PORT, RED_LED_PIN, LOW);
#elif(RED_LED_MODE == LED_REVERSE)
		  M_DIO_void_setPinValue(RED_LED_PORT, RED_LED_PIN, HIGH);
#else
  #error ("wrong LED mode")
#endif

		  break;
	  case GRN_LED:
#if(GRN_LED_MODE == LED_FORWARD)
		  M_DIO_void_setPinValue(GRN_LED_PORT, GRN_LED_PIN,LOW);
#elif(GRN_LED_MODE == LED_REVERSE)
		  M_DIO_void_setPinValue(GRN_LED_PORT, GRN_LED_PIN, HIGH);
#else
  #error ("wrong LED mode")
#endif
		  break;
	  case BLUE_LED:
#if(BLUE_LED_MODE == LED_FORWARD)
		  M_DIO_void_setPinValue(BLUE_LED_PORT, BLUE_LED_PIN, LOW);
#elif(BLUE_LED_MODE == LED_REVERSE)
		  M_DIO_void_setPinValue(BLUE_LED_PORT, BLUE_LED_PIN, HIGH);
#else
  #error ("wrong LED mode")
#endif
		  break;
	  default : break;

	  }
}
void H_Led_void_LedTOG(u8 copy_u8LedID)
{
	switch(copy_u8LedID)
		  {
		  case RED_LED :
			  M_DIO_void_TogglePinValue(RED_LED_PORT, RED_LED_PIN);
			  break;
		  case GRN_LED:
			  M_DIO_void_TogglePinValue(GRN_LED_PORT, GRN_LED_PIN);
			  break;
		  case BLUE_LED:
			  M_DIO_void_TogglePinValue(BLUE_LED_PORT, BLUE_LED_PIN);
			  break;
		  default : break;

		  }

}
