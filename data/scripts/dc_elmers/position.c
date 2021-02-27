#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/level.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/position_config.c"

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_elmers_find_target_position_x()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_elmers_get_member_anchor_x();

	if (positioning == DC_ELMERS_MODE_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = get_entity_property(ent, "position_x");
	}
	else if (positioning == DC_ELMERS_MODE_LEVEL)
	{
		result = dc_elmers_get_member_level_x();
	}
	else if (positioning == DC_ELMERS_MODE_SCREEN)
	{
		result = DC_ELMERS_DEFAULT_SCREEN_X;
	}
	else if (positioning == DC_ELMERS_MODE_TARGET)
	{
		result = get_entity_property(target, "position_x");
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_elmers_find_target_position_y()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_elmers_get_member_anchor_y();

	if (positioning == DC_ELMERS_MODE_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = get_entity_property(ent, "position_y");
	}
	else if (positioning == DC_ELMERS_MODE_LEVEL)
	{
		result = dc_elmers_get_member_level_y();
	}
	else if (positioning == DC_ELMERS_MODE_SCREEN)
	{
		result = DC_ELMERS_DEFAULT_SCREEN_Y;
	}
	else if (positioning == DC_ELMERS_MODE_TARGET)
	{
		result = get_entity_property(target, "position_y");
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-23
//
// Return a final position depending on positioning settings
// and offsets. Don't use for native engine bind functions 
// since they already do this.
float dc_elmers_find_target_position_z()
{
	void ent;			// Entity to be repositioned.
	void target;		// Target entity;
	int positioning;	// Positioning type.
	float result;		// Final output.

	// Entities.
	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	// Let's get the positioning setting and decide what to do.
	positioning = dc_elmers_get_member_anchor_z();

	if (positioning == DC_ELMERS_MODE_DISABLED)
	{
		// Use current position (IOW, no position change).
		result = get_entity_property(ent, "position_z");
	}
	else if (positioning == DC_ELMERS_MODE_LEVEL)
	{
		result = dc_elmers_get_level_z();
	}
	else if (positioning == DC_ELMERS_MODE_SCREEN)
	{
		result = DC_ELMERS_DEFAULT_SCREEN_Z;
	}
	else if (positioning == DC_ELMERS_MODE_TARGET)
	{
		// Target position.
		result = get_entity_property(target, "position_z");
	}

	return result;
}

// Caskey, Damon V.
// 2018-11-19
// 
// Move entity to target location with offset,
// or to screen position if target is NULL().
void dc_elmers_apply_position()
{
	void ent;

	float pos_x;
	float pos_y;
	float pos_z;

	// Get entities.
	ent = dc_elmers_get_member_entity();

	// Get position for each axis.
	pos_x = dc_elmers_find_position_with_offset_x();
	pos_y = dc_elmers_find_position_with_offset_y();
	pos_z = dc_elmers_find_position_with_offset_z();

	// Apply the position change.
	changeentityproperty(ent, "position", pos_x, pos_z, pos_y);
}

// Caskey, Damon V.
// 2018-11-23
// 
// Reposition entity to an offset from target's 
// location if distance between target and ent 
// is greater than the offset.
void dc_elmers_reposition_to_offset()
{
	void ent;
	void target;

	// Offsets.
	int offset;
	int offset_check;

	// Position to apply.
	float pos_x;
	float pos_y;
	float pos_z;

	// Difference between entity position vs target.
	float diff;

	// Get entities.
	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	// Get entity location for each axis.
	pos_x = get_entity_property(ent, "position_x");
	pos_y = get_entity_property(ent, "position_y");
	pos_z = get_entity_property(ent, "position_z");

	// X
	if (dc_elmers_get_member_anchor_x() != DC_ELMERS_MODE_DISABLED)
	{
		
		offset = dc_elmers_get_member_offset_x();

		// If the scaled offset is less than distance to target,
		// then get a finalized offset and add it to position.
		if (dc_math_compare_unisgned_float(dc_elmers_find_distance_to_target_x(), dc_elmers_find_scaled_offset_x(target, offset)))
		{
			pos_x += dc_elmers_find_offset_with_invert_x();
		}
	}

	// Y
	if (dc_elmers_get_member_anchor_y() != DC_ELMERS_MODE_DISABLED)
	{
		offset = dc_elmers_get_member_offset_y();

		// If the scaled offset is less than distance to target,
		// then get a finalized offset and add it to position.
		if (dc_math_compare_unisgned_float(dc_elmers_find_distance_to_target_y(), dc_elmers_find_scaled_offset_y(target, offset)))
		{
			pos_y += dc_elmers_find_offset_with_invert_y();
		}
	}

	// Z
	if (dc_elmers_get_member_anchor_y() != DC_ELMERS_MODE_DISABLED)
	{
		// If the scaled offset is less than distance to target,
		// then get a finalized offset and add it to position.
		if (dc_math_compare_unisgned_float(dc_elmers_find_distance_to_target_z(), dc_elmers_get_member_offset_z()))
		{
			pos_z += dc_elmers_find_offset_with_invert_z();
		}
	}

	// Apply the position change.
	set_entity_property(ent, "position_x", pos_x);
	set_entity_property(ent, "position_y", pos_y);
	set_entity_property(ent, "position_z", pos_z);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_elmers_find_distance_to_target_x()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	target_pos = dc_elmers_find_target_position_x();

	ent_pos = get_entity_property(ent, "position_x");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_elmers_find_distance_to_target_y()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	target_pos = dc_elmers_find_target_position_y();

	ent_pos = get_entity_property(ent, "position_y");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
//
// Find distance bewtween target location and entity.
float dc_elmers_find_distance_to_target_z()
{
	void ent;
	void target;
	float target_pos;
	float ent_pos;

	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	target_pos = dc_elmers_find_target_position_z();

	ent_pos = get_entity_property(ent, "position_z");

	return dc_math_difference_float(ent_pos, target_pos);
}

// Caskey, Damon V.
// 2018-11-23
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_elmers_find_position_with_offset_x()
{
	int direction;
	int offset;
	float position;
	void target;

	target = dc_elmers_get_member_target();

	position = dc_elmers_find_target_position_x();
		
	offset = dc_elmers_find_scaled_offset_x(target, dc_elmers_get_member_offset_x());

	if (dc_elmers_get_member_anchor_x() != DC_ELMERS_MODE_DISABLED)
	{
		// If target is facing left and 
		// inverting is enabled, then
		// we invert the offset before
		// applying it to position.	

		direction = get_entity_property(target, "position_direction");

		if (direction == openborconstant("DIRECTION_LEFT"))
		{
			if (dc_elmers_get_member_invert_x() == DC_ELMERS_INVERT_DIRECTION)
			{
				offset = -offset;
			}
		}

		position += offset;
	}

	// Return final position.
	return position;
}

// Caskey, Damon V.
// 2018-11-23
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_elmers_find_position_with_offset_y()
{
	int offset;
	float position;
	void target;

	target = dc_elmers_get_member_target();

	position = dc_elmers_find_target_position_y();

	offset = dc_elmers_find_scaled_offset_y(target, dc_elmers_get_member_offset_y());

	if (dc_elmers_get_member_anchor_x() != DC_ELMERS_MODE_DISABLED)
	{
		position += offset;
	}

	// Return final position.
	return position;
}

// Caskey, Damon V.
// 2018-11-23
//
// Find position to apply after offset and positioning
// settings are factored.
float dc_elmers_find_position_with_offset_z()
{
	int offset;
	float position;

	position = dc_elmers_find_target_position_z();

	offset = dc_elmers_get_member_offset_z();

	if (dc_elmers_get_member_anchor_x() != DC_ELMERS_MODE_DISABLED)
	{
		position += offset;
	}

	// Return final position.
	return position;
}

// Caskey, Damon V.
// 2019-04-28
//
// Move entity toward or away from target position by amount
// determined with adjustment quantity settings. Positive adjustments
// push entity away from target position. Negative adjustments
// pull toward target position.
void dc_elmers_adjust_distance_to_x()
{
	void ent;

	float pos_old;
	float pos_final;
	int adjust;

	ent = dc_elmers_get_member_entity();

	// Get the amount we want to adjust.
	adjust = dc_elmers_get_member_position_adjust_quantity_x();

	// Get our final "goal" posiiton. We'll decide how (or if)
	// to adjust it below.
	pos_final = dc_elmers_find_position_with_offset_x();

	// If the distance to our target location is less than
	// adjustment, then there's no reason to adjust the final
	// goal position.
	if (dc_math_compare_unisgned_float(adjust, dc_math_compare_unisgned_float(pos_old, pos_final)))
	{
		// Assuming we are pushing away from goal (positive adjustment) 
		// if the goal position is to the right, subtract adjustment 
		// from goal. This will get us a leftward position to apply.
		// Otherwise we add to go rightward.
		//
		// If we are pulling toward the goal position, this forumla
		// will have the opposite effect.
		pos_old = get_entity_property(ent, "position_x");

		if (pos_final > pos_old)
		{
			pos_final -= adjust;
		}
		else
		{
			pos_final += adjust;
		}
	}

	set_entity_property(ent, "position_x", pos_final);
}

void dc_elmers_adjust_distance_to_y()
{
	void ent;

	float pos_old;
	float pos_final;
	int adjust;

	ent = dc_elmers_get_member_entity();

	// Get the amount we want to adjust.
	adjust = dc_elmers_get_member_position_adjust_quantity_y();

	// Get our final "goal" posiiton. We'll decide how (or if)
	// to adjust it below.
	pos_final = dc_elmers_find_position_with_offset_y();

	// If the distance to our target location is less than
	// adjustment, then there's no reason to adjust the final
	// goal position.
	if (dc_math_compare_unisgned_float(adjust, dc_math_compare_unisgned_float(pos_old, pos_final)))
	{
		// Assuming we are pushing away from goal (positive adjustment) 
		// if the goal position is to the right, subtract adjustment 
		// from goal. This will get us a leftward position to apply.
		// Otherwise we add to go rightward.
		//
		// If we are pulling toward the goal position, this forumla
		// will have the opposite effect.
		pos_old = get_entity_property(ent, "position_y");

		if (pos_final > pos_old)
		{
			pos_final -= adjust;
		}
		else
		{
			pos_final += adjust;
		}
	}

	set_entity_property(ent, "position_y", pos_final);
}

void dc_elmers_adjust_distance_to_z()
{
	void ent;

	float pos_old;
	float pos_final;
	int adjust;

	ent = dc_elmers_get_member_entity();

	// Get the amount we want to adjust.
	adjust = dc_elmers_get_member_position_adjust_quantity_z();

	// Get our final "goal" posiiton. We'll decide how (or if)
	// to adjust it below.
	pos_final = dc_elmers_find_position_with_offset_z();

	// If the distance to our target location is less than
	// adjustment, then there's no reason to adjust the final
	// goal position.
	if (dc_math_compare_unisgned_float(adjust, dc_math_compare_unisgned_float(pos_old, pos_final)))
	{
		// Assuming we are pushing away from goal (positive adjustment) 
		// if the goal position is to the right, subtract adjustment 
		// from goal. This will get us a leftward position to apply.
		// Otherwise we add to go rightward.
		//
		// If we are pulling toward the goal position, this forumla
		// will have the opposite effect.
		pos_old = get_entity_property(ent, "position_z");

		if (pos_final > pos_old)
		{
			pos_final -= adjust;
		}
		else
		{
			pos_final += adjust;
		}
	}

	set_entity_property(ent, "position_z", pos_final);
}