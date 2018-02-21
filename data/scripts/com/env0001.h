#include "data/scripts/vars/constants"  //http://www.caskeys.com/dc/?p=1314#constants

int env0001(void vEnt, int iType, int iYPReq, float fPushX, float fPushY, float fPushZ, int iYSReq, float fSlideX, float fSlideY, float fSlideZ)
{
	/*
	env0001 - http://www.caskeys.com/dc/?p=1314#ani0009
	Damon Vaughn Caskey
	2011_04_11

    Environment effects. Simulate wind, water current, conveyor belts, ice, etc.

	vEnt:       Target entity.
	iType:      Type switch.
	iYPReq:     Y position vs. base requirement for push effect to apply.
                ~0+:    Entity Y position must be >= iYReq above its current base.
                ~-1:    Entity must be at base.
                ~-2:    Entity proportionately more affected as it rises above base.
    iYSReq:     Y position vs. base requirement for slide effect to apply.
                ~0+:    Entity Y position must be >= iYReq above its current base.
                ~-1:    Entity must be at base.
	*/

	if (!vEnt)
	{
		vEnt = getlocalvar("self");
	}

    if (getentityproperty(vEnt, "animvalid", iAni))			//Animation valid?
    {
        if (iType == -1)									//Type -1?
        {
            changeentityproperty(vEnt, "animation", iAni);	//Set animation with entity property.
        }
        else
        {
            performattack(vEnt, iAni, iType);				//Set animation with perform attack command.
        }
        return 1;											//Return 1.
    }
    return 0;
}

