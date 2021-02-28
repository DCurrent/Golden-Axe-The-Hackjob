#include "data/scripts/dc_gauntlet/config.h"


/* Autokill (kill self when current animation completes) settings. */

int dc_gauntlet_get_member_autokill()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_AUTOKILL);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_AUTOKILL;
	}

	return result;
}

void dc_gauntlet_set_member_autokill(int value)
{
	char id;

	// Get ID.
	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_AUTOKILL;

	// If value is default, make sure the variable
	// is deleted.
	if (value != DC_GAUNTLET_DEFAULT_AUTOKILL)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}
}