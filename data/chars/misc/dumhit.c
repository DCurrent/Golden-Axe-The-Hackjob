
void main()
{
	void e;
	void damagetaker = getlocalvar("damagetaker");
	void self = getlocalvar("self");
	clearspawnentry();
	setspawnentry("name", "lightning3");
	e = spawn();
	changeentityproperty(e, "position", getentityproperty(damagetaker, "x"), getentityproperty(damagetaker, "z"), getentityproperty(damagetaker, "a"));
	changeentityproperty(e, "base", getentityproperty(damagetaker, "base"));
	changeentityproperty(e, "owner", self);
}