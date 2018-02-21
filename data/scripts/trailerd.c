#include "data/scripts/trailer.h"

void tclear()
{
	int i;
	setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0, 0, 0, 0, 1, NULL());
	for(i=1; i<=trailermax; i++)
	{
		setglobalvar("trailer"+i+".c", NULL());
		setglobalvar("trailer"+i+".s", NULL());
		setglobalvar("trailer"+i+".x", NULL());
		setglobalvar("trailer"+i+".z", NULL());
		setglobalvar("trailer"+i+".a", NULL());
		setglobalvar("trailer"+i+".color", NULL());
		setglobalvar("trailer"+i+".alpha", NULL());
		setglobalvar("trailer"+i+".f", NULL());
		setglobalvar("trailer"+i+".m", NULL());
	}
}
