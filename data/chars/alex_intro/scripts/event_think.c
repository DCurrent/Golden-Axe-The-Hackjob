
void main()
{
	void acting_entity = getlocalvar("self");

	ga_alex_intro_walk(acting_entity, 170.0, 150.0);
}

void ga_alex_intro_walk(void acting_entity, float goal_pos_x, float goal_pos_z)
{
	float pos_x = get_entity_property(acting_entity, "position_x");
	float pos_z = get_entity_property(acting_entity, "position_z");

	/* Walk to designated spot, then stop and damage self. */
	if (pos_x - goal_pos_x < 1.0 && pos_z - goal_pos_z < 1.0)
	{
		int health = get_entity_property(acting_entity, "hp");
		damageentity(acting_entity, acting_entity, health, 0);
	}
	else
	{
		set_entity_property(acting_entity, "destination_x", goal_pos_x);
		set_entity_property(acting_entity, "destination_z", goal_pos_z);
	}

}