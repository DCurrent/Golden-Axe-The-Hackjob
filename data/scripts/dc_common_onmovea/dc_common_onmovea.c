#include "data/scripts/dc_common_onmovea/config.h"


/*
* Caskey, Damon V
* 2021-04-11
*
* Common takedamage event function used by
* most models.
*/
void dc_common_onmovea()
{
	void acting_entity = getlocalvar("self");
	int model_type = getentityproperty(acting_entity, "type");

	if(model_type & openborconstant("TYPE_PLAYER"))
	{
		dc_hansburg_try_axis_control_y();
	}	
}
