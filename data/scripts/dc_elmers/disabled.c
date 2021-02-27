#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// When disabled, calls to apply binding are ignored. This is so we
// can perform actions like conditionally releasing a bound entity 
// partially through an animation without subsequent bind calls in 
// the animation making a mess.

int dc_elmers_get_member_disabled()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DISABLED;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_DISABLED;
	}

	return result;
}

int dc_elmers_set_member_disabled(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DISABLED;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_DISABLED)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}