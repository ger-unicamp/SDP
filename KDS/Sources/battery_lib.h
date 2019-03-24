/*
 * battery_lib.h
 *
 * Last update on: 09/04/18
 * Comments: code formatting only
 *
 * Author: Marcelo
 *
 */

#ifndef SOURCES_BATTERY_LIB_H_
#define SOURCES_BATTERY_LIB_H_

// Includes.
#include <serial_communication_lib.h>
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

#include "GlobalVariables.h"

// Power flag
volatile bool handlingPowerUpdate;
volatile float batteryLevel;

void updateBatteryLevel();
void updatePowerState();
void sendBatteryLevel();

#endif /* SOURCES_BATTERY_LIB_H_ */
