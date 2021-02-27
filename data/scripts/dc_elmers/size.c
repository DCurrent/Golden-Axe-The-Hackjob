#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"

// When finding an offset based on height, apply this
// as a mutiplier.
float dc_elmers_get_member_size_height_factor()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_SIZE_FACTOR_HEIGHT;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_DECIMAL"))
	{
		result = DC_ELMERS_DEFAULT_SIZE_FACTOR_HEIGHT;
	}

	return result;
}

// When finding an offset based on height, apply this
// as a mutiplier.
float dc_elmers_set_size_height_factor(int value)
{
	char id;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_SIZE_FACTOR_HEIGHT;

	if (value == DC_ELMERS_DEFAULT_SIZE_FACTOR_HEIGHT)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Return height based on graphics size of target's
// current animation and preset factor.
// For instance, if we want shoulder height, setting
// factor to 0.8 will get a nice approximation.
int dc_elmers_find_size_height(void ent)
{
	int result;
	int animation;
	int frame;
	void sprite;

	if (!ent)
	{
		ent = dc_elmers_get_member_entity();
	}

	animation = DC_ELMERS_REACT_ANIMATION;// get_entity_property(target, "animation_id");
	frame = DC_ELMERS_REACT_PAIN_MID_1; // get_entity_property(target, "animation_frame");

	sprite = getentityproperty(ent, "spritea", "sprite", animation, frame);

	result = getgfxproperty(sprite, "height"); //*dc_elmers_get_member_size_height_factor();

	// Round and then remove the decimal to get 
	// whole number.
	result = trunc(round(result));

	return result;
}