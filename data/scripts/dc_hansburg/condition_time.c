#include "data/scripts/dc_hansburg/config.h"

#import "data/scripts/dc_hansburg/entity.c"

// 
int dc_hansburg_get_member_condition_disable_time()
{
	char id;
	void result;

	// Get id key.
	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_DISABLE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_HANSBURG_DEFAULT_CONDITION_POSITION_Y_MAX;
	}

	return result;
}

void dc_hansburg_set_member_condition_disable_time(void value)
{
	char id;

	id = dc_hansburg_get_instance() + DC_HANSBURG_MEMBER_DISABLE;

	if (value == DC_HANSBURG_DEFAULT_CONDITION_POSITION_Y_MAX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-05-13
* 
* Return true if time is not set or time set 
* and not yet expired. 
*/
int dc_hansburg_check_disable_time()
{
    int elapsed_time = openborvariant("elapsed_time");
    int time_disable = dc_hansburg_get_member_condition_disable_time();

	if (time_disable && time_disable <= elapsed_time)
	{
		return 0;
	}

	return 1;    
}
