#include "login.h"

 u16 Password;
 void SetPassword(u16 ValidPassword){
	 Password=ValidPassword;
 }


 u8 CheckUser(u32 VildPassword){
 	   if(Password==VildPassword)
 		{
 		  MessageWelcomeToEnterSystem();
	    return 1;

 		}
 	    else{
 	 		  MessageWrongPassword();
 			return 0;
 		}
 	}



 /////




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


u8 Login(void){

	u8 key;
	u8 flag=0;

	MessageWelcome();

	EEROM();

	while(1)

	{
		MessageSelect();
	key = KPD_u8GetPressedKey();

	if (key=='0')
	{
     flag=LoginAdmin();
		break;
	}
	else if(key=='1'){
    //run buzer
		DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN7 , DIO_OUTPUT );
		DIO_VidSetPinValue( DIO_PORTA , DIO_PIN6 , DIO_HIGH );
		RunBuzzer();
		DIO_VidSetPinValue( DIO_PORTA , DIO_PIN6 , DIO_LOW );

	}
	else
		{
		 MessageWrongSelect();
	    }

	}
	return flag;
}


u8 LoginAdmin (void)
{

	u16 ValidPassword=0;
	u8 key;
	u8 x=0;

	for ( x=0;x<3;x++)
	{
		 MessageSetPassowrd();

		for(int i =0 ;i<4;i++)
		{
			key = KPD_u8GetPressedKey();
			LCD_vidSendChar(key);
			key = getnum(key);
			ValidPassword=ValidPassword*10+key;
		}

		if(CheckUser(ValidPassword)){
			break;
		}

          	}
	if(x==3){
		MessageNotAllowedMore_3();
	return 0;
	}
	return 1;
}



