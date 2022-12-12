/*
 * gio_interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: MohamedAyman
 */

#ifndef MCAL_GIO_GIO_INTERFACE_H_
#define MCAL_GIO_GIO_INTERFACE_H_


#define SREG    *((volatile u8*) 0x5F)
#define SREG_GIE  7

void GIO_ENABLE();

void GIO_DISABLE();
#endif /* MCAL_GIO_GIO_INTERFACE_H_ */
