

void ani0003(int iAni)
{
    /*
	ani001
	Damon Vaughn Caskey
	05/11/2007	
	Switch caller to alt animation if at 20% health or below.
    */
	
    void  vSelf         = getlocalvar("self");                      //Calling entity. 
    int   iHealth       = 0.0;                                      //Health
    int   iHealthMax    = 0.0;                                      //Max health
    float fFactor       = 0.0;

    iHealth     +=  getentityproperty(vSelf, "health");       
    iHealthMax  +=  getentityproperty(vSelf, "maxhealth");
    fFactor     =  (iHealth / iHealthMax);
	
	//At or below 20%?
    if (fFactor <= 0.2)
    {   
        if (getentityproperty(vSelf, "animvalid", iAni))
        {
            changeentityproperty(vSelf, "animation", iAni);
        }
    }        
}