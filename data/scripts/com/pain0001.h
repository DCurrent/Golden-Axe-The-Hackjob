#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/com/ani0009.h"
#import "data/scripts/com/bind0005.h"
#import "data/scripts/com/bind0020.h"
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/effe0001.h"

void pain0001(){

    void    vSelf       = getlocalvar("self");                                      //Calling entity.
    int     iAni        = getentityproperty(vSelf, "animationid");                  //Pain animation.
    int     iHeight;                                                                //Caller height.
    int     iHitY;                                                                  //Hit Y.
    int     iNAni       = getentityvar(vSelf, "dc_next_animation_id");                             //Next animation request.
	int		iPainAni;																//Final animation to set.

    if (iAni == A_BURNPAIN)                                                         //Burn attack?
    {
        effe0001(MAP_BURN);                                                          //Set effect.
    }
    else if (iAni == A_SHOCKPAIN)                                                   //Shock attack?
    {
		effe0001(MAP_SHOCK);                                                         //Set effect.
    }
    else if (iAni == A_GRABBED)                                                     //Grab?
    {
    }
    else                                                                            //Normal attack#?
    {
		/*
        Hit height based pain animations.
        */
        if(CONF_SETPAIN)
        {            
            iHitY   = openborvariant("lasthita");                                   //Get hit Y.
            iHeight = getentityproperty(vSelf, "height");                           //Get caller height.

            if (iHitY < iHeight * 0.75)                                             //Hit below 75% of height?
            {
                changeentityproperty(vSelf, "animation", AC_PAINMID);                  //Middle pain
            }

			ani0009(vSelf, iPainAni, -1);											//Apply pain animation.
        }
    }

    bind0005(getentityproperty(vSelf, "opponent"), 1);                              //Run hitwarp.
	bind0020(vSelf);																//Restablish binds if grappled by another entity.

}
