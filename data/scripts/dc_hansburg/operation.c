#include "data/scripts/dc_hansburg/config.h"

#import "data/scripts/dc_hansburg/entity.c"
#import "data/scripts/dc_hansburg/config_flags.c"
#import "data/scripts/dc_hansburg/check_jumping.c"
#import "data/scripts/dc_hansburg/condition_height.c"
#import "data/scripts/dc_hansburg/condition_time.c"

/*
* Caskey, Damon V.
* 2021-05-12
* 
* Check conditions that apply to any extra jump attempt.
*/
int dc_hansburg_check_global_conditions()
{
    int flag_list = dc_hansburg_get_member_config_flags();

    /* If all flags are disabled, just exit. */
    if (flag_list == DC_HANSBURG_CONFIG_ENABLE_NONE)
    {
        return 0;
    }

    /* If acting entity is above max Y position, disable. */
    if (!dc_hansburg_check_condition_position_y_max())
    {
        return 0;
    }

    /* Disable timer expired or not set. */
    if (!dc_hansburg_check_disable_time())
    {
        return 0;
    }    

    /* Have to be in an eligible jump animation. */
    if (!dc_hansburg_check_extra_jump_eligible())
    {
        return 0;
    }

    return 1;
}

/* 
* Main auxiliary jump function. Checks entity for Wall, edge, obstacle,
* and double jumping animations, evaluates usability based on
* status and environment, and executes as necessary. Returns
* the animation set, or 0 if none.
*/
int dc_hansburg_try_extra_jump(){

    int     key_press       = 0;        // Key press triggering event.
	int     key_hold        = 0;        // Keys currently held when event was triggered.
	int     direction       = openborconstant("DIRECTION_RIGHT");    // Current facing.
	int     cmd_direction   = DC_HANSBURG_KEY_MOVE_HORIZONTAL_NEUTRAL;  // Current directional command hold from player in relation to entity's facing.
	
	/* Target entity. */
	void ent = dc_hansburg_get_member_entity();
    int player_index = get_entity_property(ent, "player_index");

    // Get current key press and any keys being held.
    
    key_press = getplayerproperty(player_index, "newkeys");

	/* Is this a jump key press? */
    if (!(key_press & openborconstant("FLAG_JUMP")))
    {
        return 0;
    }

    /* Global conditions pass?*/
    if (!dc_hansburg_check_global_conditions())
    {
        return 0;
    }

	/* Let's get the entity properties we'll need. */
	direction       = get_entity_property(ent, "position_direction");	  
    
    /* 
    * Try to execute the extra jumps in order
    * of priority. If any one succeeds, we 
    * return true and exit.
    */

    if(dc_hansburg_try_obstacle_jump(ent))
    {
        return 1;
    }

    if(dc_hansburg_try_wall_jump(ent))
    {
        return 1;
    }
    
    if(dc_hansburg_try_edge_jump(ent))
    {
        return 1;
    }

    if (dc_hansburg_try_double_jump(ent))
    {
        return 1;
    }

	/* 
    * If we made it all the way here, then no special jump action
	* was triggered. Return false.
	*/
    return 0;
}

/*
* Caskey, Damon V.
* 2021-05-16
* 
* Compare direction key to available
* double jump animations and performs
* the double jump if possible. 
*/
int dc_hansburg_try_double_jump(void acting_entity)
{
    /* 
    * Let's decide which double jump animation to use based
    * on player's horizontal direction command.
    */

    int cmd_direction = dc_hansburg_get_command_direction(acting_entity);
    int animation_set = 0;
    
    switch (cmd_direction)
    {
        
    default:
    case DC_HANSBURG_KEY_MOVE_HORIZONTAL_NEUTRAL:

        animation_set = DC_HANSBURG_ANI_JUMP_DOUBLE_NEUTRAL;
        break;
       
    case DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK:

        animation_set = DC_HANSBURG_ANI_JUMP_DOUBLE_BACK;
        break;
        
    case DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD:

        animation_set = DC_HANSBURG_ANI_JUMP_DOUBLE_FORWARD;
        break;
    }

    dc_disney_set_instance(dc_hansburg_get_instance() + DC_HANSBURG_BASE_ID);

    dc_disney_macro_execute_animation(animation_set);

    return 1;    
}

/*
* Caskey, Damon V.
* 2021-05-16 (split off from dc_hansburg_try_extra_jump).
*
* Start wall jump by playing the
* wall jump animation and forcing
* entity to face away from wall.
* Checks following conditions:
*
* - Entity has wall jump start animation.
* - Wall is within obstacle jump start
* animation range settings.
*
* Note no further action is taken by script. We
* assume the animation will handle remaining
* actions needed.
*/
int dc_hansburg_try_wall_jump(void acting_entity)
{
    float pos_x = dc_hansburg_find_wall_x(acting_entity, DC_HANSBURG_ANI_JUMP_WALL_START);

    if (!pos_x)
    {
        return 0;
    }

    dc_hansburg_face_away(acting_entity, pos_x);

    dc_disney_set_instance(dc_hansburg_get_instance() + DC_HANSBURG_BASE_ID);

    dc_disney_macro_execute_animation(DC_HANSBURG_ANI_JUMP_WALL_START);

    return 1;
}

/*
* Caskey, Damon V.
* 2021-05-16 (split off from dc_hansburg_try_extra_jump).
*
* Start obstacle jump by playing the
* obstacle jump animation and forcing
* entity to face away from obstacle. 
* Checks following conditions:
*
* - Entity has obstacle jump start animation.
* - Obstacle is within obstacle jump start 
* animation range settings.
*
* Note no further action is taken by script. We
* assume the animation will handle remaining
* actions needed.
*/
int dc_hansburg_try_obstacle_jump(void acting_entity)
{
    if (!dc_hansburg_check_extra_jump_eligible())
    {
        return 0;
    }

    float pos_x = dc_hansburg_find_obstacle_x(acting_entity, DC_HANSBURG_ANI_JUMP_OBJECT_START);

    if (!pos_x)
    {
        return 0;
    }

    dc_hansburg_face_away(acting_entity, pos_x);

    dc_disney_set_instance(dc_hansburg_get_instance() + DC_HANSBURG_BASE_ID);

    dc_disney_macro_execute_animation(DC_HANSBURG_ANI_JUMP_OBJECT_START);

    return 1;
}

/*
* Caskey, Damon V.
* 2021-05-16 (split off from dc_hansburg_try_extra_jump).
*
* Start screen edge jump by playing the
* screen edge jump animation and forcing
* entity to face away from edge. Checks
* following conditions:
*
* - Entity has screen jump start animation.
* - Edge is within screen jump start animation
* range settings.
*
* Note no further action is taken by script. We
* assume the animation will handle remaining
* actions needed.
*/
int dc_hansburg_try_edge_jump(void acting_entity)
{
    float pos_x = dc_hansburg_find_edge_x(acting_entity, DC_HANSBURG_ANI_JUMP_EDGE_START);

    if (!pos_x)
    {
        return 0;
    }

    dc_hansburg_face_away(acting_entity, pos_x);

    dc_disney_set_instance(dc_hansburg_get_instance() + DC_HANSBURG_BASE_ID);

    dc_disney_macro_execute_animation(DC_HANSBURG_ANI_JUMP_EDGE_START);

    return 1;
}



/* Face away from given position. */
int dc_hansburg_face_away(void ent, float target_x)
{

    int     result          = openborconstant("DIRECTION_RIGHT");  // Result and position entity is set to.
    float   position_x      = 0.0;    // Entity position, X axis.

	/* Get X position. */
	position_x      = get_entity_property(ent, "position_x");


    /* 
    * Simple check. If we are to left of target x
    * position, then face left. Otherwise face right.
    */
    if(position_x < target_x)
    {
        result = openborconstant("DIRECTION_LEFT");
    }
    else
    {
        result = openborconstant("DIRECTION_RIGHT");
    }

    /* Apply direction result to entity.*/
    set_entity_property(ent, "position_direction", result);
   
    return result;
}

/* 
* Caskey, Damon V.
* ~2016-xx-xx
* 
* Return if player direction input is "Forward", 
* "Backward" or "Neutral" in relation to entity's 
* current direction.
*/
int dc_hansburg_get_command_direction(void ent, int key_hold)
{
    int direction = get_entity_property(ent, "position_direction");
    int player_index = get_entity_property(ent, "player_index");
    int key_hold = getplayerproperty(player_index, "keys");

    /* 
    * If key held is same direction as facing, then
    * player is holding "Forward" key. If the key
    * is opposite, they are holding "Backward" key.
    * If player isn't holding left or right then
    * we just return "Neutral".
    */    

    if (key_hold & openborconstant("FLAG_MOVELEFT"))
    {
        if (direction == openborconstant("DIRECTION_LEFT"))
        {
            return DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD;
        }
        else
        {
            return DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK;
        }
    }
    else if (key_hold & openborconstant("FLAG_MOVERIGHT"))
    {
        if (direction == openborconstant("DIRECTION_RIGHT"))
        {
            return DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD;
        }
        else
        {
            return DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK;
        }
    }
    else
    {
        return DC_HANSBURG_KEY_MOVE_HORIZONTAL_NEUTRAL;
    }    
}

/*
* Caskey, Damon V.
* 2016-xx-xx, retool 2021-05-17
*
* Accept an entity and animation. Return
* the X position of first wall in range
* of animation (or 0 if none).
*/
int dc_hansburg_find_wall_x(void ent, int animation_id)
{
    int result              = 0;      // Final result.
    int check_x_min         = 0;      // Checking minimum range.
    int check_x_max         = 0;      // Checking maximum range.
    int check_y_min         = 0;      // Checking minimum range.
    int check_y_max         = 0;      // Checking maximum range.
    int check_z_min         = 0;      // Checking minimum range.
    int check_z_max         = 0;      // Checking maximum range.
    int wall_height         = 0;      // Wall height.
    int wall_distance_old   = 0;
    int wall_distance_new   = 0;
    int direction           = openborconstant("DIRECTION_RIGHT");  // Current facing.
    int height              = 0;      // height of wall found (if any).

    float position_x        = 0.0;
    float position_y        = 0.0;
    float position_z        = 0.0;

    int loop_x              = 0;      // Loop counter.
    int loop_z              = 0;      // Loop counter.

    /* 
    * If this entity doesn't have the animation at all,
    * then exit. There's nothing else to do.
    */ 
   
    if(!getentityproperty(ent, "animvalid", animation_id))
    {
        return 0;
    }

    /*
    * We're doing the range checking ourselves, so we'll need to
    * combine the range settings with current position. If facing
    * left, we'll need subtract for X. If facing right, then we'll
    * add. Y and Z are always added.
    */

    position_x  = get_entity_property(ent, "position_x");
    position_y  = get_entity_property(ent, "position_y");
    position_z  = get_entity_property(ent, "position_z");
    direction   = get_entity_property(ent, "position_direction");

    
    check_x_min = getentityproperty(ent, "range", "xmin", animation_id);
    check_x_max = getentityproperty(ent, "range", "xmax", animation_id);
    check_y_min = getentityproperty(ent, "range", "amin", animation_id);
    check_y_max = getentityproperty(ent, "range", "amax", animation_id);
    check_z_min = getentityproperty(ent, "range", "zmin", animation_id);
    check_z_max = getentityproperty(ent, "range", "zmax", animation_id);    

    /* Handle left/or right facing. */

    if(direction == openborconstant("DIRECTION_LEFT"))
    {
        check_x_min = position_x - check_x_min;
        check_x_max = position_x - check_x_max;
    }
    else
    {
        check_x_min += position_x;
        check_x_max += position_x;
    }

    check_y_min += position_y;
    check_y_max += position_y;

    check_z_min += position_z;
    check_z_max += position_z;

    /*
    * Loop through all possible X positions within
    * X axis range. At each X position, loop over
    * each possible Z position.
    * 
    * Note: This couldn't get more unoptimal. We 
    * are esentially running a loop and making
    * wall checks against every single pixel in
    * an animations range cube. Even if we assume 
    * a modest cube of 50 width and 50 depth that's
    * a loop count of 2,500, with each one running
    * the expensive checkwall() function. We can
    * probably rework this by looping the wall 
    * collection instead, getting the wall dimensions  
    * and comparing them to range for overlap.
    */

    for(loop_x = check_x_min; loop_x <= check_x_max; loop_x++)
    {        
        for(loop_z = check_z_min; loop_z <= check_z_max; loop_z++)
        {
            /* Is the wall height within our vertical range? */

            height = checkwall(loop_x, loop_z);
                        
            if (height < check_y_min || height > check_y_max)
            {
                continue;
            }

            /* 
            * Has a wall X position been populated? If so 
            * we'll compare distance to see if current
            * loop's wall position is closer. 
            * 
            * If we haven't populated the wall X result,
            * then just use current loop X value.
            */
            if(result)
            {                    
                wall_distance_old = result - position_x;
                wall_distance_new = loop_x - position_x;
                   
                if(wall_distance_new < wall_distance_old)
                {
                    result = loop_x;
                }
            }
            else
            {                    
                result = loop_x;
            }            
        }
    }

    // return final result.
    return result;
}

/*
* Caskey, Damon V.
* 2016-xx-xx, retool 2021-05-17
*
* Accept an entity and animation. Return
* the X position of screen edge in range
* of animation (or 0 if none). If the edge
* is found but at 0, returns 1.
*/
int dc_hansburg_find_edge_x(void ent, int animation)
{   
    int in_range            = 0;   // Target in range.
    int animation_valid     = 0;   // Animation exists flag.
    int scroll_x            = 0;  // Screen scroll position.
    int far_x               = 0;  // location of far screen edge.
    
    /* Verify entity has animation provided. */
    if(getentityproperty(ent, "animvalid", animation))
    {
        return 0;
    }

    /* 
    * Get current scroll position, far edge position
    * and entity x position.
    */
    scroll_x    = openborvariant("xpos");
    far_x       = scroll_x + openborvariant("hResolution");

    in_range = dc_hansburg_check_range_by_position(ent, animation, scroll_x, 0.0, 0.0, 0.0);

    if(in_range == 1)
    {
        /* 
        * Just in case the scroll position hasn't moved at all
        * but is still within range, return 1 instead of 0 so
        * evaluations won't fail.
        */
        if(scroll_x == 0.0)
        {
            return 1;
        }
        else
        {
            return scroll_x;
        }
    }

    /* Same check as above, but for opposite edge of the screen. */

    in_range = dc_hansburg_check_range_by_position(ent, animation, far_x, 0.0, 0.0, 0.0);

    if(in_range == 1)
    {
        if(far_x == 0.0)
        {
            return 1;
        }

        return far_x;
    }

    /* If we made it this far, result is false.*/
    return 0;
}

/*
* Caskey, Damon V.
* 2016-xx-xx, retool 2021-05-17
*
* Accept an entity and animation. Return
* the X position of first obstacle found
* in range of animation. Return 0 if none.
*/
int dc_hansburg_find_obstacle_x(void acting_entity, int animation_id){

    int     result          = 0;          // Final result.
    float   target_x        = 0.0;        // Position of entity on X axis.
    float   target_y        = 0.0;        // Position of entity on Y axis.
    float   target_z        = 0.0;        // Position of entity on Z axis.
    int     target_h        = 0;          // Target's height setting.
    void    target          = NULL();      // Target entity pointer.
    int     target_count    = 0;          // Target Entity count.
    int     i               = 0;          // Loop counter.
    
    /*
    * If entity doesn't have animation, its
    * an automatic fail.
    */
    if(getentityproperty(acting_entity, "animvalid", animation_id))
    {
        return 0;
    }

    /* Loop over each entity index. */

    target_count = openborvariant("count_entities");
    
    for(i=0; i<target_count; i++)
    {
        /* Get entity pointer. */
		target = getentity(i);

        /* 
        * Is type an obstacle? If not skip to
        * next entity.
        */
        if (!(getentityproperty(target, "type") & openborconstant("TYPE_OBSTACLE")))
        {
            continue;
        }

        target_x = get_entity_property(target, "position_x");
        target_y = get_entity_property(target, "position_y");
        target_z = get_entity_property(target, "position_z");
        target_h = getentityproperty(target, "height");

        /* Add height to target's Y position. */
        target_y += target_h;

	    /* Is the target in range? */
	    if(dc_hansburg_check_range_by_position(acting_entity, animation_id, target_x, target_y, target_z))
        {
            /* Return target x position. */
            return target_x;
        }
    }

    /* 
    * Never found valid object in 
    * range, return false. 
    */
    return 0;
}

/*
* Caskey, Damon V.
* 2016-xx-xx, retool 2021-05-17
* 
* Accepts an entity, animation, and 
* target positon coordinates. Returns
* true if target position is within
* animation's range.
*/
int dc_hansburg_check_range_by_position(void acting_entity, int animation, float target_x, float target_y, float target_z, float target_base)
{
     
    /* 
    * If entity doesn't have animation, its
    * an automatic fail.
    */ 
    if(!getentityproperty(acting_entity, "animvalid", animation))
    {
        return 0;
    }

    /*
    * If the target position is outside of any
    * range axis, return false.
    */

    /* Base range. */
    int range_b_min = getentityproperty(acting_entity, "range", "bmin", animation);
    int range_b_max = getentityproperty(acting_entity, "range", "bmax", animation);
    int base_check = target_base - get_entity_property(acting_entity, "position_base");

    if(base_check < range_b_min || base_check > range_b_max)
    {
        return 0;
    }

    /* Horizontal range. */
    int range_x_min = getentityproperty(acting_entity, "range", "xmin", animation);
    int range_x_max = getentityproperty(acting_entity, "range", "xmax", animation);
    int direction   = get_entity_property(acting_entity, "position_direction");
    int position_x  = get_entity_property(acting_entity, "position_x");
    
    int check_x = position_x + range_x_min;

    if(direction == openborconstant("DIRECTION_RIGHT"))
    {
        if(target_x < check_x || target_x > check_x)
        {
            return 0;
        }
    }
    else
    {
        check_x = position_x - range_x_min;

        if(target_x > check_x || target_x < check_x)
        {
            return 0;
        }
    }   

    /* Vertical range. */
    int range_y_min = getentityproperty(acting_entity, "range", "amin", animation);
    int range_y_max = getentityproperty(acting_entity, "range", "amax", animation);
    int check_y = target_y - get_entity_property(acting_entity, "position_y");
   
    if(check_y < range_y_min || check_y > range_y_max)
    {
        return 0;
    }
    

    /* Lateral range. */
    int range_z_min = getentityproperty(acting_entity, "range", "zmin", animation);
    int range_z_max = getentityproperty(acting_entity, "range", "zmax", animation);
    int check_z = target_y - get_entity_property(acting_entity, "position_z");

    if(check_z < range_z_min || check_z > range_z_max)
    {
        return 0;
    }
    
    /* If we made it here, we can return true. */
    return 1;
}
