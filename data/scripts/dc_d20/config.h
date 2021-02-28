#ifndef DC_D20_CONFIG
#define DC_D20_CONFIG  1

#include "data/scripts/dc_instance/main.c"

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep 
* it short.
**/
#define DC_D20_BASE_ID		"dcd20"

/** Operation flags
*
* These values control general operation and
* default behaviors. You should leave them
* alone unles you really know what you're doing.
**/

/** Operation flags **/
#define DC_D20_ALLOW_NEGATIVE_TRUE		1
#define DC_D20_ALLOW_NEGATIVE_FALSE		0

/** Default values **/
#define DC_D20_DEFAULT_INSTANCE			0
#define DC_D20_DEFAULT_ALLOW_NEGATIVE	DC_D20_ALLOW_NEGATIVE_FALSE
#define DC_D20_DEFAULT_RANGE_MIN		0
#define DC_D20_DEFAULT_RANGE_MAX		100

/** Static values **/
#define DC_D20_RADIUS_MUTIPLIER		0.02
#define DC_D20_PI					3.14159265359

/** Array keys **/
#define DC_D20_RADIUS_RETURN_SIZE	2
#define DC_D20_RADIUS_RETURN_X		0
#define DC_D20_RADIUS_RETURN_Y		1

/** Variable keys **/
#define DC_D20_MEMBER_ALLOW_NEGATIVE	DC_D20_BASE_ID + 0
#define DC_D20_MEMBER_LOCKED_LOWER		DC_D20_BASE_ID + 1
#define DC_D20_MEMBER_LOCKED_UPPER		DC_D20_BASE_ID + 2
#define DC_D20_MEMBER_RANGE_MIN			DC_D20_BASE_ID + 3
#define DC_D20_MEMBER_RANGE_MAX			DC_D20_BASE_ID + 4
#define DC_D20_MEMBER_THE_END			5		// Should always last, with a value one higher than previous key ID.	

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
#define dc_d20_get_instance()		dc_instance_get(DC_D20_BASE_ID)
#define dc_d20_set_instance(value)	dc_instance_set(DC_D20_BASE_ID, value)
#define dc_d20_reset_instance()		dc_instance_reset(DC_D20_BASE_ID, DC_D20_MEMBER_THE_END)
#define dc_d20_free_instance()		dc_instance_free(DC_D20_BASE_ID, DC_D20_MEMBER_THE_END)
#define dc_d20_dump_instance()		dc_instance_dump(DC_D20_BASE_ID, DC_D20_MEMBER_THE_END)
#define dc_d20_export_instance()	dc_instance_export(DC_D20_BASE_ID, DC_D20_MEMBER_THE_END)
#define dc_d20_import_instance()	dc_instance_import(DC_D20_BASE_ID, DC_D20_MEMBER_THE_END)
#define dc_d20_free_export()		dc_instance_free_export(DC_D20_BASE_ID, DC_D20_MEMBER_THE_END)

#endif // DC_D20_CONFIG
