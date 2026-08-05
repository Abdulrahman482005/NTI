    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 01/08/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"


//Set ADC Pin Is Enable in DIO Configure

void ADC_voidInit(void)
{
    //Disable ADC
    CLR_BIT(ADCSRA,7);
    //Disable Start Conveerion
    CLR_BIT(ADCSRA,6);
    //Disable Auto Trigger
    CLR_BIT(ADCSRA,5);
    //Clear Interrupt Flag
    CLR_BIT(ADCSRA,4);
    //Disable ADC Interrupt
    CLR_BIT(ADCSRA,3);
    //Select Left or Right Adlustment
    #if REG_ADJ==LEFT_ADJUSTMEN
	   SET_BIT(ADMUX,5);
    #elif REG_ADJ==RIGHT_ADJUSTMEN
	   CLR_BIT(ADMUX,5);
    #endif
    // Slect ADC Channel
    ADMUX &= 0XE0;
    ADMUX |= ADC_CHANNEL;
    // Select Clock Prescaller
    ADCSRA = (ADCSRA&0xF8) | 0x07;
	// Select Voltage Reference
    SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
}
//ADC Enable
void ADC_voidADCEnable(void)
{
	SET_BIT(ADCSRA,7);
}

//ADC Disable
void ADC_voidADCDisable(void)
{
	CLR_BIT(ADCSRA,7);
}

void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA,3);
}

void ADC_voidStartConverstion(void)
{
	SET_BIT(ADCSRA,6);
}

u16 ADC_u16Read(void)
{
	#if REG_ADJ == LEFT_ADJUSTMEN
	//read ADCH;
	u16 x = ADCH;
	return x;
	#elif REG_ADJ == RIGHT_ADJUSTMEN
	// read ADCH##ADCL;
	u8 y = ADC;
	return y;
	#endif
}

void ADC_voidAutoTrigger(void)
{
	//Set auto Trigger Enable
	SET_BIT(ADCSRA,5);
	// set the source of auto Trigger
	SFIOR &= 0x1F;
	SFIOR |= TRIGGER_SELECt;
}

pf ADC_CallBack;

void ADC_voidSetCallBack(pf FunctionAddress)
{
	if (FunctionAddress!=0)
	{
	ADC_CallBack = FunctionAddress;
	}
}

void __vector_20(void) __attribute__((signal, used));
void __vector_20(void)
{
	if (ADC_CallBack!=0)
	{
	ADC_CallBack();
	}
}