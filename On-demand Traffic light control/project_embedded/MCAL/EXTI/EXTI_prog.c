/*
 * EXTI_prog.c
 *
 *  Created on: Sep 30, 2022
 *      Author: fathy
 */
#include"../../LIBRARY/stdTypes.h"
#include"../../LIBRARY/errorState.h"
#include"EXTI_conf.h"
#include"EXTI_priv.h"

/********************************
 * i have initialize INTERRUPT 0 ONLY
 *********************************/
static void (*EXTI_pFunISR0Fun)(void) = NULL;
/******* static pointer to function to store the funcation when fire interrupt****/


/*
 * this function initialize the external interrupt with different modes
 */
ES_t EXTI_enuInit(void)
{
	ES_t Local_enuErrorState = ES_OK;

#if EXTI0_INT_MODE == EVENT_TRIGGERED
	GICR |= (1<<6);
#elif EXTI0_INT_MODE == POLLING
	GICR &=~(1<<6);
#else
#error exti0 configuration is wrong
#endif

	MCUCR &=~(3<<0);

#if EXTI0_SENSE_LEVEL == LOW_LEVEL

#elif EXTI0_SENSE_LEVEL == ANY_CHANGE
	MCUCR |= (1<<0);
#elif EXTI0_SENSE_LEVEL == FALLING
	MCUCR |= (2<<0);
#elif EXTI0_SENSE_LEVEL == RISING
	MCUCR |= (3<<0);
#else
#error sense level of exti 0 is wrong
#endif

	return Local_enuErrorState;
}
/*
 * this function set different modes that interrupt to work on it
 */
ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntPinNum , u8 Copy_u8SenseLevel)
{
	ES_t Local_enuErrorState = ES_OK;

	if(Copy_u8IntPinNum == INT0)
	{
		MCUCR &=~(3<<0);
		switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL:

			break;
		case ANY_CHANGE:
			MCUCR |= (1<<0);
			break;
		case FALLING:
			MCUCR |= (2<<0);
			break;
		case RISING:
			MCUCR |= (3<<0);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if(Copy_u8IntPinNum == INT1)
	{

	}
	else if(Copy_u8IntPinNum == INT2)
	{

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}
/*
 * function to enable interrupt
 */
ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntPinNum)
{
	ES_t Local_enuErrorState = ES_OK;

	if(Copy_u8IntPinNum == INT0)
	{
		GICR |= (1<<6);
	}
	else if(Copy_u8IntPinNum == INT1)
	{
		GICR |= (1<<7);
	}
	else if(Copy_u8IntPinNum == INT2)
	{
		GICR |= (1<<5);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*
 * function disable  interrupt
 */
ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntPinNum)
{
	ES_t Local_enuErrorState = ES_OK;

	if(Copy_u8IntPinNum == INT0)
	{
		GICR &=~ (1<<6);
	}
	else if(Copy_u8IntPinNum == INT1)
	{
		GICR &=~  (1<<7);
	}
	else if(Copy_u8IntPinNum == INT2)
	{
		GICR &=~  (1<<5);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*
 * function to store fun i want to do when fire interrupt
 */
ES_t EXTI_enuCallBack(void(*Copy_pFunAppFun)(void) , u8 Copy_u8IntPinNum)
{
	if(Copy_pFunAppFun != NULL)
	{
		if (Copy_u8IntPinNum == INT0)
		{
			EXTI_pFunISR0Fun = Copy_pFunAppFun;
		}
	}
	return ES_OK;
}



void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));

//int0
void __vector_1 (void)
{
	if (EXTI_pFunISR0Fun != NULL)
	{
		EXTI_pFunISR0Fun ();
	}
}

//int1
void __vector_2 (void)
{

}

//int2
void __vector_3 (void)
{

}
