void paus0001(int iTime, int iExc1, int iExc2, int iExc3, int iExc4, int iExc5){

    /*
    paus0001
    Damon Vaughn Caskey
    11022009
    Pause or unpause action for all entities except self. Works by 
    freeze effect to all entities on screen, or adding/subtracting 
    freezetime on entities that are already frozen.

    iTime:  Time to add or subtract from freezetime (pause).
    vExc#:  Model types to bypass (no freeze).    
    */

    void vSelf      = getlocalvar("self");                                  //Caller    
    int  iETime     = openborvariant("elapsed_time");                       //Current time.
    int  iMax       = openborvariant("ent_max");                            //Entity count.
    int  iEntity;                                                           //Loop counter.
    void vEntity;                                                           //Target entity.
    int  iType;                                                             //Target entity type.
    int  iFreezeT;                                                          //Previous freezetime.

    for(iEntity=0; iEntity<iMax; iEntity++)
    {    
        vEntity = getentity(iEntity);                                       //Get target entity from current loop.        
        iType   = getentityproperty(vEntity, "type");                       //Get type.

        if (vEntity != vSelf                                                //Not self?
            && iType != iExc1                                               //Not exception type 1?
            && iType != iExc2                                               //Not exception type 2?
            && iType != iExc3                                               //Not exception type 3?
            && iType != iExc4                                               //Not exception type 4?
            && iType != iExc5)                                              //Not exception type 5?
        {            

            iFreezeT = getentityproperty(vEntity, "freezetime");

            if (iTime > 0)                                                  //Frozen time will be greater then current time?
            {
                iTime += iETime + iFreezeT;                                                         //Add elapsed time and previous freeze time to time amount requested.
                changeentityproperty(vEntity, "frozen", getentityproperty(vEntity, "frozen") + 1);  //Turn freeze effect on if it isn't already.
                changeentityproperty(vEntity, "freezetime", iTime);             //Set frozen time.
            }
            else
            {               
                changeentityproperty(vEntity, "frozen", getentityproperty(vEntity, "frozen") + iTime);                                              
            }            
        }
    }    
}