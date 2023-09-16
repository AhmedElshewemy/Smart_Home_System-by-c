#include "ADC.h"




void ADC_VidInit(void){
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);

	CLR_BIT(ADMUX,ADLAR);

	CLR_BIT(ADCSRA,ADATE);

	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_U16GetDigitalValue(u8 Copy_U8ChannelNumber){
	u16 Local_U16_value;
	ADMUX &=0b11100000;
	ADMUX |=Copy_U8ChannelNumber ;

	SET_BIT(ADCSRA,ADSC);

	while((GET_BIT(ADCSRA , ADIF))==0);

	SET_BIT(ADCSRA , ADIF);

	Local_U16_value=ADC;

	return Local_U16_value;

}

//set ref 2.56v




































