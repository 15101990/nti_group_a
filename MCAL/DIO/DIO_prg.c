/*
 * DIO_prg.c
 *
 *  Created on: Jul 4, 2022
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_int.h"

void M_DIO_void_Init(void)
{
	DDRA_REG = CONC(PA0_DIR,PA1_DIR,PA2_DIR,PA3_DIR,PA4_DIR,PA5_DIR,PA6_DIR,PA7_DIR);
	DDRB_REG = CONC(PB0_DIR,PB1_DIR,PB2_DIR,PB3_DIR,PB4_DIR,PB5_DIR,PB6_DIR,PB7_DIR);
	DDRC_REG = CONC(PC0_DIR,PC1_DIR,PC2_DIR,PC3_DIR,PC4_DIR,PC5_DIR,PC6_DIR,PC7_DIR);
	DDRD_REG = CONC(PD0_DIR,PD1_DIR,PD2_DIR,PD3_DIR,PD4_DIR,PD5_DIR,PD6_DIR,PD7_DIR);
}
void M_DIO_void_setPinDirection(u8 port,u8 pin,u8 dir)
{
	switch(port)
	{
	case  PORTA_ID :
		CLR_BIT(DDRA_REG,pin);
		DDRA_REG |= dir << pin;

		break;
	case  PORTB_ID :
		CLR_BIT(DDRB_REG,pin);
		DDRB_REG |= dir << pin;
		break;
	case  PORTC_ID :
		CLR_BIT(DDRC_REG,pin);
		DDRC_REG |= dir << pin;
		break;
	case  PORTD_ID :
		CLR_BIT(DDRD_REG,pin);
		DDRD_REG |= dir << pin;
		break;
	default:
		   break;
	}
}
void  M_DIO_void_setPinValue(u8 port,u8 pin,u8 value)
{
	switch(port)
		{
		case  PORTA_ID :
			CLR_BIT(PORTA_REG,pin);
			PORTA_REG |= value << pin;
			break;
		case  PORTB_ID :
			CLR_BIT(PORTB_REG,pin);
			PORTB_REG |= value << pin;
			break;
		case  PORTC_ID :
			CLR_BIT(PORTC_REG,pin);
			PORTC_REG |= value << pin;
			break;
		case  PORTD_ID :
			CLR_BIT(PORTD_REG,pin);
			PORTD_REG |= value << pin;
			break;
		default:
			   break;
		}

}
void M_DIO_void_getPinValue(u8 port,u8 pin,u8* ptrValue)
{
	switch(port)
	{
	case  PORTA_ID : *ptrValue	= GET_BIT(PINA_REG,pin);break;
	case  PORTB_ID : *ptrValue	= GET_BIT(PINB_REG,pin);break;
	case  PORTC_ID : *ptrValue	= GET_BIT(PINC_REG,pin);break;
	case  PORTD_ID : *ptrValue	= GET_BIT(PIND_REG,pin);break;
	default:   break;
	}
}

void M_DIO_void_TogglePinValue(u8 port,u8 pin)
{
	switch(port)
		{
		case  PORTA_ID : TOG_BIT(PORTA_REG,pin); break;
		case  PORTB_ID : TOG_BIT(PORTB_REG,pin); break;
		case  PORTC_ID : TOG_BIT(PORTC_REG,pin); break;
		case  PORTD_ID : TOG_BIT(PORTD_REG,pin); break;
		default:   break;
		}

}
