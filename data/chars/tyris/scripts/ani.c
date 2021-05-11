#include "data/scripts/vars/constants.h"

#import "data/scripts/z_ani.c"	

#import "data/scripts/com/ai0007.h"
#import "data/scripts/com/ani0009.h"		//Animation switch wrapper.
#import "data/scripts/com/ani0012.h"		//Switch animation when height is < 70% of target.
#import "data/scripts/com/bind0003.h"
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/bind0010.h"      //Grapple binding.
#import "data/scripts/com/bind0014.h"
#import "data/scripts/com/bind0023.h"		//Flash or target's custom flash.
#import "data/scripts/com/dama0004.h"		//Damage by grapple index.
#import "data/scripts/com/jump0003.h"      //Change current animation to a real "jump".
#import "data/scripts/com/proj0003.h"
#import "data/scripts/com/soun0005.h"		//Random sound player.
#import "data/scripts/com/seal0001.h"       // Add seal and sealtime to target.
#import "data/scripts/com/stal0001.h"       // Add stalltime to target.
#import "data/scripts/com/velo0003.h"


#import "data/scripts/com/dc_ai_avoid_jump_attack.c"

#include "data/scripts/dc_disney/main.c"
#include "data/scripts/dc_fidelity/main.c"

/*
#import "data/scripts/common/attack.h"
#import "data/scripts/common/magic.h"
#import "data/scripts/common/mp.h"


void magic1()
{
	setlocalvar("level", 1);
}

void magic2()
{
	setlocalvar("level", 2);
}

void magic3()
{
	setlocalvar("level", 3);
}

void magic4()
{
	setlocalvar("level", 4);
}


void magic5()
{
	setlocalvar("level", 5);
}

void magic6()
{
	setlocalvar("level", 6);
}

void randspawn(void self, int x, int r, int z1, int z2)
{
	void e;
	setspawnentry("coords", x + rand()%r, z1 + (z2 - z1)/2 + rand()%(z2 - z1)/2, 0);
	e = spawn();
	if(checkhole(getentityproperty(e, "x"), getentityproperty(e, "z")) && !checkwall(getentityproperty(e, "x"), getentityproperty(e, "z")))
	{
		killentity(e);
		return 0;
	}
	else
	{
		changeentityproperty(e, "position", getentityproperty(e, "x"), getentityproperty(e, "z"), getentityproperty(e, "base"));
		changeentityproperty(e, "owner", self);
		return e;
	}
}

//frame based magic animations
void magic_anim(int frame)
{
	int level = getlocalvar("level");
	void self = getlocalvar("self");
	void e;
	int i;
	if(level == 1) // level 1 magic 
	{
		if(frame>4) // cast 1 fire spirit each frame
		{
			clearspawnentry();
			setspawnentry("name", "firespirit");
			e = spawn();
			changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z"), getentityproperty(self, "a"));
			changeentityproperty(e, "base", getentityproperty(e, "a"));
			changeentityproperty(e, "direction", frame%2);
			changeentityproperty(e, "owner", self);
		}
	}
	else if(level == 2) // level 2 magic 
	{
		if(frame==5) // spawn several fire fountains
		{
			clearspawnentry();
			setspawnentry("name", "firefountain");
			int z1 = openborvariant("player_min_z");
			int z2 = openborvariant("player_max_z");
			for(i=0; i<8; i++)
			{
				if(!randspawn(self, openborvariant("hresolution")/4, openborvariant("hresolution")/4, z1, z2)) {i--;}
			}
			for(i=0; i<8; i++)
			{
				if(!randspawn(self, openborvariant("hresolution")/4*3, openborvariant("hresolution")/4, z1, z2)) {i--;}
			}
		}
	}
	else if(level == 3) //level 3
	{
		if(frame==5) // spawn 2 fire ghost
		{
			clearspawnentry();
			setspawnentry("name", "fireghost");
			e = spawn();
			changeentityproperty(e, "position", getentityproperty(self, "x") + 64, getentityproperty(self, "z")+10, getentityproperty(self, "a")+32);
			changeentityproperty(e, "direction", 1);
			changeentityproperty(e, "base", getentityproperty(e, "a"));
			changeentityproperty(e, "owner", self);
			e = spawn();
			changeentityproperty(e, "position", getentityproperty(self, "x") - 64, getentityproperty(self, "z")+10, getentityproperty(self, "a")+32);
			changeentityproperty(e, "direction", 0);
			changeentityproperty(e, "base", getentityproperty(e, "a"));
			changeentityproperty(e, "owner", self);
		}
	}
	else if(level == 4) //level 4
	{
		if(frame==5) // spawn 12 gaint fire drops
		{

			clearspawnentry();
			setspawnentry("name", "firedrop");
			int z1 = openborvariant("player_min_z");
			int z2 = openborvariant("player_max_z");
			for(i=0; i< 12; i++)
			{
				e = randspawn(self, -1 1 0 0, z1, z2/2 + z1/2);
				if(e) { changeentityproperty(e, "direction", 0);}
				e = randspawn(self, -1 1 0 0, z2/2 + z1/2, z2);
				if(e) { changeentityproperty(e, "direction", 0);}
			}
		}
	}
	else if(level == 5) //level 5
	{
		if(frame==4) //spawn a lava pool
		{

			clearspawnentry();
			setspawnentry("name", "flare");
			e = spawn();
			changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z"), getentityproperty(self, "a"));
			changeentityproperty(e, "base", getentityproperty(e, "a"));
			changeentityproperty(e, "owner", self);
        }
	}
	else // level 6
	{
		if(frame==6) //spawn a gaint fire dragon
		{

			clearspawnentry();
			setspawnentry("name", "firedragon");
			setspawnentry("coords", 460, openborvariant("ypos"), 0);
			e = spawn();
			changeentityproperty(e, "owner", self);

		}
	}
}


void cast_magic()
{
    int pot = getlocalvar("pot");
    if(pot>=9) // level 6 magic
    {
        magic6();
    }
    else if(pot==8) // level 5 magic
    {
        magic5();
    }
    else if(pot==7) // level 4 magic
    {
        magic4();
    }
    else if(pot==6) // level 3 magic
    {
        magic3();
    }
    else if(pot==5) // level 2 magic
    {
        magic2();
    }
    else // level 1 magic
    {
        magic1();
    }
    setlocalvar("pot", NULL()); // done, remove the variant
}
*/