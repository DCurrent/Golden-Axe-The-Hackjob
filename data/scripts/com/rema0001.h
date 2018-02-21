void rema0001(int iMap, int iTime){

    /*
    rema0001
    Damon Vaughn Caskey
    07152008
    Applies "forcemap" to self.
    
    iMap:  Desired color map.
    iTime: Time (added to current gametime).
    */
    
    void vSelf = getlocalvar("self");

    changeentityproperty(vSelf, "map", iMap);
    changeentityproperty(vSelf, "maptime", openborvariant("elapsed_time") + iTime);

}
