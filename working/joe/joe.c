// #include "data/scripts/common/attack.h"
#include "data/scripts/common/magic.h"
#include "data/scripts/common/mp.h"

#include "data/scripts/com/key0004.h"
#include "data/scripts/com/bind0003.h"
#include "data/scripts/com/bind0004.h"
#include "data/scripts/com/bind0008.h"
#include "data/scripts/com/bind0010.h"
#include "data/scripts/com/dama0001.h"
#include "data/scripts/com/proj0003.h"
#include "data/scripts/com/velo0001.h"

void test_stealth(){

	void vSelf = getlocalvar("self");
	void vTarget = findtarget(vSelf);

	int s = getentityproperty(vSelf, "stealth");
	int s2 = getentityproperty(vTarget, "stealth");
	int d = getentityproperty(vSelf, "detect");

	settextobj(0, 100, 20, 1, -1, "S: " + s);
	//settextobj(1, 100, 30, 1, -1, "S2: " + s2);
	settextobj(2, 100, 40, 1, -1, "D: " + d);

}

#include "data/scripts/common/magic.h"
#include "data/scripts/common/mp.h"

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
		if(frame>8) // cast 1 fire spirit each frame
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
		if(frame==9) // spawn several fire fountains
		{
			clearspawnentry();
			setspawnentry("name", "firefountain");
			int z1 = getglobalvar("levelminz");
			int z2 = getglobalvar("levelmaxz");
			for(i=0; i<8; i++)
			{
				if(!randspawn(self, getindexedvar(11)/4, getindexedvar(11)/4, z1, z2)) {i--;}
			}
			for(i=0; i<8; i++)
			{
				if(!randspawn(self, getindexedvar(11)/4*3, getindexedvar(11)/4, z1, z2)) {i--;}
			}
		}
	}
	else if(level == 3) //level 3
	{
		if(frame==9) // spawn 2 fire ghost
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
		if(frame==9) // spawn 12 gaint fire drops
		{

			clearspawnentry();
			setspawnentry("name", "firedrop");
			int z1 = getglobalvar("levelminz");
			int z2 = getglobalvar("levelmaxz");
			for(i=0; i< 12; i++)
			{
				e = randspawn(self, -160, 100, z1, z2/2 + z1/2);
				if(e) { changeentityproperty(e, "direction", 0);}
				e = randspawn(self, -160, 100, z2/2 + z1/2, z2);
				if(e) { changeentityproperty(e, "direction", 0);}
			}
		}
	}
	else if(level == 5) //level 5
	{
		if(frame==9) //spawn a lava pool
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
		if(frame==9) //spawn a gaint fire dragon
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