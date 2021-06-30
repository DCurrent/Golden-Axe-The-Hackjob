#include "data/scripts/dc_common_onpain/config.h"

/*
* Caskey, Damon V
* 2021-03-30
* ~ Refactored from fall0001 (2009).
*
* Common onpain event function used by
* most models.
*/
void dc_common_onpain()
{
    void acting_entity = getlocalvar("self");   
    int animation_old = get_entity_property(acting_entity, "animation_id_previous");

    /*
    * Try a stun animation. If we aren't stunned, then
    * reset pain back to Pain1. This forces the same pain
    * animations no matter which attack type we are hit
    * with. That in turn lets us freely use Pain# for
    * custom reactions (example: The stun system), but 
    * also have various attack types to interact with  
    * defense ratings and fatalities.
    */

    int stun_result = dc_chain_try_stun_animation();

    if (stun_result == DC_CHAIN_ANIMATION_NONE)
    {
        executeanimation(acting_entity, openborconstant("ANI_PAIN"), 0);
        set_entity_property(acting_entity, "animation_id_previous", animation_old);
        set_entity_property(acting_entity, "in_pain", 1);
    }
    
    // settextobj(0, 10, 30, 1, openborconstant("FRONTPANEL_Z") + 10000, "Stun: " + dc_chain_get_member_stun_current() + "/" + dc_chain_get_member_stun_threshold());
    // settextobj(1, 10, 40, 1, openborconstant("FRONTPANEL_Z") + 10000, "animation_previous: " + animation_old);
    // settextobj(2, 10, 50, 1, openborconstant("FRONTPANEL_Z") + 10000, "stun_result: " + stun_result);
}