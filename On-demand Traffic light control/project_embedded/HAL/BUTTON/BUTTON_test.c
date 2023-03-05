/*
 * BUTTON_test.c
 *
 *  Created on: Oct 11, 2022
 *      Author: fathy
 */
/*
#include "../../LIBRARY/stdTypes.h"
#include"../../LIBRARY/errorState.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"BUTTON_int.h"
#include<util/delay.h>
int main(){

	DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8OUTPUT);
	BUTTON_enuInit(DIO_u8GROUP_D,DIO_u8PIN2);
	u8 local_Value;
	DIO_enuGetPinValue(DIO_u8GROUP_D,DIO_u8PIN2,&local_Value);
				// confirm the button is pressed
				if(local_Value){
					_delay_ms(10);
					DIO_enuGetPinValue(DIO_u8GROUP_D,DIO_u8PIN2,&local_Value);
					if(local_Value){
						//prevent holding the button
						while(local_Value){
							DIO_enuGetPinValue(DIO_u8GROUP_D,DIO_u8PIN2,&local_Value);
						}
					DIO_enuTogglePinValue(DIO_u8GROUP_A,DIO_u8PIN0);
					}
				}
				}
*/
