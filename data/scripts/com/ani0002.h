

void ani0002(int iFrame1){

    /*
	ani001
	Damon Vaughn Caskey
	05/11/2007
	Loop calling entity back to desired frame if below max MP (for charge animation).
    	
	iFrame: Desired frame.
	*/
	
	void vSelf  = getlocalvar("self");                  //Calling entity. 
    int  iMP    = getentityproperty(vSelf, "mp");       //Caller current MP.
    int  iMaxMP = getentityproperty(vSelf, "maxmp");    //Caller current MP.
	
	if (iMP < iMaxMP){ updateframe(vSelf, iFrame1); }
	
}