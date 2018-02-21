#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/draw0005.h"

void bind0009(void vModel, void vAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iFrame, int iKill, float iScaleX, float iScaleY, int iFlipX, int iFlipY, int iShiftX, int iFill, int iRotate, int iARotat)
{
	
    /*
     bind0009
     Damon Vaughn Caskey
     02/25/2008
     Runs bind0008 and adds draw adjustments.
     
     vName:      Model name of spawn.
     vAlias:     Display name of spawn. 
     vMap:       Color map of spawn.
     iBlend:     Transparency setting of spawn. 
     fX, fY, fZ: Location offset.
     iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
     */
    
    void  vSpawn;
    
	vSpawn = bind0008(vModel, vAlias, iMap, iBlend, fAX, fAY, iAZ, iDir, iAni, iFrame, iKill);
    
    draw0005(vSpawn, iScaleX, iScaleY, iFlipX, iFlipY, iShiftX, iBlend, iMap, iFill, iRotate, iARotat); //Apply draw values.

    draw0001(vSpawn);																				    //Update draw for spawn.    

    if (iAni){        
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);    
    
    return vSpawn;
}
