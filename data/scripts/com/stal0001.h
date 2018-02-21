int stal0001(int iSTime)
{
    /*
    stal0001
    Damon Vaughn Caskey
    12/24/2009
    Adds stalltime to opponent.

    iTime:      Time to add.
    */

    void vSelf = getlocalvar("self");
	void vOpp  = getentityproperty(vSelf, "opponent");
    int  iTime = openborvariant("elapsed_time");

	changeentityproperty(vOpp, "stalltime", iTime + iSTime);                                               
}