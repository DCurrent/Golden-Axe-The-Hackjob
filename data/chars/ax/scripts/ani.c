#include "data/scripts/vars/constants.h"

#import "data/scripts/z_ani.c"

#import "data/scripts/com/dc_ai_avoid_jump_attack.c"        //Avoid jump attacks by walking laterally.
#import "data/scripts/com/ani0001.h"       //Generic conditional animation switch.
#import "data/scripts/com/ani0009.h"		//Animation switch wrapper.
#import "data/scripts/com/ani0012.h"		//Switch animation when height is < 70% of target.
#import "data/scripts/com/ani0016.h"		//Alt animation if opponent rising.
#import "data/scripts/com/ani0017.h"		//Switch to alternate animation if nearest hostile is in range of alt and all checks match.
#import "data/scripts/com/ani0018.h"		//Switch to alternate animation if nearest hostile is in range of alt and an animal type (should be rolled into ani0017).
#import "data/scripts/com/ani0019.h"       //Switch animation by hole/wall proximity.
#import "data/scripts/com/bind0002.h"      //Syncronize location; no bind.
#import "data/scripts/com/bind0003.h"
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/bind0010.h"      //Grapple binding.
#import "data/scripts/com/bind0014.h"
#import "data/scripts/com/bind0018.h"
#import "data/scripts/com/bind0023.h"		//Flash or target's custom flash.
#import "data/scripts/com/dama0004.h"		//Damage by grapple index.
#import "data/scripts/com/dir0001.h"
#import "data/scripts/com/jump0003.h"      //Change current animation to a real "jump".
#import "data/scripts/com/jump0004.h"      //Key controlled jumpframe emulation.
#import "data/scripts/com/paus0001.h"		//Pause action of free roaming entities.
#import "data/scripts/com/proj0003.h"
#import "data/scripts/com/seal0001.h"		//Turn off target specials.
#import "data/scripts/com/soun0005.h"		//Random sound player.
#import "data/scripts/com/dc_in_screen_setup.c"		//In screen check.
#import "data/scripts/com/stal0001.h"
#import "data/scripts/com/stat0001.h"		//Change MP or HP of target.
#import "data/scripts/com/stat0003.h"      //Save MP.
#import "data/scripts/com/stat0005.h"      //Set a timed property by string.
#import "data/scripts/com/velo0001.h"
#import "data/scripts/com/wake0001.h"		//Wait before attacking function.

/*
* 2021-02-26, Non-legacy Imports
*/
#include "data/scripts/dc_chain/main.c"
#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_gauntlet/main.c"
#include "data/scripts/dc_keys/main.c"

void invins()
{
    void vSelf   = getlocalvar("self");
    int  iTime  = openborvariant("elapsed_time");

    changeentityproperty(vSelf, "invincible", 3);
    changeentityproperty(vSelf, "invinctime", iTime + 1000000);
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
            if(getentityproperty(p, "name")=="Ax_Battler")
            {
                killentity(getlocalvar("self"));
                setglobalvar("a_npc", NULL());
                break;
            }
        }
    }
   
    changeentityproperty(getlocalvar("self"), "subject_to_screen", 1);
   
}

void magic1(void self)
{
    clearspawnentry();
    setspawnentry("name", "expsmall");
    setspawnentry("coords", getentityproperty(self, "x") - openborvariant("xpos"), getentityproperty(self, "z"), getentityproperty(self, "a"));
    void e = spawn();
    changeentityproperty(e, "owner", self);
    changeentityproperty(e, "base", getentityproperty(self, "a"));
    setglobalvar("smallexp_count", 50);
}

void magic2(void self)
{
    clearspawnentry();
    setspawnentry("name", "expsmall");
    setspawnentry("coords", getentityproperty(self, "x") - openborvariant("xpos"), getentityproperty(self, "z"), getentityproperty(self, "a"));
    void e1 = spawn();
    changeentityproperty(e1, "owner", self);
    changeentityproperty(e1, "base", getentityproperty(self, "a"));
    setglobalvar("smallexp_count", 25);

    setspawnentry("name", "explarge");
    void e2 = spawn();
    changeentityproperty(e2, "owner", self);
    changeentityproperty(e2, "base", getentityproperty(self, "a"));
    setglobalvar("largeexp_count", 25);
}

void magic3(void self)
{
    clearspawnentry();
    setspawnentry("name", "explarge");
    setspawnentry("coords", getentityproperty(self, "x") - openborvariant("xpos"), getentityproperty(self, "z"), getentityproperty(self, "a"));
    void e = spawn();
    changeentityproperty(e, "owner", self);
    changeentityproperty(e, "base", getentityproperty(self, "a"));
    setglobalvar("largeexp_count", 50);
}

void magic4(void self)
{
    clearspawnentry();
    setspawnentry("name", "expgaint");
    setspawnentry("coords", 240, 120 + openborvariant("ypos"), 0);
    void e = spawn();
    changeentityproperty(e, "owner", self);
    changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z"), getentityproperty(self, "a"));
    changeentityproperty(e, "base", getentityproperty(self, "a"));
}

void cast_magic()
{
    void self = getlocalvar("self");
    changeentityproperty(self, "mp", 0);
    int pot = getlocalvar("pot");
    if(pot>=6) // level 4 magic
    {
        magic4(self);
    }
    else if(pot==5) // level 3 magic
    {
        magic3(self);
    }
    else if(pot>=3) // level 2 magic
    {
        magic2(self);
    }
    else // level 1 magic
    {
        magic1(self);
    }
    setlocalvar("pot", NULL()); // done, remove the variant
}
