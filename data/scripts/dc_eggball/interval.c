#include "data/scripts/dc_eggball/config.h"

// Returns current instance or default if not set.
int dc_eggball_check_instance()
{
    int result;

    result = getlocalvar(DC_EGGBALL_INSTANCE);

    if(!result)
    {
        result = DC_EGGBALL_DEFAULT_INSTANCE;
    }

    return result;
}

void dc_eggball_set_instance(int value)
{
    setlocalvar(DC_EGGBALL_INSTANCE, value);
}

void dc_eggball_set_interval(int value)
{
    int result;
    int instance;

    // Get the instance.
    instance = dc_eggball_check_instance();

    result = setlocalvar(DC_EGGBALL_INTERVAL + instance, value);


}

// Returns current interval or default if not set.
int dc_eggball_check_interval()
{
    int result;
    int instance;

    // Get the instance.
    instance = dc_eggball_check_instance();

    result = getlocalvar(DC_EGGBALL_INTERVAL + instance);

    if(!result)
    {
        result = DC_EGGBALL_DEFAULT_INSTANCE;
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
    instance = dc_eggball_check_instance();

    // Populate in-line vars.
    result          = DC_EGGBALL_FLAG_FALSE;
    elapsed_current = openborvariant("elapsed_time");
    last_occurrence = getlocalvar(DC_EGGBALL_LAST + instance);
    interval        = dc_eggball_check_interval();

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
        setlocalvar(DC_EGGBALL_LAST + instance, elapsed_current);
    }

    return result;
}



