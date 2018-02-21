#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009

void ani0020(void vEnt, int iAni)
{
	/*
	ani0020 - http://www.caskeys.com/dc/?p=1314#ani0020
	Damon Vaughn Caskey
	2011_06_27

	Wrapper to perform animation when triggered by key script.

	vEnt:	Target entity.
	vAni:	Animation.
	*/

	int iMP;
	int iMPO;
	int iEC;
	int iET;
	int iHP;

	if(getentityproperty(vEnt, "animvalid", iAni))
	{

		iMP = getentityproperty(vEnt, "mp");
		iEC = getentityproperty(vEnt, "energycost", "cost", iAni);
		iMPO = getentityproperty(vEnt, "energycost", "mponly", iAni);
		//log("\n iMPO:" + iMPO);

		changeentityproperty(vEnt, "velocity", 0, 0, 0);	//Stop moving.
		changeplayerproperty(vEnt, "playkeys", FLAG_NONE);	//Clear key event.
		ani0009(vEnt, iAni, 0);								//Execute animation.

		if(iMPO == 2)
		{
			iHP = getentityproperty(vEnt, "health");
			changeentityproperty(vEnt, "health", iHP - iEC); 
			
			//log("\n hp:" + iHP);
			//log("\n HP:" + getentityproperty(vEnt, "health"));
		}
		else if(iMPO == 1)
		{
			changeentityproperty(vEnt, "mp", iMP - iEC); 
		}
	}
}