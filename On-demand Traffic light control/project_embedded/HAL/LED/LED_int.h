/*
 * LED_int.h
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

ES_t LED_enuInit(u8 Copy_u8Groupe,u8 Copy_u8Pin );
ES_t LED_enuON(u8 Copy_u8Groupe,u8 Copy_u8Pin);
ES_t LED_enuOFF(u8 Copy_u8Groupe,u8 Copy_u8Pin);
ES_t LED_enuToglle(u8 Copy_u8Groupe,u8 Copy_u8Pin);
/*
#define LED_Green_Group     DIO_u8GROUP_A
#define LED_Green_Pin       DIO_u8PIN0

#define LED_Red_Group       DIO_u8GROUP_A
#define LED_Red_Pin         DIO_u8PIN1

#define LED_Yellow_Group    DIO_u8GROUP_A
#define LED__PinYellow      DIO_u8PIN2

#define LED_Green_Ped_Group    DIO_u8GROUP_B
#define LED_Green_Ped_Pin      DIO_u8PIN0

#define LED_Red_Ped_Group      DIO_u8GROUP_B
#define LED_Red_Ped_Pin        DIO_u8PIN1


#define LED_Yellow_Ped_Group    DIO_u8GROUP_C
#define LED_Yellow_Ped_Pin      DIO_u8PIN2
*/
#endif /* HAL_LED_LED_INT_H_ */
