#include "data/scripts/dc_instance/main.c"

#ifndef DC_EGGBALL_CONFIG
#define DC_EGGBALL_CONFIG 1

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_EGGBALL_BASE_ID	"dcegg"

/* Boolean flags. */
#define DC_EGGBALL_FLAG_FALSE       0
#define DC_EGGBALL_FLAG_TRUE        1

/* Defaults */
#define DC_EGGBALL_DEFAULT_COUNTDOWN_RESET			DC_EGGBALL_FLAG_TRUE
#define DC_EGGBALL_DEFAULT_COUNTDOWN_TIME_CURRENT	0
#define DC_EGGBALL_DEFAULT_COUNTDOWN_TIME_START		10
#define DC_EGGBALL_DEFAULT_INSTANCE 0
#define DC_EGGBALL_DEFAULT_INTERVAL 2500
#define DC_EGGBALL_DEFAULT_NEXT -1

/* Statics */
#define DC_EGGBALL_GAME_SPEED 200 // .

// Variable keys.
#define DC_EGGBALL_MEMBER_INTERVAL			DC_EGGBALL_BASE_ID + 0
#define DC_EGGBALL_MEMBER_INSTANCE			DC_EGGBALL_BASE_ID + 1
#define DC_EGGBALL_MEMBER_NEXT				DC_EGGBALL_BASE_ID + 2
#define DC_EGGBALL_COUNTDOWN_RESET			DC_EGGBALL_BASE_ID + 3
#define DC_EGGBALL_COUNTDOWN_TIME_CURRENT	DC_EGGBALL_BASE_ID + 4
#define DC_EGGBALL_COUNTDOWN_TIME_START		DC_EGGBALL_BASE_ID + 5

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
#define dc_eggball_get_instance()		dc_instance_get(DC_EGGBALL_BASE_ID)
#define dc_eggball_set_instance(value)	dc_instance_set(DC_EGGBALL_BASE_ID, value)
#define dc_eggball_reset_instance()		dc_instance_reset(DC_EGGBALL_BASE_ID, DC_EGGBALL_MEMBER_THE_END)
#define dc_eggball_free_instance()		dc_instance_free(DC_EGGBALL_BASE_ID, DC_EGGBALL_MEMBER_THE_END)
#define dc_eggball_dump_instance()		dc_instance_dump(DC_EGGBALL_BASE_ID, DC_EGGBALL_MEMBER_THE_END)
#define dc_eggball_export_instance()		dc_instance_export(DC_EGGBALL_BASE_ID, DC_EGGBALL_MEMBER_THE_END)
#define dc_eggball_import_instance()		dc_instance_import(DC_EGGBALL_BASE_ID, DC_EGGBALL_MEMBER_THE_END)
#define dc_eggball_free_export()			dc_instance_free_export(DC_EGGBALL_BASE_ID, DC_EGGBALL_MEMBER_THE_END)

#endif
