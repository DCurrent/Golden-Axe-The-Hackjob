#include "data/scripts/vars/constants.h"
#import "data/scripts/com/ani0009.h"

void main()
{
	void vEnt	= getlocalvar("self");
	void vPar	= getentityproperty(vEnt, "owner");
	int	iAni	= getentityproperty(vPar, "animationid");

	if(iAni == A_FSPECIAL3)
	{
		ani0009(vPar, openborconstant("ANI_FOLLOW12"), -1);
	}
}