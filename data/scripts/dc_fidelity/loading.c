#include "data/scripts/dc_fidelity/config.h"

#import "data/scripts/dc_fidelity/sound_config.c"
#import "data/scripts/dc_fidelity/category.c"

/* 
* Caskey, Damon V.
* 2018-10-23
*
* Load a sound file and place its sample ID with designated category 
* and type into the sound array for later use.
*/
void dc_fidelity_setup(char category, int type, char file)
{
	void category_list;	// Key - Category, Value - Sound types array.
	void type_list;		// Key - Sound Type, Value - Sound index array.
	void index_list;	// Key - Numeric, Value - Sound file index.
	int  sample_id;		// Sample ID loaded to element.
	
	int size;	// Array size.
	int i;		// Loop index.

	/* 
	* Get the category list array. 
	* If we don't have an array, initialize a new one.
	*/

	category_list = dc_fidelity_get_member_category_list();
	
	if (!category_list)
	{
		/*
		* Create array and store its pointer in
		* a globalvar for future access.
		*/

		category_list = array(0);
		
		dc_fidelity_set_member_category_list(category_list);
	}

	/* 
	* Get array of sound types for a category. 
	* If we don't have an array, initialize a new one.
	*/

	type_list = get(category_list, category);
	
	if (!type_list)
	{
		/*
		* Create array and store its pointer in
		* a globalvar for future access.
		*/

		type_list = array(0);
		
		set(category_list, category, type_list);
	}

	/* 
	* Get array of sound indexes for a sound type. 
	* If we don't have an array, initialize a new one.
	*/

	index_list = get(type_list, type);
	
	if (!index_list)
	{
		/*
		* Create array and store its pointer in
		* a globalvar for future access.
		*/

		index_list = array(0);
		
		set(type_list, type, index_list);
	}

	/* 
	* Get the array size, we can use this as
	* the index since we want to add an element.
	*/
	size = size(index_list);

	/* 
	* Load the same, then add a new
	* array element and populate its
	* value with the sample ID.
	*/
	
	sample_id = loadsample(file);

	add(index_list, size, sample_id);

	if (DC_FIDELITY_LOG_LOAD)
	{
		/* Output to the log. */
		log("\n Sound sample loaded: ");
		log("\n");
		log("\t");
		log("File:\t\t" + file);
		log("\n");
		log("\t");
		log("Category:\t" + category);
		log("\n");
		log("\t");
		log("Type:\t\t" + type);
		log("\n");
		log("\t");
		log("Index:\t\t" + size);
		log("\n");
		log("\t");
		log("Sample ID:\t" + sample_id);
		log("\n");
	}	
}

/*
* Caskey, Damon V.
* 2018-10-23
*
* Unload sounds and free the arrays we
* used to store sample IDs and lists.
*/
void dc_fidelity_terminate()
{
	
	void category_list = dc_fidelity_get_member_category_list();
	
	/* 
	* Free the category list of sounds.
	* Also frees each type and the type's
	* sound indexes.
	*/
	dc_fidelity_free_category_list(category_list);
}

/*
* Caskey, Damon V.
* 2021-07-03
*
* Unload all categories from the sound
* category list.
*/
void dc_fidelity_free_category_list(void target_list)
{
	/*
	* Set cursor to first element of array.
	* Then iterate through all entries and
	* free each one.
	*/
	
	int target_list_size = size(target_list);
	int i = 0;
	void element_value = NULL();
	void element_key = "";

	log("\n\t Freeing " + target_list_size + " sound categories");

	reset(target_list);

	for (i = 0; i < target_list_size; i++)
	{
		element_key = key(target_list);
		element_value = value(target_list);

		log("\n\t\t Category " + i + ": " + element_key + ", " + element_value);

		if (element_value)
		{
			/*
			* Clear all types for the category.
			*/
			dc_fidelity_free_type_list(element_value);
		}
		else
		{
			log("\t ...category not found.");
		}

		next(target_list);
	}

	log("\n\t Freeing category list");

	free(target_list);
}

/*
* Caskey, Damon V.
* 2021-07-03
*
* Unload all types from a sound category.
*/
void dc_fidelity_free_type_list(void target_list)
{
	/*
	* Set cursor to first element of array.
	* Then iterate through all entries and
	* free each one.
	*/

	

	int target_list_size = size(target_list);
	int i = 0;
	void element_value = NULL();
	void element_key = "";

	log("\n\t\t\t Freeing " + target_list_size + " sound types");

	reset(target_list);

	for (i = 0; i < target_list_size; i++)
	{
		element_key = key(target_list);
		element_value = value(target_list);

		log("\n\t\t\t\t Type " + i + ": " + element_key + ", " + element_value);
		
		if (element_value)
		{
			/* 
			* Clear all sample indexes for the type, then
			* free the type element.
			*/
			dc_fidelity_free_index_list(element_value);			
		}
		else
		{
			log("\t ...type not found.");
		}

		next(target_list);
	}
	

	log("\n\t\t\t Freeing type list");

	free(target_list);	
}

/*
* Caskey, Damon V.
* 2021-07-03
*  
* Unload all samples from a sound type.
*/
void dc_fidelity_free_index_list(void target_list)
{
	/*
	* Set cursor to first element of array.
	* Then iterate through all entries and
	* free each one.
	*/
	
	int target_list_size = size(target_list);
	int i = 0;
	void element_value = NULL();
	void element_key = "";

	log("\n\t\t\t\t\t Freeing " + target_list_size + " sample indexes");

	reset(target_list);

	for (i = 0; i < target_list_size; i++)
	{
		//element_key = key(target_list);
		element_value = get(target_list, i); //value(target_list);

		log("\n\t\t\t\t\t\t Sample " + i + ": " + element_value);

		if (element_value)
		{
			/* 
			* The element value contains an index to sound
			* sample. Unload the sample.
			*/
			unloadsample(element_value);
		}
		else
		{
			log("\t ...sample not found.");
		}

		//next(target_list);
	}
	
	log("\n\t\t\t\t\t Freeing sample index list");

	free(target_list);
	
}

// Caskey, Damon V.
// 2018-10-22
// 
// Test if a sound loaded properly.
void dc_fidelity_loaded_test(char category, int type, int index)
{
	void category_list;	// Key - model, Value - Sound types array.
	void type_list;		// Key - Sound Type, Value - Sound index array.
	void index_list;	// Key - Numeric, Value - Sound file index.
	char id;			// ID key for variables.

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_CATEGORY;

	// Get the category list array.
	category_list = getglobalvar(id);

	// Get array of sound types for a category.
	type_list = get(category_list, category);

	// Get array of sound indexes for a sound type.
	index_list = get(type_list, type);

	// Get array of sound indexes for a sound type.
	index = get(index_list, index);

	log("\n\n dc_fidelity_loaded_test");
	log("\n");
	
	log("\t");
	log("Categories Array: " + category_list);
	log("\n");

	log("\t");
	log("Types Array: " + type_list);
	log("\n");

	log("\t");
	log("Indexes Array: " + index_list);
	log("\n");

	log("\t");
	log("Sound index: " + index);
	log("\n");

	playsample(index, DC_FIDELITY_DEFAULT_SOUND_PRIORITY, DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT, DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT, DC_FIDELITY_DEFAULT_SOUND_SPEED, DC_FIDELITY_DEFAULT_SOUND_LOOP);
}