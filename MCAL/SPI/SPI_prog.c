/*
 * SPI_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "SPI_int.h"


void M_SPI_void_Init(void)
{
#if   SPI_MODE   ==   SPI_MASTER_MODE
	SET_BIT(SPCR_REG,MSTR);
	SET_BIT(SPCR_REG,SPR0);
	SET_BIT(SPCR_REG,SPR1);
	M_DIO_void_setPinDirection(PORTB_ID,PIN4,OUTPUT);
	M_DIO_void_setPinDirection(PORTB_ID,PIN5,OUTPUT);
	M_DIO_void_setPinDirection(PORTB_ID,PIN6,INPUT);
	M_DIO_void_setPinDirection(PORTB_ID,PIN7,OUTPUT);
#elif SPI_MODE   ==   SPI_SLAVE_MODE
	CLR_BIT(SPCR_REG,MSTR);
	M_DIO_void_setPinDirection(PORTB_ID,PIN4,INPUT);
	M_DIO_void_setPinDirection(PORTB_ID,PIN5,INPUT);
	M_DIO_void_setPinDirection(PORTB_ID,PIN6,OUTPUT);
	M_DIO_void_setPinDirection(PORTB_ID,PIN7,INPUT);
#endif
	/* to send from LSB first */
	SET_BIT(SPCR_REG,DORD);
	/* to enable spi circuit */
	SET_BIT(SPCR_REG,SPE);
}
u8   M_SPI_void_Transiver(u8 Copy_u8Data)
{
	SPDR_REG = Copy_u8Data;
	while(GET_BIT(SPSR_REG,SPIF) == 0);
	return SPDR_REG;
}
