#include "data/scripts/dc_elmers/config.h"

// Accessors and Mutators.

// X axis level position.
int dc_elmers_get_member_level_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_LEVEL_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_LEVEL_X;
	}

	return result;
}

int dc_elmers_set_member_level_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_LEVEL_X;

	if (value == DC_ELMERS_DEFAULT_LEVEL_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis level position.
int dc_elmers_get_member_level_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_LEVEL_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_LEVEL_Y;
	}

	return result;
}

int dc_elmers_set_member_level_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_LEVEL_Y;

	if (value == DC_ELMERS_DEFAULT_LEVEL_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Z axis level position.
int dc_elmers_get_level_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_LEVEL_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_LEVEL_Z;
	}

	return result;
}

int dc_elmers_set_level_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_LEVEL_Z;

	if (value == DC_ELMERS_DEFAULT_LEVEL_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
