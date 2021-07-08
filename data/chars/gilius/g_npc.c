#include "data/scripts/common/attack.h"

void rise_move()
{
    int r = rand();

    if(r%3==0)
    {
        changeentityproperty(getlocalvar("self"), "velocity", 0, -0.5, 0);
    }
    else if(r%2==0)
    {
        changeentityproperty(getlocalvar("self"), "velocity", 0, 0.5, 0);
    }
}

void suicide()
{
    int i;
    void p;
    for(i=0; i<3; i++)
    {
        p = getplayerproperty(i, "ent");
        if(p!=NULL())
        {
            if(getentityproperty(p, "name")=="Gilius_Thunderhead")
            {
                killentity(getlocalvar("self"));
                setglobalvar("g_npc", NULL());
                break;
            }
        }
    }
    if(getglobalvar("inscreen")==1)
    {
        changeentityproperty(getlocalvar("self"), "subject_to_screen", 1);
    }
}
