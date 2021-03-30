#include	"data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import	"data/scripts/com/bind0010.h"	//Grapple binding.
#import	"data/scripts/com/dama0001.h"	//Damage entity.
    
int bind0019(void vEnt){

	/*
	bind0019
	Damon Vaughn Caskey
	09172010 (seperated from z_damage script)
	Releases all held entities with 0 damage knockdown. By running this whenever an entity
	takes damage, it becomes possible to create throws that are vunerable to outside interference.
    
	vEnt:	Target entity.
	*/

	void	vBind;																//Bound entity.
	int		iCnt = 0;															//Loop counter.
	float	fX, fY, fZ;															//Anchor location.
	float	fOX, fOY, fOZ;														//Bind offset.
	
	if (!vEnt){ vEnt = getlocalvar("self");	}									//Anchor not available? Use caller.

	fX	=	getentityproperty(vEnt, "x");										//Get anchor X.
	fY	=	getentityproperty(vEnt, "a");										//Get anchor Y.
	fZ	=	getentityproperty(vEnt, "z");										//Get anchor Z.

	do                                                                          //Look through bind index.
    {
        vBind   = getglobalvar(vEnt + ".bind." + iCnt);							//Get bound entity from index. 
        
        if (vBind)																//Anything there?
        {
			/*
			While an entity is in one of the throwing poses, it's location is almost certain to be wildly
			different from Self due to the large bind offset needed. We'll have to figure out what that
			offset was, combine with Self's location and move the bound entity there after unbinding.
			Otherwise, the bound entity will appear to teleport whatever distance made up the bind offset.
            */
			fOX = getentityproperty(vBind, "x") - fX;							//Get X bind offset.
            fOY = getentityproperty(vBind, "a") - fY;							//Get Y bind offset.
            fOZ = getentityproperty(vBind, "z") - fZ;							//Get Z bind offset.

			fOY -= 190;															//Adjustment for average cahracter size.
			
			bind0010(0, vEnt, iCnt, 0, 0, 0, 0, openborconstant("ANI_FOLLOW10"), -2, 0);				//Release bind and clear records.
			dama0001(vBind, 0, 100, "ATK_NORMAL", 0, 2, -1, 0, 0, 0, 0);		//Knock bound entity down to reset it.
            changeentityproperty(vBind, "position", fX+fOX, fZ+fOZ, fY+fOY);	//Set location.            
        }
        iCnt++;                                                                 //Increment index.
    }
    while (vBind);																//Continue looping until the bind index slot is blank.

	return iCnt;																//Return number of bound entities discovered.
}