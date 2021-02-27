#include "data/scripts/dc_instance/config.h"

#import "data/scripts/dc_instance/operation.c"

/*
* Export
* 
* Most DC libraries rely on local vars for
* simplicity and efficiency. This also
* intentionally confines the library to
* a local scope so we never have to worry
* about conflicts outside of the current
* script.
*
* Exporting provides us a means to handle
* situations where we want to pass information
* from one scope to another.
*
* When exporting, we make a global copy of
* all the library's member variables. To 
* import into another scope, we just reverse 
* the process and then delete the globals.
*/

/*
* Caskey, Damon V.
* 2018-11-28
*
* Export instance members to global scope. 
*/ 
void dc_instance_export(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	void value;

	/* Get instance. */
	instance = dc_instance_get(base_id);

	/* 
	* Loop from 0 to end count of instance variables.
	* Copy each member to a global var with same
	* identifier.
	*/
	for (i = 0; i < the_end; i++)
	{		
		id = instance + base_id + i;
		
		value = getlocalvar(id);

		setglobalvar(id, value);
	}
}

/* 
* Caskey, Damon V.
* 2018-11-28
*
* Import an exported instance.
*/ 
void dc_instance_import(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	void value;

	// Get instance.
	instance = dc_instance_get(base_id);

	/*
	* Loop from 0 to end count of instance variables.
	* Copy each global var to local var (member) with 
	* same identifier.
	*/
	for (i = 0; i < the_end; i++)
	{
		id = instance + base_id + i;
		
		value = getglobalvar(id);
		
		setlocalvar(id, value);
	}
}

/* 
* Caskey, Damon V.
* 2018-11-22
*
* Destroy the current instance export.
*/ 
void dc_instance_free_export(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_instance_get(base_id);

	/*
	* Loop from 0 to end count of instance variables.
	* Clear each global with matched ID along the
	* way.
	*/
	for (i = 0; i < the_end; i++)
	{		
		id = instance + base_id + i;

		setglobalvar(id, NULL());
	}
}