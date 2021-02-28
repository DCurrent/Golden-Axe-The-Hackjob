#include "data/scripts/dc_spinner/config.h"
#import "data/scripts/dc_spinner/instance.c"

// What to do when incrementing and already at range limit.
int dc_spinner_get_range_bound_max()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_BOUND_MAX;

		result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_BOUND_MAX;
	}

	return result;
}

void dc_spinner_set_range_bound_max(int value)
{
	char id;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_BOUND_MAX;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_RANGE_BOUND_MAX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_spinner_get_range_bound_min()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_BOUND_MIN;

		result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_BOUND_MIN;
	}

	return result;
}

void dc_spinner_set_range_bound_min(int value)
{
	char id;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_BOUND_MIN;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_RANGE_BOUND_MIN)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Maximum ranges of spinner.
int dc_spinner_get_range_max()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_MAX;

		result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_MAX;
	}

	return result;
}

void dc_spinner_set_range_max(int value)
{
	char id;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_MAX;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_RANGE_MAX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_spinner_set_range_min(int value)
{
	char id;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_MIN;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_RANGE_MIN)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_spinner_get_range_min()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_RANGE_MIN;

		result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_RANGE_MIN;
	}

	return result;
}

// Current incremented value.
void dc_spinner_set_value(int value)
{
	char id;
	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_VALUE;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_VALUE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_spinner_get_value()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_VALUE;

	result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_VALUE;
	}

	return result;
}

// Amount to increment.
void dc_spinner_set_increment(int value)
{
	int instance;
	instance = dc_spinner_get_instance();

	setlocalvar(instance + DC_SPINNER_MEMBER_INCREMENT, value);
}

// Amount added or deducted when cycling spinner.
int dc_spinner_get_increment()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_INCREMENT;

		result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_INCREMENT;
	}

	return result;
}

void dc_spinner_set_increment(int value)
{
	char id;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_INCREMENT;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_INCREMENT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}


// Number of steps want want to take when stepsing between
// original value and final value.
int dc_spinner_get_steps()
{
	char id;
	void result;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_STEPS;

		result = getlocalvar(id);

	if (!result)
	{
		result = DC_SPINNER_DEFAULT_STEPS;
	}

	return result;
}

void dc_spinner_set_steps(int value)
{
	char id;

	id = dc_spinner_get_instance() + DC_SPINNER_MEMBER_STEPS;

	// Delete if requested set value is default.
	if (value == DC_SPINNER_DEFAULT_STEPS)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2018-11-07
//
// Calculates, stores, and returns the size of an increment 
// from the start point, end point, and number of incremental
// steps we want to take.
int dc_spinner_increment_buid()
{
	int result;
	int start;
	int end;
	int diff;
	int steps;
	
	// Get start and end points.
	start = dc_spinner_get_range_min();
	end = dc_spinner_get_range_max();

	// Get the number of increment steps we want.
	steps = dc_spinner_get_steps();

	// What is the difference between start and end?
	diff = end - start;

	// Divide difference between start and end by the
	// number of steps we want to take, and that
	// gets us our increment size.
	result = diff / steps;

	dc_spinner_set_increment(result);

	return result;
}

// Increment the spinner. Stores and returns resulting
// spinner value.
int dc_spinner_increment_run()
{
	void target;
	int current;
	int increment;
	int range_bound;
	int range_min;
	int RANGE_MAX;


	// Get current and increment values.
	current		= dc_spinner_get_value();
	increment	= dc_spinner_get_increment();
	
	// Get our min/max ranges.
	range_min = dc_spinner_get_range_min();
	RANGE_MAX = dc_spinner_get_range_max();

	// Apply increment.
	current += increment;

	// Has current gone out of bounds?
	if (current < range_min)
	{
		// Get set action.
		range_bound = dc_spinner_get_range_bound_min();

		// Cap the value? Loop back? 
		if (range_bound == DC_SPINNER_RANGE_BOUND_LOOP)
		{
			current = RANGE_MAX;
		}
		else if (range_bound == DC_SPINNER_RANGE_BOUND_CAP)
		{
			current = range_min;
		}
	}
	else if (current > RANGE_MAX)
	{
		// Get set action.
		range_bound = dc_spinner_get_range_bound_max();

		// Cap the value? Loop back? 
		if (range_bound == DC_SPINNER_RANGE_BOUND_LOOP)
		{
			current = RANGE_MAX;
		}
		else if (range_bound == DC_SPINNER_RANGE_BOUND_CAP)
		{
			current = range_min;
		}
	}

	// Store and return the spinner value.
	dc_spinner_set_value(current);
	return current;
}