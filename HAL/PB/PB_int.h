/*
 * PB_int.h
 *
 *  Created on: Jul 7, 2022
 *      Author: aya_enan
 */

#ifndef PB_PB_INT_H_
#define PB_PB_INT_H_

/*
 * choose the following :
 * PB_ID         ->       1,2,3,4
 * PB_port       ->       PORTA_ID ...PORTD_ID
 * PB_pin        ->       PIN0 ....PIN7
 * PB_ActiveMode ->       ACTIVE_HIGH ,ACTIVE_LOW
 */
#define ACTIVE_HIGH  1
#define ACTIVE_LOW   0

#define ACTIVE_LOW_PRESSED    0
#define ACTIVE_LOW_REALESED   1

#define ACTIVE_HIGH_PRESSED    1
#define ACTIVE_HIGH_REALESED   0
typedef struct
{
	u8 PB_ID;
	u8 PB_port;
	u8 PB_pin;
	u8 PB_ActiveMode;
}PB_t;
void H_PB_void_Init(PB_t copy_PB );
u8 H_PB_u8_PBread(PB_t copy_PB );
#endif /* PB_PB_INT_H_ */
