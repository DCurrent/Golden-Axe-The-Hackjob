
void main()
{
    void self = getlocalvar("self");
    void p = getglobalvar("p");
    float x = getentityproperty(p, "x");
    float z = getentityproperty(p, "z");
    float a = getentityproperty(p, "a");
    changeentityproperty(self, "position", x, z+1, a+60);
    changeentityproperty(self, "base", a+60);
    
}
