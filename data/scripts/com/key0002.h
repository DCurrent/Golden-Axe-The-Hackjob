int key0002(void vEnt, int iLeftH, int iRightH)
{
    /*
    key0002
    Damon Vaughn Caskey
    05/13/2007
    Determine if current directional key is "back" in relation to entity direction.

    vEnt:       Target entity.
    iLeftH:     Left key hold flag.
    iRightH:    Right key hold flag.
    */

    int iDir = getentityproperty(vEnt, "direction");    //Get facing.

    if  (iDir && iLeftH || !iDir && iRightH)            //Active key opposite of direction?
    { 
        return 1;                                       //Return true.
    }
    return 0;                                           //Return False.
        
}
