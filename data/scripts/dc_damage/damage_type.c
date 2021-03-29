#include "data/scripts/dc_damage/config.h"

/*
* Attack type to apply.
*/

int dc_damage_get_member_attack_type()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_TYPE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_TYPE;
	}

	return result;
}

void dc_damage_set_member_attack_type(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_TYPE, value);
}