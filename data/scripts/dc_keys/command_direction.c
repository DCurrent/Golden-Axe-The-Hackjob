#include "data/scripts/dc_keys/config.h"

#import  "data/scripts/dc_keys/entity.c"

/* 
* Caskey, Damon V.
* 2018-11-03
*
* Return true if current directional key is "back" in relation to entity direction.
*/
int dc_keys_check_key_back(int player_index)
{
    void acting_entity = getplayerproperty(player_index, "entity");
    int key_hold = 0;
    int direction = 0;    

    /*
    * Get player's key state and the entity's current
    * direction. If left/right keys are opposing the
    * entity's direction we can return true.
    */

    key_hold = getplayerproperty(player_index, "keys");
    direction = get_entity_property(acting_entity, "position_direction");

    if (direction == openborconstant("DIRECTION_LEFT"))
    {
        if (key_hold & openborconstant("FLAG_MOVERIGHT"))
        {
            return 1;
        }
    }
    else if (direction == openborconstant("DIRECTION_RIGHT"))
    {
        if (key_hold & openborconstant("FLAG_MOVELEFT"))
        {
            return 1;
        }
    }

    /* No checks passed, return false. */
    return 0;
}

/*
* Caskey, Damon V.
* 2021-04-22
* 
* Turn around if player is holding opposite
* left/right key in relation to current
* direction.
*/
void dc_keys_command_direction()
{
    void acting_entity = dc_keys_get_member_entity();
    int direction = 0;
    int opposite_key = 0;
    int player_index = 0;
    
    /* 
    * Send player index to key back function to find out
    * if player is holding direction key opposite of
    * our currect direction. If not, we just exit.
    */

    player_index = get_entity_property(acting_entity, "player_index");

    opposite_key = dc_keys_check_key_back(player_index);

    if (!opposite_key)
    {
        return;
    }

    /*
    * We got this far, so let's turn the entity around.
    * All we need to do is get current direction and
    * set it to the opposite.
    */

    direction = get_entity_property(acting_entity, "position_direction");
    
    if (direction == openborconstant("DIRECTION_LEFT"))
    {
        direction = openborconstant("DIRECTION_RIGHT");
    }
    else if (direction == openborconstant("DIRECTION_RIGHT"))
    {
        direction = openborconstant("DIRECTION_LEFT");
    }
    
    set_entity_property(acting_entity, "position_direction", direction);
}