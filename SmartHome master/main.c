
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

 ///
void CheckLight(void){


	 u16 sun;
	sun= ADC_U16GetDigitalValue(ADC_CHANNEL_3);
 if(sun<=8){
	 DIO_VidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);

 }else{
	 DIO_VidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);

 }
 }
 ///


void main (void)
{
	USART();

	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
	u8 flag=Login();
	//USART();
		ADC_VidInit();
		Timers_VidTimer0SetCallBack(&CheckLight);
		Timers_VidTimer0Init();
		DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);



if(flag==1){

 while(1){

	Menu();

}
}
 while(1);
}



