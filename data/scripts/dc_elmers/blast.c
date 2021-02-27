#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Blast is a special state used by the engine to control
// behavior when falling. It is mainly used for throws and
// a "blast" attack. When entity has an active blast,
// its "projectilehit" model property is used in place of 
// "canadamage" property for attack boxes. Blast can also
// enable the native safe land ability (hold UP + Jump), 
// assuming the model has a land animation. The native AI
// can not and does not ever use landing ability.

int dc_elmers_get_member_blast()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_BLAST;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_BLAST;
	}

	return result;
}

int dc_elmers_set_member_blast(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_BLAST;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_BLAST)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-05-13
// 
// Wrapper for setting blast entity property. Just to make
// things a little simpler in model text files.
void dc_elmers_apply_blast()
{
	void ent; 
	int value;
	   	 
	ent = dc_elmers_get_member_entity();

	value = dc_elmers_get_member_blast();

	set_entity_property(ent, "blast_state", value);
}