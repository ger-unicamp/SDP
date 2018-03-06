/*
 * BatteryController.h
 *
 *  Created on: 27/12/2016
 *      Author: marcelo
 */

#ifndef SOURCES_BATTERYCONTROLLER_H_
#define SOURCES_BATTERYCONTROLLER_H_

// Includes.
#include "PE_Types.h"
#include "Power_Level1.h"
#include "BitIoLdd5.h"
#include "Power_Level2.h"
#include "BitIoLdd6.h"
#include "Power_Level3.h"
#include "BitIoLdd7.h"
#include "Power_Level4.h"
#include "BitIoLdd8.h"
#include "AD_Converter.h"
#include "AdcLdd1.h"

#include "SerialCommunication.h"
#include "GlobalVariables.h"

// Power flag
volatile bool handlingPowerUpdate;
volatile float batteryLevel;

void updateBatteryLevel();
void updatePowerState();
void sendBatteryLevel();

#endif /* SOURCES_BATTERYCONTROLLER_H_ */
