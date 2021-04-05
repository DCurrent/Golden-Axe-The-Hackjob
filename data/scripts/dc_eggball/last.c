#include "data/scripts/dc_eggball/config.h"

/*
* "Last" is last time interval time expired.
*/

// Returns current interval or default if not set.
int dc_eggball_get_member_last()
{

    char id;
    int result;

    // Get id.
    id = dc_eggball_get_instance() + DC_EGGBALL_MEMBER_LAST;

    result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_EGGBALL_DEFAULT_LAST;
    }

    return result;
}

void dc_eggball_set_member_last(int value)
{

    char id;

    // Get ID.
    id = dc_eggball_get_instance() + DC_EGGBALL_MEMBER_LAST;

    // If value is default, make sure the variable
    // is deleted.
    if (value == DC_EGGBALL_MEMBER_LAST)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}