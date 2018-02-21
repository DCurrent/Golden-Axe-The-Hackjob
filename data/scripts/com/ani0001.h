#include    "data/scripts/vars/constants.h"

#import    "data/scripts/com/ani0009.h"
#import    "data/scripts/com/keyd0001.h"
#import    "data/scripts/com/rnd0001.h"

void ani0001(int iRType, void iAni1, int iFrame1, void iAni2, int iFrame2, int iCmd, int iAIChance, int iHPCost, int iMPCost){

    /*
	ani001
	Damon Vaughn Caskey
	2007_05_11
	~2011_03_27

	Switch calling entity to new animation and frame if command (or random chance if AI controlled) and status requirements are met.

    iRType:     Type exception?
	vAni1:      Desired animation.
	iFrame:     Desired frame.
	iCmd:       Required key command when entity is under player control.
    iAIChance:  Chance of animation change under AI control. 100 = always, 1 = almost never.
    iMPCost:    Required MPCost.
    iHPCost:    Required HPCost.
    */

    void    vSelf   = getlocalvar("self");                                          //Calling entity.
    int     iType   = getentityproperty(vSelf, "type");                             //Caller type.
    int     iHP     = getentityproperty(vSelf, "health");                           //Caller current HP.
    int     iMP     = getentityproperty(vSelf, "mp");                               //Caller current MP.
    int     iKey    = getentityproperty(vSelf, "playerindex");

    changeplayerproperty(vSelf, "playkeys", 0);                                     //Clear key event.

    //Type exception?
    if (iRType && iRType != iType)
    {
        return;
    }

    //Player or AI control?
    if (iType == TYPE_PLAYER)
    {
        if (iCmd)                                                                   //Command required?
        {
            if (keyd001(iKey, 0, vSelf)!= iCmd)                                     //Command no match?
            {
                return -1;                                                          //Exit and return "failed".
            }
        }
    }
    else
    {
        if (rnd0001(0, 100, 0, 0, 0, 0) > iAIChance)                                //Random 1 thru 100 is > then AIChance?
        {
            return-1;                                                               //Exit and return "failed".
        }
    }

	if (iMPCost < 0)                                                                //if iMP is < 0, evaulate if iMP is less then iMPCost. Otherwise, evaulate if iMP is above.
    {
        if (-iMP < iMPCost)
        {
            if (iAni2)                                                              //If provided, play "failed" animation.
            {
                ani0009(vSelf, iAni2, -1);
            }
            return -1;                                                              //Exit and return "failed".
        }
        iMPCost = 0;
    }
    else if(iMPCost > 0)
    {
		if (iMPCost > iMP)
        {
            if (iAni2)                                                              //If provided, play "failed" animation.
            {
               ani0009(vSelf, iAni2, -1);
            }
            return -1;                                                              //Exit and return "failed".
        }
    }

	/*
	If Cost is a negative number, we are checking for resource BELOW Cost and not above. To save a paremeter we differentiate
	by passing a negative Cost and reversing evaluation.
	*/
    if (iHPCost < 0)
    {
        if (-iHP < iHPCost)                                                         //If iHP is less then iHPCost (same as if Resource < Cost if positive) runalternate and or exit.
        {
            if (iAni2)                                                              //Play "failed" animation.
            {
                ani0009(vSelf, iAni2, -1);
            }
            return -1;                                                              //Exit and return "failed".
        }
        iHPCost = 0;
    }
    else if(iHPCost > 0)
    {
        if (iHPCost > iHP)
        {
            if (iAni2)                                                              //If provided, play "failed" animation.
            {
                ani0009(vSelf, iAni2, -1);
            }
            return -1;                                                              //Exit and return "failed".
        }
    }

    changeentityproperty(vSelf, "health", iHP - iHPCost);                           //Apply HP cost.
    changeentityproperty(vSelf, "mp", iMP - iMPCost);                               //Apply MP cost.

    if (iAni1)                                                                      //All checks passed?
    {
        ani0009(vSelf, iAni2, -1);                                                  //Switch to primary alternate animation.
    }
	changeplayerproperty(vSelf, "playkeys", 0);										//Clear key event.
}
