
#include "data/scripts/dc_disney/config.h"

#import "data/scripts/dc_disney/animation.c"

#import "data/scripts/dc_disney/conditions.c"
#import "data/scripts/dc_disney/condition_random.c"
#import "data/scripts/dc_disney/condition_type.c"

#import "data/scripts/dc_disney/perform_attack.c"

/*
* Caskey, Damon V.
* 2021-05-05
* 
* Switch to animation if acting entity
* is AI controlled and random roll 
* suceeds.
*/
void dc_disney_ai_random(int animation, int chance)
{
	dc_disney_set_member_condition_flag_global(DC_DISNEY_CONDITION_RANDOM_CHANCE, 1);
	dc_disney_set_member_global_random_chance(chance);

	/* 
	* We only want AI controlled entities, so set up type 
	* check to evaluate FALSE for player type.
	*/
	dc_disney_set_member_condition_flag_acting(DC_DISNEY_CONDITION_TYPE, 1);
	dc_disney_set_member_acting_type_list_eval(DC_DISNEY_CONDITION_EVAL_FALSE);

	/* Reset type list, then turn on player bit. */
	dc_disney_set_member_acting_type_list(NULL());	
	dc_disney_set_member_acting_type_flag(openborconstant("TYPE_PLAYER"), 1);

	/* 
	* Check conditions, and if everything passes perform 
	* the animation.
	*/
	if (dc_disney_check_all_conditions())
	{
		dc_disney_perform_attack(animation);
	}
}