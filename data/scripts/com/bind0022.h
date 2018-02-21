#import "data/scripts/com/bind0008.h"

void bind0022(int iIndex, char cModel, char cAlias, int iMap, int iBlend, float fAX, float fAY, int iAZ, int iDir, int iAni, int iFrame, int iKill){

	/*
	bind0022
	Damon Vaughn caskey
	12092010
	Runs bind0008 for flash entities; replaces requested entity if indexed target has custom flash settings.

	iIndex:	target by bound index. See bind0014.
	*/
	void    vSelf   = getlocalvar("self");                                  //Calling entity.
	void    vTarget = getglobalvar(vSelf + ".bind." + iIndex);              //Target entity.
	int		iFlNo;															//Get target flash property.
	int		iFlMod;															//Get target noatflash property.	

	if(vTarget)																//Valid target?
	{
		iFlNo	= getentityproperty(vTarget, "flash", 1);					//Get target flash property.
		iFlMod	= getentityproperty(vTarget, "flash", 0);					//Get target noatflash property.		

		if(iFlMod)															//Noatflash property?
		{
			cModel	= getmodelproperty(iFlMod, 1);							//Override flash request with target's custom flash
		}
	}

	return bind0008(cModel, cAlias, iMap, iBlend, fAX, fAY, iAZ, iDir, iAni, iFrame, iKill);
}

