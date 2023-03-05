/*
 * BUTTON_prog.c
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */
#include"../../LIBRARY/stdTypes.h"
#include"../../LIBRARY/errorState.h"
#include"../../MCAL/DIO/DIO_int.h"
ES_t BUTTON_enuInit(u8 Copy_u8Group,u8 Copy_u8pin){
	ES_t local_enuerrorState=ES_OK;
	if(Copy_u8Group<=DIO_u8GROUP_D&&Copy_u8pin<=DIO_u8PIN7){
		DIO_enuSetPinDirection(Copy_u8Group,Copy_u8pin,DIO_u8INPUT);
		DIO_enuSetPinDirection(Copy_u8Group,Copy_u8pin,DIO_u8FLOAT);
	}
	else
		local_enuerrorState=ES_OUT_OF_RANGE;
	return local_enuerrorState;
}
ES_t BUTTON_enuRead(u8 Copy_u8Group,u8 Copy_u8pin,u8 * Copy_u8Value){
	ES_t local_enuerrorState=ES_OK;
	if(Copy_u8Group<=DIO_u8GROUP_D&&Copy_u8pin<=DIO_u8PIN7){
		DIO_enuGetPinValue(Copy_u8Group,Copy_u8pin,Copy_u8Value);
	}
	else
		local_enuerrorState=ES_OUT_OF_RANGE;
	return local_enuerrorState;
}
