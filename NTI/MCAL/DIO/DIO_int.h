    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 28/07/2026   *****************/
 /********* File: Private File  ******************/
/************************************************/


#ifndef  DIO_INT_H
#define  DIO_INT_H


#define PORTa 0
#define PORTb 1
#define PORTc 2
#define PORTd 3

#define 	PIN0   				0
#define		PIN1				1
#define		PIN2				2
#define		PIN3				3
#define		PIN4				4
#define		PIN5				5
#define		PIN6				6
#define		PIN7				7

#define    OUTPUT				1
#define		INPUT				0

#define		HIGH				1
#define		LOW					0

void DIO_voidInitialization(void);
void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction);
void DIO_voidSetpinValue(u8 PortID,u8 PinID, u8 Value);
u8   DIO_u8GetPinValue(u8 PortID, u8 PinID);
void DIO_voidTogglePin(u8 PortID, u8 PinID);
void DIO_voidSetPortDirection(u8 PortID, u8 Direction);
void DIO_voidSetPortValue(u8 PortID, u8 Value);


#endif