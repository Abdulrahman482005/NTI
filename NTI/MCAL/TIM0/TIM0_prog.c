    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 02/08/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Std_Types.h"
#include "Bit_Math.h"
#include "TIM0_int.h"
#include "TIM0_private.h"
#include "TIM0_config.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

void TIM0_voidinit(void)
{
    //Select Prescaller
	TCCR0 &= 0xF8;
	TCCR0 |= PRESCALLER;
    //Select Mode
	#if TIM0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	#elif TIM0_MODE == CTC_MODE
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	#elif TIM0_MODE == PWM_MODE
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	#elif TIM0_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	#endif
	//Select Output Pin
	#if TIM0_PWM_OUTPUT == INVERTED_PWM
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#elif TIM0_PWM_OUTPUT == NON_INVERTED_PWM
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#else
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
	#endif
    //Clear Bit 4 -5
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
    //disable overflow interrupt
	CLR_BIT(TIMSK,0);
    //disable on Compare match interrupt
	CLR_BIT(TIMSK,1);
    //Clear overflow flag
	SET_BIT(TIFR,0);
    //Clear on Compare match flag
	SET_BIT(TIFR,1);
    //Clear TCNT0
	TCNT0 = 0x00;
    //Clear OCR
	OCR0 = 0x00;
}
/********************************************************************/
//NORMAL_MODE
void TIM0_voidEnableOVInterrupt(void)
{
    // to Enable theinterrupt ofOver flow
	SET_BIT(TIMSK,0);
}
void TIM0_voidDisableOVInterrupt(void)
{
	// to Disable theinterrupt ofOver flow
	CLR_BIT(TIMSK,0);
}

void TIM0_voidSetOVReg(u8 u8OVRegValue)
{
    //to Set the overflow Register(TCNT0) with specificValue
	TCNT0 = u8OVRegValue;
}
u8 TIM0_u8ReadOVReg(void)
{
    //to read the overflow Register(TCNT0)
	return TCNT0;
}

pf FunctionAddress1;

void TIM0_voidOVSetCallBack(pf OVFunctionAddress)
{
	if (OVFunctionAddress!= NULL )
	{
	    FunctionAddress1 = OVFunctionAddress;
	}
}
//to Set theCall Back Function ofOverflow

//For Overflow
void __vector_11(void) __attribute__((signal, used));
void __vector_11(void)
{
	if (FunctionAddress1!= NULL )
	{
	    FunctionAddress1();
	}
}
/********************************************************************************/
//CTC_MODE
void TIM0_voidEnableCTCInterrupt(void)
{
    // to Enable theinterrupt of CTC
	SET_BIT(TIMSK,1);
}


void TIM0_voidDisableCTCInterrupt(void)
{
	// to Disable the interrupt of CTC
	CLR_BIT(TIMSK,1);
}


void TIM0_voidSetCTCReg(u8 u8CTCRegValue)
{
    //to Set the CTC Register(OCR0) with specificValue
	OCR0 = u8CTCRegValue;
}


u8 TIM0_u8ReadCTCCTCReg(void)
{
    //to read the CTC Register(OCR0)
	return OCR0;
}

pf FunctionAddress2;
void TIM0_voidCTCSetCallBack(pf CTCFunctionAddress)
{
	if (CTCFunctionAddress!= NULL )
	{
	    FunctionAddress2 = CTCFunctionAddress;
	}
}
//to Set theCall Back Function ofOverflow
//for On Compare Match
void __vector_10(void) __attribute__((signal, used));
void __vector_10(void)
{
	if (FunctionAddress2!= NULL )
	{
	    FunctionAddress2();
	}
}
/********************************************************************/
//PWM_MODE
void TIM0_voidSetPWMDutyCycle(u8 u8DutyCyclePercentage)
{
    if (u8DutyCyclePercentage <= 100)
    {
        u8 u8OCRValue = ((u16)u8DutyCyclePercentage * 255) / 100;
        OCR0 = u8OCRValue;
    }
}

void TIM0_voidSetPWMValue(u8 u8Value)
{
    OCR0 = u8Value;
}
/********************************************************************/
//FAST_PWM_MODE
void TIM0_voidFastPWMSetDutyCycle(u8 u8DutyCyclePercentage)
{
    if (u8DutyCyclePercentage <= 100)
    {
        #if TIM0_PWM_OUTPUT == NON_INVERTED_PWM
            OCR0 = ((u16)u8DutyCyclePercentage * 255) / 100;
        #elif TIM0_PWM_OUTPUT == INVERTED_PWM
            OCR0 = 255 - (((u16)u8DutyCyclePercentage * 255) / 100);   
        #endif
    }
}

void TIM0_voidSetFastPWMValue(u8 u8Value)
{
	#if TIM0_PWM_OUTPUT == NON_INVERTED_PWM
        OCR0 = u8Value;
    #elif TIM0_PWM_OUTPUT == INVERTED_PWM
        OCR0 = 255 - u8Value;   
    #endif
}