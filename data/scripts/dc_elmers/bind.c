#include "data/scripts/dc_elmers/config.h"


#import "data/scripts/dc_elmers/direction.c"
#import "data/scripts/dc_elmers/entity.c"
#import "data/scripts/dc_elmers/offset.c"
#import "data/scripts/dc_elmers/palette.c"
#import "data/scripts/dc_elmers/position.c"
#import "data/scripts/dc_elmers/position_config.c"

void dc_elmers_set_bind_animation_id(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_id", value);

	return bind;
}

void dc_elmers_set_bind_frame(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_frame", value);

	return bind;
}

void dc_elmers_set_animation_match(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "animation_match", value);

	return bind;
}

int dc_elmers_get_member_bind_direction()
{
	char id;
	int result;

	// Get id.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_BIND_DIRECTION;

	result = getlocalvar(id);
	
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_BIND_DIRECTION;
	}
	
	return result;
}

//

int dc_elmers_set_member_bind_direction(int value)
{
	char id;

	// Get ID.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_BIND_DIRECTION;

	// If value is default, make sure the variable
	// is deleted.
	if (value == DC_ELMERS_DEFAULT_BIND_DIRECTION)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Set new value to member and apply to bind property.
void dc_elmers_alter_bind_direction(int value)
{
	dc_elmers_set_member_bind_direction(value);
	dc_elmers_apply_bind_direction();
}

// Apply member value to bind property.
void dc_elmers_apply_bind_direction()
{
	void ent;
	void bind;
	int value;

	// Get entity and value.
	ent = dc_elmers_get_member_entity();
	value = dc_elmers_get_member_bind_direction();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "direction", value);

	return bind;
}

//

void dc_elmers_set_bind_sorting(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "sort_id", value);

	return bind;
}

void dc_elmers_set_bind_target(void value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", value);

	return bind;
}

/*
* Offsets
*/

int dc_elmers_get_bind_offset_x()
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	return get_bind_property(bind, "offset_x");
}

void dc_elmers_set_bind_offset_x(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "offset_x", value);
}

int dc_elmers_get_bind_offset_y()
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	return get_bind_property(bind, "offset_y");
}

void dc_elmers_set_bind_offset_y(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "offset_x", value);
}

int dc_elmers_get_bind_offset_z()
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	return get_bind_property(bind, "offset_z");
}

void dc_elmers_set_bind_offset_z(int value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "offset_x", value);
}

int dc_elmers_get_bind_property(char prop_name)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");

	return get_bind_property(bind, prop_name);
}

// Caskey, Damon V.
// 2019-~03
//
// Set a bind property by name to ent member.
// used to adjust bind property that does not
// have a specific function defined for it in 
// this library.
void dc_elmers_set_bind_property(void prop_name, int the_value)
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	// Get bind pointer.
	bind = get_entity_property(ent, "bind");	

	set_bind_property(bind, prop_name, the_value);

	return bind;
}



// Caskey, Damon V.
// 2019-03-13
//
// Applies calculated offsets to bind.
void dc_elmers_quick_offset_to_bind()
{
	void target;
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "offset_x", dc_elmers_find_scaled_offset_x(target, dc_elmers_get_member_offset_x()));
	set_bind_property(bind, "offset_y", dc_elmers_find_scaled_offset_y(target, dc_elmers_get_member_offset_y()));
	set_bind_property(bind, "offset_z", dc_elmers_get_member_offset_z());

	return bind;
}

// Caskey, Damon V.
//
// Apply a bind with member properties.
void dc_elmers_quick_bind()
{
	void ent;
	void target;
	void bind;

	ent = dc_elmers_get_member_entity();
	target = dc_elmers_get_member_target();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", target);

	set_bind_property(bind, "mode_x", dc_elmers_get_member_anchor_x());
	set_bind_property(bind, "mode_y", dc_elmers_get_member_anchor_y());
	set_bind_property(bind, "mode_z", dc_elmers_get_member_anchor_z());

	set_bind_property(bind, "direction", dc_elmers_get_member_bind_direction());
	
	dc_elmers_quick_offset_to_bind();	

	dc_elmers_apply_palette_match();

	return bind;
}

// Caskey, Damon V.
// 2019-05-09
//
// Release a bind.
void dc_elmers_quick_release()
{
	void ent;
	void bind;

	ent = dc_elmers_get_member_entity();

	bind = get_entity_property(ent, "bind");

	set_bind_property(bind, "target", NULL());

	dc_elmers_apply_position();

	return bind;
}

// Caskey, Damon V.
// 2019-04-25
//
// Find the first entity bound to ent and 
// return its pointer. Only call this when 
// you know there is a single entity bound to
// the entity you are checking. If there are 
// any others this function will not find them.
void dc_elmers_find_first_bound(void ent)
{
	int ent_count;
	int i;
	void ent_cursor;
	void bind;

	// Get entity count.
	ent_count = openborvariant("count_entities");

	// Loop over each entity index.
	for (i = 0; i < ent_count; i++)
	{
		// Get entity pointer.
		ent_cursor = getentity(i);

		// Now get the cursor entity's bind
		// property, and check the target against
		// our ent pointer. If they match, we've
		// found an entity bound to ent. Return it.
		bind = get_entity_property(ent_cursor, "bind");

		if (ent == get_bind_property(bind, "target"))
		{
			return ent_cursor;
		}		
	}

	// Didn't find any entity bound to 
	// our entity, so return a NULL pointer.
	return NULL();
}