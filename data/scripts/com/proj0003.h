void proj0003(void vModel, int iAX, int iAY, int iAZ, float fX, float fY, float fZ, int iAT, int iSet, int iAM, int iAni)
{		

	
	/*
	proj0003
	Damon Vaughn Caskey
	12292009
	Simplified projectile spawner. Lacks functionality of full "DC" projectile system but very portable.
	
	vModel:			Projectile model name.
	iAX, iAY, iAZ:	Projectile spawn adjustments relative to caller.
	fX:				Projectile speed.
	fY, fZ:			Y and Z velocity adjustments.
	iAT:			Type of spawn (knife or bomb).
	iAM:			Mapping.

	*/
	
	void vSpawn;
	void vSelf	= getlocalvar("self");
	int  iX		= getentityproperty(vSelf, "x");
	int  iY		= getentityproperty(vSelf, "a");
    int  iZ		= getentityproperty(vSelf, "z");
	int  iD		= getentityproperty(vSelf, "direction");
	int  iEType = getentityproperty(vSelf, "type");
	void vAT;												//Color table.

	if (!iD)
	{
		iAX = -iAX;		
	}	    

	vSpawn = projectile(vModel, iX+iAX, iZ+iAZ, iY+iAY, iD, iAT, iSet, iAM);
		
	if (iAM == -1)
	{	
		iAM	= 0;		
		vAT	= getentityproperty(vSelf, "colourmap");

		changedrawmethod(vSpawn, "flag", 1);
		changedrawmethod(vSpawn, "table", vAT);		
	}

    if(!fY) {   changeentityproperty(vSpawn, "antigravity", 1);     }
    if(iAni){   changeentityproperty(vSpawn, "animation", iAni);    }
    
    changeentityproperty(vSpawn, "speed", fX);    
    changeentityproperty(vSpawn, "no_adjust_base", 0);
	changeentityproperty(vSpawn, "velocity", fX, fZ, fY);
	changeentityproperty(vSpawn, "owner", vSelf);	

	return vSpawn;
}
