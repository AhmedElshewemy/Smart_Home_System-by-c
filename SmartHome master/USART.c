#include"USART.h"


void USART(void){
	DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN0 , DIO_INPUT );
		DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN1 , DIO_OUTPUT );

		USART_VidInit();

}
void USART_VidInit(void)
{
	u8 Local_U8UCSRCValue = 0b10000000 ;
	u16 Local_U8BaudRateValue = 51 ;

	/* Setup Baud Rate To 9600 */
	UBRRL = (u8)Local_U8BaudRateValue ;
	UBRRH = (u8)(Local_U8BaudRateValue >> 8);

	/* Normal Speed */
	CLR_BIT( UCSRA , U2X );
	/* Disable MPM */
	CLR_BIT( UCSRA , MPCM );
	/* Rx , Tx Enable*/
	SET_BIT( UCSRB , RXEN );
	SET_BIT( UCSRB , TXEN );
	/* Select Char Size --> 8bits */
	CLR_BIT( UCSRB , UCSZ2 );
	SET_BIT( Local_U8UCSRCValue , UCSZ0 );
	SET_BIT( Local_U8UCSRCValue , UCSZ1 );
	/* Select Asynch Mode */
	CLR_BIT( Local_U8UCSRCValue , UMSEL );
	/* Parity --> Disabled */
	CLR_BIT( Local_U8UCSRCValue , UPM0 );
	CLR_BIT( Local_U8UCSRCValue , UPM1 );
	/* Stop Bits --> 2 */
	SET_BIT( Local_U8UCSRCValue , USBS );

	/* Update at the Reg*/
	UCSRC = Local_U8UCSRCValue ;

}


void USART_VidSendChar( u8 Copy_U8Char )
{
	while( (GET_BIT( UCSRA ,  UDRE )) == 0 );

	UDR = Copy_U8Char ;
}


u8 USART_U8GetChar( void )
{
	u8 Local_U8Char ;
	while( (GET_BIT( UCSRA ,  RXC )) == 0 );
	Local_U8Char = UDR ;
	return Local_U8Char ;
}

