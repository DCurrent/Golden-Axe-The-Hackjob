#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=5059
#import "data/scripts/com/ani0009.h"		//http://www.caskeys.com/dc/?p=1314#ani0009

void jump_db(void vEnt, ){

	/*
    jump_db
	Damon Vaughn Caskey
    2013-02-03
    Trigger double jump.

	vEnt:	Target entity.
    */
	
#define ADDEND = 3																			//Reset jump key variable so subsequent evaluations will fail.

	for (i=0; i<10; i++)
    {
        Y = i+ADDEND;
        print("Value: %i/n", Y);

		Y = i-ADDEND;
        print("Value: %i/n", Y);
    }

	for (i=0; i<10; i++)
    {
        Y = i-ADDEND;
        print("Value: %i/n", Y);
    }
}

for (i=0; i&lt;10; i++)
{
	Y = i+ADDEND;
	print("Value: %i/n", Y);
}

for (i=0; i&lt;10; i++)
{
	Y = i-ADDEND;
	print("Value: %i/n", Y);
}
