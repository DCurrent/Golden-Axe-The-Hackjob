#include "data/scripts/dc_chain/config.h"
#import "data/scripts/dc_chain/entity.c"

/*
* Amount of stun accrued.
*/

int dc_chain_get_member_stun_current()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_entity();
	
	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_current(): No acting entity pointer. \n\n");
	}

	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_CURRENT;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_CURRENT;
	}

	return result;
}

void dc_chain_set_member_stun_current(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_current(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_CURRENT;

	if (value == DC_CHAIN_DEFAULT_STUN_CURRENT)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Amount of stun required to induce stun reaction.
*/

int dc_chain_get_member_stun_threshold()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_threshold(): No acting entity pointer. \n\n");
	}

	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_THRESHOLD;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_THRESHOLD;
	}

	return result;
}

void dc_chain_set_member_stun_threshold(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_threshold(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_THRESHOLD;

	if (value == DC_CHAIN_DEFAULT_STUN_THRESHOLD)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Stun recovered per time unit (see check stun function).
*/

int dc_chain_get_member_stun_recover_amount()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_recover_amount(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVER_AMOUNT;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_RECOVER_AMOUNT;
	}

	return result;
}

void dc_chain_set_member_stun_recover_amount(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_recover_amount(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVER_AMOUNT;

	if (value == DC_CHAIN_DEFAULT_STUN_RECOVER_AMOUNT)
	{
		value = NULL();
	}

	setlocalvar(acting_entity, id, value);
}

/*
* Time unit to recover stun (see check stun function).
*/

int dc_chain_get_member_stun_recover_time()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_recover_time(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVER_TIME;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_RECOVER_TIME;
	}

	return result;
}

void dc_chain_set_member_stun_recover_time(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_recover_time(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVER_TIME;

	if (value == DC_CHAIN_DEFAULT_STUN_RECOVER_TIME)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Time unit to recover stun (see check stun function).
*/

int dc_chain_get_member_stun_last_check_time()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_last_check_time(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_LAST_CHECK_TIME;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_LAST_CHECK_TIME;
	}

	return result;
}

void dc_chain_set_member_last_check_time(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_last_check_time(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_LAST_CHECK_TIME;

	if (value == DC_CHAIN_DEFAULT_STUN_LAST_CHECK_TIME)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}


/*
* Animation when stunned.
*/

int dc_chain_get_member_stun_animation()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_animation(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_ANIMATION;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_ANIMATION;
	}

	return result;
}

void dc_chain_set_member_stun_animation(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_animation(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_ANIMATION;

	if (value == DC_CHAIN_DEFAULT_STUN_ANIMATION)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Caskey, Damon V.
* 2021-04-10 
* 
* Check current stun value vs. threshold. Return
* true if entity should be stunned (stun >= threshold).
*/
int dc_chain_check_stun()
{
	void acting_entity = dc_chain_get_member_entity()

	int stun_current = dc_chain_get_member_stun_current();
	int stun_threshold = dc_chain_get_member_stun_threshold();

	/* 
	* If at over over threshold then 
	* acting entity should be stunned.
	*/
	if (stun_current >= stun_threshold)
	{
		result = DC_CHAIN_FLAG_TRUE;
	}
}

/*
* Caskey, Damon V.
* 2021-04-10
* 
* Decrements current stun based on passage of time
* and deduct amount for every X units of time
* between last check.
*/
void dc_chain_decrement_stun()
{
	int stun_current = dc_chain_get_member_stun_current();
	int elapsed_time = openborvariant("elpased_time");
}