/*
 * menu.c
 *
 *  Created on: Sep 13, 2023
 *      Author: btc
 */
#include"menu.h"


void Menu(void){
	u8 key;
	MessageMenu();
	key = KPD_u8GetPressedKey();
	if (key=='0')
	{
		MessagegetTemperature();
		///
		LCD_VidSendString("TV:0 LED:1");
		key = KPD_u8GetPressedKey();
		 if(key=='0'){
			USART_VidSendChar('0');

			}else if(key=='1'){

			USART_VidSendChar('1');

			}
	}else if(key=='1'){
		MessagegetTemperature();
		LCD_VidSendString(" LED:1");
				key = KPD_u8GetPressedKey();
				 if(key=='1'){
					USART_VidSendChar('a');

					}
	}else if(key=='2'){
		MessagegetTemperature();
		LCD_VidSendString("LED:2");
		key = KPD_u8GetPressedKey();
		 if(key=='2'){
			USART_VidSendChar('b');

			}
	}else if(key=='3'){
		MessagegetTemperature();
		LCD_VidSendString("LED:3");
				key = KPD_u8GetPressedKey();
				 if(key=='3'){
					USART_VidSendChar('c');

					}
	}else{
		 MessageWrongSelect();
	}
	_delay_ms(20);

	}


