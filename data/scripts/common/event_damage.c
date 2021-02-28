#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/common/takedamage_main.c"

void main()
{
	void acting_entity = getlocalvar("self");

	common_event_takedamage(acting_entity);
}

