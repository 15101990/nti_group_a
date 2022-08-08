/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: aya_enan
 */

#include "LED_int.h"
#include "DIO_int.h"
#include "SSD_int.h"
#include "PB_int.h"
#include "Buzzer_int.h"
#include "Keypad_int.h"
#include "LCD_int.h"
#include "EXTI_int.h"
#include "GIE_int.h"
#include "ADC_int.h"
#include "TEMP_SENSOR_int.h"
#include "TIMER0_int.h"
#include "TIMER1_int.h"
#include "SERVO_int.h"
#include "WDT_int.h"
#include "UART_int.h"
#include "SPI_int.h"
#include "EXT_EEPROM_int.h"
#include <util/delay.h>

void A_Timer0Exc(void);

int main()
{
	_delay_ms(1000);
	H_EXT_EEPROM_void_Init();
	H_LCD_void_Init();
	u8 x = 0;
	x = H_EXT_EEPROM_void_Read(1,12);
	while(1)
	{
		H_LCD_void_sendIntNum(x);
		_delay_ms(1000);
		x++;
		H_LCD_void_Clear();
		H_EXT_EEPROM_void_Write(1,12,x);
	}
}

void A_Timer0Exc(void)
{
	H_Led_void_LedTOG(BLUE_LED);
}
