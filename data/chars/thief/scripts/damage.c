#include "data/scripts/vars/constants.h"

#import "data/scripts/com/dama0002.h"	//Global damage function.
#import "data/scripts/com/spaw0005.h"  //Spawn entity with toss.

void main()
{
    void vSelf	= getlocalvar("self");
    void vAtk	= getlocalvar("attacker");
    char cName	= getentityproperty(vSelf, "name");

    if(vSelf != vAtk)
    {
        if(cName == "BlueThief")
        {
            spaw0005("Magic_Pot",0,0,0,0,0,0);
        }
		else if(cName == "GrayThief")
        {
            spaw0005("time",0,0,0,0,0,0);
        }
        else
        {
            spaw0005("meat",0,0,0,0,0,0);
        }

        damageentity(vSelf, vSelf, 1, 1, openborconstant("ATK_NORMAL10"));
    }

	dama0002();                                                                 //Run global damage function.

}
