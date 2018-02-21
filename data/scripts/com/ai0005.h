#import "data/scripts/com/ani0009.h"   //Animation change wrapper.

void ai0005(int iSlot, int iBound, int iAni, int a, int b, int c)
{   
    /*
    ai0005
    Damon V. Caskey, modified from Utunnels countdown().
    05112010
    Increment counter and perform animation when threshold is reached.

    iSlot:  Entity stats slot to store value in. Currently unused.
    iBound: Threshold before animation activates.
    iAni:   Animation to play.
    a-c:    Expansion.
    */

    int ls = getlocalvar("lifespan");
	
    if(ls==NULL())
	{
		ls = 0;
	}
	else if(ls>iBound)
	{		
        ani0009(getlocalvar("self"), iAni, -1); //Change animation.
	}
	else
	{
		ls++;
	}
	setlocalvar("lifespan", ls);
}