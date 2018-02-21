#include	"data/scripts/vars/constants.h"	//Constants list.

#import	"data/scripts/com/bind0010.h"	//http://www.caskeys.com/dc/?p=1314#bind0010  
#import	"data/scripts/com/bind0019.h"	//Grapple binding release.
#import	"data/scripts/com/dama0001.h"	//Damage entity.
#import	"data/scripts/com/effe0001.h"	//Damage effects.
#import	"data/scripts/com/hit0001.h"
#import	"data/scripts/com/parr0001.h"	//Parry functions.
#import	"data/scripts/com/soun0005.h"	//Stereo sound player.

void dama0002(){

    //Global take damage function; called by almost all entities when they take damage.

    void    vSelf       = getlocalvar("self");                                  //Calling entity.
    void    vAttacker   = getlocalvar("attacker");                              //Damaging entity.
    int     iAType      = getlocalvar("attacktype");                            //Incomming attack type.
    int     iDrop       = getlocalvar("drop");                                  //Incomming attack drop power.
    int     iAni        = getentityproperty(vSelf, "animationid");              //Current animation.
    float   fDam        = 0.0+getlocalvar("damage");                            //Incoming damage.
    float   fHP         = 0.0+getentityproperty(vSelf, "health");               //Hitpoints.
    float	fMaxHP		= 0.0+getentityproperty(vSelf, "maxhealth");			//Max hitpoints.
	int		iDir, iI, iF;														//Bound direction setting, index, and frame.
 	int     iAni, iPos, iLnd;													//Animation, frame, land frame.
	int		fX, fZ;																//Caller location.
    int     iHPTemp;

	int iHPOld;
	
		

    /*
    //If attacker is a projectile, set opponent to the attacker's parent.
    if(getentityproperty(vAttacker, "type") == openborconstant("TYPE_OBSTACLE"))
    {
        if(getentityproperty(vAttacker, "mp"))
        {
            changeentityproperty(vSelf, "opponent", getentityproperty(vAttacker, "parent"));
        }
    }

    hit0001(0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);                            //Erase hit flags.                                                                //Remove special hit flags. This is in case caller is hit out of an attack with flags.

    if (parr0001(vAttacker, iDam)) { return; }                                  //Parry for unblockable attack. See parr0001 for details.
    */

    bind0019(vSelf);															//Release all grappled entities.

	if(getentityproperty(vSelf, "type") == TYPE_ENEMY)
	{
		changeentityproperty(vSelf, "hostile", "TYPE_PLAYER", "TYPE_NPC");      //Reset hostile.		
	}

	if (!fDam){ return; }														//If damage isn't "real", forget the rest.

	if(fHP > 0)																	//Damage is survivable?
	{
		iAni = getentityproperty(vSelf, "animationid");							//Get animation.
		iPos = getentityproperty(vSelf, "animpos");								//Get current frame.
		iLnd = getentityproperty(vSelf, "landframe", iAni);						//Get landframe.

        if (iPos != iLnd)														//Not landing?
        {
            if (iDrop > 0)                                                      //Knockdown hit?
		    {
				if (iAType == ATK_BURN
                    && iAni != A_BURN)											//Burn hit and not already burning?
			    {
				    soun0005(vSelf, VOI_BRN, -1, 1, 0, 0);						//Burn sound.
			    }
			    else
			    {
				    if ((fHP / fMaxHP) <= 0.25 )								//Damage below 25% max health?
				    {
					    soun0005(vSelf, VOI_DYN, -1, 1, 0, 0);		            //Dying sound (always).
				    }
				    else
				    {
						soun0005(vSelf, VOI_PN, -1, 1, 0, 0);					//Pain sound (always).
				    }
			    }
		    }
		    else
		    {
				soun0005(vSelf, VOI_PN, -1, 0.5, 0, 0);							//Pain sound (50%).
		    }
        }
        else
        {
		    if ((fHP / fMaxHP) <= 0.25 )										//Damage below 25% max health?
		    {
			    soun0005(vSelf, VOI_DYN, -1, 1, 0, 0);							//Dying sound (always).
		    }
		    else
		    {
			    soun0005(vSelf, VOI_PN, -1, 1, 0, 0);							//Pain sound (always).
		    }
	    }
	}
	else
	{

		fX	= getentityproperty(vSelf, "x");									//Get X location.
		fZ	= getentityproperty(vSelf, "z");									//Get Z location.

		if(checkhole(fX, fZ))													//In a pit?
		{
			soun0005(vSelf, VOI_PIT, -1, 1, 0, 0);								//Pit KO sound (always).
		}
		else
		{
			soun0005(vSelf, VOI_DIE, -1, 1, 0, 0);								//KO sound (always).
		}
	}
}
