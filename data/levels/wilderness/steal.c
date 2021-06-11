#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void main()
{
    int c = getglobalvar("player0mp");
	char a = getglobalvar("runanimal");
	void e;

	if(c>2) {setglobalvar("player0mp", c-2); c = 2;}
	else {setglobalvar("player0mp", 0);}

	if(c>0)
	{
		clearspawnentry();
		setspawnentry("name", "magic_pot");
	    while(c-->0)
		{
			setspawnentry("coords", 170 + c*10, 182, 0);
			e = spawn();
			setglobalvar("pot"+(c%100), e);
		}
	}

	if(a!=NULL())
	{
		setspawnentry("name", a);
		setspawnentry("coords", openborvariant("hresolution")/2, openborvariant("vresolution")-52, 0);
		changeentityproperty(spawn(), "animation", A_IDLE);
	}
}