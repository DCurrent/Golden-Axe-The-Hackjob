#import "data/scripts/com/bind0021.h"

void bind0018(void vEnt, int b, int c, int d, int e, int f){
       
	/*
	bind0018
	Damon Vaughn Caskey
	05152010

	Runs shunt function for all bound entities on vEnt.

    a-f: Expansion.
	*/

    int     iCnt        = 0;                                                    //Loop counter.
    void    vBound;                                                             //Bound entity.
    int     iOX, iOZ, iOB;														//Location offset and Base.
    
	if(!vEnt){	vEnt = getlocalvar("self");	}									//Ent not passed? Use caller.	
	
    do                                                                          //Look through bind index.
    {
        vBound   = getglobalvar(vEnt + ".bind." + iCnt);						//Get bound entity from index. 
        
        if (vBound)                                                             //Anything there?
        {           
			bind0021(vEnt, vBound);												//Run shunt function.	
		}
        iCnt++;                                                                 //Increment index.
    }
    while (vBound);                                                             //Continue looping until the bind index slot is blank.        

}