/*
 * TWI_private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_PRIVATE_H_
#define TWI_TWI_PRIVATE_H_

#define TWI_MASTER_MODE     1
#define TWI_SLAVE_MODE      2

#define TWAR_REG   *((volatile u8 *)0x22)
#define TWBR_REG   *((volatile u8 *)0x20)
#define TWCR_REG   *((volatile u8 *)0x56)
#define TWIE        0
#define TWEN        2
#define TWSTO       4
#define TWSTA       5
#define TWEA        6
#define TWINT       7
#define TWDR_REG   *((volatile u8 *)0x23)
#define TWSR_REG   *((volatile u8 *)0x21)

#define TWI_START_COND_ACK                 0x08
#define TWI_REPEATED_START_COND_ACK        0x10
#define TWI_SEND_SLAVE_ADD_WRITE_ACK       0x18
#define TWI_SEND_SLAVE_ADD_READ_ACK        0x40
#define TWI_SEND_BYTE_ACK                  0x28
#define TWI_READ_BYTE_ACK                  0x50

#endif /* TWI_TWI_PRIVATE_H_ */
