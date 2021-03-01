#include "data/scripts/dc_initialize/config.h"

#import "data/scripts/dc_initialize/config.c"
#import "data/scripts/dc_initialize/colors.c"
#import "data/scripts/dc_initialize/alias.c"


// This is really just a shortcut for function calls that
// almost every level spawn will need to make.
void dc_initialize_level_spawn()
{
	void ent;
	void alias; // Caller's alias.
	int map;	// Caller's map.

	ent = dc_initialize_get_entity();

	// If entity is spawned into play with its KO map,
	// then will randomly select one of its other
	// regular maps here.
	map = getentityproperty(ent, "map");

	if (map == 1)
	{
		map = dc_initialize_random_color_set();

		changeentityproperty(ent, "map", map);
	}

	// If the spawned entity is named "random", then we will
	// generate and assign a random alias here.
	alias = getentityproperty(ent, "name");

	if (alias == "Random")
	{
		alias = dc_initialize_random_alias();

		changeentityproperty(ent, "name", alias);
	}
}