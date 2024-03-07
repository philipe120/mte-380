/*
 * motor.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hudsonsun
 */

#include "main.h"
#include "motor.h"

volatile uint32_t* LEFT_MOTOR_FWD_CCR;
volatile uint32_t* LEFT_MOTOR_BWD_CCR;
volatile uint32_t* RIGHT_MOTOR_FWD_CCR;
volatile uint32_t* RIGHT_MOTOR_BWD_CCR;

enum motor_speed {
	LEFT_FULLSPEED = 100,	//to be calibrated
	LEFT_TURNSPEED = 70,	//to be calibrated
	RIGHT_FULLSPEED = 100,	//to be calibrated
	RIGHT_TURNSPEED = 70,	//to be calibrated
	STOP = 0,
};

void Motor_Init(void)
{
	LEFT_MOTOR_FWD_CCR = &TIM4->CCR1;
	LEFT_MOTOR_BWD_CCR = &TIM4->CCR2;
	RIGHT_MOTOR_FWD_CCR = &TIM4->CCR3;
	RIGHT_MOTOR_BWD_CCR = &TIM4->CCR4;
	//	LEFT_MOTOR_FWD_CCR = (uint32_t*) &TIM4->CCR1;
//	LEFT_MOTOR_BWD_CCR = (uint32_t*) &TIM4->CCR2;
//	RIGHT_MOTOR_FWD_CCR = (uint32_t*) &TIM4->CCR3;
//	RIGHT_MOTOR_BWD_CCR = (uint32_t*) &TIM4->CCR4;
}


void Moving_Forwards (void)
{
	*LEFT_MOTOR_FWD_CCR = LEFT_FULLSPEED;
	*LEFT_MOTOR_BWD_CCR = STOP;
	*RIGHT_MOTOR_FWD_CCR = RIGHT_FULLSPEED;
	*RIGHT_MOTOR_BWD_CCR = STOP;
}

void Moving_Backwards (void)
{
	*LEFT_MOTOR_FWD_CCR = STOP;
	*LEFT_MOTOR_BWD_CCR = LEFT_FULLSPEED;
	*RIGHT_MOTOR_FWD_CCR = STOP;
	*RIGHT_MOTOR_BWD_CCR = RIGHT_FULLSPEED;
}

void Stop (void)
{
	*LEFT_MOTOR_FWD_CCR = STOP;
	*LEFT_MOTOR_BWD_CCR = STOP;
	*RIGHT_MOTOR_FWD_CCR = STOP;
	*RIGHT_MOTOR_BWD_CCR = STOP;
}

void Turn (void)
{
	*LEFT_MOTOR_FWD_CCR = LEFT_TURNSPEED;
	*LEFT_MOTOR_BWD_CCR = STOP;
	*RIGHT_MOTOR_FWD_CCR = RIGHT_FULLSPEED;
	*RIGHT_MOTOR_BWD_CCR = STOP;
}
