#import "data/scripts/com/ani0009.h" //Verify and switch animation.

void bind0017(void vEnt, int iAni, int iType, int iRem, int A, int B, int C, int D, int E, int F)
{
    /*
    bind0017
    Damon Vaughn Caskey
    05202010
    2010_05_02
    ~2011_06_08
    Find pre existing ent with same default name, and warp to location. Primarly
    for spawning in location of corpse.

    vEnt:   Entity.
    iAni:   Animation.
    iType:  Animation set type (See ani0009).
    iRem:   Remove previous entity?
    A-F:    Expansion.
    */

    void    vSelf   = getlocalvar("self");                              //Caller.
    int     iMax    = openborvariant("ent_max");		                //Current # of entities.
	int		i;                                                          //Counter.
	int		iD;												            //Direction.
    float	fX, fY, fZ;										            //Location coords.
    int     iResH;                                                      //Horizontal resolution.
    int     iLoc;                                                       //Location.

	for(i=0; i<iMax; i++)												//Loop entity collection.
	{
		vEnt    = getentity(i);											//Get entity.
        iResH   = openborvariant("hresolution");                        //Get horizontal resolution.
        iLoc    = openborvariant("xpos");

        if(vEnt															//Valid handle?
			&& getentityproperty(vEnt, "exists")						//Valid entity?
			&& getentityproperty(vEnt, "health") < 1					//Dead?
			&& getentityproperty(vEnt, "defaultname")
			== getentityproperty(vSelf, "defaultname"))					//Same name as self?
		{
			fX = getentityproperty(vEnt, "x");							//Get X.
			fY = getentityproperty(vEnt, "a");							//Get Y.
			fZ = getentityproperty(vEnt, "z");							//Get Z.
			iD = getentityproperty(vEnt, "direction");				    //Get direction.

            if(iRem)
            {
                killentity(vEnt);                                       //Remove previous existing entity.
            }

            if(!checkhole(fX, fZ) && !checkwall(fX, fZ)                 //Location isn't in a hole or wall?
               && !(fX <= iLoc || fX >= iLoc+iResH))                    //Location isn't out of screen?
            {
			    changeentityproperty(vSelf, "direction", iD);			//Set direction to self.
			    changeentityproperty(vSelf, "position", fX, fZ, fY);    //Set location to self.
			    ani0009(vSelf, iAni, iType);                            //Set animation.
            }
		}
	}
}
