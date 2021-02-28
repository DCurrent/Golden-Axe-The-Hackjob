#include "data/scripts/dc_gauntlet/config.h"

/*
* Starting palette index when spawning.
*/


int dc_gauntlet_get_member_map()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_MAP);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_MAP;
	}

	return result;
}

int dc_gauntlet_set_member_map(int value)
{
	char id;

	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_MAP;

	if (value != DC_GAUNTLET_DEFAULT_MAP)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}
}