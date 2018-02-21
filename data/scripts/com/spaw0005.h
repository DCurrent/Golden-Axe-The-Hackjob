void spaw0005(char cModel, int a, int b, int c, int d, int e, int f)
{

    /*
    spaw0005
    Damon v. Caskey (modified from Utunnels spawnmeat()
    05112010

    Spawn an entity and toss it. Usually for items.
    */


    void self = getlocalvar("self");
    clearspawnentry();
    setspawnentry("name", cModel);
    void m = spawn();
    float x = getentityproperty(self, "x");
    float a = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    if(x<openborvariant("xpos")) x = openborvariant("xpos");
    else if(x>openborvariant("xpos") + openborvariant("hresolution")) x = openborvariant("xpos") + openborvariant("hresolution");
    changeentityproperty(m, "position", x, z, a+10);
    changeentityproperty(m, "velocity", 0, 0, 2.5);
}
