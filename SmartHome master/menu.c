/*
 * menu.c
 *
 *  Created on: Sep 13, 2023
 *      Author: btc
 */
#include"menu.h"
void getTemperature(void){
	u8 key;

	LCD_VidSetClEAR();

		USART_VidSendChar('t');
		_delay_ms(5);
		LCD_VidSendString("Temperature:");
		 key =USART_U8GetChar();
		if(key=='l'){
			LCD_VidSendString("Low");
		}else if(key=='m'){
			LCD_VidSendString("Middle");
		}else if(key=='h'){
			LCD_VidSendString("High");
		}

		LCD_VidGoToLocation(LCD_RowTwo,LCD_ColOne);
}
void Menu(void){
	u8 key;
	LCD_VidSetClEAR();
	LCD_VidSendString("Hall:0 Room1:1");
	LCD_VidGoToLocation(LCD_RowTwo,LCD_ColOne);
	LCD_VidSendString("Room2:2 Room3:3");
	key = KPD_u8GetPressedKey();
	if (key=='0')
	{
		getTemperature();
		///
		LCD_VidSendString("TV:0 LED:1");
		key = KPD_u8GetPressedKey();
		 if(key=='0'){
			USART_VidSendChar('0');

			}else if(key=='1'){

			USART_VidSendChar('1');

			}
	}else if(key=='1'){
		getTemperature();
		LCD_VidSendString(" LED:1");
				key = KPD_u8GetPressedKey();
				 if(key=='1'){
					USART_VidSendChar('a');

					}
	}else if(key=='2'){
		getTemperature();
		LCD_VidSendString("LED:2");
		key = KPD_u8GetPressedKey();
		 if(key=='2'){
			USART_VidSendChar('b');

			}
	}else if(key=='3'){
		getTemperature();
		LCD_VidSendString("LED:3");
				key = KPD_u8GetPressedKey();
				 if(key=='3'){
					USART_VidSendChar('c');

					}
	}else{
		WrongSelect();
	}
	_delay_ms(20);

	}

void WrongSelect(void)
{
	LCD_VidSetClEAR();
			LCD_VidSendString("wrong choose");
}
