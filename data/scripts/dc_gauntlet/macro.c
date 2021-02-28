#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/functions.c"
#import "data/scripts/dc_gauntlet/autokill.c"
#import "data/scripts/dc_gauntlet/entity.c"

/*
* Caskey, Damon V.
* 2021-02-08
* 
* Check to see if there is already an entity 
* bound to acting entity with same model name 
* as requested spawn name.
* 
* If there there is no existing bound entity, 
* spawn a new entity and return the pointer. 
* Otherwise do nothing.
* 
* This function is useful for looping animations 
* with overlays to avoid creating more and more 
* unwanted copies of an already existing overlay 
* entity.
*/
void dc_gauntlet_quick_spawn_unique_sub_entity(char model_name)
{
	int i = 0;
	int entity_count = openborvariant("count_entities");
	void search_entity = NULL();
	void bind = NULL();
	void bind_target = NULL();

	void ent = dc_gauntlet_get_member_entity();

	for (i = 0; i < entity_count; i++)
	{		
		search_entity = getentity(i);
			
		bind = get_entity_property(search_entity, "bind");
		bind_target = get_bind_property(bind, "target");

		if (bind_target == ent)
		{
			if (getentityproperty(search_entity, "defaultname") == model_name)
			{
				return;
			}
		}		
	}
	
	void spawn = dc_gauntlet_quick_spawn(model_name);

	return spawn;
}

/* Caskey, Damon V.
* 2019-04-23
*
* Just a one step way to run spawn functions when we
* all we need is a quick spawn.
*/
void dc_gauntlet_quick_spawn(char model_name)
{
	void spawned_entity = NULL();

	/* Clear the spawn entry, spawn in new entity, and clear again. */
	dc_gauntlet_clear_spawn_entry();

	dc_gauntlet_set_spawn_entry("name", model_name);

	spawned_entity = dc_gauntlet_spawn();

	/*
	* Failed spawns are not fatal on their own, so it may seem
	* unfriendly to force a shutdown here. However, it's just
	* about guaranteed some downstream function will try to use
	* the now non-existent spawn pointer. When it does, OpenBOR
	* will throw a NULL pointer error and we’re going to have a
	* very difficult time finding the root cause. The spawn fail
	* is most likely due to a model name typo somewhere, and
	* that’s MUCH easier to track down.
	*/
	if (!spawned_entity)
	{
		shutdown(1, "\n dc_gauntlet_quick_spawn(): Spawn attempt failed or returned NULL pointer. \n\t Parameters: " + model_name + "\n\n");
	}

	dc_gauntlet_clear_spawn_entry();

	/* Now apply properties that are not part of spawn system. */
	set_entity_property(spawned_entity, "autokill", dc_gauntlet_get_member_autokill());
	
	return spawned_entity;
}

/* 
* Caskey, Damon V.
* 2019-04-23
*
* Spawn entity with default values needed for a 
* typical hit spark (flash) or burst effect.
*/
void dc_gauntlet_quick_flash(char model_name)
{
	void spawned_entity;

	/* 
	* Clear the spawn entry, spawn in new 
	* entity, and clear again. 
	*/

	dc_gauntlet_clear_spawn_entry();

	dc_gauntlet_set_spawn_entry("name", model_name);

	spawned_entity = dc_gauntlet_spawn();

	/*
	* Failed spawns are not fatal on their own, so it may seem
	* unfriendly to force a shutdown here. However, it's just
	* about guaranteed some downstream function will try to use
	* the now non-existent spawn pointer. When it does, OpenBOR
	* will throw a NULL pointer error and we’re going to have a
	* very difficult time finding the root cause. The spawn fail
	* is most likely due to a model name typo somewhere, and
	* that’s MUCH easier to track down.
	*/
	if (!spawned_entity)
	{
		shutdown(1, "\n dc_gauntlet_quick_flash(): Spawn attempt failed or returned NULL pointer. \n\t Parameters: " + model_name + "\n\n");
	}

	dc_gauntlet_clear_spawn_entry();

	/* Now apply default properties for a flash. */
	set_entity_property(spawned_entity, "autokill", openborconstant("AUTOKILL_ANIMATION_COMPLETE"));
	set_entity_property(spawned_entity, "spawn_type", openborconstant("SPAWN_TYPE_FLASH"));

	return spawned_entity;
}