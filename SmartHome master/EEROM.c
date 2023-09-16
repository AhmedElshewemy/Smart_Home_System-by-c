#include "EEROM.h"



void EEROM(void)
{
	u16 ValidPassword=0;
	u8 pass[4];
	if ( (EEPROM_Read_Byte(0X100)!=0x01) ){
		LCD_VidSetClEAR();
		LCD_VidSendString("Login for");
		LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
		LCD_VidSendString("first time");
		_delay_ms(500);

		LCD_VidSetClEAR();
		LCD_VidSendString("Set Password");
		LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
		LCD_VidSendString(":");


		u8	key;
			for(int i =0 ;i<4;i++)
			{
				key = KPD_u8GetPressedKey();
				_delay_ms(10);

						LCD_vidSendChar(key);
						key = getnum(key);
						EEPROM_Write_Byte(0X102+i,key);
						//pass[i]=key;
						ValidPassword=ValidPassword*10+key;
						 SetPassword(ValidPassword);

				}
			_delay_ms(50);

			//EEPROM_vWriteBlockToAddress(0X102,pass,4);//save the entire password as a block to the EEPROM
			//EEPROM_vWriteByteToAddress(0X100,0x01);//write the status of pass as it is set
			EEPROM_Write_Byte(0X100,0x01);//write the status of pass as it is set

			LCD_VidSetClEAR();
			LCD_VidSendString("Pass Saved");
			_delay_ms(300);
	}else{
	 //ValidPassword= EEPROM_vReadBlockFromAddress(0X102,4);//read the stored pass from the EEPROM
		u8 key=0;
		for(int i =0 ;i<4;i++)
					{
					key=EEPROM_Read_Byte(0X102+i);
					//pass[i]=key;
					ValidPassword=ValidPassword*10+key;

						}

		SetPassword(ValidPassword);
	}
}

///

u8 EEPROM_Read_Byte( u16 Address)
{

	while(EECR & (1<<EEWE));


	EEAR = Address;

	EECR |= (1<<EERE);


	return EEDR;

}




///


////


void EEPROM_Write_Byte( u16 Address, u8 Value)
{

	/* Wait for completion of previous write process*/
	while ( EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = Address;
	EECR |= (1<<EERE);
	/* Write logical one to EEMWE */
	if(EEDR!=Value){
			EEDR = Value;
			EECR |= (1<<EEMWE);
			EECR=0x03;}			/* Start eeprom write by setting EEWE */


}




///
