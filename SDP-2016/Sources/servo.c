/*
 * servo_lib.c
 *
 * Last update on: 09/04/18
 * Comments: code formatting only
 *
 * Author: Marcelo
 *
 */

#include "servo_lib.h"
/*
 * Parameter:
 *    Direction of the Servomotor:
 *    0: Center
 *    Negative values: Turn left  (max: -350)
 *    Positive values: Turn right (max: 350)
 *
 *    Wait 480 ms between two calls of this function
 */
void setServoDirection(int direction)
{
	if (direction < -RATE || direction > RATE)
	{
		return;
	}

	Servomotor_SetDutyUS(CENTER - direction);
}
