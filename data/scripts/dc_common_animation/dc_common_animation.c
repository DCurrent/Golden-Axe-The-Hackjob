#include "data/scripts/dc_common_animation/config.h"

/*
* Common animation functions that are custom 
* for a specfic module's animation scripts.
*/

/*
* Set temporary invincibility to calling entity.
*/
void set_self_invincibility(int time)
{
    void self = getlocalvar("self");
    int expire_time = time + openborvariant("elapsed_time");

    set_entity_property(self, "invincible_state", openborconstant("INVINCIBLE_INTANGIBLE"));    
    set_entity_property(self, "invincible_time", expire_time);
}

void dc_persistent_status_save()
{
    void acting_entity = getlocalvar("self");
    int index = get_entity_property(acting_entity, "player_index");
    
    int mp;
    
    if (index >= 0)
    {
        mp = get_entity_property(acting_entity, "mp");
    
        setglobalvar("dc_pstat_mp" + index, mp);
    }
}

void dc_persistent_status_apply()
{
    void acting_entity = getlocalvar("self");
    int index = getentityproperty(acting_entity, "playerindex");

    if (index >= 0)
    {
        int max_mp = getentityproperty(acting_entity, "maxmp");
        int saved_mp = getglobalvar("dc_pstat_mp" + index);

        if (saved_mp > max_mp)
        {
            saved_mp = max_mp;
        }

        set_entity_property(acting_entity, "mp", saved_mp);
    }
}

void throw_bottles()
{
    void self = getlocalvar("self");
    // check mp
    //int mp = getentityproperty(self, "mp");
    int dir = getentityproperty(self, "direction");
    int sx = getentityproperty(self, "x");
    int sz = getentityproperty(self, "z");
    int sa = getentityproperty(self, "a");
    int pot = getentityproperty(self, "mp") / 10 + 1;
    int i;
    int x = 15;
    int y = 38;
    int off = 1;
    int cor;
    if (pot > getentityproperty(self, "maxmp") / 10) { pot = getentityproperty(self, "maxmp") / 10; }
    cor = pot % 2;
    if (dir == 0)
    {
        x = -x;
    }
    if (getentityproperty(self, "name") == "Gilius_Thunderhead")
    {
        x = -x;
    }
    else if (getentityproperty(self, "name") == "Alex_")
    {
        x = 0;
        y = 48;
    }

    clearspawnentry();
    setspawnentry("name", "Magic");

    if (getentityproperty(self, "model") != "Joe_Musashi")                 //Joe uses gestures instead of magic bottles.
    {
        for (i = 0; i < pot; i++)
        {
            void m = spawn();
            int s;
            changeentityproperty(m, "position", sx + x, sz + 1, sa + y);
            if (cor == 1)
            {
                s = (i + 1) / 2;
            }
            else
            {
                s = (i + 2) / 2;
            }
            changeentityproperty(m, "velocity", s * off / 8.0);
            off = -off;
        }
    }
    setlocalvar("pot", pot); // record magic level
    changeentityproperty(self, "mp", 0);
}
