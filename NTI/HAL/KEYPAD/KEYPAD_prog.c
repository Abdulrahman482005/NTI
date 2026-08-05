    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 30/07/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Bit_Math.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_int.h"

void KEYPAD_voidInitialization(void)
{
	DIO_voidSetpinValue(KEYPAD_C1, HIGH);
	DIO_voidSetpinValue(KEYPAD_C2, HIGH);
	DIO_voidSetpinValue(KEYPAD_C3, HIGH);
	DIO_voidSetpinValue(KEYPAD_C4, HIGH);
	
	DIO_voidSetpinValue(KEYPAD_R1, HIGH);
	DIO_voidSetpinValue(KEYPAD_R2, HIGH);
	DIO_voidSetpinValue(KEYPAD_R3, HIGH);
	DIO_voidSetpinValue(KEYPAD_R4, HIGH);
}
u8 KEYPAD_pressed_key(void)
{
	 u8 Value_Row=0;
	u8 KEY =0;
	
    DIO_voidSetpinValue(KEYPAD_C1, LOW);
	DIO_voidSetpinValue(KEYPAD_C2, HIGH);
	DIO_voidSetpinValue(KEYPAD_C3, HIGH);
	DIO_voidSetpinValue(KEYPAD_C4, HIGH);
	
	Value_Row  = DIO_u8GetPinValue(KEYPAD_R1);
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R2)<<1;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R3)<<2;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R4)<<3;
	
	switch (Value_Row)
	{
		case 0b00001110: KEY = '1'; break;
		case 0b00001101: KEY = '4'; break;
		case 0b00001011: KEY = '7'; break;
		case 0b00000111: KEY = '*'; break;
		default: break;

	}
	
	DIO_voidSetpinValue(KEYPAD_C1, HIGH);
	DIO_voidSetpinValue(KEYPAD_C2, LOW);
	DIO_voidSetpinValue(KEYPAD_C3, HIGH);
	DIO_voidSetpinValue(KEYPAD_C4, HIGH);
	
	Value_Row  = 0;
	Value_Row  = DIO_u8GetPinValue(KEYPAD_R1);
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R2)<<1;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R3)<<2;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R4)<<3;
	
	switch (Value_Row)
	{
		case 0b00001110: KEY = '2'; break;
		case 0b00001101: KEY = '5'; break;
		case 0b00001011: KEY = '8'; break;
		case 0b00000111: KEY = '0'; break;
		default: break;
	}
	
	DIO_voidSetpinValue(KEYPAD_C1, HIGH);
	DIO_voidSetpinValue(KEYPAD_C2, HIGH);
	DIO_voidSetpinValue(KEYPAD_C3, LOW);
	DIO_voidSetpinValue(KEYPAD_C4, HIGH);
	
	Value_Row  = 0;
	Value_Row  = DIO_u8GetPinValue(KEYPAD_R1);
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R2)<<1;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R3)<<2;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R4)<<3;
	
	switch (Value_Row)
	{
		case 0b00001110: KEY = '3'; break;
		case 0b00001101: KEY = '6'; break;
		case 0b00001011: KEY = '9'; break;
		case 0b00000111: KEY = '#'; break;
		default: break;
	}
	
	DIO_voidSetpinValue(KEYPAD_C1, HIGH);
	DIO_voidSetpinValue(KEYPAD_C2, HIGH);
	DIO_voidSetpinValue(KEYPAD_C3, HIGH);
	DIO_voidSetpinValue(KEYPAD_C4, LOW);
	
	Value_Row  = 0;
	Value_Row  = DIO_u8GetPinValue(KEYPAD_R1);
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R2)<<1;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R3)<<2;
	Value_Row |= DIO_u8GetPinValue(KEYPAD_R4)<<3;
	
	switch (Value_Row)
	{
		case 0b00001110: KEY = 'A'; break;
		case 0b00001101: KEY = 'B'; break;
		case 0b00001011: KEY = 'C'; break;
		case 0b00000111: KEY = 'D'; break;
		default: break;
	}

	return KEY;
}
  
	
	
	