#include	"data/scripts/vars/constants.h"	//Constants list.
#import	"data/scripts/com/ani0009.h"	//Animation switch wrapper.

void ani0012(int iAni, int iAni2)
{
	/*
	ani0012
	Damon Vaughn Caskey, based on Utunnel's in model script.
	2008_xx_xx
	~2011_03_28
	~2011_05_29

	Switch to one of two alternate animations based on opponent name and height difference.
	*/

	void vEnt		= getlocalvar("self");					//Caller.
	void vTarget	= getentityproperty(vEnt, "opponent");	//Caller's Target.
	int	 iH			= getentityproperty(vEnt, "height");
	int  iTH;
	char cTName;											//Target base name.

	if(!vTarget)											//No target?
	{
		vTarget = getentityproperty(vEnt, "grabbing");		//Use grapple defender.
	}

	if(vTarget)												//Target found?
	{
		iTH		=	getentityproperty(vTarget, "height");

		if ((iH/iTH) < 0.75)								//Caller less then 70% target's height?
		{						
			if (getentityproperty(vEnt, "animvalid", iAni))	//Animation valid?
			{
				if(checkrange(vEnt, vTarget, iAni))			//Target in range?
				{
					return ani0009(vEnt, iAni, -1);			//Perform ani1 and return.
				}
			}

			if (getentityproperty(vEnt, "animvalid", iAni2))//Animation valid?
			{
				if(checkrange(vEnt, vTarget, iAni2))		//Target in range?
				{
					return ani0009(vEnt, iAni2, -1);		//Perform ani2 and return.
				}
			}			
		}		
	}
}