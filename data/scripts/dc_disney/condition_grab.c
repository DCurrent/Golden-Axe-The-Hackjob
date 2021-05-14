#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"
#import "data/scripts/dc_disney/target_select.c"

int dc_disney_get_member_acting_grab_eligible_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_ELIGIBLE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_ELIGIBLE_EVAL;
	}

	return result;
}

void dc_disney_set_member_acting_eligible_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_ELIGIBLE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_ELIGIBLE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_acting_grab_immune_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_IMMUNE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_IMMUNE_EVAL;
	}

	return result;
}

void dc_disney_set_member_acting_immune_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_IMMUNE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_IMMUNE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_target_grab_eligible_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_ELIGIBLE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_ELIGIBLE_EVAL;
	}

	return result;
}

void dc_disney_set_member_target_eligible_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_ELIGIBLE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_ELIGIBLE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_target_grab_immune_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_IMMUNE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_IMMUNE_EVAL;
	}

	return result;
}

void dc_disney_set_member_target_immune_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_IMMUNE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_IMMUNE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates acting ability to grab target.
*/
int dc_disney_check_condition_target_grab_eligible()
{
	void acting_entity = dc_disney_get_member_entity();
	void target_entity = dc_disney_get_target();

	int eval_type = dc_disney_get_member_acting_grab_eligible_eval();

	int check_result = dc_disney_check_grab_eligible(acting_entity, target_entity);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates acting ability to grab target.
*/
int dc_disney_check_condition_target_grab_immune()
{
	void target_entity = dc_disney_get_target();

	int eval_type = dc_disney_get_member_acting_grab_immune_eval();

	int check_result = dc_disney_check_grab_immune(target_entity);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_FALSE && check_result)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_TRUE && !check_result)
	{
		return 0;
	}

	return 1;
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

int dc_disney_check_grab_eligible(void acting_entity, void target_entity)
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