/*
 * CameraController.h
 *
 *  Created on: 30/07/2016
 *      Author: marcelo
 */

#ifndef SOURCES_CAMERACONTROLLER_H_
#define SOURCES_CAMERACONTROLLER_H_

// Includes.
#include "PE_Types.h"
#include "Camera_CLK_Interruption.h"
#include "SerialCommunication.h"


/* There are five states:
 * 1) HIGH_CLK.
 * 2) HALF_HIGH_CLK.
 * 3) LOW_CLK.
 * 4) HALF_LOW_CLK.
 * 5) WAIT_TRANSFER_CHARGE.
 */
enum clockState {HIGH_CLK, HALF_HIGH_CLK, LOW_CLK, HALF_LOW_CLK, WAIT_TRANSFER_CHARGE};

enum logicalLevel {LOW, HIGH};

int clockCounter;
int state;
int transferTime;
uint8 rawImage[128];
uint8 rawImageBuffer[128];
volatile int samplesNumber;
volatile int currentSample;

// Methods
void initializeCamera();
int getRawImageMean(int samplesNum);
void verifySample();


#endif /* SOURCES_CAMERACONTROLLER_H_ */
