/*
 * TIMER_prog.c
 *
 *  Created on: Oct 9, 2022
 *      Author: fathy
 */
#include"../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorState.h"
#include"TIMER_priv.h"
#include "TIMER_conf.h"
#include"math.h"

ES_t Timer_enuInit(){
	ES_t local_enuerrorState=ES_OK;
	TCCR0 = 0x00;
return local_enuerrorState;
}

ES_t TIMER_delay(u16 copy_u16millisec){
	ES_t local_enuerrorState=ES_OK;
	u16 local_u16Num_ov,local_u16TimeInitial;
	double local_doubleTimeMaxDelay,local_doubleTimetick;
	u32 local_u32OverFlowCounnt=0;

	local_doubleTimetick = 256.0/1000.0;   // pres/F_CPU

	local_doubleTimeMaxDelay= 256.0*local_doubleTimetick; //ms		Tmaxdelay = Ttick * 2^8
	if(copy_u16millisec<local_doubleTimeMaxDelay){
		local_u16TimeInitial = (local_doubleTimeMaxDelay-copy_u16millisec)/local_doubleTimetick;
		local_u16Num_ov = 1;

	}else if(copy_u16millisec == (int)local_doubleTimeMaxDelay){
		local_u16TimeInitial=0;
		local_u16Num_ov=1;
	}else{
		local_u16Num_ov = ceil((double)copy_u16millisec/local_doubleTimeMaxDelay);
		local_u16TimeInitial= (1<<8) - ((double)copy_u16millisec/local_doubleTimetick)/local_u16Num_ov;

	}
	TCNT0 = local_u16TimeInitial;
	TCCR0 |= (1<<2);

	while(local_u32OverFlowCounnt<local_u16Num_ov){

		while(((TIFR>>0)&1)==0);

		TIFR|=(1<<0);

		local_u32OverFlowCounnt++;
	}

	TCCR0 = 0x00;
	return local_enuerrorState;
}
