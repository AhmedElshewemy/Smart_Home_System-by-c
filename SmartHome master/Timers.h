

#ifndef TIMERS_H_
#define TIMERS_H_


#include"STD_TYPES.h"
#include"BIT_Math.h"
#include"avr/io.h"
#include"avr/interrupt.h"


void Timer_VidTimer1Init(void);
void Timers_VidTimer0SetCallBack( void (*Timer0_Ptr)(void) );
void Timers_VidTimer0Init(void);



#endif
