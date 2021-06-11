#include "data/scripts/dc_math/main.c"

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

	for (i = 0; i < player_count; i++)
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