#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/common/takedamage_main.c"

void main()
{
	void ent = getlocalvar("self");
	void other = getlocalvar("other");
	int take_damage_result;

	// Compute result of take damage (knockdown, KO, etc.) so we
	// don't need to do it over and over again for different
	// action logic.
	take_damage_result = common_take_damage_result(ent);

	// Play appropriate sound effect.
	common_take_damage_sound(take_damage_result);
	common_spawn_damage_effect(take_damage_result);

	// Release any grappled entities.
	dc_elmers_set_member_target(ent);
	dc_elmers_disrupt_grapple();
}