/*
 * A4988.h
 *
 *  Created on: Sep 12, 2022
 *      Author: tkact
 */

#ifndef INC_A4988_H_
#define INC_A4988_H_



#define ENABLE_A4988_1 	GPIO_Pin_0
#define MS1_A4988_1 		GPIO_Pin_6
#define MS2_A4988_1 		GPIO_Pin_2
#define MS3_A4988_1 		GPIO_Pin_3
#define STEP_A4988_1		GPIO_Pin_4
#define DIR_A4988_1		GPIO_Pin_5




typedef struct{
	int step_degree;
}StepperMotor;


typedef struct  {
	short step_pin;
	short dir_pin;
	short enable_pin;

	short microstep_resolution;//(1,2,4,8,...)

	long step_count; //current position
	long steps_remaing; //to complete the current move(absolute value)
	long step_pulse;

	short dir_state;

	//Motor setting
	short max_steps; //max steps is 200(=360/1.8) if your motor have 1.8 step.

	short busy_status_flag; //if this is 1, busy
}StepperDriver;

void stepperDriverInit(StepperDriver* spdv,long max_steps,
		short step_pin,short dir_pin,short enable_pin);
void rotate(StepperDriver* spdv, long deg);
void move(StepperDriver* spdv,long steps);
static long calcStepsForRotation(StepperDriver* spdv,double deg);



#endif /* INC_A4988_H_ */
