#include "data/scripts/dc_common_didhit/main.c"
#include "data/scripts/dc_cancel/main.c"
/*
* Run by most enemy types as their didhitscript. 
*/

void main()
{
	void acting_entity = getlocalvar("self");
	int animation_id = get_entity_property(acting_entity, "animation_id");
	int blocked = getlocalvar("blocked");

	if (!blocked)
	{
		dc_cancel_set_member_allow_idle_animation(animation_id);
	}

	dc_common_didhit();
}