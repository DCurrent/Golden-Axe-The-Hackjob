#include "data/scripts/dc_disney/config.h"

/* How acting entity evaluates random number. */

int dc_disney_get_member_acting_random_chance_eval()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_RANDOM_CHANCE_EVAL;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_RANDOM_CHANCE_EVAL;
	}

	return result;
}

void dc_disney_set_member_acting_random_chance_eval(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_RANDOM_CHANCE_EVAL;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_RANDOM_CHANCE_EVAL)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/* Random 0-100 value acting will run random chance against. */

int dc_disney_get_member_acting_random_chance()
{
	char id;
	void result;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_RANDOM_CHANCE;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_CONDITION_ACTING_RANDOM_CHANCE;
	}

	return result;
}

void dc_disney_set_member_acting_random_chance(void value)
{
	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_CONDITION_ACTING_RANDOM_CHANCE;

	if (value == DC_DISNEY_DEFAULT_CONDITION_ACTING_RANDOM_CHANCE)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_disney_check_condition_random_chance()
{
	float chance = dc_disney_get_member_acting_random_chance();
	int eval_type = dc_disney_get_member_acting_random_chance_eval();

	/* First let's get the roll result. */
	int check_result = dc_disney_check_random_chance(chance);

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
* Return condition of random chance 
* roll.
*/
int dc_disney_check_random_chance(int chance)
{
	/* 
	* Use current instance ID for random
	* library instance.
	*/
	dc_d20_set_instance(dc_disney_get_instance());

	/* 
	* Set ranges to 1 of 100, so that our
	* roll range is 0 to Chance. Note 0-100
	* is the default range setup, so we
	* shouldn't need this step unless the
	* random ranges on this instance are
	* chaned elsewhere.
	*
	* dc_d20_set_member_range_min(0);
	* dc_d20_set_member_range_max(100);
	*/	

	/* Set the chance, and roll dice! */

	dc_d20_set_member_chance(chance);

	if (dc_d20_chance_roll())
	{
		return DC_DISNEY_CONDITION_EVAL_TRUE;
	}
	
	return DC_DISNEY_CONDITION_EVAL_FALSE;
	
}
