#ifndef EEROM_H_
#define EEROM_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr\io.h"
#include "DIO.h"
#include "KEY_PAD.h"
#include "LCD.h"
#include "login.h"

void EEROM(void);


u8 EEPROM_Read_Byte( u16 Address);

void EEPROM_Write_Byte( u16 Address, u8 Value);


#endif /* EEROM_H_ */
