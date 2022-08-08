/*
 * EXTI_private.h
 *
 *  Created on: Jul 19, 2022
 *      Author: aya_enan
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define EXTI_MCUCR  *((volatile u8*)0x55) // trigger register
#define ISC00  0  //Interrupt Sense Control 0  Bit 0
#define ISC01  1  //Interrupt Sense Control 0  Bit 1
#define ISC10  2
#define ISC11  3

#define EXTI_MCUCSR *((volatile u8*)0x54) // trigger register
#define ISC2  6   // Interrupt Sense Control 2

#define EXTI_GICR   *((volatile u8*)0x5B) // PIE register (special keys)
#define INT2  5
#define INT0  6
#define INT1  7

#define EXTI_GIFR   *((volatile u8*)0x5A) // flags register
#define INTF2  5
#define INTF0  6
#define INTF1  7


#define EXTI_INT0_TRIG_MASK  0b11111100
#define EXTI_INT1_TRIG_MASK  0b11110011
#endif /* EXTI_EXTI_PRIVATE_H_ */
