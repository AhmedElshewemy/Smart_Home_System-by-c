#include "login.h"

 u16 Password;
 void SetPassword(u16 ValidPassword){
	 Password=ValidPassword;
	// Password=1111;

 }

 /////

 void RunBuzzer()
 {

	 LCD_VidSetClEAR();
	 LCD_VidSendString("wait..");
 	for(int i=0;i<3;i++){
 	DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN7 , DIO_OUTPUT );
 	DIO_VidSetPinValue( DIO_PORTD , DIO_PIN7 , DIO_HIGH );

 		_delay_ms(100);

 		DIO_VidSetPinValue( DIO_PORTD , DIO_PIN7 , DIO_LOW );
		_delay_ms(60);
 	}

 }
 u8 getnum(u8 key)
 {
 	switch (key)
 	{
 	     case '0' : return 0;
 	     case '1' : return 1;
 	     case '2' : return 2;
 	     case '3' : return 3;
 	     case '4' : return 4;
 	     case '5' : return 5;
 	     case '6' : return 6;
 	     case '7' : return 7;
 	     case '8' : return 8;
 	     case '9' : return 9;
 	}
 	return 50;
 }






 /////


 u8 CheckUser(u32 VildPassword){
 	   if(Password==VildPassword)
 		{

		LCD_VidSetClEAR();
		DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN5 , DIO_OUTPUT );
	    Timer_VidTimer1Init();
		LCD_VidSendString(" welcome");
		DIO_VidSetPinValue( DIO_PORTA , DIO_PIN5 , DIO_HIGH );

		_delay_ms(100);
	    return 1;

 		}
 	    else{
 			LCD_VidSetClEAR();
 			LCD_VidSendString(" wrong pass");
 			_delay_ms(60);
 			return 0;
 		}
 	}


u8 Login(void){

	u8 key;
	u8 flag=0;
	LCD_VidInit();


	LCD_VidSendString("Welcome to the");
	LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
	LCD_VidSendString("smart home");
	_delay_ms(200);
	KPAD_VidInint();

	EEROM();
	while(1)
		{
	LCD_VidSetClEAR();
	LCD_VidSendString("Select mode :");
	LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
	LCD_VidSendString("0:Admin 1:Guest");


	key = KPD_u8GetPressedKey();

	if (key=='0')
	{
     flag=LoginAdmin();
		break;
	}else if(key=='1'){
    //run buzer
		DIO_VidSetPinValue( DIO_PORTA , DIO_PIN6 , DIO_HIGH );
		RunBuzzer();
		DIO_VidSetPinValue( DIO_PORTA , DIO_PIN6 , DIO_LOW );

	}else{
		LCD_VidSetClEAR();
		LCD_VidSendString("wrong select !");
		_delay_ms(100);


	}

	}
	return flag;
}

 ////
u8 LoginAdmin (void)
{

	u16 ValidPassword=0;
	u8 key;
	u8 x=0;




	for ( x=0;x<3;x++)
	{
		LCD_VidSetClEAR();
		LCD_VidSendString("Password:");

		for(int i =0 ;i<4;i++)
		{
				key = KPD_u8GetPressedKey();
					LCD_vidSendChar(key);
					key = getnum(key);
					ValidPassword=ValidPassword*10+key;

			}
		_delay_ms(50);

		if(CheckUser(ValidPassword)){

			break;
		}

          	}
	if(x==3){
	LCD_VidSetClEAR();
	LCD_VidSendString("sorry not allowed ");
	LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
	LCD_VidSendString("more of 3");

	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH);
	return 0;
	}
	return 1;
}



