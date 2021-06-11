// #import "data/scripts/common/attack.h"

void suicide()
{
    int i;
    void p;
    for(i=0; i<3; i++)
    {
        p = getplayerproperty(i, "ent");
        if(p!=NULL())
        {
            if(getentityproperty(p, "name")=="Tyris_Flare")
            {
                killentity(getlocalvar("self"));
                setglobalvar("t_npc", NULL());
                break;
            }
        }
    }
   
    changeentityproperty(getlocalvar("self"), "subject_to_screen", 1);
    
}
