#include"LEDs.h"

void LEDs_TurnON(void)
{
	LEDsSystemModeDirection();
	LED_Light_Sensor_Direction();
}



void LEDsSystemModeDirection(){
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
}

void LED_Light_Sensor_Direction(){
	DIO_VidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);

}
