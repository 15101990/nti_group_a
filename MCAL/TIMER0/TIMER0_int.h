/*
 * TIMER0_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_
/******************************************_INCLUDE_******************************************/
#include "TIMER0_config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_private.h"
#include "DIO_int.h"
#include <avr/interrupt.h>
/****************************************_PROTOTYPES_******************************************/
void M_TIMER0_Void_Init(void);
void M_TIMER0_Void_SetTime(u32);
void M_TIMER0_Void_Start(void);
void M_TIMER0_Void_Stop(void);
void M_TIMER0_voidSetCallBack(void(*)(void));

void M_TIMER0_Void_Pwm0Init(void);
void M_TIMER0_Void_Pwm0SetDutyCycle(u8);
void M_TIMER0_Void_Pwm0Start(void);
void M_TIMER0_Void_Pwm0Stop(void);

#endif /* TIMER0_TIMER0_INT_H_ */
