#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"

// Caskey, Damon V.
// 2016-09-13
//
// Verify animation and entity, then switch
// entity to new animation.
int dc_disney_play_animation(int animation)
{
	void ent;
	int is_valid;
	int vartype;
	int result = 0;

	// Get base entity.
	ent = dc_disney_get_member_entity();

	// Get animation valid "entity_status".
	is_valid = getentityproperty(ent, "animvalid", animation);

	// Animation is valid?
	if (is_valid == 1)
	{
		// Switch to animation.
		changeentityproperty(ent, "animation", animation);
		result = 1;
	}

	return result;
}