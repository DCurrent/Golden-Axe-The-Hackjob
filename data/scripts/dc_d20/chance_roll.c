#include    "data/scripts/dc_d20/config.h"
#import    "data/scripts/dc_d20/random.c"

/* 
* Lowest number random generator can return.
*/

int dc_d20_get_member_chance()
{
	char id = dc_d20_get_instance() + DC_D20_MEMBER_CHANCE;
    void result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_D20_DEFAULT_CHANCE;
    }

    return result;
   
}

void dc_d20_set_member_chance(int value)
{
	char id = dc_d20_get_instance() + DC_D20_MEMBER_CHANCE;

    if (value == DC_D20_DEFAULT_CHANCE)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2021-05-25
*
* Roll <chance> out of min range to 
* max range. Presumably the min and 
* max members are at their default
* values of 0 and 100. 
* 
* Return TRUE if random number
* meets or exeeds chance value. 
* 
* Return FALSE otherwise. 
*/
int dc_d20_chance_roll()
{
	int chance = dc_d20_get_member_chance();

	/*
	* We're rolling for chance of random
	* so we return true if random value
	* is less than the chance value.
	* 
	* In case chance happens to fall below
	* minimum range we fail automatically.
	* If chance meets or exceeds maximum
	* range then we succeed.
	*/

	/* Automatic fail. */
	if (chance < dc_d20_get_member_range_min())
	{
		return 0;
	}

	/* Automatic success. */
	if (chance >= dc_d20_get_member_range_max())
	{
		return 1;
	}
	
	/* Chance meets or exceeds random roll? */
	if (chance >= dc_d20_random_int())
	{
		return 1;
	}

	return 0;

}