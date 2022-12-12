/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              MCAL              *************************************************/
/******************************************    SWC:             USART                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         usart_program.c           ************************************************/

#include "usart_register.h"
#include "usart_interface.h"
#include "../../CONFIG/STD_TYPS.h"
#include "../../CONFIG/BIT_MATH.h"
#include "../DIO/dio_register.h"
#include "../../HAL/SERVO_MOTOR/servomotor_interface.h"
#include "../../HAL/LED/led_interface.h"
#include "../../HAL/LCD/lcd_interface.h"
u8 dataRx[2];

void USART_INIT(){

	u8 UCSRCValue=0;

		UCSRCValue |= (1<<7);
		UCSRCValue |= (1<<UCSRC_UCSZ1);
		UCSRCValue |= (1<<UCSRC_UCSZ0);

/*
	//This bit selects between accessing the UCSRC or the UBRRH Register. It is read asone when reading UCSRC. The URSEL must be one when writing the UCSRC.
	UCSRC |= (1<<UCSRC_URSEL);

	//USART Mode Select 1=SYNC
	UCSRC |= (1<<UCSRC_UMSEL);

	//Parity Mode 00=Disabled
	UCSRC &= ~(1<<UCSRC_UPM0);
	UCSRC &= ~(1<<UCSRC_UPM1);

	// USBS Bit Settings 0=1-bit
	UCSRC &= ~(1<<UCSRC_USBS);

	//. UCSZ Bits Settings  011=8-bit
	UCSRC |= (1<<UCSRC_UCSZ0);
	UCSRC |= (1<<UCSRC_UCSZ1);

	//UBRRH
	UCSRC &= ~(1<<UCSRC_URSEL);

		// Clock Polarity
	UCSRC &= ~(1<<UCSRC_UCPOL);
	*/

		UCSRC=UCSRCValue;
	UCSRB &= ~(1<<UCSRB_UCSZ2);




	//Baud rate = 9600
	UBRRL=51;

	//RECIVER ENABLE
	UCSRB |= (1<<UCSRB_RXEN);

	//TRANSIMTE ENABLE
	UCSRB |= (1<<UCSRB_TXEN);
}

void USART_Tx(char data){
while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
UDR=data;
}

void USART_Rx(){

/*
	for(u8 i=0;i<2;i++){


			while(GET_BIT(UCSRA,UCSRA_RXC)==0);
					dataRx[i]= UDR;
	}

	if(dataRx == 'O' ||dataRx == 'o')SERVOMOTOR_ANTICLOCKWISE();
	else 	if(dataRx == 'C' ||dataRx == 'c')SERVOMOTOR_CLOCKWISE();

	*/
	for(u8 i=0;i<2;i++){
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

		dataRx[i]= UDR;
	}

						if((dataRx[0]=='O') && (dataRx[1]=='D')){
							SERVOMOTOR_ANTICLOCKWISE();
							LCD_SEND_CMD(0x01);
							LCD_DISP_STR("DOOR OPENED");
						}
						if((dataRx[0]=='C') && (dataRx[1]=='D')){
							SERVOMOTOR_CLOCKWISE();
							LCD_SEND_CMD(0x01);
							LCD_DISP_STR("DOOR CLOSED");
						}
						if((dataRx[0]=='L') && (dataRx[1]=='O')){
							LED_ON();
							LCD_SEND_CMD(0x01);
							LCD_DISP_STR("LIGHTS ON");
						}
						if((dataRx[0]=='L') && (dataRx[1]=='F')){
							LED_OFF();
							LCD_SEND_CMD(0x01);
							LCD_DISP_STR("LIGHTS OFF");
						}

}
