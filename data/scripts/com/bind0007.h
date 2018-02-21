#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/draw0002.h"

void bind0007(void vModel, void vAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, void iAni, int iFrame, int iKill, int iAniFlag){
	
    /*
    bind0007
    Damon Vaughn Caskey
    02/25/2008
    Calls bind0008, but then binds entity to caller. Usful to spawn an effect that will be bound independent 
	of animation.

    vName:      Model name of spawn.
    vAlias:     Display name of spawn. 
    vMap:       Color map of spawn.
    iBlend:     Transparency setting of spawn. 
    fX, fY, fZ: Location offset of binding.
    iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
	iAni:		Animation for new spawn to run.
	iFrame:		Animation frame for new spawn to run.
	iKill:		Autokill flag.
    */
    
	void  vSelf		= getlocalvar("self");
	float fRatio	= getentityvar(vSelf, IDXE_ADSCALER);
	void  vSpawn;

    vSpawn = bind0008(vModel, vAlias, iMap, iBlend, 0, 0, 0, iDir, iAni, iFrame, iKill);
        
    setentityvar(vSelf, IDXE_SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    setentityvar(vSelf, IDXE_BINDE, vSpawn);                                     //Store into bind variant.    
    
    if (fAX){ fAX = draw0002(fRatio, fAX); }                                //If X bind, apply scaling to fX.
    if (fAY){ fAY = draw0002(fRatio, fAY); }                                //If Y bind, apply scaling to fY.
        
    bindentity(vSpawn, vSelf, fAX, iAZ, fAY, iDir, iAniFlag);               //Execute bind.
    
    draw0001(vSpawn);                                                       //Update draw for spawn.

    return vSpawn;                                                          //Return spawned entity.
}
