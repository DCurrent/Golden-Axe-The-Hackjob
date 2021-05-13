#include "data/scripts/dc_hansburg/config.h"

// List of double jump types enabled.
int dc_hansburg_get_member_flag_list()
{
	char id;
	void result;

	// Get id key.
	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_FLAG_LIST;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_HANSBURG_DEFAULT_FLAG_LIST;
	}

	return result;
}

void dc_hansburg_set_member_flag_list(void value)
{
	char id;

	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_FLAG_LIST;

	if (value == DC_HANSBURG_DEFAULT_FLAG_LIST)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
