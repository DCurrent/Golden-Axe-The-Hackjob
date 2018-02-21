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
	int     iKJmp		= playerkeys(iPlIndex, 1, "jump");									//Press "Jump".        
	int     iKDnH       = playerkeys(iPlIndex, 0, "movedown");								//Hold "Down".
	int     iKLtH       = playerkeys(iPlIndex, 0, "moveleft");								//Hold "Left".
	int     iKRtH       = playerkeys(iPlIndex, 0, "moveright");								//Hold "Right".
	int		iAni		= getentityproperty(vSelf, "animationid");							//Current animation.
	float	fY			= getentityproperty(vSelf, "a");
	int		iPos;
	int		iLnd;
	int		iDrop;
	int		iAniT;
	int     iBT;
	int		iHT;
	float   fYT;
	int	iX	= getentityproperty(vSelf, "x");               	//Get self X location.
	int	iZ	= getentityproperty(vSelf, "z");               	//Get self Z location.
	int	iB	= getentityproperty(vSelf, "base");        	//Get self Base.
	int	iWall;                                                  //Wall height.
	int	iHole;                                                  //Hole flag

	int	iDir = getentityproperty(vSelf, "direction");

	if(iKAtk)
	{		
		if(iAni == A_RUNJUMP)
		{			
			if(iKLtH || iKRtH)																	//Holding left or right?
			{					
				if (!iDir && iKLtH)																//Facing left?
				{ 
					iWall = checkwall(iX-1, iZ);												//Get wall.
				}
				else if(iDir && iKRtH)
				{
					iWall = checkwall(iX+1, iZ);												//Get wall.
				}

				if(iWall > fY)																		
				{				
					ani0009(vSelf, A_FOLLOW10, 0);
					changeentityproperty(vSelf, "velocity", 0, 0, 0);							//Stop all movement.
					changeentityproperty(vSelf, "aiflag", "idling", 0);
					changeentityproperty(vSelf, "aiflag", "jumping", 0);
					changeplayerproperty(vSelf, "playkeys", 0);

				}				
			}			
		}	
		else if(iAni == A_JUMPLAND)
		{
			changeplayerproperty(vSelf, "playkeys", 0);
		}

	}
	
	if(iKJmp)
	{
		/*
		~2012_03_01
		This code block is really crude, but it does the job for now. Will need to come back and optimise it a bit and get rid of some repeating evaluations.
		*/

		/*
		Pogo Jump
		*/
				
		vTar	= findtarget(vSelf, AC_DBJMPP, 100);										//Look for target in range of grab.
								
		if(iKJmp && (iAni == A_JUMP || iAni == A_RUNJUMP || iAni == AC_DBJMP || iAni == AC_DBJMPW || iAni == AC_DBJMPP) && vTar)																		//Valid target?
		{
			
			if(iAniT != AC_DEFPOSE
				&& iAniT != A_RISE
				&& iAniT != A_RISEATK)													//Not falling, not rising, and not being thrown already?
				
			{						
				bind0014(vTar, 0);														//Initialize bind variable.	
				ani0009(0, AC_DBJMPP, -1);													//Apply animation.
				changeplayerproperty(vSelf, "playkeys", 0);								//Clear key event.
				iKJmp = 0;																//Reset jump key variable so subsequent evaluations will fail.
				vTar = NULL();						
			}
		}

		/*
		Wall jump
		*/
		if(iKJmp && (iAni == A_JUMP || iAni == A_RUNJUMP || iAni == AC_DBJMP || iAni == AC_DBJMPP) && fY-iB < 150)			//In jumping animation and less than 150 from base?
		{
			if(iKLtH || iKRtH)																	//Holding left or right?
			{					
				if (!iDir && iKLtH)																//Facing left?
				{ 
					iWall = checkwall(iX-1, iZ);												//Get wall.
				}
				else if(iDir && iKRtH)
				{
					iWall = checkwall(iX+1, iZ);												//Get wall.
				}

				if(iWall > fY)																		
				{				
					ani0009(vSelf, AC_DBJMPW, 0);
					changeentityproperty(vSelf, "velocity", 0, 0, 0);							//Stop all movement.
					changeentityproperty(vSelf, "aiflag", "idling", 0);
					changeentityproperty(vSelf, "aiflag", "jumping", 0);
					changeplayerproperty(vSelf, "playkeys", 0);
					iKJmp = 0;																	//Reset jump key variable so subsequent evaluations will fail.
				}				
			}	
		}

		/*
		Double Jump
		*/
		if(iKJmp && (iAni == A_JUMP || iAni == A_RUNJUMP || iAni == AC_DBJMPW || iAni == AC_DBJMPP) && fY-iB < 150)
		{		

			tossentity(vSelf, getentityproperty(vSelf, "jumpheight")*0.85, 0.1, 0);
			ani0009(vSelf, AC_DBJMP, -1);
			changeplayerproperty(vSelf, "playkeys", 0);
			iKJmp = 0;																			//Reset jump key variable so subsequent evaluations will fail.
		}
	}	
}
