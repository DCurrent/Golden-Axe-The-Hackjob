#include "data/scripts/dc_hansburg/config.h"

// List of double jump types enabled.
int dc_hansburg_get_member_config_flags()
{
	char id;
	void result;

	// Get id key.
	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_CONFIG;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_HANSBURG_DEFAULT_CONFIG;
	}

	return result;
}

void dc_hansburg_set_member_config_flags(void value)
{
	char id;

	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_CONFIG;

	if (value == DC_HANSBURG_DEFAULT_CONFIG)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
