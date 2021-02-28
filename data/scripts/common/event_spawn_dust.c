#include "data/scripts/dc_kanga/main.c"
#include "data/scripts/dc_fidelity/main.c"

void main() {

	void ent = NULL();
	float pos_z = 0.0;
	int aggression = 0;	
	int spawn_type = 0;
	int mp = 0;
	void drawmethod = NULL();

	ent = getlocalvar("self");
	pos_z = get_entity_property(ent, "position_z");

	/* 
	* Entity dies when animation is 
	* complete. Should already be set,
	* but let's make sure here.
	*/ 
	set_entity_property(ent, "autokill", openborconstant("AUTOKILL_ANIMATION_COMPLETE"));
	
	/*
	* We'll use spawn type to determine several behaviors.
	*/
	spawn_type = get_entity_property(ent, "spawn_type");

	/*
	* Jump and land dusts use MP as a scale control. If the MP 
	* is not set at all, default to half size.
	*/

	if (spawn_type == openborconstant("SPAWN_TYPE_DUST_LAND") || spawn_type == openborconstant("SPAWN_TYPE_DUST_JUMP") || spawn_type == openborconstant("SPAWN_TYPE_DUST_FALL"))
	{
		mp = getentityproperty(ent, "maxmp");

		if (mp <= 0)
		{
			mp = 128;
		}

		drawmethod = get_entity_property(ent, "drawmethod");

		set_drawmethod_property(drawmethod, "enable", 1);
		set_drawmethod_property(drawmethod, "alpha", openborconstant("BLEND_MODE_ALPHA"));		
		set_drawmethod_property(drawmethod, "scale_x", mp);
		set_drawmethod_property(drawmethod, "scale_y", mp);

		//dc_kanga_z_position_autoscale(ent);
	}

	/* 
	* By default OpenBOR spawns dust effects in front of
	* parent, but we want them behind. We can set 
	* throwdamage to 1 if we want to put dust
	* back in front of parent.
	*/

	if (getentityproperty(ent, "throwdamage") != 1)
	{
		set_entity_property(ent, "position_z", pos_z - 1);
	}

	/* Play the spawm sound. */
	dc_fidelity_quick_play(DC_FIDELITY_TYPE_SOUND_SPAWN);
}