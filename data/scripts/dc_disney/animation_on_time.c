#include "data/scripts/dc_disney/config.h"
#import "data/scripts/dc_disney/animation.c"

/*
* Animation on time is an animation we can set to
* run after a predetermined delay. Uses the dc_eggball
* library to control timing.
*/

// Returns current interval or default if not set.
int dc_disney_get_member_time_delay()
{

	char id;
	int result;

	// Get id.
	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TIME_DELAY;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_DISNEY_DEFAULT_TIME_DELAY;
	}

	return result;
}

void dc_disney_set_member_time_delay(int value)
{

	char id;

	id = dc_disney_get_instance() + DC_DISNEY_MEMBER_TIME_DELAY;

	if (value == DC_DISNEY_DEFAULT_TIME_DELAY)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Reset delay timer for animation on time.
*/
void dc_disney_reset_animation_on_time()
{
	char id;

	/* Send our current instance. */
	dc_eggball_set_instance(dc_disney_get_instance());

	/* 
	* First set the delay time, then reset
	* the timing counter.
	*/
	dc_eggball_set_member_interval(dc_disney_get_member_time_delay());
	dc_eggball_reset_interval();
}

/*
* Caskey, Damon V,
* 2021-04-06 (import from runanimal ~2010)
* 
* Play animation after designated time expires.
*/
void dc_disney_animation_on_time() {

	int animation_id = dc_disney_get_member_animation_pass_id();
	
	/*
	* If time expires, set animation.
	*/
	if (dc_eggball_check_interval())
	{
		dc_disney_play_animation(animation_id);
	}	
}