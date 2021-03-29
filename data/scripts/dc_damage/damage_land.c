#include "data/scripts/dc_damage/config.h"

/*
* Damage on landing force to apply.
*/

int dc_damage_get_member_damage_on_landing_force()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DOL_FORCE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_DOL_FORCE;
	}

	return result;
}

void dc_damage_set_member_damage_on_landing_force(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_DOL_FORCE, value);
}