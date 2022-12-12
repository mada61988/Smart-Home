/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022                    *************************************************/
/******************************************   NAME:          MohamedAyman                   *************************************************/
/******************************************  LAYER:              HAL                       *************************************************/
/******************************************    SWC:              KEYPAD                    *************************************************/
/*****************************************     VER:               01                       *************************************************/
/*****************************************    FILE:             keypad_program.c            ************************************************/


#include "../../CONFIG/STD_TYPS.h"
#include "../../CONFIG/BIT_MATH.h"
#include "../../MCAL/DIO/dio_register.h"
#include "keypad_interface.h"
#include "../../HAL/LCD/lcd_interface.h"
u8 KPD_ARRAY[4][4] = {{'7','8','9','%'},
					{'4','5','6','*'},
					{'1','2','3','-'},
					{'P','0','=','+'}};

u8 KEYPAD_GET_PRESSED_KEY(){
	u8 columns=0,rows=0;
	for(columns =0;columns<4;columns++){
		// 1- Set Column LOW
		KEYPAD_PORT &= ~(1<<columns);

		for(rows=0;rows<4;rows++){
			if(!GET_BIT(KEYPAD_PIN,(rows+4))){
				while(!GET_BIT(KEYPAD_PIN,(rows+4)));

			return KPD_ARRAY[rows][columns];

			}


		}
		KEYPAD_PORT |= (1<<columns);
	}

return NULL;
}
