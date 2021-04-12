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

    if (dc_chain_try_stun_animation() == DC_CHAIN_ANIMATION_NONE)
    {
        executeanimation(acting_entity, openborconstant("ANI_PAIN"), 0);
    }
}