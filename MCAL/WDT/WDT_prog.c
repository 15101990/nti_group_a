/*
 * WDT_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "WDT_int.h"

void M_WDT_void_Enable(void)
{
	/* to enable watch dog timer */
	SET_BIT(WDTCR_REG,WDE);
	/* to select 2.1 seconds as window time */
	SET_BIT(WDTCR_REG,WDP0);
	SET_BIT(WDTCR_REG,WDP1);
	SET_BIT(WDTCR_REG,WDP2);
}
void M_WDT_void_Disable(void)
{

}
void M_WDT_void_Refresh(void)
{
	asm("WDR");
}
