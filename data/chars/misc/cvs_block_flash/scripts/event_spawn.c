#include "data/scripts/dc_kanga/main.c"
#include "data/scripts/dc_fidelity/main.c"

void main() {

	void ent;
	int	rotate;

	ent = getlocalvar("self");

	changedrawmethod(ent, "scalex", 64);
	changedrawmethod(ent, "scaley", 64);
	changedrawmethod(ent, "alpha", 1);
	changedrawmethod(ent, "enabled", 1);

	// Apply draw settings.
	//dc_kanga_z_position_autoscale(ent);

	// Play sound.
	dc_fidelity_quick_play(DC_FIDELITY_TYPE_SOUND_SPAWN);
}
