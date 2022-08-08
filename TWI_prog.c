/*
 * TWI.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "TWI_int.h"


void M_TWI_void_Init(void)
{
#if   TWI_MODE   ==   TWI_MASTER_MODE
	TWBR_REG = (((F_OSC * 1000000) / F_SCL) - 16) / 2;
#elif TWI_MODE   ==   TWI_SLAVE_MODE
	TWAR_REG = (SLAVE_ADDRESS << 1) | GENERAL_CALL;
#endif
	SET_BIT(TWCR_REG,TWEN);
void M_TWI_void_StopCondition(void)
{
	SET_BIT(TWCR_REG,TWSTO);
	SET_BIT(TWCR_REG,TWINT);   /* to clear the flag */
	//while(GET_BIT(TWCR_REG,TWINT) == 0);
	//while((TWSR_REG & 0xF8) != TWI_START_COND_ACK);
}
void M_TWI_void_RepeatedStart(void)
{
	SET_BIT(TWCR_REG,TWSTA);
	SET_BIT(TWCR_REG,TWINT);   /* to clear the flag */
	while(GET_BIT(TWCR_REG,TWINT) == 0);
	while((TWSR_REG & 0xF8) != TWI_REPEATED_START_COND_ACK);
}
void M_TWI_void_SendSlaveAddressWrite(u8 Copy_u8Address)
{
    TWDR_REG = Copy_u8Address << 1;
	SET_BIT(TWCR_REG,TWINT);   /* to clear the flag */
	while(GET_BIT(TWCR_REG,TWINT) == 0);
	while((TWSR_REG & 0xF8) != TWI_SEND_SLAVE_ADD_WRITE_ACK);
}
void M_TWI_void_SendSlaveAddressRead(u8 Copy_u8Address)
{
    TWDR_REG = (Copy_u8Address << 1) | 1;
	CLR_BIT(TWCR_REG,TWSTA);
	SET_BIT(TWCR_REG,TWINT);   /* to clear the flag */
	while(GET_BIT(TWCR_REG,TWINT) == 0);
	while((TWSR_REG & 0xF8) != TWI_SEND_SLAVE_ADD_READ_ACK);
}
void M_TWI_void_SendByte(u8 Copy_u8Data)
{
	TWDR_REG = Copy_u8Data;
	CLR_BIT(TWCR_REG,TWSTA);
	SET_BIT(TWCR_REG,TWINT);   /* to clear the flag */
	while(GET_BIT(TWCR_REG,TWINT) == 0);
	while((TWSR_REG & 0xF8) != TWI_SEND_BYTE_ACK);
}
u8   M_TWI_void_ReadByte(void)
{
	CLR_BIT(TWCR_REG,TWSTA);
	CLR_BIT(TWCR_REG,TWSTO);
	SET_BIT(TWCR_REG,TWEA);
	SET_BIT(TWCR_REG,TWINT);   /* to clear the flag */
	u8 Local_u8Data = 0;
	Local_u8Data = TWDR_REG;
	while(GET_BIT(TWCR_REG,TWINT) == 0);
	while((TWSR_REG & 0xF8) != TWI_READ_BYTE_ACK);
	Local_u8Data = TWDR_REG;
	return Local_u8Data;
}
