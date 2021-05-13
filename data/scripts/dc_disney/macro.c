
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
void dc_disney_ai_random(int animation, int chance)
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
	* Check conditions, and if everything passes perform 
	* the animation.
	*/
	if (dc_disney_check_all_conditions())
	{
		dc_disney_perform_attack(animation);
	}
}