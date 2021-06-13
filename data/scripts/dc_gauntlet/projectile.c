#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/direction.c"
#import "data/scripts/dc_gauntlet/entity.c"
#import "data/scripts/dc_gauntlet/map.c"
#import "data/scripts/dc_gauntlet/model.c"
#import "data/scripts/dc_gauntlet/offset.c"

/*
* Direction to launch projectile.
*/

int dc_gauntlet_get_member_projectile_direction()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_DIRECTION);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_PROJECTILE_DIRECTION;
	}

	return result;
}

int dc_gauntlet_set_member_projectile_direction(int value)
{
	int instance;

	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_DIRECTION, value);
}

/*
* To launch projectile as non-moving.
*/

void dc_gauntlet_get_member_projectile_stationary()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_STATIONARY);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_PROJECTILE_STATIONARY;
	}

	return result;
}

int dc_gauntlet_set_member_projectile_stationary(int value)
{
	char id;

	// Get ID.
	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_PROJECTILE_STATIONARY;

	if (value != DC_GAUNTLET_DEFAULT_PROJECTILE_STATIONARY)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}
}

/*
* Type of projectile (knife, bomb, etc.) to launch.
*/

void dc_gauntlet_get_member_projectile_type()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_PROJECTILE_TYPE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_PROJECTILE_TYPE;
	}

	return result;
}

int dc_gauntlet_set_member_projectile_type(int value)
{
	char id;

	// Get ID.
	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_PROJECTILE_TYPE;

	if (value != DC_GAUNTLET_DEFAULT_PROJECTILE_TYPE)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}
}

/* 
* Caskey, Damon V
* 2019-03-16
*
* Spawn and throw projectile.
*/
void dc_guantlet_spawn_projectile()
{
	int relative;
	char model_name;
	int pos_x;
	int pos_y;
	int pos_z;
	int projectile_stationary;
	int projectile_type;
	int map;
	void spawn;
	
	log("\n\n dc_guantlet_spawn_projectile()");

	relative				= 0; //DC_GAUNTLET_DEFAULT_PROJECTILE_RELATIVE;
	model_name				= dc_gauntlet_get_member_model_name();  
	projectile_stationary	= dc_gauntlet_get_member_projectile_stationary();
	projectile_type			= dc_gauntlet_set_member_projectile_type();
	map						= dc_gauntlet_get_member_map();

	pos_x = dc_gauntlet_find_position_with_offset_x();
	pos_y = dc_gauntlet_find_position_with_offset_y();
	pos_z = dc_gauntlet_find_position_with_offset_z();

	log("\n\t relative: " + relative);
	log("\n\t model_name: " + model_name);
	log("\n\t projectile_stationary: " + projectile_stationary);
	log("\n\t projectile_type: " + projectile_type);
	log("\n\t map: " + map);
	log("\n\t pos_x: " + pos_x);
	log("\n\t pos_y: " + pos_y);
	log("\n\t pos_z: " + pos_z);

	/* 
	* Adjust launching entity and projectile position
	* to avoid launching into wall. The projectile should
	* have wall handling capability, but it's still better 
	* to launch just in front of a wall instead of inside it.
	*/

	pos_x += dc_terrian_quick_shunt(pos_x, pos_y, pos_z);

	/* Spawn the projectile. */
	//projectile(      name,       x,     z,     a,    direction,                                 pytype,                type,            map)
	spawn = projectile(model_name, pos_x, pos_z, pos_y, DC_GAUNTLET_DEFAULT_PROJECTILE_DIRECTION, projectile_stationary, projectile_type, map);

	/* Store the spawn as a local var. */
	dc_gauntlet_set_member_spawn(spawn);

	/* Adjust spawn's direction as needed. */
	dc_apply_adjusted_direction();

	/* 
	* Apply final values to set up typical projectile
	* behavior. 2021-02-17 - probably need to set up
	* member variables so we can adjust these during
	* runtime.
	*/
	changeentityproperty(spawn, "subject_to_gravity", 0);
	changeentityproperty(spawn, "no_adjust_base", 0);
	changeentityproperty(spawn, "subject_to_basemap", 1);

	return spawn;
}

/*
* Caskey, Damon V.
* 2019-03-16
* 
* Accept three axis position and returns X position. 
* If the position is inside a wall or platform, X 
* position is adjusted to nearest location outside
* of obstruction.
*/

int dc_terrian_quick_shunt(int pos_x, int pos_y, int pos_z)
{
	void ent;
	int adjustment;
	int ent_pos_x;

	ent = dc_gauntlet_get_member_entity();
	ent_pos_x = get_entity_property(ent, "position_x");

	adjustment = 0;

	while (checkwall(pos_x + adjustment, pos_z) > pos_y)
	{
		if (checkwall((pos_x + adjustment) - 1, pos_z))
		{
			adjustment -= 2;
		}
		else
		{
			adjustment -= 2;
		}
	}
	
	ent_pos_x += adjustment;

	set_entity_property(ent, "position_x", ent_pos_x);	

	return adjustment;
}