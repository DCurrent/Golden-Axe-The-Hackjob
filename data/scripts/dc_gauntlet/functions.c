#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/autokill.c"
#import "data/scripts/dc_gauntlet/entity.c"

void dc_gauntlet_set_spawn_entry(char property, void value)
{	
	setspawnentry(property, value);
}

void dc_gauntlet_clear_spawn_entry()
{
	clearspawnentry();
}

/*
* Caskey, Damon V.
* 
* Wrapper for native spawn function. Runs the native
* spawn(), and records pointer of newly spawned
* entity into member variable.
*/
void dc_gauntlet_spawn()
{
	void spawned_entity = spawn();

	/* Store the spawn as a local var. */
	dc_gauntlet_set_member_spawn(spawned_entity);

	return spawned_entity;
}



