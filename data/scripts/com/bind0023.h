#import "data/scripts/com/bind0008.h"

void bind0023(int iIndex, char cModel, char cAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iFrame, int iKill){

	/*
	bind0023
	Damon Vaughn caskey
	12092010
	Runs bind0008 for flash entities; replaces requested entity if passed target has custom flash settings.

	iIndex:	target by bound index. See bind0014.
	*/
	void    vSelf   = getlocalvar("self");                                  //Calling entity.	
	int		iFlNo;															//Get target flash property.
	int		iFlMod;															//Get target noatflash property.	
	void    vTarget = getglobalvar(vSelf + ".bind." + iIndex);              //Target entity.

	if(vTarget)																//Valid target?
	{
		iFlNo	= getentityproperty(vTarget, "flash", "noattack");			//Get target noatflash property.
		iFlMod	= getentityproperty(vTarget, "flash", "default");			//Get target flash model.		
		
		if(iFlNo)															//Noatflash property?
		{
			cModel	= getmodelproperty(iFlMod, 1);							//Override flash request with target's custom flash
			iMap	= NULL();
			iBlend	= NULL();
			iAni	= 0;
			iFrame	= 0;
		}		
	}

	return bind0008(cModel, cAlias, iMap, iBlend, fAX, fAY, iAZ, iDir, iAni, iFrame, iKill);
}

