
void dir0001(){

    /*
    dir0001()
    Damon Vaughn Caskey
    05/17/2008
    Flips caller.
    */
    
     void vSelf = getlocalvar("self");                              //Caller.   
     int  iDir  = getentityproperty(vSelf, "direction");
     
     if (iDir)
     {
          iDir = 0;
     }
     else
     {
          iDir = 1;
     }
     
     changeentityproperty(vSelf, "direction", iDir);               
}