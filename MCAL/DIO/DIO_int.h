/*
 * DIO_int.h
 *
 *  Created on: Jul 4, 2022
 *      Author: aya_enan
 */

#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_


#include "STD_TYPES.h"

//Macros for Port IDs
#define PORTA_ID   0
#define PORTB_ID   1
#define PORTC_ID   2
#define PORTD_ID   3

// Macros for Pins IDs
#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7

//Macros for pins direction
#define OUTPUT  1
#define INPUT   0

//Macros for pins Values
#define HIGH   1
#define LOW    0
void M_DIO_void_Init(void);
/*
 *  fn name : M_DIO_void_setPinDirection
 *  inputs : port ID, pin ID , direction (choose from above macros)
 *  output : void
 */
void M_DIO_void_setPinDirection(u8 port,u8 pin,u8 dir);

void  M_DIO_void_setPinValue(u8 port,u8 pin,u8 value);

void M_DIO_void_getPinValue(u8 port,u8 pin,u8* ptrValue);

void M_DIO_void_TogglePinValue(u8 port,u8 pin);

#endif /* DIO_DIO_INT_H_ */
