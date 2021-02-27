#include "data/scripts/dc_math/config.h"

// Caskey, Damon V.
// 2018-11-29
//
// Return set instance, or default instance if
// set value is non-existing or invalid.
int dc_math_get_instance()
{
	int result;

	// Get instance value.
	result = getlocalvar(DC_MATH_MEMBER_INSTANCE);

	// Value must be a valid integer, or
	// we will use the default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_MATH_DEFAULT_INSTANCE;
	}

	return result;
}

// Caskey, Damon V.
//
// 2018-11-29
// Set instance value. 
void dc_math_set_instance(int value)
{
	// Only set instance value if new value
	// is different from default. No reason to waste
	// the memory on a default value.
	if (value != DC_MATH_DEFAULT_INSTANCE)
	{
		setlocalvar(DC_MATH_MEMBER_INSTANCE, value);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Clears the current instance, effectively resetting
// all values to their defaults.
void dc_math_reset_instance()
{
	int instance;

	// Get instance.
	instance = dc_math_get_instance();

	// Destroy all instance variables.
	dc_math_free_instance();

	// If the instance ID isn't default, then restore 
	// it to memory. Either way we now have a clean
	// copy of the current instance.
	if (instance != DC_MATH_DEFAULT_INSTANCE)
	{
		dc_math_set_instance(instance);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance by deleting all
// library variables.
void dc_math_free_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_math_get_instance();

	// Loop from 0 to end count of library variables.
	for (i = 0; i < DC_MATH_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_MATH_BASE_ID + i;

		// Delete variable.
		setlocalvar(id, NULL());
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Send all library variables to log for debugging.
void dc_math_dump_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_math_get_instance();

	// Log base name and instance.
	log("\n\n " + DC_MATH_BASE_ID + " dump:");
	log("\n\t " + "Instance: " + instance);

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_MATH_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_MATH_BASE_ID + i;

		// Log ID.
		log("\n\t " + id + ": ");

		// Log value.
		log(getlocalvar(id));
	}

	// Log end point.
	log("\n End Dump.\n");
}

// Caskey, Damon V.
// 2018-11-28
//
// Export instance to global vars for other event
// to import.
void dc_math_export_instance()
{
	int instance;
	int i;
	char id;

	void value;

	// Get instance.
	instance = dc_math_get_instance();

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_MATH_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_MATH_BASE_ID + i;

		// Get local (library) value.
		value = getlocalvar(id);

		// Export value to global var.
		setglobalvar(id, value);
	}
}

// Caskey, Damon V.
// 2018-11-28
//
// Import an exported instance.
void dc_math_import_instance()
{
	int instance;
	int i;
	char id;

	void value;

	// Get instance.
	instance = dc_math_get_instance();

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_MATH_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_MATH_BASE_ID + i;

		// Get value
		value = getglobalvar(id);

		// Import value to local (library) var.
		setlocalvar(id, value);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance export.
void dc_math_free_export_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_math_get_instance();

	// Loop from 0 to end count of library variables.
	for (i = 0; i < DC_MATH_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_MATH_BASE_ID + i;

		// Delete the global variable.
		setglobalvar(id, NULL());
	}
}