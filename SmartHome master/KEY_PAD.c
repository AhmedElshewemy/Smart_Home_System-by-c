#include "KEY_PAD.h"

//4x3
const u8 arr[KPAD_RowNum][KPAD_ColNum]= {{'1','2','3'},
			                             {'4','5','6'},
			                             {'7','8','9'},
								         {'*','0','#'}};
void KPAD_VidInint()
{
	DIO_VidPortDirection(KPAD_PORT, KPAD_ROWS_COL_PINS );
	//DDRx = 0b11110000 , (most bits are columns) , (least bits are Rows)
	DIO_VidPortValue(KPAD_PORT,KPAD_ROWS_COL_INIT);
	//port = 0b11111111, most bits (o/p high), least bits (pull up)
}

u8 KPD_u8GetPressedKey(void){


	u8 Local_U8ColCounter ;
    u8 Local_U8RowCounter ;
	u8 Local_U8Pressed ;
	u8 Local_u8ReturnValue = 20 ;
	while(1){
	for (Local_U8ColCounter =0 ; Local_U8ColCounter<KPAD_ColNum ; Local_U8ColCounter++)
	{
		 DIO_VidSetPinValue(KPAD_PORT,Local_U8ColCounter, DIO_LOW);

		    for(Local_U8RowCounter=0; Local_U8RowCounter < KPAD_RowNum; Local_U8RowCounter++ )
		    {//loop for rows
		    	Local_U8Pressed= DIO_U8GetPinValue(KPAD_PORT,Local_U8RowCounter+4);

		        /* CHECK IF SWITCH IS PRESSED */
		      if( Local_U8Pressed == DIO_LOW)
		      {
		    	  Local_u8ReturnValue = arr[Local_U8RowCounter][Local_U8ColCounter];
		          /* Polling ( wait till button is released ) */
		        while(Local_U8Pressed == DIO_LOW  )
		        {
			    	Local_U8Pressed= DIO_U8GetPinValue(KPAD_PORT,Local_U8RowCounter+4);
		        }
		        _delay_ms(10);
		        DIO_VidSetPinValue(KPAD_PORT, Local_U8ColCounter, DIO_HIGH);
		        return Local_u8ReturnValue;

		      }
		    }
		      /* DEACTIVATE CURRENT COLUMN */
		    DIO_VidSetPinValue(KPAD_PORT, Local_U8ColCounter, DIO_HIGH);
		  }
	}

}

