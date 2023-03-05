/*
 * LED_prog.c
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */
#include"../../LIBRARY/stdTypes.h"
#include"../../LIBRARY/errorState.h"
#include"../../MCAL/DIO/DIO_int.h"
//#include"LED_int.h"
/*
 *
 */
ES_t LED_enuInit(u8 Copy_u8Groupe,u8 Copy_u8Pin){
	ES_t local_enuerrorState=ES_OK;
	if(Copy_u8Groupe<=DIO_u8GROUP_D&&Copy_u8Pin<=DIO_u8PIN7){
		DIO_enuSetPinDirection(Copy_u8Groupe,Copy_u8Pin,DIO_u8OUTPUT);
	}
	else
		local_enuerrorState=ES_OUT_OF_RANGE;
	return local_enuerrorState;
}
ES_t LED_enuON(u8 Copy_u8Groupe,u8 Copy_u8Pin){
	ES_t local_enuerrorState=ES_OK;
		if(Copy_u8Groupe<=DIO_u8GROUP_D&&Copy_u8Pin<=DIO_u8PIN7){
			DIO_enuSetPinValue(Copy_u8Groupe,Copy_u8Pin,DIO_u8HIGH);
		}
		else
			local_enuerrorState=ES_OUT_OF_RANGE;
		return local_enuerrorState;
}
ES_t LED_enuOFF(u8 Copy_u8Groupe,u8 Copy_u8Pin){
	ES_t local_enuerrorState=ES_OK;
if(Copy_u8Groupe<=DIO_u8GROUP_D&&Copy_u8Pin<=DIO_u8PIN7){
	DIO_enuSetPinValue(Copy_u8Groupe,Copy_u8Pin,DIO_u8LOW);
}
else
	local_enuerrorState=ES_OUT_OF_RANGE;
return local_enuerrorState;
}
ES_t LED_enuToglle(u8 Copy_u8Groupe,u8 Copy_u8Pin){
	ES_t local_enuerrorState=ES_OK;
	if(Copy_u8Groupe<=DIO_u8GROUP_D&&Copy_u8Pin<=DIO_u8PIN7){
		DIO_enuTogglePinValue(Copy_u8Groupe,Copy_u8Pin);
	}
	else
		local_enuerrorState=ES_OUT_OF_RANGE;
	return local_enuerrorState;
}

