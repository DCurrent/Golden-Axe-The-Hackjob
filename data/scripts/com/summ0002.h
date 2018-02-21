#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0015.h"		//http://www.caskeys.com/dc/?p=1314#bind0015	

void summ0002(void vModel, int iMap)
{

	/*
	summ0002
	Damon Vaughn caskey
	2010_03_17
	
	Spawn a creature to ride (or get stolen, heh). Attempts to spawn close to
	center of playing area. Otherwise spawns on top of owner. A bit messy, 
	but it isn't used often.

	vModel: Model to spawn.
	iMap:	Initial color map.
	*/

	void	vSpawn;											//Spawn placeholder.
	void	vSelf	= getlocalvar("self");					
	int		iX		= openborvariant("hresolution")/2;		//X center of screen.
	int		iZ		= openborconstant("player_max_z");		//Max Z cord.
	int		iMZ		= openborconstant("player_min_z") + 10;	//Minimum Z cord.
	int		iBase	= getentityproperty(vSelf, "base");	

	do 
	{		
		--iZ;												//Decrement iZ.		
	}
	while (checkwall(iX, iZ-20) <= iBase && iZ > iMZ);		//Keep going until at playfield boundry or close to a wall.

	//If proposed location is in a pit or a platform intensive area, just spawn at owner's location. 
	if(checkhole(iX, iZ) || checkwall(iX, iZ-20) >= 5000)
	{
		iX = getentityproperty(vSelf, "x") - openborvariant("xpos");
		iZ = getentityproperty(vSelf, "z");
	}

	vSpawn = summ0001(vModel, vModel, 0, 0, iX, 0, iZ, 0, 0, 0, 0);
	bind0015(vSpawn, "effe0001", "effe0001", iMap, 1, 0, 0, 1, 0, A_FOLLOW1, 0, 1);
	soun0005(vSpawn, SND_EFF5, 0, 1, 0, 0);

}