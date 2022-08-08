/*
 * TWI_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_

#include "TWI_Config.h"
#include "TWI_private.h"
#include "DIO_int.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
void M_TWI_void_Init(void);
void M_TWI_void_StartCondition(void);
void M_TWI_void_StopCondition(void);
void M_TWI_void_RepeatedStart(void);
void M_TWI_void_SendSlaveAddressWrite(u8);
void M_TWI_void_SendSlaveAddressRead(u8);
void M_TWI_void_SendByte(u8);
u8   M_TWI_void_ReadByte(void);

#endif /* TWI_TWI_INT_H_ */
