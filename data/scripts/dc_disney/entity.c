#include "data/scripts/dc_disney/config.h"

// Primary acting entity.
void dc_disney_get_member_entity()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_disney_get_instance();

	result = getlocalvar(instance + DC_DISNEY_MEMBER_ENT);

	if (result == NULL())
	{
		result = DC_DISNEY_DEFAULT_ENT;
	}

	log("\n dc_disney_get_member_entity " + result);

	return result;
}

void dc_disney_set_member_entity(void value)
{
	int instance;
	void result;

	// Get instance.
	instance = dc_disney_get_instance();

	setlocalvar(instance + DC_DISNEY_MEMBER_ENT, value);
}