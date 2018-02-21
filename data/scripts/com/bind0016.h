void bind0016(void vEnt, int iAni, float fX, float fY, float fZ, int iDir, int iCond, int B, int C, int D, int E, int F){
	
    /*
    bind0016
    Damon Vaughn Caskey
    05172010

    Transport entity to nearest target.
    
    vEnt:   Entity to transport. Defaults to self if not provided.
    iAni:   Animation to apply range from.
    fX/Y/Z: X, Y, and Z offset adjustment.
    iDir:   Direction;         
                -2: Opposite target.
                -1: Left.
                0:  No change.
                1:  Right.
                2:  Match target.
    iCond:  Conditional check.
                0: Teleport X/Z only if target in air; no teleport if target over pit.
    
    B-F:    Expansion.
    */

    void    vTarg;                                          //Target entity.    
    int     iTD;                                            //Target direction.
    float   fTX, fTY, fTZ, fTB;                             //Target height and base.

    if (!vEnt)                                              //No base ent passed?
    {
        vEnt = getlocalvar("self");                         //Use caller.
    }

    if (iAni != -1)                                         //Animation provided?
    {
        vTarg   = findtarget(vEnt, iAni);                   //Get target by animation range.    
    }
    else                                                    //No animation?
    {
        vTarg   = findtarget(vEnt);                         //Get nearest target.
    }

    fTB     = getentityproperty(vTarg, "base");             //Get target base.
    fTY     = getentityproperty(vTarg, "a");                //Get target height.
	iTD     = getentityproperty(vTarg, "Direction");        //Get target direction.    

    if(!iTD)                                                //Target facing Left?
    {
        fX = -fX;                                           //Reverse direction adjustment.
    }

    fY     += fTY;                                          //Add adjustment to target Y.
    fX     += getentityproperty(vTarg, "x");                //Add adjustment to target X.
    fZ     += getentityproperty(vTarg, "z");                //Add adjustment to target Z.

    //Condition adaption.
    if(!iCond)
    {
        if(fTB < fTY)                                       //Target in air?
        {  
            fY = fTB;                                       //Use target's base as Y.
        }                      
        
        if(checkhole(fTX, fTZ))                             //Target over hole?
        {
            return 0;                                       //Cancel teleport and exit function.
        }
    }

    if (iDir == -2)                                         //Opposite request?
    {
        iDir = -iTD;                                        //Direction opposite target.
    }
    else if(iDir == -1)                                     //Left request?
    {
        iDir = 0;                                           //Direction left.
    }
    else if(iDir == 1)                                      //Right request?
    {
        iDir = 1;                                           //Direction right.
    }
    else if(iDir == 2)                                      //Same direction request?
    {
        iDir = iTD;                                         //Direction same as target.
    }

    changeentityproperty(vEnt, "position", fX, fZ, fY);     //Set location.
    changeentityproperty(vEnt, "direction", iDir);          //Set direction.

}
