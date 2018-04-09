/*
 * motor_lib.c
 *
 * Last update on: 09/04/18
 * Comments: code formatting only
 *
 * Author: Marcelo
 *
 */

#include <dc_motor_lib.h>

/*
 * Engine A is the left motor and engine B is the right motor
 * Both parameters allow values between -255 and 255.
 * With positive values the motor turns forward and with negative turns backwards
 */
void setMotorsSpeed(int leftMotorSpeed, int rightMotorSpeed)
{
	if (leftMotorSpeed < -255 || leftMotorSpeed > 255)
	{
		return;
	}

	if (rightMotorSpeed < -255 || rightMotorSpeed > 255)
	{
		return;
	}

	// LeftMotor
	// Forward
	if (leftMotorSpeed >= 0)
	{
		Motor_A_In1_SetRatio8(255);
		Motor_A_In2_SetRatio8(255 - leftMotorSpeed);
	}
	// Backward
	else
	{
		Motor_A_In1_SetRatio8(255 + leftMotorSpeed);
		Motor_A_In2_SetRatio8(255);
	}

	// Right Motor
	// Forward
	if (rightMotorSpeed >= 0)
	{
		Motor_B_In1_SetRatio8(255);
		Motor_B_In2_SetRatio8(255 - rightMotorSpeed);
	}
	// Backward
	else
	{
		Motor_B_In1_SetRatio8(255 + rightMotorSpeed);
		Motor_B_In2_SetRatio8(255);
	}


}


