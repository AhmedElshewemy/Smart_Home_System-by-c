#include "DIO.h"

/*Function for the direction*/
void DIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8pin, u8 Copy_U8Direction)
{
	switch (Copy_U8Direction)
	{
	       case DIO_INPUT:
	    	   switch (Copy_U8Port)
	    	   {
	    	        case DIO_PORTA :
	    	        	CLR_BIT(DDRA, Copy_U8pin);
	    	        	break;

	    	        case DIO_PORTB:
	    	        	CLR_BIT(DDRB, Copy_U8pin);
	    	        	break;

	    	        case DIO_PORTC:
	    	        	CLR_BIT(DDRC, Copy_U8pin);
	    	        	break;

	    	        case DIO_PORTD:
	    	        	CLR_BIT(DDRD, Copy_U8pin);
	    	        	break;


	    	   }break;
	       case DIO_OUTPUT:
	    	   switch (Copy_U8Port)
	    	  	  {
	    	  	    case DIO_PORTA :
	    	            SET_BIT(DDRA, Copy_U8pin);
 	    	            break;

	    	  	    case DIO_PORTB:
	    	  	    	SET_BIT(DDRB, Copy_U8pin);
	    	  	    	break;

	    	  	   case DIO_PORTC:
	    	  	    	 SET_BIT(DDRC, Copy_U8pin);
	    	  	    	 break;

	    	  	    case DIO_PORTD:
	    	  	    	 SET_BIT(DDRD, Copy_U8pin);
	    	  	    	  break;


	    	  	  }break;


	}

}




/*Function for the  value*/
void DIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8pin, u8 Copy_U8Value)
{
	switch (Copy_U8Value)
		{
		       case DIO_LOW:
		    	   switch (Copy_U8Port)
		    	   {
		    	        case DIO_PORTA :
		    	        	CLR_BIT(PORTA, Copy_U8pin);
		    	        	break;

		    	        case DIO_PORTB:
		    	        	CLR_BIT(PORTB, Copy_U8pin);
		    	        	break;

		    	        case DIO_PORTC:
		    	        	CLR_BIT(PORTC, Copy_U8pin);
		    	        	break;

		    	        case DIO_PORTD:
		    	        	CLR_BIT(PORTD, Copy_U8pin);
		    	        	break;


		    	   } break;
		       case DIO_HIGH:
		    	   switch (Copy_U8Port)
		    	  	  {
		    	  	    case DIO_PORTA :
		    	            SET_BIT(PORTA, Copy_U8pin);
	 	    	            break;

		    	  	    case DIO_PORTB:
		    	  	    	SET_BIT(PORTB, Copy_U8pin);
		    	  	    	break;

		    	  	   case DIO_PORTC:
		    	  	    	 SET_BIT(PORTC, Copy_U8pin);
		    	  	    	 break;

		    	  	    case DIO_PORTD:
		    	  	    	 SET_BIT(PORTD, Copy_U8pin);
		    	  	    	  break;


		    	  	  }break;


		}
}
/*Function to set port Direction*/
void DIO_VidPortDirection (u8 Copy_U8Port , u8  Copy_U8Direction)
{

     switch (Copy_U8Port)
		   {
		      case DIO_PORTA :
		        	DDRA = Copy_U8Direction;
		           	break;

	   	      case DIO_PORTB:
		    	  DDRB = Copy_U8Direction;
		    	  break;

		      case DIO_PORTC:
		    	   DDRC = Copy_U8Direction;
		    	    break;

		      case DIO_PORTD:
		    	   DDRD = Copy_U8Direction;
		    	    break;


		    	   }
		}


/*Function to set port value*/
void DIO_VidPortValue (u8 Copy_U8Port , u8  Copy_U8Value)
{
	switch (Copy_U8Port)
	{
	          case DIO_PORTA :
			    	PORTA = Copy_U8Value;
		 	        break;

		      case DIO_PORTB:
			    	PORTB = Copy_U8Value;
			    	 break;

			  case DIO_PORTC:
			       PORTC = Copy_U8Value;
			    	  break;

			  case DIO_PORTD:
			    	PORTD = Copy_U8Value;
			    	   break;

	}

}

/*Function to set port Direction*/
void DIO_VidTogglePinValue (u8 Copy_U8Port , u8  Copy_U8Pin)
{
	switch (Copy_U8Port)
	{
               	 case DIO_PORTA :
               		TOGGLE_BIT(PORTA,Copy_U8Pin);
					break;

			      case DIO_PORTB:
			    	  TOGGLE_BIT(PORTB,Copy_U8Pin);
				    	 break;

				  case DIO_PORTC:
					  TOGGLE_BIT(PORTC,Copy_U8Pin);
				    	  break;

				  case DIO_PORTD:
					  TOGGLE_BIT(PORTD,Copy_U8Pin);
				    	   break;
	}

}

/*function to get state of input value*/
u8 DIO_U8GetPinValue(u8 Copy_U8Port,u8  Copy_U8Pin)
{
	u8 read;
	switch (Copy_U8Port)
		{
	               	 case DIO_PINA :
	               		read= GET_BIT(PINA,Copy_U8Pin);
						break;

				      case DIO_PINB:
				    	  read= GET_BIT(PINB,Copy_U8Pin);
					    	 break;

					  case DIO_PINC:
						  read=GET_BIT(PINC,Copy_U8Pin);
					    	  break;

					  case DIO_PIND:
						  read= GET_BIT(PIND,Copy_U8Pin);
					    	   break;
		}
	return read;
}








