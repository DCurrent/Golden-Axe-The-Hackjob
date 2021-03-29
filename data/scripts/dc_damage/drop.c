#include "data/scripts/dc_damage/config.h"

/*
* Knockdown power to apply.
*/

int dc_damage_get_member_drop_force()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DROP_FORCE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_DROP_FORCE;
	}

	return result;
}

void dc_damage_set_member_drop_force(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_DROP_FORCE, value);
}