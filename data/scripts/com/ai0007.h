#include "data/scripts/vars/constants.h"
#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009

void ai0007(void vEnt, void vPar, int iXDis, int iAni, int iAni2, int c, int d, int e, int f)
{

    /*
    ai0007
    Damon V. Caskey, modified from Utunnels runaway().
    2012_01_30
    Switch velocity after attaining certain distance from parent.

	vPar:	Parent entity.
	vEnt:   Target entity. 
	a-f:	Expansion.
    */
	        
	float fPX;
	float fPY;
	float fPZ;
	float fX;
    float fZ;
    float fY;
    float fVX;
    float fVY;
    float fVZ;	
	int		iDir;
	int		iPDir;

	if(!vEnt)
	{
		vEnt = getlocalvar("self");
	}

	fX	= getentityproperty(vEnt, "x");
    fZ	= getentityproperty(vEnt, "z");
    fY	= getentityproperty(vEnt, "a");
    fVX	= getentityproperty(vEnt, "xdir");
    fVY	= getentityproperty(vEnt, "tossv");
    fVZ	= getentityproperty(vEnt, "zdir");

	if(!vPar)
	{
		vPar = getentityproperty(vEnt, "owner");
	}

	fPX		= getentityproperty(vPar, "x");
	iDir	= getentityproperty(vEnt, "direction");
	iPDir	= getentityproperty(vPar, "direction");

	//log("\n X: " + fX + " fPX: " + fPX);

	if(fVX > 0 && (fX - fPX) > iXDis && getentityproperty(vEnt, "animationid")==A_IDLE)
	{		
		changeentityproperty(vEnt, "direction", 0);
		//ani0009(vEnt, A_FOLLOW1, 0);
	}
	if(fVX < 0 && (fPX - fX) > iXDis && getentityproperty(vEnt, "animationid")==A_IDLE)
	{		
		changeentityproperty(vEnt, "direction", 1);
		//ani0009(vEnt, A_FOLLOW1, 0);
	}

	if(fVX > 0 && (fPX - fX) < 0 && getentityproperty(vEnt, "animationid")==A_FOLLOW1)
	{		
		changeentityproperty(vEnt, "direction", 0);
		//ani0009(vEnt, A_FOLLOW1, 0);
	}
	if(fVX < 0 && (fPX - fX) > 0 && getentityproperty(vEnt, "animationid")==A_FOLLOW1)
	{		
		changeentityproperty(vEnt, "direction", 1);
		//ani0009(vEnt, A_FOLLOW1, 0);
	}
	
	if(iDir != iPDir && checkrange(vEnt, vPar) || (iAni != NULL() && iAni != getentityproperty(vPar, "animationid")))
	{
		killentity(vEnt);
	}
}