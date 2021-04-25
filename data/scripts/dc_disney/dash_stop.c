#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"

// Caskey, Damon V.
// 2018-11-03
// 
// Stop running - used to create dash effect.
void dc_disney_dash_stop()
{
	void ent;

	// Get base entity.
	ent = dc_disney_get_member_entity();

	/*
	* Turn off run state and stop all movement.
	*/
	set_entity_property(ent, "run_state", 0);

	set_entity_property(ent, "velocity_x", 0.0);
	set_entity_property(ent, "velocity_y", 0.0);
	set_entity_property(ent, "velocity_z", 0.0);

	/* Third parameter is resettable flag. */
	executeanimation(ent, openborconstant("ANI_IDLE"), 1);
}