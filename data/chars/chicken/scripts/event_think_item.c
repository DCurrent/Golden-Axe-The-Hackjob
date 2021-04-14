#include "data/scripts/dc_eggball/main.c"

void main()
{
	runcheck();
}

/*
* Cause ridable animals to start running behavior
* after a given amount of time, or if a global run
* flag is set.
*/
void runcheck() {

	void acting_entity = getlocalvar("self");
	float position_z = get_entity_property(acting_entity, "position_z");

	// settextobj(1, 10, 60, 1, 999999994, "pos_z: " + position_z);
	// settextobj(2, 10, 70, 1, 999999994, dc_eggball_get_member_next());

	/* In playable area? */
	if (position_z < 1000 && position_z > 0)
	{
		/*
		* Initialize lifespan from localvar. If there's
		* no value, initialize an integer 0.
		*/

		if (dc_eggball_get_member_interval() == DC_EGGBALL_DEFAULT_INTERVAL)
		{
			dc_eggball_set_member_interval(dc_eggball_seconds_to_time(15));
		}

		/*
		* If the run animal flag is enabled, then
		* we move our timer right up to the expire
		* value. The very next time function runs,
		* time will expire, and trigger run away.
		*
		* This is used for bonus levels where creature
		* is momentarily at camp but takes off when
		* the thieves show up.
		*/
		if (getglobalvar("runanimal"))
		{
			dc_eggball_set_member_interval(dc_eggball_seconds_to_time(1));
			setglobalvar("runanimal", NULL());
		}

		/*
		* If lifespaen expires, set walk. The walk animation
		* is the runaway and handles things from here.
		*/
		if (dc_eggball_check_interval())
		{
			executeanimation(acting_entity, openborconstant("ANI_WALK"), 0);
		}
	}
	else
	{
		dc_eggball_set_member_interval(dc_eggball_seconds_to_time(15));
		dc_eggball_reset_interval();
	}
}