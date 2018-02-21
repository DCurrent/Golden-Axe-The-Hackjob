#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/dust0001.h"
#import "data/scripts/com/kill0001.h"

void main()
{
	dust0001("dust0001");	                           
	void vSelf = getlocalvar("self");
	void vBinde = getentityvar(vSelf, IDXE_BINDE);		   //Get any bound effect.
            
    if (getentityproperty(vBinde, "exists"))           //Bound effect exists?
    { 
        killentity(vBinde);                            //Then kill it.
    }

    kill0001();    
}
