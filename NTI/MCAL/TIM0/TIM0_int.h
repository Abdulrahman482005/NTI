    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 02/08/2026   *****************/
 /********* File: Interface File  ****************/
/************************************************/


#ifndef  TIM0_INT_H
#define  TIM0_INT_H


typedef void (*pf)(void);

#define NORMAL_MODE             0
#define CTC_MODE                1
#define PWM_MODE                2
#define FAST_PWM_MODE           3

#define INVERTED_PWM            0
#define NON_INVERTED_PWM        1

#define NO_CLOCK                0x00
#define NO_PRESCALING           0x01  
#define PRESCALER_8             0x02  
#define PRESCALER_64            0x03 
#define PRESCALER_256           0x04 
#define PRESCALER_1024          0x05  
#define EXT_CLK_FALLING_EDGE    0x06  
#define EXT_CLK_RISING_EDGE     0x07

void TIM0_voidinit(void);

void TIM0_voidEnableOVInterrupt(void);
void TIM0_voidDisableOVInterrupt(void);
void TIM0_voidSetOVReg(u8 u8OVRegValue);
u8 TIM0_u8ReadOVReg(void);
void TIM0_voidOVSetCallBack(pf OVFunctionAddress);

void TIM0_voidEnableCTCInterrupt(void);
void TIM0_voidDisableCTCInterrupt(void);
void TIM0_voidSetCTCReg(u8 u8CTCRegValue);
u8 TIM0_u8ReadCTCCTCReg(void);
void TIM0_voidCTCSetCallBack(pf CTCFunctionAddress);

void TIM0_voidSetPWMDutyCycle(u8 u8DutyCyclePercentage);
void TIM0_voidSetPWMValue(u8 u8Value);

void TIM0_voidFastPWMSetDutyCycle(u8 u8DutyCyclePercentage);
void TIM0_voidSetFastPWMValue(u8 u8Value);

#endif