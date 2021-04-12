#include "data/scripts/dc_common_takedamage/config.h"

/*
* Caskey, Damon V
* 2021-04-11
*
* Common takedamage event function used by
* most models.
*/
void dc_common_takedamage()
{
	void acting_entity = getlocalvar("self");
	void other = getlocalvar("other");
	int take_damage_result;
	int attack_force = getlocalvar("damage");
	int attack_type = getlocalvar("attacktype");
	int attack_drop = getlocalvar("drop");
	int damage_final = 0;


	/*
	* Compute result of take damage (knockdown, KO, etc.) so we
	* don't need to do it over and over again for different
	* action logic.
	*/
	take_damage_result = common_take_damage_result(acting_entity);

	// Play appropriate sound effect.
	common_take_damage_sound(take_damage_result);
	common_spawn_damage_effect(take_damage_result);

	/* Release any grappled entities. */
	dc_elmers_set_member_target(acting_entity);
	dc_elmers_disrupt_grapple();

	/* Accrue (and decrement as needed) stun. */
	//damage_final = getcomputeddamage(acting_entity, other, attack_force, attack_drop, attack_type);

	/* 
	* Apply damage as stun if we are not 
	* knocked down. Otherwise reset.
	*/

	if (take_damage_result & DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_INITIAL)
	{
		dc_chain_reset_stun();
	}
	else
	{
		dc_chain_adjust_stun(attack_force);
	}
	
	settextobj(2, 10, 70, 1, 999999994, "Stun: " + dc_chain_get_member_stun_current() + "/" + dc_chain_get_member_stun_threshold());
}

/* Caskey, Damon V.
* 2019-10-02
*
* Compute results of damage taking (knocked down, burned, KO'd, etc) and
* combine into a single integer we can use bitwise logic on elsewhere. We
* might have several sets of behavior like sound effects, fatalities, weapon
* loss or whatever else divided accross mutiple functions, and each one
* will need to check the results of taking damage to work.
*
* By compressing the results into a single integer value here, those individual
* functions can use very simple bitwise logic to find the conditions they need
* and we avoid repeating the same checks over and over.
*/
void common_take_damage_result(void ent)
{
	int animation_id = 0;
	int animation_frame = 0;
	int landframe = 0;
	int drop = 0;
	int attack_type = 0;
	float hp = 0.0;
	float hp_max = 0.0;
	float hp_ratio = 0.0;
	int result = 0;

	/*
	* HP result. We get max and current HP, find the percentage
	* of current vs. high, and then set flag based on
	* a set of preset thresholds.
	*/

	hp = 0.0 + get_entity_property(ent, "hp");
	hp_max = 0.0 + getentityproperty(ent, "maxhealth");

	hp_ratio = hp / hp_max;

	if (hp_ratio <= 0)
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_KO;
	}
	else if (hp_ratio <= DC_DAMAGE_HP_LOW)
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_LOW;
	}
	else if (hp_ratio < DC_DAMAGE_HP_MAX)
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_HIGH;
	}
	else
	{
		result += DC_DAMAGE_TAKEDAMAGE_HP_MAX;
	}



	/*
	* Is this landing damage?
	*/

	animation_frame = get_entity_property(ent, "animation_frame");
	landframe = getentityproperty(ent, "landframe", animation_id);

	if (animation_frame == landframe)
	{
		result += DC_DAMAGE_TAKEDAMAGE_LANDING;
	}


	/*
	* Knockdown hit?
	*/

	drop = get_entity_property(ent, "drop");

	if (drop)
	{
		result += DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_INITIAL;
	}

	/*
	* Burn/shock hit?
	*/

	animation_id = get_entity_property(ent, "animation_id");
	attack_type = getlocalvar("attacktype");

	if (attack_type == openborconstant("ATK_BURN"))
	{
		/* Was already burning? */
		if (animation_id == openborconstant("ANI_BURN") || animation_id == openborconstant("ANI_BURNPAIN") || animation_id == DC_ELMERS_REACT_ANIMATION)
		{
			result += DC_DAMAGE_TAKEDAMAGE_BURN_ADDITION;
		}
		else
		{
			result += DC_DAMAGE_TAKEDAMAGE_BURN_INITIAL;
		}
	}
	else if (attack_type == openborconstant("ATK_SHOCK"))
	{
		/* Was already shocked? */
		if (animation_id == openborconstant("ANI_SHOCK") || animation_id == openborconstant("ANI_SHOCKPAIN") || animation_id == DC_ELMERS_REACT_ANIMATION)
		{
			result += DC_DAMAGE_TAKEDAMAGE_SHOCK_ADDITION;
		}
		else
		{
			result += DC_DAMAGE_TAKEDAMAGE_SHOCK_INITIAL;
		}
	}

	/* Return final result. */
	return result;
}

/*
* Spawn visual effect entity for certain attack types.
*/
void common_spawn_damage_effect(int damage_result)
{
	if (damage_result & DC_DAMAGE_TAKEDAMAGE_BURN_INITIAL)
	{

		//dc_elmers_quick_particle_free(dc_gauntlet_quick_spawn("body_burn"));
	}
	else if (damage_result & DC_DAMAGE_TAKEDAMAGE_SHOCK_INITIAL)
	{
	}
}

/*
* Caskey, Damon V.
* 2019-10-03 (moved out of takedamage main)
*
* Play sound effect based on results of taking damage.
*/
void common_take_damage_sound(int damage_result)
{
	/*
	* Lethal damage? Then we play KO sound.
	*/

	if (damage_result & DC_DAMAGE_TAKEDAMAGE_HP_KO)
	{
		dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_KO);

		return;
	}

	/* Damage from falling? Otherwise it's a normal hit. */
	if (damage_result & DC_DAMAGE_TAKEDAMAGE_LANDING)
	{
		/* Low HP or normal pain voice. */
		if (damage_result & DC_DAMAGE_TAKEDAMAGE_HP_LOW)
		{
			dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_NEAR_KO);
		}
		else
		{
			dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN);
		}
	}
	else
	{
		/* This is a knockdown hit? */
		if (damage_result & DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_INITIAL)
		{
			/*
			* We want to know if this is a burn or shock hit, in which
			* case we also want to know if we're not already in the burn
			* or shock animaiton. In those cases, we play the burn or shock
			* voice.
			*
			* Otherwise this is a standard knockdown, so we'll react accordingly.
			*/
			if (damage_result & DC_DAMAGE_TAKEDAMAGE_BURN_INITIAL)
			{
				dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_BURN);
			}
			else if (damage_result & DC_DAMAGE_TAKEDAMAGE_SHOCK_INITIAL)
			{
				dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_SHOCK);
			}
			else
			{
				/*
				* This is a normal knockdown, or a burn/shock but we're already
				* in the burn/shock animation (we don't want to do the dramatic
				* burn/shock scream over and over). Are our hitpoints low? Decide
				* if we'll play a normal pain grunt or the low health voice
				* accordingly.
				*/

				if (damage_result & DC_DAMAGE_TAKEDAMAGE_HP_LOW)
				{
					dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_NEAR_KO);
				}
				else
				{
					dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN_FALL);
				}
			}
		}
		else
		{
			/* Normal non-knockdown hit. */
			dc_fidelity_quick_play(DC_FIDELITY_TYPE_VOICE_PAIN);
		}
	}
}
