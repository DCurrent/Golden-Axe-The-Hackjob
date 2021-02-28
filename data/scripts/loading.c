#include "data/scripts/dc_fidelity/main.c"

void oncreate()
{
	//log("\n");
	//log("loaded.c");
	//log("\t");
	//log("- oncreate().");
	//log("\n");

	// Global sounds.
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT, "data/sounds/custom/golden_axe_whiff_light_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT, "data/sounds/custom/rb-whiff-light-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM, "data/sounds/custom/rb-whiff-med-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE, "data/sounds/custom/samurai_shodown_whiff_light_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE, "data/sounds/custom/samurai_shodown_whiff_light_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY, "data/sounds/custom/rb-whiff-heavy-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY, "data/sounds/custom/rb-whiff-heavy-1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY_BLADE, "data/sounds/custom/samurai_shodown_whiff_heavy_0.wav");	

	// Global voices.
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/avp_soldier_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/avp_soldier_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/fatal_fury_rebout_ko.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/fighters_history_2_ray_ko.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/golden_axe_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/golden_axe_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/mortal_kombat_pain_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/ninja_spirit_ko.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/punisher_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/punisher_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/punisher_ko_2.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/sor2_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/sor2_ko_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/sor3_ko_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_VOICE_KO, "data/sounds/custom/unknown_ko.wav");

	// Jump and hop liftoff.
	dc_fidelity_setup("hop_liftoff", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_jump.wav");
	dc_fidelity_setup("jump_liftoff", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_jump.wav");

	// Jump land.
	dc_fidelity_setup("jump_land", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_land.wav");

	// Fall Land.
	dc_fidelity_setup("fall_land", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/unknown_fall_land.wav");

	// Heavy slam Land.
	dc_fidelity_setup("flash_slam_heavy", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/unknown_slam.wav");

	// Block flash.
	dc_fidelity_setup("block", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/cvs_block.wav");

	//  Hit flash
	dc_fidelity_setup("Flash", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/double_dragon_2_hit_0.wav");
	dc_fidelity_setup("flash_fatal_fury", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_hit.wav");
	dc_fidelity_setup("flash_indirect", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/sor1_hit_0.wav");
	dc_fidelity_setup("flash_cvs_cut_heavy", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/mvc_slash_0.wav");
	dc_fidelity_setup("flash_cvs_cut_blunt", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_hit.wav");


	/* Longmoan */
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/longmoan/sounds/atk_shout_0.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/longmoan/sounds/atk_shout_1.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/longmoan/sounds/atk_shout_2.wav");

	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/longmoan/sounds/atk_shout_1.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/longmoan/sounds/atk_shout_2.wav");

	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/longmoan/sounds/atk_shout_1.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/longmoan/sounds/atk_shout_2.wav");
	
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/longmoan/sounds/battle_taunt_0.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/longmoan/sounds/battle_taunt_1.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/longmoan/sounds/battle_taunt_2.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/longmoan/sounds/battle_taunt_3.wav");
	
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/longmoan/sounds/hurt_0.wav"); 
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/longmoan/sounds/hurt_1.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/longmoan/sounds/hurt_2.wav");

	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/longmoan/sounds/hurt_0.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/longmoan/sounds/hurt_1.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/longmoan/sounds/hurt_2.wav");

	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_NEAR_KO, "data/chars/longmoan/sounds/low_hp_0.wav");
	dc_fidelity_setup("longmoan", DC_FIDELITY_TYPE_VOICE_NEAR_KO, "data/chars/longmoan/sounds/low_hp_1.wav");

	
}

void ondestroy()
{
	//log("\n");
	////log("loaded.c");
	//log("\t");
	//log("- ondestroy().");
	//log("\n");
}

void main()
{
	
}



