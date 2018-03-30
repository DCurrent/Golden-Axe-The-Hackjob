#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"

// Get which effect model to use based on
// target entity's animation.
char dc_effect_model_select(void target)
{
    int animation;
    char model;

    // First we need to know what animation
    // the target entity is playing.
    animation = getentityproperty(target, "animationid");

    // Now pick an effect model based on the animation.
    if(animation == openborconstant("ANI_BURN")
       || animation == openborconstant("ANI_BURNPAIN"))
    {
        model = "effe0001";
    }
    else if(animation == openborconstant("ANI_SHOCK")
            || animation == openborconstant("ANI_SHOCKPAIN"))
    {
        model = "effect_shocked";
    }

    // Return model.
    return model;
}

void dc_effect(void target)
{
    #define DC_EFFECT_VARKEY_ENTITY "dc_effect_0"
    #define POS_X   -200
    #define POS_Y   -200
    #define POS_Z   0
    #define MAP     2

    char model_current;
    char model_spawn;
    char varkey;        // Local variable key to track any pre-existing effect entity.

    float pos_x;        // Target position, X axis.
    float pos_y;
    float pos_z;
    float anim_height;

    void effect_entity; // Effect entity. Could be a pre-existing or new spawned entity.

    // Combine key name with target's pointer
    // to create a unique local var name that
    // will then be used to track effect entity.
    //
    // Why bother with this keying system for
    // localvar instead just using of entity vars?
    // Localvars are engine managed and local to
    // a script instance. Entity vars are global
    // and require extra code carefully constructed
    // to make sure they always get cleaned up.
    // Otherwise you end up with memory leaks.
    //
    // Sticking with localvar allows us to keep
    // the management code fully self-contained
    // within this function and not worry about
    // them being left about when the script is
    // cleared from memory.
    varkey = DC_EFFECT_VARKEY_ENTITY + target;

    // Get pre-existing effect (if any).
    effect_entity = getlocalvar(varkey);

    // What effect model should we spawn (if any).
    model_spawn = dc_effect_model_select(target);

    // Do we have a model name we want to spawn
    // as an effect entity? If so we will check
    // to see if an effect entity is already in
    // use and make sure it is a different model
    // name than the one we want before spawning
    // a new effect.
    //
    // If the model name to spawn is empty, then
    // we don not want any effect entity at all,
    // so we will clear it out.
    if(model_spawn)
    {
        // If there is a previous effect entity
        // in place, get its model name.
        if(effect_entity)
        {
            model_current = getentityproperty(effect_entity, "model");
        }

        // If the current model is different than
        // the one we want to spawn, then destroy
        // the current effect entity and spawn a
        // new one using our new model.
        if (model_current != model_spawn)
        {
            // Destroy the existing effect entity (if any).
            killentity(effect_entity);

            // Spawn the new effect entity and
            // get its pointer.
            clearspawnentry();
            setspawnentry("name", model_spawn);
            setspawnentry("coords", POS_X, POS_Z, POS_Y);
            setspawnentry("map", MAP);
            effect_entity = spawn();
            clearspawnentry();
        }
    }
    else
    {
        // Destroy the existing effect entity.
        killentity(effect_entity);
        effect_entity = NULL();
    }

    // Set or clear the resulting effect entity
    // tracking variable for next cycle, and
    // then return result.
    setlocalvar(varkey, effect_entity);

    return effect_entity;

    #undef DC_EFFECT_ENTITY
    #undef POS_X
    #undef POS_Y
    #undef POS_Z
    #undef MAP
}

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

    vSpawn = dc_effect(vSelf);

    bindentity(vSpawn, vSelf, 0, 1, fHT, 1, 4);					//Execute bind.
    setentityvar(vSelf, IDXE_BINDHE, vSpawn);						//Store bind.

    /*setentityvar(vSpawn, IDXE_ADSCALEX, 0.50);						//Draw scale X adjustment.
    setentityvar(vSpawn, IDXE_ADSCALEY, 0.50);						//Draw scale Y adjustment.
	draw0001(vSpawn);											//Apply draw.
	*/
	setdrawmethod(vSpawn, 1, 150, 150, 0, 0, 0, 1, iMap, 0, 0);	//Set final values to drawmethod.

    if(iMap == MAP_BURN)
    {
        //changedrawmethod(vSelf, "reset", 1);
        //changedrawmethod(vSelf, "tintmode", 3);
        //changedrawmethod(vSelf, "tintcolor", RGB_BURN);
    }
    else if(iMap == MAP_SHOCK)
    {
        changedrawmethod(vSelf, "reset", 1);
        changedrawmethod(vSelf, "tintmode", 3);
        changedrawmethod(vSelf, "tintcolor", RGB_SHOCK);
    }
}
