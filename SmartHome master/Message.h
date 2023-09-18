/*
 * Message.h
 *
 *  Created on: Sep 18, 2023
 *      Author: btc
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include "DIO.h"
#include "STD_TYPES.h"

#include "avr/io.h"
#include "avr/interrupt.h"
#include "KEY_PAD.h"
#include "LCD.h"
#include "util/delay.h"
#include "EEROM.h"



	void MessageWelcomeToEnterSystem(void);
	void MessageWelcome(void);

	void  MessageWrongPassword();

	void  MessageWrongSelect();
	void  MessageSelect();
	void  MessageNotAllowedMore_3();
	void MessageLoginForFirstPassowrd(void);
	void MessageMenu(void);
	void MessagegetTemperature(void);




	 void RunBuzzer();




#endif /* MESSAGE_H_ */
