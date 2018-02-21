#import "data/scripts/com/ani0009.h"

void ani0018(int iAni, int iFrame){

    /*
    ani0018
    Damon Vaughn Caskey
    10262009
    Switch to alternate animation if nearest hostile is in range of alt and an animal type. Should be rolled into ani0017.

    iAni:   Alternate animation.
    iFrame: Alternate frame.
    */

    void vSelf      = getlocalvar("self");
    void vTar       = findtarget(vSelf, iAni);
    char vName      = getentityproperty(vTar, "defaultname");

    if (vTar)
    {
        if (getentityproperty(vTar, "animal"))          //Riding an animal?
        {
            ani0009(vSelf, iAni, 0);					//Perform alternate animation.
            updateframe(vSelf, iFrame);
        }
    }
}
