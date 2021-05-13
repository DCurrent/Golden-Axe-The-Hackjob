#include "data/scripts/dc_hansburg/config.h"

#import "data/scripts/dc_hansburg/entity.c"
#import "data/scripts/dc_hansburg/flag_list.c"
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
    int flag_list = dc_hansburg_get_member_flag_list();

    /* If all flags are disabled, just exit. */
    if (flag_list == DC_HANSBURG_JUMP_ENABLE_NONE)
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
    if (!dc_hansburg_check_double_jump_eligible())
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
	float   edge_x          = 0.0;      // Edge check position, X axis.
    int     wall_x          = 0;        // Wall check position, X axis.
    int     obstacle_x      = 0;        // Obstacle check position, X axis.
    
	/* Target entity. */
	void ent = dc_hansburg_get_member_entity();
    int player_index = get_entity_property(ent, "player_index");

    // Get current key press and any keys being held.
    key_hold = getplayerproperty(player_index, "keys");
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
    * We'll need to get the x position of any possible walls
    * or edges within range of our alternate jump animations.
    */
    edge_x      = dc_hansburg_find_edge_x(ent, DC_HANSBURG_ANI_JUMP_EDGE_START);
    wall_x      = dc_hansburg_find_wall_x(ent, DC_HANSBURG_ANI_JUMP_WALL_START);
    obstacle_x  = dc_hansburg_find_obstacle_x(ent, DC_HANSBURG_ANI_JUMP_OBJECT_START);

    if(obstacle_x)
    {
        /* prepare animation. */
        // animation_set   = DC_HANSBURG_ANI_JUMP_OBJECT_START;

        /* Face away from obstacle. */
        dc_hansburg_face_away(ent, obstacle_x);

    }
    else if(wall_x)
    {
        /* Prepare animation. */
        //animation_set   = DC_HANSBURG_ANI_JUMP_WALL_START;

        /* Face away from wall. */
        dc_hansburg_face_away(ent, wall_x);

    }
    else if(edge_x)
    {
        /* prepare animation. */
        //animation_set   = DC_HANSBURG_ANI_JUMP_EDGE_START;

        /* Face away from edge. */
        dc_hansburg_face_away(ent, edge_x);
    }

	// Double jump.

    // If no wall or edge jump has been set up,
    // entity in a valid jumping animation (excluding double jumps,
    // then let's try a double jump.
	if(dc_hansburg_check_double_jump_eligible())
    {
        // Which horizontal direction command is player sending?
        cmd_direction   = dc_hansburg_aux_command_direction(ent, key_hold);

        // Let's decide which double jump animation to use based
        // on player's horizontal direction command.
        switch(cmd_direction)
        {
            // No direction at all.
            default:
            case DC_HANSBURG_KEY_MOVE_HORIZONTAL_NEUTRAL:

                //animation_set = DC_HANSBURG_ANI_JUMP_DOUBLE_NEUTRAL;
                break;

            // Backward.
            case DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK:

                //animation_set = DC_HANSBURG_ANI_JUMP_DOUBLE_BACK;
                break;

            // Forward.
            case DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD:

                //animation_set = DC_HANSBURG_ANI_JUMP_DOUBLE_FORWARD;
                break;
        }
    }

	// If we made it all the way here, then no special jump action
	// was triggered. Return false.
	return 0;
}

/*
* Caskey, Damon V.
* 2021-05-12
* 
* Return true if entity is in an animation that
* allows an extra jump.
*/
int dc_hansburg_check_double_jump_eligible()
{
    void entity = dc_hansburg_get_member_entity();
    int animation_id = get_entity_property(entity, "animation_id");

    if (animation_id == openborconstant("ANI_JUMP")
        || animation_id == openborconstant("ANI_FORWARDJUMP")
        || animation_id == openborconstant("ANI_RUNJUMP")
        || animation_id == openborconstant("ANI_WALKOFF")
        || animation_id == DC_HANSBURG_ANI_JUMP_WALL
        || animation_id == DC_HANSBURG_ANI_JUMP_EDGE
        || animation_id == DC_HANSBURG_ANI_JUMP_OBJECT
        || animation_id == DC_HANSBURG_ANI_JUMP_DOUBLE_BACK
        || animation_id == DC_HANSBURG_ANI_JUMP_DOUBLE_FORWARD
        || animation_id == DC_HANSBURG_ANI_JUMP_DOUBLE_NEUTRAL)
    {
        return 1;
    }

    return 0;
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

// Return forward or backward key command in relation
// to entity's current facing.
int dc_hansburg_aux_command_direction(void ent, int key_hold)
{
    int direction   = 0;
    int result      = DC_HANSBURG_KEY_MOVE_HORIZONTAL_NEUTRAL;

    // Get current facing.
    direction = getentityproperty(ent, "direction");

    // Run checks based on facing left or right.
    if (direction == openborconstant("DIRECTION_LEFT"))
    {
        // Holding key left?
        if (key_hold & openborconstant("FLAG_MOVELEFT"))
        {
            // Then this is the "forward" key.
            result = DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD;
        }
        // Holding key right?
        else if (key_hold & openborconstant("FLAG_MOVERIGHT"))
        {
            // Then this is the "back" key.
            result = DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK;
        }
    }
    else
    {
        // Holding key left?
        if(key_hold & openborconstant("FLAG_MOVELEFT"))
        {
            // Then this is the "back" key.
            result = DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK;
        }
        // Holding key right?
        else if(key_hold & openborconstant("FLAG_MOVERIGHT"))
        {
            // Then this is the "forward" key.
            result = DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD;
        }
    }

    // Now return our results.
    return result;
}

// Returns x position of closest wall within animation range.
int dc_hansburg_find_wall_x(void ent, int animation_id)
{
    int result              = 0;      // Final result.
    int animation_valid     = 0;       // Animation exists flag.
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

    // If this entity doesn't have the animation at all,
    // then exit. There's nothing else to do.
    animation_valid =  getentityproperty(ent, "animvalid", animation_id);

    if(animation_valid == 0)
    {
        return result;
    }

    // Get current entity x position and direction.
    position_x  = getentityproperty(ent, "x");
    position_y  = getentityproperty(ent, "y");
    position_z  = getentityproperty(ent, "z");
    direction   = getentityproperty(ent, "direction");

    // Get X ranges of animation.
    check_x_min = getentityproperty(ent, "range", "xmin", animation_id);
    check_x_max = getentityproperty(ent, "range", "xmax", animation_id);
    check_y_min = getentityproperty(ent, "range", "amin", animation_id);
    check_y_max = getentityproperty(ent, "range", "amax", animation_id);
    check_z_min = getentityproperty(ent, "range", "zmin", animation_id);
    check_z_max = getentityproperty(ent, "range", "zmax", animation_id);

    // We're doing the range checking ourselves, so we'll need to
    // combine the range settings with current position. If facing
    // left, we'll need subtract for X. If facing right, then we'll
    // add. Y and Z are always added.

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

    // Loop through all possible X positions within
    // X axis range.
    for(loop_x = check_x_min; loop_x <= check_x_max; loop_x++)
    {
        // Now loop over each possible Z position within Z axis
        // range.
        for(loop_z = check_z_min; loop_z <= check_z_max; loop_z++)
        {
            // Get wall height (if any).
            height = checkwall(loop_x, loop_z);

            // Is the wall height within our vertical range?
            if(height >= check_y_min && height <= check_y_max)
            {
                // Has a wall X position been assigned?
                if(result)
                {
                    // Let's find out if this wall position X is closer
                    // to entity than the previous one.

                    wall_distance_old = result - position_x;
                    wall_distance_new = loop_x - position_x;

                    // Compare old to new. If new is closer, assign that as
                    // our wall position X.
                    if(wall_distance_new < wall_distance_old)
                    {
                        result = loop_x;
                    }
                }
                else
                {
                    // Assign wall position to our current check location.
                    result = loop_x;
                }
            }
        }
    }

    // return final result.
    return result;
}

// Get X position of screen edge if found within X range of
// animation.
int dc_hansburg_find_edge_x(void ent, int animation)
{
    // ent: Entity to perform range check.
    // animation_id: Animation to get range settings from.

    int result              = 0;   // Final result.
    int in_range            = 0;   // Target in range.
    int animation_valid     = 0;   // Animation exists flag.
    int scroll_x            = 0;  // Screen scroll position.
    int far_x               = 0;  // location of far screen edge.
    int vartype             = openborconstant("VT_EMPTY");     // Variable type.
    int anim_valid          = 0;   // Valid animation?

    // Verify valid entity.
    vartype = typeof(ent);

    if(vartype != openborconstant("VT_PTR"))
    {
        return result;
    }

    // Verify animation was provided.
    vartype = typeof(animation);

    if(vartype != openborconstant("VT_INTEGER"))
    {
        return result;
    }

    // Verify animation provided is valid.
    anim_valid = getentityproperty(ent, "animvalid", animation);

    if(anim_valid == 0)
    {
        return result;
    }

    // Get current scroll position, far edge position
    // and entity x position.
    scroll_x    = openborvariant("xpos");
    far_x       = scroll_x + openborvariant("hResolution");

    in_range = dc_hansburg_check_range_by_position(ent, animation, scroll_x);

    if(in_range == 1)
    {
        // Just in case the scroll position hasn't moved at all
        // but is still within range, return 1 instead of 0 so
        // evaluations won't fail.
        if(scroll_x == 0.0)
        {
            result = 1;
        }
        else
        {
            result = scroll_x;
        }

        return result;
    }

    // Same check, but this time for the far edge of screen.
    in_range = dc_hansburg_check_range_by_position(ent, animation, far_x);

    if(in_range == 1)
    {
        result = far_x;

        // Just in case the case the end result is still 0,
        // we'll adjust it to 1 so evaluations don't fail.
        if(result == 0.0)
        {
            result = 1;
        }

        return result;
    }

    // Return result (if we made it this far - it's false).
    return result;

}

// Returns x position of first obstacle in range of animation.
int dc_hansburg_find_obstacle_x(void ent, int animation_id){

    int     result          = 0;          // Final result.
    int     animation_valid = 0;           // Animation exists flag.
    float   target_x        = 0.0;        // Position of entity on X axis.
    float   target_y        = 0.0;        // Position of entity on Y axis.
    float   target_z        = 0.0;        // Position of entity on Z axis.
    int     target_h        = 0;          // Target's height setting.
    void    target          = NULL();      // Target entity pointer.
    int     target_count    = 0;          // Target Entity count.
    int     i               = 0;          // Loop counter.
    int     in_range        = 0;           // Target in range?
    int     type            = openborconstant("TYPE_OBSTACLE");        // Type of entity.

    // If this entity doesn't have the animation at all,
    // then exit. There's nothing else to do.
    animation_valid =  getentityproperty(ent, "animvalid", animation_id);

    if(animation_valid == 0)
    {
        return result;
    }

    // Get entity count.
    target_count = openborvariant("ent_max");

    // Loop over each entity index.
    for(i=0; i<target_count; i++)
    {
        // Get entity pointer.
		target = getentity(i);

        target_x = getentityproperty(target, "x");
        target_y = getentityproperty(target, "y");
        target_z = getentityproperty(target, "z");
        target_h = getentityproperty(target, "height");

        // Add height to target's Y position.
        target_y += target_h;

	    // Is the target in range and an obstacle?

	    in_range    = dc_hansburg_check_range_by_position(ent, animation_id, target_x, target_y, target_z);

	    type        = getentityproperty(target, "type");

	    if(in_range == 1 && type == openborconstant("TYPE_OBSTACLE"))
        {
            // Get the current target x position, then exit loop.
            result = getentityproperty(target, "x");
            break;
        }

    }
    return result;

}

// Perform a manual range check vs. given coordinates.
// Performs identical function to check_range, but against
// a manually designated set of position coordinates.
int dc_hansburg_check_range_by_position(void ent, int animation, float target_x, float target_y, float target_z, float target_base)
{
    int     result          = 0;       // Result to return.
    int     direction       = openborconstant("DIRECTION_LEFT");   // Direction of entity.
    int     range_b_min     = 0;
    int     range_b_max     = 0;
    int     range_x_min     = 0;
    int     range_x_max     = 0;
    int     range_y_min     = 0;
    int     range_y_max     = 0;
    int     range_z_min     = 0;
    int     range_z_max     = 0;
    float   position_x      = 0.0;    // Entity position, X axis.
    float   position_y      = 0.0;    // Entity position, Y axis.
    float   position_z      = 0.0;    // Entity position, Z axis.
    int     position_base   = 0;      // Entity position, base.
    int     vartype         = openborconstant("VT_EMPTY");         // Variable type.
    int     anim_valid      = 0;       // Valid animation?

    // Verify valid entity.
    vartype = typeof(ent);

    if(vartype != openborconstant("VT_PTR"))
    {
        return result;
    }

    // Verify animation was provided.
    vartype = typeof(animation);

    if(vartype != openborconstant("VT_INTEGER"))
    {
        return result;
    }

    // Verify animation provided is valid.
    anim_valid = getentityproperty(ent, "animvalid", animation);

    if(anim_valid == 0)
    {
        return result;
    }

    // If a target position base is given, evaluate base range.
    vartype = typeof(target_base);

    if(vartype == openborconstant("VT_DECIMAL")
       || vartype == openborconstant("VT_INTEGER"))
    {

        range_b_min = getentityproperty(ent, "range", "bmin", animation);
        range_b_max = getentityproperty(ent, "range", "bmax", animation);

        position_base  = getentityproperty(ent, "base");

        // If the target position falls within range, set
        // result to true. Otherwise set result to
        // false and return immediately since there's no
        // point in running any more evaluations.

        if((target_base - position_base) >= range_b_min
		  && (target_base - position_base) <= range_b_max)
        {
            result = 1;
        }
        else
        {
            result = 0;
            return result;
        }
    }


    // If a target position X is given, evaluate X range.
    vartype = typeof(target_x);

    if(vartype == openborconstant("VT_DECIMAL")
       || vartype == openborconstant("VT_INTEGER"))
    {
        // Get X range, position and direction.
        range_x_min = getentityproperty(ent, "range", "xmin", animation);
        range_x_max = getentityproperty(ent, "range", "xmax", animation);
        direction   = getentityproperty(ent, "direction");
        position_x  = getentityproperty(ent, "x");

        // X range calculation differs if facing right or left.
        if(direction == openborconstant("DIRECTION_RIGHT"))
        {
            // If the target position falls within range, set
            // result to true. Otherwise set result to
            // false and return immediately since there's no
            // point in running any more evaluations.
            if(target_x >= position_x + range_x_min
                && target_x <= position_x + range_x_max)
            {
                result = 1;
            }
            else
            {
                result = 0;
                return result;
            }
        }
        else
        {
            // If the target position falls within range, set
            // result to true. Otherwise set result to
            // false and return immediately since there's no
            // point in running any more evaluations.
            if(target_x <= position_x - range_x_min
                && target_x >= position_x - range_x_max)
            {
                result = 1;
            }
            else
            {
                result = 0;
                return result;
            }
        }
    }

    // If a target position Y is given, evaluate Y range.
    vartype = typeof(target_y);

    if(vartype == openborconstant("VT_DECIMAL")
       || vartype == openborconstant("VT_INTEGER"))
    {
        range_y_min = getentityproperty(ent, "range", "amin", animation);
        range_y_max = getentityproperty(ent, "range", "amax", animation);

        position_y  = getentityproperty(ent, "y");

        // If the target position falls within range, set
        // result to true. Otherwise set result to
        // false and return immediately since there's no
        // point in running any more evaluations.
        if((target_y - position_y) >= range_y_min
		  && (target_y - position_y) <= range_y_max)
        {
            result = 1;
        }
        else
        {
            result = 0;
            return result;
        }
    }

    // If a target position Z is given, evaluate Z range.
    vartype = typeof(target_z);

    if(vartype == openborconstant("VT_DECIMAL")
       || vartype == openborconstant("VT_INTEGER"))
    {
        range_z_min = getentityproperty(ent, "range", "zmin", animation);
        range_z_max = getentityproperty(ent, "range", "zmax", animation);

        position_z  = getentityproperty(ent, "z");

        // If the target position falls within range, set
        // result to true. Otherwise set result to
        // false and return immediately since there's no
        // point in running any more evaluations.

        if((target_z - position_z) >= range_z_min
		  && (target_z - position_z) <= range_z_max)
        {
            result = 1;
        }
        else
        {
            result = 0;
            return result;
        }
    }

    return result;
}
