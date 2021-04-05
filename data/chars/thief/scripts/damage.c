#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_gauntlet/main.c"

void main()
{
    void acting_entity = getlocalvar("self");
    void other_entity = getlocalvar("attacker");    
    char model_name	= getentityproperty(acting_entity, "name");
    int pos_direction = 0;
    float toss_x = 0.8;
    float toss_y = 3.5;
    float toss_z = 0.0;
    void item_spawn = NULL();

    if(acting_entity != other_entity)
    {
        /* 
        * Spawn an item if we are an item carrying thief. Hitpoints
        * are how we track the number of items remaining. We're
        * immune to damage from attacks, but we'll damage ourselves
        * by 1 HP.
        */
                

        /*
        * Item depends on what kind of thief we are.
        */

        if(model_name == "BlueThief")
        {
            item_spawn = dc_gauntlet_quick_spawn("Magic_Pot");
            
            dc_fidelity_quick_play("golden_axe_magic_pot");
        }
		else if(model_name == "GreenThief")
        {
            item_spawn = dc_gauntlet_quick_spawn("meat");
        } 


        /* 
        * If we spawned an item, we need to handle self damage,
        * getting item to correct spot, and tossing the item.
        */

        if (item_spawn)
        {
            /* 
            * Move item to our current position, and then toss 
            * it in same direction we are facing. 
            */

            dc_elmers_quick_spot(item_spawn, 0);

            pos_direction = get_entity_property(acting_entity, "position_direction");

            if (pos_direction == openborconstant("DIRECTION_LEFT"))
            {
                toss_x = -toss_x;
            }

            tossentity(item_spawn, toss_y, toss_x, toss_z);

            /* 
            * We use hitpoints to count the number of items we have left. 
            *
            * - Defense set up for immunity to normal damage, but not 
            * pain/knodown effect. This we can get kicked around but 
            * don't lose any HP.
            * 
            * - We damage ourselves for exactly one hitpoint here.
            */ 
            
            damageentity(acting_entity, acting_entity, 1, 1, openborconstant("ATK_LIFESPAN"));
        }
    }

    /*
    * Dirty fix for dc_fidelity getting sent
    * blank entity and falling back to global
    * KO sound when thief is KO'd. We should
    * be able to run global damage script.
    */
    dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN);

    /* Run common takedamage function. */
    //common_event_takedamage(acting_entity);

}
