/*
 * SerialCommunication.c
 *
 *  Created on: 04/09/2016
 *      Author: marcelo
 */

#include "SerialCommunication.h"

static Serial_Device deviceData;

static void init_Serial()
{
	deviceData.handle = SerialCom_Init(&deviceData); /* Initialization of serial component */
	deviceData.isSent = FALSE;
}

static int sendAChar(unsigned char ch)
{
	deviceData.isSent = FALSE;
	while(SerialCom_SendBlock(deviceData.handle, (LDD_TData*)&ch, 1)!= ERR_OK) {} /* Send char */
	while(!deviceData.isSent) {} /* wait until we get the green flag from the TX interrupt */
}
void sendChar(char character)
{
	init_Serial();
	sendAChar(character);
}

void sendString(char* string)
{
	int index = 0;

	init_Serial();

	while(string[index] != '\0')
	{
		sendAChar(string[index++]);
	}
}

void itoa_8_bit(uint8 sample)
{
	unsigned char R1, R2, R3;
	int Q1, Q2;

	if (sample < MIN || sample > MAX)
	{
		sendAChar('E');
		return;
	}

	R1 = (unsigned char) (sample % 10) + '0';
	Q1 = sample / 10;

	R2 = (unsigned char) (Q1 % 10) + '0';
	Q2 = Q1 / 10;

	R3 = (unsigned char) (Q2 % 10) + '0';

	sendAChar(R3);
	sendAChar(R2);
	sendAChar(R1);
}

void sendArrayOfPixels(uint8 array[])
{
	init_Serial();

	for (int pixel = 0; pixel < 128; pixel++)
	{
		itoa_8_bit(array[pixel]);
		sendAChar(' ');
	}

	sendAChar('\n');
	sendAChar('\r');

	serialFinished = TRUE;
}

/*
 * stringNumber must be (digitsBefore + digitsAfter + 2) cells
 */
void floatToChar(float floatNumber, char* stringNumber, int digitsBefore, int digitsAfter)
{
	int digit;
	int factor = 1;
	int intNumber;
	int remainder;

	for (digit = 0; digit < digitsAfter; digit++)
	{
		factor *= 10;
	}
	floatNumber *= factor;

	intNumber = (int) floatNumber;

	for (digit = (digitsBefore + digitsAfter); digit >= 0; digit--)
	{
		if (digit == digitsBefore)
		{
			stringNumber[digit] = '.';
		}
		else
		{
			remainder = intNumber % 10;
			stringNumber[digit] = '0' + (char) remainder;
			intNumber /= 10;
		}
	}
	stringNumber[digitsBefore + digitsAfter + 1] = '\0';
}


























