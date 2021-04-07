#import "data/scripts/com/dc_ai_terrain_turn_around.c"    // Get around walls.
#import "data/scripts/com/dc_ai_escape.c"    // Find way out of screen.

#import "data/chars/thief/scripts/thief_escape.c"

#include "data/scripts/dc_fidelity/main.c"
#include "data/scripts/dc_gauntlet/main.c"
#include "data/scripts/dc_eggball/main.c"
#include "data/scripts/dc_elmers/main.c"

/* Snatch magic pots off the screen. Gimmme! */
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

