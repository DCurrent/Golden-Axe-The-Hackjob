#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"

/* 
* Caskey, Damon V.
* 2018-11-03 (orginal 2009-10-26)
*
* Switch to alternate animation if nearest hostile target is
* in the alternate animation's range.
*/
void dc_disney_alternate_on_range(int animation) 
{
	void ent;
	void target;

	ent = dc_disney_get_member_entity();

	/* 
	* If we find a target within the animation's 
	* range, then switch to the animation.
	*/
	target = findtarget(ent, animation);

	if (target)
	{
		/* Third parameter is resettable flag. */
		executeanimation(ent, animation, 1);
	}
}
