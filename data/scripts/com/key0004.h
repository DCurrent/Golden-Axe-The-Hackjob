#import "data/scripts/com/key0002.h"

int key0004(void vEnt, int iLeftH, int iRightH)
{

    /*
    key0004
    Damon Vaughn Caskey
    05/13/2007
    Reverse entity direction based on key input.

    vEnt:       Target entity.
    iLeftH:     Left key hold flag.
    iRightH:    Right key hold flag.
    */

    int iDir = getentityproperty(vEnt, "direction");    //Get facing.
    
    if (key0002(vEnt, iLeftH, iRightH))                 //"Back" key input?
    {
        if (iDir)
        {
            iDir = 0;
        }
        else
        {
            iDir = 1;
        }

        changeentityproperty(vEnt, "direction", iDir);  //Set facing.
    }
    
    return iDir;
}
