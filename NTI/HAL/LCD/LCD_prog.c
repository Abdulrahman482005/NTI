    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 29/07/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Bit_Math.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"


void LCD_voidLCDInit(void)
{
	_delay_ms(30);
	LCD_voidSendCommand(LCD_FUNCTIONSET_8BIT);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_DISPLAYON);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_ENTRY_MODE);
	_delay_ms(1);
}

static void LCD_voidPutonBus(u8 u8Char)
{
	DIO_voidSetpinValue(LCD_D0, GET_BIT(u8Char, 0));
    DIO_voidSetpinValue(LCD_D1, GET_BIT(u8Char, 1));
    DIO_voidSetpinValue(LCD_D2, GET_BIT(u8Char, 2));
    DIO_voidSetpinValue(LCD_D3, GET_BIT(u8Char, 3));
    DIO_voidSetpinValue(LCD_D4, GET_BIT(u8Char, 4));
    DIO_voidSetpinValue(LCD_D5, GET_BIT(u8Char, 5));
    DIO_voidSetpinValue(LCD_D6, GET_BIT(u8Char, 6));
    DIO_voidSetpinValue(LCD_D7, GET_BIT(u8Char, 7));
}

void LCD_voidSendCommand(u8 u8CMD)
{
	DIO_voidSetpinValue(LCD_RS, LOW);
	DIO_voidSetpinValue(LCD_RW, LOW);
	LCD_voidPutonBus(u8CMD);
	DIO_voidSetpinValue(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_voidSetpinValue(LCD_EN, LOW);
}

void LCD_voidSendData(u8 u8Data)
{
	DIO_voidSetpinValue(LCD_RS, HIGH);
	DIO_voidSetpinValue(LCD_RW, LOW);
	LCD_voidPutonBus(u8Data);
	DIO_voidSetpinValue(LCD_EN, HIGH);
	_delay_ms(1);
	DIO_voidSetpinValue(LCD_EN, LOW);
}

void LCD_GotoXY(u8 x, u8 y)
{
	if (y== 0)
	{
		LCD_voidSendCommand(LCD_SETCURSOR1st + x);
	}
	else if (y== 1)
	{
		LCD_voidSendCommand(LCD_SETCURSOR2nd + x);
	}
	else
	{
		// no code
	}
}

void LCD_voidWriteString(u8 * u8string)
{
	while (*u8string != '\0')
	{
		LCD_voidSendData(*u8string);
		u8string++;
	}
}

void LCD_voidWriteNumber(u8 u8Number)
{
	int ones= u8Number % 10 + 48;
	int x= u8Number / 10;
	int tens= x % 10 + 48;
	int hund= u8Number / 100 + 48;
	LCD_voidSendData(hund);
	LCD_voidSendData(tens);
	LCD_voidSendData(ones);
}

