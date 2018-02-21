#include "data/scripts/trailer.h"

void tupdate()
{
	int i, j, k, color, alpha;
	void spr,map;
	int facing, cd;
	float a, z, x;

	for(i=1; i<=trailermax; i++)
	{
		spr = getglobalvar("trailer"+i+".s");
		if(spr)
		{
			cd = getglobalvar("trailer"+i+".c");
			if(!cd) 
			{
				setglobalvar("trailer"+i+".c", NULL());
				setglobalvar("trailer"+i+".s", NULL());
				setglobalvar("trailer"+i+".x", NULL());
				setglobalvar("trailer"+i+".z", NULL());
				setglobalvar("trailer"+i+".a", NULL());
				setglobalvar("trailer"+i+".m", NULL());
				setglobalvar("trailer"+i+".f", NULL());
				setglobalvar("trailer"+i+".color", NULL());
				setglobalvar("trailer"+i+".alpha", NULL());
			}
			else
			{
				if(openborvariant("game_paused")==0)
				{
					setglobalvar("trailer"+i+".c", cd-1);
				}
				x = getglobalvar("trailer"+i+".x");
				z = getglobalvar("trailer"+i+".z");
				a = getglobalvar("trailer"+i+".a");
				color = getglobalvar("trailer"+i+".color");
				alpha = getglobalvar("trailer"+i+".alpha");
				facing = getglobalvar("trailer"+i+".f");
				map = getglobalvar("trailer"+i+".m");
				////setdrawmethod(entity, int flag, int scalex, int scaley, int flipx, int flipy, int shiftx, int alpha, int remap, int fillcolor, int rotate, int fliprotate, int transparencybg, void* colourmap);
				setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0, alpha, 0, color, 0, 0, 1, map);
				drawsprite(spr, x-openborvariant("xpos"), z-a+openborvariant("gfx_y_offset"), z-i, 0);
				setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 1, NULL());
			}
		}
	}
}
