#import "data/scripts/com/rnd0001.h"  
#import "data/scripts/com/targ0001.h"

void rema0002(void vTar, int A, int B, int C, int D, int E){
     
     /*
     rema0002
     Damon Vaughn Caskey
     01262009
     Set's target map randomly, avoiding hmap range.
     */
     
     void vSelf   = getlocalvar("self");                        //Caller.
     void vTarget = targ0001(vTar, vSelf);                      //Target.
     int iMapCount = getentityproperty(vSelf, "mapcount");      //Number of maps loaded.  
     int iHMapU    = getentityproperty(vSelf, "hmapu");         //Upper range of hmaps.            
     int iMap      = rnd0001(iHMapU, iMapCount, 0, 0, 0, 0);    //Random number from upper range of hMap to number of mapps loaded.
        
     if (iMap <= iHMapU){ iMap = 0; }                           //If random number matches upper hmap, use map 0 (default colors for model).

     changeentityproperty(vTarget, "map", iMap);                //Apply map choice.
     
}
