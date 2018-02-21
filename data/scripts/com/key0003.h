int key0003(void vSelf, int iLeftH, int iRightH)
{
    /*
    key0003
    Damon Vaughn Caskey
    05/13/2007
    Determine if current directional key is "forward" in relation to entity direction.

    vEnt:       Target entity.
    iLeftH:     Left key hold flag.
    iRightH:    Right key hold flag.
    */

    int iDir = getentityproperty(vSelf, "direction");   //Get facing.

    if  (!iDir && iLeftH || iDir && iRightH)            //Active key matches direction?
    { 
        return 1;                                       //Return true.
    }
    return 0;                                           //Return false.
}
