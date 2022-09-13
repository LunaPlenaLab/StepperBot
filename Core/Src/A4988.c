/*
 * A4988.c
 *
 *  Created on: Jun 15, 2022
 *      Author: tkact
 */


#include "A4988.h"

void stepperDriver_Config(StepperDriver* spdv,StepperDriverPins pin, StepperDriverPorts port,short max_steps){
	spdv->pin = pin;
	spdv->port = port;

	spdv->microstep_resolution=2;//(1,2,4,8,...)

	spdv->step_count=0; //current position
	spdv->steps_remaing=0; //to complete the current move(absolute value)
	spdv->step_pulse=0;

	spdv->dir_state=0;

	//Motor setting
	spdv->max_steps = max_steps;
	spdv->remain_status_flag = 0;

}

void rotate(StepperDriver* spdv, long deg){
	move(spdv,calcStepsForRotation(spdv,deg));
}

void move(StepperDriver* spdv,long steps){
	spdv->step_pulse = steps;

	spdv->remain_status_flag = 0;
	if(!spdv->remain_status_flag){
		//HAL_GPIO_WritePin(spdv->port.ENABLE_PORT, spdv->pin.ENABLE_PIN, GPIO_PIN_SET);
		HAL_GPIO_TogglePin(spdv->port.STEP_PORT, spdv->pin.STEP_PIN);
	}


}


long calcStepsForRotation(StepperDriver* spdv,double deg){
	return deg * spdv->max_steps*spdv->microstep_resolution/360;
}
