#include "data/scripts/dc_instance/config.h"

/*
* Which instance is in use?
*/

char dc_instance_get(char base_id)
{
	char result = DC_INSTANCE_DEFAULT_INSTANCE;
	char instance_key = "";

	/*
	* If there's no key, there is something wrong
	* in the parent library's setup. We could catch 
	* the error and return a default key, but if we 
	* do there will probably be very hard to trace 
	* bugs or conflicts downstream. Let's error out 
	* right here so we know where the problem is.
	*/
	if (typeof(base_id) == openborconstant("VT_EMPTY"))
	{
		shutdown("Error, dc_instance_get:", "Missing base ID from parent library.");
	}

	instance_key = base_id + DC_INSTANCE_DEFAULT_INSTANCE_MEMBER_KEY;

	/*
	* Get the current instance ID. result. If it's
	* blank, we return the default value.
	*/ 
	result = getlocalvar(instance_key);

	if (!result)
	{
		result = DC_INSTANCE_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_instance_set(char base_id, char value)
{
	char instance_key = "";

	/*
	* If there's no key, there is something wrong
	* in the parent library's setup. We could catch
	* the error and return a default key, but if we
	* do there will probably be very hard to trace
	* bugs or conflicts downstream. Let's error out
	* right here so we know where the problem is.
	*/
	if (typeof(base_id) == openborconstant("VT_EMPTY"))
	{
		shutdown("Error, dc_instance_set:", "Missing base ID from parent library.");
	}

	instance_key = base_id + DC_INSTANCE_DEFAULT_INSTANCE_MEMBER_KEY;

	if (value == DC_INSTANCE_DEFAULT_INSTANCE)
	{
		value = NULL();
	}

	setlocalvar(instance_key, value);
}

/*
* Use when sending instance id to dependency, so that the dependency's 
* instance is unique to the library that calls it.
*/
char dc_instance_dependency_get(char base_id)
{
	int result;

	result = base_id + dc_instance_get(base_id);
}

/*
* Caskey, Damon V.
* 2018-11-22
*
* Clears the current instance, effectively resetting
* all values to their defaults.
*/ 
void dc_instance_reset(char base_id, int the_end)
{
	int instance;

	/* Get instance. */
	instance = dc_instance_get(base_id);

	/* Destroy all instance variables. */
	dc_instance_free(base_id, the_end);

	/*
	* If the instance ID isn't default, then restore 
	* it to memory. Either way we now have a clean
	* copy of the current instance.
	*/ 
	if (instance != DC_INSTANCE_DEFAULT_INSTANCE)
	{
		dc_instance_set(base_id, instance);
	}
}

/* Caskey, Damon V.
* 2018-11-22
*
* Destroy the current instance by deleting all
* library variables.
*/ 
void dc_instance_free(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	/* Get instance. */
	instance = dc_instance_get(base_id);

	/* 
	* Loop from 0 to end count of 
	* library members and clear each.
	*/ 
	for (i = 0; i < the_end; i++)
	{
		id = instance + base_id + i;

		setlocalvar(id, NULL());
	}

	/* Now clear the instance variable. */
	dc_instance_set(instance, NULL());
}

/*
* Caskey, Damon V.
* 2018-11-22
*
* Send all library member values to log for debugging.
*/ 
void dc_instance_dump(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	/* Get instance. */
	instance = dc_instance_get(base_id);
	
	/* Log base name and instance. */ 
	log("\n dc_instance_dump: " + base_id + ", " + instance + ", " + the_end);
	log("\n\n " + base_id + " dump:");
	log("\n\t " + "Instance: " + instance);

	/*
	* Loop from 0 to end count of instance variables,
	* then output each key/id and value to the log.
	*/
	for (i = 0; i < the_end; i++)
	{
		id = instance + base_id + i;

		log("\n\t " + id + ": \t");
		log(getlocalvar(id));
	}

	/* Log end point. */
	log("\n End Dump.\n");
}

