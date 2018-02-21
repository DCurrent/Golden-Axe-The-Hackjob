#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void hit0001(int iDamage, int iFinish, void vType, float fTossX, float fTossY, float fTossZ, int iDrop, int iReset, int iWarpX, int iWarpY, int iWarpZ, int iWarpT, int M){

    /*
    hit0001
    Damon Vaughn Caskey
    11292007
    Sets up damage and other effects to be applied during didhitscript.
    */

    void vSelf = getlocalvar("self");    

    if(vType == -2)                               //If attack type = -2, delete all hit flags.
    {
        setentityvar(vSelf, IDXE_HITDMG,   NULL());    //Damage.
        setentityvar(vSelf, IDXE_HITFIN,   NULL());    //Leathal/non leathal damage.
        setentityvar(vSelf, IDXE_HITTYP,   NULL());    //Attack type.
        setentityvar(vSelf, IDXE_HITDRP,   NULL());    //Drop.
        setentityvar(vSelf, IDXE_TOSSX,    NULL());    //Toss X
        setentityvar(vSelf, IDXE_TOSSY,    NULL());    //Toss Y
        setentityvar(vSelf, IDXE_TOSSZ,    NULL());    //Toss Z
        setentityvar(vSelf, IDXE_HITNOR,   NULL());    //Remove flags on hit toggle.
        setentityvar(vSelf, IDXE_HITWRX,   NULL());    //Move defender to attacker with X adjust.
        setentityvar(vSelf, IDXE_HITWRY,   NULL());    //Move defender to attacker with Y adjust.
        setentityvar(vSelf, IDXE_HITWRZ,   NULL());    //Move defender to attacker with Z adjust.
        setentityvar(vSelf, IDXE_HITWRT,   NULL());    //Only move if in pain or fall.
    }
    else
    {
        setentityvar(vSelf, IDXE_HITDMG,   iDamage);   //Damage.
        setentityvar(vSelf, IDXE_HITFIN,   iFinish);   //Leathal/non leathal damage.
        setentityvar(vSelf, IDXE_HITTYP,   vType);     //Attack type.
        setentityvar(vSelf, IDXE_HITDRP,   iDrop);     //Drop.
        setentityvar(vSelf, IDXE_TOSSX,    fTossX);    //Toss X
        setentityvar(vSelf, IDXE_TOSSY,    fTossY);    //Toss Y
        setentityvar(vSelf, IDXE_TOSSZ,    fTossZ);    //Toss Z
        setentityvar(vSelf, IDXE_HITNOR,   iReset);    //Remove flags on hit toggle.
        setentityvar(vSelf, IDXE_HITWRX,   iWarpX);    //Move defender to attacker with X adjust.
        setentityvar(vSelf, IDXE_HITWRY,   iWarpY);    //Move defender to attacker with Y adjust.
        setentityvar(vSelf, IDXE_HITWRZ,   iWarpZ);    //Move defender to attacker with Z adjust.
        setentityvar(vSelf, IDXE_HITWRT,   iWarpT);    //Only move if in pain or fall.
    }
}