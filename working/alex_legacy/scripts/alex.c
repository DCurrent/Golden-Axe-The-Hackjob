//*****************************************************
//  alex.c
//  Used by npc file alex_.txt
//*****************************************************

// spawn a dummy enemy to hold level scrolling
void spawndummy()
{
    if(getglobalvar("dummy")==NULL())
    {
        clearspawnentry();
        setspawnentry("name", "dummy");
        setglobalvar("dummy", spawn());
    }
}

// no extra enemy, or player is near, or reach destination
// then suicide and play the cut scene
void checksuicide()
{
    int ec = openborvariant("count_enemies");
    void self = getlocalvar("self");
    float sx = getentityproperty(self, "x");
    float sz = getentityproperty(self, "z");
    int i;
    float dx; float dz;
    void p;
    for(i=0; i<4; i++)
    {
        p = getplayerproperty(i, "entity");
        if(p)
        {
            dx = sx - getentityproperty(p, "x");
            dz = dz - getentityproperty(p, "z");
            if(dx < 0) { dx = -dx;}
            if(dz < 0) { dz = -dz;}
            break;
        }
    }
    if(ec==1 || sx<120 || (dx <60 && dz < 35))
    {
        damageentity(self, self, 10000);
    }
}

// used by checktext
void adjustpos(void text)
{
    int i;
    void p = NULL();
    for(i=0; i<4; i++)
    {
        p = getplayerproperty(i, "entity");
        if(p) // find the player and move the text above his head
        {
            float x = getentityproperty(p, "x");
            float z = getentityproperty(p, "z");
            float a = getentityproperty(p, "a");
            changeentityproperty(text, "position", x, z+1, a+60);
            changeentityproperty(text, "base", a+60);
            break;
        }
    }
    setglobalvar("p", p); // used by the text's update function, stay with that player
}

// spawn 3 text boxes, in a chain
void checktext()
{
    int t1 = getlocalvar("t1");
    int t2 = getlocalvar("t2");
    int t3 = getlocalvar("t3");
    void self = getlocalvar("self");
    void text1;
    void text2;
    void text3;
    if(!t1)
    {
        // spawn the text1: Alex, what has happened?
        clearspawnentry();
        setspawnentry("name", "text1");
        text1 = spawn();
        adjustpos(text1);
        setlocalvar("t1", 1);
        setlocalvar("text1", text1);
    }
    else if(!t2)
    {
        text1 = getlocalvar("text1");
        if(text1 && getentityproperty(text1,"animating")==0)
        {
            killentity(text1);
            setlocalvar("text1", NULL());
            // spawn the text2 that Alex spoke
            clearspawnentry();
            setspawnentry("name", "text2");
            text2 = spawn();
            float x = getentityproperty(self, "x");
            float z = getentityproperty(self, "z");
            // move the text above Alex's head
            changeentityproperty(text2, "position", x, z+1, 53);
            changeentityproperty(text2, "base", 53);
            setlocalvar("t2", 1);
            setlocalvar("text2", text2);
        }
    }
    else if(t2)
    {
        text2 = getlocalvar("text2");
        if(text2 && getentityproperty(text2,"animating")==0)
        {
            killentity(text2);
            setlocalvar("text2", NULL());
            // spawn text3: Alex...
            clearspawnentry();
            setspawnentry("name", "text3");
            text3 = spawn();
            adjustpos(text3);
            changeentityproperty(self, "animation", openborconstant("ANI_DIE10"));
            setlocalvar("text3", text3);
        }
    }// end of if
}
