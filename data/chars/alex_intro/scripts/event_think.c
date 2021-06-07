
void main()
{
	void acting_entity = getlocalvar("self");

	float pos_x = get_entity_property(acting_entity, "position_x");
	float pos_z = get_entity_property(acting_entity, "position_z");
	


	if (pos_x - 170.0 < 1.0 && pos_z - 150 < 1.0)
	{		
		int health = get_entity_property(acting_entity, "hp");
		damageentity(acting_entity, acting_entity, health, 0);
	}
	else
	{
		set_entity_property(acting_entity, "destination_x", 170);
		set_entity_property(acting_entity, "destination_z", 150);
	}
	
}