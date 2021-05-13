#include "data/scripts/dc_hansburg/config.h"

#import "data/scripts/dc_hansburg/entity.c"

float dc_hansburg_get_member_condition_position_y_max()
{
	char id;
	void result;

	// Get id key.
	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_CONDITION_POSITION_Y_MAX;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_HANSBURG_DEFAULT_CONDITION_POSITION_Y_MAX;
	}

	return result;
}

void dc_hansburg_set_member_condition_position_y_max(void value)
{
	char id;

	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_CONDITION_POSITION_Y_MAX;

	if (value == DC_HANSBURG_DEFAULT_CONDITION_POSITION_Y_MAX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-05-12 
* 
* Return true if entity is at or below 
* maximum allowed height for special jumping.
*/
int dc_hansburg_check_condition_position_y_max()
{
	void acting_entity = dc_hansburg_get_member_entity();
	
	int pos_y_max = dc_hansburg_get_member_condition_position_y_max();
	int position_y = get_entity_property(acting_entity, "position_y");

	/*
	* If current Y position is beyond maximum height, then
	* exit. We don't want to do anything else.
	*/
	if (position_y > pos_y_max)
	{
		// was triggered. Return false.
		return 0;
	}

	return 1;
}
