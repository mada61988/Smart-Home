/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              MCAL              *************************************************/
/******************************************    SWC:              TIMER1                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         timer1_interface.h          ************************************************/

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

void TIMER1_INIT(u16 Copy_u16Top,u16 Copy_u16CompareMatch);
void SET_ICR1(u16 Copy_u16Top);
void SET_OCR1(u8);
void TIMER1_SET_COMPAREMATCH_CALLBACKFUNC(void (*callBackFunc)(void));
void TIMER1_SET_OVERFLOW_CALLBACKFUNC(void (*callBackFunc)(void));

#define ANTICLOCKWISE 0
#define CLOCKWISE 1

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
