#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/targ0001.h"

void stun0003(void vTar, int iAdd){

     /*
     stun0003
     Damon Vaughn Caskey
     06132008
     Adds stun to target.
     
     vTarget: Target entity
     vAni:    Stun animation.
     */

     void vSelf   = getlocalvar("self");        //Calling entity. 
     void vTarget = targ0001(vTar, vSelf);       //Target entity.
     int  iStun   = getentityvar(vTarget, 1);   //Previous stun factor.
     
     iStun += iAdd; //Add stun.
     
     setentityvar(vTarget, 1, iStun);           //Store new stun value.
}