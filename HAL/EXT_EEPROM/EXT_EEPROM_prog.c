/*
 * EXT_EEPROM_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "EXT_EEPROM_int.h"
#include "LED_int.h"

void H_EXT_EEPROM_void_Init(void)
{
	M_TWI_void_Init();
}
void H_EXT_EEPROM_void_Write(u8 Copy_u8PageNo,u8 Copy_u8ByteNo,u8 Copy_u8Data)
{
	M_TWI_void_StartCondition();
	M_TWI_void_SendSlaveAddressWrite(0x50 | Copy_u8PageNo);
	M_TWI_void_SendByte(Copy_u8ByteNo);
	M_TWI_void_SendByte(Copy_u8Data);
	M_TWI_void_StopCondition();
}
u8   H_EXT_EEPROM_void_Read(u8 Copy_u8PageNo,u8 Copy_u8ByteNo)
{
	u8 Local_u8Data = 0;
	M_TWI_void_StartCondition();
	M_TWI_void_SendSlaveAddressWrite(0x50 | Copy_u8PageNo);
	M_TWI_void_SendByte(Copy_u8ByteNo);
	M_TWI_void_RepeatedStart();
	M_TWI_void_SendSlaveAddressRead(0x50 | Copy_u8PageNo);
	Local_u8Data = M_TWI_void_ReadByte();
	M_TWI_void_StopCondition();
	return Local_u8Data;
}
