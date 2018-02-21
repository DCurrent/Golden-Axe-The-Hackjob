#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/draw0002.h"

void bind0015(void vEnt, void vModel, void vAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iFrame, int iKill){
	
     /*
     bind0015
     Damon Vaughn Caskey
     2008_02_25
	 ~2011_05_17
     
	 Spawn an entity, place it in location with relation to designated entity, but do not bind.
     
     vName:      Model name of spawn.
     vAlias:     Display name of spawn. 
     vMap:       Color map of spawn.
     iBlend:     Transparency setting of spawn. 
     fX, fY, fZ: Location offset.
     iDir:       Direction - 0 = no change, 1 = same target, -1 = opposite of target,  2 = right, -2 = left.
     */
    
    void  vSpawn;
    void  vSelf  = getlocalvar("self");                                     //entity.
    float fRatio = getentityvar(vEnt, IDXE_ADSCALER);							//entity's current scale ratio.
    int	  iX     = getentityproperty(vEnt, "x"); //- openborvariant("xpos");	//entity X location.
    int	  iZ     = getentityproperty(vEnt, "z");							//entity Z location.
    int	  iY     = getentityproperty(vEnt, "a"); //- openborvariant("ypos");	//entity Y location.
	int	  iDir	 = getentityproperty(vEnt, "direction");					//entity direction.

	if (fAX){ fAX = draw0002(fRatio, fAX); }                                //If X adjust, apply scaling to fX.
    if (fAY){ fAY = draw0002(fRatio, fAY); }                                //If Y adjust, apply scaling to fY.
    if (!iDir){ fAX = -fAX;   }                                             //Reverse horizontal adjustment if facing left.

    if (iMap == -1)                                                         //Map "-1"?
    { 
        iMap = getentityproperty(vEnt, "map");								//Set iMap to entitys current map.
    }  
    
    clearspawnentry();                                                      //Clear current spawn entry.
    setspawnentry("name",   vModel);                                        //Aquire spawn entity by name.
    setspawnentry("alias",  vAlias);                                        //Set alias.
    setspawnentry("map",    iMap);                                          //Set color remap.
	//setspawnentry("coords", iX + fAX, iZ + iAZ, iY + fAY);                  //Spawn location.
    vSpawn = spawn();                                                       //Spawn entity.
    clearspawnentry();                                                      //Clear current spawn entry.
    
	
	changeentityproperty(vSpawn, "base", getentityproperty(vEnt, "base"));
	changeentityproperty(vSpawn, "position", iX + fAX, iZ + iAZ, iY + fAY);
	
    //setentityvar(vEnt, IDXE_SPAWN, vSpawn);										//Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);
    changeentityproperty(vSpawn, "parent", vSelf);                          //Set entity as parent of spawn.
	
    changeentityproperty(vSpawn, "alpha", iBlend);                          //Set transparency property.
    
    draw0001(vSpawn);                                                       //Update draw for spawn.    

    if (iAni)
	{        
        changeentityproperty(vSpawn, "animation", iAni);
    }

    changeentityproperty(vSpawn, "autokill", iKill);

    return vSpawn;
}
