/*
 * error_management.c
 *
 * Last update on: 09/04/18
 * Comments: code formatting only
 *
 */

#include <error_management.h>

double get_error(uint8 image[])
{
	uint8 range, left_border, right_border;

	double error;

	set_borders(image, &left_border, &right_border);
	range = left_border + right_border;

	error = ((double)(right_border - left_border)) / range;

	return error;

}
