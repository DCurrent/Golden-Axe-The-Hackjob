#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"

/*
* Caskey, Damon V.
* 2021-04-25 (copy of ani0002 ~2007-05-11).
* 
* Loop to start of animation if MP is 
* not filled. 
*/
void dc_disney_loop_on_partial_mp(int start_frame)
{
	void acting_entity = dc_disney_get_member_entity();

	int mp_current = get_entity_property(entity, "mp");
	int mp_max = getentityproperty(vSelf, "maxmp");

	if (mp_current < mp_max)
	{
		updateframe(acting_entity, start_frame);
	}
}