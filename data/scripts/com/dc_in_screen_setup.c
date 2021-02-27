
/*
* 
* Called when an entity is walking and invincible. Makes
* sure the entity becomes active in play by turning off
* invincibility, stealth, and the ability to leave screen.
* 
*/
int dc_in_screen_setup(void acting_entity)
{	
    /*
    * In the screen and not in spawn animation?
    */

    float position_x = get_entity_property(acting_entity, "position_x");

	if(get_entity_property(acting_entity, "animation_id") != openborconstant("ANI_SPAWN") && position_x > 0 && position_x < openborvariant("hresolution"))
    {
        /* Turn off any invincibility. */
	    set_entity_property(acting_entity, "invincible_state", openborconstant("INVINCIBLE_NONE"));
        set_entity_property(acting_entity, "invincible_time", 0);
        
        /* Stop movement. */
        set_entity_property(acting_entity, "velocity_x", 0.0);
        set_entity_property(acting_entity, "velocity_y", 0.0);
        set_entity_property(acting_entity, "velocity_z", 0.0);
	    
        /* No stealth and can't leave screen. */
        changeentityproperty(acting_entity, "subject_to_screen", 1);
        changeentityproperty(acting_entity, "stealth", 0);
        
        /* Try to use spawn if we have it. */
        if (getentityproperty(acting_entity, "animvalid"), openborconstant("ANI_SPAWN"))
        {
            executeanimation(acting_entity, openborconstant("ANI_SPAWN"), 1);
        }

        return 1;
    }
    else
    {
        return 0;
    }
}
