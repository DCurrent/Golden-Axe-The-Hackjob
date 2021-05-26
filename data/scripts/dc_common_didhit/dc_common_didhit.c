#include "data/scripts/dc_common_didhit/config.h"

/*
* Caskey, Damon V
* 2018
*
* Common didhit event function used by
* most models.
*/
void dc_common_didhit()
{

	void acting_entity = getlocalvar("self");
	int model_type = getentityproperty(acting_entity, "type");
	int animation_id = get_entity_property(acting_entity, "animation_id");
	int blocked = getlocalvar("blocked");

	if (model_type & openborconstant("TYPE_PLAYER"))
	{		
	}
	else
	{
		if (!blocked)
		{
			dc_cancel_set_member_allow_idle_animation(animation_id);
		}
	}

	dc_battle_talk();
	
}

/*
* Caskey, Damon V.
* 2021-05-25 (Broken off from didhit ~2010).
* 
* Temporary function to run trash talk when
* knocking an entity down.
*/

void dc_battle_talk()
{
	int blocked = 0;
	void ent = NULL();
	void target = NULL();

	int blast_state = 0;
	int drop_previous = 0;
	int drop = 0;
	int animation_id = 0;
	int knockdown_count = 0;
	int spawn_type = 0;

	blocked = getlocalvar("blocked");

	if (blocked)
	{
	}
	else
	{
		ent = getlocalvar("self");
		blast_state = get_entity_property(ent, "blast_state");

		animation_id = get_entity_property(ent, "animation_id");

		target = getlocalvar("damagetaker");
		drop_previous = get_entity_property(target, "drop");

		/*
		* Trash talk. Entities taunt, brag, or otherwise comment
		* after knocking a hostile entity down.
		*
		* Occurs under following conditions:
		*
		* 1. Target isn't falling already. We don't want to overdo by talking on juggle hits.
		* 2. Projectile flag isn't active (i.e. the hit isn't because we weren't thrown into someone).
		* 3. We're not in a grappled animation.
		*/
		if (!blast_state && animation_id != openborconstant("ANI_FOLLOW10"))
		{
			/*
			* Will we knock the target down? Todo: Account for target's knockdown defense.
			*/

			drop = getlocalvar("drop");
			knockdown_count = get_entity_property(target, "knockdown_count");

			if (drop > knockdown_count)
			{
				/*
				* AI characters always trash talk. Players have
				* a 50% chance. In both cases, we set up a timed
				* sound play so the trash talk is more organic
				* and not mixed in with hit sounds.
				*/

				spawn_type = get_entity_property(ent, "spawn_type");

				if (spawn_type == openborconstant("SPAWN_TYPE_PLAYER_MAIN"))
				{
					dc_fidelity_set_member_sound_chance(0.5);
					dc_fidelity_timed_play(DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, 175);
					dc_fidelity_set_member_sound_chance(NULL());
				}
				else
				{
					dc_fidelity_timed_play(DC_FIDELITY_TYPE_VOICE_BATTLE_TAUNT, 175);
				}
			}
		}
	}
}