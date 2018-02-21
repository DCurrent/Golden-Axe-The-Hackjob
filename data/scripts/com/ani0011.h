void ani0011(void vEnt)
{
    /*
    ani0011
    Damon Vaughn Caskey
    12072009
    Switch caller to next followup animation in order. Primarily intended 
    for projectile entity where every other follow up is its predecessor’s 
    finish/clash animation.

    Could probably be done just as effciantly with a series of "ifs", but loop
    design allows quick adding of more projectile animations without modifying script.

    vEnt: Target entity.
    */

    int i = 0;                                                              //Counter.
    int iTest;                                                              //Animation test.
    int iAni = getentityproperty(vEnt, "animationid");                      //Target's current animation.

    do                                                                      //Start loop.                                                                  
    {
        i++;                                                                //Increment counter.
        iTest = openborconstant("ANI_FOLLOW" + i);                          //Create animation string and get resulting constant.
    }   
    while (iAni != iTest && getentityproperty(vEnt, "animvalid", iTest));   //Continue until constant/current animation match or no more valid constants are found.

    iAni = openborconstant("ANI_FOLLOW" + (++i));                           //Increment counter once more, combine for string, and get resulting constant.
    
    if (getentityproperty(vEnt, "animvalid", iAni))                         //Animation valid?
    {
        changeentityproperty(vEnt, "animation", iAni);                      //Assign animation.
        changeentityproperty(vEnt, "velocity", 0, 0, 0);                    //Stop movement.
    }
}
