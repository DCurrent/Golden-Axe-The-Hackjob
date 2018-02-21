#import "data/scripts/com/key0002.h"

int key0005(int A, int B, int C, int D, int E)
{

    /*
    key0004
    Damon Vaughn Caskey
    05/13/2007
    Key0004 (Reverse entity direction based on key input), but with own key checks.

    vEnt:       Target entity.
    iLeftH:     Left key hold flag.
    iRightH:    Right key hold flag.
    */

    int     iPlIndex    = getlocalvar("player");                                    //Player index.
    void    vSelf       = getplayerproperty(iPlIndex, "entity");                    //Get calling entity.
    int     iLeftH      = playerkeys(iPlIndex, 0, "moveleft");                      //Hold  "Left".
    int     iRightH     = playerkeys(iPlIndex, 0, "moveright");                     //Hold  "Right".
    
    int iDir = getentityproperty(vSelf, "direction");                               //Get facing.
    
    if (key0002(vSelf, iLeftH, iRightH))                                            //"Back" key input?
    {
        if (iDir)
        {
            iDir = 0;
        }
        else
        {
            iDir = 1;
        }

        changeentityproperty(vSelf, "direction", iDir);                             //Set facing.
    }
    
    return iDir;
}
