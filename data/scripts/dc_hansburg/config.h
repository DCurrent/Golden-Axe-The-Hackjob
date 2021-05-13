#ifndef DC_HANSBURG
#define DC_HANSBURG 1

#include "data/scripts/dc_instance/main.c"

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_HANSBURG_BASE_ID		"dchan"

/* 
* These are the auxiliary jumping animations. Settings here are module wide.
* For example, whatever animation you set for double jumping here must be used
* by every model you want to have double jumping capability. If a model does not
* have one of these animations, then it simply does not have the associated
* jumping capability. You can mix and match how you like. In other words, a model
* might not have a wall jump, but could still have double jumping. Another model
* might only have double jumping, and yet another might have everything.

* Note that if you like you may also re-use animation definitions. For example, you
* could define the same animation here for the start-up of obstacle jumping, wall
* jumping, and edge jumping. Then adding that single animation to a model would
* give it all those types of auxiliary jumping.
*/
#define DC_HANSBURG_ANI_JUMP_DOUBLE_NEUTRAL     openborconstant("ANI_FOLLOW42")     // Double jumping animation.
#define DC_HANSBURG_ANI_JUMP_DOUBLE_BACK        openborconstant("ANI_FOLLOW44")     // Double jumping backward animation.
#define DC_HANSBURG_ANI_JUMP_DOUBLE_FORWARD     openborconstant("ANI_FOLLOW43")     // Double jumping forward animation.
#define DC_HANSBURG_ANI_JUMP_EDGE               openborconstant("ANI_FOLLOW41")     // Screen edge jumping animation.
#define DC_HANSBURG_ANI_JUMP_EDGE_START         openborconstant("ANI_FOLLOW40")     // Screen edge prepping to jump animation. The range of this animation is used to detect screen edges
#define DC_HANSBURG_ANI_JUMP_OBJECT             openborconstant("ANI_FOLLOW41")     // Obstacle jumping animation.
#define DC_HANSBURG_ANI_JUMP_OBJECT_START       openborconstant("ANI_FOLLOW40")     // Obstacle prepping to jump animation. The range of this animation is used to detect objects.
#define DC_HANSBURG_ANI_JUMP_WALL               openborconstant("ANI_FOLLOW41")     // Wall jump animation.
#define DC_HANSBURG_ANI_JUMP_WALL_START         openborconstant("ANI_FOLLOW40")     // Wall prepping to jump animation.   The range of this animation is used to detect walls.

#define DC_HANSBURG_JUMP                        1

/*
* Control flags 
*/

/* Enable flags for extra jump types allowed. */
#define DC_HANSBURG_JUMP_ENABLE_NONE			0
#define DC_HANSBURG_JUMP_ENABLE_CONTROL_HEIGHT	(1 << 0)
#define DC_HANSBURG_JUMP_ENABLE_DOUBLE_AIR		(1 << 1)	
#define DC_HANSBURG_JUMP_ENABLE_DOUBLE_EDGE		(1 << 2)
#define DC_HANSBURG_JUMP_ENABLE_DOUBLE_OBJECT	(1 << 3)
#define DC_HANSBURG_JUMP_ENABLE_DOUBLE_WALL		(1 << 4)

/* No time limit. */
#define DC_HANSBURG_TIME_INFINITE               -1

/* Forward/Backward command status in relation to facing. */
#define DC_HANSBURG_KEY_MOVE_HORIZONTAL_BACK    1
#define DC_HANSBURG_KEY_MOVE_HORIZONTAL_FORWARD 2
#define DC_HANSBURG_KEY_MOVE_HORIZONTAL_NEUTRAL 3

/*
* Default values. 
*/

#define DC_HANSBURG_DEFAULT_FLAG_LIST					DC_HANSBURG_JUMP_ENABLE_CONTROL_HEIGHT | DC_HANSBURG_JUMP_ENABLE_DOUBLE_AIR | DC_HANSBURG_JUMP_ENABLE_DOUBLE_EDGE | DC_HANSBURG_JUMP_ENABLE_DOUBLE_OBJECT | DC_HANSBURG_JUMP_ENABLE_DOUBLE_WALL
#define DC_HANSBURG_DEFAULT_ENT							getlocalvar("self")
#define DC_HANSBURG_DEFAULT_CONDITION_POSITION_Y_MAX	openborvariant("hResolution") * 1.25    // Maximum height to allow auxiliary jumps.
#define DC_HANSBURG_DEFAULT_DISABLE_TIME				0
/*
* Member Variable keys.
*/
#define DC_HANSBURG_MEMBER_CONDITION_POSITION_Y_MAX		DC_HANSBURG_BASE_ID + 0 
#define DC_HANSBURG_MEMBER_DISABLE						DC_HANSBURG_BASE_ID + 1
#define DC_HANSBURG_MEMBER_ENT							DC_HANSBURG_BASE_ID + 2
#define DC_HANSBURG_MEMBER_FLAG_LIST					DC_HANSBURG_BASE_ID + 3
#define DC_HANSBURG_MEMBER_THE_END		95			// Should always be last, with a value one higher than previous key ID.

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
#define dc_hansburg_get_instance()		dc_instance_get(DC_HANSBURG_BASE_ID)
#define dc_hansburg_set_instance(value)	dc_instance_set(DC_HANSBURG_BASE_ID, value)
#define dc_hansburg_reset_instance()	dc_instance_reset(DC_HANSBURG_BASE_ID, DC_HANSBURG_MEMBER_THE_END)
#define dc_hansburg_free_instance()		dc_instance_free(DC_HANSBURG_BASE_ID, DC_HANSBURG_MEMBER_THE_END)
#define dc_hansburg_dump_instance()		dc_instance_dump(DC_HANSBURG_BASE_ID, DC_HANSBURG_MEMBER_THE_END)
#define dc_hansburg_export_instance()	dc_instance_export(DC_HANSBURG_BASE_ID, DC_HANSBURG_MEMBER_THE_END)
#define dc_hansburg_import_instance()	dc_instance_import(DC_HANSBURG_BASE_ID, DC_HANSBURG_MEMBER_THE_END)
#define dc_hansburg_free_export()		dc_instance_free_export(DC_HANSBURG_BASE_ID, DC_HANSBURG_MEMBER_THE_END)

#endif


