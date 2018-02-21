void debu0002(void vEnt)
{
	/*
	shap0001
	Damon Vaughn Caskey
	01102011
	Draws a box over target entity for collision debug.		
	*/
	    
    int		iAni;       
    int		iStatus; 

	float	fX, fY, fZ;		
	int		iC0, iC1, iC2, iC3, iC4;
	int		iDX, iDY, iDW, iDH; 
	int		iFrame;
	int		iD;
	
	if(openborvariant("in_selectscreen")) {return; }

	vEnt		= getlocalvar("self");						//Caller.
    iAni		= getentityproperty(vEnt, "animationid");	//Current animation.
    iStatus		= getentityvar(vEnt, IDXE_STATUS);				//General status variant.

	fX			= getentityproperty(vEnt, "x") - openborvariant("xpos");
	fY			= getentityproperty(vEnt, "a") + getentityproperty(vEnt, "base");
	fZ			= getentityproperty(vEnt, "z");
	
	iFrame		= getentityproperty(vEnt, "animpos");
	iD			= getentityproperty(vEnt, "direction");

	fX %= (++fX);
	fY %= (++fY);
	fZ %= (++fZ);
		
	fY = -fY;	
	fY += (fZ-4);

	drawdot(fX, fY, fZ+6, rgbcolor(0, 0, 0) , 0);

	iC0 = getentityproperty(vEnt, "bbox", 0, iAni, iFrame, 0);
	iC1 = getentityproperty(vEnt, "bbox", 0, iAni, iFrame, 1);
	iC2 = getentityproperty(vEnt, "bbox", 0, iAni, iFrame, 2);
	iC3 = getentityproperty(vEnt, "bbox", 0, iAni, iFrame, 3);
	iC4 = getentityproperty(vEnt, "bbox", 0, iAni, iFrame, 4);	

	shap0001(fX, fY, fZ+1, iC0, iC1, iC2, iC3, iD, rgbcolor(0, 0, 255));

	iC0 = getentityproperty(vEnt, "attack", "coords", 0, iAni, iFrame, 0);
	iC1 = getentityproperty(vEnt, "attack", "coords", 0, iAni, iFrame, 1);
	iC2 = getentityproperty(vEnt, "attack", "coords", 0, iAni, iFrame, 2);
	iC3 = getentityproperty(vEnt, "attack", "coords", 0, iAni, iFrame, 3);
	iC4 = getentityproperty(vEnt, "attack", "coords", 0, iAni, iFrame, 4);

	shap0001(fX, fY, fZ+2, iC0, iC1, iC2, iC3, iD, rgbcolor(255, 0, 0));

	iC0 = getentityproperty(vEnt, "range", "xmin", iAni, iFrame);
	iC1 = getentityproperty(vEnt, "range", "xmax", iAni, iFrame);
	iC2 = getentityproperty(vEnt, "range", "amin", iAni, iFrame);
	iC3 = getentityproperty(vEnt, "range", "amax", iAni, iFrame);	
	
	//log("\n iC0: " + iC0 + ", iC1: " + iC1 + ", iC2: " + iC2 + ", iC3: " + iC3);

	//drawbox(fX+iC0, fY, (fX-(fX+iC0))+iC1, 10, fZ+1, rgbcolor(121, 0, 215), 1);
	shape0003(fX, fY, fZ+3, iC0, iC1, iC2, iC3, iD, rgbcolor(0, 255, 0));
	shape0004(fX, fY, fZ+4, iC0, iC1, iC2, iC3, iD, rgbcolor(0, 255, 255));
}

void shap0001(int fX, int fY, float fZ, int iC0, int iC1, int iC2, int iC3, int iD, int iColor)
{
	int iDX, iDY, iDW, iDH; 

	if(!iC0 && iC0 != 0){ return; }

	if(!iD)
	{
		iDW =	iC2 - iC0;
		iDX	=	(fX - iC0) - iDW;		
	}
	else
	{
		iDX	=	fX + iC0;		
		iDW =	iC2 - iC0;		
	}

	iDY	=	fY	+ iC1;
	iDH =	iC3 - iC1;		
	
	drawbox(iDX, iDY, iDW, iDH, fZ, iColor , 1);
}

void shape0002(int fX, int fY, int fZ, int iC0, int iC1, int iC2, int iC3, int iD, int iColor){

	int iDX, iDY, iDW, iDH; 

	if(!iD)
	{
		iDX = fX-iC1;
		iDY = fY;
		iDW = (iC1-iC0);
		
		iDH = 10;		
	}
	else
	{
		iDX = fX+iC0;	
		iDY = fY;
		iDW = (iC1-iC0);
		iDH = 10;
	}

	drawbox(iDX, iDY, iDW, iDH, fZ, iColor, 1);
}

void shape0003(int fX, int fY, int fZ, int iC0, int iC1, int iC2, int iC3, int iD, int iColor){

	int iDX, iDY, iDW, iDH; 

	if(!iD)
	{
		iDX = fX-iC1;
		iDW = fX-iC0;				
	}
	else
	{
		iDX = fX+iC0;		
		iDW = fX+iC1;		
	}

	iDY = fY;
	iDH = fY;
		
	drawline(iDX, iDH, iDW, iDY, fZ, iColor, 0);	
}

void shape0004(int fX, int fY, int fZ, int iC0, int iC1, int iC2, int iC3, int iD, int iColor){

	int iDX, iDY, iDW, iDH; 

	if(iC2 < -500 && iC3 > 500)
	{
		iC2 = -10;
		iC3 = 10;
		iColor = rgbcolor(255, 0, 0);
	}

	fY = (fZ - fY)-4;
		
	iDX = fX;
	iDW = fX;				
			
	iDY = fZ;
	iDH = fZ-50;
	
	//log("\n iDY: " + iDY + ", iDH: " + iDH);	
	drawline(iDX, iDY, iDW, iDH, fZ, iColor, 0);	
}