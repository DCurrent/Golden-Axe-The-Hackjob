#include	"data/scripts/vars/constants.h"
#import	"data/scripts/com/jump0003.h"

void ani0013(void vEnt, int iAni, int C){

    /*
    ani0013
    Damon Vaughn Caskey
    2010_03_27
	~2011_03_26

    Switch to jump animation after walking over an edge.

    vEnt:	Target.
	iAni:	Animation.
	C:		Expansion
    */

    float	fY		= getentityproperty(vEnt, "tossv");							//Get vertical velocity.
	float   fX;
	float	fZ;	
    int     iJump   = getentityproperty(vEnt, "aiflag", "jumping");				//Jumping?
    
	if (fY < 0 && !iJump && !getentityproperty(vEnt, "animvalid", A_WALKOFF))	//Y velocity and not jumping and no Walkoff??
	{
        if (iAni == -1 
		|| iAni == A_IDLE
		|| iAni == A_WALK
		|| iAni == A_RUN
		|| iAni == A_UP
		|| iAni == A_DOWN       
        || iAni == A_ATKUP
        || iAni == openborconstant("ANI_ATTACKDOWN")
        || iAni == A_FSPECIAL2)        
        {
			fX      = getentityproperty(vEnt, "xdir");
			fZ      = getentityproperty(vEnt, "zdir") * 0.5;	
			iAni    = A_JUMP;

			if (getentityproperty(vEnt, "animvalid", iAni))
			{
				jump0003(iAni, 0, vEnt);										//Set jump action.
				tossentity(vEnt, 1, fX, fZ);									//Give a little hop.
			}
		}
	}
}


    

