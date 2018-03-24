#include "data/scripts/dc_hud/config.h"

// Get a pre-loaded colored block sprite based on
// fraction argument.
int dc_get_block_large(float value_fraction)
{

    int sprite_index;

    if (value_fraction >= 0.75)
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE);
    }
    else if (value_fraction >= 0.50)
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW);
    }
    else if (value_fraction >= 0.25)
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE);
    }
    else
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED);
    }

    return sprite_index;
}
