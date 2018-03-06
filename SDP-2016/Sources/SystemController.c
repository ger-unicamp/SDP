/*
 * SystemController.c
 *
 *  Created on: 31/12/2016
 *      Author: marcelo
 */

#include "SystemController.h"
#include "GreenLED.h"

#define MAX_PWM 80

void advancedControl(double pid_output)
{
	int pwm_left, pwm_right;

	int servo_parameter = (int) (pid_output * 350.0);
	dc_motors_normalization(pid_output, &pwm_left, &pwm_right);
	int left_motor_parameter = pwm_left;
	int right_motor_parameter = pwm_right;

	setServoDirection(servo_parameter);
	setMotorsSpeed(left_motor_parameter, right_motor_parameter);

}

void dc_motors_normalization(double pid_output, int * pwm_left, int * pwm_right)
{

    if(pid_output <= 0)
    {

        (* pwm_right) =  MAX_PWM;
        (* pwm_left) = (int)((pid_output + 1) * MAX_PWM);

    }
    else
    {

        (* pwm_left) = MAX_PWM;
        (* pwm_right) = (int)((1 - pid_output) * MAX_PWM);

    }
}
