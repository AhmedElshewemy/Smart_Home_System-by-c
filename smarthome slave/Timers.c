

#include"Timers.h"



void (*Timer0_PFun)(void);



void Timers_VidTimer0SetCallBack( void (*Timer0_Ptr)(void) )
{
	Timer0_PFun = Timer0_Ptr ;
}
//servo motor


void Timer_VidTimer1Init(void){
	// select mode
	//fast PWM -->14
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//select OC1A PIN -->Fast PWM
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	//setup value of ICR1

	ICR1=19999;

	//setup OCR1A--> for the angle of serve
	OCR1A=500;
	//presalar-->8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}


void Timers_VidTimer0Init(void)
{
	/*Select the MODE*/
	/*Normal Mode*/
	//CLR_BIT( TCCR0 , WGM00 );
	//CLR_BIT( TCCR0 , WGM01 );
	/*CTC Mode*/
//	CLR_BIT( TCCR0 , WGM00 );
//	SET_BIT( TCCR0 , WGM01 );
	//fast PWM mode
	SET_BIT( TCCR0 , WGM00 );
	SET_BIT( TCCR0 , WGM01 );

	/*setup the mode of OC0 pin*/

	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*Enable the Interrupt*/
	/*GIE*/
	/*SET_BIT( SREG , 7 );*/
	/*PIE -- > OVF */
	//SET_BIT( TIMSK , TOIE0 );
	/*PIE -- > CTC */
	//SET_BIT( TIMSK , OCIE0 );

	/* setup the preload value*/
	//TCNT0 = 192 ;

	/*Setup the OCR Value*/
	//OCR0 = 99 ;

	/*Select Prescaler factor*/
	/*/8 */
	CLR_BIT( TCCR0 , CS00 );
	SET_BIT( TCCR0 , CS01 );
	CLR_BIT( TCCR0 , CS02 );
	OCR0=0;
}

