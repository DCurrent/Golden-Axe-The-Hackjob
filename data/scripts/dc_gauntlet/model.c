#include "data/scripts/dc_gauntlet/config.h"

/*
* Model name to spawn.
*/

char dc_gauntlet_get_member_model_name()
{
	int instance;
	char result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GUANTLET_MEMBER_MODEL_NAME);

	if (typeof(result) != openborconstant("VT_STR"))
	{
		result = DC_GAUNTLET_DEFAULT_MODEL_NAME;
	}

	return result;
}

char dc_gauntlet_set_member_model_name(char value)
{
	int instance;

	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GUANTLET_MEMBER_MODEL_NAME, value);
}