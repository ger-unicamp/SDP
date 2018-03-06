/*
 * MotorController.h
 *
 *  Created on: 28/12/2016
 *      Author: marcelo
 */

#ifndef SOURCES_MOTORCONTROLLER_H_
#define SOURCES_MOTORCONTROLLER_H_

#include "Enable_Motors.h"
#include "BitIoLdd4.h"
#include "Motor_A_In1.h"
#include "PwmLdd1.h"
#include "TU2.h"
#include "Motor_A_In2.h"
#include "PwmLdd2.h"
#include "Motor_B_In1.h"
#include "PwmLdd3.h"
#include "Motor_B_In2.h"
#include "PwmLdd4.h"

void setMotorsSpeed(int leftMotorSpeed, int rightMotorSpeed);

#endif /* SOURCES_MOTORCONTROLLER_H_ */
