    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 30/07/2026   *****************/
 /********* File: Interface File  ******************/
/************************************************/


#ifndef  EXTI_INT_H
#define  EXTI_INT_H


typedef void (*pf)(void);

#define EXIT_LOW_LEVEL      0
#define EXIT_ANY_CHANGE     1
#define EXIT_FALLING_EDGE   2
#define EXIT_RAISING_EDGE   3

#define   EXTI_INT0        0	
#define   EXTI_INT1	       1	
#define   EXTI_INT2	       2	

void EXTI_voidInitilaization (void);
void EXTI_voidSetSignalCriteria(u8 u8SensMode ,u8 EXTI);
void EXTI_voidInterruptEnable ( u8 EXTI );
void EXTI_voidInterruptDisable ( u8 EXTI );
void EXTI_voidSetCallBack( pf FunctionAddress , u8 EXTI );


#endif