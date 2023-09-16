#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "util/delay.h"
#include"stdlib.h"
#define LCD_RS_PORT             DIO_PORTA
#define LCD_RW_PORT             DIO_PORTA
#define LCD_ENABLE_PORT         DIO_PORTA
#define LCD_RS_pin              DIO_PIN0
#define LCD_R_W_Pin             DIO_PIN1
#define LCD_Enable_pin          DIO_PIN2
#define LCD_DATA_COMMAND_PORT   DIO_PORTC
#define FUNCTION_SET            0b00111000
#define LCD_RowOne              1
#define LCD_RowTwo              2
#define LCD_ColOne              0x00
#define LCD_ColTwo              0x01
#define LCD_ColThree            0x02
#define LCD_ColFour             0x03
#define LCD_ColFive             0x04
#define LCD_ColSix              0x05
#define LCD_ColSeven            0x06
#define LCD_ColEight            0x07
#define LCD_ColNine             0x08
#define LCD_ColTen              0x09
#define LCD_ColEleven           0x0A
#define LCD_ColTwelve           0x0B
#define LCD_ColThirteen         0x0C
#define LCD_ColFourteen         0x0D
#define LCD_ColFiveteen         0x0E
#define LCD_ColSixteen          0x0F


#define LCD_RowOneStart 0x80
#define LCD_RowTwoStart 0xc0

#define LCD_CLEAR        0X01
/* LCD initialization function*/
void LCD_VidInit(void) ;

/* LCD Send Command Function*/
void LCD_VidSendCommand (u8 command);

/* LCD send Data Function*/
void LCD_vidSendChar (u8 Data);

/*Go to location*/
void LCD_VidGoToLocation (u8 Copy_U8RowNumber, u8 Copy_U8ColoumNumber);

/*Send String*/
void LCD_VidSendString(u8 * Copy_Pu8String);

/*Send Number*/
void LCD_VidSendNum(u32 Copy_U32Number);

void LCD_VidSendNumber( u32 Copy_U32Number );


/*LCD clear*/
void LCD_VidSetClEAR ();

#endif
