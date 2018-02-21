/*Dust spawn.

Heavy slam dust spawn.

*/

#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/com/bind0008.h"
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
	void	vSpawn;
    
    for (iCount = 0; iCount <= iMaxVar; iCount++)
    {
         setentityvar(vSelf, iCount, NULL());
    }
     
    changeentityproperty(vSelf, "autokill", 1);																//Make sure autokill property is on.
	vSpawn = bind0008("effe0001", "effe0001", 0, 1, 0, 0, 0, 0, A_FOLLOW1, 0, 1);							//Spawn impact effect.
	draw0005(vSpawn, 1.5, 1.5, 0, 0, 0, 1, 0, 0, 0, 0);
    draw0001(vSpawn);
    
	//if (vAlias == "0")														//Stage check
    //{
        iBlend  = 1;                                                            //Set blend.
	    iMap	= 0;															//Set map.		    
	    soun0005(vSelf, SND_IMPH, -1, 1, 0, 0);							        //Set sound.
	    fScaleX = 1;															//X scale.
	    fScaleY = 1;															//Y scale.            
    //}
	            
    draw0005(vSelf, fScaleX, fScaleY, 0, 0, 0, iBlend, iMap, 0, 0, 0);
    draw0001(vSelf);    
}


