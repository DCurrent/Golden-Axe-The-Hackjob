#include "data/scripts/dc_damage/config.h"

#import "data/scripts/dc_damage/direction.c"
#import "data/scripts/dc_damage/lethality.c"
#import "data/scripts/dc_damage/damage_force.c"
#import "data/scripts/dc_damage/damage_land.c"
#import "data/scripts/dc_damage/damage_type.c"
#import "data/scripts/dc_damage/direction.c"
#import "data/scripts/dc_damage/drop.c"
#import "data/scripts/dc_damage/entity.c"
#import "data/scripts/dc_damage/projectile.c"
#import "data/scripts/dc_damage/toss.c"
#import "data/scripts/dc_damage/velocity.c"

/*
* Caskey, Damon V.
* 2018-11-13
*
* Apply damage to entity.
*/
void dc_damage_apply_damage()
{
	void ent;
	void other;

	int force;
	int drop;
	int type;
	int fall;
	int dol_force;
	int projectile;


	/* Get acting entities. */
	ent = dc_damage_get_member_entity();
	other = dc_damage_get_member_other();

	/*
	* Unset target's death status (death = false) so it can receive 
	* damage effects. This won't adversely affect anything, because 
	* assuming hitpoints are at or below 0 after damage applies
	* the engine will immediately set the dead flag to true again.
	*/
	set_entity_property(ent, "dead", 0);                                      

	/*
	* Get attack attributes from member values.	
	*/
	drop = dc_damage_get_member_drop_force();
	type = dc_damage_get_member_attack_type();

	/*
	* If damage is not allowed to KO the entity, then get the
	* amount needed to bring them close as possible (1 hitpoint).
	*/
	if (dc_damage_get_member_lethality() == DC_DAMAGE_LETHALITY_NON_LETHAL)
	{
		force = dc_damage_find_non_lethal_force();
	}
	else
	{
		force = dc_damage_get_member_damage_force();
	}

	/*
	* Runs the native damage function to apply damage. Note the 
	* native damage functionality function handles offense and 
	* defense factors. It does not handle damage on landing, as
	* that is technically a second application of damage.
	*/
	damageentity(ent, other, force, drop, type);	

	/*
	* Damge on land / projectile properties. As above, if we
	* want to add projectile (throwing entity into other entities)
	* and damage on landing effects, we need to apply them
	* manually. 
	* 
	* We'll get the member values here and apply them as 
	* entity properties. When the entity lands the engine
	* will use its native damage functionality to apply a
	* damage of type ATK_LAND. 
	*/
	dol_force = dc_damage_get_member_damage_on_landing_force();
	projectile = dc_damage_get_member_projectile();
	
	/*
	* Damage on landing access isn't updated yet, so we'll 
	* have to use legacy entity property.
	*/
	changeentityproperty(ent, "damage_on_landing", dol_force);

	set_entity_property(ent, "blast_state", projectile);

	/*
	* We may have knocked entity down using the native
	* damageentity() function's drop parameter above. 
	* If that's the case, the native functionlity always 
	* applies a hard coded default velocity and direction.
	* 
	* At time of writing there's nothing we can do to change
	* those values in the damageentity() function, so we'll 
	* apply them directly to the entity here instead.
	*/

	fall = get_entity_property(ent, "fall_state");

	if (fall)
	{
		dc_damage_apply_toss();
	}
	
	dc_damage_apply_direction_adjust();
	
}

/*
* Caskey, Damon V.
* 2019-10-16
* 
* If opponent is KO'd, toss them away a bit. This is
* mainly for grapple holds and other situations where
* we might damage opponent without letting it go into
* pain oor fall. But if the damage KO's target, it will
* just appear on the floor dead when released. Run this
* function at time of release so the death doesn't look
* stupid. :)
*/
void dc_damage_ko_release()
{
	void ent;
	void other;

	/* Get acting entities. */
	ent = dc_damage_get_member_entity();
	other = dc_damage_get_member_other();

	/*
	* Reset this instance to clear memory and avoid future conflicts.
	*/
	dc_damage_reset_instance();

	// KO/Dead?
	//if (get_entity_property(ent, "dead"))
	//{
		dc_damage_set_member_drop_force(DC_DAMAGE_DROP_FORCE_MAX);

		// Give it a toss.
		dc_damage_apply_damage();

		dc_damage_set_member_drop_force(NULL());

		return 1;
	//}

	return 0;
}

/*
* Caskey, Damon V.
* 2019-10-17
* 
* Get and return the amount of damage entity will actually take 
* after the engine's interal calculations are complete (offense,
* defense, etc.).
*/
int dc_damage_get_member_final_force()
{
	void ent;
	void other;
	int force;
	int result;
	int drop;
	int type;

	/* Get acting entities. */
	ent = dc_damage_get_member_entity();
	other = dc_damage_get_member_other();

	/* Get damage and attack type. */
	force = dc_damage_get_member_damage_force();
	type = dc_damage_get_member_attack_type();
	drop = dc_damage_get_member_drop_force();

	/*
	* Send entites and attack arguments to the
	* native calculate function and get result.
	*/
	result = getcomputeddamage(ent, other, force, drop, type);

	return result;
}

// Caskey, Damon V.
// 2019-10-17
//
// Return true if final damage will kill entity.
int dc_damage_check_ko()
{
	void ent;
	int health;
	int final_force;

	ent = dc_damage_get_member_entity();

	health = get_entity_property(ent, "hp");
	final_force = dc_damage_get_member_final_force();

	// Final force will reduce health to 0?
	if (final_force >= health)
	{
		return 1;
	}

	return 0;
}

/* 
* Caskey, Damon V.
* 2019-10-17
*
* Returns nearest non-lethal attack force.
*/
int dc_damage_find_non_lethal_force()
{
	int force_result;

	force_result = dc_damage_get_member_damage_force();

	/*
	* Keep decrementing force result
	* it's no longer enough to cause
	* lethal damage.
	*/	
	while (dc_damage_check_ko())
	{
		force_result--;
	}

	/* Return non-lethal force amount. */
	return force_result;
}
