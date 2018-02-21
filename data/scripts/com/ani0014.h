#include "data/scripts/vars/constants.h"	
#import "data/scripts/com/ani0009.h"
#import "data/scripts/com/bind0014.h"

void ani0014(void vOpp, int iAni1, int iFrame1, int iTime1, int iAni2, int iFrame2, int iTime2){

	/*
	ani0014
	Damon Vaughn Caskey
	2010_04_03
	~2011_06_19
	If opponent can be grabbed, perform iAni1, otherwise perform iAni2 while setting invinsible time.
	
	vOpp:	Opponent. If not provided, current opponent will be used.
	iAni1:	Animation to perform if opponent can be grabbed.
	iAni2:	Animation to perform if opponent can't be grabbed.
	iTime:	Time to freeze opp (if any) during iAni1.
	iTime2:	Time to make self invinsible (if any) during iAni2.
	*/

	void vSelf = getlocalvar("self");						//Caller.
	int	 iType;												//opponent type.
	int	 iAni;												//Opponents animation.

	if (!vOpp)												//No opponent provided?
	{ 
		vOpp = getentityproperty(vSelf, "opponent");		//Get current opponent.		
	}

	if (!vOpp){ return; }									//failsafe.


	iType = getentityproperty(vOpp, "type");				//Get opponent type.
	changeentityproperty(vSelf, "velocity", 0,0,0);			//Stop movement.
	
	iAni = getentityproperty(vOpp, "animationid");
		
	if (!getentityproperty(vOpp, "nograb")
		&& !getentityproperty(vOpp, "animal")
		&& iAni != A_JUMPLAND
		&& (iType == TYPE_PLAYER
			|| iType == TYPE_ENEMY
			|| iType == TYPE_NPC))		//Legitimate grabbing target?
	{		
	
		bind0014(vOpp, 0);									//Initialize bind variable.	
		if (ani0009(0, iAni1, -1))   			            //Perform iAni1 and check for frame change.
        {
            if(iTime1)
		    {
				iTime1 += openborvariant("elapsed_time") + getentityproperty(vOpp, "freezetime");

				changeentityproperty(vOpp, "frozen", 1);
				changeentityproperty(vOpp, "freezetime", iTime1);				
		    }
            
            if (iFrame1)
            {
                changeentityproperty(vSelf, "animpos", iFrame1);
            }
        }           
    }
	else if(iAni2 != -1)
	{	
		if (ani0009(0, iAni2, -1))   			            //Perform iAni1 and check for frame change.
        {
            if(iTime2)
		    {   
			    changeentityproperty(vSelf, "invincible", 1);
			    changeentityproperty(vSelf, "invinctime", openborvariant("elapsed_time") + iTime2);
		    }
            
            if (iFrame2)
            {
                changeentityproperty(vSelf, "animpos", iFrame2);
            }
        }	
	}
}

