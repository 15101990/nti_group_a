/*
 * EXT_EEPROM_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef EXT_EEPROM_EXT_EEPROM_INT_H_
#define EXT_EEPROM_EXT_EEPROM_INT_H_

#include "TWI_int.h"
#include "STD_TYPES.h"

void H_EXT_EEPROM_void_Init(void);
void H_EXT_EEPROM_void_Write(u8,u8,u8);
u8   H_EXT_EEPROM_void_Read(u8,u8);

#endif /* EXT_EEPROM_EXT_EEPROM_INT_H_ */
