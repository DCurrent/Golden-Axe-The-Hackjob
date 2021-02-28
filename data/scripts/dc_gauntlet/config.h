#ifndef DC_GAUNTLET_CONFIG
#define DC_GAUNTLET_CONFIG 1

#include "data/scripts/dc_instance/main.c"

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_GAUNTLET_BASE_ID	 "dcgaun"

// Base values
#define DC_GAUNTLET_DRAWMETHOD_SCALE_MAX_X			256
#define DC_GAUNTLET_DRAWMETHOD_SCALE_MAX_Y			256

// Options.
#define DC_GAUNTLET_INVERT_DIRECTION				1
#define DC_GAUNTLET_INVERT_DISABLED					0

#define DC_GAUNTLET_INITIAL_POSITION_ENT			0
#define DC_GAUNTLET_INITIAL_POSITION_LEVEL			1
#define DC_GAUNTLET_INITIAL_POSITION_SCREEN			2

#define DC_GAUNTLET_PROJECTILE_STATIONARY_DISABLED	0
#define DC_GAUNTLET_PROJECTILE_STATIONARY_ENABLED	1

#define DC_GAUNTLET_PROJECTILE_PATH_AIR				0
#define DC_GAUNTLET_PROJECTILE_PATH_GROUND			1

// Default values.
#define DC_GAUNTLET_DEFAULT_INSTANCE				0
#define	DC_GAUNTLET_DEFAULT_AUTOKILL				0
#define	DC_GAUNTLET_DEFAULT_DIRECTION_ADJUST		openborconstant("DIRECTION_ADJUST_SAME")
#define DC_GAUNTLET_DEFAULT_ENT						getlocalvar("self")
#define	DC_GAUNTLET_DEFAULT_INITIAL_POSITION		DC_GAUNTLET_INITIAL_POSITION_ENT
#define DC_GAUNTLET_DEFAULT_INVERT_X				DC_GAUNTLET_INVERT_DIRECTION
#define DC_GAUNTLET_DEFAULT_INVERT_Y				DC_GAUNTLET_INVERT_DISABLED
#define DC_GAUNTLET_DEFAULT_INVERT_Z				DC_GAUNTLET_INVERT_DISABLED
#define DC_GAUNTLET_DEFAULT_MAP						0
#define DC_GAUNTLET_DEFAULT_MODEL_NAME				"knife"
#define DC_GAUNTLET_DEFAULT_OFFSET_X				0
#define DC_GAUNTLET_DEFAULT_OFFSET_Y				0
#define DC_GAUNTLET_DEFAULT_OFFSET_Z				0
#define DC_GAUNTLET_DEFAULT_PROJECTILE_DIRECTION	NULL()
#define DC_GAUNTLET_DEFAULT_PROJECTILE_PATH			DC_GAUNTLET_PROJECTILE_PATH_AIR
#define DC_GAUNTLET_DEFAULT_PROJECTILE_RELATIVE		0
#define DC_GAUNTLET_DEFAULT_PROJECTILE_STATIONARY	DC_GAUNTLET_PROJECTILE_STATIONARY_DISABLED
#define DC_GAUNTLET_DEFAULT_PROJECTILE_TYPE			openborconstant("PROJECTILE_TYPE_KNIFE")
#define DC_GAUNTLET_DEFAULT_SPAWN					getlocalvar("self")
#define DC_GAUNTLET_DEFAULT_TARGET					getlocalvar("self")

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_GAUNTLET_MEMBER_AUTOKILL					DC_GAUNTLET_BASE_ID + 0
#define DC_GAUNTLET_MEMBER_DIRECTION_ADJUST			DC_GAUNTLET_BASE_ID + 1
#define DC_GAUNTLET_MEMBER_ENT						DC_GAUNTLET_BASE_ID + 2
#define DC_GAUNTLET_MEMBER_INITIAL_POSITION			DC_GAUNTLET_BASE_ID + 3
#define DC_GAUNTLET_MEMBER_INVERT_X					DC_GAUNTLET_BASE_ID + 4
#define DC_GAUNTLET_MEMBER_INVERT_Y					DC_GAUNTLET_BASE_ID + 5
#define DC_GAUNTLET_MEMBER_INVERT_Z					DC_GAUNTLET_BASE_ID + 6
#define DC_GAUNTLET_MEMBER_MAP						DC_GAUNTLET_BASE_ID + 7
#define DC_GUANTLET_MEMBER_MODEL_NAME				DC_GAUNTLET_BASE_ID + 8
#define DC_GAUNTLET_MEMBER_OFFSET_X					DC_GAUNTLET_BASE_ID + 9
#define DC_GAUNTLET_MEMBER_OFFSET_Y					DC_GAUNTLET_BASE_ID + 10
#define DC_GAUNTLET_MEMBER_OFFSET_Z					DC_GAUNTLET_BASE_ID + 11
#define DC_GAUNTLET_MEMBER_PROJECTILE_DIRECTION		DC_GAUNTLET_BASE_ID + 12
#define DC_GAUNTLET_MEMBER_PROJECTILE_RELATIVE		DC_GAUNTLET_BASE_ID + 13
#define DC_GAUNTLET_MEMBER_PROJECTILE_STATIONARY	DC_GAUNTLET_BASE_ID + 14
#define DC_GAUNTLET_MEMBER_PROJECTILE_TYPE			DC_GAUNTLET_BASE_ID + 15
#define DC_GAUNTLET_MEMBER_SPAWN					DC_GAUNTLET_BASE_ID + 16
#define DC_GAUNTLET_MEMBER_THE_END					17			// Should always last, with a value one higher than previous key ID.

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
#define dc_gauntlet_get_instance()			dc_instance_get(DC_GAUNTLET_BASE_ID)
#define dc_gauntlet_set_instance(value)		dc_instance_set(DC_GAUNTLET_BASE_ID, value)
#define dc_gauntlet_reset_instance()		dc_instance_reset(DC_GAUNTLET_BASE_ID, DC_GAUNTLET_MEMBER_THE_END)
#define dc_gauntlet_free_instance()			dc_instance_free(DC_GAUNTLET_BASE_ID, DC_GAUNTLET_MEMBER_THE_END)
#define dc_gauntlet_dump_instance()			dc_instance_dump(DC_GAUNTLET_BASE_ID, DC_GAUNTLET_MEMBER_THE_END)
#define dc_gauntlet_export_instance()		dc_instance_export(DC_GAUNTLET_BASE_ID, DC_GAUNTLET_MEMBER_THE_END)
#define dc_gauntlet_import_instance()		dc_instance_import(DC_GAUNTLET_BASE_ID, DC_GAUNTLET_MEMBER_THE_END)
#define dc_gauntlet_free_export()			dc_instance_free_export(DC_GAUNTLET_BASE_ID, DC_GAUNTLET_MEMBER_THE_END)

#endif // !DC_GAUNTLET_CONFIG