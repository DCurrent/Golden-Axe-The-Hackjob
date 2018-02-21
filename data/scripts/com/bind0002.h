#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void bind0002(float fX, float fY, float fZ){
    
    /*
    bind0002
	Damon Vaughn Caskey
	06/20/2007
	Syncronizes target with caller's location without binding.
	
	iSync:      Sync target setting (see targ0001 function).
	fX, fY, fZ: Distance adjustment (from caller).
	iDirection: Direction adjustment (see loc001 function).
    */

    void  vSelf   = getlocalvar("self");                     //Calling entity.
    void  vTarget = getentityproperty(vSelf, "opponent");    //Current opponent.
    int   iDir    = getentityproperty(vTarget, "direction"); //Current direction.
    float fRatio  = getentityvar(vSelf, IDXE_ADSCALER);         //Caller's current scale ratio.

    //If any incoming values are NULL(), set to 0.
    if(!fX) fX = 0;
    if(!fY) fY = 0;
    if(!fZ) fZ = 0;
    
    if (iDir == 1){ fX = -fX;   }   //Reverse horizontal adjustment if facing left.    
    
    fX = (fX * fRatio) + getentityproperty(vSelf, "x"); //Apply requested X offset to X location and apply zoom scale.
    fY = (fY * fRatio) + getentityproperty(vSelf, "a"); //Apply requested Y offset to Y location and apply zoom scale.
    fZ = fZ + getentityproperty(vSelf, "z");            //Apply requested Z offset.

    changeentityproperty(vTarget, "position", fX, fZ, fY);
}
