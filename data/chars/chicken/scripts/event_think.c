
void main()
{
	void acting_entity = getlocalvar("self");

	dc_ai_escape(acting_entity);
}

/*
* Caskey, Damon V.
* 2021-03-31
* 
* Reset walking destination out of screen. Kill
* self once destination reached.
*/
void dc_ai_escape(void acting_entity)
{
	

	float pos_x = get_entity_property(acting_entity, "position_x");
	int scroll_x = openborvariant("xpos");
	int screen_size_x = openborvariant("hresolution");

	int screen_size_half = screen_size_x / 2;

	/* To compare entity position. */
	int center_pont_x = screen_size_half + scroll_x;

	int target_pos = 0;

	if (pos_x <= center_pont_x)
	{
		target_pos = scroll_x - screen_size_half;
	}
	else
	{
		target_pos = scroll_x + screen_size_x + screen_size_half;
	}

	set_entity_property(acting_entity, "destination_x", target_pos);

	changeentityproperty(acting_entity, "offscreenkill", screen_size_half - 1);

	float velocity_x = get_entity_property(acting_entity, "velocity_x");

	if (velocity_x > 0)
	{
		set_entity_property(acting_entity, "position_direction", openborconstant("DIRECTION_RIGHT"));
	}
	else if (velocity_x < 0)
	{
		set_entity_property(acting_entity, "position_direction", openborconstant("DIRECTION_LEFT"));
	}
}