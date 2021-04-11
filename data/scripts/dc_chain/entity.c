#include "data/scripts/dc_chain/config.h"


// Base entity functions will act on.
// Get
void dc_chain_get_member_entity()
{
	char id;
	void result;

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_ENTITY;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_CHAIN_DEFAULT_ENTITY;
	}

	return result;
}

// Set
void dc_chain_set_member_entity(void value)
{
	char id;

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_ENTITY;

	if (value == DC_CHAIN_DEFAULT_ENTITY)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}
