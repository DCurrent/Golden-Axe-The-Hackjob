#import "data/scripts/com/dc_ai_terrain_turn_around.c"    // Get around walls.
#import "data/scripts/com/dc_ai_escape.c"    // Find way out of screen.
#import "data/scripts/com/ai0005.h"    // Timed animation.

#include "data/scripts/dc_fidelity/main.c"  // Sound player.

/*
* Theif "escapes" by spawning a visualy identical model
* with escaping behavior and moving new model to its
* current position, then killing self.
*/
void escape()
{
	void acting_entity = getlocalvar("self");
	void escape_entity = NULL();
	int position_base = 0;
	float position_x = 0.0;
	float position_y = 0.0;
	float position_z = 0.0;
	
	/* Spawn escaping theif. */
	
	clearspawnentry();
	setspawnentry("name", "escthief");
	escape_entity = spawn();
		
	/* Move new entity to current position. */
	position_base = get_entity_property(acting_entity, "position_base");
	position_x = get_entity_property(acting_entity, "position_x");
	position_y = get_entity_property(acting_entity, "position_y");
	position_z = get_entity_property(acting_entity, "position_z");

	set_entity_property(acting_entity, "position_base", position_base);
	set_entity_property(escape_entity, "position_x", position_x);
	set_entity_property(escape_entity, "position_y", position_y);
	set_entity_property(escape_entity, "position_z", position_z);

	set_entity_property(escape_entity, "colorset_table", get_entity_property(acting_entity, "colorset_table"));

	if(getlocalvar("lifespan") > 3)
	{
		executeanimation(escape_entity, openborconstant("ANI_RESPAWN"), 0);
	}


	/* Set new entity velocity based on current facing.*/
	if(get_entity_property(acting_entity, "position_direction") == openborconstant("DIRECTION_RIGHT"))
	{
		set_entity_property(escape_entity, "position_direction", openborconstant("DIRECTION_RIGHT"));
		set_entity_property(escape_entity, "velocity_x", 3.0);
		set_entity_property(escape_entity, "velocity_y", 0.0);
		set_entity_property(escape_entity, "velocity_z", 0.0);
	}
	else
	{
		set_entity_property(escape_entity, "position_direction", openborconstant("DIRECTION_LEFT"));
		set_entity_property(escape_entity, "velocity_x", -3.0);
		set_entity_property(escape_entity, "velocity_y", 0.0);
		set_entity_property(escape_entity, "velocity_z", 0.0);
	}

	/* Kill self. */
	killentity(acting_entity);
}

/* Snatch magic pots off the screen. Gimme! */
void steal()
{
	void acting_entity = getlocalvar("self");
	
	if(getentityproperty(acting_entity, "name")=="BlueThief")
	{
		/*
		* If magic pots exist, remove them and add
		* to self health (this acts as a tracker).
		*/

		void magic_pot = getglobalvar("pot0");
		
		if(magic_pot != NULL())
		{
			killentity(magic_pot);
			changeentityproperty(acting_entity, "maxhealth", getentityproperty(acting_entity, "maxhealth")+1);
			changeentityproperty(acting_entity, "health", getentityproperty(acting_entity, "maxhealth"));
			setglobalvar("pot0", NULL());
		}
		
		magic_pot = getglobalvar("pot1");

		if(magic_pot != NULL())
		{
			killentity(magic_pot);
			changeentityproperty(acting_entity, "maxhealth", getentityproperty(acting_entity, "maxhealth")+1);
			changeentityproperty(acting_entity, "health", getentityproperty(acting_entity, "maxhealth"));
			setglobalvar("pot1", NULL());
		}
	}
}

void runcheck(){

	void acting_entity = getlocalvar("self");
	float position_z = get_entity_property(acting_entity, "position_z");

	if(position_z < 1000 && position_z > 0)
	{
		int lifespan = getlocalvar("lifespan");

		if(getglobalvar("runanimal"))
		{
			lifespan = 15;
			setglobalvar("runanimal", NULL());
		}
		if(lifespan==NULL())
		{
			lifespan = 0;
		}
		else if(lifespan > 15)
		{
			executeanimation(acting_entity, openborconstant("ANI_WALK"), 0);
		}
		else
		{
			lifespan++;
		}
		setlocalvar("lifespan", lifespan);
	}
}
