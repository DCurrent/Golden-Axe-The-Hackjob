#import "data/scripts/com/ani0009.h"

void ani0017(int iAni, int iFrame, char vName, int A, int B, int C, int D, int E){

    /*
    ani0017
    Damon Vaughn Caskey
    10262009
    Switch to alternate animation if nearest hostile is in range of alt and all checks match.

    iAni:   Alternate animation.
    iFrame: Alternate frame.
    vName:  String to verify against target's default name.
    A-E:    Expansion.
    */

    void vSelf      = getlocalvar("self");
    void vTar       = findtarget(vSelf, iAni);
    
	if (vTar)
    {		
        if (!vName || vName == getentityproperty(vTar, "defaultname"))
        {        
            ani0009(vSelf, iAni, 0);					//Perform alternate animation.
            updateframe(vSelf, iFrame);
        }
    }    
}
