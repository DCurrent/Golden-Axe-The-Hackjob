#include "data/scripts/dc_gauntlet/config.h"

/*
* Base entity functions will act on.
*/

void dc_gauntlet_get_member_entity()
{
	char id;
	void result;

	// Get id key.
	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_ENT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_GAUNTLET_DEFAULT_ENT;
	}

	return result;
}

void dc_gauntlet_set_member_entity(void value)
{
	char id;

	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_ENT;

	if (value == DC_GAUNTLET_DEFAULT_ENT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* 
* Spawned entity (if any).
*/ 

void dc_gauntlet_get_member_spawn()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_SPAWN);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_GAUNTLET_DEFAULT_SPAWN;
	}

	return result;
}

void dc_gauntlet_set_member_spawn(void value)
{
	int instance;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_SPAWN, value);
}
