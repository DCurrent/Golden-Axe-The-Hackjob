#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"

void effe0001(int iMap){

    /*
    effe0001
    Damon Vaughn Caskey
 	2009_09_15
	~2011_05_17

    Spawn and bind effect entity. It might seem like a good idea to run this as part of a takedamage script,
    but that won't work. At that point the engine has not set defender to appropriate reactive animation yet.
    Therefore an animation match bind will kill the effect spawn instantly.

    vName:      Model name of spawn.
    */

    void  vSelf     = getlocalvar("self");						//Caller.
    void  vModel    = "effe0001";								//Model.
    void  vBound    = getentityvar(vSelf, IDXE_BINDHE);				//Previous effect entity.
    float fRatio	= getentityvar(vSelf, IDXE_ADSCALER);			//Caller's current scale ratio.
    float fX		= getentityproperty(vSelf, "x");			//Caller X location.
    float fY		= getentityproperty(vSelf, "a");			//Caller Y location.
	float fZ		= getentityproperty(vSelf, "z");			//Caller Z location.
	float fHT		= getentityproperty(vSelf, "animheight");	//Caller's Y height.
    void  vSpawn;												//New spawn placeholder.

	if (!fRatio){	fRatio = 1;	}								//Scale ratio failsafe.
	if(!fHT){	fHT = getentityproperty(vSelf, "height");	}	//If no animheight, get entity height.
	fHT = 0.5 * (fHT * fRatio);									//Get center height.

    if (vBound)													//Previous effect entity in place?
    {
        if (vModel == getentityproperty(vBound, "model"))		//Previous same as proposed?
        {
            bindentity(vBound, vSelf, 0, 1, fHT, 1, 4);			//Refresh bind.
            return;												//Exit.
        }
        else
        {
            killentity(vBound);									//Kill old effect.
        }
    }

    clearspawnentry();											//Clear current spawn entry.
    setspawnentry("name",   vModel);							//Aquire spawn entity by name.
    setspawnentry("coords", fX, fZ, fY+fHT);					//Spawn location.
    setspawnentry("map", iMap);									//Spawn map.
    vSpawn = spawn();											//Spawn entity.
    clearspawnentry();											//Clear current spawn entry.
    changeentityproperty(vSpawn, "parent", vSelf);				//Set caller as parent of spawn.
    setentityvar(vSelf, IDXE_SPAWN, vSpawn);							//Store spawn.

    bindentity(vSpawn, vSelf, 0, 1, fHT, 1, 4);					//Execute bind.
    setentityvar(vSelf, IDXE_BINDHE, vSpawn);						//Store bind.

    /*setentityvar(vSpawn, IDXE_ADSCALEX, 0.50);						//Draw scale X adjustment.
    setentityvar(vSpawn, IDXE_ADSCALEY, 0.50);						//Draw scale Y adjustment.
	draw0001(vSpawn);											//Apply draw.
	*/
	setdrawmethod(vSpawn, 1, 150, 150, 0, 0, 0, 1, iMap, 0, 0);	//Set final values to drawmethod.

    if(iMap == MAP_BURN)
    {
        changedrawmethod(vSelf, "reset", 1);
        changedrawmethod(vSelf, "tintmode", 3);
        changedrawmethod(vSelf, "tintcolor", RGB_BURN);
    }
    else if(iMap == MAP_SHOCK)
    {
        changedrawmethod(vSelf, "reset", 1);
        changedrawmethod(vSelf, "tintmode", 3);
        changedrawmethod(vSelf, "tintcolor", RGB_SHOCK);
    }
}
