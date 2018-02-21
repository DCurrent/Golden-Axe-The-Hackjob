#import "data/scripts/com/hit0004.h"	//http://www.caskeys.com/dc/?p=1314#hit0004

void main()
{  
	void	vEnt;
	void	vPar;
	float fPX;
	float fPY;
	float fPZ;
	float fX;
    float fZ;
    float fY;
    float fVX;
    float fVY;
    float fVZ;	
	int		iDir;
	int		iPDir;

	if(!vEnt)
	{
		vEnt = getlocalvar("self");
	}
	
	if(!vPar)
	{
		vPar = getentityproperty(vEnt, "owner");
	}
	
	fX	= getentityproperty(vEnt, "x");
    fZ	= getentityproperty(vEnt, "z");
    fY	= getentityproperty(vEnt, "a");
    fVX	= getentityproperty(vEnt, "xdir");
    fVY	= getentityproperty(vEnt, "tossv");
    fVZ	= getentityproperty(vEnt, "zdir");	
	iDir	= getentityproperty(vEnt, "direction");
	iPDir	= getentityproperty(vPar, "direction");	
	
	hit0004(vPar);	

	if(fVX > 0 && iDir == iPDir)
	{		
		changeentityproperty(vEnt, "direction", 0);
	}
	if(fVX < 0 && iDir == iPDir)
	{		
		changeentityproperty(vEnt, "direction", 1);
	}
	
}