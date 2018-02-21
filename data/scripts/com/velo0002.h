void velo0002(void vEnt, float fXM, float fZM, float fYM){
     
    /*
    velo0002 - http://www.caskeys.com/dc/?p=1314#velo0002
	Damon Vaughn Caskey		
    2011_08_12

	Set velocity to X% of current.
	
	vEnt:	Target entity.
	fXM:	X axis modifier.
	fZM:	Z axis modifier.
	fYM:	Y axis modifier.
	*/
	
	void vEnt = getlocalvar("self");						//Calling entity.
	
	float fX, fY, fZ;
	
	/*
	Default to caller if Ent not passed.
	*/
	if(!vEnt)
	{
		vEnt = getlocalvar("self");
	}


	fX	= getentityproperty(vEnt, "xdir");					//Get X velocity.						
	fY  = getentityproperty(vEnt, "tossv");					//Get Y velocity.
	fZ  = getentityproperty(vEnt, "zdir");					//Get Z velocity.

	if(fXM){	fX = fX * fXM;	}
	if(fYM){	fY = fY * fYM;	}
	if(fZM){	fZ = fZ * fZM;	}	
	
	changeentityproperty(vEnt, "velocity", fX, fZ, fY);	//Apply movement.

}