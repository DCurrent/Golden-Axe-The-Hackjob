#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/com/bind0023.h"
#import "data/scripts/com/dama0001.h"

void z_blocko(void vEnt)
{
    /*
    z_blocko
    Damon Vaughn Caskey
    2009_11_13
    ~2011_02_25

	Primary obstacle function. Run for most entities when movement is blocked by an obstacle entity.
    */

    int     iFall;																						//Falling flag.
    int     iDamage		= 0;																			//Damage to apply on self.
	void    vOpp;																						//Last interaction.
    void    vObstacle;																					//Blocking entity.
    int     iDir;																						//Facing setting.
    int     iXDir;																						//Current X velocity.
    int     iXVel;																						//Set X velocity.
    int     iOHeight;																					//Obstacle height.
    int     iY;																							//Self Y location.
	int		iDOL;																						//Damage on landing.
	int		iOHP;																						//Obstacle health.
    int		iRush;																						//Opponent rush count.

	if(!vEnt){	vEnt = getlocalvar("self");	}															//Caller failsafe.

	iFall = getentityproperty(vEnt, "aiflag", "falling");												//Falling flag.

    if (iFall)																							//Falling?
    {
		vObstacle	= getlocalvar("obstacle");															//Get blocking entity.
        iOHeight    = getentityproperty(vObstacle, "height");											//Get obstacle height.
        iY          = getentityproperty(vEnt, "a");														//Get self Y.
		iOHP		= getentityproperty(vObstacle, "health");											//Get obstacle health.

        if (iOHeight > iY)																				//Self lower then obstacle's top?
        {
            iXDir		= getentityproperty(vEnt, "xdir");												//Get current X velocity.
			vOpp		= getentityproperty(vEnt, "opponent");											//Get last interaction.
			iDOL		= getentityproperty(vEnt, "damage_on_landing");									//Get damage on landing value.
			iOHP		= getentityproperty(vObstacle, "health");										//Get obstacle health.
			iRush		= getentityproperty(vOpp, "rush_count");										//Get last interaction's rush count.

			changeentityproperty(vOpp, "rush_count", iRush + 2);										//Add 2 hits to opponent's rush count (one for self, and another for obstacle).

			if (iXDir >= 0)																				//Moving Right?
			{
				iDir	= 2;																			//Set facing right.
				iXVel	= -1.5;																			//Set movement left.
				iDamage	+= (iXDir * 3);																	//Set damage (Velocity * 3).
			}
			else																						//Moving left.
			{
				iDir	= -2;																			//Set facing left.
				iXVel	= 1.5;																			//Set movement right.
				iDamage += ((-iXDir) * 3);																//Set damage (Resigned velocity * 3).
			}

			bind0023(vOpp, "flash", "flash", 0, 1, 0, 0, 0, 0, 0, 0, 1);								//Spawn flash.

            dama0001(vEnt, iDamage+iDOL, 100, openborconstant("ATK_NORMAL"), iDir, 0, 0, 0, 0, 0, 0);							//Apply damage to self.

			if (iOHP > iDamage)																			//Will obstacle survive damage?
			{
				changeentityproperty(vEnt, "animation", openborconstant("ANI_FALL"));										//Reset fall animation.
				tossentity(vEnt, 2.5, iXVel, 0);														//Apply toss values.
			}
            dama0001(vObstacle, iDamage, 100, openborconstant("ATK_NORMAL"), 0, 0, 0, 0, 0, 0, 0);
        }
    }
}
