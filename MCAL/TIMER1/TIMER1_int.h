/*
 * TIMER1_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_

#include "TIMER1_config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_private.h"
#include "DIO_int.h"

void M_TIMER1_voidPwm1Init(void);
void M_TIMER1_voidPwm1SetFrequancy(u32);
void M_TIMER1_voidPwm1SetDutyCycle(f32);
void M_TIMER1_voidPwm1Start(void);
void M_TIMER1_voidPwm1Stop(void);

#endif /* TIMER1_TIMER1_INT_H_ */
