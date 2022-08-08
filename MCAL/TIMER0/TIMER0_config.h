/*
 * TIMER0_config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_
/*
 *  choose TIMER0_MODE : NORMAL_MODE  , CTC_MODE
 */
#define TIMER0_MODE    CTC_MODE

/*
 *  choose TIMER0_PRESCALER : 1024  ,  256
 */
#define TIMER0_PRESCALER    1024

/*
 *  choose F_OSC
 */
#define F_OSC    16
/*
 *  choose TIMER0_FAST_PWM_MODE : FAST_PWM , PHASE_CORRECT
 */
#define TIMER0_PWM_MODE       PHASE_CORRECT

/*
 *  choose TIMER0_FAST_PWM_MODE : NON_INVERTED , INVERTED
 */
#define TIMER0_FAST_PWM_MODE    NON_INVERTED



#endif /* TIMER0_TIMER0_CONFIG_H_ */
