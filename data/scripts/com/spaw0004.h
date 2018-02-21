#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void spaw0004()
{

    //Copy of Golden Axe Remake "Wake" function.

    void self = getlocalvar("self");
    if(getentityproperty(self, "x")<=0 || getentityproperty(self, "x")>=openborvariant("hresolution"))
    {
        changeentityproperty(self, "invincible", 1);
        changeentityproperty(self, "invinctime", 2000000+openborvariant("elapsed_time"));
        if(getentityproperty(self, "x")<openborvariant("hresolution")/2)
        {
            changeentityproperty(self, "velocity", 0.6, 0, 0);
        }
        else
        {
            changeentityproperty(self, "velocity", -0.6, 0, 0);
        }
		changeentityproperty(self, "stealth", 0);
        changeentityproperty(self, "animation", A_WALK);
        return 1;
    }
    return 0;
}
