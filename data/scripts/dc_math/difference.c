#include "data/scripts/dc_math/config.h"

/* 
* Caskey, Damon V.
* 2018-11-24
*
* Find difference between two floating point values.
*/
float dc_math_difference_float(float a, float b)
{
	if (a < b)
	{
		return b - a;
	}
	return a - b;
}


/*
* Caskey, Damon V.
* 2018-11-24
*
* Find difference between two integer values.
*/
int dc_math_difference_int(int a, int b)
{
	if (a < b)
	{
		return b - a;
	}
	return a - b;
}