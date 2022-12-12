/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              MCAL              *************************************************/
/******************************************    SWC:             USART                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         usart_register.h           ************************************************/

#ifndef MCAL_USART_USART_REGISTER_H_
#define MCAL_USART_USART_REGISTER_H_


/*USART Register Interfacing*/

#define UDR                     *((volatile u8*)0x2C)                        //USART IO Data Register

#define UCSRA                   *((volatile u8*)0x2B)                        //USART Control And Status Register A
#define UCSRA_RXC               7                                            // USART Receive Complete
#define UCSRA_TXC               6                                            // USART Transmit Complete
#define UCSRA_UDRE              5                                            // USART Data Register Empty
#define UCSRA_U2x               1                                            //This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous operation

#define UCSRB                   *((volatile u8*)0x2A)                        //USART Control And Status Register B
#define UCSRB_RXCIE             7                                            //RX Complete Interrupt Enable
#define UCSRB_TXCIE             6                                            //TX Complete Interrupt Enable
#define UCSRB_UDRIE             5                                            //USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN              4                                            //Receiver Enable
#define UCSRB_TXEN              3                                            //Transmitter Enable
#define UCSRB_UCSZ2             2                                            //The UCSZ2 bits combined with the UCSZ1:0 bit in UCSRC sets the number of data bits (Character Size) in a frame the receiver and transmitter use.
#define UCSRB_RXB8              1                                            //RXB8 is the ninth data bit of the received character when operating with serial frames with nine data bits. Must be read before reading the low bits from UDR
#define UCSRB_TXB8              0                                            //TXB8 is the ninth data bit in the character to be transmitted when operating with serial frames with nine data bits. Must be written before writing the low bits to UDR

#define UCSRC                   *((volatile u8*)0x40)                        //USART Control and Status Register C
#define UCSRC_URSEL             7                                            //Register Select
#define UCSRC_UMSEL             6                                            //USART Mode Select
#define UCSRC_UPM1              5                                            //Parity Mode
#define UCSRC_UPM0              4                                            //Parity Mode
#define UCSRC_USBS              3                                            //USART Stop Bit
#define UCSRC_UCSZ1             2                                            //Character Size
#define UCSRC_UCSZ0             1                                            //Character Size
#define UCSRC_UCPOL             0                                            //UCPOL

/*USART Baud Rate Registers – UBRRL and UBRRH*/
#define UBRRL                   *((volatile u8*) 0x29)                        //USART Baud Rate Register HIGH
#define UBRRH                   *((volatile u8*) 0x40)                        //USART Baud Rate Register LOW
#define UBRRH_URSEL             15





#endif /* MCAL_USART_USART_REGISTER_H_ */
