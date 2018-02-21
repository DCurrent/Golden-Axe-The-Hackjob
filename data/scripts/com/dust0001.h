#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void dust0001(void vType){
	
    /*
     dust0002
     Damon Vaughn Caskey
     02/25/2008
     Spawn effect for jump, land, slide and skid. Given it's own simple as possible function since it will be called a lot.
     
	 iType:	
     0 = Jump.
     1 = Land.
     2 = Sudden start.
     3 = Sudden stop.
     4 = Skid.
     5 = Impact.
     6 = Heavy Impact.
     7 = Jump (no sound in normal enviroment).
     8 = Fall.
     */
    
    void  vSpawn;
    void  vSelf		= getlocalvar("self");										//Caller.
    int   iX		= getentityproperty(vSelf, "x") - openborvariant("xpos");	//Caller X location.
    int   iZ		= getentityproperty(vSelf, "z");							//Caller Z location.
    int   iY		= getentityproperty(vSelf, "a");							//Caller Y location.    
	int	  iDir		= getentityproperty(vSelf, "direction");					//Caller direction.	
	void  vModel    = "dust0001";											    //Dust model.
    
    clearspawnentry();															//Clear current spawn entry.
    setspawnentry("name",   vModel);											//Aquire spawn entity by name.
    setspawnentry("alias",  "" + vType + "");                                   //Set alias (this will be used to set type of "dust").    
	setspawnentry("coords", iX, iZ, iY);										//Spawn location.
    vSpawn = spawn();															//Spawn entity.
    clearspawnentry();															//Clear current spawn entry.
        
    setentityvar(vSelf, IDXE_SPAWN, vSpawn);											//Store spawn into last spawn variant.
    changeentityproperty(vSpawn, "direction", iDir);							//Set spawn direction.	    

    return vSpawn;
}