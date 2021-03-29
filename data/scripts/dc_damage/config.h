#ifndef DC_DAMAGE_CONFIG
#define DC_DAMAGE_CONFIG 1

#include "data/scripts/dc_instance/main.c"

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_DAMAGE_BASE_ID	"dcdam"

/*
* Configuration
*/
#define DC_DAMAGE_PROJECTILE_OFF			openborconstant("BLAST_NONE")
#define DC_DAMAGE_PROJECTILE_THROWN			openborconstant("BLAST_TOSS")	// (OpenBOR uses 2 for its default throw system).
#define DC_DAMAGE_PROJECTILE_SLAM			openborconstant("BLAST_ATTACK")

/*
* Static values
*/
#define DC_DAMAGE_INCOMING_HEIGHT_UPPER 0
#define DC_DAMAGE_INCOMING_HEIGHT_MIDDLE 1
#define DC_DAMAGE_INCOMING_HEIGHT_LOWER 2

#define DC_DAMAGE_DETECT_HEIGHT_UPPER 0.70
#define DC_DAMAGE_DETECT_HEIGHT_MIDDLE 0.3

/*
* Options 
*/
#define DC_DAMAGE_DROP_FORCE_MAX			1000		

#define DC_DAMAGE_LETHALITY_LETHAL			0
#define DC_DAMAGE_LETHALITY_NON_LETHAL		1

/*
* Default values.
*/
#define DC_DAMAGE_DEFAULT_INSTANCE				0
#define DC_DAMAGE_DEFAULT_ANCHOR_X				getlocalvar("self")
#define DC_DAMAGE_DEFAULT_ANCHOR_Y				getlocalvar("self")
#define DC_DAMAGE_DEFAULT_ANCHOR_Z				getlocalvar("self")
#define DC_DAMAGE_DEFAULT_DIRECTION_ADJUST		openborconstant("DIRECTION_ADJUST_OPPOSITE")
#define DC_DAMAGE_DEFAULT_DOL_FORCE				0
#define DC_DAMAGE_DEFAULT_DROP_FORCE			0
#define DC_DAMAGE_DEFAULT_DROP_VELOCITY_X		1.2
#define DC_DAMAGE_DEFAULT_DROP_VELOCITY_Y		3.0
#define DC_DAMAGE_DEFAULT_DROP_VELOCITY_Z		0.0
#define DC_DAMAGE_DEFAULT_ENT					get_entity_property(DC_DAMAGE_DEFAULT_OTHER, "opponent")
#define DC_DAMAGE_DEFAULT_FORCE					0
#define DC_DAMAGE_DEFAULT_LETHALITY				DC_DAMAGE_LETHALITY_LETHAL
#define DC_DAMAGE_DEFAULT_OTHER					getlocalvar("self")
#define DC_DAMAGE_DEFAULT_POSITION_X			NULL()
#define DC_DAMAGE_DEFAULT_POSITION_Y			NULL()
#define DC_DAMAGE_DEFAULT_POSITION_Z			NULL()
#define DC_DAMAGE_DEFAULT_PROJECTILE			DC_DAMAGE_PROJECTILE_OFF
#define DC_DAMAGE_DEFAULT_REACTION_BLOCK_LOWER	openborconstant("ANI_BLOCKPAIN2")
#define DC_DAMAGE_DEFAULT_REACTION_BLOCK_MIDDLE	openborconstant("ANI_BLOCKPAIN2")
#define DC_DAMAGE_DEFAULT_REACTION_BLOCK_UPPER	openborconstant("ANI_BLOCKPAIN")
#define DC_DAMAGE_DEFAULT_REACTION_PAIN_LOWER	openborconstant("ANI_PAIN2")
#define DC_DAMAGE_DEFAULT_REACTION_PAIN_MIDDLE	openborconstant("ANI_PAIN2")
#define DC_DAMAGE_DEFAULT_REACTION_PAIN_UPPER	openborconstant("ANI_PAIN")
#define DC_DAMAGE_DEFAULT_TYPE					openborconstant("ATK_NORMAL")

/*
* Member Variable keys.
*/
#define DC_DAMAGE_MEMBER_ANCHOR_X				DC_DAMAGE_BASE_ID + 0
#define DC_DAMAGE_MEMBER_ANCHOR_Y				DC_DAMAGE_BASE_ID + 1
#define DC_DAMAGE_MEMBER_ANCHOR_Z				DC_DAMAGE_BASE_ID + 2
#define DC_DAMAGE_MEMBER_DIRECTION_ADJUST		DC_DAMAGE_BASE_ID + 3
#define DC_DAMAGE_MEMBER_DOL_FORCE				DC_DAMAGE_BASE_ID + 4
#define DC_DAMAGE_MEMBER_DROP_FORCE				DC_DAMAGE_BASE_ID + 5
#define DC_DAMAGE_MEMBER_DROP_VELOCITY_X		DC_DAMAGE_BASE_ID + 6
#define DC_DAMAGE_MEMBER_DROP_VELOCITY_Y		DC_DAMAGE_BASE_ID + 7
#define DC_DAMAGE_MEMBER_DROP_VELOCITY_Z		DC_DAMAGE_BASE_ID + 8
#define DC_DAMAGE_MEMBER_ENT					DC_DAMAGE_BASE_ID + 9
#define DC_DAMAGE_MEMBER_FORCE					DC_DAMAGE_BASE_ID + 10
#define DC_DAMAGE_MEMBER_LETHALITY				DC_DAMAGE_BASE_ID + 11
#define DC_DAMAGE_MEMBER_OFFSET_X				DC_DAMAGE_BASE_ID + 12
#define DC_DAMAGE_MEMBER_OFFSET_Y				DC_DAMAGE_BASE_ID + 13
#define DC_DAMAGE_MEMBER_OFFSET_Z				DC_DAMAGE_BASE_ID + 14
#define DC_DAMAGE_MEMBER_OTHER					DC_DAMAGE_BASE_ID + 15
#define DC_DAMAGE_MEMBER_PROJECTILE				DC_DAMAGE_BASE_ID + 16
#define DC_DAMAGE_MEMBER_REACTION_BLOCK_LOWER	DC_DAMAGE_BASE_ID + 17
#define DC_DAMAGE_MEMBER_REACTION_BLOCK_MIDDLE	DC_DAMAGE_BASE_ID + 18
#define DC_DAMAGE_MEMBER_REACTION_BLOCK_UPPER	DC_DAMAGE_BASE_ID + 19
#define DC_DAMAGE_MEMBER_REACTION_PAIN_LOWER	DC_DAMAGE_BASE_ID + 20
#define DC_DAMAGE_MEMBER_REACTION_PAIN_MIDDLE	DC_DAMAGE_BASE_ID + 21
#define DC_DAMAGE_MEMBER_REACTION_PAIN_UPPER	DC_DAMAGE_BASE_ID + 22
#define DC_DAMAGE_MEMBER_TYPE					DC_DAMAGE_BASE_ID + 23
#define DC_DAMAGE_MEMBER_THE_END				24

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
#define dc_damage_get_instance()		dc_instance_get(DC_DAMAGE_BASE_ID)
#define dc_damage_set_instnace(value)	dc_instance_set(DC_DAMAGE_BASE_ID, value)
#define dc_damage_reset_instance()		dc_instance_reset(DC_DAMAGE_BASE_ID, DC_DAMAGE_MEMBER_THE_END)
#define dc_damage_free_instance()		dc_instance_free(DC_DAMAGE_BASE_ID, DC_DAMAGE_MEMBER_THE_END)
#define dc_damage_dump_instance()		dc_instance_dump(DC_DAMAGE_BASE_ID, DC_DAMAGE_MEMBER_THE_END)
#define dc_damage_export_instance()		dc_instance_export(DC_DAMAGE_BASE_ID, DC_DAMAGE_MEMBER_THE_END)
#define dc_damage_import_instance()		dc_instance_import(DC_DAMAGE_BASE_ID, DC_DAMAGE_MEMBER_THE_END)
#define dc_damage_free_export()			dc_instance_free_export(DC_DAMAGE_BASE_ID, DC_DAMAGE_MEMBER_THE_END)

#endif // !DC_DAMAGE_CONFIG

