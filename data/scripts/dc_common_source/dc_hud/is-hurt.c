#include "data/scripts/dc_common_source/dc_hud/config.h"

// Return true if target is currently
// receiving an attack, being grappled,
// or otherwise taking punishment.
int dc_get_is_hurt(void target)
{
    int drop;   // Falling flag.
    int pain;   // Pain flag.
    int frozen; // Frozen flag.
    int seal;   // Seal factor.

    // Falling?
    drop = getentityproperty(target, "aiflag", "drop");

    if(drop)
    {
        return 1;
    }

    // In pain (reeling from a hit)?
    pain = getentityproperty(target, "aiflag", "inpain");

    if(pain)
    {
        return 1;
    }

    // Frozen?
    frozen = getentityproperty(target, "frozen");

    if(frozen)
    {
        return 1;
    }

    // Special moves disabled? This is done in a grapple,
    // so its a good way to tell if target is being
    // thrown around.
    seal = getentityproperty(target, "seal");

    if(seal)
    {
        return 1;
    }

    // Made it this far, then we can return
    // false and exit.
    return 0;
}
