#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void draw0004(float iScaleX, float iScaleY, int iFlipX, int iFlipY, int iShiftX, int iBlend, int iRemap, int iFill, int iRotate, int iARotat){

     /*
     draw0002
     Damon Vaughn Caskey
     2008_01_25
	 ~2011_05_17
     
	 Sets passed drawmethod parameters to caller.
     */
     
     void vSelf = getlocalvar("self"); //Caller.
     
            
     setentityvar(vSelf, IDXE_ADSCALEX,    iScaleX);		//iScaleX adjustment.
     setentityvar(vSelf, IDXE_ADSCALEY,    iScaleY);		//iScaleY adjustment.
     setentityvar(vSelf, IDXE_ADFLIPX,     iFlipX);		//Flip X.
     setentityvar(vSelf, IDXE_ADFLIPY,     iFlipY);		//Flip Y.
     setentityvar(vSelf, IDXE_ADSHIFTX,    iShiftX);		//Shift X.     
	 changeentityproperty(vSelf, "alpha", iBlend);	//Set transparency.
     changeentityproperty(vSelf, "map", iRemap);	//Set remap.
     setentityvar(vSelf, IDXE_ADFILL,      iFill);		//Fill color.
     setentityvar(vSelf, IDXE_ADROTATE,    iRotate);		//Rotate.
     setentityvar(vSelf, IDXE_ADAROTAT,    iARotat);		//Auto rotation
        
}
