#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0002.h"

void bind0004(void vTar, int iX, int iY, int iZ, int iDir, int iAniFlag){
     
    /*
    bind0004
    Damon Vaughn Caskey
    03/12/2008
    Basic binding functions. Idea was to consolidate binding to reduce redundant code. Proved very cumbersome
    and will be phased out over time.
     
    vTar:       Target entity. See targ0001 function.
    iX, iY, iZ: Location offsets.
    iDir:       Facing and bind set:    0   = No change.
                                        1   = Same as self facing.
                                        -1  = Opposite of self  
                                        2   = Face right 
                                        -2  = Face left.
                                        11  = Release previous bind and delete record of bind.
                                        12  = Release previous bind but store record as if binding normally.
                                        13  = Release previous bind, knock bound entity down to reset it (it may have been stuck 
                                              in a looping animation), and delete record of bind.
    
    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
    */

    void  vSelf   = getlocalvar("self");           //Calling entity.
    void  vTarget = targ0001(vTar, vSelf);          //Target entity.
    float fRatio;                                  //Caller's current scale ratio.
    
    //Check direction flag to apply any special behaviors.
    if (iDir == 11)
    {
        bindentity(vTarget, NULL());                                            //Release bind.
        setentityvar(vSelf, IDXE_BIND, NULL());                                      //Remove bind record.
    }
    else if (iDir == 12)
    {
        bindentity(vTarget, NULL());                                            //Release bind.
        setentityvar(vSelf, IDXE_BIND, vTarget);                                     //Record bind target. May seem counter productive, but has uses for grappling. Mainly for applying an animation and knockdown effect to formerly bound entity after release.
    }
    else if (iDir == 13)
    {
        bindentity(vTarget, NULL());                                            //Release bind.
        damageentity(vTarget, vSelf, 0, 100, openborconstant("ATK_NORMAL"));    //Knock bound entity down to reset it.
        setentityvar(vSelf, IDXE_BIND, NULL());                                      //Remove bind target.
    }
    else
    {
        fRatio      = getentityvar(vSelf, IDXE_ADSCALER);                            //Get caller's current scale ratio.

        if (iX){ iX = draw0002(fRatio, iX); }                               //If X bind, apply scaling to fX.
        if (iY){ iY = draw0002(fRatio, iY); }                               //If Y bind, apply scaling to fY.
        
        bindentity(vTarget, vSelf, iX, iZ, iY, iDir, iAniFlag);                 //Execute bind.
        setentityvar(vSelf, IDXE_BIND, vTarget);                                     //Make record of binding.
    }
}
