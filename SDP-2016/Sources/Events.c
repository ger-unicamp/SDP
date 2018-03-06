/* ###################################################################
 **     Filename    : Events.c
 **     Project     : SDP_2016
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2016-07-30, 17:07, # CodeGen: 0
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Contents    :
 **         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
 **
 ** ###################################################################*/
/*!
 ** @file Events.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup Events_module Events module documentation
 **  @{
 */
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
 ** ===================================================================
 **     Event       :  Cpu_OnNMIINT (module Events)
 **
 **     Component   :  Cpu [MKL25Z128LK4]
 */
/*!
 **     @brief
 **         This event is called when the Non maskable interrupt had
 **         occurred. This event is automatically enabled when the [NMI
 **         interrupt] property is set to 'Enabled'.
 */
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  Camera_CLK_Interruption_OnInterrupt (module Events)
 **
 **     Component   :  Camera_CLK_Interruption [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable_Motors> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void Camera_CLK_Interruption_OnInterrupt(void)
{
	switch (state)
	{
	// First state
	case HALF_LOW_CLK:
	{
		// next state
		state = HIGH_CLK;

		if (clockCounter == 0)
		{
			// SI High
			SI_SetVal();
			while (!SI_GetVal());
		}

		// End of the cycle
		// The camera needs an extra clock (129) to send the last pixel
		else if (clockCounter == 129)
		{
			clockCounter = 0;

			// And 20 microseconds to prepare for the next cycle.
			state = WAIT_TRANSFER_CHARGE;

			// Checks if reading is finished
			verifySample();
		}
		break;
	}

	case HIGH_CLK:
	{
		// Clock High.
		CLK_SetVal();
		while (!CLK_GetVal());

		clockCounter++;

		state = HALF_HIGH_CLK;

		break;
	}

	case HALF_HIGH_CLK:
	{
		if (clockCounter == 1)
		{
			// SI Low.
			SI_ClrVal();
			while (SI_GetVal());
		}

		// Starts the AD convertion
		AD_Converter_MeasureChan(FALSE, 0);
		state = LOW_CLK;
		break;
	}
	case LOW_CLK:
	{
		// Clock Low.
		CLK_ClrVal();
		while (CLK_GetVal());

		state = HALF_LOW_CLK;

		break;
	}

	// Pixel charge transfer time
	case WAIT_TRANSFER_CHARGE:
	{
		if (transferTime)
		{
			transferTime++;
		}
		else
		{
			transferTime = 0;
			state = HALF_LOW_CLK;
		}

		break;
	}

	}
}

/*
 ** ===================================================================
 **     Event       :  AD_Converter_OnEnd (module Events)
 **
 **     Component   :  AD_Converter [AD_Converter]
 **     Description :
 **         This event is called after the measurement (which consists
 **         of <1 or more conversions>) is/are finished.
 **         The event is available only when the <Interrupt
 **         service/event> property is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void AD_Converter_OnEnd(void)
{
	if (!handlingPowerUpdate)
	{
		AD_Converter_GetChanValue(0, &rawImageBuffer[clockCounter]);
	}
	else
	{
		updatePowerState();
	}
}

/*
 ** ===================================================================
 **     Event       :  SerialCom_OnBlockSent (module Events)
 **
 **     Component   :  SerialCom [Serial_LDD]
 */
/*!
 **     @brief
 **         This event is called after the last character from the
 **         output buffer is moved to the transmitter.
 **     @param
 **         UserDataPtr     - Pointer to the user or
 **                           RTOS specific data. This pointer is passed
 **                           as the parameter of Init method.
 */
/* ===================================================================*/
void SerialCom_OnBlockSent(LDD_TUserData *UserDataPtr)
{
	Serial_Device *ptr = (Serial_Device*)UserDataPtr;

	ptr->isSent = TRUE; /* set flag so sender knows we have finished */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
