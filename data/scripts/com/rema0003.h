#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants         
#import "data/scripts/com/targ0001.h"

void rema0003(void vTar, int iTime, void vMap){

    /*
    mapko
    Damon Vaughn Caskey
    08/23/2008
    Map designated target from list of constants.

    vTar: Target. See targ0001 function.
    */

    void vSelf      = getlocalvar("self");  //Caller.
    void vTarget    = targ0001(vTar, vSelf); //target.

    if      (vMap == "MAP_KO")       { vMap = MAP_KO;       }   //KO.
    else if (vMap == "MAP_BURN")     { vMap = MAP_BURN;     }   //Burn.
    else if (vMap == "MAP_SHOCK")    { vMap = MAP_SHOCK;    }   //Shock.
    else if (vMap == "MAP_FREEZE")    { vMap = MAP_FREEZE;    }   //Freeze.
    else if (vMap == "MAP_POISON")     { vMap = MAP_POISON;     }   //Poison.

    if (iTime)
    {                                                                                       //Time provided? If so, map will be temporary.
        changeentityproperty(vTarget, "colourmap", vMap);                                   //Set temporary map.
        changeentityproperty(vTarget, "maptime", openborvariant("elapsed_time") + iTime);   //Set temporary maptime.
    }
    else
    {                                                                                       //No time provided. Map will be permenant.
        changeentityproperty(vTarget, "map", vMap);                                         //Set map.
    }
}
