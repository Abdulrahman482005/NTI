    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 28/07/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidInitialization(void)
{
	DDRA = DIO_PORTA_DIRECTIONS;
	DDRB = DIO_PORTB_DIRECTIONS;
	DDRC = DIO_PORTC_DIRECTIONS;
	DDRD = DIO_PORTD_DIRECTIONS;
}

void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
	if(PortID < 4 && PinID < 8)
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case PORTa: SET_BIT(DDRA, PinID); break;
				case PORTb: SET_BIT(DDRB, PinID); break;
				case PORTc: SET_BIT(DDRC, PinID); break;
				case PORTd: SET_BIT(DDRD, PinID); break;
			}
		}
		else if(Direction == INPUT)
		{
			switch(PortID)
			{
				case PORTa: CLR_BIT(DDRA, PinID); break;
				case PORTb: CLR_BIT(DDRB, PinID); break;
				case PORTc: CLR_BIT(DDRC, PinID); break;
				case PORTd: CLR_BIT(DDRD, PinID); break;
			}
		}
		else
		{
			
			// this else for any valye not input or output
		}
	}
	else
	{
		// No Code
	}
}

void DIO_voidSetpinValue(u8 PortID,u8 PinID, u8 Value) 
{
	if(PortID < 4 && PinID < 8)
	{
		if(Value == HIGH)
		{
			switch(PortID)
			{
				case PORTa: SET_BIT(PORTA, PinID); break;
				case PORTb: SET_BIT(PORTB, PinID); break;
				case PORTc: SET_BIT(PORTC, PinID); break;
				case PORTd: SET_BIT(PORTD, PinID); break;
			}
		}
		else if(Value == LOW)
		{
			switch(PortID)
			{
				case PORTa: CLR_BIT(PORTA, PinID); break;
				case PORTb: CLR_BIT(PORTB, PinID); break;
				case PORTc: CLR_BIT(PORTC, PinID); break;
				case PORTd: CLR_BIT(PORTD, PinID); break;
			}
		}
		else
		{
			
			// this else for any valye not 1 or 0
		}
	}
	else
	{
		// No Code
	}
}

u8 DIO_u8GetPinValue(u8 PortID, u8 PinID)
{
    	u8 x = 0;    // x is the get_bit 
	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
	    {
			case PORTa: x = GET_BIT(PINA, PinID); break;
			case PORTb: x = GET_BIT(PINB, PinID); break;
			case PORTc: x = GET_BIT(PINC, PinID); break;
			case PORTd: x = GET_BIT(PIND, PinID); break;
		}
	}
	else
	{
		// No Code
	}
	return x;
}

void DIO_voidTogglePin(u8 PortID, u8 PinID)
{
	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
	    {
			case PORTa: TOG_BIT(PORTA, PinID); break;
			case PORTb: TOG_BIT(PORTB, PinID); break;
			case PORTc: TOG_BIT(PORTC, PinID); break;
			case PORTd: TOG_BIT(PORTD, PinID); break;
		}
	}
	else
	{
		// No Code
	}
}

void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{
	if(PortID < 4 && Direction < 256)
	{
		switch(PortID)
	    {
			case PORTa: ASG_PORT(DDRA, Direction); break;
			case PORTb: ASG_PORT(DDRB, Direction); break;
			case PORTc: ASG_PORT(DDRC, Direction); break;
			case PORTd: ASG_PORT(DDRD, Direction); break;
		}
	}
	else
	{
		// No Code
	}
}

void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
	if(PortID < 4 && Value < 256)
	{
		switch(PortID)
	    {
			case PORTa: ASG_PORT(PORTA, Value); break;
			case PORTb: ASG_PORT(PORTB, Value); break;
			case PORTc: ASG_PORT(PORTC, Value); break;
			case PORTd: ASG_PORT(PORTD, Value); break;
		}
	}
	else
	{
		// No Code
	}
}
