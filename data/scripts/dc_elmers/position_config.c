#include "data/scripts/dc_elmers/config.h"


// When adjusting toward or away from a position (as opposed
// to outright warping to new coordinates) these values 
// determine how far the entity is moved.

// X axis.
int dc_elmers_get_member_position_adjust_quantity_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_QUANTITY_X;
	}

	return result;
}

int dc_elmers_set_member_position_adjust_quantity_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_X;

	if (value == DC_ELMERS_DEFAULT_POSITION_QUANTITY_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis.
int dc_elmers_get_member_position_adjust_quantity_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_QUANTITY_Y;
	}

	return result;
}

int dc_elmers_set_member_position_adjust_quantity_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Y;

	if (value == DC_ELMERS_DEFAULT_POSITION_QUANTITY_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Z axis.
int dc_elmers_get_member_position_adjust_quantity_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_POSITION_QUANTITY_Z;
	}

	return result;
}

int dc_elmers_set_member_position_adjust_quantity_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_POSITION_QUANTITY_Z;

	if (value == DC_ELMERS_DEFAULT_POSITION_QUANTITY_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// "positioning" controls where we get our
// base target position from (screen, a target entity, etc.).

// X axis.
int dc_elmers_get_member_anchor_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ANCHOR_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_ANCHOR_X;
	}

	return result;
}

int dc_elmers_set_member_anchor_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ANCHOR_X;

	if (value == DC_ELMERS_DEFAULT_ANCHOR_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis.
int dc_elmers_get_member_anchor_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ANCHOR_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_ANCHOR_Y;
	}

	return result;
}

int dc_elmers_set_member_anchor_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ANCHOR_Y;

	if (value == DC_ELMERS_DEFAULT_ANCHOR_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// z axis.
int dc_elmers_get_member_anchor_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ANCHOR_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_ANCHOR_Z;
	}

	return result;
}

int dc_elmers_set_member_anchor_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ANCHOR_Z;

	if (value == DC_ELMERS_DEFAULT_ANCHOR_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
