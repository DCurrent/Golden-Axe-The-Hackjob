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

int dc_chain_get_member_stun_recovery_delay()
{
	char id = "";
	void result = 0;
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_get_member_stun_recovery_delay(): No acting entity pointer. \n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_DELAY;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_RECOVERY_DELAY;
	}

	return result;
}

void dc_chain_set_member_stun_recovery_delay(void value)
{
	char id = "";
	void acting_entity = dc_chain_get_member_entity();

	/*
	* Catch missing entity before the engine does!
	*/
	if (!acting_entity)
	{
		shutdown(1, "\n dc_chain_set_member_stun_recovery_delay(): No acting entity pointer. \n\t Parameters: " + value + "\n\n");
	}

	// Get id.
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_RECOVERY_DELAY;

	if (value == DC_CHAIN_DEFAULT_STUN_RECOVERY_DELAY)
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
* Animation when initially stunned.
*/

int dc_chain_get_member_stun_animation_initial()
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
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_ANIMATION_INITIAL;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_ANIMATION_INITIAL;
	}

	return result;
}

void dc_chain_set_member_stun_animation_initial(void value)
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
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_ANIMATION_INITIAL;

	if (value == DC_CHAIN_DEFAULT_STUN_ANIMATION_INITIAL)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Animation when stunned and hit with 
* non-knockdown attack.
*/

int dc_chain_get_member_stun_animation_pain()
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
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_ANIMATION_PAIN;

	result = getentityvar(acting_entity, id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_CHAIN_DEFAULT_STUN_ANIMATION_PAIN;
	}

	return result;
}

void dc_chain_set_member_stun_animation_pain(void value)
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
	id = dc_chain_get_instance() + DC_CHAIN_MEMBER_STUN_ANIMATION_PAIN;

	if (value == DC_CHAIN_DEFAULT_STUN_ANIMATION_PAIN)
	{
		value = NULL();
	}

	setentityvar(acting_entity, id, value);
}

/*
* Caskey, Damon V.
* 2021-04-13
*
* Simulates the additional combo or finish
* attacks found in games like Double Dragon
* and Golden Axe. When opponent is in range
* and stunned we do a series (or single)
* finishing attack.
*/
void dc_chain_try_stun_series_simple(int stun_pain_alt, int repeat_max, int stun_pain_finish)
{
	void acting_entity = dc_chain_get_member_entity();

	int counter = getlocalvar("dc_chain_counter" + stun_pain_alt);

	if (!counter)
	{
		counter = 0;
	}

	if (dc_chain_check_target_in_stun_animation(stun_pain_alt))
	{
		if (counter < repeat_max)
		{
			executeanimation(acting_entity, stun_pain_alt, 1);
			counter++;
		}
		else
		{
			executeanimation(acting_entity, stun_pain_finish, 1);
			counter = 0;
		}
	}

	setlocalvar("dc_chain_counter" + stun_pain_alt, counter);
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

	//settextobj(0, 10, 60, 1, 999999994, "stun_current: " + stun_current);
	//settextobj(1, 10, 70, 1, 999999994, "stun_threshold: " + stun_threshold);

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
* 2021-04-11
* 
* Assume stun animation if over threshold.
*
* If already in stun animation, play the
* stun pain instead.
* 
* Note this function needs to run in
* the onpain event or as a @cmd in a
* non-stun pain animation. The takedamage 
* won't work because it occurs before 
* OpenBOR applies pain animations.
*/
int dc_chain_try_stun_animation()
{
	void acting_entity = dc_chain_get_member_entity();
	int animation_old = get_entity_property(acting_entity, "animation_id");
	int animation_new = 0;
	int stun_initial = 0;  
	int stun_pain = dc_chain_get_member_stun_animation_pain();
			
	/*
	* Have we accured enough stun to
	* be in the stunned status?
	*/

	int is_stunned = dc_chain_check_stun();

	if (!is_stunned)
	{
		return DC_CHAIN_ANIMATION_NONE;
	}

	/*
	* We may already be in a stunned animation.
	* If so we go into stun pain and exit.
	* 
	* Otherwise we put ourselves into the
	* initial stunned animation.
	*/

	int in_stun_animation = dc_chain_check_in_stun_animation(acting_entity);

	if (in_stun_animation)
	{
		animation_new = dc_chain_get_member_stun_animation_pain();

		executeanimation(acting_entity, animation_new, 1);
		set_entity_property(acting_entity, "animation_id_previous", animation_old);
		set_entity_property(acting_entity, "in_pain", 1);

		// settextobj(4, 10, 70, 1, openborconstant("FRONTPANEL_Z") + 10000, "animation_new: " + animation_new);

		return animation_new;
	}
	else
	{
		animation_new = dc_chain_get_member_stun_animation_initial();

		executeanimation(acting_entity, animation_new, 1);
		set_entity_property(acting_entity, "animation_id_previous", animation_old);
		set_entity_property(acting_entity, "in_pain", 1);

		return animation_new;
	}	
}

/*
* Caskey, Damon V.
* 2021-04-13
* 
* Accept an animation ID and return true
* if a target in range is play one of
* its stun animations.
*/
int dc_chain_check_target_in_stun_animation(int acting_animation)
{
	void acting_entity = dc_chain_get_member_entity();
	void target_entity = NULL();
	int target_animation = 0;

	/*
	* Find target entity in acting animation range.
	* If we don't have a target, just return false.
	*/

	target_entity = findtarget(acting_entity, acting_animation);

	if (!target_entity)
	{
		return DC_CHAIN_FLAG_FALSE;
	}

	/* 
	* Send target to our stun animation check
	* function and return its result.
	*/

	return dc_chain_check_in_stun_animation(target_entity);
}

/*
* Caskey, Damon V.
* 2021-04-11
*
* Return TRUE if an opponent is grabbing
* active entity.
*/
int dc_chain_check_grabbed(void acting_entity)
{
	if (!acting_entity)
	{
		acting_entity = dc_chain_get_member_entity();
	}

	void opponent = get_entity_property(acting_entity, "opponent");

	// settextobj(2, 10, 40, 1, openborconstant("FRONTPANEL_Z") + 10000, "opponent: " + opponent);

	if (!opponent)
	{
		return 0;
	}
	
	/* 
	* Get the our link property. It should be same
	* as our opponent.
	*/

	void link_grabbed = get_entity_property(acting_entity, "link");

	// settextobj(4, 10, 60, 1, openborconstant("FRONTPANEL_Z") + 10000, "link_grabbed: " + link_grabbed);

	if (opponent != link_grabbed)
	{
		return 0;
	}

	return 1;
}

/*
* Caskey, Damon V.
* 2021-04-11
* 
* Return TRUE if currently playing a designated
* stun animation.
*/
int dc_chain_check_in_stun_animation(void acting_entity)
{	
	int stun_initial = dc_chain_get_member_stun_animation_initial();
	int stun_pain = dc_chain_get_member_stun_animation_pain();
	int animation_current = 0;
	int animation_previous = 0;
	int in_pain = 0;

	if (!acting_entity)
	{
		acting_entity = dc_chain_get_member_entity();
	}

	/* If not currently in pain, return false now. */

	in_pain = get_entity_property(acting_entity, "in_pain");

	if (!in_pain)
	{
		return DC_CHAIN_FLAG_FALSE;
	}
	
	animation_current = get_entity_property(acting_entity, "animation_id");
	animation_previous = get_entity_property(acting_entity, "animation_id_previous");
	
	if (animation_current == stun_initial 
		|| animation_current == stun_pain 
		|| animation_previous == stun_initial
		|| animation_previous == stun_pain)
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
* current stun. In most cases, we'll
* want to run this in takedamage event
* and use damage as the value.
*/
void dc_chain_adjust_stun(int value)
{
	int stun_current = dc_chain_get_member_stun_current();
	int stun_new = stun_current + value;	

	stun_new = stun_new - dc_chain_calculate_stun_recovery();

	//settextobj(0, 10, 60, 1, 999999994, "stun_current: " + stun_current);
	//settextobj(1, 10, 70, 1, 999999994, "stun_new: " + stun_current);

	dc_chain_set_member_stun_current(stun_new);

	/*
	* So recover function knows how long
	* since last recovery.
	*/
	dc_chain_set_member_recovery_last(openborvariant("elapsed_time"));


}

/*
* Caskey, Damon V.
* 2021-04-12
* 
* Set stun values and timers to defaults. 
*/
void dc_chain_reset_stun()
{
	dc_chain_set_member_recovery_last(DC_CHAIN_DEFAULT_STUN_RECOVERY_LAST);
	dc_chain_set_member_stun_current(DC_CHAIN_DEFAULT_STUN_CURRENT);
}

/*
* Caskey, Damon V.
* 2021-04-10
* 
* Gets amount of stun to recover based
* on current stun, recovery delay, recovery
* rate, and passage of time since last
* recovery check.
*/
int dc_chain_calculate_stun_recovery()
{
	int stun_current = dc_chain_get_member_stun_current();
	int result = 0;
	int stun_recovery_last = 0;
	int stun_recovery_delay = 0;
	int stun_recovery_rate = 0;
	int elapsed_time = openborvariant("elapsed_time");
	int time_difference = 0;
	int time_units = 0;
		
	/* Do we have a stun recovery last time? */
	
	stun_recovery_last = dc_chain_get_member_stun_recovery_last();	

	if (stun_recovery_last == DC_CHAIN_DEFAULT_STUN_RECOVERY_LAST)
	{
		return result;
	}

	/* Time difference is valid? */

	time_difference = elapsed_time - stun_recovery_last;

	if (time_difference > 0)
	{
		/*
		* Find number of recovery occurrences that
		* would occur since last check. We do this
		* by calculating difference between current
		* time and last check time. We then divide
		* the difference by recovery delay. This
		* tells us how many recovery "ticks" would
		* take place over the time since last check
		* if we were using a repeat event like update.
		*
		* Once we have number of occurrences, we can
		* multiply by the rate per tick to get total
		* amount of stun recovery.
		*/

		stun_recovery_delay = dc_chain_get_member_stun_recovery_delay();
		stun_recovery_rate = dc_chain_get_member_stun_recovery_rate();

		/* Truncate the result to get integer only. */

		time_units = time_difference / stun_recovery_delay;
		time_units = trunc(time_units);

		result = time_units * stun_recovery_rate;
	}

	/* Cap result to amount of current stun. */
	if (result > stun_current)
	{
		result = stun_current;
	}

	return result;
}