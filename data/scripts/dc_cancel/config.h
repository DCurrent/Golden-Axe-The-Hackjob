#include "data/scripts/dc_instance/main.c"

#ifndef DC_CANCEL_CONFIG
#define DC_CANCEL_CONFIG 1

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_CANCEL_BASE_ID	"dconhit"

/* Boolean flags. */
#define DC_CANCEL_FLAG_FALSE       0
#define DC_CANCEL_FLAG_TRUE        1

/* Defaults */
#define DC_CANCEL_DEFAULT_ALLOW_IDLE_ANIMATION			-1 // -1 No animation. 
#define DC_CANCEL_DEFAULT_ENTITY						getlocalvar("self")  

/* Statics */
#define DC_CANCEL_GAME_SPEED 200 // 

/* Variable keys. */
#define DC_CANCEL_MEMBER_ALLOW_IDLE_ANIMATION	DC_CANCEL_BASE_ID + 0
#define DC_CANCEL_MEMBER_ENT				DC_CANCEL_BASE_ID + 1

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
#define dc_cancel_get_instance()		dc_instance_get(DC_CANCEL_BASE_ID)
#define dc_cancel_set_instance(value)	dc_instance_set(DC_CANCEL_BASE_ID, value)
#define dc_cancel_reset_instance()		dc_instance_reset(DC_CANCEL_BASE_ID, DC_CANCEL_MEMBER_THE_END)
#define dc_cancel_free_instance()		dc_instance_free(DC_CANCEL_BASE_ID, DC_CANCEL_MEMBER_THE_END)
#define dc_cancel_dump_instance()		dc_instance_dump(DC_CANCEL_BASE_ID, DC_CANCEL_MEMBER_THE_END)
#define dc_cancel_export_instance()		dc_instance_export(DC_CANCEL_BASE_ID, DC_CANCEL_MEMBER_THE_END)
#define dc_cancel_import_instance()		dc_instance_import(DC_CANCEL_BASE_ID, DC_CANCEL_MEMBER_THE_END)
#define dc_cancel_free_export()			dc_instance_free_export(DC_CANCEL_BASE_ID, DC_CANCEL_MEMBER_THE_END)

#endif
