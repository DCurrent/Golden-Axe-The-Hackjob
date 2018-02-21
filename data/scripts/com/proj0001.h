#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/proj0002.h"

void proj0001(void vName, float fX, float fZ, float fY, float iXSpeed, float iYSpeed, float iZSpeed, int iType, int iPType, int iScaleX, int iScaleY, int iFlipX, int iFlipY, int iShiftX, int iBlend, int iMap, int iFill, int iRotate, int iFlip){
     	
    /*
    proj0001
    Damon Vaughn Caskey
	2008_02_11
	~2011_05_11

    Launch projectile with all draw adjustments.

    vName:         projectile model name.
    fX, fY, fZ:    Spawn location adjustment.
    iX/Y/ZSpeed:   Speed adjustment of projectile (as of 02112008, X speed is ignored for knife types).
    iType:         Unknown.
    iPType:        Projectile launch type. 0 = knife, 1 = bomb.

    See draw0001() for following:
    iScaleX adjustment.
    iScaleY adjustment.
    Flip X.
    Flip Y.
    Shift X.
    Alpha.
    iMap.
    Fill color.
    Rotation.     
    */
        
    void vProj = proj0002(vName, fX, fZ, fY, iXSpeed, iYSpeed, iZSpeed, iType, iPType, iFlip);  //Call proj0001 to do basic projectile launch.
    int  iDir  = getentityproperty(vProj, "direction");                                         //Projectile's direction. This will have already been set up by proj0002 function.

    changeentityproperty(vProj, "map", iMap);		//Set remap color.
	changeentityproperty(vProj, "alpha", iBlend);	//Set transparency.


    //Store settings for draw function.                     
    if (iScaleX){ setentityvar(vProj, IDXE_ADSCALEX, iScaleX); }     //iScaleX adjustment.
    if (iScaleY){ setentityvar(vProj, IDXE_ADSCALEY, iScaleY); }     //iScaleY adjustment.
    if (iFlipX) { setentityvar(vProj, IDXE_ADFLIPX,  iFlipX);  }     //Flip X.
    if (iFlipY) { setentityvar(vProj, IDXE_ADFLIPY, iFlipY);   }     //Flip Y.
    if (iShiftX){ setentityvar(vProj, IDXE_ADSHIFTX, iShiftX); }     //Shift X.
    if (iFill)  { setentityvar(vProj, IDXE_ADFILL, iFill);     }     //Fill color.   
    
    if (iRotate)
    {    
       if (!iDir) { iRotate = -iRotate; }                       //Reverse rotation.
       setentityvar(vProj, IDXE_ADROTATE, iRotate);                  //Set Rotation.    
    }
}
