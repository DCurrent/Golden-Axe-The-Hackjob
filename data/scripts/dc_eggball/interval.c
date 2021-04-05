#include "data/scripts/dc_eggball/config.h"

void dc_eggball_set_member_interval(int value)
{

    char id;

    // Get ID.
    id = dc_eggball_get_instance() + DC_EGGBALL_MEMBER_INTERVAL;

    // If value is default, make sure the variable
    // is deleted.
    if (value == DC_EGGBALL_DEFAULT_INTERVAL)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

// Returns current interval or default if not set.
int dc_eggball_get_member_interval()
{

    char id;
    int result;

    // Get id.
    id = dc_eggball_get_instance() + DC_EGGBALL_MEMBER_INTERVAL;

    result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_EGGBALL_DEFAULT_INTERVAL;
    }

    return result;
}

int dc_eggball_interval()
{
    int result;
    int elapsed_current;    // Current gametime.
    int interval;           // Time interval.
    int instance;           // Instance index.
    int last_occurrence;    // Time of triggered instance.
    int difference;         // Time difference.

    // Which instance are we using?
    instance = dc_eggball_get_instance();

    // Populate in-line vars.
    result          = DC_EGGBALL_FLAG_FALSE;
    elapsed_current = openborvariant("elapsed_time");
    last_occurrence = getlocalvar(DC_EGGBALL_MEMBER_LAST + instance);
    interval        = dc_eggball_get_member_interval();

    // If last occurrence is empty or
    // exceeds elapsed time then re-zero.
    if(!last_occurrence || last_occurrence > elapsed_current)
    {
        last_occurrence = 0;
    }

    // If no interval is set, then use default.
    if(!interval)
    {
        interval = DC_EGGBALL_DEFAULT_INTERVAL;
    }

    // Get difference between last_occurrence
    // and elapsed_current.
    difference = elapsed_current - last_occurrence;

    // Once difference is met, perform
    // action and record last occurrence
    // for the next cycle.
    if(difference >= interval)
    {
        result = DC_EGGBALL_FLAG_TRUE;
        setlocalvar(DC_EGGBALL_MEMBER_LAST + instance, elapsed_current);
    }

    return result;
}



