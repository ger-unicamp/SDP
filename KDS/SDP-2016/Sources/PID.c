#include "PID.h"

// the setup routine runs once when you press reset:

void resetPID(SPID *pid)
{
	pid->i_state = 0;
	pid->i_max = 1;
	pid->i_min = -1;

	pid->last_error = 0;
}

double update_pid (SPID * pid, double error)
{
	double output;

	// Termo proporcionao, integrativo e derivativo.
	double p_term = 0, i_term = 0, d_term = 0;


	// Verify how controls is been used.
	update_gains(pid);

	// Proportional term
	p_term = error * pid->p_gain;

	// integral term
	i_term = get_integral_term(pid, error);

	// derivative term
	d_term = get_derivative_state(pid, error);

	pid->last_error = error;

	output = p_term + i_term + d_term;


	if (output < -1)
	{
		output = -1;
	}
	else if (output > 1)
	{
		output = 1;
	}

	return output;
}

double get_derivative_state(SPID *pid, double error)
{
	return (error - pid->last_error) * pid->d_gain;
}

double get_integral_term(SPID * pid, double error)
{
	// Reset of i_state
	if (error < LIMIT_ERROR)
	{
		pid->i_state = 0;
	}

	// calculate the integrator state
	pid->i_state += error;

	// applies anti-windup
	if(pid->i_state > pid->i_max)
	{
		pid->i_state = pid->i_max;
	}

	else if(pid->i_state < pid->i_min)
	{
		pid->i_state = pid->i_min;
	}
	// Return the integrative error.
	return pid->i_state * pid->i_gain;
}

void update_gains(SPID *pid)
{
	// Proportional gain
	if (Switch1_GetVal())
	{
		pid->p_gain = P_DEFAUT_GAIN;
	}
	else
	{
		pid->p_gain = 0;
	}

	// Integrative gain
	if (Switch2_GetVal())
	{
		pid->i_gain = I_DEFAUT_GAIN;
	}
	else
	{
		pid->i_gain = 0;
	}

	// Derivative gain
	if (Switch3_GetVal())
	{
		pid->d_gain = D_DEFAUT_GAIN;
	}
	else
	{
		pid->d_gain = 0;
	}


}

