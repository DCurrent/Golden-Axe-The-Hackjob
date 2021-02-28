#include "data/scripts/dc_kanga/config.h"

#import "data/scripts/dc_kanga/instance.c"

// Base entity functions will act on.

// Get
void dc_kanga_get_target()
{
	char id;
	void result;

	// Get id key.
	id = dc_kanga_get_instance() + DC_KANGA_MEMBER_TARGET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_KANGA_DEFAULT_TARGET;
	}

	return result;
}

// Set
void dc_kanga_set_target(void value)
{
	char id;

	// Get id key.
	id = dc_kanga_get_instance() + DC_KANGA_MEMBER_TARGET;

	// If the value is same as default, then use
	// make sure variable is deleted instead. We fall
	// back to default for empty vars, so may as
	// well save the memory.
	if (value == DC_KANGA_DEFAULT_TARGET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

