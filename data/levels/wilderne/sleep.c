#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void main()
{
    int i;
    void p;
    for(i=0; i<3; i++)
    {
        p = getplayerproperty(i, "ent");
        if(p!=NULL())
        {
            changeentityproperty(p, "animation",  AC_SCENENAP);
        }
    }
}
