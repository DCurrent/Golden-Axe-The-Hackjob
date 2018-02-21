#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void init0001(void vEnt){

	/*
	init0001
	Damon Vaughn Caskey
	2010_12_03

	Store an artifical handle and total count of entities spawned.
	*/
	    
    int     iMaxVar = openborvariant("maxentityvars");                          //Maximum vars in use.
    int     iList   = getindexedvar(IDXG_ECOUNT);                                    //Entity counter.
    int     iCount;                                                             //Loop counter.

	if(!vEnt)
	{
		vEnt = getlocalvar("self");												//If no target passed use caller.
	}

    if (!iList)
    {    
        iList = 0;																//Count not initalized, set to 0.
    }
    else
    {
        iList++;																//Count initalized, increment by 1.
    }
    
    setentityvar(vEnt, IDXE_ENTID, iList);											//Set artificial handle.
    setindexedvar(IDXG_ECOUNT, iList);                                               //Set entity counter.    
}