#include "data/scripts/dc_disney/config.h"

/*
* Caskey, Damon V.
* 2021-04-25
*
* Return true if conditions match.
*/

int dc_disney_check_condition_grab_immune(int eval_flag, void acting_entity, void target_entity)
{
	int value = dc_disney_check_grab_eligible(acting_entity, target_entity);

	if (eval_flag & DC_DISNEY_CONDITION_EVAL_TRUE && value)
	{
		return 1;
	}
	else if (eval_flag & DC_DISNEY_CONDITION_EVAL_FALSE && !value)
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
* Return true if conditions match.
*/
int dc_disney_check_condition_grab_elgible(int eval_flag, void acting_entity, void target_entity)
{
	int grab_eligible = dc_disney_check_grab_eligible(acting_entity, target_entity);

	if (eval_flag & DC_DISNEY_CONDITION_EVAL_TRUE && grab_eligible)
	{
		return 1;
	}
	else if (eval_flag & DC_DISNEY_CONDITION_EVAL_FALSE && !grab_eligible)
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