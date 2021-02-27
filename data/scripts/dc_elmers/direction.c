#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Non binding direction control.

int dc_elmers_get_member_direction()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DIRECTION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_DIRECTION;
	}

	return result;
}

int dc_elmers_set_member_direction(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DIRECTION;	

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_DIRECTION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-08-27
//
// Apply direction relative to target. Works exactly
// like direction adjustment in native bind.
int dc_elmers_apply_direction()
{
	int adjustment;
	int direction_target;
	int direction_ent;
	void target;
	void ent;

	target = dc_elmers_get_member_target();
	ent = dc_elmers_get_member_entity();

	adjustment = dc_elmers_get_member_direction();

	direction_target = get_entity_property(target, "position_direction");
	direction_ent = get_entity_property(ent, "position_direction");

	// If the setting is NONE, these conditions won't apply and we do nothing.
	if (adjustment == openborconstant("DIRECTION_ADJUST_LEFT"))
	{
		set_entity_property(ent, "position_direction", openborconstant("DIRECTION_LEFT"));	
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_RIGHT"))
	{
		set_entity_property(ent, "position_direction", openborconstant("DIRECTION_RIGHT"));
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_SAME"))
	{
		set_entity_property(ent, "position_direction", direction_target);
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_OPPOSITE"))
	{
		if (direction_target == openborconstant("DIRECTION_LEFT"))
		{
			set_entity_property(ent, "position_direction", openborconstant("DIRECTION_RIGHT"));
		}
		else
		{
			set_entity_property(ent, "position_direction", openborconstant("DIRECTION_LEFT"));
		}		
	}	
}