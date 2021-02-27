#include "data/scripts/dc_elmers/config.h"

#import "data/scripts/dc_elmers/entity.c"


// Get
int dc_elmers_get_member_palette_match()
{
	char id;
	void result;

	// Get id from key and instance.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_PALETTE_MATCH;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_ELMERS_DEFAULT_PALETTE_MATCH;
	}

	return result;
}

// Set
int dc_elmers_set_palette_match(void value)
{
	char id;

	// Get id from key and instance.
	id = dc_elmers_get_instance() + DC_ELMERS_MEMBER_PALETTE_MATCH;

	if (value == DC_ELMERS_DEFAULT_PALETTE_MATCH)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Caskey, Damon V.
// 2019-03-27
//
// Apply palette according to settings.
void dc_elmers_apply_palette_match()
{
	int match;

	void target;
	void entity;

	
	target = dc_elmers_get_member_target();
	entity = dc_elmers_get_member_entity();

	if (!target || !entity)
	{
		return;
	}

	match = dc_elmers_get_member_palette_match();

	switch (match)
	{
		default:
		case DC_ELMERS_PALETTE_MATCH_NONE:
	
			return;
			break;
	
		case DC_ELMERS_PALETTE_MATCH_INDEX:

			// Nothing right now.
			break;

		case DC_ELMERS_PALETTE_MATCH_TABLE:

			// Set our color table pointer to the target's.

			void drawmethod_ent;
			void table;

			// Get color table in use by target.
			table = get_entity_property(target, "colorset_table");
			
			// Get entity drawmethod.
			drawmethod_ent		= get_entity_property(entity, "drawmethod");
			
			// Use target's color table as entity's drawmethod table, and
			// enable entity's drawmethod if it isn't already.
			set_drawmethod_property(drawmethod_ent, "colorset_table", table);
			set_drawmethod_property(drawmethod_ent, "enable", 1);

			break;
	}
}