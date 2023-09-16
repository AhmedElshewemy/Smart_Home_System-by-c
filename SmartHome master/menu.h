/*
 * menu.h
 *
 *  Created on: Sep 13, 2023
 *      Author: btc
 */

#ifndef MENU_H_
#define MENU_H_
#include "DIO.h"
#include "STD_TYPES.h"
#include"USART.h"

#include "avr/io.h"
#include "avr/interrupt.h"
#include "KEY_PAD.h"
#include "LCD.h"
#include "util/delay.h"
#include"Timers.h"

void Menu(void);

void WrongChoose(void);


#endif /* MENU_H_ */
