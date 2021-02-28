#include "data/scripts/dc_gauntlet/config.h"

#import "data/scripts/dc_gauntlet/entity.c"


/* 
* Invert X offset settings.
*/

int dc_gauntlet_get_member_invert_x()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_INVERT_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_INVERT_X;
	}

	return result;
}

int dc_gauntlet_set_invert_x(int value)
{
	char id;

	id = dc_gauntlet_get_instance() + DC_GAUNTLET_MEMBER_INVERT_X;

	if (value != DC_GAUNTLET_DEFAULT_INVERT_X)
	{
		setlocalvar(id, value);
	}
	else
	{
		setlocalvar(id, NULL());
	}	
}

/* 
* Invert Y offset settings.
*/

int dc_gauntlet_get_member_invert_y()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_INVERT_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_INVERT_Y;
	}

	return result;
}

int dc_gauntlet_set_invert_y(int value)
{
	int instance;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_INVERT_Y, value);
}

/* 
* Invert Z offset settings.
*/

int dc_gauntlet_get_member_invert_z()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_INVERT_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_INVERT_Z;
	}

	return result;
}

int dc_gauntlet_set_invert_z(int value)
{
	int instance;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_INVERT_Z, value);
}

/* 
* X axis offset.
*/

int dc_gauntlet_get_member_offset_x()
{
	int instance;
	int result;

	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_OFFSET_X);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_OFFSET_X;
	}

	return result;
}

int dc_gauntlet_set_member_offset_x(int value)
{
	int instance;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_OFFSET_X, value);
}

/* 
* Y axis offset.
*/

int dc_gauntlet_get_member_offset_y()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_OFFSET_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_OFFSET_Y;
	}

	return result;
}

int dc_gauntlet_set_member_offset_y(int value)
{
	int instance;

	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_OFFSET_Y, value);
}

/* 
* Z axis offset.
*/

int dc_gauntlet_get_member_offset_z()
{
	int instance;
	int result;

	// Get instance.
	instance = dc_gauntlet_get_instance();

	result = getlocalvar(instance + DC_GAUNTLET_MEMBER_OFFSET_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_GAUNTLET_DEFAULT_OFFSET_Z;
	}

	return result;
}

int dc_gauntlet_set_member_offset_z(int value)
{
	int instance;

	instance = dc_gauntlet_get_instance();

	setlocalvar(instance + DC_GAUNTLET_MEMBER_OFFSET_Z, value);
}



/*** Operations ***/

/* 
* Caskey, Damon V.
* 2018-11-19
*
* Return an adjusted X offset to compensate for 
* scaling effects ent may have applied.
*/
int dc_gauntlet_find_scaled_offset_x()
{
	void	ent;
	float	scale;
	int		offset;

	/* Get the offset. */
	offset = dc_gauntlet_get_member_offset_x();

	/* Is there a valid ent entity? */
	ent = dc_gauntlet_get_member_entity();

	if (typeof(ent) == openborconstant("VT_PTR"))
	{
		/* 
		* Get ent scale. If it's a valid number,
		* then divide it by max value to get a scale 
		* percentage.
		*/
		scale = getdrawmethod(ent, "scalex");

		if (scale)
		{
			scale = scale / DC_GAUNTLET_DRAWMETHOD_SCALE_MAX_X;
		}

		/* 
		* Multiply offset by scale percentage to get
		* an offset that compensates for the
		* ent's current size.
		*/
		offset *= scale;
	}

	return offset;
}

/*
* Caskey, Damon V.
* 2018-11-19
*
* Return an adjusted Y offset to compensate for
* scaling effects ent may have applied.
*/
int dc_gauntlet_find_scaled_offset_y()
{
	void	ent;
	float	scale;
	int		offset;

	/* Get the offset. */
	offset = dc_gauntlet_get_member_offset_y();

	/* Is there a valid entity? */
	ent = dc_gauntlet_get_member_entity();

	if (typeof(ent) == openborconstant("VT_PTR"))
	{
		/* 
		* Get ent scale. If it's a valid number,
		* then divide it by max value to get a scale 
		* percentage.
		*/

		scale = getdrawmethod(ent, "scaley");

		if (scale)
		{
			scale = scale / DC_GAUNTLET_DRAWMETHOD_SCALE_MAX_Y;
		}

		/* 
		* Multiply offset by scale percentage to get
		* an offset that compensates for the
		* ent's current size.
		*/
		offset *= scale;
	}

	return offset;
}

/*
* Caskey, Damon V.
* 2018-11-24
*
* Return a final X offset value to use in non native
* bind functions. Don't use this to get an offset
* for OpenBOR's native bind, because it already
* does invert.
*/
int dc_gauntlet_find_offset_with_invert_x()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.

	/* Get invert and offset, we need these right away. */
	offset = dc_gauntlet_find_scaled_offset_x();
	invert = dc_gauntlet_get_member_invert_x();

	if (invert == DC_GAUNTLET_INVERT_DISABLED)
	{
		/* Do nothig, offset is returned as is. */
	}
	else if (invert == DC_GAUNTLET_INVERT_DIRECTION)
	{
		/* Invert if ent exists and is facing left. */

		ent = dc_gauntlet_get_member_entity();

		if (getentityproperty(ent, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}

	/* Return final offset. */
	return offset;
}

/*
* Caskey, Damon V.
* 2018-11-24
*
* Return a final Y offset value to use in non native
* bind functions. Don't use this to get an offset
* for OpenBOR's native bind, because it already
* does invert.
*/
int dc_gauntlet_find_offset_with_invert_y()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	
	/* Get invert and offset, we need these right away. */
	offset = dc_gauntlet_find_scaled_offset_y();
	invert = dc_gauntlet_get_member_invert_y();

	if (invert == DC_GAUNTLET_INVERT_DISABLED)
	{
		/* Do nothig, offset is returned as is. */
	}
	else if (invert == DC_GAUNTLET_INVERT_DIRECTION)
	{
		/* Invert if ent exists and is facing left. */

		ent = dc_gauntlet_get_member_entity();

		if (getentityproperty(ent, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}

	/* Return final offset. */
	return offset;
}

/*
* Caskey, Damon V.
* 2018-11-24
*
* Return a final Z offset value to use in non native
* bind functions. Don't use this to get an offset
* for OpenBOR's native bind, because it already
* does invert.
*/
int dc_gauntlet_find_offset_with_invert_z()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	
	/* Get invert and offset, we need these right away. */
	offset = dc_gauntlet_get_member_offset_z();
	invert = dc_gauntlet_get_member_invert_z();

	if (invert == DC_GAUNTLET_INVERT_DISABLED)
	{
		/* Do nothig, offset is returned as is. */
	}
	else if (invert == DC_GAUNTLET_INVERT_DIRECTION)
	{
		/* Invert if ent exists and is facing left. */
		ent = dc_gauntlet_get_member_entity();

		if (getentityproperty(ent, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	
	/* Return final offset. */
	return offset;
}

/* 
* Caskey, Damon V.
* 2019-03-18
* 
* Return position of entity with fully calculated offset added.
*/
int dc_gauntlet_find_position_with_offset_x()
{
	void ent;
	int pos;

	ent = dc_gauntlet_get_member_entity();

	pos = get_entity_property(ent, "position_x");

	pos += dc_gauntlet_find_offset_with_invert_x();

	return pos;
}

/* Caskey, Damon V.
* 2019-03-18
* 
* Return position of entity with fully calculated offset added.
*/
int dc_gauntlet_find_position_with_offset_y()
{
	void ent;
	int pos;

	ent = dc_gauntlet_get_member_entity();

	pos = get_entity_property(ent, "position_y");

	pos += dc_gauntlet_find_offset_with_invert_y();

	return pos;
}

/* 
* Caskey, Damon V.
* 2019-03-18
* 
* Return position of entity with fully calculated offset added.
*/
int dc_gauntlet_find_position_with_offset_z()
{
	void ent;
	int pos;

	ent = dc_gauntlet_get_member_entity();

	pos = get_entity_property(ent, "position_z");

	pos += dc_gauntlet_find_offset_with_invert_z();

	return pos;
}
