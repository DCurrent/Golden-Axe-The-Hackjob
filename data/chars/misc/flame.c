void main()
{
    void self = getlocalvar("self");
	if(getentityproperty(self, "animating")==0 && getentityproperty(self, "animationid")==A_IDLE)
	{killentity(self);}
	else
	{
		changeentityproperty(self, "position", openborvariant("xpos"), openborvariant("ypos"), 0);
		changeentityproperty(self, "direction", 1);
		changeentityproperty(self, "owner", NULL());
	}
}