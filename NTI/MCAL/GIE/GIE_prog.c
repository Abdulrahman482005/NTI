    /************************************************/
   /********* Author: Abdulrahman Mohamed **********/
  /********* Date  : 01/08/2026   *****************/
 /********* File: Program File  ******************/
/************************************************/


#include "Std_Types.h"
#include "Bit_Math.h"
#include "GIE_int.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnable(void)
{
	// Enable the GLOBAL Interupt Enable Bit  --> SREG
    SET_BIT(SREG,7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
    // Disable the GLOBAL Interupt Enable Bit
}