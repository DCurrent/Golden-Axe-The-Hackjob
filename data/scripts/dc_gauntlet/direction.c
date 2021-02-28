#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/entity.c"

/* Direction adjust settings. */

int dc_gauntlet_get_member_direction_adjust()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_DIRECTION_ADJUST);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_DIRECTION_ADJUST;
	}

	return result;
}

int dc_gauntlet_set_member_direction_adjust(int value)
{
	char id;

	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_DIRECTION_ADJUST;

	if (value != DC_GAUNTLET_DEFAULT_DIRECTION_ADJUST)
	{
		setlocalvar(id, value);		
	}
	else
	{
		setlocalvar(id, NULL());
	}
}

/* 
* Caskey, Damon V.
*
* Return a final direction value after comparing adjustment
* setting to entity direct we are adjusting from. Logic is 
* identical dentical to openbor engine's direction adjustment.
*/ 
int dc_find_adjusted_direction(int initial_direction)
{
	void ent;
	int adjustment;
	int ent_direction;

	adjustment = dc_gauntlet_get_member_direction_adjust();

	ent = dc_gauntlet_get_member_entity();
	ent_direction = get_entity_property(ent, "position_direction");


	if (adjustment == openborconstant("DIRECTION_ADJUST_NONE"))
	{
		return initial_direction;
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_SAME"))
	{
		return ent_direction;
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_OPPOSITE"))
	{
		if (ent_direction == openborconstant("DIRECTION_LEFT"))
		{
			return openborconstant("DIRECTION_RIGHT");
		}
		else
		{
			return openborconstant("DIRECTION_LEFT");
		}
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_RIGHT"))
	{
		return openborconstant("DIRECTION_RIGHT");
	}
	else if (adjustment == openborconstant("DIRECTION_ADJUST_LEFT"))
	{
		return openborconstant("DIRECTION_LEFT");
	}
	else
	{
		return initial_direction;
	}
}

/*
* Caskey, Damon V.
* 2019-03-18
*
* Apply direction adjust to spawned entity.
*/
void dc_apply_adjusted_direction(void spawn)
{
	int initial_direction;
	int final_direction;

	if (!spawn)
	{
		spawn = dc_gauntlet_get_member_spawn();
	}

	initial_direction = get_entity_property(spawn, "position_direction");

	final_direction = dc_find_adjusted_direction(initial_direction);

	set_entity_property(spawn, "position_direction", final_direction);

	return final_direction;
}