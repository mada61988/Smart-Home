/*
 * servomotor_program.c
 *
 *  Created on: Dec 9, 2022
 *      Author: MohamedAyman
 */

#include "../../CONFIG/STD_TYPS.h"
#include "../../MCAL/TIMER1/timer1_interface.h"


void SERVOMOTOR_CLOCKWISE(){
SET_OCR1(CLOCKWISE);
}

void SERVOMOTOR_ANTICLOCKWISE(){
SET_OCR1(ANTICLOCKWISE);
}
