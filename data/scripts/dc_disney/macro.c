
#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/animation.c"

#import "data/scripts/dc_disney/conditions.c"
#import "data/scripts/dc_disney/condition_random.c"
#import "data/scripts/dc_disney/condition_type.c"

#import "data/scripts/dc_disney/animation.c"

/*
* Caskey, Damon V.
* 2021-05-05
* 
* Switch to animation if acting entity
* is AI controlled and random roll 
* suceeds.
*/
void dc_disney_macro_try_ai_random(int animation, int chance)
{
	/* 
	* Set global conditions to check for 
	* random, and pass along the random 
	* chance argument.
	*/
	dc_disney_set_member_condition_list_global(DC_DISNEY_CONDITION_RANDOM_CHANCE);
	dc_disney_set_member_global_random_chance(chance);

	/* 
	* We only want AI controlled entities. Set up 
	* evaluation for true, and to check for NPC
	* or ENEMY type.
	*/
	dc_disney_set_member_condition_list_acting(DC_DISNEY_CONDITION_TYPE);
	dc_disney_set_member_acting_type_list_eval(DC_DISNEY_CONDITION_EVAL_TRUE);

	dc_disney_set_member_acting_type_list(openborconstant("TYPE_ENEMY") | openborconstant("TYPE_NPC"));	
	
	/* 
	* Set pass animation, check conditions, and 
	* attempt to perform the animation.
	*/
	dc_disney_set_member_animation_pass_id(animation);
	dc_disney_try_conditional_animation();
}

/*
* Caskey, Damon V.
* 2021-05-14
* 
* Switch to new animation depending on there being
* a valid opponent that we can grab or not.
*/
void dc_disney_macro_try_grab_alternate_vs_opponent(int grab_eligible_animation, int grab_ineligible_animation)
{
	/* Disable acting and global conditions. */
	dc_disney_set_member_condition_list_global(DC_DISNEY_CONDITION_NONE);
	dc_disney_set_member_condition_list_acting(DC_DISNEY_CONDITION_NONE);

	/* 
	* Criteris is our current opponent, and
	* if they are eligible for a grab.
	*/
	dc_disney_set_member_target_select_method(DC_DISNEY_TARGET_SELECT_METHOD_OPPONENT);	
	dc_disney_set_member_condition_list_target(DC_DISNEY_CONDITION_GRAB_ELIGIBLE);

	/*
	* Set pass and fail animation, then run
	* conditional animation update.
	*/
	dc_disney_set_member_animation_pass_id(grab_eligible_animation);
	dc_disney_set_member_animation_fail_id(grab_ineligible_animation);
	dc_disney_try_conditional_animation();
}

/*
* Caskey, Damon V.
* 2021-05-15
* 
* Attempt perform attack without conditions.
*/
void dc_disney_macro_perform_attack(int animation_id)
{
	void acting_entity = dc_disney_get_member_entity();

	dc_disney_try_animation_update(acting_entity, animation_id, DC_DISNEY_PLAY_METHOD_PERFORM_ATTACK, 0);
}

/*
* Caskey, Damon V.
* 2021-05-15
*
* Attempt animation ID update without conditions.
*/
void dc_disney_macro_animation_id(int animation_id)
{
	void acting_entity = dc_disney_get_member_entity();

	dc_disney_try_animation_update(acting_entity, animation_id, DC_DISNEY_PLAY_METHOD_ENTITY_PROPERTY, 0);
}

/*
* Caskey, Damon V.
* 2021-05-15
*
* Attempt execute animation without conditions.
*/
void dc_disney_macro_execute_animation(int animation_id)
{
	void acting_entity = dc_disney_get_member_entity();

	dc_disney_try_animation_update(acting_entity, animation_id, DC_DISNEY_PLAY_METHOD_EXECUTE_ANIMATION, 0);
}