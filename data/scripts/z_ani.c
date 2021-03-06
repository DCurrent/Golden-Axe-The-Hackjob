//Generic animation script.

#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/dc_common_source/dc_ai_avoid_jump_attack.c"        //Avoid jump attacks by walking laterally.
#import "data/scripts/com/ani0009.h"		//Animation switch wrapper.
#import "data/scripts/com/ani0012.h"		//Switch animation when height is < 70% of target.
#import "data/scripts/com/ani0017.h"		//Switch to alternate animation if nearest hostile is in range of alt and all checks match.
#import "data/scripts/com/bind0003.h"
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/bind0010.h"      //Grapple binding.
#import "data/scripts/com/bind0014.h"
#import "data/scripts/com/bind0018.h"
#import "data/scripts/com/bind0023.h"		//Flash or target's custom flash.
#import "data/scripts/com/dama0004.h"		//Damage by grapple index.
#import "data/scripts/com/dir0001.h"
#import "data/scripts/com/jump0003.h"      //Change current animation to a real "jump".
#import "data/scripts/com/proj0003.h"
#import "data/scripts/com/seal0001.h"		//Turn off target specials.
#import "data/scripts/com/soun0005.h"		//Random sound player.
#import "data/scripts/com/dc_in_screen_setup.c"		//In screen check.
#import "data/scripts/com/stal0001.h"

#include "data/scripts/dc_fidelity/main.c"  // Sound player.

void backattack()
{
	void self = getlocalvar("self");
	void target = findtarget(self);
	if(target!=NULL())
	{
		int x1 = getentityproperty(self, "x");
		int x2 = getentityproperty(target, "x");
		int z1 = getentityproperty(self, "z");
		int z2 = getentityproperty(target, "z");
		int dir = getentityproperty(self, "direction");
		int dx = x1 - x2;
		int dz = z1 - z2;
		if(dz<0)
		{
			dz = -dz;
		}
		if((dx>-42 && dz<12 && dx < 0 && dir==0) || (dx<42 && dz<12 && dx>0 && dir==1) )
		{
			// back attack
			changeentityproperty(self, "animation", openborconstant("ANI_ATTACKBACKWARD"));
		}
	}
}

void set_self_invincibility(int t)
{
    void self = getlocalvar("self");
	changeentityproperty(self, "invincible", 1);
	//changeentityproperty(self, "blink", 1);
	changeentityproperty(self, "invinctime", t+openborvariant("elapsed_time"));
}

//slam
void change_slam_2()
{
    void self=getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    if(target!=NULL())
    {
        changeentityproperty(target, "animation", openborconstant("ANI_FALL5"));
        bindentity(target, self, 32, -1, 35, 1, 0);
    }
}

void dc_persistent_status_save()
{
	void self = getlocalvar("self");
    int index = getentityproperty(self, "playerindex");
	int mp;
    if(index>=0) 
    {
        mp = getentityproperty(self, "mp") / 10;
        setglobalvar("player"+index+"mp", mp);
    }
}

void dc_persistent_status_apply()
{
	void self = getlocalvar("self");
    int index = getentityproperty(self, "playerindex");
    
	if(index>=0)
    {
		changeentityproperty(self, "mp", getglobalvar("player"+index+"mp")*10);
		if(getentityproperty(self, "mp") > getentityproperty(self, "maxmp"))
		{
			changeentityproperty(self, "mp", getentityproperty(self, "maxmp"));
		}		
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
    int pot = getentityproperty(self, "mp")/10 + 1;
    int i;
    int x = 15;
    int y = 38;
    int off = 1;
    int cor ;
	if(pot>getentityproperty(self, "maxmp")/10) {pot = getentityproperty(self, "maxmp")/10;}
	cor = pot%2;
    if(dir==0)
    {
       x = -x;
    }
	if(getentityproperty(self, "name")=="Gilius_Thunderhead")
	{
		x = -x;
	}
	else if(getentityproperty(self, "name")=="Alex_")
	{
		x = 0;
		y = 48;
	}

    clearspawnentry();
    setspawnentry("name", "Magic");
        
    if(getentityproperty(self, "model")!="Joe_Musashi")                 //Joe uses gestures instead of magic bottles.
    {    
        for(i=0; i<pot; i++)
        {
            void m = spawn();
            int s;
            changeentityproperty(m, "position", sx + x, sz+1, sa+y);
            if(cor==1)
            {
                s = (i+1)/2;
            }
            else
            {
                s = (i+2)/2;
            }
            changeentityproperty(m, "velocity", s*off/8.0);
            off = -off;
        }
    }
    setlocalvar("pot", pot); // record magic level
    changeentityproperty(self, "mp", 0);
}