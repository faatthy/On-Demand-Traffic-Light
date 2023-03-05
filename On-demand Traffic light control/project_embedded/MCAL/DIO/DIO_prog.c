/*
 * DIO_prog.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Ahmed El-Gaafrawy
 */
// public libraries
#include "../../LIBRARY/stdTypes.h"
//#include "BIT_MATH.h
#include "../../LIBRARY/errorState.h"

//lower layer libraries

//my libraries
#include "DIO_conf.h"
#include "DIO_priv.h"
/******
 * function use :
 * this function set the direcation of pin as input or output
 */

ES_t DIO_enuSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState = ES_OK;

	if (Copy_u8GroupID <= DIO_u8GROUP_D &&
			Copy_u8PinID <=  DIO_u8PIN7 &&
			Copy_u8Direction <= DIO_u8OUTPUT)
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A:
			DDRA &=~ (DIO_u8BIT_MASK   << Copy_u8PinID);
			DDRA |=  (Copy_u8Direction << Copy_u8PinID);
			break;
		case DIO_u8GROUP_B:
			DDRB &=~ (DIO_u8BIT_MASK   << Copy_u8PinID);
			DDRB |=  (Copy_u8Direction << Copy_u8PinID);
			break;
		case DIO_u8GROUP_C:
			DDRC &=~ (DIO_u8BIT_MASK   << Copy_u8PinID);
			DDRC |=  (Copy_u8Direction << Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			DDRD &=~ (DIO_u8BIT_MASK   << Copy_u8PinID);
			DDRD |=  (Copy_u8Direction << Copy_u8PinID);
			break;
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*******
 * this function set the pin high or low
 * float or pulledup
 */
ES_t DIO_enuSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_OK;

	if (Copy_u8GroupID <= DIO_u8GROUP_D &&
			Copy_u8PinID <=  DIO_u8PIN7 &&
			Copy_u8Value <= DIO_u8HIGH)
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A:
			if (Copy_u8Value == DIO_u8HIGH ||
					Copy_u8Value == DIO_u8PULL_UP)
				PORTA |= (DIO_u8BIT_MASK << Copy_u8PinID);

			else if (Copy_u8Value == DIO_u8LOW ||
					Copy_u8Value == DIO_u8FLOAT)
				PORTA &=~ (DIO_u8BIT_MASK << Copy_u8PinID);

			break;
		case DIO_u8GROUP_B:
			if (Copy_u8Value == DIO_u8HIGH ||
					Copy_u8Value == DIO_u8PULL_UP)
				PORTB |= (DIO_u8BIT_MASK << Copy_u8PinID);

			else if (Copy_u8Value == DIO_u8LOW ||
					Copy_u8Value == DIO_u8FLOAT)
				PORTB &=~ (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		case DIO_u8GROUP_C:
			if (Copy_u8Value == DIO_u8HIGH ||
					Copy_u8Value == DIO_u8PULL_UP)
				PORTC |= (DIO_u8BIT_MASK << Copy_u8PinID);

			else if (Copy_u8Value == DIO_u8LOW ||
					Copy_u8Value == DIO_u8FLOAT)
				PORTC &=~ (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			if (Copy_u8Value == DIO_u8HIGH ||
					Copy_u8Value == DIO_u8PULL_UP)
				PORTD |= (DIO_u8BIT_MASK << Copy_u8PinID);

			else if (Copy_u8Value == DIO_u8LOW ||
					Copy_u8Value == DIO_u8FLOAT)
				PORTD &=~ (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*
 * this function toggle the pin
 */
ES_t DIO_enuTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8GroupID <= DIO_u8GROUP_D &&
			Copy_u8PinID <=  DIO_u8PIN7)
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A:
			PORTA ^= (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		case DIO_u8GROUP_B:
			PORTB ^= (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		case DIO_u8GROUP_C:
			PORTC ^= (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		case DIO_u8GROUP_D:
			PORTD ^= (DIO_u8BIT_MASK << Copy_u8PinID);
			break;
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*
 * this function get the value in pin
 * return this value in pointer
 */
ES_t DIO_enuGetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_OK;

	if (Copy_pu8Value != NULL)
	{
		if (Copy_u8GroupID <= DIO_u8GROUP_D &&
				Copy_u8PinID <= DIO_u8PIN7)
		{
			switch(Copy_u8GroupID)
			{
			case DIO_u8GROUP_A:
				*Copy_pu8Value = ((PINA >> Copy_u8PinID ) & DIO_u8BIT_MASK);
				break;
			case DIO_u8GROUP_B:
				*Copy_pu8Value = ((PINB >> Copy_u8PinID ) & DIO_u8BIT_MASK);
				break;
			case DIO_u8GROUP_C:
				*Copy_pu8Value = ((PINC >> Copy_u8PinID ) & DIO_u8BIT_MASK);
				break;
			case DIO_u8GROUP_D:
				*Copy_pu8Value = ((PIND >> Copy_u8PinID ) & DIO_u8BIT_MASK);
				break;
			}

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
