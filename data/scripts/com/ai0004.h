#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void ai0004(int a, int b, int c, int d, int e, int f)
{
    
    /*
    ai0004
    Damon V. Caskey, copied from changedir() by utunnels.
    05102010

    Find way around wall by changing direction as appropriate.

    a-f: Expansion.
    */


    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float a = getentityproperty(self, "a");
    float va = getentityproperty(self, "tossv");
    float vx = getentityproperty(self, "xdir");
    float vz = getentityproperty(self, "zdir");
    int d = getentityproperty(self, "direction");
    float wall;
    if(vx>0)
    {
        wall = checkwall(4 + x, z);
        if( wall>a || (wall==0 && checkhole(4 + x, z)) )
        {
            d=0;vx=-1.6;
        }
    }
    else if(vx<0)
    {
        wall = checkwall(x-4, z);
        if( wall>a || (wall==0 && checkhole(x-4, z)) )
        {
            d=1;vx=1.6;
        }
    }
    if(getentityproperty(self, "animationid")== A_WALK && !vx)
    {
        wall = checkwall(x, 8 + z);
        if( 8 + z > openborvariant("player_max_z") || wall>a || (wall==0 && checkhole (x, 8 + z)) )
        {
            vz = -0.8;
            changeentityproperty(self, "animation", A_UP);
        }
    }
	else if(getentityproperty(self, "animationid")== A_UP )
	{
        wall = checkwall(x, z-8);
        if(z-8 < openborvariant("player_min_z") || wall>a || (wall==0 && checkhole (x, z-8)) )
        {
            vz = 0.8;
            changeentityproperty(self, "animation", A_WALK);
        }
	}
    changeentityproperty(self, "velocity", vx, vz, va);
    changeentityproperty(self, "direction", d);
}
