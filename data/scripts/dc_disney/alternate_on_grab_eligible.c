#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"
#import "data/scripts/dc_disney/perform_attack.c"

/*
* Caskey, Damon V.
* 2018-11-03
* 
* Switch animation based on opponent's grab eligibility.
* Used mainly for reversal (counter) throw moves. Note all
* this function does is start the animation. It's up to
* the animation functions to perform the reversal actions.
*/
void dc_disney_alternate_on_grab_eligible(int grab_eligible_animation, int grab_ineligible_animation)
{
	void acting_entity = dc_disney_get_entity();
	void opponent_entity = get_entity_property(acting_entity, "opponent");
	int elapsed_time = openborvariant("elapsed_time");

	/* No opponent? Then exit before we crash. */
	if (!opponent_entity)
	{
		return;
	}

	/* Stop all movement. */

	set_entity_property(acting_entity, "velocity_x", 0.0);
	set_entity_property(acting_entity, "velocity_y", 0.0);
	set_entity_property(acting_entity, "velocity_z", 0.0);

	/*
	* Now let's see if opponent is grab eligible. Any normal
	* fighting entity without the animal or nograb is
	* eligible for a counter throw. We don't worry about
	* the anti grab system since this isn't a "walk and grab".
	*/

	int type = getentityproperty(opponent_entity, "type");
	int opoonent_animation_id = get_entity_property(opponent_entity, "animation_id");

	int opponent_animal = getentityproperty(opponent_entity, "animal");
	int opponent_nograb = get_entity_property(opponent_entity, "nograb");

	if (!opponent_animal
		&& !opponent_nograb
		&& (type == openborconstant("TYPE_PLAYER")
			|| type == openborconstant("TYPE_ENEMY")
			|| type == openborconstant("TYPE_NPC")))
	{
		/* Grab eligible animation. */

		dc_disney_perform_attack(grab_eligible_animation);

	}
	else
	{
		/* Grab ineligible animation. */

		dc_disney_perform_attack(grab_ineligible_animation);
	}
}