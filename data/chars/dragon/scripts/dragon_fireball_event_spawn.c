#include "data/scripts/dc_fidelity/main.c"

void main()
{
	void acting_entity = getlocalvar("self");

	changeentityproperty(acting_entity, "subject_to_basemap", 0);
	changeentityproperty(acting_entity, "subject_to_platform", 0);
	changeentityproperty(acting_entity, "subject_to_wall", 0);

	set_entity_property(acting_entity, "autokill", 1);

	dc_fidelity_quick_play(DC_FIDELITY_TYPE_SOUND_SPAWN);
}
