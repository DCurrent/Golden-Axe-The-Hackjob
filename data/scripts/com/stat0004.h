void stat0004()
{

    //adjustmp

	void self = getlocalvar("self");
    int index = getentityproperty(self, "playerindex");
    
	if(index>=0)
    {
		changeentityproperty(self, "mp", getglobalvar("player"+index+"mp")*10);
		if(getentityproperty(self, "mp") > getentityproperty(self, "maxmp"))
		{
			changeentityproperty(self, "mp", getentityproperty(self, "maxmp"));
		}		
    }
}
