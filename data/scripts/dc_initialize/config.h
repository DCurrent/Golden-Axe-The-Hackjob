// Dependencies
#include "data/scripts/dc_d20/main.c"
#include "data/scripts/dc_fidelity/main.c"

#ifndef DC_INITIALIZE_CONFIG
#define DC_INITIALIZE_CONFIG 1

// Default values.
#define DC_INITIALIZE_DEFAULT_INSTANCE				0
#define DC_INITIALIZE_DEFAULT_ENT					getlocalvar("self")

// Variable indentifiers.
#define DC_INITIALIZE_MEMBER_INSTANCE				"dcini_0"
#define DC_INITIALIZE_MEMBER_ENT					"dcini_1"
#define DC_INITIALIZE_MEMBER_ALIAS_LIST				"dcini_2"

#define DC_INITIALIZE_FLASH_SIZE_BASE				175

#define DC_INITIALIZE_FLASH_INTENSITY_BASE				100	// Base (100%) intensity value.
#define DC_INITIALIZE_FLASH_INTENSITY_FORCE_MEDIAN		2	// The attack force we consider "normal", i.e where intensity calculates to 100%.
#define DC_INITIALIZE_FLASH_INTENSITY_FORCE_MUTIPLIER	12	// Used as mutiplier for force value after we subjtract DC_INITIALIZE_FLASH_INTENSITY_FORCE_MEDIAN.

#define DC_INITIALIZE_FLASH_INTENSITY_SOUND_MAX	130
#define DC_INITIALIZE_FLASH_INTENSITY_SOUND_MIN	70

#endif // !DC_INITIALIZE
