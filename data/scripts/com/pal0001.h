void pal0001(int iMap){    
    
    /*
    pal0001
    Damon Vaughn Caskey
    02/11/2008     
    Set panel color maps. Needed when panels do not share global palette.

    */

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration placeholder.
    int  iType;                                         //Entity type.
    int  iMax        = openborvariant("ent_max");       //Entity count.
        
    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
    
        vEntity = getentity(iEntity);                   //Get target entity from current loop.
        iType   = getentityproperty(vEntity, "type");   //Get target type.

        //Panel type?
        if (iType ==1024){            
            changeentityproperty(vEntity, "map", getentityproperty(vEntity, "map") + iMap);
        }                   
    }    
}