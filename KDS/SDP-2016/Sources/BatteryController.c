/*
 * BatteryController.c
 *
 *  Created on: 27/12/2016
 *      Author: marcelo
 */

#include "BatteryController.h"

void updateBatteryLevel()
{
	handlingPowerUpdate = TRUE;

	// Converts the voltage vOut of PTE29 pin
	AD_Converter_MeasureChan(FALSE, 1);

	// Waits the end of conversion
	while (handlingPowerUpdate);
}

void updatePowerState()
{
	unsigned char adcValue;
	float vOut;
	float newVoltage;

	AD_Converter_GetChanValue(1, &adcValue);

	// Find the value of vOut
	vOut = (2.87 / 255) * (float) adcValue; // Theoretical value: 3.0


	// Find the value of batteryLevel (voltage of battery)
	newVoltage = 5.7 * vOut;			// Theoretical value: 57/10

	batteryLevel = (batteryLevel + newVoltage) / 2;

	if (batteryLevel > 7.5)
	{
		Power_Level1_SetVal();
		Power_Level2_SetVal();
		Power_Level3_SetVal();
		Power_Level4_SetVal();
	}
	else if (batteryLevel > 7.2)
	{
		Power_Level1_SetVal();
		Power_Level2_SetVal();
		Power_Level3_SetVal();
		Power_Level4_ClrVal();
	}

	else if (batteryLevel > 6.9)
	{
		Power_Level1_SetVal();
		Power_Level2_SetVal();
		Power_Level3_ClrVal();
		Power_Level4_ClrVal();
	}
	else if (batteryLevel > 6.6)
	{
		Power_Level1_SetVal();
		Power_Level2_ClrVal();
		Power_Level3_ClrVal();
		Power_Level4_ClrVal();
	}
	else
	{
		Power_Level1_NegVal();
		Power_Level2_NegVal();
		Power_Level3_NegVal();
		Power_Level4_NegVal();

		for (int delay = 0; delay < 100000; delay++);
	}

	handlingPowerUpdate = FALSE;
}

void sendBatteryLevel()
{
	char batteryVoltageArray[6];
	floatToChar(batteryLevel, batteryVoltageArray, 2, 2);
	sendString(batteryVoltageArray);
	sendChar('\n');
	sendChar('\r');
}


