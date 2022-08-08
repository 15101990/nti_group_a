/*
 * LED_int.h
 *
 *  Created on: Jul 6, 2022
 *      Author: aya_enan
 */

#ifndef LED_LED_INT_H_
#define LED_LED_INT_H_

#include "STD_TYPES.h"
#define RED_LED   0
#define GRN_LED   1
#define BLUE_LED  2
// this function will set direction as output
void H_Led_void_LedInit(u8 copy_u8LedID);
void H_Led_void_LedSetON(u8 copy_u8LedID);
void H_Led_void_LedSetOFF(u8 copy_u8LedID);
void H_Led_void_LedTOG(u8 copy_u8LedID);
#endif /* LED_LED_INT_H_ */
