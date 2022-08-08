/*
 * TIMER1.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "TIMER1_int.h"

void M_TIMER1_voidPwm1Init(void)
{
	/* to enable output circuit for PD5 pin */
	M_DIO_void_setPinDirection(PORTD_ID,PIN5,OUTPUT);
	/* to select mode 14 in table 47 */
	CLR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);

	/* to select non inverting mode */
	SET_BIT(TCCR1A_REG,COM1A1);
	CLR_BIT(TCCR1A_REG,COM1A0);
}
void M_TIMER1_voidPwm1SetFrequancy(u32 Copy_u32Frequancy)
{
	ICR1_REG = ((F_OSC * 1000000 )/ TIMER1_PRESCALER ) / Copy_u32Frequancy;
}
void M_TIMER1_voidPwm1SetDutyCycle(f32 Copy_u8DutyCycle)
{
	OCR1A_REG = ((Copy_u8DutyCycle * ICR1_REG ) / 100) - 1;

}
void M_TIMER1_voidPwm1Start(void)
{
#if   TIMER1_PRESCALER   ==   1024
	SET_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
#elif TIMER1_PRESCALER   ==   256
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
#endif
}
void M_TIMER1_voidPwm1Stop(void)
{
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}
