#include"Timers.h"

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

////
void (*Timer0_PFun)(void);


void Timers_VidTimer0Init(void)
{
	/*Select the MODE*/
	/*Normal Mode*/
	CLR_BIT( TCCR0 , WGM00 );
	CLR_BIT( TCCR0 , WGM01 );
	/*CTC Mode*/
//	CLR_BIT( TCCR0 , WGM00 );
//	SET_BIT( TCCR0 , WGM01 );

	/*Enable the Interrupt*/
	/*GIE*/
	SET_BIT( SREG , 7 );
	/*PIE -- > OVF */
	SET_BIT( TIMSK , TOIE0 );
	/*PIE -- > CTC */
//	SET_BIT( TIMSK , OCIE0 );

	/* setup the preload value*/
	TCNT0 = 113 ;

	/*Setup the OCR Value*/
//	OCR0 = 99 ;

	/*Select Prescaler factor*/
	/*/64 */
//	SET_BIT( TCCR0 , CS00 );
//	SET_BIT( TCCR0 , CS01 );
//	CLR_BIT( TCCR0 , CS02 );
	////
	/*Select Prescaler factor*/
		/*/8 */
		CLR_BIT( TCCR0 , CS00 );
		SET_BIT( TCCR0 , CS01 );
		CLR_BIT( TCCR0 , CS02 );
}

void Timers_VidTimer0SetCallBack( void (*Timer0_Ptr)(void) )
{
	Timer0_PFun = Timer0_Ptr ;
}



//
//ISR(TIMER0_OVF_vect)
//{
//	static u16 Local_U16CounterOVF = 0 ;
//	Local_U16CounterOVF++ ;
//	if( Local_U16CounterOVF == 976 )
//	{
//		Local_U16CounterOVF = 0 ;
//		TCNT0 = 113 ;
//
//		Timer0_PFun();
//	}
//
//}



ISR(TIMER0_OVF_vect)
{
	static u16 Local_U16CounterOVF = 0 ;
	Local_U16CounterOVF++ ;
	if( Local_U16CounterOVF == 3907 )
	{
		Local_U16CounterOVF = 0 ;
		TCNT0 = 192 ;

		Timer0_PFun();
	}

}




/*
 *          Toggle Led Every One sec using Timer --> OVF mode
 *
 *          F_CPU = 8M Hz , prescaler = 8 , res = 8 bits
 *
 *          number of OVF = ?    , Preload value = ?
 *
 *          Timer Frequency =  8M / 8 = 1M
 *          Timer Tick Time = 1 / 1M = 1us   ----> inc every 1us
 *          Time of OVFs  = 1us * 256 = 256 us
 *
 *				1sec = 1000000us > 256us
 *
 *          Number of OVFs = 1000000u / 256u = 3906.25 ---> 3906 complete OVF + 0.25 OVF
 *
 *          Number of ticks for  0.25  = 0.25 * 256 = 64
 *
 *          prelaod value  = 256 - 64 = 192 tick  ---> 3907
 *
 *
//////
 *          Toggle Led Every One sec using Timer --> CTC mode
 *
 *          F_CPU = 8M Hz , prescaler = 8 , res = 8 bits , OCR = 99
 *
 *            Preload value = ? , number of CTC  = ?
 *
 *          Timer Frequency =  8M / 8 = 1M
 *          Timer Tick Time = 1 / 1M = 1us   ----> inc every 1us
 *          Time of CTCs  = 100 * 1us = 100us
 *
 *				1sec = 1000000us > 100us
 *
 *          Number of CTCs = 1000000u / 100u = 10000 time
 *
 *          prelaod value  = 0
 *
 *
 *
 */










