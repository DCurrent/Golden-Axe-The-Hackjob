#include "data/scripts/dc_kanga/main.c"

void main()
{
    void vSelf      = getlocalvar("self");
    int  iZ         = getentityproperty(vSelf, "z");

    if (iZ < openborvariant("PLAYER_MIN_Z")){                       //Past min boundry?
        changeentityproperty(vSelf, "setlayer", -9);                //Layer behind floor panels and obstacles.
        changeentityproperty(getlocalvar("self"), "gfxshadow", 0);  //No shadow.

        dc_kanga_z_position_autoscale(vSelf);                                                //Run draw function for Z zooming.
    }
	else
	{
		changeentityproperty(vSelf, "setlayer", 0);					//Normal layer.
        changeentityproperty(getlocalvar("self"), "gfxshadow", 1);  //Shadow.
	}

	if (iZ > openborvariant("PLAYER_MAX_Z"))
    {
        dc_kanga_z_position_autoscale(vSelf);
    }

    //dc_kanga_z_position_autoscale(vSelf);                                                //Run draw function for Z zooming.
}

