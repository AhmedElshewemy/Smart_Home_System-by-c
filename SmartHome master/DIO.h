#ifndef DIO_H_
#define DIO_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr\io.h"

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PINA 0
#define DIO_PINB 1
#define DIO_PINC 2
#define DIO_PIND 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_LOW 0
#define DIO_HIGH 1

#define DIO_PORT_Clearing   0x00  // 0b0000 0000
#define DIO_PORT_Setting    0xFF  // 0b1111 1111


/*Function for pin the direction*/
void DIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8pin, u8 Copy_U8Direction);

/*Function for the  value*/
void DIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8pin, u8 Copy_U8Value);

/*Function to set port Direction*/
void DIO_VidPortDirection (u8 Copy_U8Port , u8  Copy_U8Direction);

/*Function to set port value*/
void DIO_VidPortValue (u8 Copy_U8Port , u8  Copy_U8Value);

/*Function to set port Direction*/
void DIO_VidTogglePinValue (u8 Copy_U8Port , u8  Copy_U8Pin);

/*function to get state of input value*/
u8 DIO_U8GetPinValue(u8 Copy_U8Port,u8  Copy_U8Pin);
#endif
