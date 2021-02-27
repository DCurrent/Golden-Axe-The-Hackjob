#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import	"data/scripts/com/ani0009.h"	//http://www.caskeys.com/dc/?p=1314#ani0009
#import	"data/scripts/com/dama0001.h"	//http://www.caskeys.com/dc/?p=1314#dama0001
#import	"data/scripts/com/bind0008.h"	//http://www.caskeys.com/dc/?p=1314#bind0008

/*
* Caskey, Damon V.
* 
* 2009_10_10
* ~2011_07_22
* 
* Primary wall function. Damages and bounces self in opposite direction of current
* X velocity when falling and obstructed by wall/platform.
*/
void dc_wall_bounce()
{	
	void acting_ent		= getlocalvar("self");														//Calling entity.
	int iFall		= getentityproperty(acting_ent, "aiflag", "falling");							//Falling flag.
	int damage_force		= 0;																		//Damage to apply on self.
	void opponent_entity;																				//Last interaction.
	int position_direction;																					//Facing setting.
	float velocity_x_old = 0.0;																			//Current X velocity.
	float velocity_x_new = 0.0;																			//Set X velocity.
    float velocity_y = 0.0;
	int	invincible_time = 0+getentityproperty(acting_ent, "invinctime");
	int	elapsed_time = openborvariant("elapsed_time");

	/*
	* Falling and not currently invincible?
	*/
	if (iFall && invincible_time < elapsed_time)
	{													
		/* 
		* Give entity a very short window of invincibility
		* so it can't spam the wall damage. 
		*/
		changeentityproperty(acting_ent, "invinctime", invincible_time+20+elapsed_time);

		/*
		* If we are moving right, then we'll bounce
		* to left and vice versa. The bounce velocity 
		* is 50% of original velocity so entity won't
		* bounce between walls forever or be TOO easy
		* to juggle.
		* 
		* We also aply some damge to the entity as 
		* a % of the velocity. If the entity is moving
		* left, we need to resign so the damage isn't
		* negative.
		*/

		velocity_x_old = getentityproperty(acting_ent, "xdir");

		if (velocity_x_old >= 0)																			
		{
			position_direction	= 2;																		
			velocity_x_new	= (-velocity_x_old) * 0.5;															
			velocity_y	= velocity_x_old * 1.5;
			damage_force	+= (velocity_x_old * 3);																
		}
		else																					
		{
			position_direction	= -2;																		
			velocity_x_new	= (-velocity_x_old) * 0.5;															
			velocity_y	= (-velocity_x_old) * 1.5;
			damage_force += ((-velocity_x_old) * 3);															
		}

		/* Spawn a flash and then apply damage. */
		bind0008("hith", "hith", 0, 1, 0, 0, 0, 0, 0, 0, 1);									
		dama0001(acting_ent, damage_force, 100, openborconstant("ATK_NORMAL"), position_direction, 0, 0, 0, 0, 0, 0);

		/* 
		* Put entity into its normal fall animation if
		* it has one and apply the new velocity.
		*/

		if (getentityproperty(acting_ent, "animvalid", openborconstant("ANI_FALL")) && !getentityproperty(acting_ent, "dead"))
		{
			changeentityproperty(acting_ent, "animation", openborconstant("ANI_FALL"));
		}

		tossentity(acting_ent, velocity_y, velocity_x_new, 0);
	}
}

/*
	else
    {
        iType = getentityproperty(acting_ent, "type");                                                   //Get type.

        if (iType == TYPE_NPC || iType == TYPE_ENEMY)														//Enemy or NPC?
        {
            iBase   = getentityproperty(acting_ent, "base");                                             //Get base.
            iWHt    = getlocalvar("height");                                                        //Get wall height.

            if (iWHt - iBase < 75)                                                                  //Not too high to jump?
            {
                iAni = getentityproperty(acting_ent, "animationid");                                     //Get current animation.
                if (iAni == A_UP)																	//Walking up?
                {
                    changeentityproperty(acting_ent, "velocity", 0,0,0);                                 //Stop walking movement.
                    ani0009(acting_ent, AC_CLIMBUPB, 0);													//Perform Lateral climb/jump up.
                }
                else if (iAni == A_DOWN)															//Walking down?
                {
                    changeentityproperty(acting_ent, "velocity", 0,0,0);                                 //Stop walking movement.
                    ani0009(acting_ent, AC_CLIMBDNB, 0);													//Perform Lateral climb/jump down.
                }
            }
        }
    }
	*/





