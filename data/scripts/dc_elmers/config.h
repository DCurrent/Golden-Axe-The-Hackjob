#ifndef DC_ELMERS_CONFIG
#define DC_ELMERS_CONFIG 1

#include "data/scripts/dc_disney/main.c"
#include "data/scripts/dc_math/main.c"
#include "data/scripts/dc_instance/main.c"

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_ELMERS_BASE_ID	"dcelme"

/* 
* Disabled. When disabled, calls to bind are skipped.
*/ 
#define DC_ELMERS_DISABLED_FALSE			0
#define DC_ELMERS_DISABLED_TRUE				1

/*
* Invert. Invert the offset when criteria are met.
*/
#define DC_ELMERS_INVERT_DIRECTION			1	// Target faces left.
#define DC_ELMERS_INVERT_DISABLED			0	// No invert.
#define DC_ELMERS_INVERT_POSITION			2	// Target position is greater along axis.

/*
* Positioning. 
* 
* Controls How binds/reposition offsets are applied
* for a given axis.
*/ 
#define DC_ELMERS_MODE_DISABLED				openborconstant("BIND_MODE_NONE")
#define DC_ELMERS_MODE_LEVEL				openborconstant("BIND_MODE_LEVEL")
#define DC_ELMERS_MODE_SCREEN				3
#define	DC_ELMERS_MODE_TARGET				openborconstant("BIND_MODE_TARGET")

#define DC_ELMERS_PALETTE_MATCH_NONE		0
#define DC_ELMERS_PALETTE_MATCH_INDEX		1
#define DC_ELMERS_PALETTE_MATCH_TABLE		2

/*
* Grapple control sub system.
* 
* Series of flags used to control binding specifically for
* building custom throw and slam sequences.
*/

#define DC_ELMERS_DEFAULT_BLAST_STATE		openborconstant("BLAST_ATTACK")

/*
* Preset attack types (make sure these match the pain/fall in your models).
*/
#define DC_ELMERS_ATTACK_TYPE_THROW			openborconstant("ATK_NORMAL10")
#define DC_ELMERS_ATTACK_TYPE_FLAT			openborconstant("ATK_NORMAL11")
#define DC_ELMERS_ATTACK_TYPE_DIVE			openborconstant("ATK_NORMAL12")

/*
* Resetting the grappled entity when interrupted.
*/
#define DC_ELMERS_RESET_ATTACK_TYPE			openborconstant("ATK_NORMAL")	// Drop force grabbed entity takes when grapple is interrupted.
#define DC_ELMERS_RESET_ATTACK_FORCE		0								// Damage grabbed entity takes when grapple is interrupted.
#define DC_ELMERS_RESET_ATTACK_DROP			10000							// Drop force grabbed entity takes when grapple is interrupted.

/*
* Sorting the grappled entity in relation to
* holding entity.
*/ 
#define DC_ELMERS_SORT_BACK				-1
#define DC_ELMERS_SORT_BACK_GRAPPLE		-2
#define DC_ELMERS_SORT_FRONT			1
#define DC_ELMERS_SORT_FRONT_GRAPPLE	2

/*
* Ability to damage other entities when NOT
* being thrown (i.e. blast state).
*/
#define DC_ELMERS_CAN_DAMAGE_NONE 0

/* 
* Grapple animations
*/
#define DC_ELMERS_SWITCH_TO_BACK				openborconstant("ANI_FOLLOW11")
#define DC_ELMERS_SWITCH_TO_FRONT				openborconstant("ANI_FOLLOW12")
#define DC_ELMERS_GRAB_BACK						openborconstant("ANI_GRAB")
#define DC_ELMERS_GRABBED_BACK					openborconstant("ANI_GRABBED")

/* 
* Reaction animation (pose collection).
*/
#define DC_ELMERS_REACT_ANIMATION				openborconstant("ANI_FOLLOW10")

/*
* Reaction frames (poses). These set the frame to play from
* reaction control animation. The animation's frame order MUST 
* match up with this list to work properly.
*/ 
#define DC_ELMERS_REACT_FALLING_UP_0			0	
#define DC_ELMERS_REACT_FALLING_UP_CENTER_0		1	
#define DC_ELMERS_REACT_FALLING_UP_LIFT_0		2	
#define DC_ELMERS_REACT_FALLING_UP_TILT_0		3
#define DC_ELMERS_REACT_HELD_0					4
#define DC_ELMERS_REACT_HORIZONTAL_DOWN_0		5
#define DC_ELMERS_REACT_HORIZONTAL_DOWN_PAIN_0	6
#define DC_ELMERS_REACT_HORIZONTAL_DOWN_PAIN_1	7
#define DC_ELMERS_REACT_HORIZONTAL_DOWN_PAIN_2	8
#define DC_ELMERS_REACT_HORIZONTAL_UP_0			9
#define DC_ELMERS_REACT_HORIZONTAL_UP_PAIN_0	10
#define DC_ELMERS_REACT_HORIZONTAL_UP_PAIN_1	11
#define DC_ELMERS_REACT_HORIZONTAL_UP_PAIN_2	12
#define DC_ELMERS_REACT_LAYING_UP_0				13
#define DC_ELMERS_REACT_LAYING_UP_PAIN_0		14
#define DC_ELMERS_REACT_LAYING_UP_PAIN_1		15
#define DC_ELMERS_REACT_LAYING_UP_PAIN_2		16
#define DC_ELMERS_REACT_PAIN_0					17
#define DC_ELMERS_REACT_PAIN_1					18
#define DC_ELMERS_REACT_PAIN_2					19
#define DC_ELMERS_REACT_PAIN_MID_0				20
#define DC_ELMERS_REACT_PAIN_MID_1				21
#define DC_ELMERS_REACT_PAIN_MID_2				22
#define DC_ELMERS_REACT_TILT_DOWN_0				23
#define DC_ELMERS_REACT_TILT_FORWARD_0			24
#define DC_ELMERS_REACT_TILT_UP_0				25
#define DC_ELMERS_REACT_VERTICAL_DOWN_0			26
#define DC_ELMERS_REACT_VERTICAL_DOWN_PAIN_0	27
#define DC_ELMERS_REACT_VERTICAL_DOWN_PAIN_1	28
#define DC_ELMERS_REACT_VERTICAL_DOWN_PAIN_2	29
#define DC_ELMERS_REACT_VERTICAL_UP_0			30

/*
* Default values.
*/ 
#define DC_ELMERS_DEFAULT_INSTANCE				0
#define DC_ELMERS_DEFAULT_ATTACKING				openborconstant("ATTACKING_ACTIVE")
#define DC_ELMERS_DEFAULT_BIND_DIRECTION		openborconstant("DIRECTION_ADJUST_SAME")
#define DC_ELMERS_DEFAULT_BLAST					openborconstant("BLAST_ATTACK")
#define DC_ELMERS_DEFAULT_CAN_DAMAGE			DC_ELMERS_CAN_DAMAGE_NONE
#define DC_ELMERS_DEFAULT_CAN_DAMAGE_OLD		DC_ELMERS_CAN_DAMAGE_NONE
#define DC_ELMERS_DEFAULT_DIRECTION				openborconstant("DIRECTION_ADJUST_SAME")
#define DC_ELMERS_DEFAULT_DISABLED				0
#define DC_ELMERS_DEFAULT_DOUBLE_OFFSET_X		0
#define DC_ELMERS_DEFAULT_DOUBLE_OFFSET_Y		0
#define DC_ELMERS_DEFAULT_DOUBLE_OFFSET_Z		0
#define DC_ELMERS_DEFAULT_ENT					getlocalvar("self")
#define DC_ELMERS_DEFAULT_INVERT_X				DC_ELMERS_INVERT_DIRECTION
#define DC_ELMERS_DEFAULT_INVERT_Y				DC_ELMERS_INVERT_DISABLED
#define DC_ELMERS_DEFAULT_INVERT_Z				DC_ELMERS_INVERT_DISABLED
#define DC_ELMERS_DEFAULT_LEVEL_X				0
#define DC_ELMERS_DEFAULT_LEVEL_Y				0
#define DC_ELMERS_DEFAULT_LEVEL_Z				0
#define DC_ELMERS_DEFAULT_OFFSET_X				0
#define DC_ELMERS_DEFAULT_OFFSET_Y				0
#define DC_ELMERS_DEFAULT_OFFSET_Z				0
#define DC_ELMERS_DEFAULT_PALETTE_MATCH			DC_ELMERS_PALETTE_MATCH_NONE
#define DC_ELMERS_DEFAULT_POSITION_QUANTITY_X	1
#define DC_ELMERS_DEFAULT_POSITION_QUANTITY_Y	1
#define DC_ELMERS_DEFAULT_POSITION_QUANTITY_Z	1
#define DC_ELMERS_DEFAULT_ANCHOR_X				DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_ANCHOR_Y				DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_ANCHOR_Z				DC_ELMERS_MODE_TARGET
#define DC_ELMERS_DEFAULT_SCREEN_X				dc_elmers_find_screen_center_x()
#define DC_ELMERS_DEFAULT_SCREEN_Y				dc_elmers_find_screen_center_y()
#define DC_ELMERS_DEFAULT_SCREEN_Z				openborconstant("SCREENPANEL_Z")
#define DC_ELMERS_DEFAULT_SIZE_FACTOR_HEIGHT	1.0
#define DC_ELMERS_DEFAULT_TAG					NULL()
#define DC_ELMERS_DEFAULT_TARGET				getlocalvar("self")

/*
* Member Variable keys.
*/
#define DC_ELMERS_MEMBER_INSTANCE				DC_ELMERS_BASE_ID + 0
#define DC_ELMERS_MEMBER_ATTACKING				DC_ELMERS_BASE_ID + 1
#define DC_ELMERS_MEMBER_BIND_DIRECTION			DC_ELMERS_BASE_ID + 2
#define DC_ELMERS_MEMBER_BLAST					DC_ELMERS_BASE_ID + 3
#define DC_ELMERS_MEMBER_CAN_DAMAGE				DC_ELMERS_BASE_ID + 4
#define DC_ELMERS_MEMBER_CAN_DAMAGE_OLD			DC_ELMERS_BASE_ID + 5
#define DC_ELMERS_MEMBER_DIRECTION				DC_ELMERS_BASE_ID + 6
#define DC_ELMERS_MEMBER_DISABLED				DC_ELMERS_BASE_ID + 7
#define DC_ELMERS_MEMBER_DOUBLE_OFFSET_X		DC_ELMERS_BASE_ID + 8
#define DC_ELMERS_MEMBER_DOUBLE_OFFSET_Y		DC_ELMERS_BASE_ID + 9
#define DC_ELMERS_MEMBER_DOUBLE_OFFSET_Z		DC_ELMERS_BASE_ID + 10
#define DC_ELMERS_MEMBER_ENT					DC_ELMERS_BASE_ID + 11
#define DC_ELMERS_MEMBER_INVERT_X				DC_ELMERS_BASE_ID + 12
#define DC_ELMERS_MEMBER_INVERT_Y				DC_ELMERS_BASE_ID + 13
#define DC_ELMERS_MEMBER_INVERT_Z				DC_ELMERS_BASE_ID + 14
#define DC_ELMERS_MEMBER_LEVEL_X				DC_ELMERS_BASE_ID + 15
#define DC_ELMERS_MEMBER_LEVEL_Y				DC_ELMERS_BASE_ID + 16
#define DC_ELMERS_MEMBER_LEVEL_Z				DC_ELMERS_BASE_ID + 17
#define DC_ELMERS_MEMBER_OFFSET_X				DC_ELMERS_BASE_ID + 18
#define DC_ELMERS_MEMBER_OFFSET_Y				DC_ELMERS_BASE_ID + 19
#define DC_ELMERS_MEMBER_OFFSET_Z				DC_ELMERS_BASE_ID + 20
#define DC_ELMERS_MEMBER_PALETTE_MATCH			DC_ELMERS_BASE_ID + 21
#define DC_ELMERS_MEMBER_POSITION_QUANTITY_X	DC_ELMERS_BASE_ID + 22
#define DC_ELMERS_MEMBER_POSITION_QUANTITY_Y	DC_ELMERS_BASE_ID + 23
#define DC_ELMERS_MEMBER_POSITION_QUANTITY_Z	DC_ELMERS_BASE_ID + 24
#define DC_ELMERS_MEMBER_ANCHOR_X				DC_ELMERS_BASE_ID + 25
#define DC_ELMERS_MEMBER_ANCHOR_Y				DC_ELMERS_BASE_ID + 26
#define DC_ELMERS_MEMBER_ANCHOR_Z				DC_ELMERS_BASE_ID + 27
#define DC_ELMERS_MEMBER_SIZE_FACTOR_HEIGHT		DC_ELMERS_BASE_ID + 28
#define DC_ELMERS_MEMBER_SIZE_FACTOR_WIDTH		DC_ELMERS_BASE_ID + 29
#define DC_ELMERS_MEMBER_TAG					DC_ELMERS_BASE_ID + 30
#define DC_ELMERS_MEMBER_TARGET					DC_ELMERS_BASE_ID + 31
#define DC_ELMERS_MEMBER_THE_END				32				// Should always be last, with a value one higher than previous key ID.

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
#define dc_elmers_get_instance()		dc_instance_get(DC_ELMERS_BASE_ID)
#define dc_elmers_set_instance(value)	dc_instance_set(DC_ELMERS_BASE_ID, value)
#define dc_elmers_reset_instance()		dc_instance_reset(DC_ELMERS_BASE_ID, DC_ELMERS_MEMBER_THE_END)
#define dc_elmers_free_instance()		dc_instance_free(DC_ELMERS_BASE_ID, DC_ELMERS_MEMBER_THE_END)
#define dc_elmers_dump_instance()		dc_instance_dump(DC_ELMERS_BASE_ID, DC_ELMERS_MEMBER_THE_END)
#define dc_elmers_export_instance()		dc_instance_export(DC_ELMERS_BASE_ID, DC_ELMERS_MEMBER_THE_END)
#define dc_elmers_import_instance()		dc_instance_import(DC_ELMERS_BASE_ID, DC_ELMERS_MEMBER_THE_END)
#define dc_elmers_free_export()			dc_instance_free_export(DC_ELMERS_BASE_ID, DC_ELMERS_MEMBER_THE_END)

/*
* Misc hard code values
*/ 
#define DC_ELMERS_DRAWMETHOD_SCALE_MAX_X	256
#define DC_ELMERS_DRAWMETHOD_SCALE_MAX_Y	256

/*
* Misc Function macros
*/ 
#define dc_elmers_find_screen_center_x() openborvariant("xpos") + (openborvariant("hresolution") / 2)
#define dc_elmers_find_screen_center_y() openborvariant("ypos") + (openborvariant("vresolution") / 2)
#define dc_elmers_get_member_targets_opponent() get_entity_property(dc_elmers_get_member_target(),"opponent")

#endif // !DC_ELMERS_CONFIG