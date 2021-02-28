#include "data/scripts/dc_kanga/config.h"

// Caskey, Damon V.
// 2018-08-23
//
// Replace old draw0002 function. Return whole int
// from incoming value based on target entity's current 
// draw scale. This is allows us to easily adjust 
// offsets for binds, spawns, etc. to match up with 
// the target's current drawing scale.
float dc_kanga_adjust_to_scale_x(void target, float value)
{
	float scale_percentage;

	// Get the target's scale percentage.
	scale_percentage = dc_kanga_get_scale_x_percentage(target);

	value *= scale_percentage;

	// If a 0 or empty slips through, set value to 1.
	if (!value)
	{
		value = 1;
	}

	// Round and return.
	value = round(value);

	return value;
}

// Caskey, Damon V.
// 2018-08-23
//
// See dc_kanga_adjust_to_scale_x.
float dc_kanga_adjust_to_scale_y(void target, float value)
{
	float scale_percentage;

	// Get the target's scale percentage.
	scale_percentage = dc_kanga_get_scale_y_percentage(target);

	value *= scale_percentage;

	// If a 0 or empty slips through, set value to 1.
	if (!value)
	{
		value = 1;
	}

	// Round and return.
	value = round(value);

	return value;
}

// Caskey, Damon V.
// 2018-08-22
//
// Get a decimal value of target's current
// scale vs. default (presumably full size)
// scale. NULL target means global drawmethod.
float dc_kanga_get_scale_x_percentage(void target)
{
	float	scale_current;
	float	scale_default;
	float	result = 0.0;

	// If the divisor and dividend are integers, 
	// then OpenBOR script treats the quotient as 
	// an integer too. Since we want a float result
	// let's force our values to be flating type
	// here.
	scale_current = getdrawmethod(target, "scalex") + 0.0;
	scale_default = DC_KANGA_DEFAULT_SCALE + 0.0;

	// If either is 0, then result must be 0.
	if (!scale_current || !scale_default)
	{
		return result;
	}

	result = scale_current / scale_default;

	return result;
}

// Caskey, Damon V.
// 2018-08-22
//
// Get a decimal value of target's current
// scale vs. default (presumably full size)
// scale. NULL target means global drawmethod.
float dc_kanga_get_scale_y_percentage(void target)
{
	float	scale_current;
	float	scale_default;
	float	result = 0.0;

	// If the divisor and dividend are integers, 
	// then OpenBOR script treats the quotient as 
	// an integer too. Since we want a float result
	// let's force our values to be flating type
	// here.
	scale_current = getdrawmethod(target, "scaley") + 0.0;
	scale_default = DC_KANGA_DEFAULT_SCALE + 0.0;

	// If either is 0, then result must be 0.
	if (!scale_current || !scale_default)
	{
		return result;
	}

	result = scale_current / scale_default;

	return result;
}