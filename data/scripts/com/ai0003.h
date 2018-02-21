#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

int ai0003(void self)
{
    /*
    ai0003
    Utunnels
    xxxx2006
    
    Keep AI character in playfield (screen).
    */

    if(getentityproperty(self, "animnum")!=A_SPAWN && getentityproperty(self, "x")>0 && getentityproperty(self, "x")<openborvariant("xpos"))
    {
	    changeentityproperty(self, "invincible", 0);
	    changeentityproperty(self, "invinctime", 0);
	    changeentityproperty(self, "velocity", 0, 0, 0);
	    changeentityproperty(self, "subject_to_screen", 1);
        changeentityproperty(self, "animation", A_SPAWN);
        changeentityproperty(self, "stealth", 0);
        return 1;
    }
    else
    {
        return 0;
    }
}

