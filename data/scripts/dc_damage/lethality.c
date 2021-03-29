#include "data/scripts/dc_damage/config.h"

#import "data/scripts/dc_damage/config.c"

/*
* Enable or disable lethal damage. When disabled, the
* damage system will reduce hitpoints to 1 (or close as
* possible depending on calculation), but not 0.
*/

int dc_damage_get_member_lethality()
{
	int instance;
	int result;

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_LETHALITY);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_LETHALITY;
	}

	return result;
}

void dc_damage_set_member_lethality(int value)
{
	int instance;

	setlocalvar(instance + DC_DAMAGE_MEMBER_LETHALITY, value);
}