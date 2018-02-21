#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/trailerd.c"

//cache most often used things here
void main()
{
	tclear();
    setindexedvar(IDXG_INLVL, 0); // in level flag
    if(getindexedvar(16)) // free mpicon
    {
        free(getindexedvar(16));
        setindexedvar(16, NULL());
    }
}
