#include "data/scripts/dc_math/config.h"

// Caskey, Damon V.
// 2018-11-24
//
// Discard signs and return true if Value A is
// greater than Value B.
int dc_math_compare_unisgned_float(float A, float B)
{
	// Remove signing for values.
	if (A < 0.0)
	{
		A = -A;
	}
	
	if(B < 0.0)
	{
		B = -B;
	}

	// If A is greater than B, return true.
	if (A > B)
	{
		return 1;
	}

	return 0;
}

// Caskey, Damon V.
// 2018-11-24
//
// Discard signs and return true if Value A is
// greater than Value B.
int dc_math_compare_unisgned_int(int A, int B)
{
	// Remove signing for values.
	if (A < 0)
	{
		A = -A;
	}

	if (B < 0)
	{
		B = -B;
	}

	// If A is greater than B, return true.
	if (A > B)
	{
		return 1;
	}

	return 0;
}