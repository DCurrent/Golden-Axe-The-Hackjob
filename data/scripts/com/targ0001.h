#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void targ0001(void vTarget, void vSelf){
	
	/*
    targ0001
	Damon Vaughn Caskey
	08/02/2007	
	Returns target entity handle from desired source.
	
	vTarget:  Desired target source.
	vSelf:    Entity searching for target.
    */   

    if      (!vTarget)      { return vSelf;                                 }   //Return "self".	
    else if (vTarget == 1)  { return getentityproperty(vSelf, "opponent");  }   //Last entity vSelf interacted with.
    else if (vTarget == 2)  { return getentityproperty(vSelf, "grabbing");  }   //Entity vSelf is holding.
    else if (vTarget == 3)  { return findtarget(vSelf);                     }   //vSelf's Nearest opponent.		
    else if (vTarget == 4)  { return getentityproperty(vSelf, "parent");    }   //vSelf's parrent.
    else if (vTarget == 5)  { return getentityvar(vSelf, IDXE_BIND);             }   //Bound entity.
    else if (vTarget == 6)  { return getentityvar(vSelf, IDXE_BINDHE);           }   //Bound hit effect entity.
    else                    { return vTarget;                               }   //Target was passed directly, return variable.

}
