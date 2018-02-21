#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0003.h"
#import "data/scripts/com/draw0001.h"

void bind0006(void vName, void vAlias, void vMap, int iBlend, int iX, int iY, int iZ, int iDir, int iAniFlag, float fScaleX, float fScaleY, int iFlipX, int iFlipY, int iShiftX, int iFill, int iRotate){
	
    /*
    bind0006
    Damon Vaughn Caskey
    02/25/2008
    Performs bind0003 functions and adds draw adjustments.

    vName:      Model name of spawn.
    vAlias:     Display name of spawn. 
    vMap:       Color map of spawn.
    iBlend:     Transparency setting of spawn. 
    fX, fY, fZ: Location offset of binding.
    iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
    */

    void vTarget = bind0003(vName, vAlias, vMap, iBlend, iX, iY, iZ, iDir, iAniFlag);
        
    setentityvar(vTarget, IDXE_ADSCALEX,   fScaleX);   //iScaleX adjustment.
    setentityvar(vTarget, IDXE_ADSCALEY,   fScaleY);   //iScaleY adjustment.
    setentityvar(vTarget, IDXE_ADFLIPX,    iFlipX);    //Flip X.
    setentityvar(vTarget, IDXE_ADFLIPY,    iFlipY);    //Flip Y.
    setentityvar(vTarget, IDXE_ADSHIFTX,   iShiftX);   //Shift X.
    setentityvar(vTarget, IDXE_ADFILL,     iFill);     //Fill color.
    setentityvar(vTarget, IDXE_ADROTATE,   iRotate);   //Rotate.

    draw0001(vTarget);                            //Run draw to imediatly apply adjustments.        
}