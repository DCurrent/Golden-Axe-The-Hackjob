#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import	"data/scripts/com/ani0009.h"	//http://www.caskeys.com/dc/?p=1314#ani0009
#import	"data/scripts/com/dama0001.h"	//http://www.caskeys.com/dc/?p=1314#dama0001
#import	"data/scripts/com/bind0008.h"	//http://www.caskeys.com/dc/?p=1314#bind0008

void wall0001()
{
	/*
	wall0001
	Damon Vaughn Caskey
	2009_10_10
	~2011_07_22
	Primary wall function. Damages and bounces self in opposite direction of current
	X velocity when falling and obstructed by wall/platform.
	*/

	void vSelf		= getlocalvar("self");														//Calling entity.
	int iFall		= getentityproperty(vSelf, "aiflag", "falling");							//Falling flag.
	int iDamage		= 0;																		//Damage to apply on self.
	void vOpponent;																				//Last interaction.
	int iDir;																					//Facing setting.
	float iXDir = 0.0;																			//Current X velocity.
	float iXVel = 0.0;																			//Set X velocity.
    float iYVel = 0.0;
	int iAni;                                                                                   //Current animation.
    int iType;                                                                                  //Entity type.
    int iWHt;                                                                                   //Wall height.
    int iBase;                                                                                  //Current base.
	int	iITime = 0+getentityproperty(vSelf, "invinctime");
	int	iETime = openborvariant("elapsed_time");

	if (iFall && iITime < iETime)																//Falling and no invinctime?
	{
		iXDir		= getentityproperty(vSelf, "xdir");											//Get current X velocity.
		vOpponent	= getentityproperty(vSelf, "opponent");										//Get last interaction.

		changeentityproperty(vSelf, "invinctime", iITime+20+iETime);

		if (iXDir >= 0)																			//Moving Right?
		{

			iDir	= 2;																		//Set facing right.
			iXVel	= (-iXDir) * 0.5;															//Set movement left.
			iYVel	= iXDir * 1.5;
			iDamage	+= (iXDir * 3);																//Set damage (Velocity * 3).
		}
		else																					//Moving left.
		{
			iDir	= -2;																		//Set facing left.
			iXVel	= (-iXDir) * 0.5;															//Set movement right.
			iYVel	= (-iXDir) * 1.5;
			iDamage += ((-iXDir) * 3);															//Set damage (Resigned velocity * 3).
		}

		bind0008("hith", "hith", 0, 1, 0, 0, 0, 0, 0, 0, 1);									//Spawn flash.
		dama0001(vSelf, iDamage, 100, openborconstant("ATK_NORMAL"), iDir, 0, 0, 0, 0, 0, 0);							//Apply damage to self.

		changeentityproperty(vSelf, "animation", A_FALL);										//Reset fall.
		tossentity(vSelf, iYVel, iXVel, 0);														//Toss self.
	}
}

/*
	else
    {
        iType = getentityproperty(vSelf, "type");                                                   //Get type.

        if (iType == TYPE_NPC || iType == TYPE_ENEMY)														//Enemy or NPC?
        {
            iBase   = getentityproperty(vSelf, "base");                                             //Get base.
            iWHt    = getlocalvar("height");                                                        //Get wall height.

            if (iWHt - iBase < 75)                                                                  //Not too high to jump?
            {
                iAni = getentityproperty(vSelf, "animationid");                                     //Get current animation.
                if (iAni == A_UP)																	//Walking up?
                {
                    changeentityproperty(vSelf, "velocity", 0,0,0);                                 //Stop walking movement.
                    ani0009(vSelf, AC_CLIMBUPB, 0);													//Perform Lateral climb/jump up.
                }
                else if (iAni == A_DOWN)															//Walking down?
                {
                    changeentityproperty(vSelf, "velocity", 0,0,0);                                 //Stop walking movement.
                    ani0009(vSelf, AC_CLIMBDNB, 0);													//Perform Lateral climb/jump down.
                }
            }
        }
    }
	*/





