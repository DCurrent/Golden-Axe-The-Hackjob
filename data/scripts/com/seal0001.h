int seal0001(int iSeal, int iSTime)
{
    /*
    seal0001
    Damon Vaughn Caskey
    12/24/2009
    Adds seal effect (special disabling) to opponent.

    iSeal:      Seal level (entity cannot use specials with energycost > iSeal.
    iTime:      Time before seal effect expires.
    */

    void vSelf = getlocalvar("self");
	void vOpp  = getentityproperty(vSelf, "opponent");    
    int  iTime = openborvariant("elapsed_time");

	changeentityproperty(vOpp, "seal", iSeal);
	changeentityproperty(vOpp, "sealtime", iTime + iSTime);     
}
