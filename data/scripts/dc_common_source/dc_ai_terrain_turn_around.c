/*
* Caskey, Damon V.
* 2010-05-12 - rework of changedir() by utunnels.
* ~ Retool 2021-02-27
* 
* Change direction when encountering a wall or hole.
*/
void dc_ai_terrain_turn_around()
{

    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float a = getentityproperty(self, "a");
    float va = getentityproperty(self, "tossv");
    float vx = getentityproperty(self, "xdir");
    float vz = getentityproperty(self, "zdir");
    int d = getentityproperty(self, "direction");
    float wall;
    if (vx > 0)
    {
        wall = checkwall(4 + x, z);
        if (wall > a || (wall == 0 && checkhole(4 + x, z)))
        {
            d = 0; vx = -1.6;
        }
    }
    else if (vx < 0)
    {
        wall = checkwall(x - 4, z);
        if (wall > a || (wall == 0 && checkhole(x - 4, z)))
        {
            d = 1; vx = 1.6;
        }
    }
    if (getentityproperty(self, "animationid") == openborconstant("ANI_WALK") && !vx)
    {
        wall = checkwall(x, 8 + z);
        if (8 + z > openborvariant("player_max_z") || wall > a || (wall == 0 && checkhole(x, 8 + z)))
        {
            vz = -0.8;
            changeentityproperty(self, "animation", openborconstant("ANI_UP"));
        }
    }
    else if (getentityproperty(self, "animationid") == openborconstant("ANI_UP"))
    {
        wall = checkwall(x, z - 8);
        if (z - 8 < openborvariant("player_min_z") || wall > a || (wall == 0 && checkhole(x, z - 8)))
        {
            vz = 0.8;
            changeentityproperty(self, "animation", openborconstant("ANI_WALK"));
        }
    }
    changeentityproperty(self, "velocity", vx, vz, va);
    changeentityproperty(self, "direction", d);

    return;

    /*  
	* 2021-02-28, new code below. Unable to fix issues before 
	* deadline. Disabled for now and reinserted legacy code. 
	*/

    /*void acting_entity = getlocalvar("self");
    float position_x = get_entity_property(acting_entity, "position_x");
    float position_y = get_entity_property(acting_entity, "position_y");
    float position_z = get_entity_property(acting_entity, "position_z");
    float velocity_x = get_entity_property(acting_entity, "velocity_x");
    float velocity_y = get_entity_property(acting_entity, "velocity_y");
    float velocity_z = get_entity_property(acting_entity, "velocity_z");
    int position_direction = get_entity_property(acting_entity, "position_direction");
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
    */
}
