#include "data/scripts/dc_disney/config.h"


/* Animation ID, acting. */

int dc_disney_get_member_condition_acting_animation_id()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_ID;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_ID;
	}

	return result;
}

void dc_disney_set_member_condition_acting_animation_id(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_ID;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_ID)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_condition_acting_animation_id_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_ID_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_ID_EVAL;
	}

	return result;
}

void dc_disney_set_member_condition_acting_animation_id_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_ID_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_ID_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Animation ID, target. */

int dc_disney_get_member_condition_target_animation_id()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_ID;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_ID;
	}

	return result;
}

void dc_disney_set_member_condition_target_animation_id(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_ID;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_ID)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_condition_target_animation_id_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_ID_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_ID_EVAL;
	}

	return result;
}

void dc_disney_set_member_condition_target_animation_id_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_ID_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_ID_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

