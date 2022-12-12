/*
 * program.c
 *
 *  Created on: Dec 2, 2022
 *      Author: MohamedAyman
 */

#ifndef APP_PROGRAM_C_
#define APP_PROGRAM_C_
#include "../HAL/LCD/lcd_interface.h"
#include "../CONFIG/STD_TYPS.h"
#include "../HAL/KEYPAD/keypad_interface.h"
#include "../MCAL/USART/usart_interface.h"
#include "../MCAL/DIO/dio_interface.h"
#include "../MCAL/TIMER1/timer1_interface.h"
#include "../HAL/SERVO_MOTOR/servomotor_interface.h"
#include <avr/delay.h>
#include "macros.h"

void SMARTHOMEINITIALIZE(){
		 DIO_INIT();
			//u16 servoMotorIterations=750;
			//GIO_ENABLE();
			LCD_INIT();

			LCD_DISP_STR("INITIALIZING...");
			TIMER1_INIT(20000,1000);
			//SERVOMOTOR_CLOCKWISE();
			USART_INIT();
	}

void DOOR_CLOSE(){
	SERVOMOTOR_CLOCKWISE();
}
void DOOR_OPEN(){
	SERVOMOTOR_ANTICLOCKWISE();
}
#endif /* APP_PROGRAM_C_ */
