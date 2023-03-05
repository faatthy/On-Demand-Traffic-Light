/*
 * EXTI_test.c
 *
 *  Created on: Oct 11, 2022
 *      Author: fathy
 */
/*
#include"../../LIBRARY/errorState.h"
#include "../../LIBRARY/stdTypes.h"
#include"../DIO/DIO_int.h"
#include"../GIE/GIE_int.h"
#include "EXTI_int.h"
#include"../../HAL/BUTTON/BUTTON_int.h"
void tog(){
	DIO_enuTogglePinValue(DIO_u8GROUP_A,DIO_u8PIN0);
}
int main(){
	GIE_vidEnable();
	EXTI_enuInit();
	BUTTON_enuInit(DIO_u8GROUP_D,DIO_u8PIN2);
	DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8HIGH);
	EXTI_enuCallBack(tog,INT0);
	while (1){

	}

}

*/
