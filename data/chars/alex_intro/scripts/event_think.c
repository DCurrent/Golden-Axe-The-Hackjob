
#include "data/scripts/dc_math/main.c"

void main()
{
	void acting_entity = getlocalvar("self");

	dc_alex_intro_walk(acting_entity, 170.0, 150.0);
}

/*
* Caskey, Damon V.
* 2021-06-07 (replaces legacy move commands in idle animation)
* 
* Force entity's AI to walk to spot. Spot is reached or
* a player entity is near by, set up dialog.
*/
void dc_alex_intro_walk(void acting_entity, float goal_pos_x, float goal_pos_z)
{	
	int health = get_entity_property(acting_entity, "hp");

	/* 
	* If we are at designated spot and not dead yet,
	* run dialog setup function. It will KO us and
	* prepare variables. Otherwise set destination 
	* points so we will walk to designated spot.
	*/

	if (health < 1)
	{		
		return;
	}

	if (dc_get_first_player(acting_entity, 15.0))
	{		
		dc_dialog_setup(acting_entity);
	}
	else if (dc_check_near_position(acting_entity, goal_pos_x, goal_pos_z, 1.0))
	{
		dc_dialog_setup(acting_entity);
	}
	else
	{
		set_entity_property(acting_entity, "destination_x", goal_pos_x);
		set_entity_property(acting_entity, "destination_z", goal_pos_z);
	}
}

/*
* Caskey, Damon V.
* 2021-06-07
* 
* Kill self and set up dialog variable for first player.
*/
void dc_dialog_setup(void acting_entity)
{
	void first_player = dc_get_first_player(acting_entity, -1);

	/* Kill acting entity. */
	int health = get_entity_property(acting_entity, "hp");

	damageentity(acting_entity, acting_entity, health, 0);

	/* Animation script needs this to assign binding on dialog. */
	setentityvar(acting_entity, "dialog_player_entity", first_player); // first_player);
}

/*
* Caskey, Damon V.
* 2021-06-07
* 
* Accept entity, position, and distance. Return 
* true if entity position is within distance of 
* position parameters.
*/
int dc_check_near_position(void acting_entity, float pos_x, float pos_z, float distance)
{
	float acting_pos_x = get_entity_property(acting_entity, "position_x");
	float acting_pos_z = get_entity_property(acting_entity, "position_z");
	float distance_x = dc_math_difference_float(acting_pos_x, pos_x);
	float distance_z = dc_math_difference_float(acting_pos_z, pos_z);

	if (distance_x <= distance && distance_z <= distance)
	{
		return 1;
	}

	return 0;
}


/*
* Caskey, Damon V.
* 2021-06-08
* 
* Get first player entity within distance
* parameter of acting entity. Return 0 if 
* none found. Use -1 distance for infinite.
*/
void dc_get_first_player(void acting_entity, float distance)
{
	int i = 0;
	int player_count = openborvariant("maxplayers");
	void player_entity = NULL();

	float acting_pos_x = 0.0;
	float acting_pos_z = 0.0;
	float player_pos_x = 0.0;
	float player_pos_z = 0.0;
	float distance_x = 0.0;
	float distance_z = 0.0;

	for(i=0; i < player_count; i++)
	{
		/* 
		* Get entity for this player index.
		* If there isn't one, just move on.
		*/
		player_entity = getplayerproperty(i, "entity");

		if (!player_entity)
		{
			continue;
		}

		/* 
		* Get distance between acting entity and player. 
		* If distance is within parameter distance, then
		* we return true.
		*/

		acting_pos_x = get_entity_property(acting_entity, "position_x");
		acting_pos_z = get_entity_property(acting_entity, "position_z");
		player_pos_x = get_entity_property(player_entity, "position_x");
		player_pos_z = get_entity_property(player_entity, "position_z");

		distance_x = dc_math_difference_float(acting_pos_x, player_pos_x);
		distance_z = dc_math_difference_float(acting_pos_z, player_pos_z);

		/* 
		* If distance is a negative number, just return
		* player entity. 
		*/
		if (distance < 0)
		{			
			return player_entity;
		}

		if (distance_x <= distance && distance_z <= distance)
		{
			return player_entity;
		}
	}

	/* 
	* Never found a player entity within 
	* distance, so we return false.
	*/
	return 0;
}