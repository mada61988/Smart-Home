/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              MCAL              *************************************************/
/******************************************    SWC:              TIMER1                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         timer1_register.h          ************************************************/

#ifndef MCAL_TIMER1_TIMER1_REGISTER_H_
#define MCAL_TIMER1_TIMER1_REGISTER_H_

//Timer/Counter1 Control Register A � TCCR1A
#define TCCR1A               *((volatile u8*)0x4F)
#define TCCR1A_WGM10          0
#define TCCR1A_WGM11          1
#define TCCR1A_FOC1B          2
#define TCCR1A_FOC1A          3
#define TCCR1A_COM1B0         4
#define TCCR1A_COM1B1         5
#define TCCR1A_COM1A0         6
#define TCCR1A_COM1A1         7





#define TCCR1B               *((volatile u8*)0x4E)
#define TCCR1B_CS10          0
#define TCCR1B_CS11          1
#define TCCR1B_CS12          2
#define TCCR1B_WGM12         3
#define TCCR1B_WGM13         4
//#define TCCR1B          5   RESERVED
#define TCCR1B_ICES1         6
#define TCCR1B_ICNC1         7


//#define TCNT1H               *((volatile u8*)0x4D)
#define TCNT1               *((volatile u16*)0x4C)

//#define OCR1AH               *((volatile u8*)0x4B)
#define OCR1A               *((volatile u16*)0x4A)

//#define OCR1BH               *((volatile u8*)0x49)
#define OCR1B                *((volatile u16*)0x48)

//#define ICR1H               *((volatile u8*)0x47)
#define ICR1                *((volatile u16*)0x46)

#define TIMSK               *((volatile u8*)0x59)
#define TIMSK_OCIE1A         4
#define TIMSK_TICIE1         5
#define TIMSK_TOIE1          2


#define TIFR               *((volatile u8*)0x58)
#define TIFR_TOV1          2
#define TIFR_OCF1B         3
#define TIFR_OCF1A         4
#define TIFR_ICF1          5


#endif /* MCAL_TIMER1_TIMER1_REGISTER_H_ */
