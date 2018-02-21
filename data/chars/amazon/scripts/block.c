#include "data/scripts/vars/constants.h"

#import	"data/scripts/com/ani0014.h"	////http://www.caskeys.com/dc/?p=1314#ani0014

void main(){
    
    void vSelf      = getlocalvar("self");                                                  //Calling entity.        
    void vAtk       = getlocalvar("attacker");                                              //Attacking entity.
    int  iType      = getentityproperty(vAtk, "type");                                      //Attacker type.
    int  iTime;                                                                             //Pause/Stall time.

	//Counter throw, or counter attack if opponent can't be grabbed.
	ani0014(vAtk, A_FOLLOW3, 0, 1000, A_ATK2, 0, 400);    
}
