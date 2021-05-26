#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/z_ani.c"
#import "data/scripts/com/ani0009.h"
#import "data/scripts/com/ani0019.h"
#import "data/scripts/com/ani0012.h"
#import "data/scripts/com/ani0017.h"
#import "data/scripts/com/ani0018.h"
#import "data/scripts/com/bind0003.h"
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/bind0010.h"
#import "data/scripts/com/bind0014.h"
#import "data/scripts/com/bind0018.h"
#import "data/scripts/com/dama0004.h"
#import "data/scripts/com/dir0001.h"
#import "data/scripts/com/jump0003.h"
#import "data/scripts/com/paus0001.h"
#import "data/scripts/com/proj0003.h"
#import "data/scripts/com/seal0001.h"		// Place a seal & sealtime on target.
#import "data/scripts/com/stal0001.h"		// Place a stalltime on target.
#import "data/scripts/com/soun0005.h"


#import "data/scripts/com/dc_ai_avoid_jump_attack.c"        //Avoid jump attacks.

#include "data/scripts/dc_disney/main.c"
#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_keys/main.c"

void suicide()
{
    int i;
    void p;
    for(i=0; i<3; i++)
    {
        p = getplayerproperty(i, "ent");
        if(p!=NULL())
        {
            if(getentityproperty(p, "name")=="Alex_")
            {
                killentity(getlocalvar("self"));
                setglobalvar("al_npc", NULL());
                break;
            }
        }
    }

    changeentityproperty(getlocalvar("self"), "subject_to_screen", 1);

}

void summon(void vModel, int iMap)
{

	/*
	summ0002
	Damon Vaughn caskey
	2010_03_17
	Spawn a creature to ride (or get stolen, heh). Attempts to spawn close to
	center of playing area. Otherwise spawns on top of owner. Code is a bit messy,
	but it isn't used often.
	*/

	void	vSpawn;											//Spawn placeholder.
	void	vSelf	= getlocalvar("self");
	int		iX		= openborvariant("hresolution")/2;		//X center of screen.
	int		iZ		= openborconstant("player_max_z");		//Max Z cord.
	int		iMZ		= openborconstant("player_min_z") + 10;	//Minimum Z cord.
	int		iBase	= getentityproperty(vSelf, "base");

	do
	{
		--iZ;									//Decrement iZ.
	}
	while (checkwall(iX, iZ-20) <= iBase && iZ > iMZ);	//Keep going until at playfield boundry or close to a wall.

	//If proposed location is in a pit or a platform intensive area, just spawn at owner's location.
	if(checkhole(iX, iZ) || checkwall(iX, iZ-20) >= 5000)
	{
		iX = getentityproperty(vSelf, "x") - openborvariant("xpos");
		iZ = getentityproperty(vSelf, "z");
	}

	// vSpawn = summ0001(vModel, vModel,    0,          0,     iX,      0,     iZ,        0,        0,          0,         0);
	         //summ0001(vModel, vAlias, iMap, int iBlend, int iX, int iY, int iZ, int iDir, int iAni, int iFrame, int iKill)

	//bind0015(vSpawn, "effe0001", "effe0001", iMap, 1, 0, 0, 1, 0, A_FOLLOW1, 0, 1);
	soun0005(vSpawn, SND_EFF5, 0, 1, 0, 0);

}

void cast_magic()
{
    void self = getlocalvar("self");
    changeentityproperty(self, "mp", 0);
    int pot = getlocalvar("pot");
	if(pot >= 4)
	{
		summon("Red_Dragon", 13);
	}
	else if(pot >= 2)
	{
		summon("Blue_Dragon", 12);
	}
	else
	{
		summon("Chickenlegs", 11);
	}
    setlocalvar("pot", NULL());		//done, remove the variant
}
