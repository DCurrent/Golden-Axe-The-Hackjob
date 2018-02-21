#import "data/scripts/com/ani0009.h"

int ani0015(int iAni, int iHP){
    
	/*
	ani0015
	Damon Vaughn Caskey
	Perform alternate attack if target is within range and below health threshold.

	iAni:	Alternate attack.
	iHP:	Health threshold.
	*/

    void vSelf      = getlocalvar("self");				//Caller.                                                  //Calling entity.        
    void vOpp       = findtarget(vSelf, iAni);			//Nearest target in range of alternate attack.
	
	if (vOpp)											//Found a target?
	{
		if(getentityproperty(vOpp, "health") <= iHP)	//At or below health threshold?
		{
			ani0009(vSelf, iAni, 0);					//Perform alternate attack.
			return 1;									//Return 1.
		}
	}

	return 0;											//Return 0.
}
