/* 
* Grapple functions serve as more or less a shortcut 
* wrapper for the dc_elmers library, centered around
* quickly setting up grappling moves or other types
* of strictly controlled reactions.
*
* It is important to note that in both OpenBOR's native 
* bind and the dc_elmers library "ent" binds itself to "target". 
* Essentially when doing grappling, we are sending "ent" 
* (the grappled) instructions to bind itself to a designated 
* "target" (the grappler) and assume whatever poses we need.
*
* The whole point of having a grapple subset is to avoid some 
* of this possible confusion. To do so, the grapple subset refers
* to the grappled entity (ent) as "controlled", and the grappler
* entity (target) as "controller". But under the hood, the 
* grapple subset is still using the main dc_elmers library 
* and functions and its ent/target member variables. So if you 
* choose to employ the grapple subset along with other functions 
* in or outside of the dc_elmers library, you must never assume 
* "target" means "the target of my grapple move". Otherwise 
* you'll get erroneous (albeit potentially hilarious) results.
*/

#include	"data/scripts/dc_elmers/config.h"
#import		"data/scripts/dc_elmers/attacking.c"
#import		"data/scripts/dc_elmers/bind.c"
#import		"data/scripts/dc_elmers/blast.c"
#import		"data/scripts/dc_elmers/candamage.c"
#import		"data/scripts/dc_elmers/direction.c"
#import		"data/scripts/dc_elmers/disabled.c"
#import		"data/scripts/dc_elmers/entity.c"
#import		"data/scripts/dc_elmers/offset.c"
#import		"data/scripts/dc_elmers/position_config.c"
#import		"data/scripts/dc_elmers/size.c"
#import		"data/scripts/dc_elmers/tag.c"

/* Caskey, Damon V.
* 2019-10-15
* 
* Light grapple. Grappler (target) holds and poses the
* grapple target (ent), but there is no breaking of
* native link or knockdown. Use this when we want to
* enhance native grabbatack moves with binding
* or perform other holds where the grapple target
* shouldn't be in an outright slammed state.
*
* - Populate target (grappler), and entity (grappled).
* - Place entity in reaction animation ready for
* posing by frame.
*/
void dc_elmers_initialize_grapple_hold()
{
	void target = NULL();
	void ent = NULL();

	/* 
	* Reset this instance of elmers so we don't have any
	* possible conflicts from previous uses.
	*/
	dc_elmers_reset_instance();

	/* 
	* Get target, and then get target's opponent. We set that
	* the entity we are acting on. As in, the one binding itself
	* to the grapple controller (target).
	*/
	target = dc_elmers_get_member_target();
	ent = get_entity_property(target, "opponent");

	dc_elmers_set_member_entity(ent);

	/* 
	* Apply desired blast effect.
	*/
	dc_elmers_set_member_blast(openborconstant("BLAST_NONE"));
	dc_elmers_apply_blast();

	/* 
	* Set binding to match a manually defined animation ID and
	* animation frame. Then set the manual animation ID property
	* to our default reaction animation. Later we set the frame
	* property to apply whatever specific pose we want.
	*/
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_DEFINED") + openborconstant("BIND_ANIMATION_FRAME_DEFINED"));
	dc_elmers_set_bind_animation_id(DC_ELMERS_REACT_ANIMATION);

	/* 
	* Disable can damage property so we can't hit
	* the grapple controller. We need to restore it
	* when finished, and possibly with another script
	* event, so we'll record the old value into bind
	* tag property first.
	*/
	dc_elmers_set_member_tag(getentityproperty(ent, "candamage"));
	dc_elmers_apply_tag();
	dc_elmers_set_member_can_damage(DC_ELMERS_CAN_DAMAGE_NONE);
	dc_elmers_apply_can_damage();
}

/* 
* Caskey, Damon V.
* 2019-05-13
*
* Shortcut to set up default grappling.
*
* - Populate target (grappler), and entity (grappled).
* - Place entity in default blast state so its attack
* box can hit others and not hit target.
* - Disable the native grappling system so it won't
* interfere with sorting or certain bind poses, and
* lets engine know its own job is done.
* - Place entity in reaction animation ready for
* posing by frame.
*/
void dc_elmers_initialize_grapple()
{	
	void target = NULL();
	void ent = NULL();
	
	/* 
	* Reset this instance of elmers so we don't have any
	* possible conflicts from previous uses.
	*/
	dc_elmers_reset_instance();

	/* 
	* Get target, and then get target's opponent. We set that
	* the entity we are acting on. As in, the one binding itself
	* to the grapple controller (target).
	*/
	target = dc_elmers_get_member_target();		
	ent = get_entity_property(target, "opponent");

	dc_elmers_set_member_entity(ent);
	
	/* Put us into a thrown state. */
	dc_elmers_apply_blast();

	/* 
	* Break openbor native grab system link if it exists. If we 
	* don't do this, the native grab system overrides binding 
	* sort ID.
	*/ 
	dc_elmers_end_native_link();

	/* 
	* Set binding to match a manually defined animation ID and
	* animation frame. Then set the manual animation ID property
	* to our default reaction animation. Later we set the frame
	* property to apply whatever specific pose we want.
	*/
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_DEFINED") + openborconstant("BIND_ANIMATION_FRAME_DEFINED"));
	dc_elmers_set_bind_animation_id(DC_ELMERS_REACT_ANIMATION);

	// Disable can damage property so we can't hit
	// the grapple controller. We need to restore it
	// when finished, and possibly with another script
	// event, so we'll record the old value into bind
	// tag property first.
	dc_elmers_set_member_tag(getentityproperty(ent, "candamage"));
	dc_elmers_apply_tag();
	dc_elmers_set_member_can_damage(DC_ELMERS_CAN_DAMAGE_NONE);
	dc_elmers_apply_can_damage();
}

/* 
* Caskey, Damon V.
* 2019-06-15
*
* Bind grappler to grappled - this is for moves 
* where the grappler needs to position itself
* around the grappler. Like the start of a swing
* DDT move, vaulting over the grappled's head
* Steets of Rage style, and so on...
*/
void dc_elmers_initialize_reverse_grapple()
{
	void target = NULL();
	void ent = NULL();

	/* 
	* Reset this instance of elmers so we don't have any
	* possible conflicts from previous uses.
	*/
	dc_elmers_reset_instance();

	/* 
	* Get target, and then get target's opponent. We set that
	* the entity we are acting on. As in, the one binding itself
	* to the grapple controller (target).
	*/
	target = dc_elmers_get_member_target();
	ent = get_entity_property(target, "opponent");

	dc_elmers_set_member_entity(ent);

	/* Put us into a thrown state.
		// dc_elmers_apply_blast();
	/*

	/* 
	* Break openbor native grab system link if it exists. If we 
	* don't do this, the native grab system overrides binding 
	* sort ID.
	*/
	dc_elmers_end_native_link();

	/* 
	* Set binding to match a manually defined animation ID and
	* animation frame. Then set the manual animation ID property
	* to our default reaction animation. Later we set the frame
	* property to apply whatever specific pose we want.
	*/
	dc_elmers_set_animation_match(openborconstant("BIND_ANIMATION_DEFINED") + openborconstant("BIND_ANIMATION_FRAME_DEFINED"));
	dc_elmers_set_bind_animation_id(DC_ELMERS_REACT_ANIMATION);

	/* 
	* Disable can damage property so we can't hit
	* the grapple controller. We need to restore it
	* when finished, and possibly with another script
	* event, so we'll record the old value into bind
	* tag property first.
	*/
	dc_elmers_set_member_tag(getentityproperty(ent, "candamage"));
	dc_elmers_apply_tag();
	dc_elmers_set_member_can_damage(DC_ELMERS_CAN_DAMAGE_NONE);
	dc_elmers_apply_can_damage();

	/* Bind self to current location. */
	dc_elmers_set_member_anchor_x(openborconstant("BIND_MODE_LEVEL"));
	dc_elmers_set_member_anchor_y(openborconstant("BIND_MODE_LEVEL"));
	dc_elmers_set_member_anchor_z(openborconstant("BIND_MODE_LEVEL"));

	int x;
	int y;
	int z;

	/* 
	* Bind offset only accepts decimals, but we need
	* integers for the offset members.Round and then
	* truncate the position values first.
	*/

	x = trunc(round(get_entity_property(ent, "position_x")));
	y = trunc(round(get_entity_property(ent, "position_y")));
	z = trunc(round(get_entity_property(ent, "position_z")));

	dc_elmers_set_member_invert_x(DC_ELMERS_INVERT_DISABLED);

	dc_elmers_set_member_offset_x(x);
	dc_elmers_set_member_offset_y(y);
	dc_elmers_set_member_offset_z(z);
}

/* 
* Caskey, Damon V.
* 2019-05-28
*
* Executes the current grapple/bind settings.
*/
void dc_elmers_apply_grapple()
{	
	if (dc_elmers_get_member_disabled() != DC_ELMERS_DISABLED_TRUE)
	{
		dc_elmers_apply_blast();
		dc_elmers_apply_can_damage();

		// Apply bind settings.
		dc_elmers_quick_bind();
	}	
}

/* 
* Caskey, Damon V.
* 2019-05-28
*
* Release grappled entity and restore relevant
* properties. Return the entity pointer so
* other libraries (like damage) can do their work.
*/
void dc_elmers_end_grapple()
{
	void ent = dc_elmers_get_member_entity();

	if (dc_elmers_get_member_disabled() != DC_ELMERS_DISABLED_TRUE)
	{
		/* 
		* Restore our previous candamage property
		* before the grapple started.
		*/
		dc_elmers_apply_can_damage_old();

		/* Makes final position adjustment and ends bind. */
		dc_elmers_quick_release();

		/*
		* Restore the candamage value we stored 
		* in bind tag.
		*/
		dc_elmers_set_member_can_damage(dc_elmers_set_member_tag_from_property());
		dc_elmers_apply_can_damage();
	}	

	/* 
	* Reset the instance. This is both to
	* save memory and ensure we
	* don't have conflicts later.
	*/
	dc_elmers_reset_instance();

	/* Return our entity pointer. */
	return ent;
}

/* 
* Caskey, Damon V.
* 
* Release grappled entity and disable grappling system IF
* condition is true. This is useful for unique situations
* where we want to use binding in conjunction with native
* OpenBOR grab attacks, or any sort of hold that damages
* an entity but leaves it standing if the damage isn’t 
* enough to kill.
*
* Use in conjunction with a damage check or whatever else 
* sends a TRUE value when we want to let go. If we didn’t
* release a bound entity when it is killed, the entity would
* not fall away properly.
*
* If we DO release in the middle of an animation, we must 
* also set the disable flag to handle subsequent calls for
* binding in the animation. If we just tried to clear the
* instance instead, default bind values would apply and cause 
* undefined behaviors.
*/
void dc_elmers_conditional_end_grapple(int condition)
{
	void ent = dc_elmers_get_member_entity();

	if (condition && dc_elmers_get_member_disabled() != DC_ELMERS_DISABLED_TRUE)
	{
		/* 
		* Restore our previous candamage property
		* before the grapple started.
		*/
		dc_elmers_apply_can_damage_old();

		/* Makes final position adjustment and ends bind. */
		dc_elmers_quick_release();

		/* 
		* Restore the candamage value we stored 
		* in bind tag.
		*/
		dc_elmers_set_member_can_damage(dc_elmers_set_member_tag_from_property());
		dc_elmers_apply_can_damage();

		/*
		* Set the disabled member to turn off binding.
		*/
		dc_elmers_set_member_disabled(DC_ELMERS_DISABLED_TRUE);
	}

	return ent;
}

/* 
* Caskey, Damon V.
* 2019-05-28
*
* Release grappled entity and restore relevant
* properties. Return the entity pointer so
* other libraries (like damage) can do their work.
*/
void dc_elmers_end_grapple_hold()
{
	void ent = dc_elmers_get_member_entity();

	if (dc_elmers_get_member_disabled() != DC_ELMERS_DISABLED_TRUE)
	{
		/* 
		* Restore our previous candamage property
		* before the grapple started.
		*/
		dc_elmers_apply_can_damage_old();

		/* Makes final position adjustment and ends bind. */
		dc_elmers_quick_release();

		/* 
		* Restore the candamage value we stored 
		* in bind tag.
		*/
		dc_elmers_set_member_can_damage(dc_elmers_set_member_tag_from_property());
		dc_elmers_apply_can_damage();
	}	

	/*
	* Reset the instance. This is both to
	* save memory and ensure we
	* don't have conflicts later.
	*/
	dc_elmers_reset_instance();

	/* Return our entity pointer. */
	return ent;
}

/* 
* Caskey, Damon V.
* 2019-05-31 
* 
* Establish a native grab with following exceptions:
* - No location adjustment. 
* - No direction adjustment.
*/
void dc_elmers_apply_grab()
{
	void ent = NULL();
	void target = NULL();
	int elapsed_time = 0;

	float pos_x = 0.0;
	float pos_z = 0.0;	
	int direction = 0;

	if (dc_elmers_get_member_disabled() != DC_ELMERS_DISABLED_TRUE)
	{
		/* Entity is us. Target is the entity grabbing us. */
		ent = dc_elmers_get_member_entity();
		target = dc_elmers_get_member_target();

		/*
		* We are going to use dograb() below because it
		* takes care of the gazillion flags and actions 
		* needed for starting a native grapple in one 
		* call, and since its running native code can 
		* probably do the work much faster than we could 
		* manage with script. Only problem is it also 
		* relocates us and switches directions, and we 
		* don't want that here.
		*
		* Let's get our position and information now 
		* so we can restore it soon as the dograb() 
		* function is complete.
		*/
		pos_x = get_entity_property(target, "position_x");
		pos_z = get_entity_property(target, "position_z");
		direction = get_entity_property(ent, "position_direction");

		/* 
		* Release bind and knock entity down to ensure
		* it is "reset".
		*/

		void bind = get_entity_property(ent, "bind");
		/*
		void bind_target = get_bind_property(bind, "target");
		*/
		set_bind_property(bind, "target", NULL());

		/* Target grabs us! */
		dograb(target, ent);

		/* Now restore our position and direction. */
		/* 
		set_entity_property(target, "position_x", pos_x);
		set_entity_property(target, "position_z", pos_z); 
		*/
		set_entity_property(ent, "position_direction", direction);

	}
}

/* 
* Caskey, Damon V.
* 2019-05-31
*
* Connect target's native grab to us. Similar to native 
* dograb(), but we're only setting the record keeping, not 
* the alignment, direction, takeaction, etc., that dograb()
* does.
*/
void dc_elmers_apply_native_link()
{
	void target = dc_elmers_get_member_target();
	void ent = dc_elmers_get_member_entity();
	void link = NULL();

	link = get_entity_property(target, "link");

	/* Target grabs us. */
	set_entity_property(target, "grab_target", ent);
	
	/* Link target and us together. */
	set_entity_property(ent, "link", target);
	set_entity_property(target, "link", ent);
}

/* 
* Caskey, Damon V.
* 2019-05-13
*
* Release target's native grab (presumably from holding us). 
* Based on native ent_unlink() function.
*/
void dc_elmers_end_native_link()
{
	void target = dc_elmers_get_member_target();
	void link = NULL();

	link = get_entity_property(target, "link");

	if (link)
	{
		set_entity_property(link, "link", NULL());
		set_entity_property(link, "grab_target", NULL());
	}

	set_entity_property(target, "link", NULL());
	set_entity_property(target, "grab_target", NULL());
}

/* 
* Caskey, Damon V.
* 2018-08-27
*
* Release all of the target entity's grappled
* targets. Call this when the target is damaged
* or gets interrupted some way before it can finish
* a grapple move.
*/
int dc_elmers_disrupt_grapple()
{
	void target = NULL();
	int i = 0;						// Loop cursor.
	int entity_count = 0;			// Entites on screen.
	int entity_exists = 0;			// Entity cursor is not a dangling pointer.
	void entity_cursor = NULL();	// Entity in loop.
	int drop = 0;					// Falling state.
	void bind = NULL();				// Binding property.
	void bind_target = NULL();		// 
	int animation_current = 0;
	int release_count = 0;		// How many entities have been released?
	int candamage = 0;			// Can damage property.

	target = dc_elmers_get_member_target();

	release_count = 0;
	entity_count = openborvariant("count_entities");

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

		/* 
		* In a grappled pose?
		*/
		animation_current = get_entity_property(entity_cursor, "animation_id");

		if (animation_current != DC_ELMERS_REACT_ANIMATION)
		{
			if (animation_current != openborconstant("ANI_GRABBED"))
			{
				continue;
			}
		}

		/* 
		* Bound to target?
		*/
		bind = get_entity_property(entity_cursor, "bind");
		bind_target = get_bind_property(bind, "target");

		if (bind_target != target)
		{
			continue;
		}

		/* 
		* Restore the entity's can damage properties if we messed with them.
		*/
		candamage = get_bind_property(bind, "meta_tag");

		if (typeof(candamage) == openborconstant("VT_INTEGER"))
		{
			changeentityproperty(entity_cursor, "candamage", candamage);
		}		

		/* 
		* Release bind and knock entity down to ensure
		* it is "reset".
		*/
		set_bind_property(bind, "target", NULL());
		damageentity(entity_cursor, target, DC_ELMERS_RESET_ATTACK_FORCE, DC_ELMERS_RESET_ATTACK_DROP, DC_ELMERS_RESET_ATTACK_TYPE);
		

		/* Increment reelase count; */
		release_count++;
	}

	return release_count;
}

/* 
* Caskey, Damon V.
* 2018-11-01
*
* Verify conditions for switching sides and do it 
* if possible. By switching sides, we mean the 
* vaulting mechanic from Streets of Rage series 
* or Final Fight 3.
*/
void dc_elmers_side_switch()
{
	void target = dc_elmers_get_member_target();	

	performattack(target, DC_ELMERS_SWITCH_TO_BACK);

	/* Must have a switch to back. */
	if (!getentityproperty(target, "animvalid", DC_ELMERS_SWITCH_TO_BACK))
	{
		return 0;
	}

	if (get_entity_property(target, "animation_id") == openborconstant("ANI_GRAB"))
	{
		dc_disney_perform_attack(DC_ELMERS_SWITCH_TO_BACK);
	}
	else if (get_entity_property(target, "animation_id") == DC_ELMERS_GRAB_BACK)
	{
		dc_disney_perform_attack(DC_ELMERS_SWITCH_TO_FRONT);
	}	
}