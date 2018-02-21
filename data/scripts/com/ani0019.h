#import "data/scripts/com/ani0009.h"   //Animation switch wrapper.

void ani0019(int iOX, int iOZ, int iWY, int iCK, int iAni, int iType, int a, int b, int c, int d, int e, int f){
       
	/*
	ani0019
	Damon Vaughn Caskey
	05152010

    Perform alternate animation if nearby wall or hole.
	
    iOX:    X offset from self.
    iOZ:    Z offset from self.
    iWY:    Wall height check.
    iCK:    Check type: 0 = Wall. 1 = Hole. 2 = Both.

    a-f: Expansion.
	*/

    void    vSelf       = getlocalvar("self");                      //Calling entity. 
    
    int     iDir        = getentityproperty(vSelf, "direction");    //Get facing.
	int	    iX          = getentityproperty(vSelf, "x");            //Get self X location.
    int     iZ          = getentityproperty(vSelf, "z");            //Get self Z location.
    int		iB			= getentityproperty(vSelf, "base");			//Get self Base.
	int     iWall;                                                  //Wall height.
    int     iHole;                                                  //Hole flag.
	
    if (!iDir)                                                      //Facing left?
    { 
        iOX = -iOX;                                                 //Invert offset.
    }

    iWall = checkwall(iOX+iX, iOZ+iZ);                              //Get wall.

    if(iWall >= (iWY+iB))											//Wall at or over check threshold?
    {
        ani0009(vSelf, iAni, iType);                                //Switch animation.
    }
}