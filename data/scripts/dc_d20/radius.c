#include   "data/scripts/dc_d20/config.h"

#import    "data/scripts/dc_d20/negative.c"
#import    "data/scripts/dc_d20/random.c"

/**
* Caskey, Damon V.
* 2019-11-11
*
* Generate a set of random X and Y offsets within
* area of a circle. Accepts radius and outputs
* pointer to an array contianing random X and Y 
* offsets from center of the circle. 
*
* Remember arrays are global - make sure to free
* the pointer when you are finished with it.
**/
void dc_d20_generate_radial_coordinates(int radius)
{
	/* 
	* We need a square of the radius.
	*/
	float rSquared = radius * radius;

	/*
	* Select a random point within diameter of circle
	* along X axis.
	*/
	dc_d20_set_member_range_min(0);
	dc_d20_set_member_range_max(radius);	

	float x = dc_d20_generate_random_int();

	/* 
	* Select random point within diameter of circle along 
	* Y axis with square root. This is so we don't favor
	* the inside areas of circle.
	*/
	dc_d20_set_member_range_min(0);
	dc_d20_set_member_range_max(100);

	float y = (dc_d20_generate_random_int() * 0.01) * sqrt(rSquared - x * x);

	y = trunc(y);

	/*
	* Our formula can only return positive values, so 
	* we'll use a 50% chance to reverse the X, Y, or
	* both in order to cover the "back" and lower halves.
	*/
	if (dc_d20_generate_random_int() > 50)
	{
		x = -x;
	}

	if (dc_d20_generate_random_int() > 50)
	{
		y = -y;
	}

	/*
	* Now build array with both axis coordinates and return
	* the array pointer. OpenBOR arrays occupy a global
	* memory space, so make sure you hang on to this pointer 
	* and free it when you don't need the data any more.
	*/
	void result = array(DC_D20_RADIUS_RETURN_SIZE);

	set(result, DC_D20_RADIUS_RETURN_X, x);
	set(result, DC_D20_RADIUS_RETURN_Y, y);

	return result;
}
