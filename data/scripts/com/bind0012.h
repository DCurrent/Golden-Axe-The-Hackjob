#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"

void bind0012(void vTarget){
    
    /*
    bind0012
	Damon Vaughn Caskey
	06/20/2007
	Syncronizes target with caller's location with hit flags.	
    */

    void  vSelf     = getlocalvar("self");                              //Calling entity.     
    int   iWarpT    = getentityvar(vSelf, IDXE_HITWRT);                      //Warp condition.
    float fX        = getentityvar(vSelf, IDXE_HITWRX);                      //Warp X adjustment.
    float fY        = getentityvar(vSelf, IDXE_HITWRY);                      //Warp X adjustment.
    float fZ        = getentityvar(vSelf, IDXE_HITWRZ);                      //Warp X adjustment.
    float fRatio;                                                       //Caller's current scale ratio.
    
    if (fX || fY || fZ)                                                 //Any warp flags at all?
    {
        if (iWarpT)                                                     //Any warp condition?
        {
            setentityvar(vTarget, IDXE_WARPX, fX);                           //Warp X adjustment.
            setentityvar(vTarget, IDXE_WARPY, fY);                           //Warp Y adjustment.
            setentityvar(vTarget, IDXE_WARPZ, fZ);                           //Warp Z adjustment.
            setentityvar(vTarget, IDXE_WARPT, iWarpT);                       //Set warp condition.        
        }
        else
        { 
            fRatio = getentityvar(vSelf, IDXE_ADSCALER);                     //Get caller's current scale ratio.

            if(!fX) fX = 0;                                             //If Null, initialize to 0.
            if(!fY) fY = 0;                                             //If Null, initialize to 0.
            if(!fZ) fZ = 0;                                             //If Null, initialize to 0.
            
            if (getentityproperty(vTarget, "direction"))                //Facing left?
            { 
                fX = -fX;                                               //Reverse X adjustment.
            }                                   
            
            fX = (fX * fRatio) + getentityproperty(vSelf, "x");         //Apply requested X offset to X location and apply zoom scale.
            fY = (fY * fRatio) + getentityproperty(vSelf, "a");         //Apply requested Y offset to Y location and apply zoom scale.
            fZ = fZ + getentityproperty(vSelf, "z");                    //Apply requested Z offset.

            changeentityproperty(vTarget, "position", fX, fZ, fY);      //Set target postion.

            draw0001(vTarget);                                          //Refresh target's draw values.
        }        
    }    
}
