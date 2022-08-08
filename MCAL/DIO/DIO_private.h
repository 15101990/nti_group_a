/*
 * DIO_private.h
 *
 *  Created on: Jul 4, 2022
 *      Author: aya_enan
 */

#ifndef DIO_DIO_PRIVATE_H_
#define DIO_DIO_PRIVATE_H_
/*
 *  this file is a private file to the driver
 *  contains the following :
 *  1- private (Not sharable) Macros
 *  2- private (Not sharable) fn like Macros
 *  3- static functions
 */

/****************PORTA Registers**************/
#define PORTA_REG   *((volatile u8*)0x3B) // o/p data
#define DDRA_REG   *((volatile u8*)0x3A)  // direction
#define PINA_REG   *((volatile u8*)0x39)  // i/p data

/****************PORTB Registers**************/
#define PORTB_REG   *((volatile u8*)0x38)
#define DDRB_REG   *((volatile u8*)0x37)
#define PINB_REG   *((volatile u8*)0x36)

/****************PORTC Registers**************/
#define PORTC_REG   *((volatile u8*)0x35)
#define DDRC_REG   *((volatile u8*)0x34)
#define PINC_REG   *((volatile u8*)0x33)
/****************PORTD Registers**************/
#define PORTD_REG   *((volatile u8*)0x32)
#define DDRD_REG   *((volatile u8*)0x31)
#define PIND_REG   *((volatile u8*)0x30)

/************Function like Macros************/
#define CONC(b0,b1,b2,b3,b4,b5,b6,b7)  CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* DIO_DIO_PRIVATE_H_ */
