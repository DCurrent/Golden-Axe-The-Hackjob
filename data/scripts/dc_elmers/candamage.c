#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Can damage is the candamage property. It controls who we
// can hit with normal (i.e. not thrown/blast) attacks. In order to
// cause friendly fire when thrown around, our reaction 
// animations need an attack box. But we might not always be
// getting thrown/blasted. Ex: We get put in a choke hold
// so controller's allies can pound on us. In this case, the
// engine treats the attack box in our poses as any other 
// normal attack, and it will probably hit the controller.
//
// To prevent this from happening, we use candamage to disable
// our ability to attack normally. 

int dc_elmers_get_member_can_damage()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_CAN_DAMAGE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_CAN_DAMAGE;
	}

	return result;
}

int dc_elmers_set_member_can_damage(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_CAN_DAMAGE;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_CAN_DAMAGE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_elmers_get_member_can_damage_old()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_CAN_DAMAGE_OLD;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_CAN_DAMAGE_OLD;
	}

	return result;
}

int dc_elmers_set_member_can_damage_old(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_CAN_DAMAGE_OLD;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_CAN_DAMAGE_OLD)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-05-14
//
// Apply candamage member to entity.
void dc_elmers_apply_can_damage()
{
	void ent;
	int value;

	ent = dc_elmers_get_member_entity();

	value = dc_elmers_get_member_can_damage();

	changeentityproperty(ent, "candamage", value);
}

// Caskey, Damon V.
// 2019-05-14
//
// Apply candamage OLD member to entity.
void dc_elmers_apply_can_damage_old()
{
	void ent;
	int value;

	ent = dc_elmers_get_member_entity();

	value = dc_elmers_get_member_can_damage_old();

	changeentityproperty(ent, "candamage", value);
}