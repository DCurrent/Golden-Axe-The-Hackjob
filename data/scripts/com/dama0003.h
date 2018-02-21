#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/dama0001.h"
#import "data/scripts/com/parr0001.h"

void dama0003(){
    
    //Projectile damage function..

    void    vSelf       = getlocalvar("self");                              //Calling entity. 
    void    vAtk        = getlocalvar("attacker");                          //Damaging entity.
    void    vPar        = getentityproperty(vSelf, "parent");               //Caller's parent.
    int     iAType      = getlocalvar("attacktype");                        //Incomming attack type.
    int     iGP         = getentityproperty(vSelf, "guardpoints");          //Vunerability vs. physical attacks (punches, kicks, etc.).

    /*
    Guardpoints is used as a free variable to track projectiles vunerability to
    physical attack (note, this does not apply to other projectiles, that is handled
    in projectile's didhit script).

    -1 = Projectile is not subject to physical attack.
    0+ = Number of extra hits projectile can take before it is destroyed.
    */

    changeentityproperty(vAtk, "opponent", vPar);                                       //Set attackers opponent to caller's parent.
    
    if (iGP == -1 || vAtk == vPar)                                                      //Attacker is parent or caller is immune to attack?
    {
        return;                                                                         //Exit.
    }
    else
    {   
        if (--iGP < 0)                                                                  //Decremented below 0?
        {                 
            changeentityproperty(vSelf, "animation", getentityvar(vSelf, IDXE_NEXTANI2));    //Set animation.
            changeentityproperty(vSelf, "velocity", 0, 0, 0);                           //Stop movement.
            return;                                                                     //Exit. 
        }
        
        changeentityproperty(vSelf, "guardpoints", iGP);                                //Apply final GP loss to caller.
    }
}