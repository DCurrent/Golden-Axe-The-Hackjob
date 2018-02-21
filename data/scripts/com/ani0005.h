#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

int ani0005(){

    /*
	ani0005
	Damon Vaughn Caskey
	05/10/2008
	Play animation in "animation" global var if it exists. 
	This function is more or less to get around an issue where changing animation on the same frame a hit 
    occurs instantly crashes the engine. Also useful for setting animations on an event, then playing them 
    in another to get past engine overides.
	*/
	
	void vSelf = getlocalvar("self");           //Calling entity. 
    int  iAni  = getentityvar(vSelf, IDXE_NEXTANI);  //Get animation varible.

    if (iAni)
    {
	   performattack(vSelf, iAni, 1);           //Switch to desired animation.    	
       setentityvar(vSelf, IDXE_NEXTANI, NULL());    //Clear variable.
       return iAni;
    }
    return 0;
}