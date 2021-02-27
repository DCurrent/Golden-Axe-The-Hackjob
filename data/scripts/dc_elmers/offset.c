#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// Accessors and Mutators
// Invert X offset settings.
int dc_elmers_get_member_invert_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_INVERT_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_INVERT_X;
	}

	return result;
}

int dc_elmers_set_member_invert_x(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_INVERT_X;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_INVERT_X)
	{
		value = NULL();
	}
	
	setlocalvar(id, value);		
}

// Invert Y offset settings.
int dc_elmers_get_member_invert_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_INVERT_Y;

	result = getlocalvar(id + DC_ELMERS_MEMBER_INVERT_Y);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_INVERT_Y;
	}

	return result;
}

int dc_elmers_set_member_invert_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_INVERT_Y;

	if (value == DC_ELMERS_DEFAULT_INVERT_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Invert Z offset settings.
int dc_elmers_get_member_invert_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_INVERT_Z;

	result = getlocalvar(id + DC_ELMERS_MEMBER_INVERT_Z);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_INVERT_Z;
	}

	return result;
}

int dc_elmers_set_member_invert_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_INVERT_Z;

	if (value == DC_ELMERS_DEFAULT_INVERT_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// X axis offset.
int dc_elmers_get_member_offset_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_OFFSET_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_OFFSET_X;
	}

	return result;
}

int dc_elmers_set_member_offset_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_OFFSET_X;

	if (value == DC_ELMERS_DEFAULT_OFFSET_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis offset.
int dc_elmers_get_member_offset_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_OFFSET_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_OFFSET_Y;
	}

	return result;
}

int dc_elmers_set_member_offset_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_OFFSET_Y;

	if (value == DC_ELMERS_DEFAULT_OFFSET_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Z axis offset.
int dc_elmers_get_member_offset_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_OFFSET_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_OFFSET_Z;
	}

	return result;
}

int dc_elmers_set_member_offset_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_OFFSET_Z;

	if (value == DC_ELMERS_DEFAULT_OFFSET_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}


// Double offset. Double offset is when we bind grappled 
// and grappler together at the same time. The double offset 
// is for target entity (the grappler).
// X axis offset.
int dc_elmers_get_member_double_offset_x()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DOUBLE_OFFSET_X;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_DOUBLE_OFFSET_X;
	}

	return result;
}

int dc_elmers_set_member_double_offset_x(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DOUBLE_OFFSET_X;

	if (value == DC_ELMERS_DEFAULT_DOUBLE_OFFSET_X)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Y axis offset.
int dc_elmers_get_member_double_offset_y()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DOUBLE_OFFSET_Y;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_DOUBLE_OFFSET_Y;
	}

	return result;
}

int dc_elmers_set_member_double_offset_y(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DOUBLE_OFFSET_Y;

	if (value == DC_ELMERS_DEFAULT_DOUBLE_OFFSET_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Z axis offset.
int dc_elmers_get_member_double_offset_z()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DOUBLE_OFFSET_Z;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_DOUBLE_OFFSET_Z;
	}

	return result;
}

int dc_elmers_set_member_double_offset_z(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_DOUBLE_OFFSET_Z;

	if (value == DC_ELMERS_DEFAULT_DOUBLE_OFFSET_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}


// Operations

// Caskey, Damon V.
// 2018-11-19
//
// Return an adjusted offset to compensate for 
// X scaling effects target may have applied.
int dc_elmers_find_scaled_offset_x(void target, int offset)
{	
	float	scale;

	// Get the offset.
	offset = dc_elmers_get_member_offset_x();

	// Is there a valid target entity?
	target = dc_elmers_get_member_target();

	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scalex");

		if (scale)
		{
			scale = scale / DC_ELMERS_DRAWMETHOD_SCALE_MAX_X;
		}

		// Multiply offset by scale percentage to get
		// an offset that compensates for the
		// target's current size.
		offset *= scale;

		// Round and cast result as integer.
		offset = trunc(round(offset));
	}

	return offset;
}

// Caskey, Damon V.
// 2018-11-19
//
// Return an adjusted offset to compensate for 
// Y scaling effects target may have applied.
int dc_elmers_find_scaled_offset_y(void target, int offset)
{
	void	target;
	float	scale;
	int		offset;

	// Get the offset.
	offset = dc_elmers_get_member_offset_y();

	// Is there a valid target entity?
	target = dc_elmers_get_member_target();

	// Is there a valid target entity?
	if (typeof(target) == openborconstant("VT_PTR"))
	{
		// Get target scale. If it's a valid number,
		// then divide it by max value to get a scale 
		// percentage.
		scale = getdrawmethod(target, "scaley");

		if (scale)
		{
			scale = scale / DC_ELMERS_DRAWMETHOD_SCALE_MAX_Y;
		}

		// Multiply offset by scale percentage to get
		// an offset that compensates for the
		// target's current size.
		offset *= scale;

		// Round and cast result as integer.
		offset = trunc(round(offset));
	}	

	return offset;
}

// Caskey, Damon V.
// 2018-11-24
//
// Return a final X offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_elmers_find_offset_with_invert_x()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	target = dc_elmers_get_member_target();

	// Get invert and offset, we need these right away.
	offset = dc_elmers_find_scaled_offset_x(target, dc_elmers_get_member_offset_x());
	invert = dc_elmers_get_member_invert_x();

	if (invert == DC_ELMERS_INVERT_DISABLED)
	{
		// Do nothing, offset is returned as is.
	}
	else if (invert == DC_ELMERS_INVERT_DIRECTION)
	{
		// Invert if target is facing left.
		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_ELMERS_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_elmers_get_member_entity();
		target = dc_elmers_get_member_target();

		ent_pos = getentityproperty(ent, "x");
		target_pos = getentityproperty(target, "x");

		if (target_pos > ent_pos)
		{
			offset = -offset;
		}
	}		

	// Return final offset.
	return offset;
}

// Caskey, Damon V.
// 2018-11-24
//
// Return a final Y offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_elmers_find_offset_with_invert_y()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	// Get invert and offset, we need these right away.
	offset = dc_elmers_find_scaled_offset_y();
	invert = dc_elmers_get_member_invert_y();

	if (invert == DC_ELMERS_INVERT_DISABLED)
	{
		// Do nothing, offset is returned as is.
	}
	else if (invert == DC_ELMERS_INVERT_DIRECTION)
	{
		// Invert if target is and facing left.
		target = dc_elmers_get_member_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_ELMERS_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_elmers_get_member_entity();
		target = dc_elmers_get_member_target();

		ent_pos = getentityproperty(ent, "y");
		target_pos = getentityproperty(target, "y");

		if (target_pos > ent_pos)
		{
			offset = -offset;
		}
	}

	// Return final offset.
	return offset;
}

// Caskey, Damon V.
// 2018-11-24
//
// Return a final Z offset value to use in non native
// bind functions. Don't use this to get an offset
// for OpenBOR's native bind, because it already
// does invert.
int dc_elmers_find_offset_with_invert_z()
{
	int offset;			// Offset to output.
	int invert;			// Invert setting.
	void ent;			// Acting entity.
	void target;		// Target entity.
	float target_pos;	// Target location.
	float ent_pos;		// Entity location.	

	// Get invert and offset, we need these right away.
	offset = dc_elmers_get_member_offset_z();
	invert = dc_elmers_get_member_invert_z();

	if (invert == DC_ELMERS_INVERT_DISABLED)
	{
		// Do nothing, offset is returned as is.
	}
	else if (invert == DC_ELMERS_INVERT_DIRECTION)
	{
		// Invert if target is and facing left.
		target = dc_elmers_get_member_target();

		if (getentityproperty(target, "direction") == openborconstant("DIRECTION_LEFT"))
		{
			offset = -offset;
		}
	}
	else if (invert == DC_ELMERS_INVERT_POSITION)
	{
		// Invert if target is in a greater position.
		ent = dc_elmers_get_member_entity();
		target = dc_elmers_get_member_target();

		ent_pos = getentityproperty(ent, "z");
		target_pos = getentityproperty(target, "z");

		if (target_pos > ent_pos)
		{
			offset = -offset;
		}
	}

	// Return final offset.
	return offset;
}



