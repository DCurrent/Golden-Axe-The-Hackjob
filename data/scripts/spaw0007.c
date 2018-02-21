/*Dust spawn.

Manipulate jumpstart/jumpframe "dust" entity to produce appropriate visual and sound effects.

*/

#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/draw0001.h"
#import "data/scripts/com/draw0005.h"
#import "data/scripts/com/soun0005.h"

void main(){

    void    vSelf   = getlocalvar("self");    
    int     iCount;
    int     iMaxVar = openborvariant("maxentityvars");
    int     iMap;
    float   fScaleX;
	float   fScaleY;
	int	    iBlend;
    
    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }
     
    changeentityproperty(vSelf, "autokill", 1);                                 //Make sure autokill property is on.
    
    //if (vAlias == "0")															//Stage check
    //{
        iBlend  = 1;                                                            //Set blend.
	    iMap	= 0;															//Set map.		    
	    soun0005(vSelf, SND_LANDM, -1, 1, 0, 0);							        //Set sound.
	    fScaleX = 0.5;															//X scale.
	    fScaleY = 0.5;															//Y scale.            
    //}
	            
    draw0005(vSelf, fScaleX, fScaleY, 0, 0, 0, iBlend, iMap, 0, 0, 0);
    draw0001(vSelf);    
}


