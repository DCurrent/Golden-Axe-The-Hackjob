// Configuration.
#include "data/scripts/dc_kanga/config.h"

#import "data/scripts/dc_kanga/entity.c"

// Caskey, Damon V.
// 2016-10-27
//
// Apply target entity's next map index in a continuous loop from
// first to last.
int dc_kanga_rotate_palette()
{
    int index_current;  // Current palette in use.
    int index_count;    // Number of palettes entity has loaded.
    void ent;			// Target entity.

    // Get target entity.
    ent = dc_kanga_get_target();

    // Get number of maps loaded and the entity's current map index.
    index_count     = getentityproperty(ent, "mapcount");
    index_current   = getentityproperty(ent, "maps", "current");

    // Increment to next index.
    index_current++;

    // If we've passed up the last index, reset to 0.
    if(index_current > index_count)
    {
        index_current = 0;
    }

    // Apply the map index.
    changeentityproperty(ent, "map", index_current);

    return index_current;
}
