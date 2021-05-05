#ifndef DC_DISNEY_CONFIG
#define DC_DISNEY_CONFIG 1

#include "data/scripts/dc_instance/main.c"
#include "data/scripts/dc_eggball/main.c"
#include "data/scripts/dc_d20/main.c"

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_DISNEY_BASE_ID		"dcdis"	// Base name of every var ID. Must be unique vs. all other libraries.

/*
* Options
*/

#define DC_DISNEY_ANIMATION_SELECT_ACTING_CURRENT	-1

/* 
* What means we use to get "target" entity
* when evaluating conditions to change 
* animation. 
*/
#define DC_DISNEY_TARGET_SELECT_METHOD_ANIMATION	0
#define DC_DISNEY_TARGET_SELECT_METHOD_GRABBED		(1 << 0)
#define DC_DISNEY_TARGET_SELECT_METHOD_OPPONENT		(1 << 1)
#define DC_DISNEY_TARGET_SELECT_METHOD_MANUAL		(1 << 2)


/* Conditions for switching an animation. */

#define DC_DISNEY_CONDITION_EVAL_FALSE		0					// Condition must evaluate FALSE.
#define DC_DISNEY_CONDITION_EVAL_TRUE		(1 << 0)			// Condition must evaluate TRUE.
#define DC_DISNEY_CONDITION_EVAL_EQUAL		(1 << 1)			// Compared value must match member value.
#define DC_DISNEY_CONDITION_EVAL_GREATER	(1 << 2)			// Compared value must exceed member value.
#define DC_DISNEY_CONDITION_EVAL_LESSER		(1 << 3)			// Compared value must be less than member value.

#define DC_DISNEY_CONDITION_NONE					0			// No conditions. Adding any other condition overrides this.
#define DC_DISNEY_CONDITION_AIR						(1 << 0)	// Airborne.
#define DC_DISNEY_CONDITION_ANIMAL					(1 << 1)	// Has animal flag.
#define DC_DISNEY_CONDITION_ANIMATION				(1 << 2)	// Current animation matches aniamtion member.
#define DC_DISNEY_CONDITION_DELAY					(1 << 3)	// First use or enough time passed since last use.
#define DC_DISNEY_CONDITION_FALL					(1 << 4)	// In falling state.
#define DC_DISNEY_CONDITION_GRAB_ELIGIBLE			(1 << 5)	// Acting has ability to grab target.
#define DC_DISNEY_CONDITION_GRAB_IMMUNE				(1 << 6)	// Target is fully immune to all grabs.
#define DC_DISNEY_CONDITION_HEALTH_PORTION			(1 << 7)	// Health % vs. member value.
#define DC_DISNEY_CONDITION_HEALTH_VALUE			(1 << 8)	// Health vs. member value. 
#define DC_DISNEY_CONDITION_HEIGHT_DIFFERENCE		(1 << 9)	// Difference between acting height and target height vs. member value.
#define DC_DISNEY_CONDITION_HEIGHT_VALUE			(1 << 10)	// Difference of height vs. member value.
#define DC_DISNEY_CONDITION_HOSTILE					(1 << 11)	// Entity hostile list vs member value.
#define DC_DISNEY_CONDITION_MODEL_DEFAULT			(1 << 12)	// Default model name vs. member value.
#define DC_DISNEY_CONDITION_MP_PORTION				(1 << 13)	// MP % vs. member value.
#define DC_DISNEY_CONDITION_MP_VALUE				(1 << 14)	// MP vs. member value.
#define DC_DISNEY_CONDITION_RANDOM_CHANCE			(1 << 15)	// 0-100% chance (set by member value).
#define DC_DISNEY_CONDITION_RANGE					(1 << 16)	// In animation range (animation set by member value).
#define DC_DISNEY_CONDITION_SUBTYPE					(1 << 17)	// Subtype vs. member value.
#define DC_DISNEY_CONDITION_TYPE					(1 << 18)	// Type vs. member value.
#define DC_DISNEY_CONDITION_WALKOFF					(1 << 19)	// In walkoff (stepping over edge of platform, wall, etc.).

/* Method for switching animation. */
#define DC_DISNEY_SWITCH_TYPE_ENTITY_PROPERTY				0
#define DC_DISNEY_SWITCH_TYPE_EXECUTE_ANIMATION				1
#define DC_DISNEY_SWITCH_TYPE_PERFORM_ATTACK				2

/*
* Default member values.
*/

#define DC_DISNEY_DEFAULT_ENT			getlocalvar("self")
#define DC_DISNEY_DEFAULT_ANIMATION		openborconstant("ANI_IDLE")
#define DC_DISNEY_DEFAULT_SWITCH_RESET	0
#define DC_DISNEY_DEFAULT_SWITCH_TYPE	DC_DISNEY_SWITCH_TYPE_EXECUTE_ANIMATION
#define DC_DISNEY_DEFAULT_TARGET		NULL()
#define DC_DISNEY_DEFAULT_TIME_DELAY	1000

#define DC_DISNEY_DEFAULT_TARGET_SELECT_ANIMATION					DC_DISNEY_ANIMATION_SELECT_ACTING_CURRENT
#define DC_DISNEY_DEFAULT_TARGET_SELECT_METHOD						DC_DISNEY_TARGET_SELECT_METHOD_ANIMATION

#define DC_DISNEY_DEFAULT_CONDITION_LIST_ACTING						DC_DISNEY_CONDITION_NONE
#define DC_DISNEY_DEFAULT_CONDITION_LIST_GLOBAL						DC_DISNEY_CONDITION_NONE
#define DC_DISNEY_DEFAULT_CONDITION_LIST_TARGET						DC_DISNEY_CONDITION_NONE

#define DC_DISNEY_DEFAULT_CONDITION_GLOBAL_DELAY					100
#define DC_DISNEY_DEFAULT_CONDITION_GLOBAL_DELAY_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_GLOBAL_RANDOM_CHANCE			50
#define DC_DISNEY_DEFAULT_CONDITION_GLOBAL_RANDOM_CHANCE_EVAL		DC_DISNEY_CONDITION_EVAL_TRUE

#define DC_DISNEY_DEFAULT_CONDITION_ACTING_AIR						1
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_AIR_EVAL					DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMAL					1
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMAL_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION				openborconstant("ANI_IDLE")
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_ANIMATION_EVAL			DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_FALL						1
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_FALL_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_ELIGIBLE			1
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_ELIGIBLE_EVAL		DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_IMMUNE				1
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_GRAB_IMMUNE_EVAL			DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_PORTION			1.0
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_PORTION_EVAL		DC_DISNEY_CONDITION_EVAL_LESSER
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_VALUE				100
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEALTH_VALUE_EVAL		DC_DISNEY_CONDITION_EVAL_LESSER
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEIGHT_DIFFERENCE		20
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEIGHT_DIFFERENCE_EVAL	DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEIGHT_VALUE				100
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HEIGHT_VALUE_EVAL		DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HOSTILE					100
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_HOSTILE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_MODEL_DEFAULT			""
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_MODEL_DEFAULT_EVAL		DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_MP_PORTION				0.749
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_MP_PORTION_EVAL			DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_MP_VALUE					74
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_MP_VALUE_EVAL			DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_RANGE					openborconstant("ANI_IDLE")
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_RANGE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_SUBTYPE					openborconstant("TYPE_NONE")
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_SUBTYPE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_TYPE						openborconstant("TYPE_ENEMY") + openborconstant("TYPE_PLAYER")
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_TYPE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_WALKOFF					1
#define DC_DISNEY_DEFAULT_CONDITION_ACTING_WALKOFF_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE

#define DC_DISNEY_DEFAULT_CONDITION_TARGET_AIR						1
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_AIR_EVAL					DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMAL					1
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMAL_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION				openborconstant("ANI_IDLE")
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_ANIMATION_EVAL			DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_FALL						1
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_FALL_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_ELIGIBLE			1
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_ELIGIBLE_EVAL		DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_IMMUNE				1
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_GRAB_IMMUNE_EVAL			DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION			1.0
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION_EVAL		DC_DISNEY_CONDITION_EVAL_LESSER
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE				100
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE_EVAL		DC_DISNEY_CONDITION_EVAL_LESSER
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_DIFFERENCE		20
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_DIFFERENCE_EVAL	DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_VALUE				100
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_VALUE_EVAL		DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HOSTILE					100
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HOSTILE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MODEL_DEFAULT			""
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MODEL_DEFAULT_EVAL		DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_PORTION				0.749
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_PORTION_EVAL			DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_VALUE					74
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MP_VALUE_EVAL			DC_DISNEY_CONDITION_EVAL_GREATER
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_RANGE					openborconstant("ANI_IDLE")
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_RANGE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_SUBTYPE					openborconstant("TYPE_NONE")
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_SUBTYPE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_TYPE						openborconstant("TYPE_ENEMY") + openborconstant("TYPE_PLAYER")
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_TYPE_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_WALKOFF					1
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_WALKOFF_EVAL				DC_DISNEY_CONDITION_EVAL_TRUE

/*
* Member Variable keys.
*/

#define DC_DISNEY_MEMBER_ANIMATION									DC_DISNEY_BASE_ID + 0	// Animation we want to switch to.

/* Condition values to check on acting entity. */
#define DC_DISNEY_MEMBER_CONDITION_ACTING_AIR						DC_DISNEY_BASE_ID + 1
#define DC_DISNEY_MEMBER_CONDITION_ACTING_AIR_EVAL					DC_DISNEY_BASE_ID + 2
#define DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMAL					DC_DISNEY_BASE_ID + 3
#define DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMAL_EVAL				DC_DISNEY_BASE_ID + 4
#define DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION					DC_DISNEY_BASE_ID + 5
#define DC_DISNEY_MEMBER_CONDITION_ACTING_ANIMATION_EVAL			DC_DISNEY_BASE_ID + 6
#define DC_DISNEY_MEMBER_CONDITION_ACTING_FALL						DC_DISNEY_BASE_ID + 7
#define DC_DISNEY_MEMBER_CONDITION_ACTING_FALL_EVAL					DC_DISNEY_BASE_ID + 8
#define DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_ELIGIBLE				DC_DISNEY_BASE_ID + 9
#define DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_ELIGIBLE_EVAL		DC_DISNEY_BASE_ID + 10
#define DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_IMMUNE				DC_DISNEY_BASE_ID + 11
#define DC_DISNEY_MEMBER_CONDITION_ACTING_GRAB_IMMUNE_EVAL			DC_DISNEY_BASE_ID + 12
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_PORTION			DC_DISNEY_BASE_ID + 13
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_PORTION_EVAL		DC_DISNEY_BASE_ID + 14
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_VALUE				DC_DISNEY_BASE_ID + 15
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEALTH_VALUE_EVAL			DC_DISNEY_BASE_ID + 16
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEIGHT_DIFFERENCE			DC_DISNEY_BASE_ID + 17
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEIGHT_DIFFERENCE_EVAL	DC_DISNEY_BASE_ID + 18
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEIGHT_VALUE				DC_DISNEY_BASE_ID + 19
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HEIGHT_VALUE_EVAL			DC_DISNEY_BASE_ID + 20
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HOSTILE					DC_DISNEY_BASE_ID + 21
#define DC_DISNEY_MEMBER_CONDITION_ACTING_HOSTILE_EVAL				DC_DISNEY_BASE_ID + 22
#define DC_DISNEY_MEMBER_CONDITION_ACTING_MODEL_DEFAULT				DC_DISNEY_BASE_ID + 23
#define DC_DISNEY_MEMBER_CONDITION_ACTING_MODEL_DEFAULT_EVAL		DC_DISNEY_BASE_ID + 24
#define DC_DISNEY_MEMBER_CONDITION_ACTING_MP_PORTION				DC_DISNEY_BASE_ID + 25
#define DC_DISNEY_MEMBER_CONDITION_ACTING_MP_PORTION_EVAL			DC_DISNEY_BASE_ID + 26
#define DC_DISNEY_MEMBER_CONDITION_ACTING_MP_VALUE					DC_DISNEY_BASE_ID + 27
#define DC_DISNEY_MEMBER_CONDITION_ACTING_MP_VALUE_EVAL				DC_DISNEY_BASE_ID + 28
#define DC_DISNEY_MEMBER_CONDITION_ACTING_RANGE						DC_DISNEY_BASE_ID + 29
#define DC_DISNEY_MEMBER_CONDITION_ACTING_RANGE_EVAL				DC_DISNEY_BASE_ID + 30
#define DC_DISNEY_MEMBER_CONDITION_ACTING_SUBTYPE					DC_DISNEY_BASE_ID + 31
#define DC_DISNEY_MEMBER_CONDITION_ACTING_SUBTYPE_EVAL				DC_DISNEY_BASE_ID + 32
#define DC_DISNEY_MEMBER_CONDITION_ACTING_TYPE						DC_DISNEY_BASE_ID + 33
#define DC_DISNEY_MEMBER_CONDITION_ACTING_TYPE_EVAL					DC_DISNEY_BASE_ID + 34
#define DC_DISNEY_MEMBER_CONDITION_ACTING_WALKOFF					DC_DISNEY_BASE_ID + 35
#define DC_DISNEY_MEMBER_CONDITION_ACTING_WALKOFF_EVAL				DC_DISNEY_BASE_ID + 36

/* Conditions values to check unrelated to an entity. */
#define DC_DISNEY_MEMBER_CONDITION_GLOBAL_DELAY						DC_DISNEY_BASE_ID + 37
#define DC_DISNEY_MEMBER_CONDITION_GLOBAL_DELAY_EVAL				DC_DISNEY_BASE_ID + 38
#define DC_DISNEY_MEMBER_CONDITION_GLOBAL_RANDOM_CHANCE				DC_DISNEY_BASE_ID + 39
#define DC_DISNEY_MEMBER_CONDITION_GLOBAL_RANDOM_CHANCE_EVAL		DC_DISNEY_BASE_ID + 40

/* Which conditions to check. Uses bitwise flags. */
#define DC_DISNEY_MEMBER_CONDITION_LIST_ACTING						DC_DISNEY_BASE_ID + 41	
#define DC_DISNEY_MEMBER_CONDITION_LIST_GLOBAL						DC_DISNEY_BASE_ID + 42	
#define DC_DISNEY_MEMBER_CONDITION_LIST_TARGET						DC_DISNEY_BASE_ID + 43

/* Conditions values to check on a target entity. */
#define DC_DISNEY_MEMBER_CONDITION_TARGET_AIR						DC_DISNEY_BASE_ID + 44
#define DC_DISNEY_MEMBER_CONDITION_TARGET_AIR_EVAL					DC_DISNEY_BASE_ID + 45
#define DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMAL					DC_DISNEY_BASE_ID + 46
#define DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMAL_EVAL				DC_DISNEY_BASE_ID + 47
#define DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION					DC_DISNEY_BASE_ID + 48
#define DC_DISNEY_MEMBER_CONDITION_TARGET_ANIMATION_EVAL			DC_DISNEY_BASE_ID + 49
#define DC_DISNEY_MEMBER_CONDITION_TARGET_DELAY						DC_DISNEY_BASE_ID + 50
#define DC_DISNEY_MEMBER_CONDITION_TARGET_DELAY_EVAL				DC_DISNEY_BASE_ID + 51
#define DC_DISNEY_MEMBER_CONDITION_TARGET_FALL						DC_DISNEY_BASE_ID + 52
#define DC_DISNEY_MEMBER_CONDITION_TARGET_FALL_EVAL					DC_DISNEY_BASE_ID + 53
#define DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_ELIGIBLE				DC_DISNEY_BASE_ID + 54
#define DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_ELIGIBLE_EVAL		DC_DISNEY_BASE_ID + 55
#define DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_IMMUNE				DC_DISNEY_BASE_ID + 56
#define DC_DISNEY_MEMBER_CONDITION_TARGET_GRAB_IMMUNE_EVAL			DC_DISNEY_BASE_ID + 57
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION			DC_DISNEY_BASE_ID + 58
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION_EVAL		DC_DISNEY_BASE_ID + 59
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE				DC_DISNEY_BASE_ID + 60
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE_EVAL			DC_DISNEY_BASE_ID + 61
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_DIFFERENCE			DC_DISNEY_BASE_ID + 62
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_DIFFERENCE_EVAL	DC_DISNEY_BASE_ID + 63
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_VALUE				DC_DISNEY_BASE_ID + 64
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_VALUE_EVAL			DC_DISNEY_BASE_ID + 65
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HOSTILE					DC_DISNEY_BASE_ID + 66
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HOSTILE_EVAL				DC_DISNEY_BASE_ID + 67
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MODEL_DEFAULT				DC_DISNEY_BASE_ID + 68
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MODEL_DEFAULT_EVAL		DC_DISNEY_BASE_ID + 69
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MP_PORTION				DC_DISNEY_BASE_ID + 70
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MP_PORTION_EVAL			DC_DISNEY_BASE_ID + 71
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MP_VALUE					DC_DISNEY_BASE_ID + 72
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MP_VALUE_EVAL				DC_DISNEY_BASE_ID + 73
#define DC_DISNEY_MEMBER_CONDITION_TARGET_RANGE						DC_DISNEY_BASE_ID + 74
#define DC_DISNEY_MEMBER_CONDITION_TARGET_RANGE_EVAL				DC_DISNEY_BASE_ID + 75
#define DC_DISNEY_MEMBER_CONDITION_TARGET_SUBTYPE					DC_DISNEY_BASE_ID + 76
#define DC_DISNEY_MEMBER_CONDITION_TARGET_SUBTYPE_EVAL				DC_DISNEY_BASE_ID + 77
#define DC_DISNEY_MEMBER_CONDITION_TARGET_TYPE						DC_DISNEY_BASE_ID + 78
#define DC_DISNEY_MEMBER_CONDITION_TARGET_TYPE_EVAL					DC_DISNEY_BASE_ID + 79
#define DC_DISNEY_MEMBER_CONDITION_TARGET_WALKOFF					DC_DISNEY_BASE_ID + 80
#define DC_DISNEY_MEMBER_CONDITION_TARGET_WALKOFF_EVAL				DC_DISNEY_BASE_ID + 81

#define DC_DISNEY_MEMBER_ENT										DC_DISNEY_BASE_ID + 82	// The acting entity - entity to perform animation switch.
#define DC_DISNEY_MEMBER_SWITCH_RESET								DC_DISNEY_BASE_ID + 83
#define DC_DISNEY_MEMBER_SWITCH_TYPE								DC_DISNEY_BASE_ID + 84
#define DC_DISNEY_MEMBER_TARGET										DC_DISNEY_BASE_ID + 85
#define DC_DISNEY_MEMBER_TARGET_SELECT_ANIMATION					DC_DISNEY_BASE_ID + 86	// Animation sent to findtarget() function when using animation to select target entity.
#define DC_DISNEY_MEMBER_TARGET_SELECT_METHOD						DC_DISNEY_BASE_ID + 87	// method used to select target entity.
#define DC_DISNEY_MEMBER_TIME_DELAY									DC_DISNEY_BASE_ID + 88	// Animation executed after a delay in time. Not to be confused with delay condition, which forces a delay between uses of animation.

#define DC_DISNEY_MEMBER_THE_END		89			// Should always be last, with a value one higher than previous key ID.

/** Instance control
*
* Instance control allows us to run more than
* one copy (instance) of a library without the
* instances conflicting with each other.
*
* To avoid repeat code, there is a library
* dedicated specifically to instance control.
* This section overrides local function names
* with instance control library functions to
* simplify use of the the instance control
* library.
**/
#define dc_disney_get_instance()		dc_instance_get(DC_DISNEY_BASE_ID)
#define dc_disney_set_instance(value)	dc_instance_set(DC_DISNEY_BASE_ID, value)
#define dc_disney_reset_instance()		dc_instance_reset(DC_DISNEY_BASE_ID, DC_DISNEY_MEMBER_THE_END)
#define dc_disney_free_instance()		dc_instance_free(DC_DISNEY_BASE_ID, DC_DISNEY_MEMBER_THE_END)
#define dc_disney_dump_instance()		dc_instance_dump(DC_DISNEY_BASE_ID, DC_DISNEY_MEMBER_THE_END)
#define dc_disney_export_instance()		dc_instance_export(DC_DISNEY_BASE_ID, DC_DISNEY_MEMBER_THE_END)
#define dc_disney_import_instance()		dc_instance_import(DC_DISNEY_BASE_ID, DC_DISNEY_MEMBER_THE_END)
#define dc_disney_free_export()			dc_instance_free_export(DC_DISNEY_BASE_ID, DC_DISNEY_MEMBER_THE_END)

#endif // !DC_DISNEY_CONFIG

