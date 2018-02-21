#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void stun0001(){

     /*
     stun0001
     Damon Vaughn Caskey
     02252008
     Sets stun animation and resets stun on caller if stun factor is -1.
     
     vAni: Stun animation.
     */

     void vSelf = getlocalvar("self");              //Calling entity. 
     int  iStun = getentityvar(vSelf, IDXE_STUNV);     //Previous stun factor.
     
     if (iStun == -1){                      //Stun is -1? Dizzy; your screwed!
         setentityvar(vSelf, IDXE_STUNV, 0);   //Reset stun factor.
         performattack(vSelf, AC_DIZZY, 1);  //Set animation for stun.
     }     
}