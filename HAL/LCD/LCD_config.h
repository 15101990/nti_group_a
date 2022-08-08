/*
 * LCD_config.h
 *
 *  Created on: Jul 17, 2022
 *      Author: aya_enan
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/*
 *  choose LCD Mode : FOUR_BIT  , EIGHT_BIT
 */
#define LCD_MODE  FOUR_BIT

/*
 * choose control pins
 */
#define RS_PIN   PIN1
#define RS_PORT  PORTB_ID

#define RW_PIN   PIN2
#define RW_PORT  PORTB_ID

#define EN_PIN   PIN3
#define EN_PORT  PORTB_ID

/*
 * data pins
 */
#define D7_PIN    PIN7
#define D7_PORT   PORTA_ID

#define D6_PIN    PIN6
#define D6_PORT   PORTA_ID

#define D5_PIN    PIN5
#define D5_PORT   PORTA_ID

#define D4_PIN    PIN4
#define D4_PORT   PORTA_ID

#define D3_PIN    PIN0
#define D3_PORT   PORTB_ID

#define D2_PIN    PIN2
#define D2_PORT   PORTB_ID

#define D1_PIN    PIN3
#define D1_PORT   PORTB_ID

#define D0_PIN   PIN4
#define D0_PORT  PORTB_ID
#endif /* LCD_LCD_CONFIG_H_ */
