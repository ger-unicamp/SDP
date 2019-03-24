/*
 * SystemController.h
 *
 *  Created on: 31/12/2016
 *      Author: marcelo
 */

#ifndef SOURCES_SYSTEMCONTROLLER_H_
#define SOURCES_SYSTEMCONTROLLER_H_


#include <camera_lib.h>
#include <dc_motor_lib.h>
#include <servo_lib.h>
#include "PE_Types.h"


void advancedControl(double pid_output);

#endif /* SOURCES_SYSTEMCONTROLLER_H_ */
