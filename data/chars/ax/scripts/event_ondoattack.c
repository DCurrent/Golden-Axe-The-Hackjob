#include "data/scripts/dc_disney/main.c"

void main()
{
	/*
	Damon V. Caskey
	2011_07_26 - Derived from previous parry code written for Fatal Fury Chronicles 
	authored sometime in 2010.

	If opponent's incoming attack is a Run Attack or Jump Attack and player blocks 
	with precise timing, cancel the engine's hit handling and perform a counter move.
	If the entity is AI controlled, do the same thing except checking for idle status 
	instead of block frame.
	*/
    
    void	acting_entity			= getlocalvar("self");															//Calling entity.        
	int		attack_id_incoming		= getlocalvar("attackid");														//Attack ID.
	void	other_entity			= getlocalvar("other");									
	int		other_animation_id		= get_entity_property(other_entity, "animation_id");
	int		acting_animation_id		= get_entity_property(acting_entity, "animation_id");	
	int		acting_animation_frame	= get_entity_property(acting_entity, "animation_frame");
	int		model_type				= getentityproperty(acting_entity, "type");
	int		acting_direction		= 0;
	int		other_direction			= get_entity_property(other_entity, "position_direction");
	int		acting_idle_state		= get_entity_property(acting_entity, "idle_state");
	int		acting_pos_base			= get_entity_property(acting_entity, "position_base");
	float	acting_pos_y			= get_entity_property(acting_entity, "position_y");
	float	acting_pos_altitude		= 0;
	int		elapsed_time			= openborvariant("elapsed_time");
	int		pause_time				= 0;
	
	/* 
	* Run series of verifications. If any one fails, we exit 
	* the function imediately.
	*/

	/*
	* Do attack runs when giving and taking - here we only want
	* to act if we're taking the hit.
	*/

	if (getlocalvar("which") != openborconstant("EXCHANGE_RECIPIANT"))
	{
		return;
	}

	if (getentityproperty(acting_entity, "hitbyid") == attack_id_incoming)							//Unique attack?
	{
		return;
	}

	/*
	* Opponent is in any run or jump attack animation?
	*/

	if (other_animation_id != openborconstant("ANI_RUNATTACK")
		&& other_animation_id != openborconstant("ANI_JUMPATTACK")
		&& other_animation_id != openborconstant("ANI_JUMPATTACK2")
		&& other_animation_id != openborconstant("ANI_JUMPATTACK3")
		&& other_animation_id != openborconstant("ANI_RUNJUMPATTACK"))
	{
		return;
	}
		

	/* In first frames of block? */

	if (acting_animation_id != openborconstant("ANI_BLOCK") || acting_animation_frame > 1)
	{
		return;
	}

	/* Enemy or NPC type? */

	if (model_type != openborconstant("TYPE_ENEMY") && model_type != openborconstant("TYPE_NPC"))
	{
		return;
	}

	/* Idle and less than 5 pixels above base ground. */

	acting_pos_altitude = acting_pos_y - acting_pos_base;

	if(!acting_idle_state || acting_pos_altitude >= 5)													
	{
		return;
	}

	/* Make sure acting entity is facing opponent. */

	if(other_direction == openborconstant("DIRECTION_LEFT"))
	{
		acting_direction = openborconstant("DIRECTION_RIGHT");
	}
	else
	{
		acting_direction = openborconstant("DIRECTION_LEFT");
	}

	set_entity_property(acting_entity, "position_direction", acting_direction);

	/* Cancel engine's native hit handling routines.*/
	changeopenborvariant("lasthitc", 0);
	
	/* Freeze attacker in place briefly. */

	pause_time = elapsed_time + 300;

	set_entity_property(other_entity, "animation_time", pause_time);
	set_entity_property(other_entity, "move_time", pause_time);
	set_entity_property(other_entity, "think_time", pause_time);
	set_entity_property(other_entity, "toss_time", pause_time);

	/* Start animation to counter. */

	dc_disney_macro_try_grab_alternate_vs_opponent(openborconstant("ANI_FOLLOW14"), openborconstant("ANI_ATTACK2"));
	
	/* Mark this attack ID as used. */
	set_entity_property(acting_entity, "attack_id_incoming", attack_id_incoming);
}


