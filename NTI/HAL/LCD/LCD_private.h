    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 28/07/2026   *****************/
 /********* File: Private File  ******************/
/************************************************/


#ifndef     LCD_PRIVATE_H
#define 		LCD_PRIVATE_H


#define LCD_CLEAR			  0x01  	// replace all Character with Ascii 'space'
#define LCD_HOME			  0x02  	// return Cursor tofirst Position on First Line
#define LCD_ENTRY_MODE 		  0x06      
#define LCD_DISPLAYOFF		  0x08      
#define LCD_DISPLAYON		  0x0C      
#define LCD_FUNCTION_RESET    0x30      //Reset LCD
#define LCD_FUNCTIONSET_8BIT  0x38      //2 line Display, 5*7 font
#define LCD_SETCURSOR1st	  0x80      //Set Cursor Position to 1st column
#define LCD_SETCURSOR2nd	  0xC0      //Set Cursor Position to 2nd column


static void LCD_voidPutonBus(u8 u8Char);

#endif