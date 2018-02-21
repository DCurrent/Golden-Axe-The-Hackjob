#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/targ0001.h"

void stat0001(void vTar, int iMPAdjust, int iHPAdjust, int A, int B, int C, int D, int E){

    /*
    stat0001
    Damon Vaughn Caskey
    11/03/2007    
    Change MP or HP level of target.
    
	vTarget:    Entity or target set.
	iMPAdjust:  MP loss or gain.
	iHPAdjust:  HP loss or gain.
    A-E:        Reserved.
    */

	void vSelf   = getlocalvar("self");                  //Calling entity.
	void vTarget = targ0001(vTar, vSelf);                 //Target entity.
    int  iMP     = getentityproperty(vTarget, "mp");     //Target's current MP.
	int  iHP     = getentityproperty(vTarget, "health"); //Target's current HP.

	changeentityproperty(vTarget, "mp", iMP + iMPAdjust);       //Adjust target's MP.
    changeentityproperty(vTarget, "health", iHP + iHPAdjust);   //Adjust target's MP.
}