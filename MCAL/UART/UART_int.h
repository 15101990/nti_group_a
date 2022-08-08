/*
 * UART_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

#include "UART_cfg.h"
#include "UART_private.h"
#include "DIO_int.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void M_UART_void_Init(void);
void M_UART_void_SetBaudRate(u32);
void M_UART_void_Tx(u8);
void M_UART_void_Rx(u8*);

#endif /* UART_UART_INT_H_ */
