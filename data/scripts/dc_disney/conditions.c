#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/animation.c"
#import "data/scripts/dc_disney/entity.c"
#import "data/scripts/dc_disney/condition_grab.c"
#import "data/scripts/dc_disney/condition_health.c"
#import "data/scripts/dc_disney/target_select.c"

/* Flag that determines which conditions are applied. */

int dc_disney_get_member_condition_flag_target()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_FLAG_TARGET;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_FLAG_TARGET;
	}

	return result;
}

void dc_disney_set_member_condition_flag_target(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_FLAG_TARGET;

	if (value == DC_DISNEY_DEFAULT_CONDITION_FLAG_TARGET)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Health value of target. */

int dc_disney_get_member_target_animation()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION;
	}

	return result;
}

void dc_disney_set_member_target_animation(int value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Height of target. */

int dc_disney_get_member_target_height_difference()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_DIFFERENCE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_DIFFERENCE;
	}

	return result;
}

void dc_disney_set_member_target_height_difference(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_DIFFERENCE;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_DIFFERENCE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Name of target's base model. */

char dc_disney_get_member_target_model_default()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_MODEL_DEFAULT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_STR"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_MODEL_DEFAULT;
	}

	return result;
}

void dc_disney_set_member_target_model_default(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_MODEL_DEFAULT;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_MODEL_DEFAULT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* MP % of target. */

float dc_disney_get_member_target_mp_portion()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_MP_PORTION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_PORTION;
	}

	return result;
}

void dc_disney_set_member_target_mp_portion(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_MP_PORTION;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_PORTION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* MP value of target. */

int dc_disney_get_member_target_mp_value()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_MP_VALUE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE;
	}

	return result;
}

void dc_disney_set_member_target_mp_value(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_MP_VALUE;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_VALUE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-04-25
* 
* Return TRUE if all TARGET entity conditions 
* on TARGET pass for setting a new animation.
*/

int dc_disney_check_target_conditions()
{
	void acting_entity = dc_disney_get_member_entity();
	void target_entity = dc_disney_get_target();
	int animation = dc_disney_get_member_animation();
	int condition_flag = dc_disney_get_member_condition_flag_target();
	int condition_eval = dc_disney_get_member_condition_flag_target();

	/*
	* Now we go one by one through conditions. 
	* If the condition flag bit for a given 
	* condition is on, we check that condition.
	* If not, we skip it and move on.
	* 
	* When a condition check is made and passes 
	* we continue. Otherwise  we return FALSE 
	* instantly.
	*/

	/*
	* Acting walkoff. Are we falling and not 
	* in a jump state? The engine has a native 
	* walkoff, but this can handle walkoffs
	* outside of the walking animations engine
	* checks for.
	*/
	if(condition_flag & DC_DISNEY_CONDITION_WALKOFF)
	{
		if (!dc_disney_check_walkoff())
		{
			return 0;
		}
	}

	/*
	* Acting entity can't grab target.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_GRAB_ELIGIBLE)
	{
		if (!dc_disney_check_condition_grab_elgible(condition_eval, acting_entity, target_entity))
		{
			return 0; 
		}		
	}
		
	/*
	* Target fully immune to grabs.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_GRAB_IMMUNE)
	{
		if (!dc_disney_check_condition_grab_immune(condition_eval, acting_entity, target_entity))
		{
			return 0;
		}
	}
	
	/*
	* Target health %.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_HEALTH_PORTION)
	{
		if (!dc_disney_check_condition_target_health_portion(target_entity))
		{
			return 0;
		}
	}

	/*
	* Target health value above/below threshold.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE)
	{
		if (!dc_disney_check_condition_health_value(target_entity))
		{
			return 0;
		}
	}

	/*
	* Difference between a taller target's height 
	* vs acting height is more/less than threshold.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_HEIGHT_DIFFERENCE)
	{
		float value_threshold = dc_disney_get_member_target_health_value();

		int above_height_threshold = dc_disney_check_height_difference_above(acting_entity, target_entity, value_threshold);

		/* Value should be opposite flag, or we exit with false. */

		if (above_height_threshold && condition_flag & DC_DISNEY_CONDITION_EVAL_LESSER)
		{
			return 0;
		}

		if (!above_height_threshold && condition_flag & DC_DISNEY_CONDITION_EVAL_GREATER)
		{
			return 0;
		}
	}

	/*
	* Default model of target entity.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_MODEL_DEFAULT)
	{
		char defaultmodel = dc_disney_get_member_target_model_default();

		int model_match = dc_disney_check_defaultmodel_match(target_entity, defaultmodel);

		if (model_match && condition_flag & DC_DISNEY_CONDITION_EVAL_FALSE)
		{
			return 0;
		}

		if (!model_match && condition_flag & DC_DISNEY_CONDITION_EVAL_TRUE)
		{
			return 0;
		}
	}
}

/*
* Caskey, Damon V.
* 2018-11-03
*
* Return true if in a walkoff condition.
*/
int dc_disney_check_walkoff(void entity)
{	
	/*
	* If we aren't falling or in jump state
	* just exit.
	*/
	
	float	velocity_y = get_entity_property(entity, "velocity_y");
	int     jump_state = get_entity_property(entity, "jump_state");


	if (velocity_y >= 0.0 || jump_state)
	{
		return 0;
	}

	/*
	* Are we in one of the predetermined walkoff
	* eligible animations?
	*/

	int animation_id = get_entity_property(entity, "animation_id");

	if (animation_id == -1
		|| animation_id == openborconstant("ANI_IDLE")
		|| animation_id == openborconstant("ANI_ATTACKUP")
		|| animation_id == openborconstant("ANI_ATTACKDOWN")
		|| animation_id == openborconstant("ANI_FREESPECIAL2"))
	{		
		return 1;
	}

	return 0;
}



/*
* Caskey, Damon V.
* 2021-04-25
*
* Return TRUE if difference between entity
* and target height exceeds threshold.
*/
int dc_disney_check_height_difference_above(void acting_entity, void target_entity, int threshold)
{
	float acting_pos_y = get_entity_property(acting_entity);
	int acting_size_y = getentityproperty(acting_entity, "height");
	
	float target_pos_y = get_entity_property(target_entity);
	int target_size_y = getentityproperty(acting_entity, "height");
	
	int acting_height = acting_pos_y + acting_size_y;
	int target_height = target_pos_y + target_size_y;

	/* 
	* We assume target is taller. Is the difference
	* more than threshold? 
	*/

	if (target_height - acting_height > threshold)
	{
		return 1;
	}

	return 0;
}

/*
* Caskey, Damon V.
* 2021-04-26
* 
* Return true of entity default model 
* matches supplied name.
*/
int dc_disney_check_defaultmodel_match(void entity, char match_name)
{
	char defaultmodel = getentityproperty(entity, "defaultname");

	char defaultmodel = dc_disney_get_member_target_model_default();

	if (defaultmodel == match_name)
	{
		return 1;
	}

	return 0;
}
