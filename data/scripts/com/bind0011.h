#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0008.h"

void bind0011(void vModel, void vAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, void iAni, int iFrame, int iKill)
{

    /*
    bind0011
    Damon Vaughn Caskey
    10262009
    Runs bind0008 while storing resulting entity into IDXE_BINDE variable.
    */

    void vSelf = getlocalvar("self");
    void vSpawn;

    vSpawn = bind0008(vModel, vAlias, iMap, iBlend, fAX, fAY, iAZ, iDir, iAni, iFrame, iKill);
    setentityvar(vSelf, IDXE_BINDE, vSpawn);
}
