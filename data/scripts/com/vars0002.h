#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void vars0002(int iVar, int iVal)
{
    /*
    vars0002
	Damon Vaughn Caskey
	08/02/2007	
	sets entity var by index.
    */

    void vSelf = getlocalvar("self");

    setentityvar(vSelf, iVar, iVal);

}

