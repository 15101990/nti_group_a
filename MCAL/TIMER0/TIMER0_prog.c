/*
 * TIMER0_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "TIMER0_int.h"

u32 Timer0_u32NumOfOv  = 0;
u8  Timer0_u8RemTicks  = 0;
u32 Timer0_u32NumOfCm  = 0;

void (*CallBack) (void);

void M_TIMER0_Void_Init(void)
{
#if TIMER0_MODE   ==   NORMAL_MODE
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
	/* to enable timer 0 overflow INT */
	SET_BIT(TIMSK_REG,TOIE0);
#elif TIMER0_MODE   ==   CTC_MODE
	CLR_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	/* to enable timer 0 compare match INT */
	SET_BIT(TIMSK_REG,OCIE0);
#endif

}
void M_TIMER0_Void_SetTime(u32 Copy_u32DesiredTime)
{
	u32 Local_u32TickTime   = TIMER0_PRESCALER / F_OSC;    /* result will be in micro secons */
	u32 Local_u32TotalTicks = (Copy_u32DesiredTime * 1000) / Local_u32TickTime;
#if TIMER0_MODE   ==   NORMAL_MODE
	Timer0_u32NumOfOv       = Local_u32TotalTicks / 256;
	Timer0_u8RemTicks       = Local_u32TotalTicks % 256;
	if(Timer0_u8RemTicks != 0)
	{
		TCNT0_REG           = 256 - Timer0_u8RemTicks;
		Timer0_u32NumOfOv++;
	}
#elif TIMER0_MODE   ==   CTC_MODE
	u8 Local_u8Counter = 255;
	while(Local_u32TotalTicks % Local_u8Counter)
	{
		Local_u8Counter--;
	}
	Timer0_u32NumOfCm = Local_u32TotalTicks / Local_u8Counter;
	OCR0_REG = Local_u8Counter - 1;
#endif
}
void M_TIMER0_Void_Start(void)
{
#if TIMER0_PRESCALER   ==   1024
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
#elif TIMER0_PRESCALER ==   256
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
#endif
}
void M_TIMER0_Void_Stop(void)
{
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}



void M_TIMER0_Void_Pwm0Init(void)
{
	/* to enable output circuit for PB3 */
	M_DIO_void_setPinDirection(PORTB_ID,PIN3,OUTPUT);
#if   TIMER0_PWM_MODE   ==   FAST_PWM
	/* to select fast PWM mode */
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
#if   TIMER0_FAST_PWM_MODE   ==   NON_INVERTED
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#elif TIMER0_FAST_PWM_MODE   ==   INVERTED
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#endif
#elif TIMER0_PWM_MODE   ==   PHASE_CORRECT
	/* to select fast PWM mode */
	SET_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
#if   TIMER0_FAST_PWM_MODE   ==   NON_INVERTED
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#elif TIMER0_FAST_PWM_MODE   ==   INVERTED
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#endif
#endif
}
void M_TIMER0_Void_Pwm0SetDutyCycle(u8 Copy_u8DutyCycle)
{
#if TIMER0_PWM_MODE   ==   FAST_PWM
	#if TIMER0_FAST_PWM_MODE   ==   NON_INVERTED
	OCR0_REG = ((Copy_u8DutyCycle * 256 ) / 100) - 1;
	#elif TIMER0_FAST_PWM_MODE   ==   INVERTED

	#endif
#elif TIMER0_PWM_MODE   ==   PHASE_CORRECT
	#if TIMER0_FAST_PWM_MODE   ==   NON_INVERTED
	OCR0_REG = ((Copy_u8DutyCycle * 255 ) / 100);
	#elif TIMER0_FAST_PWM_MODE   ==   INVERTED

	#endif
#endif
}
void M_TIMER0_Void_Pwm0Start(void)
{
	M_TIMER0_Void_Start();
}
void M_TIMER0_Void_Pwm0Stop(void)
{
	M_TIMER0_Void_Stop();
}







void M_TIMER0_voidSetCallBack(void(*CopyPtr)(void))
{
	CallBack = CopyPtr;
}
#if TIMER0_MODE   ==   NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter++;
	if(Local_u32Counter == Timer0_u32NumOfOv)
	{
		CallBack();
		Local_u32Counter = 0;
		TCNT0_REG = 256 - Timer0_u8RemTicks;
	}
}
#elif TIMER0_MODE   ==   CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter++;
	if(Local_u32Counter == Timer0_u32NumOfCm)
	{
		CallBack();
		Local_u32Counter = 0;
	}
}
#endif
