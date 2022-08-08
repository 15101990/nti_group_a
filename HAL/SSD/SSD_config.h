/*
 * SSD_config.h
 *
 *  Created on: Jul 6, 2022
 *      Author: aya_enan
 */

#ifndef SSD_SSD_CONFIG_H_
#define SSD_SSD_CONFIG_H_

/*
 *   choose :
 *   PORT ->  PORTA_ID ,  PORTB_ID , PORTC_ID , PORTD_ID
 *   PIN  ->  PIN0 ....PIN7
 */
#define SSD_LED_A_PORT  PORTA_ID
#define SSD_LED_A_PIN   PIN1

#define SSD_LED_B_PORT  PORTA_ID
#define SSD_LED_B_PIN   PIN2

#define SSD_LED_C_PORT  PORTA_ID
#define SSD_LED_C_PIN   PIN3

#define SSD_LED_D_PORT PORTA_ID
#define SSD_LED_D_PIN  PIN4

#define SSD_LED_E_PORT PORTA_ID
#define SSD_LED_E_PIN  PIN5

#define SSD_LED_F_PORT PORTA_ID
#define SSD_LED_F_PIN  PIN6

#define SSD_LED_G_PORT PORTA_ID
#define SSD_LED_G_PIN   PIN7

#define SSD_E1_PORT   PORTC_ID  // Enable SSD Digit 1
#define SSD_E1_PIN    PIN6

#define SSD_E2_PORT   PORTC_ID  // Enable SSD Digit 2
#define SSD_E2_PIN    PIN7

#define SSD_DOT_PORT PORTB_ID   //DOT
#define SSD_DOT_PIN  PIN0
#endif /* SSD_SSD_CONFIG_H_ */
