/*
 * GIE_prog.c
 *
 *  Created on: Sep 30, 2022
 *      Author: fathy
 */
#include"../../LIBRARY/stdTypes.h"
#include"../../LIBRARY/errorState.h"
#include"GIE_priv.h"

/*
 * fire global interrupt
 */
void GIE_vidEnable(void)
{
	SREG |= (1<<7);
	//asm("SEI");
}
/*
 * close global interrupt
 */
void GIE_vidDisable(void)
{
	SREG&=~(1<<7);
	//asm("CLI");
}
