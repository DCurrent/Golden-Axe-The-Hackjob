#include "data/scripts/dc_module_hud/config.h"

// Return a decimal fraction of
// current HP vs. max HP.
float get_health_fraction(void target)
{
	float health_current;   // Current HP.
	float health_max;       // Maximum HP.
	float result;           // Output.

	health_current  = 0.0 + get_entity_property(target, "hp_old");
	health_max      = 0.0 + getentityproperty(target, "maxhealth");

	// Don't divide by 0!
	if(health_current && health_max)
    {
        result = health_current / health_max;
    }
    else
    {
        result = 0.0;
    }

	return result;
}
