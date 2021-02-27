#include "data/scripts/dc_fidelity/config.h"

#import "data/scripts/dc_fidelity/sound_config.c"
#import "data/scripts/dc_fidelity/category.c"

// Caskey, Damon V.
// 2018-10-23
//
// Load a sound file and place its sample ID with designated category 
// and type into the sound array for later use.
void dc_fidelity_setup(char category, int type, char file)
{
	void category_list;	// Key - Category, Value - Sound types array.
	void type_list;		// Key - Sound Type, Value - Sound index array.
	void index_list;	// Key - Numeric, Value - Sound file index.
	int  sample_id;		// Sample ID loaded to element.
	
	int size;	// Array size.
	int i;		// Loop index.

	// Get the category list array.
	category_list = dc_fidelity_get_member_category_list();

	// Initialize array if it doesn't exist.
	if (!category_list)
	{
		// Create the array.
		category_list = array(0);

		// Store pointer to array in a globalvar for
		// future access.
		dc_fidelity_set_member_category_list(category_list);
	}

	// Get array of sound types for a category.
	type_list = get(category_list, category);

	// Initialize array if it doesn't exist.
	if (!type_list)
	{
		// Create the array.
		type_list = array(0);

		// Store pointer to array in an element of
		// the parent array.
		set(category_list, category, type_list);
	}

	// Get array of sound indexes for a sound type.
	index_list = get(type_list, type);

	// Initialize array if it doesn't exist.
	if (!index_list)
	{
		// Create the array.
		index_list = array(0);

		// Store pointer to array in an element of
		// the parent array.
		set(type_list, type, index_list);
	}

	// Get the array size, we can use this as
	// the index since we want to add an element.
	size = size(index_list);

	// Load the sample and get ID.
	sample_id	= loadsample(file);

	// Add new array element and populate its
	// value with sample ID.
	add(index_list, size, sample_id);

	if (DC_FIDELITY_LOG & DC_FIDELITY_LOG_LOAD)
	{
		// Output to the log.
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