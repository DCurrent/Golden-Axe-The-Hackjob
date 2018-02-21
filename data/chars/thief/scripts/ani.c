#include "data/scripts/vars/constants.h"

#import "data/scripts/com/ai0004.h"    //Get around walls.
#import "data/scripts/com/ai0005.h"    //Countdown to alternate animation.
#import "data/scripts/com/ai0006.h"    //Find way out of screen.
#import "data/scripts/com/soun0005.h"  //Stereo sound player.

void escape()
{
	void self = getlocalvar("self");
	void e;
	clearspawnentry();
	setspawnentry("name", "escthief");
	e = spawn();

	changeentityproperty(e, "position", getentityproperty(self, "x"), getentityproperty(self, "z"), getentityproperty(self, "a"));
	changeentityproperty(e, "base", getentityproperty(self, "base"));
	changeentityproperty(e, "map", getentityproperty(self, "map"));

	if(getlocalvar("lifespan")>3)
	{
		changeentityproperty(e, "animation", A_RESPAWN);
	}

	if(getentityproperty(self, "direction")==1)
	{
		changeentityproperty(e, "velocity", 3, 0, 0);
		changeentityproperty(e, "direction", 1);
	}
	else
	{
		changeentityproperty(e, "velocity", -3, 0, 0);
		changeentityproperty(e, "direction", 0);
	}
	killentity(self);
}

void steal()
{
	void self = getlocalvar("self");
	if(getentityproperty(self, "name")=="BlueThief")
	{
		void p = getglobalvar("pot0");
		if(p != NULL())
		{
			killentity(p);
			changeentityproperty(self, "maxhealth", getentityproperty(self, "maxhealth")+1);
			changeentityproperty(self, "health", getentityproperty(self, "maxhealth"));
			setglobalvar("pot0", NULL());
		}
		p = getglobalvar("pot1");
		if(p != NULL())
		{
			killentity(p);
			changeentityproperty(self, "maxhealth", getentityproperty(self, "maxhealth")+1);
			changeentityproperty(self, "health", getentityproperty(self, "maxhealth"));
			setglobalvar("pot1", NULL());
		}
	}
}

void runcheck(){

	void self = getlocalvar("self");
	if(getentityproperty(self, "z") < 1000 && getentityproperty(self, "z") >0)
	{
		int ls = getlocalvar("lifespan");
		if(getglobalvar("runanimal"))
		{
			ls = 15;
			setglobalvar("runanimal", NULL());
		}
		if(ls==NULL())
		{
			ls = 0;
		}
		else if(ls>15)
		{
			changeentityproperty(self, "animation", A_WALK);
		}
		else
		{
			ls++;
		}
		setlocalvar("lifespan", ls);
	}
}
