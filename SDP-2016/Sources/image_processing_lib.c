/*
 * image_processing_lib.c
 *
 * Last update on: 09/04/18
 * Comments: code formatting only
 *
 * Author: Marcelo
 *
 */


#include <image_processing_lib.h>

void calibration()
{
	for (int border = 0; border < 128; border++)
	{
		referenceImage[border] = rawImage[border];
	}
}

void binarization(uint8 binarizedImage[])
{
	float light;

	for (int border = 0; border < 128; border++)
	{
		light = (float) rawImage[border] / (float) referenceImage[border];
		if (light < 0.6)
		{
			binarizedImage[border] = 0;
		}
		else
		{
			binarizedImage[border] = 255;
		}
	}
}

uint8 get_track_width(uint8 image[])
{
	uint8 left_border, right_border;
	set_borders(image, &left_border, &right_border);

	return left_border + right_border;
}

void set_borders(uint8 image[], uint8 *leftBorder, uint8 *rightBorder)
{
	int index;
	bool found = FALSE;
	uint8 border;

	// right side
	// default value
	border = 127;
	// Percorre do centro ate o limite direito da camera procurando uma borda
	for (index = 64; index < 127 && !found; index++)
	{
		if (image[index] == 0)
		{
			border = index;
			found = TRUE;
		}
	}
	*rightBorder = border - 64;

	found = FALSE;

	// left side
	// default value
	border = 0;
	// Percorre do centro ate o limite esquerdo da camera procurando uma borda
	for (index = 63; index >= 0 && !found; index--)
	{
		if (image[index] == 0)
		{
			border = index;
			found = TRUE;
		}
	}
	*leftBorder = 63 - border;
}

double inverse_proportional_avg(uint8_t *image, uint8_t left_border, uint8_t right_border)
{
    double avg = 0;
    for (uint8_t i = left_border; i < right_border; i++) {
	    avg += image[i];
    }

    /* Total average */
    avg /= (right_border - left_border);

    /* Unitarization */
    avg /= 255.0;

    return (1.0 - avg);
}


