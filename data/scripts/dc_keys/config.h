#include "data/scripts/dc_instance/main.c"

#ifndef DC_KEYS_CONFIG
#define DC_KEYS_CONFIG 1

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_KEYS_BASE_ID	"dckeys"

/* Static and flag values. */
#define DC_KEYS_FLAG_FALSE 0
#define DC_KEYS_FLAG_TRUE	1

/* Defaults */
#define DC_KEYS_DEFAULT_ENTITY					getlocalvar("self") 

/* Member variable keys. */
#define DC_KEYS_MEMBER_ENTITY					DC_KEYS_BASE_ID + 0

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
#define dc_keys_get_instance()			dc_instance_get(DC_KEYS_BASE_ID)
#define dc_keys_set_instance(value)		dc_instance_set(DC_KEYS_BASE_ID, value)
#define dc_keys_reset_instance()		dc_instance_reset(DC_KEYS_BASE_ID, DC_KEYS_MEMBER_THE_END)
#define dc_keys_free_instance()			dc_instance_free(DC_KEYS_BASE_ID, DC_KEYS_MEMBER_THE_END)
#define dc_keys_dump_instance()			dc_instance_dump(DC_KEYS_BASE_ID, DC_KEYS_MEMBER_THE_END)
#define dc_keys_export_instance()		dc_instance_export(DC_KEYS_BASE_ID, DC_KEYS_MEMBER_THE_END)
#define dc_keys_import_instance()		dc_instance_import(DC_KEYS_BASE_ID, DC_KEYS_MEMBER_THE_END)
#define dc_keys_free_export()			dc_instance_free_export(DC_KEYS_BASE_ID, DC_KEYS_MEMBER_THE_END)

#endif
