
#import "data/chars/thief/scripts/thief_escape.c"

#include "data/scripts/dc_d20/main.c"  // Random numbers.
#include "data/scripts/dc_fidelity/main.c"  // Sound player.

/*
* Caskey, Damon V.
* 2021-02-28
* 
* Quick and dirty interval sound player. Could
* probably roll this into dc_fidelity library.
*/
void dc_interval_sound(int time_interval, int sound_type, float sound_chance)
{
	int time_expire = getlocalvar("time_expire");
	int time_elapsed = openborvariant("elapsed_time");

	/* Initialize expired time if it's empty. */
	if (!time_expire)
	{
		time_expire = time_elapsed;
	}

	if (time_elapsed >= time_expire)
	{		
		dc_fidelity_set_member_sound_chance(sound_chance);
		dc_fidelity_quick_play(sound_type);
		dc_fidelity_set_member_sound_chance(NULL());


		/* 
		* Set up timer for next call.
		*/

		time_expire = time_elapsed + time_interval;
		setlocalvar("time_expire", time_expire);
	}	
}

/*
* Caskey, Damon V.
* 2021-02-28
* 
* Returns false until timer expires, then random
* chance to return true with cumulatively increasing
* probability.
*/
int dc_timed_chance(int initial_delay, int initial_probability, int maximum_probability, int cumulative_interval, int cumulative_increase)
{
	int time_expire = getlocalvar("time_expire_tc");
	int time_elapsed = openborvariant("elapsed_time");
	int probability = getlocalvar("probability");
	int random = 0;
	/* 
	* Initialize expired time to initial delay 
	* if it's empty, or if initial delay is set
	* to a reset value.
	*/
	if (!time_expire || initial_delay == -1)
	{
		time_expire = time_elapsed + initial_delay;
		setlocalvar("time_expire_tc", time_expire);
	}

	if (!probability || initial_probability == -1)
	{
		probability = initial_probability;
		setlocalvar("probability", probability);
	}
		

	if (time_elapsed >= time_expire)
	{	
		
		dc_d20_set_range_max(100);
		random = probability + dc_d20_random_int();

		
		if (random >= 100)
		{			
			setlocalvar("time_expire_tc", NULL());
			setlocalvar("probability", NULL());
			
			return 1;
		}

		/*
		* Set up cumulative probability for next call.
		*/
		probability += cumulative_increase;

		if (probability > maximum_probability)
		{
			probability = maximum_probability;
		}

		setlocalvar("probability", probability);

		/*
		* Set up timer for next call.
		*/

		time_expire = time_elapsed + cumulative_interval;
		setlocalvar("time_expire_tc", time_expire);
	}
	

	return 0;
}

void main()
{
	/* Occasionally giggle. */
	dc_interval_sound(250, DC_FIDELITY_TYPE_VOICE_LAUGH, 0.5);

	/* 
	* Increasing chance to run away after
	* initial delay.
	*/

	if (dc_timed_chance(1000, 0, 50, 200, 1))
	{
		escape("thief_escape_full");
	}
}
