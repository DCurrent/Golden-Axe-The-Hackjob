void main()
{
	void self = getlocalvar("self");
	float dx; float dz;
	if(getentityproperty(self,"direction")==1)
	{dx = -2;dz=-0.2;}
	else
	{dx=2;dz=0.2;}
	changeentityproperty(self, "position", getentityproperty(self,"x")+dx, getentityproperty(self,"z")+dz, getentityproperty(self,"a"));
}