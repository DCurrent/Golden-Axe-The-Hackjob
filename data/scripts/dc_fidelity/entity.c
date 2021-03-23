#include "data/scripts/dc_fidelity/config.h"

/*
* Entity is the target entity when searching for
* a model to play sounds, an on screen location
* for stereo effects, and anything else that
* requires a target entity reference. Defaults
* to the calling entity.
*/

/* Base entity functions will act on. */
void dc_fidelity_get_member_entity()
{
	char id;
	void result;

	// Get id key.
	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_ENT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_FIDELITY_DEFAULT_ENT;
	}

	return result;
}

void dc_fidelity_set_member_entity(void value)
{
	char id;


	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_ENT;

	if (value == DC_FIDELITY_DEFAULT_ENT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}