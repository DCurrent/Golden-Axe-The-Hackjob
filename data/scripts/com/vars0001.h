#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void vars0001(void vTarget, int iBindBreak, int B, int C, int D, int E){

    /*
    vars0001
    Damon Vaughn Caskey
    01292009
    Cleans all entity vars.

    vTarget: Entity to clean vars from.
    A-E:     Reserved.
    */

    int iCount;                                            //Loop counter.
    int vBound;                                            //Bound entity placeholder.
    int iMax = openborvariant("maxentityvars");            //Entity var count.

    if (iBindBreak)
    {
        vBound  = getentityvar(vTarget, IDXE_BIND);              //Get bound entity (if any).    
        if (vBound)
        {
            //bind0004(vBound, 0, 0, 0, 13, 0);               //Release bound entity.
        }    
    }

    for (iCount = 0; iCount <= iMax; iCount++)
    {
        setentityvar(vTarget, iCount, NULL());
    }    
}

