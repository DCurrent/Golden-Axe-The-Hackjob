#include    "data/scripts/dc_d20/config.h"
#import    "data/scripts/dc_d20/negative.c"

/* 
* Lowest number random generator can return.
*/

int dc_d20_get_member_range_min()
{
    char id = dc_d20_get_instance() + DC_D20_MEMBER_RANGE_MIN;
    void result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_D20_DEFAULT_RANGE_MIN;
    }

    return result;
}

void dc_d20_set_member_range_min(int value)
{
    char id = dc_d20_get_instance() + DC_D20_MEMBER_RANGE_MIN;

    if (value == DC_D20_DEFAULT_RANGE_MIN)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}


/* 
* Highest number random generator can return.
*/
int dc_d20_get_member_range_max()
{
    char id = dc_d20_get_instance() + DC_D20_MEMBER_RANGE_MAX;
    void result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_D20_DEFAULT_RANGE_MAX;
    }

    return result;
}

void dc_d20_set_member_range_max(int value)
{
    char id = dc_d20_get_instance() + DC_D20_MEMBER_RANGE_MAX;

    if (value == DC_D20_DEFAULT_RANGE_MAX)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}


/*
* Generate random value between
* upper and lower boundaries.
*/
int dc_d20_random_int()
{
    int result;

    result = dc_d20_generate_random_int();

    return result;
}

int dc_d20_generate_random_int()
{
    int result;
    int lower_bound;
    int upper_bound;
    int mod;

    /*
    * Get upper and lower bound settings.
    */
    lower_bound = dc_d20_get_member_range_min();
    upper_bound = dc_d20_get_member_range_max();

    /*
    * OpenBOR's random generator is a bit odd,
    * so we'll need to do some math work to get
    * usable values.
    */

    /* 
    * Find difference between desired min and max,
    * then add 1 to create random seed.
    */
    mod = (upper_bound - lower_bound) + 1;
	
    /*
    * Generate random number.
    */
    result  = rand()%mod;

    /*
    * Unless we also negatives, make sure the result
    * is a positive value.
    */
    if (result < 0 && dc_d20_get_allow_negative() == DC_D20_ALLOW_NEGATIVE_FALSE)
    {
        result = result * -1;
    }

    /*
    * Apply lower bound cap if needed.
    */
    result = result + lower_bound;

    // Return final result.
    return result;
}
