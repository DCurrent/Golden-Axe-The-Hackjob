
#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009
#import "data/scripts/com/ani0020.h"		//http://www.caskeys.com/dc/?p=1314#ani0020
#import "data/scripts/com/debu0001.h"		//http://www.caskeys.com/dc/?p=1314#debu0001
#import "data/scripts/com/soun0005.h"		//http://www.caskeys.com/dc/?p=1314#soun0005

void main(){

	/*
    Damon Vaughn Caskey
    06/25/2009
    Capture keystrokes and perform actions accordingly.
    */

    int     iPlIndex    = getlocalvar("player");											//Player index.
    void    vEnt		= getplayerproperty(iPlIndex, "entity");							//Get calling entity.
    int     iFIdl       = getentityproperty(vEnt, "aiflag", "idling");						//Self idling?
    int     iFAtk       = getentityproperty(vEnt, "aiflag", "attacking");					//Self attacking (freespecial, jumpattack, follow, or attack)?
    int     iFJmp       = getentityproperty(vEnt, "aiflag", "jumping");						//Self jumping?
	int		iFPain		= getentityproperty(vEnt, "aiflag", "inpain");						//Self in pain?
    int     iXDir       = getentityproperty(vEnt, "xdir");									//X velocity.
    int     iTime       = openborvariant("elapsed_time");									//Current time.
    int     iAni, iPos, iLnd;																//Current animation, frame, and landframe.
    int     iFrame;																			//Current animation frame.
    float   fTossV;																			//Vertical speed.
    float   fXDir;																			//Horizontal speed.
    float   fZDir;																			//Z axis speed.
    void    vTarget;																		//Opponent.
	int		iMP;
	int		iEC;

	int     iKUpH       = playerkeys(iPlIndex, 0, "moveup");								//Hold "Up".
    int     iKDnH       = playerkeys(iPlIndex, 0, "movedown");								//Hold "Down".
	int     iKLtH       = playerkeys(iPlIndex, 0, "moveleft");								//Hold "Left".
    int     iKRtH       = playerkeys(iPlIndex, 0, "moveright");								//Hold "Right".
    int     iKAtkH      = playerkeys(iPlIndex, 0, "attack");								//Hold "Attack".
    int     iKAtk2H     = playerkeys(iPlIndex, 0, "attack2");								//Hold "Attack2".
    int     iKAtk3H     = playerkeys(iPlIndex, 0, "attack3");								//Hold "Attack3".
    int     iKAtk4H     = playerkeys(iPlIndex, 0, "attack4");								//Hold "Attack4".
    int     iKJmpH      = playerkeys(iPlIndex, 0, "jump");									//Hold "Jump".
    int     iKSpH       = playerkeys(iPlIndex, 0, "special");								//Hold "Special".
	int     iKStH       = playerkeys(iPlIndex, 0, "start");									//Hold "Start".
	int     iKSsH       = playerkeys(iPlIndex, 0, "SCREENSHOT");							//Hold "Screenshot".
    int     iKEscH      = playerkeys(iPlIndex, 0, "esc");									//Hold "esc".
	int     iKAnyH      = playerkeys(iPlIndex, 0, "ANYBUTTON");								//Hold any key.

	int     iKUp        = playerkeys(iPlIndex, 1, "moveup");								//Press "Up".
    int     iKDn        = playerkeys(iPlIndex, 1, "movedown");								//Press "Down".
    int     iKLt        = playerkeys(iPlIndex, 1, "moveleft");								//Press "Left".
    int     iKRt        = playerkeys(iPlIndex, 1, "moveright");								//Press "Right".
	int     iKAtk       = playerkeys(iPlIndex, 1, "attack");								//Press "Attack".
	int     iKAtk2      = playerkeys(iPlIndex, 1, "attack2");								//Press "Attack2".
    int     iKAtk3      = playerkeys(iPlIndex, 1, "attack3");								//Press "Attack3".
    int     iKAtk4      = playerkeys(iPlIndex, 1, "attack4");								//Press "Attack4".
	int     iKJmp       = playerkeys(iPlIndex, 1, "jump");									//Press "Jump".
    int     iKSp        = playerkeys(iPlIndex, 1, "special");								//Press "Special".
    int     iKSt        = playerkeys(iPlIndex, 1, "start");
	int     iKSs        = playerkeys(iPlIndex, 1, "SCREENSHOT");							//Press "Screenshot".
	int     iKEsc       = playerkeys(iPlIndex, 1, "esc");									//Press "escape".
/*  int     iKAny       = playerkeys(iPlIndex, 1, "ANYBUTTON");								//Press any key.

    int     iKUpR       = playerkeys(iPlIndex, 2, "moveup");								//Release "Up".
    int     iKDnR       = playerkeys(iPlIndex, 2, "movedown");								//Release "Down".
*/  int     iKLtR       = playerkeys(iPlIndex, 2, "moveleft");								//Release "Left".
    int     iKRtR       = playerkeys(iPlIndex, 2, "moveright");								//Release "Right".
/*  int     iKAtkR      = playerkeys(iPlIndex, 2, "attack");								//Release "Attack".
    int     iKAtk2R     = playerkeys(iPlIndex, 2, "attack2");								//Release "Attack2".
    int     iKAtk3R     = playerkeys(iPlIndex, 2, "attack3");								//Release "Attack3".
    int     iKAtk4R     = playerkeys(iPlIndex, 2, "attack4");								//Release "Attack4".
*/  int     iKJmpR      = playerkeys(iPlIndex, 2, "jump");									//Release "Jump".
/*  int     iKSpR       = playerkeys(iPlIndex, 2, "special");								//Release "Special".
    int     iKStR       = playerkeys(iPlIndex, 2, "start");									//Release "Start".
    int     iKSsR       = playerkeys(iPlIndex, 2, "SCREENSHOT");							//Release "Screenshot".
    int     iKAnyR      = playerkeys(iPlIndex, 2, "ANYBUTTON");								//Release any key.

*/

	 //debu0001(vEnt, iKUp, iKDn, iKLt, iKRt, iKAtk, iKAtk2, iKAtk3, iKAtk4, iKSt, iKSs, iKEsc, iKAtkH, iKAtk2H, iKAtk3H, iKAtk4H, iKSp, iKJmpH, iKEscH);
/*

	if (iKSp)
    {
        setentityvar(vEnt, IDXE_KEY1SP, iTime);													//Store last press of special key.
    }
	else if(iKAtk)
    {
        setentityvar(vEnt, IDXE_KEY1AT, iTime);													//Store last press of Attack key.
    }
	*/

	if (iFIdl)																				//Idle?
    {
		//Backstep.
		if(iKSp)
		{
			if(iKDnH)
			{
				ani0020(vEnt, AC_BACKSTEP);
			}
		}

		//GA Magic. If insuffciant energy, cancel key event and play "can't" sound.
		if(iKAtk2)
		{
			if(getentityproperty(vEnt, "animvalid", A_FSPECIAL8))
			{
				iMP = getentityproperty(vEnt, "mp");
				iEC = getentityproperty(vEnt, "energycost", "cost", A_FSPECIAL8);

				if(iMP < iEC)																//Cost more then current MP?
				{
					soun0005(vEnt, VOI_CNT, -1, 1, 0, 0);									//Fail sound.
					changeplayerproperty(vEnt, "playkeys", FLAG_NONE);								//Clear key event.
				}
			}
		}
    }
    else if (iFJmp)																			//Jumping?
    {
    }
    else if (iFAtk)																			//Attacking?
    {
    }
	else if (iFPain)
	{
		if(iKSp)
		{
			ani0020(vEnt, A_SPECIAL);
		}
	}
}





