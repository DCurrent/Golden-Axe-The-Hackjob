// General calculations for use in other libraries.

#include "data/scripts/dc_spinner/config.h"

#import "data/scripts/dc_spinner/instance.c"
#import "data/scripts/dc_spinner/spinner.c"

/*
* Caskey, Damon V.
* 
* Increment an adjustment value in a wave
* pattern. For example, given an adjustment
* value of 10, incrmeneted values range 
* from -10 to 10, then back to -10 in an
* endless loop.   
*/
float dc_spinner_sine(float increment, int delay)
{

    int elpased_time = openborvariant("elapsed_time");
    int time_next = getlocalvar("dc_spinner_time_last");
    float accumulator = getlocalvar("dc_spinner_accumulator");

    /*
    * OpenBOR treats ininitialized numerics as 
    * empty, not 0, so if empty set 0.
    * 
    * In the case of time_next, we'll want to reset 
    * if there is a time value leftover from previous 
    * level play.
    * 
    * We'll also put in a safeguard just in case the 
    * accumulator goes out of bounds. You'd have to
    * play one level for a couple of hours straight
    * for that to happen, but it's still possible.
    */

    if (!time_next || time_next > (elpased_time + delay))
    {
        time_next = 0;
        accumulator = 0;
    }

    if (!accumulator || accumulator >= 2147483647 - increment || accumulator < 0)
    {
        accumulator = 0;
    }
    
    /*
    * If delay time is expired, then add increment
    * to accumulator.
    */
    if (time_next <= elpased_time)
    {
        time_next = elpased_time + delay;

        accumulator += increment;
    }
        
    float result = sin(accumulator);

    //settextobj(7, 10, 100, 1, 999999994, "Value: " + accumulator);
    //settextobj(8, 10, 110, 1, 999999994, " Sine: " + result);
    
    /*
    * Populate local vars for next cycle.
    */

    setlocalvar("dc_spinner_accumulator", accumulator);
    setlocalvar("dc_spinner_time_last", time_next);

    return result;
}