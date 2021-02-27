#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Attacking turns the standard attack box on or off. 

int dc_elmers_get_member_attacking()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ATTACKING;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_ATTACKING;
	}

	return result;
}

int dc_elmers_set_attacking(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_ATTACKING;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_ATTACKING)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-05-14
//
// Apply attacking member to entity.
void dc_elmers_apply_attacking()
{
	void ent;
	int value;

	ent = dc_elmers_get_member_entity();

	value = dc_elmers_get_member_attacking();

	set_entity_property(ent, "attack_state", value);
}