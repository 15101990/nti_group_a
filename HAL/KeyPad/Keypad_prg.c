/*
 * Keypad_prg.c
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "Keypad_private.h"
#include "Keypad_config.h"
#include "Keypad_int.h"
#include <avr/delay.h>
void H_KEYPAD_void_Init(void)
{
  //step1 : config cols as inputs
	M_DIO_void_setPinDirection(COL_PORT , KEYPAD_C0_PIN , INPUT);
	M_DIO_void_setPinDirection(COL_PORT , KEYPAD_C1_PIN , INPUT);
	M_DIO_void_setPinDirection(COL_PORT , KEYPAD_C2_PIN , INPUT);
	M_DIO_void_setPinDirection(COL_PORT , KEYPAD_C3_PIN , INPUT);
  //step 2 : config row as outputs
	M_DIO_void_setPinDirection(ROW_PORT, KEYPAD_R0_PIN,OUTPUT);
	M_DIO_void_setPinDirection(ROW_PORT, KEYPAD_R1_PIN,OUTPUT);
	M_DIO_void_setPinDirection(ROW_PORT, KEYPAD_R2_PIN,OUTPUT);
	M_DIO_void_setPinDirection(ROW_PORT, KEYPAD_R3_PIN,OUTPUT);
  //step 3 : config initial values of rows as high
	M_DIO_void_setPinValue(ROW_PORT, KEYPAD_R0_PIN, HIGH);
	M_DIO_void_setPinValue(ROW_PORT, KEYPAD_R1_PIN, HIGH);
	M_DIO_void_setPinValue(ROW_PORT, KEYPAD_R2_PIN, HIGH);
	M_DIO_void_setPinValue(ROW_PORT, KEYPAD_R3_PIN, HIGH);
}
u8 H_KEYPAD_u8_getPressedKey(void)
{
	u8 Loc_u8ReturnValue = NO_PRESSED_KEY;// this value holds pressed key
    u8 Loc_u8row_indx ; // row iterator
    u8 Loc_u8col_indx ; // col iterator
    u8 Loc_u8PB_State;
    u8 Loc_u8KeyArr[KEYPAD_ROWS][KEYPAD_COLS]=KEYPAD_ARR;
    //loop on Rows from R0 -> R3
    for(Loc_u8row_indx = KEYPAD_R0_PIN  ;Loc_u8row_indx <= KEYPAD_R3_PIN; Loc_u8row_indx++)
    {
    	// activate row => output = low
    	M_DIO_void_setPinValue(ROW_PORT ,Loc_u8row_indx,LOW);
    	// loop on cols from C0 -> C3
    	for(Loc_u8col_indx = KEYPAD_C0_PIN ;Loc_u8col_indx <= KEYPAD_C3_PIN ;Loc_u8col_indx++ )
    	{
    		// scan col state
    		M_DIO_void_getPinValue(COL_PORT,Loc_u8col_indx,&Loc_u8PB_State);
    		if(Loc_u8PB_State == PRESSED)
    		{
              // debouncing
    			_delay_ms(200);
    			M_DIO_void_getPinValue(COL_PORT,Loc_u8col_indx,&Loc_u8PB_State);
    			if(Loc_u8PB_State == PRESSED)
    			{
    				//single press
    				while(Loc_u8PB_State == PRESSED)
    				{
    					M_DIO_void_getPinValue(COL_PORT,Loc_u8col_indx,&Loc_u8PB_State);
    				}//while
    				// algorithm update return value in case (PB is pressed)
    				Loc_u8ReturnValue =Loc_u8KeyArr[Loc_u8row_indx-KEYPAD_R0_PIN ][Loc_u8col_indx- KEYPAD_C0_PIN];
    			}//if

    		}//if
    	}//for inner
    	// deactivate row
    	M_DIO_void_setPinValue(ROW_PORT ,Loc_u8row_indx,HIGH);
    }//for outer


   return Loc_u8ReturnValue;
}
