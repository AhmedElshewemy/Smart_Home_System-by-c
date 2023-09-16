
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "util/delay.h"
#include "Timers.h"
#include "ADC.h"

 ///
void main (void)
{

	USART();
	ADC_VidInit();
	Timers_VidTimer0Init();
	u16 Local_U16Temp;
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN4,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);
	DIO_VidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);

	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);






	u8 x = 0 ;
	u8 temp='n';

while(1){

	x = USART_U8checkGetChar();

			if(x=='t'){
				_delay_ms(5);
				USART_VidSendChar(temp);

			}else if(x=='0'){
			DIO_VidTogglePinValue(DIO_PORTD,DIO_PIN3);

			}else if(x=='1'){
				DIO_VidTogglePinValue(DIO_PORTD,DIO_PIN4);

			}else if(x=='a'){
				DIO_VidTogglePinValue(DIO_PORTD,DIO_PIN5);

			}else if(x=='b'){
				DIO_VidTogglePinValue(DIO_PORTD,DIO_PIN6);

			}else if(x=='c'){
				DIO_VidTogglePinValue(DIO_PORTD,DIO_PIN7);

			}else if(x=='0'){

			}


	Local_U16Temp = ADC_U16GetTempValue( ADC_CHANNEL_0 );

	     _delay_ms(50);

	 	 if((Local_U16Temp<18)){
	 			DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_INPUT);
	 		//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_LOW);
				OCR0=0;

	 		 temp='l';
	 	 }else{
			DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	 		//DIO_VidSetPinValue(DIO_PORTB,DIO_PIN3,DIO_HIGH);

			  if((Local_U16Temp>=18)&&(Local_U16Temp<25)){
						OCR0=45;
			 			temp='m';

						_delay_ms(50);
				  }else if((Local_U16Temp>25) && (Local_U16Temp<30)){
						OCR0=102;
			 			temp='h';
						_delay_ms(50);
					}
					else if((Local_U16Temp>30)){
									OCR0=255;
									_delay_ms(50);
								}
	 					}

	}

}


