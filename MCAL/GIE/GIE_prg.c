/*
 * GIE_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_int.h"

void M_GIE_void_Enable(void)
{
     
	//SET_BIT(GIE_SREG,I_bit);
	 asm("SEI");
}
void M_GIE_void_Disable(void)
{
 
	//CLR_BIT(GIE_SREG,I_bit);
	asm("CLI");
}
