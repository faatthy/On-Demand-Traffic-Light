/*
 * APP.h
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#define LED_Green_Group     DIO_u8GROUP_A
#define LED_Green_Pin       DIO_u8PIN0

#define LED_Yellow_Group     DIO_u8GROUP_A
#define LED_Yellow_Pin       DIO_u8PIN1


#define LED_Red_Group     DIO_u8GROUP_A
#define LED_Red_Pin       DIO_u8PIN2

#define LED_Green_Ped_Group     DIO_u8GROUP_B
#define LED_Green_Ped_Pin       DIO_u8PIN0

#define LED_Yellow_Ped_Group     DIO_u8GROUP_B
#define LED_Yellow_Ped_Pin       DIO_u8PIN1


#define LED_Red_Ped_Group     DIO_u8GROUP_B
#define LED_Red_Ped_Pin       DIO_u8PIN2

#define BUTTON_Interrupt_Group   DIO_u8GROUP_D
#define BUTTON_Interrupt_Pin      DIO_u8PIN2


#define Green_Led  0
#define Yellow_Led 1
#define Red_Led    2
void APPInit(void);
void APPStrat(void);
#endif /* APPLICATION_APP_H_ */
