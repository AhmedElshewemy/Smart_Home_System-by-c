#ifndef DIO_H
#define DIO_H

#include "DIO.h"
#include "avr/io.h"
#include "util/delay.h"
#include "STD_TYPES.h"

#define KPAD_ROW1            0
#define KPAD_ROW2            1
#define KPAD_ROW3            2
#define KPAD_ROW4            3

#define KPAD_COL1            4
#define KPAD_COL2            5
#define KPAD_COL3            6
#define KPAD_COL4            7

#define KPAD_RowNum          4
#define KPAD_ColNum          3

#define KPAD_PORT            DIO_PORTB
#define KPAD_ROWS_COL_PINS   0x0F
#define KPAD_ROWS_COL_INIT   0xFF

/* Key_Pad initlization*/
void KPAD_VidInint(void);

/*Key_Pad get Key pressed*/
u8 KPD_u8GetPressedKey(void);

#endif
