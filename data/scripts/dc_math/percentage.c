#include "data/scripts/dc_math/config.h"


// Caskey, Damon V. 
// 2018-08-23
//
// Return adjusted value from
// supplied percentage and float. 
//
// Example: Percent 0.1, value 100, return 10.0.
//
// This is useful when we need to adjust a value 
// by some percentage and then pass it to a function 
// that only accepts whole values (such as binding).
float dc_math_value_from_percent(float percent, float value)
{
	int negative = 0; // Negative flag.

	// Negative number? If so, the conversions below won't work. 
	// Temporarily invert to a positive integer. We'll also
	// set a flag alerting us to invert the value back to
	// negative when we're done.
	if (value < 0) 
	{
		negative = 1;
		value = value * -1;
	}

	// Value must be a float for calculations to work.
	value += 0.0;

	// Mutiply by percent to get adjusted value.
	value *= percent;

	// If we get a 0 value, then set
	// our value to 1 instead.
	if (!value)
	{ 
		value = 1.0; 
	} 

	return value;
}