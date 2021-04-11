#include "data/scripts/dc_chain/config.h"
#import "data/scripts/dc_chain/entity.c"

/*
* Amount of stun accrued.
*/

int dc_chain_get_member_stun_current()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_member_entity();
	
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
	void acting_entity = dc_chain_get_member_entity();

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
	void acting_entity = dc_chain_get_member_entity();

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
	void acting_entity = dc_chain_get_member_entity();

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

int dc_chain_get_member_stun_recovery_rate()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_recovery_rate(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_RATE;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_RECOVERY_RATE;
	}

	return result;
}

void dc_chain_set_member_stun_recovery_rate(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_recovery_rate(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_RATE;

	if (value == DC_CHAIN_DEFAULT_STUN_RECOVERY_RATE)
	{
		value = NULL();
	}

	setlocalvar(acting_entity, id, value);
}

/*
* Time unit to recover stun (see check stun function).
*/

int dc_chain_get_member_stun_recovery_time()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_recovery_time(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_TIME;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_RECOVERY_TIME;
	}

	return result;
}

void dc_chain_set_member_stun_recovery_time(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_recovery_time(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_TIME;

	if (value == DC_CHAIN_DEFAULT_STUN_RECOVERY_TIME)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Time unit to recover stun (see check stun function).
*/

int dc_chain_get_member_stun_recovery_last()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_recovery_last(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_LAST;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_RECOVERY_LAST;
	}

	return result;
}

void dc_chain_set_member_recovery_last(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_recovery_last(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_LAST;

	if (value == DC_CHAIN_DEFAULT_STUN_RECOVERY_LAST)
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
	void acting_entity = dc_chain_get_member_entity();

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
	void acting_entity = dc_chain_get_member_entity();

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
* Return true if entity is over its
* stun threshold.
*/
int dc_chain_check_stun()
{
	void acting_entity = dc_chain_get_member_entity();

	int stun_current = dc_chain_get_member_stun_current();
	int stun_threshold = dc_chain_get_member_stun_threshold();

	/* 
	* If at over over threshold then 
	* acting entity should be stunned.
	*/

	if (stun_current >= stun_threshold)
	{
		return DC_CHAIN_FLAG_TRUE;
	}

	return DC_CHAIN_FLAG_FALSE;
}

/*
* Caskey, Damon V.
* 2021-04-10
*
* Accept integer value and apply to
* current stun.
*/
void dc_chain_adjust_stun(int value)
{
	int stun_current = dc_chain_get_member_stun_current();
	int stun_new = stun_current + value;

	dc_chain_set_member_stun_current(stun_new);
}

/*
* Caskey, Damon V.
* 2021-04-10
* 
* Decrements current stun based on passage of time
* and deduct amount for every X units of time
* between last check.
*/
void dc_chain_stun_recovery()
{
	int stun_current = dc_chain_get_member_stun_current();
	int stun_new = DC_CHAIN_DEFAULT_STUN_CURRENT;
	int stun_recovery_total = 0;
	int stun_recovery_last = dc_chain_get_member_stun_recovery_last();
	int stun_recovery_time = dc_chain_get_member_stun_recovery_time();
	int stun_recovery_rate = dc_chain_get_member_stun_recovery_rate();
	int elapsed_time = openborvariant("elapsed_time");
	int time_difference = 0;
	int time_units = 0;

	/*
	* If we run this function whenever we use 
	* the stun value, we can simulate recovery 
	* over time without relying on a repeating 
	* event script (example: update.c).
	* 
	* To do this we get the time we last checked
	* and subtract it from elapsed time. Then
	* we divide the difference by recovery time.
	* That tells us how often the entity would
	* recover stun since we last checked.
	* 
	* We then multiply the number of recoveries
	* by recovery amount. Now we have the total
	* amount of stun the entity would recover.
	* 
	* If last check time is greater than elapsed
	* time, we assume the entity is copied into a 
	* new stage or there's some other anomaly in 
	* play and apply the default new stun value.
	*/
	
	time_difference = elapsed_time - stun_recovery_last;

	if (time_difference > 0)
	{		
		/* 
		* Find number of recovery occurrences since
		* last check, rounding and truncating any 
		* decimal value.
		*/

		time_units = time_difference / stun_recovery_time;
		time_units = round(time_units);
		time_units = trunc(time_units);

		/*
		* Use total recovery to get a final new stun
		* value for entity.
		*/

		stun_recovery_total = time_units * stun_recovery_rate;
		stun_new = stun_current - stun_recovery_total;
	}
	
	/* 
	* Apply new stun value and record check time 
	* for next use.
	*/
	
	dc_chain_set_member_stun_current(stun_new);
	dc_chain_set_member_recovery_last(elapsed_time);
}