    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 30/07/2026   *****************/
 /********* File: Private File  ******************/
/************************************************/


#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H


#define MCUCR    *((volatile u8 *)0x55)
#define GICR     *((volatile u8 *)0x5B)
#define SREG     *((volatile u8 *)0x5F)
#define GIFR     *((volatile u8 *)0x5A)

#endif