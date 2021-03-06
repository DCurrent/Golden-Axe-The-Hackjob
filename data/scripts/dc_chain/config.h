#include "data/scripts/dc_instance/main.c"

#ifndef DC_CHAIN_CONFIG
#define DC_CHAIN_CONFIG 1

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_CHAIN_BASE_ID	"dcchain"

/* Static and flag values. */
#define DC_CHAIN_FLAG_FALSE 0
#define DC_CHAIN_FLAG_TRUE	1
#define DC_CHAIN_GAME_SPEED	200 
#define DC_CHAIN_ANIMATION_NONE -1

/* Defaults */
#define DC_CHAIN_DEFAULT_ALLOW_IDLE_ANIMATION	DC_CHAIN_ANIMATION_NONE
#define DC_CHAIN_DEFAULT_ENTITY					getlocalvar("self")  
#define DC_CHAIN_DEFAULT_STUN_ANIMATION_INITIAL	openborconstant("ANI_PAIN2")
#define DC_CHAIN_DEFAULT_STUN_ANIMATION_PAIN	openborconstant("ANI_PAIN3")
#define DC_CHAIN_DEFAULT_STUN_CURRENT			0
#define DC_CHAIN_DEFAULT_STUN_RECOVERY_LAST		0
#define DC_CHAIN_DEFAULT_STUN_RECOVERY_RATE		1
#define DC_CHAIN_DEFAULT_STUN_RECOVERY_DELAY	150
#define DC_CHAIN_DEFAULT_STUN_THRESHOLD			8

/* Member variable keys. */
#define DC_CHAIN_MEMBER_ALLOW_IDLE_ANIMATION	DC_CHAIN_BASE_ID + 0
#define DC_CHAIN_MEMBER_ENTITY					DC_CHAIN_BASE_ID + 1
#define DC_CHAIN_MEMBER_STUN_ANIMATION_INITIAL	DC_CHAIN_BASE_ID + 2
#define DC_CHAIN_MEMBER_STUN_ANIMATION_PAIN		DC_CHAIN_BASE_ID + 3
#define DC_CHAIN_MEMBER_STUN_CURRENT			DC_CHAIN_BASE_ID + 4
#define DC_CHAIN_MEMBER_STUN_RECOVERY_LAST		DC_CHAIN_BASE_ID + 5
#define DC_CHAIN_MEMBER_STUN_RECOVERY_RATE		DC_CHAIN_BASE_ID + 6
#define DC_CHAIN_MEMBER_STUN_RECOVERY_DELAY		DC_CHAIN_BASE_ID + 7
#define DC_CHAIN_MEMBER_STUN_THRESHOLD			DC_CHAIN_BASE_ID + 8

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
#define dc_chain_get_instance()			dc_instance_get(DC_CHAIN_BASE_ID)
#define dc_chain_set_instance(value)	dc_instance_set(DC_CHAIN_BASE_ID, value)
#define dc_chain_reset_instance()		dc_instance_reset(DC_CHAIN_BASE_ID, DC_CHAIN_MEMBER_THE_END)
#define dc_chain_free_instance()		dc_instance_free(DC_CHAIN_BASE_ID, DC_CHAIN_MEMBER_THE_END)
#define dc_chain_dump_instance()		dc_instance_dump(DC_CHAIN_BASE_ID, DC_CHAIN_MEMBER_THE_END)
#define dc_chain_export_instance()		dc_instance_export(DC_CHAIN_BASE_ID, DC_CHAIN_MEMBER_THE_END)
#define dc_chain_import_instance()		dc_instance_import(DC_CHAIN_BASE_ID, DC_CHAIN_MEMBER_THE_END)
#define dc_chain_free_export()			dc_instance_free_export(DC_CHAIN_BASE_ID, DC_CHAIN_MEMBER_THE_END)

#endif
