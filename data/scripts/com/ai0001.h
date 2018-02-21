
void ai0001(void vAI1, int iAI1, void vAI2, int iAI2){
     
    /*
    ani001
    Damon Vaughn Caskey
    11/13/2007
    Switch caller to new AI mode.

    vAI#: AI Flag.
    iAI#: AI flag state.
    */
         
    void vSelf = getlocalvar("self"); //Get calling entity. 
        
    changeentityproperty(vSelf, "aiflag", vAI1, iAI1);   //Set flag.

	if(vAI2)
	{
		changeentityproperty(vSelf, "aiflag", vAI2, iAI2); //Set flag.
	}
      
}