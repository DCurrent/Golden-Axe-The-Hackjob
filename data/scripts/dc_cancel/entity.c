#include "data/scripts/dc_cancel/config.h"


// Base entity functions will act on.
// Get
void dc_cancel_get_member_entity()
{
	char id;
	void result;

	// Get id.
	id = dc_cancel_get_instance() + DC_CANCEL_MEMBER_ENT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_CANCEL_DEFAULT_ENTITY;
	}

	return result;
}

// Set
void dc_cancel_set_member_entity(void value)
{
	char id;

	// Get id.
	id = dc_cancel_get_instance() + DC_CANCEL_MEMBER_ENT;

	if (value == DC_CANCEL_DEFAULT_ENTITY)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
