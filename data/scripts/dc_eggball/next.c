#include "data/scripts/dc_eggball/config.h"

/*
* "Last" is last time interval time expired.
*/

// Returns current interval or default if not set.
int dc_eggball_get_member_next()
{

    char id;
    int result;

    // Get id.
    id = dc_eggball_get_instance() + DC_EGGBALL_MEMBER_NEXT;

    result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_EGGBALL_DEFAULT_NEXT;
    }

    return result;
}

void dc_eggball_set_member_next(int value)
{

    char id;

    // Get ID.
    id = dc_eggball_get_instance() + DC_EGGBALL_MEMBER_NEXT;

    // If value is default, make sure the variable
    // is deleted.
    if (value == DC_EGGBALL_DEFAULT_NEXT)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

