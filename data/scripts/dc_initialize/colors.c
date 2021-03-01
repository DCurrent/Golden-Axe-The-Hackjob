#include "data/scripts/dc_initialize/config.h"

#import "data/scripts/dc_initialize/config.c"

// Caskey, Damon V.
// 2018-10-12 (Rewrite from orginal, 2007-07-??)
// 
// Randomly choose return index of one of the target entity's 
// non-hidden color sets.
char dc_initialize_random_color_set()
{
	void ent;
	int hidden_map_lower;
	int hidden_map_upper;
	int mapcount;

	int random_index;

	ent = dc_initialize_get_entity();

	hidden_map_lower = getentityproperty(ent, "hmapl");
	hidden_map_upper = getentityproperty(ent, "hmapu");

	mapcount = getentityproperty(ent, "mapcount");

	// Use the number of color sts available as maximum random number.
	dc_d20_set_range_max(mapcount);

	// Generate a random map index. If we accidently choose a map
	// that is in the hidden range, loop back until we find one that
	// is not.
	do
	{
		// Generate random number.
		random_index = dc_d20_random_int();

	} while (hidden_map_lower && (random_index >= hidden_map_lower && random_index <= hidden_map_upper));

	// Return the color map index.
	return random_index;
}