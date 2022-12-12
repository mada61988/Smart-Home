/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              MCAL              *************************************************/
/******************************************    SWC:              TIMER1                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         timer1_program.c          ************************************************/
#include "..\..\CONFIG\STD_TYPS.h"
#include "timer1_register.h"
#include "timer1_interface.h"
#include "timer1_private.h"
#include "avr/delay.h"
/*
void (*compareMatchCallBackFunc)(void)=0;
void (*overFlowCallBackFunc)(void)=0;
*/
u16 servomotorCurrentPosition=2500;
void TIMER1_INIT(u16 Copy_u16Top,u16 Copy_u16CompareMatch){
	TCNT1=0;
	// Compare Match Mode, Set on Top clear on compare
	TCCR1A &= ~(1<<TCCR1A_COM1A0);
	TCCR1A |= (1<<TCCR1A_COM1A1);

	//Wage Generation Mode Fast PWM ICR1 Top
	TCCR1A &= ~(1<<TCCR1A_WGM10);
	TCCR1A |= (1<<TCCR1A_WGM11);
	TCCR1B |= (1<<TCCR1B_WGM12);
	TCCR1B |= (1<<TCCR1B_WGM13);

	TCCR1B &= ~(1<<TCCR1B_CS10);
	TCCR1B |= (1<<TCCR1B_CS11);
	TCCR1B &= ~(1<<TCCR1B_CS12);

	//TIMSK |= (1<<TIMSK_OCIE1A); //Enable Compare match interrupt
	//TIMSK |= (1<<TIMSK_TOIE1);  //Enable Overflow interrupt

	SET_ICR1(Copy_u16Top);
	OCR1A=600;
	_delay_ms(2000);
	//SET_OCR1(Copy_u16CompareMatch);
}
/*
void TIMER1_SET_COMPAREMATCH_CALLBACKFUNC(void (*callBackFunc)(void)){
	compareMatchCallBackFunc = callBackFunc;
}
void TIMER1_SET_OVERFLOW_CALLBACKFUNC(void (*callBackFunc)(void)){
	overFlowCallBackFunc = callBackFunc();
}
*/
void SET_ICR1(u16 Copy_u16Top){
	ICR1 = Copy_u16Top;
	}

void SET_OCR1(u8 direction){



	if(direction ==CLOCKWISE)OCR1A=600;
	else if(direction == ANTICLOCKWISE) OCR1A=2500;



	/*
	if(direction==CLOCKWISE && servomotorCurrentPosition > 600){
		for(;servomotorCurrentPosition>550;servomotorCurrentPosition-=50){
							OCR1A = servomotorCurrentPosition;
							_delay_ms(100);
						}
	}

	if(direction == ANTICLOCKWISE && servomotorCurrentPosition!= 2500){
		for(;servomotorCurrentPosition<2500;servomotorCurrentPosition+=50){
				OCR1A = servomotorCurrentPosition;
				_delay_ms(100);
			}
	}
*/

	/*
	if(servomotorCurrentPosition==750){
	for(;servomotorCurrentPosition<=2500;servomotorCurrentPosition+=10){
		OCR1A = servomotorCurrentPosition;
		_delay_ms(400);
	}
	}

	else {
		for(;servomotorCurrentPosition>=750;servomotorCurrentPosition-=10){
			OCR1A = servomotorCurrentPosition;
			_delay_ms(400);
		}
	}
*/
	}





void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{

}

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{

}
