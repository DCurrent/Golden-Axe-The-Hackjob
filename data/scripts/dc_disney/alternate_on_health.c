#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/entity.c"

/*
* Caskey, Damon V.
* 2018-11-03
* 
* Switch animation based on health thresholds. For now,
* hard codes to switching on 20% or below. We can add
* more switches using localvars later when we need them.
*/
void dc_disney_alternate_on_health(int animation)
{ 
	
	void  ent;
	int   hp_current = 0.0;
	int   hp_max = 0.0;
	float ratio_current = 0.0;

	float ratio_threshold = 0.2;

	ent = dc_disney_get_entity();

	hp_current += get_entity_property(ent, "hp");
	hp_max += getentityproperty(ent, "maxhealth");
	
	ratio_current = (hp_current / hp_max);

	/* 
	* At or below ratio_threshold?
	* If seo we execute new animation.
	*/
	if (ratio_current <= ratio_threshold)
	{
		if (getentityproperty(ent, "animvalid", animation))
		{
			/* Third parameter is resettable flag. */
			executeanimation(ent, animation, 1);
		}
	}
}