#include "data/scripts/dc_fidelity/main.c"

/*
* 
* Initialize sound references used by dc_fidelity
* sound player library. Each sound reference
* consists of a Category, Type, and Path.
*
* Category - Generally the item sound belongs to.
* Most commonly this is a model name, which is
* later furnished automatically when a sound
* playback is requested. It is possible to define
* and use custom categories as well. Finally,
* there is a global category that is used when a
* sound request is made but the supplied category
* does not have a sound reference of the requested
* type (see below) defined for it here.
*
* Type - Type of sound to play. Examples would be
* attack shouts, hello greetings, KO screams and
* so on. Each category is allowed unlimited definitions
* of any sound type. When playback is requested for
* the sound type, the sound player randomly selects
* one reference to play. it is also possible to request
* playback of a specific reference by number.
* Reference numbers for each type are 0 indexed in
* order of definition. The sound player has a wide
* selection of category constants ready for use, or
* you may write in your own.
*
* Path - Path to the sound file. You may use the same
* sound path for multiple references with no memory
* penalty - the actual sound file is only loaded once.
*/
void load_sounds()
{
	/***** Global *****/

	/* Global Sounds. */
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_LIGHT, "data/sounds/custom/golden_axe_whiff_light_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM, "data/sounds/custom/rb-whiff-med-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE, "data/sounds/custom/samurai_shodown_whiff_light_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_MEDIUM_BLADE, "data/sounds/custom/samurai_shodown_whiff_light_1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY, "data/sounds/custom/rb-whiff-heavy-0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY, "data/sounds/custom/rb-whiff-heavy-1.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, DC_FIDELITY_TYPE_SOUND_ATTACK_HEAVY_BLADE, "data/sounds/custom/samurai_shodown_whiff_heavy_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, "golden_axe_special", "data/sounds/custom/golden_axe_special.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, "golden_axe_heavy", "data/sounds/custom/golden_axe_whiff_heavy.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, "golden_axe_item_get", "data/sounds/custom/golden_axe_item_get_0.wav");
	dc_fidelity_setup(DC_FIDELITY_CATEGORY_GLOBAL, "golden_axe_magic_pot", "data/sounds/custom/golden_axe_magic_pot_0.wav");

	/* Global voices. */
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

	/* Jump and hop liftoff. */
	dc_fidelity_setup("hop_liftoff", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/shinobi_jump.wav");
	dc_fidelity_setup("jump_liftoff", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/shinobi_jump.wav");

	/* Jump land. */
	dc_fidelity_setup("jump_land", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_land.wav");

	/* Fall Land. */
	dc_fidelity_setup("fall_land", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_fall_land_light.wav");

	/* Slam, heavy. */
	dc_fidelity_setup("slam_heavy", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/unknown_slam.wav");

	/* Slam, light. */
	dc_fidelity_setup("slam_light", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/world_heroes_slam_0.wav");

	/* Block flash. */
	dc_fidelity_setup("flash_block", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/metal_deflect_0.wav");

	/*  Hit flash */
	dc_fidelity_setup("flash_bite", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_2_arcade_eat_0.wav");
	dc_fidelity_setup("flash_blunt_cut", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/shinobi_box.wav");
	dc_fidelity_setup("flash_cut_vertical", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_hit_cut_0.wav");
	dc_fidelity_setup("flash_cut_vertical_knockdown", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_hit_knockdown_0.wav");
	dc_fidelity_setup("flash_fatal_fury", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/fatal_fury_1_hit.wav");
	dc_fidelity_setup("flash_hit_head_knock", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_knock_head_0.wav");
	dc_fidelity_setup("flash_hit_knockdown", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_hit_knockdown_0.wav");
	dc_fidelity_setup("flash_impact_cut", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_hit_ram_0.wav");
	dc_fidelity_setup("flash_indirect", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/sor1_hit_0.wav");
	dc_fidelity_setup("flash_stab_knockdown", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_hit_knockdown_0.wav");

	
	/* Ax Battler */
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/ax/sounds/voice_attack_0.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/ax/sounds/voice_attack_1.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/ax/sounds/voice_attack_2.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/ax/sounds/voice_attack_3.wav");

	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/ax/sounds/voice_attack_1.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/ax/sounds/voice_attack_2.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/ax/sounds/voice_attack_3.wav");

	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/ax/sounds/voice_attack_1.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/ax/sounds/voice_attack_2.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/ax/sounds/voice_attack_3.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/ax/sounds/voice_ga2_stern_special_0.wav");

	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/ax/sounds/voice_battle_cry_destroy.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/ax/sounds/voice_battle_cry_die.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/ax/sounds/voice_battle_cry_fall.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/ax/sounds/voice_battle_cry_steel.wav");

	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/ax/sounds/voice_hurt_0.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/ax/sounds/voice_hurt_1.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/ax/sounds/voice_hurt_2.wav");

	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/ax/sounds/voice_hurt_0.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/ax/sounds/voice_hurt_1.wav");
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/ax/sounds/voice_hurt_2.wav");

	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_KO, "data/chars/ax/sounds/voice_ko_0.wav");
	
	dc_fidelity_setup("ax", DC_FIDELITY_TYPE_VOICE_NEAR_KO, "data/chars/ax/sounds/voice_low_hp_0.wav");

	/* bor_steam*/
	dc_fidelity_setup("bor_steam", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/sounds/custom/marvel_vs_capcom_2_fire_hit_0.wav");

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

	/* Heninger */
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/Heninger/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/Heninger/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/Heninger/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/Heninger/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/Heninger/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/Heninger/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/Heninger/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/Heninger/sounds/battle_taunt_fear_comes.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/Heninger/sounds/battle_taunt_haha.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/Heninger/sounds/battle_taunt_see_dead.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/Heninger/sounds/battle_taunt_survive_0.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, "data/chars/Heninger/sounds/battle_taunt_survive_1.wav");

	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/Heninger/sounds/hurt_0.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/Heninger/sounds/hurt_1.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/Heninger/sounds/hurt_2.wav");

	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/Heninger/sounds/hurt_0.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/Heninger/sounds/hurt_1.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/Heninger/sounds/hurt_2.wav");

	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_NEAR_KO, "data/chars/Heninger/sounds/low_hp_help_me.wav");
	dc_fidelity_setup("Heninger", DC_FIDELITY_TYPE_VOICE_NEAR_KO, "data/chars/Heninger/sounds/low_hp_need_aid.wav");

	/* Chickenlegs */
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/chicken/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/chicken/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/chicken/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Chickenlegs", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Chickenlegs", "piledriver", "data/chars/chicken/sounds/loud_cry_0.wav");

	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/chicken/sounds/atk_shout_0.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/chicken/sounds/atk_shout_0.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/chicken/sounds/atk_shout_0.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/chicken/sounds/atk_shout_1.wav");
	dc_fidelity_setup("chicken_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/chicken/sounds/atk_shout_2.wav");

	dc_fidelity_setup("chicken_escape", "piledriver", "data/chars/chicken/sounds/loud_cry_0.wav");

	/* Red_Dragon */
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/dragon/sounds/loud_cry_0.wav");

	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Red_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_2.wav");
	

	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/dragon/sounds/loud_cry_0.wav");

	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("red_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_2.wav");

	/* Blue_Dragon */
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/dragon/sounds/loud_cry_0.wav");

	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("Blue_Dragon", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_SPAWN_NEW, "data/chars/dragon/sounds/loud_cry_0.wav");

	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_LIGHT, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_MEDIUM, "data/chars/dragon/sounds/atk_shout_2.wav");

	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_0.wav");
	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_1.wav");
	dc_fidelity_setup("blue_dragon_escape", DC_FIDELITY_TYPE_VOICE_ATTACK_SHOUT_HEAVY, "data/chars/dragon/sounds/atk_shout_2.wav");

	/* Ridable dragon fire attacks. */
	dc_fidelity_setup("dragon_flame", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/chars/dragon/sounds/fire_stream_0.wav");

	dc_fidelity_setup("dragon_fireball", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/golden_axe_red_dragon_fireball_0.wav");
	dc_fidelity_setup("dragon_fireball", "explode", "data/sounds/custom/golden_axe_red_dragon_fireball_impact_0.wav");

	dc_fidelity_setup("dragon_fireball_ex", DC_FIDELITY_TYPE_SOUND_SPAWN, "data/sounds/custom/mvc3_ryu_se_hadou_charge_0.wav");
	dc_fidelity_setup("dragon_fireball_ex", "explode", "data/sounds/custom/mvc3_ryu_se_hadou_exp_0.wav");

	/* Thief */
	dc_fidelity_setup("Thief", DC_FIDELITY_TYPE_VOICE_LAUGH, "data/chars/thief/sounds/laugh_0.wav");

	dc_fidelity_setup("Thief", DC_FIDELITY_TYPE_VOICE_PAIN, "data/chars/thief/sounds/pain_0.wav");

	dc_fidelity_setup("Thief", DC_FIDELITY_TYPE_VOICE_PAIN_FALL, "data/chars/thief/sounds/pain_0.wav");

	dc_fidelity_setup("Thief", DC_FIDELITY_TYPE_VOICE_KO, "data/chars/thief/sounds/pain_0.wav");

	dc_fidelity_setup("escthief", DC_FIDELITY_TYPE_VOICE_KO, "data/chars/thief/sounds/pain_0.wav");
}

void oncreate()
{
	//log("\n");
	//log("loaded.c");
	//log("\t");
	//log("- oncreate().");
	//log("\n");

	load_sounds();

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




