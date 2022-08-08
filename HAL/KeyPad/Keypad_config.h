/*
 * Keypad_config.h
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */

#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_

#define ROW_PORT        PORTB_ID
#define KEYPAD_R0_PIN   PIN4
#define KEYPAD_R1_PIN   PIN5
#define KEYPAD_R2_PIN   PIN6
#define KEYPAD_R3_PIN   PIN7

#define COL_PORT        PORTD_ID
#define KEYPAD_C0_PIN   PIN2
#define KEYPAD_C1_PIN   PIN3
#define KEYPAD_C2_PIN   PIN4
#define KEYPAD_C3_PIN   PIN5

#define KEYPAD_ROWS  4
#define KEYPAD_COLS  4
#define KEYPAD_ARR  {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
//#define KEYPAD_ARR  {{'7','8','9','+'},{'4','5','6','-'},{'3','2','1','*'},{'N','0','0','0'}}
#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
