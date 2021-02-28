#import "data/scripts/com/dc_ai_terrain_turn_around.c"    // Get around walls.
#import "data/scripts/com/dc_ai_escape.c"    // Find way out of screen.
#import "data/scripts/com/ai0005.h"    // Timed animation.

#import "data/chars/thief/scripts/thief_escape.c"

#include "data/scripts/dc_fidelity/main.c"  // Sound player.



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
