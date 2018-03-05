/*
 * ImageProcessing.h
 *
 *  Created on: 31/12/2016
 *      Author: marcelo
 */

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_


#include "PE_Types.h"
#include "CameraController.h"

volatile uint8 referenceImage[128];

void calibration();
void binarization(uint8 binarizedImage[]);
void set_borders(uint8 image[], uint8 *leftBorder, uint8 *rightBorder);
uint8 get_track_width(uint8 image[]);

#endif /* IMAGEPROCESSING_H_ */
