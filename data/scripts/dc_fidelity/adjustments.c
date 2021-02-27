#include "data/scripts/dc_fidelity/config.h"

// Enables auto balance. As a location moves horizontaly
// in relation to screen position, volume balance is 
// adjusted to create a true location based stereo
// effect.
void dc_fidelity_set_member_sound_location_balance(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_LOCATION_BALANCE;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_LOCATION_BALANCE == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_location_balance()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_LOCATION_BALANCE;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_LOCATION_BALANCE;
	}

	return result;
}

// Caskey, Damon V.
// 2020-07-06 (refactor from orginal function ~2010)
// 
// Accept position and volume. Applies stereo volume 
// effect by reducing supplied volume equal to % of 
// position from screen center toward opposite side 
// of channel.
//
// Example: 
// 
// Position from own side to center = Full volume. 
// Position halfway between center and opposite side = Half volume.
// Position at far opposite side: No volume.
int dc_fidelity_auto_balance_volume_left(float position, int volume)
{
	float	h_median;
	float	result;
	float	factor;
	float	relative_position;

	// To find out what volume to apply, we need to
	// divide the screen in half. We only care about
	// the side that is opposite of our channel
	// because at center and beyond/ we just use 
	// the supplied volume.
	//
	// Once we divide screen in half, we need to find
	// a relative position within that half from
	// the absolute position supplied to us.
	//
	// Once we have the absolute relative position
	// we find out what % it is of our screen half
	// from left to right.
	//
	// So, if the screen is 480, we want to know
	// what % the relative position is of 240.
	//
	// Finally, we can apply that % to the supplied
	// volume and return the result. 
	

	// Get get 50% of current resolution. This works 
	// as both our starting point and maximum range.
	h_median = openborvariant("hResolution") * 0.5;

	// The supplied position is absolute, so we need 
	// to subtract the level scroll position to get 
	// where we are on on screen.
	//
	// Example:
	//
	// Position: 800
	// Scroll Position: 500
	// Relative Position: 300

	// Level:	|----------------------00
	//			0                      Infinity
	//                          
	// Screen:			|----------|----------|
	//					0          240        480
	//
	// In OpenBOR, the screen's far left (0) in 
	// relation to entire level is scroll X.

	relative_position = position - (openborvariant("xpos"));
	
	// Below or at median? That means we are are
	// at or left of center, and there's no reason
	// to waste time with more calculations. Just
	// return supplied volume as is.
	if (relative_position <= h_median)
	{
		return volume;
	}

	// We need to know how far we are into the
	// opposite side of screen vs. our channel.
	//
	// This is the left channel, so we need to 
	// know far far we are over the center toward
	// right of screen. Find the difference between 
	// center and current relative position. Then
	// divide by half screen size (median works for
	// both center and half size) to get % factor.
	//
	// So if we have a resolution of 480 and are at
	// a relative position of 320, we are 80 from
	// the center, meaning we are 33% of the distance
	// between center and far right.
	factor = (relative_position - h_median) / h_median;

	// Now use the factor to reduce our volume.
	// Example: If we are 75% into the opposite 
	// side of screen, then reduce volume by 75%. 
	result = volume - (factor * volume);

	// Now round and truncate the result to get
	// an integer value, then make sure it isn't
	// below 0.
	result = trunc(round(result));

	if (result < 0)
	{
		result = 0;
	}

	// Return the result.
	return result;
}

// Caskey, Damon V.
// 2020-07-06 (refactor from orginal function ~2010)
// 
// Accept position and volume. Applies stereo volume 
// effect by reducing supplied volume equal to % of 
// position from screen center toward opposite side 
// of channel.
//
// Example: 
// 
// Position from own side to center = Full volume. 
// Position halfway between center and opposite side = Half volume.
// Position at far opposite side: No volume.
int dc_fidelity_auto_balance_volume_right(float position, int volume)
{
	float	h_median;
	float	result;
	float	factor;
	float	relative_position;

	// To find out what volume to apply, we need to
	// divide the screen in half. We only care about
	// the side that is opposite of our channel
	// because at center and beyond/ we just use 
	// the supplied volume.
	//
	// Once we divide screen in half, we need to find
	// a relative position within that half from
	// the absolute position supplied to us.
	//
	// Once we have the absolute relative position
	// we find out what % it is of our screen half
	// from left to right.
	//
	// So, if the screen is 480, we want to know
	// what % the relative position is of 240.
	//
	// Finally, we can apply that % to the supplied
	// volume and return the result. 


	// Get get 50% of current resolution. This works 
	// as our maximum range.
	h_median = openborvariant("hResolution") * 0.5;

	// The supplied position is absolute, so we need 
	// to subtract the level scroll position to get 
	// where we are on on screen.
	//
	// Example:
	//
	// Position: 800
	// Scroll Position: 500
	// Relative Position: 300

	// Level:	|----------------------00
	//			0                      Infinity
	//                          
	// Screen:			|----------|----------|
	//					0          240        480
	//
	// In OpenBOR, the screen's far left (0) in 
	// relation to entire level is scroll X.

	relative_position = position - (openborvariant("xpos"));

	// Above or at median? That means we are are
	// at or right of center, and there's no reason
	// to waste time with more calculations. Just
	// return supplied volume as is.
	if (relative_position >= h_median)
	{
		return volume;
	}

	// We need to know how far we are into the
	// opposite side of screen vs. our channel.
	// Find % of relative_position vs. median.
	factor = relative_position / h_median;

	// Now apply the factor our volume.
	// Example: If we are 15% away from the far
	// opposite position, play channel at 15%. 
	result = factor * volume;

	// Now round and truncate the result to get
	// an integer value, then make sure it isn't
	// below 0.
	result = trunc(round(result));

	if (result < 0)
	{
		result = 0;
	}

	// Return the result.
	return result;
}
