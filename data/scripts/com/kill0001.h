#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/draw0006.h"

void kill0001()
{
    /*
    kill0001
    Damon Vaughn Caskey
	2007_05_13
	~2011_05_17
    Primary on kill function. Run for most entities when engine removes them from play.
    */

    void    vSelf   = getlocalvar("self");													//Caller.
    void    vParent = getentityproperty(vSelf, "parent");									//Caller's parent.
    int     iAni    = getentityproperty(vSelf, "animationid");								//Current animation.
    void    vBindhe;																		//Bound hit effect entity.
    void    vSpawn;																			//Spawn entity.

    if (iAni == A_BURNDIE)																	//Self in burning death?
    {
        if (getentityproperty(vSelf, "model") != MODEL_EFFECT)									//Self not the fatality or effect model?
        {
            vBindhe = getentityvar(vSelf, IDXE_BINDHE);											//Get any bound effect.

            if (getentityproperty(vBindhe, "exists"))										//Bound effect exists?
            {
                killentity(vBindhe);														//Then kill it.
            }

			vSpawn = bind0008(MODEL_EFFECT, MODEL_EFFECT, 11, 1, 0, 60, 2, 2, A_FOLLOW2, 0, 1);			//Spawn ball explosion.
            draw0006(vSpawn, vSelf);

			vSpawn = bind0008(MODEL_EFFECT, MODEL_EFFECT, MAP_BURN, 0, 0, 0, 0, 1, A_FOLLOW14, 0, 0);	//Spawn fatality model.
            draw0006(vSpawn, vSelf);														//Match fatality model size to self.
        }
    }
    else if (iAni == A_SHOCKDIE)
    {
		if (getentityproperty(vSelf, "model") != MODEL_EFFECT)									//Self not the fatality or effect model?
        {
            vBindhe = getentityvar(vSelf, IDXE_BINDHE);											//Get any bound effect.

            if (getentityproperty(vBindhe, "exists"))										//Bound effect exists?
            {
                killentity(vBindhe);														//Then kill it.
            }

			vSpawn = bind0008(MODEL_EFFECT, MODEL_EFFECT, 11, 1, 0, 60, 2, 2, A_FOLLOW2, 0, 1);			//Spawn ball explosion.
            draw0006(vSpawn, vSelf);

			vSpawn = bind0008(MODEL_EFFECT, MODEL_EFFECT, MAP_BURN, 0, 0, 0, 0, 1, A_FOLLOW14, 0, 0);	//Spawn fatality model.
            draw0006(vSpawn, vSelf);														//Match fatality model size to self.
        }
    }
	else																					//Normal.
	{
		vBindhe = getentityvar(vSelf, IDXE_BINDHE);												//Get any bound effect.

        if (getentityproperty(vBindhe, "exists"))											//Bound effect exists?
        {
            killentity(vBindhe);															//Then kill it.
        }
	}

	/*
	If self was an effect model (body burn flames, shocked, etc.) let's get parent
	back to normal.
	*/
    if (getentityproperty(vParent, "exists"))												//Parent exists?
    {
         vBindhe = getentityvar(vParent, IDXE_BINDHE);											//Get parent's bound effect variant.
         if (vBindhe == vSelf)																//Was bound effect same as self?
         {
            setentityvar(vParent, IDXE_BINDHE, NULL());											//Clear parent's bound effect variant.
            //changeentityproperty(vParent, "map", getentityproperty(vParent, "mapdefault"));	//Clear parent's remap.

            changedrawmethod(vParent, "reset", 1); //reset just in case
         }
    }

}
