#include    "data/scripts/vars/constants.h"

void ai0002()
{
    /*
    ai0002
    Utunnels
    xxxx2006
	~2011_03_27 - #defined constants, clean up.

    Ai controlled caller tries to avoid jump attacks by moving laterally.
    */

	void    vSelf   = getlocalvar("self");
	void    vTarget = findtarget(vSelf);
    int     iAni;
    float   fXDir, fTossv, fZDir;

	if (getentityproperty(vSelf, "type") == TYPE_PLAYER)
	{
	    return;
    }

    if(vTarget)
    {
        iAni   = getentityproperty(vTarget, "animationid");
        fXDir  = getentityproperty(vSelf, "xdir");
        fTossv = getentityproperty(vSelf, "tossv");

        if(iAni == A_JUMPATK || iAni == A_RUNJUMPATK)
        {
            if(getentityproperty(vTarget, "z") > getentityproperty(vSelf, "z"))
            {
                fZDir = -0.1;
            }
            else
            {
                fZDir = 0.1;
            }

            changeentityproperty(vSelf, "velocity", fXDir, fZDir, fTossv);
        }
    }
}
