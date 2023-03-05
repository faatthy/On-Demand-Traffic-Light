/*
 * TIMER_priv.h
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_
#define PRES_0				0
#define PRES_1				1
#define PRES_8				8
#define PRES_64				64
#define PRES_256			256
#define PRES_1024			1024
#define PRES_FALL			7
#define PRES_RISE			3

#define NORMAL				36
#define CTC					41

#define INTERRUPT			96
#define POLLING				76

#define DISCONNECTED		65
#define TOGGLE				20
#define CLEAR				50
#define SET					90


#define TIMSK	*((volatile u8*) 0x59)

/*TIFR*/
#define TIFR	*((volatile u8*) 0x58)

/*TCCR*/
#define TCCR0	*((volatile u8*) 0x53)
#define TCCR1A	*((volatile u8*) 0x4f)
#define TCCR1B	*((volatile u8*) 0x4e)
#define TCCR2	*((volatile u8*) 0x45)

/*TCNT*/
#define TCNT0	*((volatile u8*) 0x52)

#define TCNT1H	*((volatile u8*) 0x4d)
#define TCNT1L	*((volatile u8*) 0x4c)

#define TCNT1	*((volatile u16*) 0x4c)

#define TCNT2	*((volatile u8*) 0x44)

/*OCR*/
#define OCR0	*((volatile u8*) 0x5c)
#define OCR1AH	*((volatile u8*) 0x4b)
#define OCR1AL	*((volatile u8*) 0x4a)

#define OCR1A	*((volatile u16*) 0x4a)

#define OCR1BH	*((volatile u8*) 0x49)
#define OCR1BL	*((volatile u8*) 0x48)

#define OCR1B	*((volatile u16*) 0x48)

#define OCR2	*((volatile u8*) 0x43)









#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
