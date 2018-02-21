#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

int jump0004(void vEnt, float fY, float fX, float fZ, int iJmp, int iIdle, int c, int d)
{
	/*
	jump0004
	Damon Vaughn caskey
	03172010
	Perform a toss based on direction command.

	vEnt:		Target entity.
	fY, fZ:	Toss velocities.
	a-d:		Expansion.
	*/
		
	int		iKRtH;
	int		iKLtH;
	int		iPI;

	if (!vEnt)
	{
		vEnt = getlocalvar("self");
	}

	iPI = getentityproperty(vEnt, "playerindex");

	iKRtH     = playerkeys(iPI, 0, "moveleft");									//Hold "Left".
    iKLtH     = playerkeys(iPI, 0, "moveright");								//Hold "Right".
	
	if(iKRtH)																	//Left pressed?
	{            
		fX = -fX;																//Set velocity left.
		changeentityproperty(vEnt, "direction", 0);								//Set facing left.
	}
	else if(iKLtH)																//Right pressed?
	{
		changeentityproperty(vEnt, "direction", 1);								//Set facing right.									
	}
	else
	{
		fX = 0;
	}
    
	changeplayerproperty(vEnt, "playkeys", FLAG_NONE);
	tossentity(vEnt, fY, fX, fZ);							//Apply velocity

	changeentityproperty(vEnt, "aiflag", "jumping", iJmp);
	changeentityproperty(vEnt, "aiflag", "idling", iIdle);
	changeentityproperty(vEnt, "takeaction", "common_jump");
}