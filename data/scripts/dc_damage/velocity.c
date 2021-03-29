#include "data/scripts/dc_damage/config.h"
#import "data/scripts/dc_damage/config.c"

/*
* Knockdown velocity to apply, X axis.
*/

float dc_damage_get_member_drop_velocity_x()
{
	char id;
	float result;

	// Get instance.
	id = dc_damage_get_instance() + DC_DAMAGE_MEMBER_DROP_VELOCITY_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_DAMAGE_DEFAULT_DROP_VELOCITY_X;
	}

	return result;
}

void dc_damage_set_member_drop_velocity_x(float value)
{
	char id;

	// Get id.
	id = dc_damage_get_instance() + DC_DAMAGE_MEMBER_DROP_VELOCITY_X;

	if (value == DC_DAMAGE_DEFAULT_DROP_VELOCITY_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Knockdown velocity to apply, Y axis.
*/

float dc_damage_get_member_drop_velocity_y()
{
	int instance;
	float result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DROP_VELOCITY_Y);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_DAMAGE_DEFAULT_DROP_VELOCITY_Y;
	}

	return result;
}

void dc_damage_set_member_drop_velocity_y(float value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_DROP_VELOCITY_Y, value);
}

/*
* Knockdown velocity to apply, Z axis.
*/

float dc_damage_get_member_drop_velocity_z()
{
	int instance;
	float result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DROP_VELOCITY_Z);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_DAMAGE_DEFAULT_DROP_VELOCITY_Z;
	}

	return result;
}

void dc_damage_set_member_drop_velocity_z(float value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_DROP_VELOCITY_Z, value);
}
