/*
 * SPI_private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

#define SPI_MASTER_MODE       1
#define SPI_SLAVE_MODE        2


#define SPCR_REG   *((volatile u8 *)0x2D)
#define SPR0        0
#define SPR1        1
#define MSTR        4
#define DORD        5
#define SPE         6

#define SPDR_REG   *((volatile u8 *)0x2F)
#define SPSR_REG   *((volatile u8 *)0x2E)
#define SPIF        7

#endif /* SPI_SPI_PRIVATE_H_ */
