#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void bind0001(int iX, int iY, int iZ, int iDir, int iAniFlag){
     
     /*
     bind0001
     Damon Vaughn Caskey
     02/11/2008
     Bind caller to parent.
     
     iX, iY, iZ: Location offsets.
     iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
     iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
     */

     void  vSelf   = getlocalvar("self");                   //Caller.
     void  vParent = getentityproperty(vSelf, "parent");    //Caller parent.
     float fRatio  = getentityvar(vParent, IDXE_ADSCALER);     //Current scale factor.
     
     if (!fRatio) { fRatio = 1; }
     
     iX *= fRatio;
     iY *= fRatio;
         
     bindentity(vSelf, vParent, iX, iZ, iY, iDir, iAniFlag);  //Execute bind.    

}