void spawnrock()
{
	void self = getlocalvar("self");
	void e;
	int x = getentityproperty(self, "x");
	int z = getentityproperty(self, "z");
	int a = getentityproperty(self, "a");
	setspawnentry("name", "rock");
	e = spawn();
	changeentityproperty(e, "position", x, z+1, a);
	changeentityproperty(e, "velocity", rand()%50/10, rand()%30/10, 3 + rand()%5/10);
	if(rand()%100>50)
	{
		changeentityproperty(e, "animation", A_RESPAWN);
	}
	if(rand()%100>50)
	{
		changeentityproperty(e, "direction", 1);
	}
	else
	{
		changeentityproperty(e, "direction", 0);
	}
}