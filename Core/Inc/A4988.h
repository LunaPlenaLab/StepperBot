/*
 * A4988.h
 *
 *  Created on: Sep 12, 2022
 *      Author: tkact
 */

#ifndef INC_A4988_H_
#define INC_A4988_H_

#include "main.h"

#define ENABLE_A4988_1 	GPIO_Pin_0
#define MS1_A4988_1 		GPIO_Pin_6
#define MS2_A4988_1 		GPIO_Pin_2
#define MS3_A4988_1 		GPIO_Pin_3
#define STEP_A4988_1		GPIO_Pin_4
#define DIR_A4988_1		GPIO_Pin_5

#define A4988_NUM (2)


typedef struct{
	uint16_t ENABLE_PIN;
	uint16_t MS1_PIN;
	uint16_t MS2_PIN;
	uint16_t MS3_PIN;
	uint16_t STEP_PIN;
	uint16_t DIR_PIN;
}StepperDriverPins;


typedef struct{
	GPIO_TypeDef * ENABLE_PORT;
	GPIO_TypeDef * MS1_PORT;
	GPIO_TypeDef * MS2_PORT;
	GPIO_TypeDef * MS3_PORT;
	GPIO_TypeDef * STEP_PORT;
	GPIO_TypeDef * DIR_PORT;
}StepperDriverPorts;


typedef struct  {
	StepperDriverPins pin;
	StepperDriverPorts port;


	short microstep_resolution;//(1,2,4,8,...)

	long step_count; //current position
	long steps_remaing; //to complete the current move(absolute value)
	long step_pulse;

	short dir_state;

	//Motor setting
	short max_steps; //max steps is 200(=360/1.8) if your motor have 1.8 step.

	short remain_status_flag; //if this is 1, busy
}StepperDriver;

void stepperDriver_Config(StepperDriver* spdv,StepperDriverPins pin, StepperDriverPorts port,short max_steps);
void rotate(StepperDriver* spdv, long deg);
void move(StepperDriver* spdv,long steps);
long calcStepsForRotation(StepperDriver* spdv,double deg);




#endif /* INC_A4988_H_ */
