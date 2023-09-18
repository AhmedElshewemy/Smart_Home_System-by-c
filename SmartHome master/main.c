
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "KEY_PAD.h"
#include "LCD.h"
#include "util/delay.h"
#include "login.h"
#include"Timers.h"
#include"USART.h"
#include"menu.h"
#include "ADC.h"
#include"LEDs.h"

 ///
void CheckLight(void){
 u16 temperature;
 temperature= ADC_U16GetDigitalValue(ADC_CHANNEL_3);
 if(temperature<=8){
	 DIO_VidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);

 }else{
	 DIO_VidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);

     }
 }




void main (void)
{


	USART();

	LEDs_TurnON();

	LCD_VidInit();

	KPAD_VidInint();

	u8 flag=Login();

	ADC_VidInit();

	Timers_VidTimer0SetCallBack(&CheckLight);
	Timers_VidTimer0Init();





if(flag==1){

 while(1){

	Menu();

}
}
 while(1);
}



