#include "data/scripts/dc_cancel/config.h"

#import "data/scripts/dc_cancel/entity.c"

void dc_cancel_set_member_allow_idle_animation(int value)
{
    void acting_entity = dc_cancel_get_member_entity();
    char id = "";

    /* 
    * If we're missing an entity, attempting to get
    * an entityvar will throw an error and shut down.
    * 
    * Let's catch it here so we know precisely where
    * the problem is.
    */

    if (!acting_entity)
    {       
        shutdown(1, "\n dc_cancel_set_member_allow_idle_animation(): No acting entity available. \n\t Parameters: " + value + "\n\n");
    }

    // Get ID.
    id = dc_cancel_get_instance() + DC_CANCEL_MEMBER_ALLOW_IDLE_ANIMATION;

    // If value is default, make sure the variable
    // is deleted.
    if (value == DC_CANCEL_DEFAULT_ALLOW_IDLE_ANIMATION)
    {
        value = NULL();
    }
   
    setentityvar(acting_entity, id, value);
    
}

int dc_cancel_get_member_allow_idle_animation()
{
    char id;
    int result;
    void acting_entity = dc_cancel_get_member_entity();
    
    /*
    * If we're missing an entity, attempting to get
    * an entityvar will throw an error and shut down.
    *
    * Let's catch it here so we know precisely where
    * the problem is.
    */

    if (!acting_entity)
    {
        shutdown(1, "\n dc_cancel_get_member_allow_idle_animation(): No acting entity available. \n\n");
    }
    
    // Get id.
    id = dc_cancel_get_instance() + DC_CANCEL_MEMBER_ALLOW_IDLE_ANIMATION;

    result = getentityvar(acting_entity, id);
  
    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_CANCEL_DEFAULT_ALLOW_IDLE_ANIMATION;
    }

    return result;
}

/*
* Caskey, Damon V.
* 2021-04-09
* 
* Check current allowed idle animation. If same as
* current animation, set entity to idle.
*/
void dc_cancel_try_set_idle()
{
    void acting_entity = dc_cancel_get_member_entity();
 
    int animation_allow_idle = dc_cancel_get_member_allow_idle_animation();
    int animation_id = get_entity_property(acting_entity, "animation_id");

    /* 
    * If this is the current allowed idle, then
    * set idle state and erase the allowed idle
    * animation member.
    */
    if (animation_allow_idle == animation_id)
    {
        setidle(acting_entity);
        dc_cancel_set_member_allow_idle_animation();
    }    
}
