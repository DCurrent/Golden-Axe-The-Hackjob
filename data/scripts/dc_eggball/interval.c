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

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_EGGBALL_DEFAULT_INTERVAL;
    }

    return result;
}

/*
* Cskey, Damon V.
* 2021-04-06
* 
* Reset interval time by addinf interval value to 
* the next member variable.
*/
int dc_eggball_reset_interval()
{
    int interval = dc_eggball_get_member_interval();
    int next = 0;
    int elapsed_time = openborvariant("elapsed_time");

    next = interval + elapsed_time;

    dc_eggball_set_member_next(next);

    return next;
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
    int instance;           // Instance index.
    int next;           // Time of triggered instance.
    int difference;         // Time difference.
    
    /* Populate in-line vars. */
    result          = DC_EGGBALL_FLAG_FALSE;
    elapsed_time    = openborvariant("elapsed_time");
    next            = dc_eggball_get_member_next();

    /* Initialize next if this is first run. */
    if (next == DC_EGGBALL_DEFAULT_NEXT || (!elapsed_time && next))
    {
        next = dc_eggball_reset_interval();
    }
    
    /* 
    * Time expired? Set time for next interval and
    * set result true.
    */
    if(elapsed_time >= next)
    {    
        result = DC_EGGBALL_FLAG_TRUE;
        
        dc_eggball_reset_interval();
    }
        
    return result;
}