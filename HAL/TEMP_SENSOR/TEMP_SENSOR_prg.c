/*
 * TEMP_SENSOR_prg.c
 *
 *  Created on: Jul 21, 2022
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "TEMP_SENSOR_private.h"
#include "TEMP_SENSOR_config.h"
#include "TEMP_SENSOR_int.h"
void H_TEMPSENSOR_void_Init()
{
   //set direction of temp Sensor channel  pin as input
	M_DIO_void_setPinDirection(PORTA_ID, TEMP_SENSOR_CHANNEL, INPUT);
}
u8   H_TEMPSENSOR_u8_readTemp()
{
	// step 1 : call adc to convert (read digital value)
	u16 adc_read = M_ADC_u16_getValue(TEMP_SENSOR_CHANNEL);
	// step 2: convert digital value to analog
    u32 read_mv =   ( (u32)adc_read * TEMP_VREF)/ TEMP_RES;
    //step 3 : convert from mv to degree C
    u8 temp =  read_mv / 10;
    //step 4 : return temp
    return temp;
}
