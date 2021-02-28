#include "data/scripts/dc_kanga/config.h"

// Caskey, Damon V.
// 2018-08-21
//
// Check local vars, and apply defaults to any
// that lack a usuable value.
void dc_kanga_check_z_position_autoscale_params()
{
	int type;	// Variable type.

	float autoscale_adjustment;
	float min_z_size;
	int	  scale_x;
	int	  scale_y;

	// We can't just (!value), because there
	// might be a 0 by design. We'll have to
	// use type to look for empty instead.

	autoscale_adjustment	= getlocalvar("autoscale_adjustment");
	type					= typeof(autoscale_adjustment);

	if (type == openborconstant("VT_EMPTY"))
	{
		setlocalvar("autoscale_adjustment", DC_KANGA_MIN_Z_ADJUST);
	}

	//
	min_z_size  = getlocalvar("min_z_size");
	type		= typeof(min_z_size);

	if (type == openborconstant("VT_EMPTY"))
	{
		setlocalvar("min_z_size", DC_KANGA_MIN_Z_SIZE);
	}

	//
	scale_x	= getlocalvar("drawsize_max");
	type	= typeof(scale_x);

	if (type == openborconstant("VT_EMPTY"))
	{
		setlocalvar("scale_x", DC_KANGA_AUTOSCALE_SCALE_X);
	}

	// 
	scale_y = getlocalvar("drawsize_max");
	type	= typeof(scale_y);

	if (type == openborconstant("VT_EMPTY"))
	{
		setlocalvar("scale_y", DC_KANGA_AUTOSCALE_SCALE_Y);
	}
}

// Caskey, Damon V.
// 2008-01-25
//
// Applies requested draweffects and autozoom to all valid entities. The overall effect is to cause an entity to shirink as it
// moves "away" from the player's viewpoint and expand as it moves toward the player's vantage, similar to many Neo-Geo games.

// 1. Zoom ratio is stored as entity variable for later use, and applied to ScaleX/ScaleY parameters of setdrawmthod for entity.
// 2. This function will overidde other uses of drawmethod. Therfore values are taken and applied from entity variables stored
// by other functions to control other setdrawmethod parameters. This includes manual adjustment of scale values if desired.
// 3. Autozoom variance is controlled by fMinZ * X. By changing the value of fMax, it is also possible to change the Z location in
// which entity is shown at its normal size.
void dc_kanga_z_position_autoscale(void target){    

	float	autoscale_adjustment;
	float	min_z_size;
	float	drawsize_max;

	float	scale_x;			// Current scale.
	float	scale_y;
	float	range_z;			// Range between min and max player Z.
	float	scale_final;		// 0-255 scale to apply after calculations.	
	float	pos_z;				// Z position.

	float	min_z_distance;		// Distance from minimum Z.
	float	min_z_adjusted;		// Min Z after DC_KANGA_MIN_Z_ADJUST is applied.
	float	median_z;			// Midpoint between min (adjusted) and max Z.

	float	range_percentage;	// % of z pos to min_z range vs min_z to max_z range. 

	// Before going further, let's populate the adjustment values.
	dc_kanga_check_z_position_autoscale_params();

	autoscale_adjustment = getlocalvar("autoscale_adjustment");
	min_z_size = getlocalvar("min_z_size");
	scale_x = getlocalvar("scale_x");
	scale_y = getlocalvar("scale_y");


	// Get adjusted minimum Z, and range between it
	// and maximum Z. The adjustment affects what Z 
	// position the entity will be displayed at its 
	// original size.
	min_z_adjusted	= openborconstant("PLAYER_MIN_Z") * autoscale_adjustment;
	range_z = (openborconstant("PLAYER_MAX_Z")) - min_z_adjusted;

	// Get Z posiiton and range from minimum z.
	pos_z = getentityproperty(target, "z");
	min_z_distance = pos_z - min_z_adjusted;

	// Get a percentage of distance between full
	// z range and range between target's z position
	// and minimum z. 
	if (min_z_distance != 0 && range_z)
	{
		range_percentage = min_z_distance / range_z;
	}
	else
	{
		range_percentage = 0.0;
	}
	
	// Move the percentage one decimal right, and then
	// add the min_z size percentage constant. This is 
	// what makes the minimum Z position a minimum 
	// base size. As an example, if our Z range is
	// min 200 max 250, and the entity is at 225, the
	// resulting percentage would be 50% - meaning
	// a half sized entity. This also means the entity 
	// would be at 0% size if it were at 200. But by 
	// moving the decimal one right and adding a value 
	// of 9, the entity's size at 200 will be 90% and
	// at 225 it will be 95% sized. This is a much more 
	// acceptable range of size for the entity.
	range_percentage *= 0.1;
	range_percentage += min_z_size;

	// Now mutiply our final % value by the scale
	// sizes so we have usable values for drawmethod.
	scale_x *= range_percentage;
	scale_y *= range_percentage;

	changedrawmethod(target, "enabled", 1);
	changedrawmethod(target, "scalex", scale_x);
	changedrawmethod(target, "scaley", scale_y);

}