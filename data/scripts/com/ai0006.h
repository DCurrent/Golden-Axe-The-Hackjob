void ai0006(int a, int b, int c, int d, int e, int f)
{
    /*
    ai0006
    Damon V. Caskey, modified from Utunnels runaway().
    05112010
    Work around walls, escape screen, and then kill self.

    a-f: Expansion.
    */

    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float a = getentityproperty(self, "a");
    float vx = getentityproperty(self, "xdir");
    float va = getentityproperty(self, "tossv");
    float vz = getentityproperty(self, "zdir");

	float xpos = openborvariant("xpos");

	if(x<xpos - 30 || x> xpos + openborvariant("hresolution") + 30)
	{
		killentity(self);
	}
	else
	{
		int d = getentityproperty(self, "direction");
		float wall;
		float wb;

		if(d==0)
		{
			d = -1;
		}

		wall = checkwall(x + 10*d, z);
		wb = checkwall(x - 60*d, z);

		if(wall>0 && wall>a+20)
		{
			if(wb > a) { vz = 1.5;}
			changeentityproperty(self, "velocity", -3*d, vz+0.5, va);
			if(d > 0) // flip
			{
				changeentityproperty(self, "direction", 0);
			}
			else
			{
				changeentityproperty(self, "direction", 1);
			}
		}
		else if(wall>0 && wall>a)
		{
			changeentityproperty(self, "base", wall);
			changeentityproperty(self, "position", x, z, wall+0.5);
			changeentityproperty(self, "velocity", 3*d, 0, va);
		}
		else
		{
			changeentityproperty(self, "velocity", 3*d, vz, va);
		}		
	}
}