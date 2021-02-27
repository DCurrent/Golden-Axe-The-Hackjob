#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import	"data/scripts/com/ani0014.h"	//http://www.caskeys.com/dc/?p=1314#ani0014

void main()
{
	/*
	Damon V. Caskey
	2011_07_26 - Derived from previous parry code written for Fatal Fury Chronicles 
	authored sometime in 2010.

	If opponent's incoming attack is a Run Attack or Jump Attack and player blocks 
	with precise timing, cancel the engine's hit handling and perform a counter move.
	If the entity is AI controlled, do the same thing except checking for idle status 
	instead of block frame.
	*/
    
    void	vEnt		= getlocalvar("self");															//Calling entity.        
	int		iAtkID		= getlocalvar("attackid");														//Attack ID.
	void	vOther		= getlocalvar("other");															//Owner of incoming attack.
	int		iOAni		= getentityproperty(vOther, "animationid");										//Other's current animation.
	int		iAni		= getentityproperty(vEnt, "animationid");										//Current animation.
	int		iFrame		= getentityproperty(vEnt, "animpos");											//Current frame.
	int		iType		= getentityproperty(vEnt, "type");
	int		iDir;																						//Current facing.
	int		iODir		= getentityproperty(vOther, "direction");										//Others current facing.
	int		iIdle		= getentityproperty(vEnt, "aiflag", "idling");									//Caller idle flag.
	int		iBase		= getentityproperty(vEnt, "base");												//Caller base.
	float	fY			= getentityproperty(vEnt, "a");													//Caller height.
	float	fH;																							//Caller height above base.

	if(!getlocalvar("which") && (getentityproperty(vEnt, "hitbyid") != iAtkID))							//Unique attack?
	{		
			if(iOAni == A_RUNATK																		//Other using run attack or a jump attack? 
				|| iOAni == openborconstant("ANI_JUMPATTACK")
				|| iOAni == A_JUMPATK2
				|| iOAni == A_JUMPATK3
				|| iOAni == openborconstant("ANI_RUNJUMPATTACK"))
			{		

				fH = fY - iBase;

				if(iAni == A_BLOCK && iFrame < 2														//In second frame or below of block animation?
					|| ((iType == TYPE_ENEMY || iType == TYPE_NPC) && iIdle && fH < 5))						//Ai control, idle, and not in the air?														
				{	

					if(!iODir)
					{
						iDir = 1;
					}
					else
					{
						iDir = 0;
					}

					changeentityproperty(vEnt, "direction", iDir);										//Make sure caller is facing opponent.
					changeopenborvariant("lasthitc", 0);												//Skip engine's default hit routines.
					ani0014(vOther, A_FOLLOW14, 0, 1000, A_ATK2, 0, 400);								//Counter throw, or counter attack if opponent can't be grabbed.
				}
			}		
	}
		
	changeentityproperty(vEnt, "hitbyid", iAtkID);
}


