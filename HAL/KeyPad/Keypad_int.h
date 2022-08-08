/*
 * Keypad_int.h
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */

#ifndef KEYPAD_KEYPAD_INT_H_
#define KEYPAD_KEYPAD_INT_H_

#define NO_PRESSED_KEY   0xff

void H_KEYPAD_void_Init(void);
u8 H_KEYPAD_u8_getPressedKey(void);

#endif /* KEYPAD_KEYPAD_INT_H_ */
