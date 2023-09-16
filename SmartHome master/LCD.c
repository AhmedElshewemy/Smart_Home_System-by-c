#include "LCD.h"


void LCD_VidInit(void)
{
	//set the directions
	DIO_VidSetPinDirection(LCD_RS_PORT, LCD_RS_pin, DIO_OUTPUT );
	DIO_VidSetPinDirection(LCD_RW_PORT,LCD_R_W_Pin,DIO_OUTPUT);
	DIO_VidSetPinDirection(LCD_ENABLE_PORT, LCD_Enable_pin, DIO_OUTPUT);
	DIO_VidPortDirection(LCD_DATA_COMMAND_PORT,DIO_PORT_Setting);
	_delay_ms(35);
	// function set command
	LCD_VidSendCommand(FUNCTION_SET);
	// 0b0011NF00 while N>>line number(1) , F>>font size(0)
	_delay_ms(10);
	LCD_VidSendCommand(0b00001100);
	_delay_ms(10);
	LCD_VidSendCommand(0x01);
	_delay_ms(10);
	LCD_VidSendCommand(0b00000110);



}

void LCD_VidSendCommand (u8 command)
{
	DIO_VidSetPinValue(DIO_PORTA,LCD_RS_pin,DIO_LOW);
	DIO_VidSetPinValue(DIO_PORTA,LCD_R_W_Pin,DIO_LOW);
	DIO_VidPortValue(LCD_DATA_COMMAND_PORT,command );
	DIO_VidSetPinValue(DIO_PORTA,LCD_Enable_pin, DIO_HIGH);
	_delay_us(1);
	DIO_VidSetPinValue(DIO_PORTA,LCD_Enable_pin, DIO_LOW);

}


void LCD_vidSendChar(u8 Data)
{
	DIO_VidSetPinValue(LCD_RS_PORT,LCD_RS_pin,DIO_HIGH);
	DIO_VidSetPinValue(LCD_RW_PORT,LCD_R_W_Pin,DIO_LOW);
	DIO_VidPortValue(LCD_DATA_COMMAND_PORT,Data );
	DIO_VidSetPinValue(LCD_ENABLE_PORT,LCD_Enable_pin, DIO_HIGH);
	_delay_us(1);
	DIO_VidSetPinValue(LCD_ENABLE_PORT,LCD_Enable_pin, DIO_LOW);

}

/*Go to location*/
void LCD_VidGoToLocation (u8 Copy_U8RowNumber, u8 Copy_U8ColoumNumber)
{
	 _delay_ms(2);
	  switch(Copy_U8RowNumber)
	    {

	        case LCD_RowOne: LCD_VidSendCommand(LCD_RowOneStart+ Copy_U8ColoumNumber);
	                         break;
	        case LCD_RowTwo: LCD_VidSendCommand(LCD_RowTwoStart + Copy_U8ColoumNumber);
	                         break;
	    }
}

/*Send String*/
void LCD_VidSendString(u8 * Copy_Pu8String)
{

  while(*Copy_Pu8String != '\0' ) // \0 is the last element in the arrray
  {
    LCD_vidSendChar(*Copy_Pu8String);
    Copy_Pu8String++;

  }
}
//
//void LCD_VidSendString( u8 *Copy_Pu8String )
//{
//	for( int i = 0 ; Copy_Pu8String[i] != '\0' ; i++ )
//	{
//		LCD_VidSendChar( Copy_Pu8String[i] );
//	}
//}


///

/*Send Number*/
void LCD_VidSendNum(u32 Copy_U32Number)
{
  u8 nums[32];
  itoa(Copy_U32Number, nums , 10);  //convert integer data type to string data type ,10 (base-DEC)
  LCD_VidSendString(nums);

}

void LCD_VidSendNumber( u32 Copy_U32Number )
{
	u32 Local_u32Counter=1 , Local_u32Digit=0;

	if (Copy_U32Number == 0)
	{
		LCD_vidSendChar('0');
	}
	else
	{
		while (Copy_U32Number/Local_u32Counter != 0)
		{
			Local_u32Counter *= 10;
		}
		Local_u32Counter /=10;

		while (Local_u32Counter != 0)
		{
			Local_u32Digit = Copy_U32Number/Local_u32Counter;

			LCD_vidSendChar(Local_u32Digit + '0');

			Copy_U32Number = Copy_U32Number%Local_u32Counter;

			Local_u32Counter /= 10;
		}
	}
}


/////





/*LCD clear*/
void LCD_VidSetClEAR()
{
	LCD_VidSendCommand(LCD_CLEAR);
	LCD_VidGoToLocation(LCD_RowOne,LCD_ColOne);

}

