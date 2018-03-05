/*
 * SystemController.h
 *
 *  Created on: 31/12/2016
 *      Author: marcelo
 */

#ifndef SOURCES_SYSTEMCONTROLLER_H_
#define SOURCES_SYSTEMCONTROLLER_H_


#include "PE_Types.h"

#include "MotorController.h"
#include "ServoController.h"
#include "CameraController.h"

void advancedControl(double pid_output);

#endif /* SOURCES_SYSTEMCONTROLLER_H_ */
