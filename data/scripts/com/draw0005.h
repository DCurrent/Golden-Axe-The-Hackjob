#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void draw0005(void vTarget, float iScaleX, float iScaleY, int iFlipX, int iFlipY, int iShiftX, int iBlend, int iRemap, int iFill, int iRotate, int iARotat){

     /*
     draw0002
     Damon Vaughn Caskey
	 2008_01_28
	 ~2011_05_17

     Sets passed drawmethod parameters to target.
     */
         
            
     setentityvar(vTarget, IDXE_ADSCALEX,    iScaleX);		//iScaleX adjustment.
     setentityvar(vTarget, IDXE_ADSCALEY,    iScaleY);		//iScaleY adjustment.
     setentityvar(vTarget, IDXE_ADFLIPX,     iFlipX);		//Flip X.
     setentityvar(vTarget, IDXE_ADFLIPY,     iFlipY);		//Flip Y.
     setentityvar(vTarget, IDXE_ADSHIFTX,    iShiftX);		//Shift X.
     changeentityproperty(vTarget, "alpha", iBlend);	//Set transparency.		
     changeentityproperty(vTarget, "map", iRemap);		//Set remap.
	 setentityvar(vTarget, IDXE_ADREMAP,     iRemap);		//Remap.
     setentityvar(vTarget, IDXE_ADFILL,      iFill);			//Fill color.
     setentityvar(vTarget, IDXE_ADROTATE,    iRotate);		//Rotate.
     setentityvar(vTarget, IDXE_ADAROTAT,    iARotat);		//Auto rotation
        
}

