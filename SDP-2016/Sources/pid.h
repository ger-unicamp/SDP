/*
 * PID.h
 *
 *  Created on: 27/07/2017
 *      Author: marcelo
 */

#ifndef SOURCES_PID_H_
#define SOURCES_PID_H_

// Switchs
#include "BitIoLdd11.h"
#include "Switch1.h"
#include "BitIoLdd12.h"
#include "Switch2.h"
#include "BitIoLdd13.h"
#include "Switch3.h"

struct SPID
{
  // PID gains
  double p_gain;
  double d_gain;
  double i_gain;

  double i_state;
  int i_max;
  int i_min;

  double last_error;
  double last_track_width;
} typedef SPID;

// Default values of gains
#define P_DEFAUT_GAIN 0.8
#define D_DEFAUT_GAIN 0.4
#define I_DEFAUT_GAIN 0.6

#define LIMIT_ERROR 0.1

double update_pid (SPID * pid, double error);
double get_derivative_state(SPID *pid, double error);
double get_integral_term(SPID * pid, double error);
void update_gains(SPID *pid);
void resetPID(SPID *pid);


#endif /* SOURCES_PID_H_ */
