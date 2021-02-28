
/*
* Caskey, Damon V.
* 2010-05-22, modified from Utunnels runaway().
* 2021-02-27 - Remove most legacy property calls 
* and remove unused expansion parameters. 
* 
* Work around walls, escape screen, and then kill acting_entity.
*
*/
void dc_ai_escape()
{
    void acting_entity = getlocalvar("acting_entity");
    float position_x = get_entity_property(acting_entity, "position_x");
    float position_y = get_entity_property(acting_entity, "position_y");
    float position_z = get_entity_property(acting_entity, "position_z");
    float velocity_x = get_entity_property(acting_entity, "velocity_x");
    float velocity_y = get_entity_property(acting_entity, "velocity_y");
    float velocity_z = get_entity_property(acting_entity, "velocity_z");

	float xpos = openborvariant("xpos");

	/*
	* If we're off the screen, just kill overselves
	* and exit.
	*/
	if(position_x < xpos - 30 || position_x > xpos + openborvariant("hresolution") + 30)
	{
		killentity(acting_entity);
		return;
	}
	
	
	int position_direction = get_entity_property(acting_entity, "position_direction");
	int direction_mutiplier = 0;
	float wall;
	float wb;

	if(position_direction == openborconstant("DIRECTION_LEFT"))
	{
		direction_mutiplier = -1;
	}

	wall = checkwall(position_x + 10 * position_direction, position_z);
	wb = checkwall(position_x - 60 * position_direction, position_z);

	if(wall > 0 && wall > position_y +20)
	{
		if(wb > position_y) { velocity_z = 1.5;}
				
		set_entity_property(acting_entity, "velocity_x", -3 * direction_mutiplier);
		set_entity_property(acting_entity, "velocity_y", velocity_y);
		set_entity_property(acting_entity, "velocity_z", velocity_z + 0.5);

		if(direction_mutiplier > 0) // flip
		{
			changeentityproperty(acting_entity, "direction", openborconstant("DIRECTION_LEFT"));
		}
		else
		{
			changeentityproperty(acting_entity, "direction", openborconstant("DIRECTION_RIGHT"));
		}
	}
	else if(wall > 0 && wall > position_y)
	{
		set_entity_property(acting_entity, "position_base", wall);
		set_entity_property(acting_entity, "position_x", position_x);
		set_entity_property(acting_entity, "position_y", wall + 0.5);
		set_entity_property(acting_entity, "position_z", position_z);

		set_entity_property(acting_entity, "velocity_x", 3 * direction_mutiplier);
		set_entity_property(acting_entity, "velocity_y", velocity_y);
		set_entity_property(acting_entity, "velocity_z", 0.0);
	}
	else
	{
		set_entity_property(acting_entity, "velocity_x", 3 * direction_mutiplier);
		set_entity_property(acting_entity, "velocity_y", velocity_y);
		set_entity_property(acting_entity, "velocity_z", velocity_z);
	}		
	
}