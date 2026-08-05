    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 01/08/2026   *****************/
 /********* File: Interface File  ****************/
/************************************************/


#ifndef  ADC_INT_H
#define  ADC_INT_H


typedef void (*pf)(void);

#define FREE_RUNNING      0x1F

#define   ADC0            0	
#define   ADC1            1	
#define   ADC2            2	
#define   ADC3            3	
#define   ADC4            4	
#define   ADC5            5	
#define   ADC6            6
#define   ADC7            7

void ADC_voidInit(void);
void ADC_voidADCEnable(void);
void ADC_voidADCDisable(void);
u16 ADC_u16Read(void);
void ADC_voidStartConverstion(void);
void ADC_voidAutoTrigger(void);
void ADC_voidInterruptEnable(void);
void ADC_voidSetCallBack(pf FunctionAddress);

#endif