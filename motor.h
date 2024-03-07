/*
 * motor.h
 *
 *  Created on: Mar 6, 2024
 *      Author: hudsonsun
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_


enum motor_speed;
//void Motor_Init(void);
void Motor_Init(void);

void Moving_Forwards (void);
void Moving_Backwards (void);
void Stop (void);
void Turn (void);

#endif /* INC_MOTOR_H_ */
