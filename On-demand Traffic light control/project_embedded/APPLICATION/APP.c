/*
 * main.c
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */


#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/errorState.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/TIMER/TIMER_int.h"
#include"../HAL/LED/LED_int.h"
#include"../HAL/BUTTON/BUTTON_int.h"
#include "APP.h"

//this variable for select mode if 1 normal mode if 0  pedestrians
u8 NORMAL_mode=1;
//this variable i used to prevent call interrupt at start code
u8 once=0;
u8 Car_Light=Green_Led;
u8 LAST_Light=Green_Led;
/*
 * function send to interrupt to do
 */
void GO_INT(void){
	if(once==0){
		once++;
		return ;
	}
	NORMAL_mode=0;
}
/*
 * function initialize system
 */
void APPInit(void){

// INTILE NORMAL MODE
	LED_enuInit(LED_Green_Group,LED_Green_Pin);
	LED_enuInit(LED_Yellow_Group,LED_Yellow_Pin);
    LED_enuInit(LED_Red_Group,LED_Red_Pin);


    LED_enuInit(LED_Green_Ped_Group,LED_Green_Ped_Pin);
    LED_enuInit(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
    LED_enuInit(LED_Red_Ped_Group,LED_Red_Ped_Pin);


    BUTTON_enuInit(BUTTON_Interrupt_Group,BUTTON_Interrupt_Pin);


    EXTI_enuInit();
    EXTI_enuCallBack(GO_INT,INT0);
    GIE_vidEnable();
    Timer_enuInit();

}

void APPStrat(){
	if(NORMAL_mode||Car_Light==Green_Led||Car_Light==Yellow_Led){
		//have i press button if i press i make in interrupt normal_mode=0;
		if(!NORMAL_mode){
			//make light yellow
			Car_Light=Yellow_Led;
		}
		//close green and yellow leds to prevent  pedestrians
		LED_enuOFF(LED_Green_Ped_Group,LED_Green_Ped_Pin);
		LED_enuOFF(LED_Yellow_Ped_Group,LED_Yellow_Ped_Group);

	switch(Car_Light){
	case Green_Led:
		LED_enuON(LED_Green_Group,LED_Green_Pin);
		LED_enuOFF(LED_Yellow_Group,LED_Yellow_Pin);
		LED_enuOFF(LED_Red_Group,LED_Red_Pin);
		for(u8 i=0;i<10;i++){
			TIMER_delay(500);
			//if i press the button on green led
			if(!NORMAL_mode)
				break;
		}
		Car_Light=Yellow_Led;
		LAST_Light=Green_Led;
		break;
	case Yellow_Led:
		if(!NORMAL_mode){
			// i have in red_mode in last
			if(LAST_Light!=Red_Led){
				LED_enuON(LED_Red_Ped_Group,LED_Red_Ped_Pin);
				// blink both yellow leds
				for(u8 i=0;i<5;i++){
					LED_enuON(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
					LED_enuON(LED_Yellow_Group,LED_Yellow_Pin);
					TIMER_delay(400);
					LED_enuToglle(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
					LED_enuToglle(LED_Yellow_Group,LED_Yellow_Pin);
					TIMER_delay(200);

					LED_enuON(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
					LED_enuON(LED_Yellow_Group,LED_Yellow_Pin);
				    TIMER_delay(400);
				}}
				LAST_Light=Yellow_Led;
				Car_Light=Red_Led;
				LED_enuON(LED_Red_Group,LED_Red_Pin);
			}
		else {
			for(u8 i=0;i<5;i++){
				LED_enuON(LED_Yellow_Group,LED_Yellow_Pin);

								TIMER_delay(400);

								LED_enuToglle(LED_Yellow_Group,LED_Yellow_Pin);
								TIMER_delay(200);


								LED_enuON(LED_Yellow_Group,LED_Yellow_Pin);
							    TIMER_delay(400);
							    if(!NORMAL_mode){
							    	  LAST_Light=Yellow_Led;
							    	  break;
							    }

							    }

		}

		LED_enuOFF(LED_Yellow_Group,LED_Yellow_Pin);
		LED_enuOFF(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
		if(LAST_Light==Green_Led){
			LAST_Light=Yellow_Led;
			Car_Light=Red_Led;
		}
		else if(LAST_Light==Red_Led){
			Car_Light=Green_Led;
			LAST_Light=Yellow_Led;
		}
		break;
		case Red_Led:
			LED_enuOFF(LED_Green_Group,LED_Green_Pin);
			LED_enuOFF(LED_Yellow_Group,LED_Yellow_Pin);
			LED_enuON(LED_Red_Group,LED_Red_Pin);
			for(u8 i=0;i<10;i++){
				TIMER_delay(500);
				if(!NORMAL_mode){
					break;
				}
			}
			Car_Light=Yellow_Led;
			LAST_Light=Red_Led;
			break;

	}
	}
	else{
		LED_enuON(LED_Green_Ped_Group,LED_Green_Ped_Pin);
		LED_enuOFF(LED_Red_Ped_Group,LED_Red_Pin);
		LED_enuOFF(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);

		LED_enuOFF(LED_Green_Group,LED_Green_Pin);
		LED_enuOFF(LED_Yellow_Group,LED_Yellow_Pin);
		LED_enuON(LED_Red_Group,LED_Red_Pin);
		TIMER_delay(5000);
		LED_enuOFF(LED_Red_Group,LED_Red_Pin);

		for(u8 i=0;i<5;i++){
							LED_enuON(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
							LED_enuON(LED_Yellow_Group,LED_Yellow_Pin);
							TIMER_delay(400);
							LED_enuToglle(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
							LED_enuToglle(LED_Yellow_Group,LED_Yellow_Pin);
							TIMER_delay(200);

							LED_enuON(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);
							LED_enuON(LED_Yellow_Group,LED_Yellow_Pin);
						    TIMER_delay(400);
		}
		LED_enuOFF(LED_Yellow_Group,LED_Yellow_Pin);
		LED_enuOFF(LED_Yellow_Ped_Group,LED_Yellow_Ped_Pin);

		LED_enuON(LED_Red_Ped_Group,LED_Red_Ped_Pin);
		//return to normal mode
		NORMAL_mode=1;
		Car_Light=Green_Led;
		LAST_Light=Yellow_Led;
	}
}

