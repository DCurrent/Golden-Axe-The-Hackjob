void debu0003(void vEnt)
{
	

	float	fX;
	float	fY;
	float	fZ;
	float	fVX;
	float	fVY;
	float	fVZ;
	
	if(!vEnt){	vEnt	=	getlocalvar("self");	}

	
	fX	= getentityproperty(vEnt, "x");
	fY	= getentityproperty(vEnt, "a");
	fZ	= getentityproperty(vEnt, "z");

	fVX = getentityproperty(vEnt, "xdir");
	fVY = getentityproperty(vEnt, "tossv");
	fVZ = getentityproperty(vEnt, "zdir");

	log("\n debug0003: X(" + fX + "), Y(" + fY + ") Z(" + fZ +")");
	log("\n debug0003: vX(" + fVX + "), vY(" + fVY + ") vZ(" + fVZ +")");
	
}
