#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/draw0002.h"
#import "data/scripts/com/bind0003.h"
#import "data/scripts/com/bind0008.h"
#import "data/scripts/com/hit0001.h"

void proj0002(void vModel, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iAniH, int iAniD, int iKill, int iGrav, int iBase, int iHP, int iMP, int iPen, int iPhys, float fXS, float fYS, float fZS, int iStyle, int iForce, int iFin, int iType, int iDrop, float fTX, float fTY, float fTZ, int iReset, int iWX, int iWY, int iWZ, int iWT){
/*   
Big Tornado     "proj0001"        0           1         90          1        0         1         1          2          2          1          1          0        3        3         0         -1 1 0 0
Hishoken        "proj0001"       11           1         70         50        1         1         4          4          4          1          1          0     1000       15        -1 1 0 0
G. Hishoken     "andybe"          3           1         85         30        1         1         5          0          0          1          1          0     1000       15        -1 1 0 0
  
     proj0002
     Damon Vaughn Caskey
     02/11/2008     
     Launch projectile with auto compensation for current zoom, does not provide draw adjustments.
     
	 vModel, 
	 vAlias, 
	 iMap, 
	 iBlend, 
	 fAX, 
	 fAY, 
	 iAZ, 
	 *iDir (default to self facing), 
	 iAni, 
	 iFrame, 
	 *iKill (Default to 1): See bind0008.

     iAniH:         Animation to play when projectile hits and stops.
     iAniD:         Animation to play when projectile is defeated (overpowered by another projectile, stopped with an attack, blocked, etc.)
     fXS/fYS/fZS:   Projectile velocity.
     iStyle:        Projectile style (not same as engine's types). 0 = Knife style.
     iForce:        Damage.
     iType:         Damage type.
     iDrop:         Knockdown power.     
	 */    

    void  vSpawn;
    void  vSelf  = getlocalvar("self");												            //Caller.    
    int   iEType = getentityproperty(vSelf, "type");								            //Caller type.	                                                
    
    if (!iStyle)
    {
	    iAni	= openborconstant("ANI_FOLLOW" + iAni);												//Get animation constant.
        iAniH	= openborconstant("ANI_FOLLOW" + iAniH);											//Get animation constant.
        iAniD	= openborconstant("ANI_FOLLOW" + iAniD);											//Get animation constant.
    
        vSpawn	= bind0008(vModel, "Projectile", iMap, iBlend, fAX, fAY, iAZ, iDir, iAni, 0, iKill);//Spawn projectile using the bind0008 function.
	
        if (!getentityproperty(vSpawn, "direction"))												//Reverse horizontal adjustments if facing left.
        {        
            fXS = -fXS; 
        }
    }
    else if (iStyle == 1)
    {
        vSpawn  = bind0003(vModel, "Projectile", iMap, iBlend, fAX, fAY, iAZ, iDir, iAni);
        changeentityproperty(vSpawn, "autokill", iKill);
    }

	changeentityproperty(vSpawn, "aimove", AI_NOMOVE);											//Using obstacle type to allow hit control. Give it normal AI mode here.
    setentityvar(vSelf, IDXE_SPAWN, vSpawn);															//Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "velocity", fXS, fZS, fYS);						            //Adjust projectile velocity.
    changeentityproperty(vSpawn, "antigravity", iGrav);											//Adjust gravity.
	changeentityproperty(vSpawn, "no_adjust_base", iBase);										//So it won't "land" instantly when thrown from the air.
    changeentityproperty(vSpawn, "base", iBase);                                                //Starting base. Again, to prevent instant "land" when thrown from air.
    changeentityproperty(vSpawn, "health", iHP);                                                //Health. Projectile can't be damaged conventionaly but health is still used as a self destruct flag.
    changeentityproperty(vSpawn, "mp", iMP);                                                    //Vunerability and priority vs. other projectiles. See projectile didhit script.
    changeentityproperty(vSpawn, "aggression", iPen);                                           //Penetration (how many extra hits projectile can dish out before stopping).
    changeentityproperty(vSpawn, "guardpoints", iPhys);                                         //Vunerability vs. physical attacks (punches, kicks, etc.). -1 projectile can't be hit. 0 = 1 hit stop. 1+ no. of extra hits that can be taken.
    
    setentityvar(vSpawn, IDXE_NEXTANI, iAniH);                                                       //Animation to play when projectile hits and stops.
    setentityvar(vSpawn, IDXE_NEXTANI2, iAniD);                                                      //Animation to play when projectile is defeated.

    setentityvar(vSpawn, IDXE_HITDMG,   iForce);                                                     //Damage.
    setentityvar(vSpawn, IDXE_HITFIN,   iFin);                                                       //Leathal/non leathal damage.
    setentityvar(vSpawn, IDXE_HITTYP,   iType);                                                      //Attack type.
    setentityvar(vSpawn, IDXE_HITDRP,   iDrop);                                                      //Drop.
    setentityvar(vSpawn, IDXE_TOSSX,    fTX);                                                        //Toss X
    setentityvar(vSpawn, IDXE_TOSSY,    fTY);                                                        //Toss Y
    setentityvar(vSpawn, IDXE_TOSSZ,    fTZ);                                                        //Toss Z
    setentityvar(vSpawn, IDXE_HITNOR,   iReset);                                                     //Remove flags on hit toggle.
    setentityvar(vSpawn, IDXE_HITWRX,   iWX);                                                        //Move defender to attacker with X adjust.
    setentityvar(vSpawn, IDXE_HITWRY,   iWY);                                                        //Move defender to attacker with Y adjust.
    setentityvar(vSpawn, IDXE_HITWRZ,   iWZ);                                                        //Move defender to attacker with Z adjust.
    setentityvar(vSpawn, IDXE_HITWRT,   iWT);                                                        //Only move if in pain or fall.

	if (TYPE_ENEMY)																				//Self enemy type?
    {
        changeentityproperty(vSpawn, "candamage", "TYPE_PLAYER", "TYPE_NPC", "TYPE_OBSTACLE");	//Set candamage.
        changeentityproperty(vSpawn, "hostile", "TYPE_PLAYER", "TYPE_NPC");                     //Set hostile.
    }
    else if (iEType == TYPE_PLAYER || iEType == TYPE_NPC)												//Self player or NPC type?
    {
        changeentityproperty(vSpawn, "candamage", "TYPE_ENEMY", "TYPE_OBSTACLE");				//Set can damage.
        changeentityproperty(vSpawn, "hostile", "TYPE_ENEMY");				                    //Set Hostile.
    }           

    return vSpawn;  
    
}
