/*
 * A4988.c
 *
 *  Created on: Jun 15, 2022
 *      Author: tkact
 */


#include "A4988.h"

void stepperDriverInit(StepperDriver* spdv,long max_steps,
		short step_pin,short dir_pin,short enable_pin){
	spdv->step_pin = step_pin;
	spdv->dir_pin = dir_pin;
	spdv->enable_pin = enable_pin;

	spdv->microstep_resolution=2;//(1,2,4,8,...)

	spdv->step_count=0; //current position
	spdv->steps_remaing=0; //to complete the current move(absolute value)
	spdv->step_pulse=0;

	spdv->dir_state=0;

	//Motor setting
	spdv->max_steps = max_steps;
	spdv->busy_status_flag = 0;
}

void rotate(StepperDriver* spdv, long deg){
	move(spdv,calcStepsForRotation(spdv,deg));
}

void move(StepperDriver* spdv,long steps){
	spdv->step_pulse = steps;

	if(!spdv->busy_status_flag){

	}


}


long calcStepsForRotation(StepperDriver* spdv,double deg){
	return deg * spdv->max_steps*spdv->microstep_resolution/360;
}