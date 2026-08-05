    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 30/07/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void EXTI_voidInitilaization (void)
{
	//Set the Sense Mode
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	//Clear Enable Bit
	CLR_BIT(GICR,5);
	CLR_BIT(GICR,6);
	CLR_BIT(GICR,7);
	//Clear Flag Bit
	CLR_BIT(GIFR,5);
	CLR_BIT(GIFR,6);
	CLR_BIT(GIFR,7);
	
	CLR_BIT(SREG,7);
	}


void EXTI_voidSetSignalCriteria(u8 u8SensMode ,u8 EXTI)
{
	//to chage the Sense Mode
	if ( u8SensMode < 4 && EXTI ==0 )
	{
		switch ( u8SensMode )
		{
			case EXIT_LOW_LEVEL: 
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case EXIT_ANY_CHANGE: 
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case EXIT_FALLING_EDGE: 
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
			case EXIT_RAISING_EDGE: 
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
		    default:
			break;
		}
	}
	else if (u8SensMode < 4 && EXTI == 1 )
	{
		switch ( u8SensMode )
		{
			case EXIT_LOW_LEVEL: 
			CLR_BIT(MCUCR,1);
			CLR_BIT(MCUCR,0);
			break;
			case EXIT_ANY_CHANGE: 
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			case EXIT_FALLING_EDGE: 
			CLR_BIT(MCUCR,1);
			SET_BIT(MCUCR,0);
			break;
			case EXIT_RAISING_EDGE: 
			SET_BIT(MCUCR,1);
			SET_BIT(MCUCR,0);
			break;
		    default:
			break;
		}
	}
	else 
	{
		// no code
	}
}

void EXTI_voidInterruptEnable ( u8 EXTI )
{
    //Set enable Bit
	if (EXTI==EXTI_INT0)
	{
        SET_BIT(GIFR,6);
		SET_BIT(GICR,6);
		SET_BIT(SREG,7);
	}
	else if (EXTI==EXTI_INT1)
	{
        SET_BIT(GIFR,7);
		SET_BIT(GICR,7);
		SET_BIT(SREG,7);	
	}
	else
	{
		// no code
	}
}

void EXTI_voidInterruptDisable ( u8 EXTI )
{
    //clear enable Bit
	if (EXTI==EXTI_INT0)
	{
        CLR_BIT(GICR,6);
	}
	else if (EXTI==EXTI_INT1)
	{
        CLR_BIT(GICR,7);	
	}
	else
	{
		// no code
	}
}

pf x = 0;
pf y = 0;

void EXTI_voidSetCallBack( pf FunctionAddress , u8 EXTI )
{
	if (EXTI==EXTI_INT0)
	{
        x = FunctionAddress;
	}
	if (EXTI==EXTI_INT1)
	{
        y = FunctionAddress;	
	}
	else
	{
		// no code
	}
}

void __vector_1 (void)__attribute__((signal,used));
void __vector_1 (void)
{
	// Action of Interrupt
	if ( x!=0 )
	{
	x();
	}
}
void __vector_2 (void)__attribute__((signal,used));
void __vector_2 (void)
{
	// Action of Interrupt
	if ( y!=0 )
	{
	y();
	}
}