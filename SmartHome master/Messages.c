#include"Message.h"


	void MessageWelcomeToEnterSystem(void)
  {
	 LCD_VidSetClEAR();
	DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN5 , DIO_OUTPUT );
	Timer_VidTimer1Init();
	LCD_VidSendString(" welcome");
	DIO_VidSetPinValue( DIO_PORTA , DIO_PIN5 , DIO_HIGH );
	_delay_ms(100);

  }
	void MessageWelcome(void)
	  {
		LCD_VidSendString("Welcome to the");
		LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
		LCD_VidSendString("smart home");
		_delay_ms(200);
	  }

	void MessageMenu(void)
	  {
		LCD_VidSetClEAR();
		LCD_VidSendString("Hall:0 Room1:1");
		LCD_VidGoToLocation(LCD_RowTwo,LCD_ColOne);
		LCD_VidSendString("Room2:2 Room3:3");
	  }


	void MessageSetPassowrd(void)
		  {
		LCD_VidSetClEAR();
		LCD_VidSendString("Password:");

		  }

	void MessageLoginForFirstPassowrd(void)
	 {
		LCD_VidSetClEAR();
		LCD_VidSendString("Login for");
		LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
		LCD_VidSendString("first time");
		_delay_ms(300);
		LCD_VidSetClEAR();
		LCD_VidSendString("Set Password");
		LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
		LCD_VidSendString(":");
			  }

	void  MessageSavePassword()
		{
		LCD_VidSetClEAR();
		LCD_VidSendString("Pass Saved");
		_delay_ms(300);
		}

	void  MessageWrongPassword()
	{
		LCD_VidSetClEAR();
		LCD_VidSendString(" wrong pass");
		_delay_ms(60);
	}

	void  MessageWrongSelect()
		{
		LCD_VidSetClEAR();
		LCD_VidSendString("wrong select !");
		_delay_ms(100);
		}

	void  MessageSelect()
			{
		LCD_VidSetClEAR();
		LCD_VidSendString("Select mode :");
		LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
		LCD_VidSendString("0:Admin 1:Guest");
			}


	 void RunBuzzer()
	 {

		 LCD_VidSetClEAR();
		 LCD_VidSendString("wait..");
	 	for(int i=0;i<3;i++)
	 	{
			DIO_VidSetPinValue( DIO_PORTD , DIO_PIN7 , DIO_HIGH );

			_delay_ms(100);

			DIO_VidSetPinValue( DIO_PORTD , DIO_PIN7 , DIO_LOW );
			_delay_ms(60);
	 	}

	 }


		void  MessageNotAllowedMore_3()
			{
			LCD_VidSetClEAR();
			LCD_VidSendString("sorry not allowed ");
			LCD_VidGoToLocation(LCD_RowTwo, LCD_ColOne);
			LCD_VidSendString("more of 3");
			DIO_VidSetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH);
			}



		void MessagegetTemperature(void)
		{
			u8 key;

			LCD_VidSetClEAR();

				USART_VidSendChar('t');
				_delay_ms(5);
				LCD_VidSendString("Temperature:");
				 key =USART_U8GetChar();
				if(key=='l'){
					LCD_VidSendString("Low");
				}else if(key=='m'){
					LCD_VidSendString("Middle");
				}else if(key=='h'){
					LCD_VidSendString("High");
				}

				LCD_VidGoToLocation(LCD_RowTwo,LCD_ColOne);
		}



