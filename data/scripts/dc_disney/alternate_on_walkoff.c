#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"
#import "data/scripts/dc_disney/perform_attack.c"

/*
* Caskey, Damon V.
* 2018-11-03
* 
* Switch animation when walking off an edge. 
* The engine's native walkoff doesn't handle
* situations where the entity isn't in a 
* walking state, like using attackup/down as
* a sidestep.
*/
void dc_disney_alternate_on_walkoff(int walkoff_animation)
{
	void acting_entity = dc_disney_get_member_entity();
	float	velocity_y = get_entity_property(acting_entity, "velocity_y");
	int     jump_state = get_entity_property(acting_entity, "jump_state");

	/* 
	* If we aren't falling or in jump state
	* just exit.
	*/
	if (velocity_y >= 0.0 || jump_state)
	{
		return;
	}

	int animation_id = get_entity_property(acting_entity, "animation_id");

	if (animation_id == -1
		|| animation_id == openborconstant("ANI_IDLE")
		|| animation_id == openborconstant("ANI_ATTACKUP")
		|| animation_id == openborconstant("ANI_ATTACKDOWN")
		|| animation_id == openborconstant("ANI_FREESPECIAL2"))
	{		
		executeanimation(acting_entity, walkoff_animation, 0);

		float	velocity_x = get_entity_property(acting_entity, "velocity_z");
		float	velocity_z = get_entity_property(acting_entity, "velocity_z");
		
		if (get_entity_property(acting_entity, "position_direction") == openborconstant("DIRECTION_LEFT"))
		{
			velocity_x = -velocity_x;
		}

		tossentity(acting_entity, 1, velocity_x, velocity_z);
		set_entity_property(acting_entity, "jump_state", 1);
	}	
}