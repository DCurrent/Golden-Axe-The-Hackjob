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

/* Animation frame, acting. */

int dc_disney_get_member_condition_acting_animation_frame_max()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_FRAME_MAX;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_FRAME_MAX;
	}

	return result;
}

void dc_disney_set_member_condition_acting_animation_frame_max(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_FRAME_MAX;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_FRAME_MAX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_condition_acting_animation_frame_min()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_FRAME_MIN;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_FRAME_MIN;
	}

	return result;
}

void dc_disney_set_member_condition_acting_animation_frame_min(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_FRAME_MIN;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_FRAME_MIN)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_condition_acting_animation_frame_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_FRAME_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_FRAME_EVAL;
	}

	return result;
}

void dc_disney_set_member_condition_acting_animation_frame_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_FRAME_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_FRAME_EVAL)
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

/* Animation frame, target. */

int dc_disney_get_member_condition_target_animation_frame_max()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_FRAME_MAX;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_FRAME_MAX;
	}

	return result;
}

void dc_disney_set_member_condition_target_animation_frame_max(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_FRAME_MAX;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_FRAME_MAX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_condition_target_animation_frame_min()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_FRAME_MIN;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_FRAME_MIN;
	}

	return result;
}

void dc_disney_set_member_condition_target_animation_frame_min(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_FRAME_MIN;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_FRAME_MIN)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_condition_target_animation_frame_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_FRAME_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_FRAME_EVAL;
	}

	return result;
}

void dc_disney_set_member_condition_target_animation_frame_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_FRAME_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_FRAME_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}


/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates acting animation. Return true 
* if value == current.
*/
int dc_disney_check_condition_acting_animation_id(void entity)
{
	int check_value = dc_disney_get_member_condition_acting_animation_id();
	int eval_type = dc_disney_get_member_condition_acting_animation_id_eval();

	int check_result = dc_disney_check_animation_id(entity, check_value);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates target animation. Return true
* if value == current.
*/
int dc_disney_check_condition_target_animation_id(void entity)
{
	int check_value = dc_disney_get_member_condition_target_animation_id();
	int eval_type = dc_disney_get_member_condition_target_animation_id_eval();

	int check_result = dc_disney_check_animation_id(entity, check_value);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluate current animation ID vs. entity
* current animation ID.
*/
int dc_disney_check_animation_id(void entity, int animation_id)
{
	int animation_id_current = get_entity_property(entity, "animation_id");

	/* Result equal value? */

	if (animation_id_current == animation_id)
	{
		return DC_DISNEY_CONDITION_EVAL_TRUE;
	}

	return DC_DISNEY_CONDITION_EVAL_FALSE;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates acting frame. Return true
* if current frame is in min/max range.
*/
int dc_disney_check_condition_acting_animation_frame(void entity)
{
	int check_value_min = dc_disney_get_member_condition_acting_animation_frame_min();
	int check_value_max = dc_disney_get_member_condition_acting_animation_frame_max();

	int eval_type = dc_disney_get_member_condition_acting_animation_frame_eval();

	int check_result = dc_disney_check_animation_frame(entity, check_value_min, check_value_max);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates target frame. Return true
* if current frame is in min/max range.
*/
int dc_disney_check_condition_target_animation_frame(void entity)
{
	int check_value_min = dc_disney_get_member_condition_target_animation_frame_min();
	int check_value_max = dc_disney_get_member_condition_target_animation_frame_max();

	int eval_type = dc_disney_get_member_condition_target_animation_frame_eval();

	int check_result = dc_disney_check_animation_frame(entity, check_value_min, check_value_max);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluate current animation frame vs range.
*/
int dc_disney_check_animation_frame(void entity, int frame_min, int frame_max)
{
	int animation_frame_current = get_entity_property(entity, "animation_frame");

	/* 
	* Frame within range? Ignore max if set to
	* last, as it means last frame is the 
	* last in range.
	*/

	if (animation_frame_current >= frame_min && (animation_frame_current <= frame_max || frame_max == DC_DISNEY_ANIMATION_FRAME_NONE))
	{
		return DC_DISNEY_CONDITION_EVAL_TRUE;
	}

	return DC_DISNEY_CONDITION_EVAL_FALSE;
}