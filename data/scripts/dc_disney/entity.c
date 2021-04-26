#include "data/scripts/dc_disney/config.h"

// Primary acting entity.
void dc_disney_get_member_entity()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ENT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_DISNEY_DEFAULT_ENT;
	}

	return result;
}

void dc_disney_set_member_entity(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ENT;

	if (value == DC_DISNEY_DEFAULT_ENT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}