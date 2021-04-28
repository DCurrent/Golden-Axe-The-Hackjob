#include "data/scripts/dc_disney/config.h"
#import "data/scripts/dc_disney/entity.c"

/*
* Target selection. This is where we select the target 
* used when running condition evaluations. 
* 
* Example: We want to switch aniamtions if an entity
* is much taller than acting entity. Target is the
* entity we will compare to acting entity's height.
*/

void dc_disney_get_member_target()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TARGET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_DISNEY_DEFAULT_TARGET;
	}

	return result;
}

void dc_disney_set_member_target(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TARGET;

	if (value == DC_DISNEY_DEFAULT_TARGET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_target_select_method()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TARGET_SELECT_METHOD;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_TARGET_SELECT_METHOD;
	}

	return result;
}

void dc_disney_set_member_target_select_method(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TARGET_SELECT_METHOD;

	if (value == DC_DISNEY_DEFAULT_TARGET_SELECT_METHOD)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_target_select_animation()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TARGET_SELECT_ANIMATION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_TARGET_SELECT_ANIMATION;
	}

	return result;
}

void dc_disney_set_member_target_select_animation(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TARGET_SELECT_ANIMATION;

	if (value == DC_DISNEY_DEFAULT_TARGET_SELECT_ANIMATION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Return animation used for evaluations 
* such as findtarget(). 
*/
int dc_disney_get_target_select_animation()
{
	int animation_member = dc_disney_get_member_target_select_animation();

	/* 
	* If the animation member value matches one
	* of our alternate source constants, then we
	* get the animation ID from the designated 
	* alternate source and return it.
	* 
	* Otherwise we can assume the member value is 
	* a animation ID we want to use and return it.
	*/
	if (animation_member == DC_DISNEY_ANIMATION_SELECT_ACTING_CURRENT)
	{
		void acting_entity = dc_disney_get_member_entity();

		return get_entity_property(acting_entity, "animation_id");
	}
	else
	{
		return animation_member;
	}
}

/*
* Caskey, Damon V.
* 2021-04-28
* 
* Return a target entity using designated 
* target select method.
*/
void dc_disney_get_target()
{
	int select_method = dc_disney_get_member_target_select_method();
	void acting_entity = dc_disney_get_member_entity();
	int animation_id = 0;

	/* 
	* Find out which method we want to
	* get target with and return the
	* target accordingly.
	* 
	* I'd prefer a switch statement, but
	* at time of writing OpenBOR doesn't
	* support macros for case values.
	*/

	if (select_method & DC_DISNEY_TARGET_SELECT_METHOD_ANIMATION)
	{
		animation_id = dc_disney_get_target_select_animation();
	
		return findtarget(acting_entity, animation_id);
	}

	if (select_method & DC_DISNEY_TARGET_SELECT_METHOD_GRABBED)
	{
		animation_id = dc_disney_get_target_select_animation();

		return get_entity_property(acting_entity, "grab_target");
	}

	if (select_method & DC_DISNEY_TARGET_SELECT_METHOD_MANUAL)
	{
		return dc_disney_get_member_target();
	}

	if (select_method & DC_DISNEY_TARGET_SELECT_METHOD_OPPONENT)
	{
		return get_entity_property(acting_entity, "opponent");
	}
}