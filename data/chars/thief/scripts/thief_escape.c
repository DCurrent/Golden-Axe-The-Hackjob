/*
* Subject "escapes" by spawning a visualy identical model
* with escaping behavior and moving new model to its
* current position, then killing self.
*/
void escape(char model_name)
{
	void acting_entity = getlocalvar("self");
	void escape_entity = NULL();
	int position_base = 0;
	float position_x = 0.0;
	float position_y = 0.0;
	float position_z = 0.0;

	/* Spawn escaping theif. */

	clearspawnentry();
	setspawnentry("name", model_name);
	escape_entity = spawn();

	/* Move new entity to current position. */
	position_base = get_entity_property(acting_entity, "position_base");
	position_x = get_entity_property(acting_entity, "position_x");
	position_y = get_entity_property(acting_entity, "position_y");
	position_z = get_entity_property(acting_entity, "position_z");

	set_entity_property(escape_entity, "position_base", position_base);
	set_entity_property(escape_entity, "position_x", position_x);
	set_entity_property(escape_entity, "position_y", position_y);
	set_entity_property(escape_entity, "position_z", position_z);

	set_entity_property(escape_entity, "colorset_table", get_entity_property(acting_entity, "colorset_table"));

	if (getlocalvar("lifespan") > 3)
	{
		executeanimation(escape_entity, openborconstant("ANI_RESPAWN"), 0);
	}

	/* Kill self. */
	killentity(acting_entity);
}