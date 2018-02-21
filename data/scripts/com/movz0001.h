#import "data/scripts/com/draw0001.h"

void movz0001()
{

    void vSelf      = getlocalvar("self");    
    int  iZ;

	if(vSelf)
	{
		iZ = getentityproperty(vSelf, "z");

		if (iZ < openborvariant("PLAYER_MIN_Z")){                       //Past min boundry?
			changeentityproperty(vSelf, "setlayer", -9);                //Layer behind floor panels and obstacles.
			changeentityproperty(vSelf, "gfxshadow", 0);				//No shadow.
		}
		else
		{
			changeentityproperty(vSelf, "setlayer", 0);					//Normal layer.
			changeentityproperty(vSelf, "gfxshadow", 1);				//Shadow.
		}

		

		draw0001(vSelf);                                                //Run draw function for Z zooming.
	}
}

