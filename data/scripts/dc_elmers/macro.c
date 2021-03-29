#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/bind.c"
#import "data/scripts/dc_elmers/direction.c"
#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/palette.c"
#import "data/scripts/dc_elmers/position.c"

/* 
* These compound functions allow you to use a single function 
* call to set up and run dc_elmers with pre-configured options 
* that will handle the most common module building needs.
*/

/* 
* Caskey, Damon V.
* 2020-08-13
*
* Destory the bound entity.
*/
void dc_elmers_quick_destroy()
{
	void ent = dc_elmers_get_member_entity(ent);

	killentity(ent);
}

/* 
* Caskey, Damon V.
* 2019-05-02
*
* Bind to target's exact location and direction
* with exact animation matching, sorted to appear in front
* of target. Do not match target colors.
*
* - Basic particle effects
* - Blade motion trails
* - Auras
*/
void dc_elmers_quick_particle(void ent)
{	
	void target = NULL();
	void bind = NULL();

	/*
	* Reset the instance so we can avoid conflicts.
	*/
	dc_elmers_reset_instance();

	/* Seems redeundant, but gets default if ent is blank. */
	dc_elmers_set_member_entity(ent);	
	ent = dc_elmers_get_member_entity(ent);		
	
	target = dc_elmers_get_member_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

	dc_elmers_alter_bind_direction(openborconstant("DIRECTION_ADJUST_SAME"));
	
	/* Default sort to front. */
	dc_elmers_set_bind_sorting(DC_ELMERS_SORT_FRONT);
		
	/* Default bind to animation + frame and remove on no match. */
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_TARGET")+openborconstant("BIND_ANIMATION_REMOVE")+openborconstant("BIND_ANIMATION_FRAME_TARGET")+openborconstant("BIND_ANIMATION_FRAME_REMOVE"));

	dc_elmers_quick_offset_to_bind();
	dc_elmers_apply_palette_match();

	return bind;
}

/* 
* Caskey, Damon V.
* 2019-05-02
*
* Bind to target's exact location and direction
* with exact animation matching, but not frame,
* sorted to appear in front of target. Do not
* match target colors.
*
* - Basic particle effects
* - Blade motion trails
* - Auras
*/
void dc_elmers_quick_particle_free(void ent)
{
	void target = NULL();
	void bind = NULL();

	/*
	* Reset the instance so we can avoid conflicts.
	*/
	dc_elmers_reset_instance();

	/* Seems redeundant, but gets default if ent is blank. */
	dc_elmers_set_member_entity(ent);
	ent = dc_elmers_get_member_entity(ent);

	target = dc_elmers_get_member_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

	dc_elmers_alter_bind_direction(openborconstant("DIRECTION_ADJUST_SAME"));

	/* Default sort to front. */
	dc_elmers_set_bind_sorting(DC_ELMERS_SORT_FRONT);

	/* Default bind to animation and remove on no match. */
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_TARGET") + openborconstant("BIND_ANIMATION_REMOVE"));

	dc_elmers_quick_offset_to_bind();
	dc_elmers_apply_palette_match();

	return bind;
}



/* Caskey, Damon V.
* 2019-10-15
*
* Bind to target, also using target's color table. Use this when we
* need parts of our own body broken into layers or effects like the
* blurred leg motion of Terry's Crack Shot, where the blur needs to
* match the animation, position, and colors of main body.
*
* - Layered body parts
* - Matched motions (Terry Bogard's Crack Shot).
*/
void dc_elmers_quick_overlay(void ent, int layer_adjustment)
{
	void target = NULL();
	void bind = NULL();
	
	/*
	* Reset the instance so we can avoid conflicts.
	*/
	dc_elmers_reset_instance();

	/* Seems redeundant, but gets default if ent is blank. */
	dc_elmers_set_member_entity(ent);
	ent = dc_elmers_get_member_entity(ent);

	target = dc_elmers_get_member_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	set_bind_property(bind, "mode_x", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_y", openborconstant("BIND_MODE_TARGET"));
	set_bind_property(bind, "mode_z", openborconstant("BIND_MODE_TARGET"));

	dc_elmers_alter_bind_direction(openborconstant("DIRECTION_ADJUST_SAME"));
	
	/* Set sorting order. */
	dc_elmers_set_bind_sorting(layer_adjustment);

	/* Default bind to animation + frame and remove on no match. */
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_TARGET") + openborconstant("BIND_ANIMATION_REMOVE") + openborconstant("BIND_ANIMATION_FRAME_TARGET") + openborconstant("BIND_ANIMATION_FRAME_REMOVE"));

	dc_elmers_quick_offset_to_bind();
	
	/* Match to target's table. */
	dc_elmers_set_palette_match(DC_ELMERS_PALETTE_MATCH_TABLE);	
	dc_elmers_apply_palette_match();

	return bind;
}


/* Caskey, Damon V.
* 2019-07-23
*
* Move to self location (with offset), but no binding. 
*
* - Smoke bombs.
* - Staionary overlays.
*/
void dc_elmers_quick_spot(void ent, int layer_adjustment)
{
	void target = NULL();
	void bind = NULL();
	int sort_id = 0;

	/* Seems redeundant, but gets default if ent is blank. */
	dc_elmers_set_member_entity(ent);
	ent = dc_elmers_get_member_entity(ent);	

	target = dc_elmers_get_member_target();		

	sort_id = dc_elmers_find_front_sort() + layer_adjustment;
	set_entity_property(ent, "sort_id", sort_id);

	dc_elmers_apply_position();
	dc_elmers_apply_direction();

	dc_elmers_free_instance();
}

/* 
* Caskey, Damon V.
* 2018-08-27
*
* Find frontmost sort id from target and any 
* entities that are bound to it.
*/
int dc_elmers_find_front_sort()
{
	void target = NULL();
	int i = 0;						// Loop cursor.
	int entity_count = 0;			// Entites on screen.
	int entity_exists = 0;			// Entity cursor is not a dangling pointer.
	void entity_cursor = NULL();	// Entity in loop.
	void bind = NULL();				// Binding property.
	void bind_target = NULL();		 
	
	int sort_cursor = 0;
	int sort_result = 0;

	target = dc_elmers_get_member_target();
	
	entity_count = openborvariant("count_entities");
	sort_result = get_entity_property(target, "sort_id");

	/* Loop through entity collection. */
	for (i = 0; i < entity_count; i++)
	{
		/* Get entity cursor for this loop increment. */
		entity_cursor = getentity(i);

		/* Make sure we got a valid target pointer. */
		if (!entity_cursor)
		{
			continue;
		}

		/* 
		* Make sure the entity exists in play. We perform this
		* check because it's possible for an entity to be
		* removed but its pointer is still valid.
		*/
		entity_exists = getentityproperty(entity_cursor, "exists");

		if (!entity_exists)
		{
			continue;
		}

		/* Bound to target? */
		bind = get_entity_property(entity_cursor, "bind");
		bind_target = get_bind_property(bind, "target");

		if (bind_target != target)
		{
			continue;
		}

		/* 
		* Get sorting of bound entity. If the sort ID is greater
		* than old value, update the old value with current.
		*/
		sort_cursor = get_entity_property(entity_cursor, "sort_id");

		if (sort_cursor > sort_result)
		{
			sort_result = sort_cursor;
		}
	}

	/* Add one to final sort and return. */
	return sort_result + 1;
}

