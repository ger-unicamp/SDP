/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "SI.h"
#include "BitIoLdd1.h"
#include "CLK.h"
#include "BitIoLdd2.h"
#include "Camera_CLK_Interruption.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "AD_Converter.h"
#include "AdcLdd1.h"
#include "SerialCom.h"
#include "Enable_Motors.h"
#include "BitIoLdd4.h"
#include "Motor_A_In1.h"
#include "PwmLdd1.h"
#include "TU2.h"
#include "Motor_A_In2.h"
#include "PwmLdd2.h"
#include "Motor_B_In1.h"
#include "PwmLdd3.h"
#include "Motor_B_In2.h"
#include "PwmLdd4.h"
#include "Servomotor.h"
#include "PwmLdd5.h"
#include "TU3.h"
#include "SW2_Start_Button.h"
#include "BitIoLdd3.h"
#include "Power_Level1.h"
#include "BitIoLdd5.h"
#include "Power_Level2.h"
#include "BitIoLdd6.h"
#include "Power_Level3.h"
#include "BitIoLdd7.h"
#include "Power_Level4.h"
#include "BitIoLdd8.h"
#include "GreenLED.h"
#include "BitIoLdd10.h"
#include "BlueLED.h"
#include "BitIoLdd11.h"
#include "Switch1.h"
#include "BitIoLdd12.h"
#include "Switch2.h"
#include "BitIoLdd13.h"
#include "Switch3.h"
#include "BitIoLdd14.h"
#include "ErrorLED.h"
#include "BitIoLdd9.h"

/* User includes*/
#include "CameraController.h"
#include "SerialCommunication.h"
#include "BatteryController.h"

// User Variables
extern volatile bool serialTest;
extern volatile bool serialFinished;
extern volatile bool serialTestStart;


#ifdef __cplusplus
extern "C" {
#endif 

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
void Cpu_OnNMIINT(void);


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
void Camera_CLK_Interruption_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  AS1_OnBlockReceived (module Events)
**
**     Component   :  AS1 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void AS1_OnBlockReceived(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  AS1_OnBlockSent (module Events)
**
**     Component   :  AS1 [Serial_LDD]
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
void AS1_OnBlockSent(LDD_TUserData *UserDataPtr);

void SerialInterrupt_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  SerialInterrupt_OnInterrupt (module Events)
**
**     Component   :  SerialInterrupt [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void AD_Converter_OnEnd(void);
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
void SerialCom_OnBlockSent(LDD_TUserData *UserDataPtr);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
