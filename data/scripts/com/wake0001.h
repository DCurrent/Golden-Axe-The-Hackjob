#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009

void wake0001()
{
    /*
	Copy of Golden Axe Remake "Wake" function, with just a bit of optimising.
	When entity is out of screen, turns them back, starts walk animation,
	and sets stealth/invinsibility.
	*/

    void	self	= getlocalvar("self");						//Caller.
    int		iResH	= openborvariant("hresolution");			//Horizontal resolution.
	float	fX		= getentityproperty(self, "x");				//Caller X location.
	
	if(fX<=0 || fX>=iResH)										//Outside of screen?
    {        
		if(fX < iResH/2)										//Outside screen to left?
        {
            changeentityproperty(self, "velocity", 0.6, 0, 0);	//Start moving to right.
        }
        else													//Outside screen to right?
        {
            changeentityproperty(self, "velocity", -0.6, 0, 0);	//Start moving to left.
        }
	
		changeentityproperty(self, "invincible", 1);
        changeentityproperty(self, "invinctime", 2000000+openborvariant("elapsed_time"));
		changeentityproperty(self, "stealth", 0);
        ani0009(self, A_WALK, -1);
        return 1;
    }
    return 0;
}
