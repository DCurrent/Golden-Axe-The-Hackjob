void stat0003()
{

    //Savemp

	void self = getlocalvar("self");
    int index = getentityproperty(self, "playerindex");
	int mp;
    if(index>=0) 
    {
        mp = getentityproperty(self, "mp") / 10;
        setglobalvar("player"+index+"mp", mp);
    }
}

