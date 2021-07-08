#include "data/scripts/common/attack.h"
#include "data/scripts/common/magic.h"
#include "data/scripts/common/mp.h"

void adjust_offense()
{
    void self=getlocalvar("self");
    int index = getentityproperty(self, "playerindex");
	int i;
	int m = getglobalvar("player"+index+"mp");
	if(m>4) {m=4;}
	for(i=0; i<15; i++)
    {
		changeentityproperty(self, "offense", i, m/8.0);
	}
}

void rise_move()
{
    void self=getlocalvar("self");
    int index = getentityproperty(self, "playerindex");
    if(playerkeys(index, 0, "moveup"))
    {
        changeentityproperty(self, "velocity", 0, -0.5, 0);
    }
    else if(playerkeys(index, 0, "movedown"))
    {
        changeentityproperty(self, "velocity", 0, 0.5, 0);
    }
}

void magic1()
{
	void e;
	void self = getlocalvar("self");
	clearspawnentry();
	setspawnentry("name", "lightning1");
	e = spawn();
	//changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z"), getentityproperty(self, "a"));
	changeentityproperty(e, "position", openborvariant("xpos") + getindexedvar(11)/2, openborvariant("ypos") + 120, 0);
	changeentityproperty(e, "base", 0);
	changeentityproperty(e, "owner", self);
}

void magic2()
{
	void e;
	void self = getlocalvar("self");
	clearspawnentry();
	setspawnentry("name", "lightning2");
	e = spawn();
	changeentityproperty(e, "position", openborvariant("xpos")+getindexedvar(11)+20, getentityproperty(self, "z") + 10, getentityproperty(self, "a"));
	//changeentityproperty(e, "velocity", -3, 0, 0);
	changeentityproperty(e, "direction", 1);
	changeentityproperty(e, "owner", self);

	e = spawn();
	changeentityproperty(e, "position", openborvariant("xpos")-20, getentityproperty(self, "z") - 10, getentityproperty(self, "a"));
	//changeentityproperty(e, "velocity", 3, 0, 0);
	changeentityproperty(e, "direction", 0);
	changeentityproperty(e, "owner", self);
}

void magic3()
{
	void e;
	void self = getlocalvar("self");
	clearspawnentry();
	setspawnentry("name", "dummylightning");
	e = spawn();
	changeentityproperty(e, "position", openborvariant("xpos")+getindexedvar(11)/2, getentityproperty(self, "z"), getentityproperty(self, "a"));
	changeentityproperty(e, "base", getentityproperty(self, "base"));
	changeentityproperty(e, "owner", self);

}

void cast_magic()
{
    void self = getlocalvar("self");
    changeentityproperty(self, "mp", 0);
    int pot = getlocalvar("pot");
	if(pot >= 4)
	{magic3();}
	else if(pot >= 2) 
	{magic2();}
	else
	{magic1();}
    setlocalvar("pot", NULL()); // done, remove the variant
}

