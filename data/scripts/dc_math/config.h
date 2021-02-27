#ifndef DC_MATH_CONFIG
#define DC_MATH_CONFIG 1

// Dependencies
#include "data/scripts/dc_instance/main.c"

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_MATH_BASE_ID	 "dcmath"

#define DC_MATH_DEFAULT_INSTANCE	0

// Variable keys. Used to identify cross function
// variables used throughout library.
#define DC_MATH_MEMBER_INSTANCE				DC_MATH_BASE_ID + 0
#define DC_MATH_MEMBER_THE_END					1			// Should always last, with a value one higher than previous key ID.



#endif // !DC_MATH_CONFIG
