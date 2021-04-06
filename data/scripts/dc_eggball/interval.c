#include "data/scripts/dc_eggball/config.h"
#import  "data/scripts/dc_eggball/next.c"

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
   
    log("\n\n result(): " + result);
    log("\n\n typeof(result): " + typeof(result));

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_EGGBALL_DEFAULT_INTERVAL;
    }

    log("\n\n result(): " + result);

    return result;
}

/*
* Caskey, Damon V.
* 2021-04-05
* Orginal ~2017
* 
* Return true and prepare for next interval if 
* interval time is expired.
*/
int dc_eggball_check_interval()
{
    int result;
    int elapsed_time;    // Current gametime.
    int interval;           // Time interval.
    int instance;           // Instance index.
    int next;           // Time of triggered instance.
    int difference;         // Time difference.
    
    /* Populate in-line vars. */
    result          = DC_EGGBALL_FLAG_FALSE;
    elapsed_time    = openborvariant("elapsed_time");
    next            = dc_eggball_get_member_next();
    interval        = dc_eggball_get_member_interval();

    /* Initialize next if this is first run. */
    if (next == DC_EGGBALL_DEFAULT_NEXT)
    {
        next = elapsed_time + interval;

        dc_eggball_set_member_next(next);
    }

    /* 
    * Time expired? Set time for next interval and
    * set result true.
    */
    if(elapsed_time >= next)
    {    
        result = DC_EGGBALL_FLAG_TRUE;
        
        next = elapsed_time + interval;

        dc_eggball_set_member_next(next);
    }
        

    return result;
}