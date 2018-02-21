#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/targ0001.h"

void ani0007(void vTarget, int vControl, int iMin, int iMax, void vAni){

    /*
    ani0007
    Damon Vaughn Caskey
    06/02/2009
    Change animation if opponent's height is within given threshold.

    iThreshold: Control.
    iMin:       Minimum value.
    iMax:       Maximum value.
    vAni:       New animation.
    */

    void vSelf = getlocalvar("self");                  //Calling entity.
    int  iControl;

    vTarget = targ0001(vTarget, vSelf);
    
    iControl = getentityproperty(vTarget, vControl);

    if (iControl >= iMin && iControl <= iMax){
        changeentityproperty(vSelf, "animation", openborconstant(vAni));
    }

}