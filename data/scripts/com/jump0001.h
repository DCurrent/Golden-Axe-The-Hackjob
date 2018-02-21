
void jump0001(float fY, float fX, float fZ){

    /*
    jumpd001
    Damon Vaughn Caskey
    05/13/2007
    Toss caller.

    fX,fY,fZ: X, Y, and Z distance.
    */

    void vSelf  = getlocalvar("self");                   //Caller.
    int  iDir   = getentityproperty(vSelf, "direction"); //Caller's direction.
    
    if (!iDir){ fX = -fX; }        
    tossentity(vSelf, fY, fX, fZ);                       //Toss caller.
    
}