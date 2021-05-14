#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"
#import "data/scripts/dc_disney/conditions.c"

/*
* Animation to apply.
*/

void dc_disney_get_member_animation_pass_id()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_ID;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_ID;
	}

	return result;
}

void dc_disney_set_member_animation_pass_id(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_ID;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_ID)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_pass_frame()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_FRAME;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_FRAME;
	}

	return result;
}

void dc_disney_set_member_animation_pass_frame(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_FRAME;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_FRAME)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_pass_method()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_METHOD;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_METHOD;
	}

	return result;
}

void dc_disney_set_member_animation_pass_method(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_METHOD;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_METHOD)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_pass_reset()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_RESET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_PASS_RESET;
	}

	return result;
}

void dc_disney_set_member_animation_pass_reset(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_PASS_RESET;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_PASS_RESET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Animation on condition fail.
*/

void dc_disney_get_member_animation_fail_id()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_ID;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_ID;
	}

	return result;
}

void dc_disney_set_member_animation_fail_id(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_ID;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_ID)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_fail_frame()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_FRAME;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_FRAME;
	}

	return result;
}

void dc_disney_set_member_animation_fail_frame(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_FRAME;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_FRAME)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_fail_method()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_METHOD;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_METHOD;
	}

	return result;
}

void dc_disney_set_member_animation_fail_method(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_METHOD;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_METHOD)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_disney_get_member_animation_fail_reset()
{
	char id;
	void result;

	// Get id key.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_RESET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_ANIMATION_FAIL_RESET;
	}

	return result;
}

void dc_disney_set_member_animation_fail_reset(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_ANIMATION_FAIL_RESET;

	if (value == DC_DISNEY_DEFAULT_ANIMATION_FAIL_RESET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-05-13
*
* Conditional animation update. Checks all 
* conditions. If conditions all pass, plays
* pass aniamtion and frame. If any condition 
* fails, apply fail animation and frame.
*/
void dc_disney_try_conditional_animation()
{
	void acting_entity = dc_disney_get_member_entity();
	int animation_id = DC_DISNEY_ANIMATION_ID_NONE;
	int animation_frame = DC_DISNEY_ANIMATION_FRAME_NONE;
	int animation_method = DC_DISNEY_PLAY_METHOD_ENTITY_PROPERTY;
	int animation_reset = 0;

	/* 
	* Check all available conditions
	* and set up animations accordingly.
	*/
	if (dc_disney_check_all_conditions())
	{
		/* Conditions passed. */
		animation_id = dc_disney_get_member_animation_pass_id();
		animation_frame = dc_disney_get_member_animation_pass_frame();
		animation_method = dc_disney_get_member_animation_pass_method();
		animation_reset = dc_disney_get_member_animation_pass_reset();
	}
	else
	{
		/* Conditions failed. */
		animation_id = dc_disney_get_member_animation_fail_id();
		animation_frame = dc_disney_get_member_animation_fail_frame();
		animation_method = dc_disney_get_member_animation_fail_method();
		animation_reset = dc_disney_get_member_animation_fail_reset();
	}

	/* Send results to action functions. */
	dc_disney_try_animation_update(acting_entity, animation_id, animation_method, animation_reset);
	dc_disney_try_frame_update(acting_entity, animation_frame);
}

/*
* Caskey, Damon V.
* 2021-05-13
* 
* Attempt to run animation using specified 
* method. Return true on success, false if
* entity's model doesn't have the requested 
* animation.
*/
int dc_disney_try_animation_update(void acting_entity, int animation, int method, int reset)
{	
	/* Animation disabled. Exit. */
	if (animation == DC_DISNEY_ANIMATION_ID_NONE)
	{
		return 0;
	}	

	/* Verify entity has animation. */
	if (!getentityproperty(acting_entity, "animvalid", animation))
	{
		return 0;
	}

	switch (method)
	{
	default:
	case DC_DISNEY_PLAY_METHOD_ENTITY_PROPERTY:

		set_entity_property(acting_entity, "animation_id", animation);

		break;

	case DC_DISNEY_PLAY_METHOD_EXECUTE_ANIMATION:

		executeanimation(acting_entity, animation, reset);

		break;

	case DC_DISNEY_PLAY_METHOD_PERFORM_ATTACK:

		/* 
		* Note: getlocalvar("self") returns NULL after
		* perform attack.
		*/

		performattack(acting_entity, animation, reset);

		break;
	}
	
	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-13
* 
* Update frame, assuming frame argument is valid.
*/
void dc_disney_try_frame_update(void acting_entity, int frame)
{	
	/* If frame disabled, exit. */
	if (frame == DC_DISNEY_ANIMATION_FRAME_NONE)
	{
		return 0;
	}

	/*
	* We don't need to worry about arguments that
	* are too high. The engine does this for us
	* and ignores them. 
	*/
	updateframe(acting_entity, frame);
}