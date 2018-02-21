#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009

int ani0021(int iAni, int iTAni){
    
	/*
	ani0021 - http://www.caskeys.com/dc/?p=1314#ani0021
	Damon Vaughn Caskey
	2011_08_12
	Perform alternate animation if target is within range and in specified animation.

	iAni:	Alternate attack.
	iTAni:	Target animation.
	*/

    void vSelf      = getlocalvar("self");					//Caller.                                                         
    void vOpp       = findtarget(vSelf, iAni);				//Nearest target in range of alternate attack.
	
	if (vOpp)												//Found a target?
	{
		if(getentityproperty(vOpp, "animationID") == iTAni)	//Animation match?
		{
			ani0009(vSelf, iAni, 0);						//Perform alternate attack.
			return 1;										//Return 1.
		}
	}

	return 0;												//Return 0.
}