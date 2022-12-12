/*
 * dio_register.h
 *
 *  Created on: Dec 5, 2022
 *      Author: MohamedAyman
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

/*******************
 * DIO-REGISTERS
*******************/
#define DDRA *((volatile u8 *)0x3A)
#define PINA *((volatile u8 *)0x39)
#define PORTA *((volatile u8 *)0x3B)

#define DDRB *((volatile u8 *)0x37)
#define PINB *((volatile u8 *)0x36)
#define PORTB *((volatile u8 *)0x38)

#define DDRC *((volatile u8 *)0x34)
#define PINC *((volatile u8 *)0x33)
#define PORTC *((volatile u8 *)0x35)

#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND *((volatile u8*) 0x30)
/*******************/

#endif /* MCAL_DIO_DIO_REGISTER_H_ */
