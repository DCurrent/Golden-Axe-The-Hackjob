void loc0001(float fX, float fZ, float fY){
     
    /*
    loc0001
    Damon Vaughn Caskey
    05/19/2008     
    Adjust location of entity from current position.

    fX, fY, fZ: Adjustment offsets.
    */
    
    void  vSelf = getlocalvar("self");           //Caller.
	float fCX   = getentityproperty(vSelf, "x"); //Caller X location.
    float fCZ   = getentityproperty(vSelf, "z"); //Caller Z location.
    float fCY   = getentityproperty(vSelf, "a"); //Caller Y location.

	changeentityproperty(vSelf, "position", fCX + fX, fCZ + fZ, fCY + fY);
}