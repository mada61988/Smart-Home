/*
 * gio_program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: MohamedAyman
 */

#ifndef MCAL_GIO_GIO_PROGRAM_C_
#define MCAL_GIO_GIO_PROGRAM_C_

#include "../../CONFIG/STD_TYPS.h"
#include "gio_interface.h"

void GIO_ENABLE(){
SREG |= (1<<SREG_GIE);
}

void GIO_DISABLE(){
	SREG &= ~(1<<SREG_GIE);
}

#endif /* MCAL_GIO_GIO_PROGRAM_C_ */
