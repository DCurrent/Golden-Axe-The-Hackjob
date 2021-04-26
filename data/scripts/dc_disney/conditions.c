#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/animation.c"
#import "data/scripts/dc_disney/entity.c"

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

/* Health % of animation target. */

float dc_disney_get_member_target_health_portion()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION;
	}

	return result;
}

void dc_disney_set_member_target_health_portion(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Health value of animation target. */

int dc_disney_get_member_target_health_value()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE;
	}

	return result;
}

void dc_disney_set_member_target_health_value(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Height of animation target. */

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

/*
* Caskey, Damon V.
* 2021-04-25
* 
* Return TRUE if all TARGET entity conditions 
* on TARGET pass for setting a new animation.
*/

int dc_disney_check_target_conditions(void target_entity)
{
	void acting_entity = dc_disney_get_member_entity();
	void target_entity = NULL();
	int animation = dc_disney_get_member_animation();
	int condition_flag = dc_disney_get_member_condition_flag_target();

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
	if (condition_flag & DC_DISNEY_CONDITION_GRAB_ELIGIBLE_NO || condition_flag & DC_DISNEY_CONDITION_GRAB_ELIGIBLE_YES)
	{
		int grab_eligible = dc_disney_check_grab_eligible(acting_entity, target_entity);

		/* Value should be opposite flag, or we exit with false. */

		if (grab_eligible && condition_flag & DC_DISNEY_CONDITION_GRAB_ELIGIBLE_NO)
		{
			return 0;
		}

		if (!grab_eligible && condition_flag & DC_DISNEY_CONDITION_GRAB_ELIGIBLE_YES)
		{
			return 0;
		}
	}
		
	/*
	* Target fully immune to grabs.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_GRAB_IMMUNE_NO || condition_flag & DC_DISNEY_CONDITION_GRAB_IMMUNE_YES)
	{
		int grab_immune = dc_disney_check_grab_immune(target_entity);

		/* Value should be opposite flag, or we exit with false. */

		if (grab_immune && condition_flag & DC_DISNEY_CONDITION_GRAB_IMMUNE_NO)
		{
			return 0;
		}
		
		if(!grab_immune && condition_flag & DC_DISNEY_CONDITION_GRAB_IMMUNE_YES)
		{
			return 0;
		}
	}
	
	/*
	* Target health % above/below threshold.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_HEALTH_PORTION_ABOVE || condition_flag & DC_DISNEY_CONDITION_HEALTH_PORTION_BELOW)
	{
		float portion_threshold = dc_disney_get_member_target_health_portion();

		int above_threshold = dc_disney_check_health_above_portion(target_entity, portion_threshold);

		/* Value should be opposite flag, or we exit with false. */

		if (above_threshold && condition_flag & DC_DISNEY_CONDITION_HEALTH_PORTION_BELOW)
		{
			return 0;
		}

		if (!above_threshold && condition_flag & DC_DISNEY_CONDITION_HEALTH_PORTION_ABOVE)
		{
			return 0;
		}
	}

	/*
	* Target health value above/below threshold.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE_ABOVE || condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE_BELOW)
	{
		float value_threshold = dc_disney_get_member_target_health_value();

		int above_threshold = dc_disney_check_health_above_value(target_entity, value_threshold);

		/* Value should be opposite flag, or we exit with false. */

		if (above_threshold && condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE_BELOW)
		{
			return 0;
		}

		if (!above_threshold && condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE_ABOVE)
		{
			return 0;
		}
	}

	/*
	* Difference between a taller target's height 
	* vs acting height is more/less than threshold.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_HEIGHT_DIFFERENCE_ABOVE || condition_flag & DC_DISNEY_CONDITION_HEIGHT_DIFFERENCE_BELOW)
	{
		float value_threshold = dc_disney_get_member_target_health_value();

		int above_height_threshold = dc_disney_check_height_difference_above(acting_entity, target_entity, value_threshold);

		/* Value should be opposite flag, or we exit with false. */

		if (above_height_threshold && condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE_BELOW)
		{
			return 0;
		}

		if (!above_height_threshold && condition_flag & DC_DISNEY_CONDITION_HEALTH_VALUE_ABOVE)
		{
			return 0;
		}
	}

	/*
	* Default model of target entity.
	*/
	if (condition_flag & DC_DISNEY_CONDITION_MODEL_DEFAULT_NO || condition_flag & DC_DISNEY_CONDITION_MODEL_DEFAULT_YES)
	{
		char defaultmodel = dc_disney_get_member_target_model_default();

		int model_match = dc_disney_check_defaultmodel_match(target_entity, defaultmodel);

		if (model_match && condition_flag & DC_DISNEY_CONDITION_MODEL_DEFAULT_NO)
		{
			return 0;
		}

		if (!model_match && condition_flag & DC_DISNEY_CONDITION_MODEL_DEFAULT_YES)
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
* Return TRUE if entity is immune to
* all grabs.
*/
void dc_disney_check_grab_immune(void entity)
{
	/*
	* Non fighting types, animals, and
	* entities with nograb enabled are
	* all immune to grabs.
	*/

	int type = getentityproperty(entity, "type");

	int animal = getentityproperty(entity, "animal");
	int nograb = get_entity_property(entity, "nograb");

	if (!animal
		&& !nograb
		&& (type == openborconstant("TYPE_PLAYER")
			|| type == openborconstant("TYPE_ENEMY")
			|| type == openborconstant("TYPE_NPC")))
	{
		return 1;

	}

	return 0;
}

/*
* Caskey, Damon V.
* 2021-04-25
*
* Return TRUE if acting entity is
* able to grab target entity.
*/
void dc_disney_check_grab_eligible(void acting_entity, void target_entity)
{
	/* 
	* If target is immune to grabs outright
	* nothing else matters.
	*/
	if (dc_disney_check_grab_immune(target_entity))
	{
		return 0;
	}

	/* Can acting grabforce beat target's antigrab? */

	int anti_grab = getentityproperty(acting_entity, "antigrab");
	int grab_force = getentityproperty(acting_entity, "grabforce");

	if (grab_force >= anti_grab)
	{
		return 1;
	}

	return 0;
}

/*
* Caskey, Damon V.
* 2021-05-25
* 
* Return true if entity health % exceeds
* supplied portion value.
*/
int dc_disney_check_health_above_portion(void entity, float threshold)
{
	float health_current = 0.0 + get_entity_property(entity, "hp");
	float health_max = 0.0 + getentityproperty(entity, "maxhealth");
	float health_portion = 0.0;

	// Don't divide by 0!
	if (health_current && health_max)
	{
		health_portion = health_current / health_max;
	}
	else
	{
		health_portion = 0.0;
	}

	/* Result exceed value? */

	if (health_portion > threshold)
	{
		return 1;
	}

	return 0;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Return true if entity health exceeds
* supplied value.
*/
int dc_disney_check_health_above_value(void entity, int threshold)
{
	float health_current = get_entity_property(entity, "hp");

	/* Result exceed value? */

	if (health_current > threshold)
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
