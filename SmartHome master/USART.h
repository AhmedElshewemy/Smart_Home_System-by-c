#ifndef USART_H_
#define USART_H_


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"

#include"avr/io.h"



void USART(void);

void USART_VidInit(void);

void USART_VidSendChar( u8 Copy_U8Char );


u8 USART_U8GetChar( void );






#endif
