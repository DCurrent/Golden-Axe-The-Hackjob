#ifndef DC_DISNEY_CONFIG
#define DC_DISNEY_CONFIG 1

#include "data/scripts/dc_instance/main.c"
#include "data/scripts/dc_eggball/main.c"

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

/* Conditions for switching an animation. */
#define DC_DISNEY_CONDITION_NONE					0
#define DC_DISNEY_CONDITION_ANIMATION_NO			1
#define DC_DISNEY_CONDITION_ANIMATION_YES			2
#define DC_DISNEY_CONDITION_GRAB_ELIGIBLE_NO		4
#define DC_DISNEY_CONDITION_GRAB_ELIGIBLE_YES		8
#define DC_DISNEY_CONDITION_GRAB_IMMUNE_NO			16
#define DC_DISNEY_CONDITION_GRAB_IMMUNE_YES			32
#define DC_DISNEY_CONDITION_HEALTH_PORTION_ABOVE	64
#define DC_DISNEY_CONDITION_HEALTH_PORTION_BELOW	128
#define DC_DISNEY_CONDITION_HEALTH_VALUE_ABOVE		256
#define DC_DISNEY_CONDITION_HEALTH_VALUE_BELOW		512
#define DC_DISNEY_CONDITION_HEIGHT_DIFFERENCE_ABOVE	1024
#define DC_DISNEY_CONDITION_HEIGHT_DIFFERENCE_BELOW	2048
#define DC_DISNEY_CONDITION_MODEL_DEFAULT_NO		4096
#define DC_DISNEY_CONDITION_MODEL_DEFAULT_YES		8192
#define DC_DISNEY_CONDITION_MP_PORTION_ABOVE		16384 //
#define DC_DISNEY_CONDITION_MP_PORTION_BELOW		32768 // 
#define DC_DISNEY_CONDITION_MP_VALUE_ABOVE			65536 //
#define DC_DISNEY_CONDITION_MP_VALUE_BELOW			131072 //
#define DC_DISNEY_CONDITION_RANDOM					262144 //
#define DC_DISNEY_CONDITION_RANGE_IN				524288
#define DC_DISNEY_CONDITION_RANGE_OUT				1048576
#define DC_DISNEY_CONDITION_WALKOFF					2097152

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
#define DC_DISNEY_DEFAULT_TIME_DELAY	1000

#define DC_DISNEY_DEFAULT_CONDITION_FLAG_TARGET					DC_DISNEY_CONDITION_NONE
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_PORTION		0.1	
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEALTH_VALUE			100			
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_HEIGHT_DIFFERENCE	50
#define DC_DISNEY_DEFAULT_CONDITION_TARGET_MODEL_DEFAULT		""

/*
* Member Variable keys.
*/

#define DC_DISNEY_MEMBER_ANIMATION							DC_DISNEY_BASE_ID + 0
#define DC_DISNEY_MEMBER_CONDITION_FLAG_TARGET				DC_DISNEY_BASE_ID + 1
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_PORTION	DC_DISNEY_BASE_ID + 2
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEALTH_VALUE		DC_DISNEY_BASE_ID + 3
#define DC_DISNEY_MEMBER_CONDITION_TARGET_HEIGHT_DIFFERENCE	DC_DISNEY_BASE_ID + 4
#define DC_DISNEY_MEMBER_CONDITION_TARGET_MODEL_DEFAULT		DC_DISNEY_BASE_ID + 5
#define DC_DISNEY_MEMBER_ENT								DC_DISNEY_BASE_ID + 6
#define DC_DISNEY_MEMBER_SWITCH_RESET						DC_DISNEY_BASE_ID + 7
#define DC_DISNEY_MEMBER_SWITCH_TYPE						DC_DISNEY_BASE_ID + 8
#define DC_DISNEY_MEMBER_TIME_DELAY							DC_DISNEY_BASE_ID + 9
#define DC_DISNEY_MEMBER_THE_END		9			// Should always be last, with a value one higher than previous key ID.

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

