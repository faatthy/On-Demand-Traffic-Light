/*
 * BUTTON_int.h
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */

#ifndef HAL_BUTTON_BUTTON_INT_H_
#define HAL_BUTTON_BUTTON_INT_H_

ES_t BUTTON_enuInit(u8 Copy_u8Group,u8 Copy_u8pin);
ES_t BUTTON_enuRead(u8 Copy_u8Group,u8 Copy_u8pin,u8 * Copy_u8Value);
#endif /* HAL_BUTTON_BUTTON_INT_H_ */
