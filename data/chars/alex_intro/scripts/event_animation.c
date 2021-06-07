
/* spawn 3 text boxes, in a chain. */
void checktext()
{
    int t1 = getlocalvar("t1");
    int t2 = getlocalvar("t2");
    int t3 = getlocalvar("t3");
    
    void self = getlocalvar("self");
    
    void text1;
    void text2;
    void text3;

    if (!t1)
    {
        // spawn the text1: Alex, what has happened?
        clearspawnentry();
        setspawnentry("name", "alex_intro_dialog_0");
        
        text1 = spawn();
        adjustpos(text1);

        setlocalvar("t1", 1);
        setlocalvar("alex_intro_dialog_0", text1);
    }
    else if (!t2)
    {
        text1 = getlocalvar("text1");

        if (text1 && getentityproperty(text1, "animating") == 0)
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
            changeentityproperty(text2, "position", x, z + 1, 53);
            changeentityproperty(text2, "base", 53);
            setlocalvar("t2", 1);
            setlocalvar("text2", text2);
        }
    }
    else if (t2)
    {
        text2 = getlocalvar("text2");
        if (text2 && getentityproperty(text2, "animating") == 0)
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
