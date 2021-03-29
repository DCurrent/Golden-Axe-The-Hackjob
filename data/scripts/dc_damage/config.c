#include "data/scripts/dc_damage/config.h"

/*
* Damage on landing force to apply.
*/
int dc_damage_get_member_damage_on_landing_force()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DOL_FORCE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_DOL_FORCE;
	}

	return result;
}

void dc_damage_set_member_damage_on_landing_force(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_DOL_FORCE, value);
}

/*
* Knockdown power to apply.
*/
int dc_damage_get_member_drop_force()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_DROP_FORCE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_DROP_FORCE;
	}

	return result;
}

void dc_damage_set_member_drop_force(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_DROP_FORCE, value);
}

/*
* Base entity functions will act on. This is the
* entity that takes applied damage.
*/
void dc_damage_get_member_entity()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_ENT);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_DAMAGE_DEFAULT_ENT;
	}

	return result;
}

void dc_damage_set_member_entity(void value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_ENT, value);
}

/*
* Force (amount of hitpoint damage) to apply.
*/
int dc_damage_get_member_damage_force()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_FORCE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_FORCE;
	}

	return result;
}

void dc_damage_set_member_damage_force(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_FORCE, value);
}

/*
* Entity given credit for damage.
*/
void dc_damage_get_member_other()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_damage_get_instance();

	result = getlocalvar(instance + DC_DAMAGE_MEMBER_OTHER);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_DAMAGE_DEFAULT_OTHER;
	}

	return result;
}

void dc_damage_set_member_other(void value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_OTHER, value);
}

/*
* Projectile mode (i.e. attack box activated while falling) to apply.
* 
* This is used mainly for indirect hits. The most common example
* is when one entity is thrown into a group of his own buddies and 
* knocks them all down.
*/
int dc_damage_get_member_projectile()
{
	char id;
	int result;
	
	// Get id.
	id = dc_damage_get_instance() + DC_DAMAGE_MEMBER_PROJECTILE;
	
	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_PROJECTILE;
	}

	return result;
}

void dc_damage_set_member_projectile(int value)
{
	char id;

	// Get id.
	id = dc_damage_get_instance() + DC_DAMAGE_MEMBER_PROJECTILE;

	if (value == DC_DAMAGE_DEFAULT_PROJECTILE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Attack type (Normal #, Shock, Fire, etc.) to apply.
*/
int dc_damage_get_member_attack_type()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_damage_get_instance();
	
	result = getlocalvar(instance + DC_DAMAGE_MEMBER_TYPE);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DAMAGE_DEFAULT_TYPE;
	}

	return result;
}

void dc_damage_set_member_attack_type(int value)
{
	int instance;

	// Get instance.
	instance = dc_damage_get_instance();

	setlocalvar(instance + DC_DAMAGE_MEMBER_TYPE, value);
}