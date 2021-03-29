#include "data/scripts/dc_damage/config.h"
#import "data/scripts/dc_damage/config.c"
#import "data/scripts/dc_damage/entity.c"

/*
* Direction adjustment.
*/
int dc_damage_get_member_direction_adjust()
{
	int instance;
	int result;

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DIRECTION_ADJUST);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_DIRECTION_ADJUST;
	}

	return result;
}

void dc_damage_set_member_direction_adjust(int value)
{
	int instance;

	setlocalvar(instance + DC_DAMAGE_MEMBER_DIRECTION_ADJUST, value);
}

/*
* Applies direction adjustment to entity.
*/ 
void dc_damage_apply_direction_adjust()
{
	void ent;
	int direction;

	ent = dc_damage_get_member_entity();
	direction = dc_damage_find_adjusted_direction();

	set_entity_property(ent, "position_direction", direction);
}

/* 
* Caskey, Damon V.
* 2018-11-13
*
* Determine which direction should be applied to entity based
* on direction adjustment setting and entity's current
* direction. Essentially mimics the native function 
* engine uses for direction adjustment.
*/
int dc_damage_find_adjusted_direction()
{
	void ent;
	void other;
	int direction_adjust;
	int direction_current;
	int direction_final;

	ent = dc_damage_get_member_entity();
	other = dc_damage_get_member_other();

	direction_adjust = dc_damage_get_member_direction_adjust();
		
	direction_current = get_entity_property(other, "position_direction");

	if (direction_adjust == openborconstant("DIRECTION_ADJUST_LEFT"))
	{
		direction_final = openborconstant("DIRECTION_LEFT");
	}
	else if (direction_adjust == openborconstant("DIRECTION_ADJUST_OPPOSITE"))
	{
		if (direction_current == openborconstant("DIRECTION_LEFT"))
		{
			direction_final = openborconstant("DIRECTION_RIGHT");
		}
		else if(direction_current == openborconstant("DIRECTION_RIGHT"))
		{
			direction_final = openborconstant("DIRECTION_LEFT");
		}
	}
	else if (direction_adjust == openborconstant("DIRECTION_ADJUST_RIGHT"))
	{
		direction_final = openborconstant("DIRECTION_RIGHT");
	}
	else if (direction_adjust == openborconstant("DIRECTION_ADJUST_SAME"))
	{
		direction_final = direction_current;
	}
	else if (direction_adjust == openborconstant("DIRECTION_ADJUST_NONE"))
	{
		direction_final = get_entity_property(ent, "position_direction");
	}

	return direction_final;
}
