

void ani0004(void vAni, int iFrame){

    /*
	ani0004
	Damon Vaughn Caskey
	04/01/2008
	Force opponent entity to play animation.

    vTar: Target entity.
    vAni: Desired animation.    	
	iFrame: Desired frame.
	*/
	
	void vSelf   = getlocalvar("self");                                 //Calling entity. 
    void vTarget = getentityproperty(vSelf, "opponent");                //Target entity.

	changeentityproperty(vTarget, "animation", openborconstant(vAni));  //Switch to desired animation.    	
    updateframe(vTarget, iFrame);

}