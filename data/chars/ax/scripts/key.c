#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009
#import "data/scripts/com/bind0014.h"		//http://www.caskeys.com/dc/?p=1314#bind0014
#import "data/scripts/com/bind0023.h"		//http://www.caskeys.com/dc/?p=1314#bind0023
#import "data/scripts/com/soun0005.h"		//http://www.caskeys.com/dc/?p=1314#soun0005
#import "data/scripts/com/path0002.h"		//http://www.caskeys.com/dc/?p=1314#path0002

void main(){

	/*
    Damon Vaughn Caskey
    06/25/2009
    Capture keystrokes and perform actions accordingly.
    */

    int     iPlIndex    = getlocalvar("player");											//Player index.
    void    vSelf       = getplayerproperty(iPlIndex, "entity");							//Get calling entity.
    void	vTar;
	int     iFIdl       = getentityproperty(vSelf, "aiflag", "idling");						//Self idling?
   	int     iKAtk		= playerkeys(iPlIndex, 1, "attack");								//Press "Attack".        
	int     iKDnH       = playerkeys(iPlIndex, 0, "movedown");								//Hold "Down".
	int     iKLtH       = playerkeys(iPlIndex, 0, "moveleft");								//Hold "Left".
	int     iKRtH       = playerkeys(iPlIndex, 0, "moveright");								//Hold "Right".
	int		iAni		= getentityproperty(vSelf, "animationid");							//Current animation.
	int		iBase;
	float	fY;
	int		iH;
	int		iPos;
	int		iLnd;
	int		iDrop;
	int		iAni;

	if(iKAtk)
	{
		if(iAni == A_FSPECIAL11)
		{
			iPos = getentityproperty(vSelf, "animpos");
			iLnd = getentityproperty(vSelf, "landframe", "frame", iAni);			

			if(iPos < iLnd)
			{
				if(iKDnH)
				{					
					ani0009(vSelf, A_FOLLOW8, -1);
				}
				else
				{
					ani0009(vSelf, A_FOLLOW9, -1);					
				}
				changeplayerproperty(vSelf, "playkeys", 0);										//Clear key event.
			}
		}
		else if(iAni == A_RUN)
		{
			/*
			Tackle
			*/
			iPos = getentityproperty(vSelf, "animpos");
			iLnd = getentityproperty(vSelf, "landframe", "frame", iAni);

			if(iKLtH || iKRtH)																	//Holding left or right?
			{
				vTar	= findtarget(vSelf, A_FOLLOW18, 100);									//Look for target in range of grab.
								
				if(vTar)																		//Valid target?
				{
					iAni	= getentityproperty(vTar, "animationid");							//Animation ID.
					iDrop   = getentityproperty(vTar, "aiflag", "drop");						//Drop status.
					iBase	= getentityproperty(vTar, "base");
					fY		= getentityproperty(vTar, "a");
					iH		= fY - iBase;

					if(iAni != openborconstant("ANI_FOLLOW10")															//Not being thrown already?
						&& iAni != A_RISE														//Not getting up?
						&& iAni != A_RISEATK													//Not getting up?
						&& (!iDrop || iH >= 10))												//Either not falling or falling and more then 10 pixels from floor?
					{	
						/*
						Can be grabbed? Can't use nograb flag as we want to catch falling targets too 
						and OpenBOR applies nograb flag by default. Instead we check for riding on an animal. 
						Otherwise, anything that won't crash (i.e. has thrown poses) is fair game.
						*/
						if(!getentityproperty(vTar, "animal") && getentityproperty(vTar, "animvalid", openborconstant("ANI_FOLLOW10")))
						{							
							bind0014(vTar, 0);													//Initialize bind variable.	
							ani0009(0, A_FOLLOW18, 0);											//Apply animation.
							changeentityproperty(vSelf, "velocity", 0, 0, 0);
							changeplayerproperty(vSelf, "playkeys", 0);							//Clear key event.							
						}
					}
				}
			}

		}
		else if(iAni == A_JUMP
			|| iAni == A_RUNJUMP)
		{
			/*
			Air to Air throw (Ax Destroyer). 
			*/
			if(iKLtH || iKRtH)																	//Holding left or right?
			{				
				vTar	= findtarget(vSelf, A_FOLLOW12, 100);									//Look for target in range of grab.
								
				if(vTar)																		//Valid target?
				{
					iBase	= getentityproperty(vTar, "base");
					fY		= getentityproperty(vTar, "a");
					iH		= fY - iBase;
					iAni	= getentityproperty(vTar, "animationid");

					if(iAni != openborconstant("ANI_FOLLOW10") 
						&& iH >= 5)																//More then 5 pixels from ground and not being thrown already?
					{	
						/*
						Can be grabbed? Can't use nograb flag as we want to catch falling targets too 
						and OpenBOR applies nograb flag by default. Instead we check for riding on an animal. 
						Otherwise, anything that won't crash (i.e. has thrown poses) is fair game.
						*/
						if(!getentityproperty(vTar, "animal") && getentityproperty(vTar, "animvalid", openborconstant("ANI_FOLLOW10")))
						{
							bind0014(vTar, 0);													//Initialize bind variable.	
							ani0009(0, A_FOLLOW12, -1);											//Apply animation.
							changeentityproperty(vSelf, "velocity",0,0,0);
							changeplayerproperty(vSelf, "playkeys", 0);							//Clear key event.
						}
					}
				}

				vTar	= findtarget(vSelf, A_FOLLOW15, 100);									//Look for target in range of grab.
								
				if(vTar)																		//Valid target?
				{
					iBase	= getentityproperty(vTar, "base");
					fY		= getentityproperty(vTar, "a");
					iH		= fY - iBase;
					iDrop   = getentityproperty(vTar, "aiflag", "drop");						//Drop status.
					iAni	= getentityproperty(vTar, "animationid");

					if(iAni != openborconstant("ANI_FOLLOW10")
						&& iAni != A_RISE
						&& iAni != A_RISEATK
						&& iH < 5 
						&& !iDrop)																//Less then 5 pixels from ground, not falling, not rising, and not being thrown already?
					{	
						/*
						Can be grabbed? Can't use nograb flag as we want to catch falling targets too 
						and OpenBOR applies nograb flag by default. Instead we check for riding on an animal. 
						Otherwise, anything that won't crash (i.e. has thrown poses) is fair game.
						*/
						if(!getentityproperty(vTar, "animal") && getentityproperty(vTar, "animvalid", openborconstant("ANI_FOLLOW10")))
						{
							bind0014(vTar, 0);													//Initialize bind variable.	
							ani0009(0, A_FOLLOW15, -1);											//Apply animation.
							changeplayerproperty(vSelf, "playkeys", 0);							//Clear key event.
						}
					}
				}
			}
		}
		else if(iAni == A_FOLLOW7
			|| iAni == A_FOLLOW8
			|| iAni == A_FOLLOW9
			|| iAni == A_FOLLOW13)
		{
			changeplayerproperty(vSelf, "playkeys", 0);
		}
	}
}
