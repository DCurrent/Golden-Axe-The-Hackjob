#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Tag is a user defined value the engine ignores.

int dc_elmers_get_member_tag()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_TAG;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_TAG;
	}

	return result;
}

int dc_elmers_set_member_tag(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_TAG;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_TAG)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-05-13
// 
// Apply member value to property.
void dc_elmers_apply_tag()
{
	void ent;
	void bind;
	void value;
	   	 
	ent = dc_elmers_get_member_entity();

	bind = get_entity_property(ent, "bind");

	value = dc_elmers_get_member_tag();

	set_bind_property(bind, "meta_tag", value);
}

// Caskey, Damon V.
// 2019-05-29
//
// Get the property and apply it to member. 
int dc_elmers_set_member_tag_from_property()
{
	void ent;
	void bind;
	void value;

	ent = dc_elmers_get_member_entity();

	bind = get_entity_property(ent, "bind");

	value = get_bind_property(bind, "meta_tag");

	dc_elmers_set_member_tag(value);

	return value;
}