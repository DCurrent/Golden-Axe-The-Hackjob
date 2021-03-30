#include "data/scripts/dc_common_onblock/config.h"

/*
* Caskey, Damon V.
* 2021-03-28 (refactor from obst0001, 2009-11-13)
* 
* Run when blocked by an obstacle. If falling, entity
* collides with obstacle causing damage to the
* obstacle and itself. If obstacle survives entity
* bounces back.
*/
void dc_common_onblock_obstacle()
{
	void    acting_entity = getlocalvar("self");							
	int     fall_state = get_entity_property(acting_entity, "fall_state");
	int     impact_damage_force = 0;
	void    opponent_entity = NULL();
	void    obstacle_entity = NULL();
	int     pos_direction = 0;
	float   velocity_x = 0.0;	
	int     obstacle_height = 0;
	int     pos_y = 0.0;
	
	int		obstacle_hitpoints = 0;
	int		rush_count = 0;
	void	damage_on_landing = NULL();
	int		damage_on_landing_attack_type = 0;
	int		damage_on_landing_attack_force = 0;
	int		damage_type = 0;

	float toss_x = 0.0;
	float toss_y = 0.0;

	/* If we aren't falling, do nothing and exit. */
	if (!fall_state)
	{
		return;
	}
		
	obstacle_entity = getlocalvar("obstacle");						
	obstacle_height = getentityproperty(obstacle_entity, "height");
	pos_y = get_entity_property(acting_entity, "position_y");
	
	/* 
	* Obstacle must be higher than us, we just
	* fly over it otherwise.
	*/
	if (obstacle_height < pos_y)
	{
		return;
	}
		
	/* 
	* Get opponent entity, if there isn't an opponent, we'll 
	* just use the obstacle.
	*/
	
	opponent_entity = get_entity_property(acting_entity, "opponent");
	
	if (!opponent_entity)
	{
		opponent_entity = obstacle_entity;
	}
			
	/*
	* Add two hits to opponents rush count. One is for 
	* slamming acting entity into something, the other
	* is for damage done to an obstacle.
	*/

	rush_count = getentityproperty(opponent_entity, "rush_count");
	changeentityproperty(opponent_entity, "rush_count", rush_count + 2);

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
	* 
	* TODO: Calculate Z velocity for lateral bouncing.
	*/

	velocity_x = get_entity_property(acting_entity, "velocity_x");

	if (velocity_x >= 0)																				
	{
		pos_direction = openborconstant("DIRECTION_ADJUST_RIGHT");
		toss_x = (-velocity_x) * 0.5;
		toss_y = velocity_x * 1.5;
		impact_damage_force += (velocity_x * 3);
	}
	else														
	{
		pos_direction = openborconstant("DIRECTION_ADJUST_LEFT");
		toss_x = (-velocity_x) * 0.5;
		toss_y = (-velocity_x) * 1.5;
		impact_damage_force += ((-velocity_x) * 3);
	}

	/* 
	* Spawn flash at acting entity location. 
	* Note the flash handles sound effects 
	* for us too.
	*/

	void flash = dc_gauntlet_quick_flash("cvs_hit_flash");
	dc_elmers_set_member_target(acting_entity);
	dc_elmers_quick_spot(flash, DC_ELMERS_SORT_FRONT);

	/*
	* Now we damage ourselves and the obstacle. 
	*/

	/* 
	* Obstacle damage. We use opponent as "other" for the obstacle's
	* damage to give them credit since they're probably the one 
	* that chucked us into obstacle or lured us into a trap that 
	* did it. This gives credit to opponent for the damage, but 
	* also means we need to damage obstacle first so when script
	* is finished current opponent appears in HUD and in opponent
	* property instead of the obstacle.
	* 
	* Obstacles take the impact damage only, using normal attack
	* type, and a fall force equal to the impact force.
	* 
	* TODO: Find out if we have an attacking box for indirect
	* damage, and if so use its attack type.
	*/	

	dc_damage_set_member_entity(obstacle_entity);
	dc_damage_set_member_other(opponent_entity);
	dc_damage_set_member_attack_type(openborconstant("ATK_NORMAL"));
	dc_damage_set_member_damage_force(impact_damage_force);
	dc_damage_set_member_direction_adjust(openborconstant("DIRECTION_ADJUST_NONE"));
	dc_damage_set_member_drop_force(impact_damage_force);
	dc_damage_apply_damage();

	/*
	* Damage ourselves, using impact for the drop force and adding
	* impact with any existing damage on landing for the total
	* damage force. Opponent gets credit for the damage.
	* 
	* If the damage we caused to obstacle wasn't sufficient to KO
	* it, we apply the calculated velocity as a toss value so we 
	* appear to bounce off. Otherwise we do nothing and appear to 
	* crash through the obstacle instead.
	*/

	//damage_on_landing = get_entity_property(acting_entity, "damage_on_landing");
	//damage_on_landing_attack_force = get_damage_on_landing_property(damage_on_landing, "attack_force");
	damage_on_landing_attack_force = getentityproperty(acting_entity, "damage_on_landing");
	damage_type = openborconstant("ATK_LAND");

	dc_damage_set_member_entity(acting_entity);
	dc_damage_set_member_entity(opponent_entity);
	dc_damage_set_member_attack_type(damage_type);
	dc_damage_set_member_damage_force(impact_damage_force + damage_on_landing_attack_force);
	dc_damage_set_member_direction_adjust(pos_direction);
	dc_damage_set_member_drop_force(impact_damage_force);
	dc_damage_apply_damage();

	/* If obstacle survived - bounce off. */

	obstacle_hitpoints = get_entity_property(obstacle_entity, "hp");

	if (obstacle_hitpoints > impact_damage_force)
	{				
		tossentity(acting_entity, toss_y, toss_x, 0.0);													
	}
}
