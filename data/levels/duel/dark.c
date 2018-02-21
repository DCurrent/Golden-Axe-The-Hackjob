void main()
{
    if(getglobalvar("darkone")==1)
    {
        setglobalvar("darkone", NULL());
    }
    else
    {
        setglobalvar("darkone", 1);
    }

    if(getglobalvar("darkskeleton")==1)
    {
        setglobalvar("darkskeleton", NULL());
    }
    else
    {
        setglobalvar("darkskeleton", 1);
    }
}