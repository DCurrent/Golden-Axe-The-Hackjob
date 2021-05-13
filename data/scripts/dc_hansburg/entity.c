#include "data/scripts/dc_hansburg/config.h"

// Primary acting entity.
void dc_hansburg_get_member_entity()
{
	char id;
	void result;

	// Get id key.
	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_ENT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_HANSBURG_DEFAULT_ENT;
	}

	return result;
}

void dc_hansburg_set_member_entity(void value)
{
	char id;

	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_ENT;

	if (value == DC_HANSBURG_DEFAULT_ENT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}