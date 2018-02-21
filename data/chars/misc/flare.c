void spawnmeteor()
{
	void self = getlocalvar("self");
	void e;
	int x = getentityproperty(self, "x");
	int z = getentityproperty(self, "z");
	int a = getentityproperty(self, "a");
	setspawnentry("name", "meteor");
	e = spawn();
	changeentityproperty(e, "position", x, z+1, a+ 64);
	int randx = rand()%50/10;
	changeentityproperty(e, "velocity", randx, rand()%30/10, 3 + rand()%5/10);
	if(randx>0)
	{
		changeentityproperty(e, "direction", 1);
	}
	else
	{
		changeentityproperty(e, "direction", 0);
	}
}