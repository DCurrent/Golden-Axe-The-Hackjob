#include "data/scripts/trailer.h"
#include "data/scripts/vars/constants.h"

void main()
{
	int i, j, k, elapsed_time, aid;
	void spr;
	int facing, cd;
	float a, z, x;
	
	void ent = getlocalvar("self");
	aid = getentityproperty(ent, "animationid");
	if(aid==A_FSPECIAL || aid==A_FSPECIAL2 || aid==A_RISEATK)
	{
		elapsed_time = openborvariant("elapsed_time");


		if(elapsed_time%trailerd==0)
		{
			spr = getentityproperty(ent, "sprite");
			x = getentityproperty(ent, "x");
			z = getentityproperty(ent, "z");
			a = getentityproperty(ent, "a");
			facing = !getentityproperty(ent, "direction");
			for(k=1; k<=trailermax; k++) //find an empty trailer slot
			{
				if(getglobalvar("trailer"+k+".s")==NULL())
				{
					setglobalvar("trailer"+k+".s", spr);
					setglobalvar("trailer"+k+".x", x);
					setglobalvar("trailer"+k+".z", z);
					setglobalvar("trailer"+k+".a", a);
					setglobalvar("trailer"+k+".f", facing);
					setglobalvar("trailer"+k+".c", trailerc*trailerd);
					setglobalvar("trailer"+k+".color", 0);
					setglobalvar("trailer"+k+".alpha", 6);
					setglobalvar("trailer"+k+".m", NULL());
					break;
				}
			}
		}
	}
}
