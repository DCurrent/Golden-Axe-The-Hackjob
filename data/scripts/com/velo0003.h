void velo0003(void vEnt, int iTimeMod){
     
    /*
    velo0003 - http://www.caskeys.com/dc/?p=1314#velo0003
	Damon Vaughn Caskey		
    2012_01_09

	Set tosstime to target.
	
	vEnt:	Target entity.
	iTime:	Time modifier
	*/
	
	int	iTime   = openborvariant("elapsed_time");                           //Get elapsed time.

	/*
	Default to caller if Ent not passed.
	*/
	if(!vEnt)
	{
		vEnt = getlocalvar("self");
	}

	changeentityproperty(vEnt, "tosstime", iTime + iTimeMod);

}