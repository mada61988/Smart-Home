/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              APP              *************************************************/
/******************************************    SWC:              NONE                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:             main.c             ************************************************/

#include "../HAL/LCD/lcd_interface.h"
#include "../CONFIG/STD_TYPS.h"
#include "../HAL/KEYPAD/keypad_interface.h"
#include "../MCAL/USART/usart_interface.h"
#include "../MCAL/DIO/dio_interface.h"
#include "../MCAL/TIMER1/timer1_interface.h"
#include "../HAL/SERVO_MOTOR/servomotor_interface.h"
#include "macros.h"
#include <avr/delay.h>
void SMARTHOMEINITIALIZE();
void main () {
	SMARTHOMEINITIALIZE();
	_delay_ms(3000);
	DOOR_OPEN();
	while(1){
USART_Rx();
	}
}

