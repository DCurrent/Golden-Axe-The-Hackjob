#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/draw0002.h"

void bind0003(void vModel, int vAlias, int iMap, int iBlend, float fX, float fY, float fZ, int iDir, int iAniFlag){
	
    /*
    bind0003
    Damon Vaughn Caskey
    02/25/2008
	2008_02_25
	~2011_05_17
    Spawn an entity and then bind it to caller; primarly special effects.

    vName:      Model name of spawn.
    vAlias:     Display name of spawn. 
    vMap:       Color map of spawn.
    iBlend:     Transparency setting of spawn. 
    fX, fY, fZ: Location offset of binding.
    iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
    iAniFlag:   See http://www.lavalit.com/index.php?topic=963.msg14445#msg14445
    */
    
    void  vSpawn;
    void  vSelf  = getlocalvar("self");                                     //Caller.
    void  vBinde = getentityvar(vSelf, IDXE_BINDE);                              //Previous bound entity.
    float fRatio = getentityvar(vSelf, IDXE_ADSCALER);                           //Caller's current scale ratio.
    int   iX     = getentityproperty(vSelf, "x") - openborvariant("xpos");  //Caller X location.
    int   iZ     = getentityproperty(vSelf, "z");                           //Caller Z location.
    int   iY     = getentityproperty(vSelf, "a");                           //Caller Y location.
    void  vAT	 = NULL();

    if (vBinde && getentityproperty(vBinde, "exists"))                      //Previously bound entity in place?
    {
        if (getentityproperty(vBinde, "name") == vAlias)                    //Alias of previous same as new?
        {
            killentity(vBinde);                                             //Kill previous.
        }
    }      
    
    clearspawnentry();                                                      //Clear current spawn entry.
    setspawnentry("name",   vModel);                                        //Aquire spawn entity by name.
    setspawnentry("alias",  vAlias);                                        //Set alias.
    setspawnentry("map",    iMap);                                          //Set color remap.
	setspawnentry("coords", iX, iZ, iY);                                    //Spawn location.
    vSpawn = spawn();                                                       //Spawn entity.
    clearspawnentry();                                                      //Clear current spawn entry.
        
    setentityvar(vSelf, IDXE_SPAWN, vSpawn);                                     //Store spawn into last spawn variant.
    setentityvar(vSelf, IDXE_BINDE, vSpawn);                                     //Store into bind variant.

    changeentityproperty(vSpawn, "parent", vSelf);                          //Set caller as parent of spawn.
    
	if(iMap == -1)															//Map "-1"?
	{
		vAT = getentityproperty(vSelf, "colourmap");						//Set vMap to callers current table.
		//setdrawmethod(vSpawn, 1, 256, 256, 0, 0, 0, iBlend, 0, 0, 0, 0, 0, vAT);		
		changedrawmethod(vSpawn, "table", vAT);	
		changedrawmethod(vSpawn, "alpha", iBlend);
	}
	else
	{
		changeentityproperty(vSpawn, "alpha", iBlend);							//Set transparency property.
	}

    if (fX){ fX = draw0002(fRatio, fX); }                                   //If X bind, apply scaling to fX.
    if (fY){ fY = draw0002(fRatio, fY); }                                   //If Y bind, apply scaling to fY.
        
    bindentity(vSpawn, vSelf, fX, fZ, fY, iDir, iAniFlag);                  //Execute bind.	
	
	draw0001(vSpawn);                                                       //Update draw for spawn.

    return vSpawn;                                                          //Return spawned entity.
}
