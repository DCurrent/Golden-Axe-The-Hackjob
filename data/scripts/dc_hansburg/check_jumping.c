#include "data/scripts/dc_hansburg/config.h"

#import "data/scripts/dc_hansburg/entity.c"

/*
* Caskey, Damon V.
* 2021-05-19
* 
* Return true if in jump state and playing
* a non-attacking jump animation.
*/
int dc_hansburg_check_normal_jump()
{
    void acting_entity = dc_hansburg_get_member_entity();
    int animation_id = get_entity_property(acting_entity, "animation_id");

    if (!get_entity_property(acting_entity, "jump_state"))
    {
        return 0;
    }

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

/*
* Caskey, Damon V.
* 2021-05-12
*
* Return true if entity is in an animation that
* allows an extra jump.
*/
int dc_hansburg_check_extra_jump_eligible()
{
    void acting_entity = dc_hansburg_get_member_entity();
    int animation_id = get_entity_property(acting_entity, "animation_id");

    if (dc_hansburg_check_normal_jump())
    {
        return 1;
    }

    return 0;
}