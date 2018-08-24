/*
 * image_processing_lib.h
 *
 * Last update on: 09/04/18
 * Comments: code formatting only
 *
 * Author: Marcelo
 *
 */

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_


#include <camera_lib.h>
#include "PE_Types.h"

volatile uint8 referenceImage[128];

void calibration();
void binarization(uint8 binarizedImage[]);
void set_borders(uint8 image[], uint8 *leftBorder, uint8 *rightBorder);
uint8 get_track_width(uint8 image[]);
double inverse_proportional_avg(uint8_t *image);

#endif /* IMAGEPROCESSING_H_ */
