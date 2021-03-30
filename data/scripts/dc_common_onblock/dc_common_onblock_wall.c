#include "data/scripts/dc_common_onblock/config.h"
/*
* Caskey, Damon V.
* 
* 2021-03-29
* ~2011-07-22
* ~2009-10-10
* 
* Primary wall function. Damages and bounces self in opposite direction of current
* X velocity when falling and obstructed by wall/platform.
*/
void dc_common_onblock_wall()
{	
	void acting_entity		= getlocalvar("self");														
	int fall_state		= 0;
	int damage_force	= 1;																		
	void opponent_entity = NULL();																				
	int position_direction;																				
	float velocity_x = 0.0;																			
	float toss_x = 0.0;																			
    float toss_y = 0.0;
	int	invincible_time = 0;
	int	elapsed_time = openborvariant("elapsed_time");
	int rush_count = 0;
	int damage_on_landing_attack_force = 0;
	int damage_type = 0;

	/* Falling and not currently invincible? */

	invincible_time = get_entity_property(acting_entity, "invincible_time");
	fall_state = get_entity_property(acting_entity, "fall_state");

	/* 
	* If we aren't falling, or have any invincible time
	* left, do nothing and exit. 
	*/
	
	if (!fall_state)
	{
		return;
	}
		
	if (invincible_time > elapsed_time)
	{
		return;
	}
														
	/* 
	* Give acting entity a very short window of invincibility
	* so it can't spam the wall damage. 
	*/

	invincible_time = DC_COMMON_ONBLOCK_INVINCIBLE_TIME + elapsed_time;

	set_entity_property(acting_entity, "invincible_state", openborconstant("INVINCIBLE_INTANGIBLE"));
	set_entity_property(acting_entity, "invincible_time", invincible_time);

	/*
	* If we have an opponent, add a hit to their rush count
	* for the wall slam. Otherwise use acting entity as
	* opponent, but don't credit the rush count.
	*/

	opponent_entity = get_entity_property(acting_entity, "opponent");

	if (opponent_entity)
	{
		rush_count = getentityproperty(opponent_entity, "rush_count");
		changeentityproperty(opponent_entity, "rush_count", rush_count + 1);
	}
	else
	{
		opponent_entity = acting_entity;
	}
	
	/*
	* If we are moving right, then we'll bounce
	* to left and vice versa. The bounce velocity 
	* is 50% of original velocity so entity won't
	* bounce between walls forever or be TOO easy
	* to juggle.
	* 
	* We also aply some damge to the entity as 
	* a % of the velocity. If the entity is moving
	* left, we need to resign so the damage isn't
	* negative.
	*/

	velocity_x = get_entity_property(acting_entity, "velocity_x");

	if (velocity_x >= 0)																			
	{
		position_direction	= openborconstant("DIRECTION_ADJUST_RIGHT");
		toss_x	= (-velocity_x) * 0.5;															
		toss_y	= velocity_x * 1.5;
		damage_force += (velocity_x * 3);																
	}
	else																					
	{
		position_direction	= openborconstant("DIRECTION_ADJUST_LEFT");
		toss_x	= (-velocity_x) * 0.5;															
		toss_y	= (-velocity_x) * 1.5;
		damage_force += ((-velocity_x) * 3);															
	}

	/*
	* Spawn flash at acting entity location.
	* Note the flash handles sound effects
	* for us too.
	*/

	void flash = dc_gauntlet_quick_flash("flash_hit_knockdown");
	dc_elmers_set_member_target(acting_entity);
	dc_elmers_quick_spot(flash, DC_ELMERS_SORT_FRONT);

	/*
	* Damage ourselves, using impact for the drop force and adding
	* impact with any existing damage on landing for the total
	* damage force. Opponent gets credit for the damage.
	*/

	damage_on_landing_attack_force = getentityproperty(acting_entity, "damage_on_landing");
	damage_type = openborconstant("ATK_LAND");

	damage_force += damage_on_landing_attack_force;

	dc_damage_set_member_entity(acting_entity);
	dc_damage_set_member_other(opponent_entity);
	dc_damage_set_member_attack_type(damage_type);
	dc_damage_set_member_damage_force(damage_force);
	dc_damage_set_member_direction_adjust(position_direction);
	dc_damage_set_member_drop_force(damage_force);
	dc_damage_apply_damage();
	
	/* 
	* Apply the toss to bounce.
	*/

	tossentity(acting_entity, toss_y, toss_x, 0.0);
	
}