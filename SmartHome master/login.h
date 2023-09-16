/*
 * login.h
 *
 *  Created on: Sep 6, 2023
 *      Author: btc
 */

#ifndef LOGIN_H_
#define LOGIN_H_
#include "DIO.h"
#include "STD_TYPES.h"

#include "avr/io.h"
#include "avr/interrupt.h"
#include "KEY_PAD.h"
#include "LCD.h"
#include "util/delay.h"
#include "EEROM.h"


u8 getnum(u8 key);
u8 Login (void);

u8 LoginAdmin(void);

#endif /* LOGIN_H_ */
