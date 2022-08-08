/*
 * SERVO_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "SERVO_int.h"

void H_SERVO_void_Init(void)
{
	M_TIMER1_voidPwm1Init();
	M_TIMER1_voidPwm1SetFrequancy(50);
}
void H_SERVO_void_SetAngel(u8 Copy_u8Angel)
{
	f32 Local_f32Value = ((5.0 * Copy_u8Angel)  / 180.0) + 5.0;
	M_TIMER1_voidPwm1SetDutyCycle(Local_f32Value);
}
void H_SERVO_void_Start(void)
{
	M_TIMER1_voidPwm1Start();
}
void H_SERVO_void_Stop(void)
{
	M_TIMER1_voidPwm1Stop();
}
