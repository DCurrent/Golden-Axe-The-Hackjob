#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bloc0002.h"		//http://www.caskeys.com/dc/?p=1314#bloc0002	
#import "data/scripts/com/soun0005.h"		//http://www.caskeys.com/dc/?p=1314#soun0005

void hit0004(void vEnt)
{
	/*
	hit0004
	Damon Vaughn Caskey
	2012_02_04
	
	Primary on hit script. Moved here from z_hit to be called by other functions.
	*/
		
    void    vDef		= getlocalvar("damagetaker");
    int		iBloc		= getlocalvar("blocked");	
	int		iProj;
	int		iAIDrop;
	int		iDrop;
	int		iKnock;	
	int		iType;
	int		iAni;

	if(!vEnt)
	{
		vEnt = getlocalvar("self");
	}
	
	if(iBloc)																			//Attack blocked?
	{
        //bloc0002(vDef, 1);                                                            //Run block function.
    }
	else
	{
		iProj	= getentityproperty(vEnt, "projectile");								//Get projectile flag.
		iAIDrop = getentityproperty(vEnt, "aiflag", "drop");							//Get AI Drop flag.
		iAni	= getentityproperty(vEnt, "animationid");								//Get animation.

		if(!iAIDrop && !iProj && iAni != A_FOLLOW10)									//Not falling and has a sndcnt?
		{
			iDrop	= getlocalvar("drop");
			iKnock	= getentityproperty(vDef, "knockdowncount");

			if(iDrop > iKnock)															//Opponent will be knocked down?
			{
				iType = getentityproperty(vEnt, "type");

                if (iType == openborconstant("TYPE_PLAYER"))							//Player type?
                {
					soun0005(vEnt, VOI_BTL, -1, 0.5, 0, 0);								//Battle cry (50%).
				}
                else
                {
                    soun0005(vEnt, VOI_BTL, -1, 1, 0, 0);								//Battle cry.
                }			
			}
		}
	}
}
