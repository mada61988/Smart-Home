/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              HAL              *************************************************/
/******************************************    SWC:             LCD                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         lcd_program.c           ************************************************/

#include <avr/delay.h>
#include "../../CONFIG/STD_TYPS.h"
#include "../../MCAL/DIO/dio_register.h"
#include "lcd_register.h"
#include "lcd_interface.h"
#include "..\..\MCAL\DIO\dio_interface.h"



void LCD_INIT(){
DIO_INIT();
	// INIT LCD IN 4BIT MODE

	//1- WAIT FOR MORE THAN 30ms
	_delay_ms(35);


	//2- Commands
	LCD_SEND_CMD(0x33);
	LCD_SEND_CMD(0x32);	// Send for 4 bit initialization of LCD
	LCD_SEND_CMD(0x28);	// 2 line, 5*7 matrix in 4-bit mode
	LCD_SEND_CMD(0x0C);	/// Display on cursor off
	LCD_SEND_CMD(0x06);	// Increment cursor (shift cursor to right)
	LCD_SEND_CMD(0x01);


}
void LCD_SEND_CMD(char cmd){

	/*
	 * SENDING UPPER NIBBLE
	 * */
	LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
	// RS=0
	LCD_PORT &= ~(1<<RS);

	//RW=0
	LCD_PORT &= ~(1<<RW);

	//Enable=1
	LCD_PORT |= (1<<Enable);



	_delay_ms(5);

	LCD_PORT &= ~(1<<Enable);


	/*
		 * SENDING LOWER NIBBLE
		 * */

	LCD_PORT = (LCD_PORT & 0x0F) | (cmd <<4);


	//Enable=1
		LCD_PORT |= (1<<Enable);

		_delay_ms(5);

		LCD_PORT &= ~(1<<Enable);

		_delay_ms(5);

}
void LCD_DISP_CHAR(char c){
	//if(LCD_DISP_CURR_POS==0x90) LCD_DISP_CURR_POS=0xC0;
//LCD_SEND_XY();
	/*
	 * SENDING UPPER NIBBLE
	 * */
	//data
	LCD_PORT = (LCD_PORT & 0x0F)| (c & 0xF0);
	//RS=1
	LCD_PORT |= (1<<RS);

	//RW=0
	LCD_PORT &= ~(1<<RW);

	//Enable =1
	LCD_PORT |= (1<<Enable);

	_delay_ms(5);

	//Enable =0
		LCD_PORT &= ~ (1<<Enable);



		/*
		 * SENDING LOWER NIBBLE
		 * */
		LCD_PORT = (LCD_PORT & 0x0F) | (c <<4);

		//Enable =1
		LCD_PORT |= (1<<Enable);

		_delay_ms(5);

		//Enable =0
		LCD_PORT &= ~ (1<<Enable);

		//LCD_DISP_CURR_POS++;


}
void LCD_DISP_STR(char arr[]){
int i=0;

while(arr[i] != '\0'){
	LCD_DISP_CHAR(arr[i]);
	i++;
}
}
void LCD_SEND_XY(){
	/*Send Upper Nibble*/
	//==============================================================
	//LCD_PORT = (LCD_PORT & 0x0F) | (LCD_DISP_CURR_POS & 0xF0);
	//RS=0
		LCD_PORT &= ~(1<<RS);

	//RW=0
	LCD_PORT &= ~(1<<RW);

	//Enable=1
	LCD_PORT |= (1<<Enable);

	_delay_ms(1);

	//Enable =0
	LCD_PORT &= ~(1<<Enable);

	/*Send Lower Nibble*/
	//==============================================================
	//LCD_PORT = (LCD_PORT & 0x0F) | (LCD_DISP_CURR_POS << 4);
	//RS=0
		LCD_PORT &= ~(1<<RS);

	//RW=0
	LCD_PORT &= ~(1<<RW);



	//Enable=1
	LCD_PORT |= (1<<Enable);

	_delay_ms(1);

	//Enable =0
	LCD_PORT &= ~(1<<Enable);
}
