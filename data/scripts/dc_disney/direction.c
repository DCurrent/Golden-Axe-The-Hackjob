#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"

// Caskey, Damon V.
// 2016-09-13
//
// Verify animation and entity, then instruct entity
// to perform animation as an attack.
int dc_disney_adjust_direction(int value)
{
	void ent;
	int direction_old;
	int result;
	
	// Get base entity.
	ent = dc_disney_get_entity();

	

	direction_old = get_entity_property(ent, "position_direction");

	if (value == openborconstant("DIRECTION_ADJUST_OPPOSITE"))
	{
		// Opposite of current direction.
		if (direction_old == openborconstant("DIRECTION_LEFT"))
		{
			result = openborconstant("DIRECTION_RIGHT");
		}
		else
		{
			result = openborconstant("DIRECTION_LEFT");
		}
	}
	else if (value == openborconstant("DIRECTION_ADJUST_LEFT"))
	{
		result = result = openborconstant("DIRECTION_LEFT");
	}
	else if (value == openborconstant("DIRECTION_ADJUST_RIGHT"))
	{
		result = result = openborconstant("DIRECTION_RIGHT");
	}
	else
	{
		result = direction_old;
	}

	set_entity_property(ent, "position_direction", result);

	return result;
}