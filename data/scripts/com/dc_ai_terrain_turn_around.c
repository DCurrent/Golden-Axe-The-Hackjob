/*
* Caskey, Damon V.
* 2010-05-12 - rework of changedir() by utunnels.
* ~ Retool 2021-02-27
* 
* Change direction when encountering a wall or hole.
*/
void dc_ai_terrain_turn_around()
{
    void acting_entity = getlocalvar("acting_entity");
    float position_x = get_entity_property(acting_entity, "position_x");
    float position_y = get_entity_property(acting_entity, "position_y");
    float position_z = get_entity_property(acting_entity, "position_z");
    float velocity_x = get_entity_property(acting_entity, "velocity_x");
    float velocity_y = get_entity_property(acting_entity, "velocity_y");
    float velocity_z = get_entity_property(acting_entity, "velocity_z");
    int position_direction = getentityproperty(acting_entity, "direction");
    float wall = 0.0;
    
    if(velocity_x > 0)
    {
        wall = checkwall(4 + position_x, position_z);
        if( wall > position_y || (wall==0 && checkhole(4 + position_x, position_z)) )
        {
            position_direction = openborconstant("DIRECTION_LEFT");
            velocity_x = -1.6;
        }
    }
    else if(velocity_x < 0)
    {
        wall = checkwall(position_x -4, position_z);
        if( wall > position_y || (wall==0 && checkhole(position_x - 4, position_z)) )
        {
            position_direction = openborconstant("DIRECTION_RIGHT");
            velocity_x = 1.6;
        }
    }
    if(get_entity_property(acting_entity, "animation_id")== openborconstant("ANI_WALK") && !velocity_x)
    {
        wall = checkwall(position_x, 8 + position_z);

        if( 8 + position_z > openborvariant("player_max_z") || wall > position_y || (wall==0 && checkhole(position_x, 8 + position_z)))
        {
            velocity_z = -0.8;
            executeanimation(acting_entity, openborconstant("ANI_UP"), 1);
        }
    }
	else if(get_entity_property(acting_entity, "animation_id")== openborconstant("ANI_UP"))
	{
        wall = checkwall(position_x, position_z - 8);
        
        if(position_z - 8 < openborvariant("player_min_z") || wall > position_y || (wall==0 && checkhole(position_x, position_z - 8)))
        {
            velocity_z = 0.8;
            executeanimation(acting_entity, openborconstant("ANI_WALK"), 1);
        }
	}

    set_entity_property(acting_entity, "velocity_x", velocity_x);
    set_entity_property(acting_entity, "velocity_y", velocity_y);
    set_entity_property(acting_entity, "velocity_z", velocity_z);

    set_entity_property(acting_entity, "position_direction", position_direction);
}
