#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/com/targ0001.h"

void dama0004(void iIndex, int iBind, float fHP, int iDrop, int iType, int iDir, float fY, float fX, float fZ, int iDOL, int iAttacking, int iProj, int fMode){

	log("\n dama0004");

    /*
    dama0004
    Damon Vaughn Caskey
    02/02/2010
	2010_02_02
	~2011_07_19
    Damage caller's bound entity by index. Differs from dama0001 in that a mode is provided to allow
    non leathal damage, and attack types are passed as integers rather than text.

    iIndex:        Target entity by index. 
    fHP:           Amount of damage to apply.
    iDrop:         Knockdown.
    iType:         Attack type.
    iDir:          Force direction.
    fX/fY/fZ:      Toss entity parameters.
    iDOL:          Damage on landing.
    iAttacking:    Attacking flag.
    iProj:         Projectile flag. 
    fMode:         0: Normal damage, -1: Normal damage to 1hp, 0+: Add fMode % of target's current HP.
    */

    void    vSelf   = getlocalvar("self");                                          //Calling entity.
    void    vTarget = getglobalvar(vSelf + ".bind." + iIndex);                      //Target entity.
    int     iSDir   = getentityproperty(vSelf, "direction");                        //Calling entity facing.
    int     iTDir   = getentityproperty(vTarget, "direction");                      //Target entity facing.
    float   fOff    = 0.0;                                                          //Offense.
    float   fDef    = 0.0;                                                          //Defense.
    int     iDam	= 0;                                                            //Potential damage placeholder.
    int     iHealth;                                                                //Target health.
       
    if (iBind = -2)
    {
        setglobalvar(vSelf + ".bind." + iIndex, NULL());                            //Remove record of binding.

		setentityvar(vTarget, IDXE_BOUNDA, NULL());										//Remove record bound to self anchor from target.
		setentityvar(vTarget, IDXE_BOUNDI, NULL());										//Remove record bound to self Index from target.
		setentityvar(vTarget, IDXE_BOUNDX, NULL());										//Remove record bound to self X from target.
		setentityvar(vTarget, IDXE_BOUNDY, NULL());										//Remove record bound to self Y from target.
		setentityvar(vTarget, IDXE_BOUNDZ, NULL());										//Remove record bound to self Z from target.
		setentityvar(vTarget, IDXE_BOUNDD, NULL());										//Remove record bound to self direction from target.
		setentityvar(vTarget, IDXE_BOUNDF, NULL());										//Remove record bound to self frame from target.
    }

	if(fMode == -1)                                                                 //Mode 1. Only damage to 1 health. 
    {
        /*
        Let's find out if the requested damage will kill target. We'll need to factor in
        the attacker's offense and target's defense ratings.
        */
        iHealth = getentityproperty(vTarget, "health");                             //Get target health
        fOff    = getentityproperty(vSelf, "offense", iType);                       //Get self offense.
        fDef    = getentityproperty(vTarget, "defense", iType, "factor");           //Get self defense.
        
        if(fOff){ iDam = fHP * fOff;    }                                           //Apply self offense.
        if(fDef){ iDam *= fDef;         }                                           //Apply target defense.
            
        if (iDam >= iHealth)                                                        //Will damage kill defender?
        {
            iDam    = -1;
            fHP     = 0;                                                            //Set damage to 0. We're still going to "damage" the entity so engine knows damage took place and takes appropriate measures.
        }

        /*
        Here is a formula for setting the exact amount of damage needed to reduce
        health to 1. Rounding is a problem, for now just setting health directly
        to 1 and damaging the target for 0 will do.
        
        fHP = --iHealth; 
        fHP /= fDef; 
        fHP /= fOff; 

        if (fHP > 1) --fHP;
        */
    }
    else if(fMode>0)
    {
        iHealth     = getentityproperty(vTarget, "health");                         //Get target health
        fHP         += (iHealth * fMode);        
    }
	
    changeentityproperty(vTarget, "dead", 0);                                       //Unset target's death status so it can receive damage effect even if already killed.
    damageentity(vTarget, vSelf, fHP, iDrop, iType);                                //Apply attack/damage.    
	changeentityproperty(vTarget, "damage_on_landing", iDOL);                       //Set damage on landing flag.
    changeentityproperty(vTarget, "projectile",        iProj);                      //Set "hit others" flag.     

	if(iDam == -1)
    {
        changeentityproperty(vTarget, "health", 0);                                 //Set health to 0. Next time entity is damaged, even for 0HP, the engine will consider it killed.
    }    
	
    if (iDir == 1)
    { 
		iTDir = iSDir;                                                              //Same as self.         
    }
    else if (iDir == 2)												                //Right.
    {
		iTDir = 1;                                                         
    }
    else if (iDir == -1)												            //Opposite of self.
    {
		if (iSDir)
		{
			iTDir = 0;             
		}
		else
		{
			iTDir = 1;
		}         
    }
    else if (iDir == -2)												            //Left.
    {
		iTDir = 0;                                                         
    }     

    if (!iSDir){ fX = -fX; }          

    if (fY || fX || fZ) { tossentity(vTarget, fY, fX, fZ); }                        //If velocity provided, toss em'.
    changeentityproperty(vTarget,"direction", iTDir);                               //Change direction.

}
