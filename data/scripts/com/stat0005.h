void stat0005(void vEnt, char cStat, int iTime, int a, int b, int c){

    /*
    stat0005
    Damon Vaughn Caskey
	07102010

    Set a timed property by string. Can't belive I didn't think to
	do this instead of making loads of one shot functions.

	vEnt:	Target entity. Default to self.
	cStat:	Stat to change, such as "tosstime".
	a-c: Expansion.
    */

	if(!vEnt)
	{
		vEnt = getlocalvar("self");
	}

	changeentityproperty(vEnt, cStat, iTime+openborvariant("elapsed_time"));
}
