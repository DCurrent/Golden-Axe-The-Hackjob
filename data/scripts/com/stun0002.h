#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void stun0002(void vAni){

     /*
     stun0003
     Damon Vaughn Caskey
     06132008     
     Sets requested animation and does NOT reset stun on caller if stun factor is -1.
     
     vAni: Stun animation.
     */

     void vSelf = getlocalvar("self");                      //Calling entity. 
     int  iStun = getentityvar(vSelf, 1);                   //Previous stun factor.
     
     if (iStun == -1){                                      //Stun is -1? Dizzy; your screwed!
         performattack(vSelf, openborconstant(vAni), 1);    //Set animation.
     }     
}