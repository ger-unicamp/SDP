/*
 * ServoController.h
 *
 *  Created on: 29/12/2016
 *      Author: marcelo
 */

#ifndef SOURCES_SERVOCONTROLLER_H_
#define SOURCES_SERVOCONTROLLER_H_

#include "Servomotor.h"

#define MAX_LEFT 	18900
#define CENTER 		18550
#define MAX_RIGHT 	18200
#define RATE		350

void setServoDirection(int direction);
void dc_motors_normalization(double pid_output, int * pwm_left, int * pwm_right);

#endif /* SOURCES_SERVOCONTROLLER_H_ */
