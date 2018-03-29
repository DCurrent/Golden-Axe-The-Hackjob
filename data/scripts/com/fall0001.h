#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0005.h"
#import "data/scripts/com/bind0020.h"
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/effe0001.h"
#import "data/scripts/com/jump0001.h"

void fall0001(){

    //Primary falling function.

    void    vSelf       = getlocalvar("self");                                      //Calling entity.
    int     iType       = getlocalvar("attacktype");                                //Incoming attack type.
    float   fTossX      = getentityvar(vSelf, IDXE_TOSSX);								//Toss X
    float   fTossY      = getentityvar(vSelf, IDXE_TOSSY);								//Toss Y
    float   fTossZ      = getentityvar(vSelf, IDXE_TOSSZ);								//Toss Z
    int     iAni        = getentityvar(vSelf, IDXE_NEXTANI);                             //Animation.
    int     iHeight     = getentityproperty(vSelf, "height");                       //Caller height.
    int     iBase       = getentityproperty(vSelf, "base");                         //Caller base (platform height).
    int     iHitY;                                                                  //Last hit height.


    if (iType == openborconstant("ATK_BURN"))															//Burn attack?
    {
        effe0001(MAP_BURN);                                                          //Set effect.
    }
    else if (iType == ATK_SHOCK)													//Shock attack?
    {
		effe0001(MAP_SHOCK);                                                         //Set effect.
    }
    else if (iType == ATK_2)														//Attack Type 2?
    {
		/*
		Using auto set conditionals? Collapse or fall.
		*/
		if(CONF_SETFALL)
		{
			if ((iHeight - iBase)<=1)                                               //Caller 1 or less from the ground?
			{
				changeentityproperty(vSelf, "velocity", 0,0,0);                     //Stop moving (fall2 is collapse in place)
			}
			else
			{
				changeentityproperty(vSelf, "animation", A_FALL);					//Fall normally since caller was in the air.
			}
		}
    }
    else
    {
		/*
		Using auto set conditionals? Sweep or fall.
		*/
		if(CONF_SETFALL)
		{
			iHitY   = openborvariant("lasthita");                                   //Get last hit height.

			if (iHitY && iHitY < iHeight * 0.3 && iAni != AC_DEFPOSE)                  //Knockdown was from low and and self not being thrown?
			{
				changeentityproperty(vSelf, "animation", AC_SWEPT);                    //Put into sweep animation.
			}
		}
    }

    ///////////
    if (iAni)                                                                       //Animation switch request?
    {
        changeentityproperty(vSelf, "animation", iAni);                             //Switch animations.
        setentityvar(vSelf, IDXE_NEXTANI, NULL());                                       //Clear animation switch variable.
    }

    bind0005(getentityproperty(vSelf, "opponent"), 2);                              //Run bind0005.

    //////////

    if (fTossX || fTossY || fTossZ)                                                 //Any toss values?
    {
        if(!fTossX) fTossX = 0;                                                     //If null, set 0.
        if(!fTossY) fTossY = 0;                                                     //If null, set 0.
        if(!fTossZ) fTossZ = 0;                                                     //If null, set 0.

        jump0001(fTossY, fTossX, fTossZ);                                           //Toss caller.
        setentityvar(vSelf, IDXE_TOSSX, NULL());                                        //Clear toss value.
        setentityvar(vSelf, IDXE_TOSSY, NULL());                                        //Clear toss value.
        setentityvar(vSelf, IDXE_TOSSZ, NULL());                                        //Clear toss value.
    }

	bind0020(vSelf);																//Restablish binds if grappled by another entity.

}
