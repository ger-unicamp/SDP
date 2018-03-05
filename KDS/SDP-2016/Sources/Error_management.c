/*
 * Error_management.c
 *
 *  Created on: 27/07/2017
 *      Author: marcelo
 */
#include "Error_management.h"

double get_error(uint8 image[])
{
	uint8 range, left_border, right_border;

	double error;

	set_borders(image, &left_border, &right_border);
	range = left_border + right_border;

	error = ((double)(right_border - left_border)) / range;

	return error;

}
