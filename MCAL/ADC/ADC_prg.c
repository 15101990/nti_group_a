/*
 * ADC_prg.c
 *
 *  Created on: Jul 21, 2022
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_int.h"

void M_ADC_void_init(prescaler_t copy_u8prescaler, vref_t copy_u8vref)
{
   
	ADCSRA_REG &=      PRESCALER_MASK;
	ADCSRA_REG |= (u8) copy_u8prescaler;
   
    SET_BIT(ADCSRA_REG ,ADEN);
	
    CLR_BIT(ADCSRA_REG,ADIE );
	
    CLR_BIT(ADCSRA_REG,ADATE);
    
    CLR_BIT(ADMUX_REG,ADLAR );
	
    ADMUX_REG  &=  VREF_MASK ;
    ADMUX_REG  |= (((u8)copy_u8vref) << REFS0 );

}
u16  M_ADC_u16_getValue(u8 copy_u8channel)
{
    
	ADMUX_REG &= CHANNEL_MASK;
	ADMUX_REG |= copy_u8channel;
	
	SET_BIT(ADCSRA_REG,ADSC);

	
	while(GET_BIT(ADCSRA_REG,ADIF)== 0);

	
	return ADCL_REG;
}
