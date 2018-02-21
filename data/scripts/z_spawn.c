#import "data/scripts/com/z_spawn.h"  //Find entity with same name and move to it.

void main()
{
    void    vEnt   = getlocalvar("self");                  //Caller.

	z_spawn(vEnt);
}


	
