/*
* Caskey, Damon V.
* 2021-02-27. Retool of function writeen by utuneels ~2006.
* 
* AI controlled caller attempts to avoid jump attacks
* with lateral movement.
*/
void dc_ai_avoid_jump_attack()
{   
	void  acting_entity = getlocalvar("self");
	void  target_entity = findtarget(acting_entity);
    int   animation_id = 0;
    float velocity_z = 0.0;
    
    /* Ignore players. */
	if (getentityproperty(acting_entity, "type") == openborconstant("TYPE_PLAYER"))
	{
	    return;
    }

    if(target_entity)
    {
        animation_id   = get_entity_property(target_entity, "animation_id");       
               
        if (animation_id != openborconstant("ANI_JUMPATTACK") && animation_id != openborconstant("ANI_RUNJUMPATTACK"))
        {
            return;
        }

        /* 
        Stop movement. This is instantly overidden by the
        engine unless we actually start a new animation, so
        it's safe to put it here.
        */
        set_entity_property(acting_entity, "velocity_x", 0.0);
        set_entity_property(acting_entity, "velocity_y", 0.0);
        set_entity_property(acting_entity, "velocity_z", 0.0);


        /*
        * Evade up or down depending on our location in relation
        * to target and if we have an evade animation available.
        * 
        * We also run findtarget() again, this time using the evade
        * animation instead animation that called script. The evade
        * animation most likely has a more limited range. We do this
        * because the calling animation is probably WALK. As soon as
        * we dodge the AI will begin walking, and because the WALK
        * has a large range, we'd end up stupidly spamming the 
        * evade animation against an attack we already dodged.
        */

        if(getentityproperty(target_entity, "z") > getentityproperty(acting_entity, "z"))
        {
            
                
            if (getentityproperty(acting_entity, "animvalid", openborconstant("ANI_ATTACKUP")))
            {
                target_entity = findtarget(acting_entity, openborconstant("ANI_ATTACKUP"));
                    
                if(target_entity)
                { 
                    performattack(acting_entity, openborconstant("ANI_ATTACKUP"), 0);
                }                  
            }                
        }
        else
        {
            /*
            * Verify we have the animation, and only evade if the
            * target is within evade animation range. This keeps us
            * from stupidly spamming the evade.
            */

            if (getentityproperty(acting_entity, "animvalid", openborconstant("ANI_ATTACKDOWN")))
            {
                target_entity = findtarget(acting_entity, openborconstant("ANI_ATTACKDOWN"));

                if (target_entity)
                {
                    performattack(acting_entity, openborconstant("ANI_ATTACKDOWN"), 0);
                }
            }
        }        
    }
}
