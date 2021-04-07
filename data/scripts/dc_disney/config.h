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
#define DC_DISNEY_DEFAULT_ENT			getlocalvar("self")
#define DC_DISNEY_DEFAULT_ANIMATION		openborconstant("ANI_IDLE")
#define DC_DISNEY_DEFAULT_TIME_DELAY			1000

/*
* Member Variable keys.
*/

#define DC_DISNEY_MEMBER_ANIMATION		DC_DISNEY_BASE_ID + 0
#define DC_DISNEY_MEMBER_ENT			DC_DISNEY_BASE_ID + 1
#define DC_DISNEY_MEMBER_TIME_DELAY			DC_DISNEY_BASE_ID + 2
#define DC_DISNEY_MEMBER_THE_END		3			// Should always be last, with a value one higher than previous key ID.

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

