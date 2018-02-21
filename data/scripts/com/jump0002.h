
void jump0002(float fY, float fX, float fZ){

    /*
    jumpd001
    Damon Vaughn Caskey
    05/13/2007
    Toss caller's current opponent.

    fX,fY,fZ: X, Y, and Z distance.
    */
    
    void vSelf   = getlocalvar("self");                     //Caller.
    void vTarget = getentityproperty(vSelf, "opponent");    //Callers opponent.
    int  iDir    = getentityproperty(vTarget, "direction"); //Caller's direction.
    
    if (!iDir){ fX = -fX; }        
    tossentity(vTarget, fY, fX, fZ);                       //Toss opponent.    
}