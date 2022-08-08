/*
 * Buzzer_prg.c
 *
 *  Created on: Jul 7, 2022
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "Buzzer_private.h"
#include "Buzzer_config.h"
#include "Buzzer_int.h"
#include <avr/delay.h>
void H_Buzzer_void_Init(void)
{
  M_DIO_void_setPinDirection(BUZZER_PORT, BUZZER_PIN , OUTPUT);
}
void H_Buzzer_void_SetON(void)
{
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , HIGH);
}
void H_Buzzer_void_SetOFF(void)
{
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , LOW);
}
void H_Buzzer_void_BuzzOnce(void)
{
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , HIGH);
	_delay_ms(BUZZER_DELAY);
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , LOW);

}
void H_Buzzer_void_Buzztwice(void)
{
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , HIGH);
	_delay_ms(BUZZER_DELAY);
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , LOW);
	_delay_ms(BUZZER_DELAY);
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , HIGH);
	_delay_ms(BUZZER_DELAY);
	M_DIO_void_setPinValue(BUZZER_PORT, BUZZER_PIN , LOW);

}
