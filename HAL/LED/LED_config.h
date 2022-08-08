/*
 * LED_config.h
 *
 *  Created on: Jul 6, 2022
 *      Author: aya_enan
 */

#ifndef LED_LED_CONFIG_H_
#define LED_LED_CONFIG_H_

/*
 *   choose :
 *   PORT ->  PORTA_ID ,  PORTB_ID , PORTC_ID , PORTD_ID
 *   PIN  ->  PIN0 ....PIN7
 *   MODE ->  LED_FORWARD  , LED_REVERSE
 */
#define RED_LED_PORT  PORTC_ID
#define RED_LED_PIN   PIN0
#define RED_LED_MODE  LED_FORWARD

#define GRN_LED_PORT  PORTC_ID
#define GRN_LED_PIN   PIN1
#define GRN_LED_MODE  LED_FORWARD

#define BLUE_LED_PORT PORTC_ID
#define BLUE_LED_PIN  PIN2
#define BLUE_LED_MODE LED_FORWARD

#endif /* LED_LED_CONFIG_H_ */
