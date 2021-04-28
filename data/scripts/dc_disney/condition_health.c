#include "data/scripts/dc_disney/config.h"

/* Health % of acting. */

float dc_disney_get_member_acting_health_portion()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_PORTION;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_PORTION;
	}

	return result;
}

void dc_disney_set_member_acting_health_portion(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_PORTION;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_PORTION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_acting_health_portion_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_PORTION_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_PORTION_EVAL;
	}

	return result;
}

void dc_disney_set_member_acting_health_portion_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_PORTION_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_PORTION_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Health value of acting. */

int dc_disney_get_member_acting_health_value()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_VALUE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_VALUE;
	}

	return result;
}

void dc_disney_set_member_acting_health_value(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_VALUE;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_VALUE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_get_member_acting_health_value_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_VALUE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_VALUE_EVAL;
	}

	return result;
}

void dc_disney_set_member_acting_health_value_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_VALUE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_VALUE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}


/* Health % of target. */

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

int dc_disney_get_member_target_health_portion_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION_EVAL;
	}

	return result;
}

void dc_disney_set_member_target_health_portion_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Health value of target. */

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

int dc_disney_get_member_target_health_value_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE_EVAL;
	}

	return result;
}

void dc_disney_set_member_target_health_value_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates target health portion condition.
* Return true if conditions are met.
*/
int dc_disney_check_condition_target_health_portion(void entity)
{
	float check_value = dc_disney_get_member_target_health_portion();
	int eval_type = dc_disney_get_member_target_health_portion_eval();

	int check_result = dc_disney_check_health_portion(entity, check_value);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_LESSER && check_result & DC_DISNEY_CONDITION_EVAL_GREATER)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_GREATER && check_result & DC_DISNEY_CONDITION_EVAL_LESSER)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_EQUAL && check_result & DC_DISNEY_CONDITION_EVAL_EQUAL)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Return condition of entity health % vs
* supplied portion value.
*/
int dc_disney_check_health_portion(void entity, float threshold)
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

	/*
	* If it's not greater or
	* lesser, it must be equal!
	*/

	if (health_portion > threshold)
	{
		return DC_DISNEY_CONDITION_EVAL_GREATER;
	}
	
	if (health_portion < threshold)
	{
		return DC_DISNEY_CONDITION_EVAL_LESSER;
	}

	return DC_DISNEY_CONDITION_EVAL_EQUAL;
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Evaluates target health condition.
* Return true if conditions are met.
*/
int dc_disney_check_condition_health_value(void entity)
{
	float check_value = dc_disney_get_member_target_health_value();
	int eval_type = dc_disney_get_member_target_health_value_eval();

	int check_result = dc_disney_check_health_value(entity, check_value);

	/*
	* All specified evaluations must pass or we return false.
	*/

	if (eval_type & DC_DISNEY_CONDITION_EVAL_LESSER && check_result & DC_DISNEY_CONDITION_EVAL_GREATER)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_GREATER && check_result & DC_DISNEY_CONDITION_EVAL_LESSER)
	{
		return 0;
	}

	if (eval_type & DC_DISNEY_CONDITION_EVAL_EQUAL && check_result & DC_DISNEY_CONDITION_EVAL_EQUAL)
	{
		return 0;
	}

	return 1;
}


/*
* Caskey, Damon V.
* 2021-05-25
*
* Return condition of entity health vs
* supplied value.
*/
int dc_disney_check_health_value(void entity, int threshold)
{
	float health_current = get_entity_property(entity, "hp");

	/* Result exceed value? */

	if (health_current > threshold)
	{
		return DC_DISNEY_CONDITION_EVAL_GREATER;
	}
	
	if (health_current < threshold)
	{
		return DC_DISNEY_CONDITION_EVAL_LESSER;
	}

	return DC_DISNEY_CONDITION_EVAL_EQUAL;
}