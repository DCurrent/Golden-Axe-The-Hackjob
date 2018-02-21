int host0001(void vTar1, void vTar2){

    /*
    host0001
    Damon Vaughn Caskey
    12072009
    Return 1 if targets are valid targets.

    vTar# = Target entites.
    */

    int     iType1  = getentityproperty(vTar1, "type"); //Caller type.
    int     iType2  = getentityproperty(vTar2, "type");  //Target type.

    if(iType1 == openborconstant("TYPE_ENEMY"))                                                 //iType1 is Enemy?
    {
        if(iType2 == openborconstant("TYPE_PLAYER") 
        || iType2 == openborconstant("TYPE_NPC")
        || iType2 == openborconstant("TYPE_OBSTACLE"))
        {
            return 1;                                                                           //Return 1.                    
        }
    }
    else if (iType1 == openborconstant("TYPE_PLAYER")
    || iType1 == openborconstant("TYPE_NPC"))    

    {
        if(iType2 == openborconstant("TYPE_ENEMY")
        || iType1 == openborconstant("TYPE_OBSTACLE"))                                          
        {
            return 1;                                                                           //Return 1.
        }
    }
    return 0;
}
