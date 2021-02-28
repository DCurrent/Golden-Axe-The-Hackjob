#import "data/scripts/com/spaw0005.h"  //Spawn entity with toss.

#include "data/scripts/common/takedamage_main.c"
#include "data/scripts/dc_fidelity/main.c"

void main()
{
    void acting_entity = getlocalvar("self");
    void other_entity = getlocalvar("attacker");    
    char model_name	= getentityproperty(acting_entity, "name");
        

    if(acting_entity != other_entity)
    {
        if(model_name == "BlueThief")
        {
            spaw0005("Magic_Pot",0,0,0,0,0,0);
        }
		else if(model_name == "GrayThief")
        {
            spaw0005("time",0,0,0,0,0,0);
        }
        else
        {
            spaw0005("meat",0,0,0,0,0,0);
        }

        damageentity(acting_entity, acting_entity, 1, 1, openborconstant("ATK_NORMAL10"));
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
