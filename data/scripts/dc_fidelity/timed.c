#include "data/scripts/dc_fidelity/config.h"
#import "data/scripts/dc_fidelity/entity.c"

// Get
void dc_fidelity_get_member_timed_list()
{
	char id;
	void result;

	// Get id key.
	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_TIMED_LIST;

	result = getglobalvar(id);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_FIDELITY_DEFAULT_TIMED_LIST;
	}

	return result;
}

// Set
void dc_fidelity_set_member_timed_list(void value)
{
	char id;

	// Get id key.
	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_TIMED_LIST;

	// If the value is same as default, then use
	// make sure variable is deleted instead. We fall
	// back to default for empty vars, so may as
	// well save the memory.
	if (value == DC_FIDELITY_DEFAULT_TIMED_LIST)
	{
		value = NULL();
	}

	setglobalvar(id, value);
}

// Caskey, Damon V.
// 2018-10-23
//
// Place sample id and delay time to play later.
void dc_fidelity_timed_setup(int sample_id, int delay)
{
	void timed_list;	// Key - current size, Value - pointer to timed sample array.
	void timed_sample;	// Sample and time  to play. See constants for keys.
	int size;			// Size of timed_list.	
	int time;			// Time to play sample.

	// TIme is current time + requested delay. The check function
	// will play sounds in array when their time <= elapsed time.
	time = openborvariant("elapsed_time") + delay;

	// Let's create an array to carry the time and sample ID.
	timed_sample = array(DC_FIDELITY_TIMED_SAMPLE_ARRAY_SIZE);

	//  Set the sample to play data.
	set(timed_sample, DC_FIDELITY_TIMED_SAMPLE_SAMPLE_ID, sample_id);
	set(timed_sample, DC_FIDELITY_TIMED_SAMPLE_TIME, time);
	set(timed_sample, DC_FIDELITY_TIMED_SAMPLE_ENTITY, dc_fidelity_get_member_entity());

	// Get the timed list array. This array keeps a list
	// of the timed sample arrays we just created.
	timed_list = dc_fidelity_get_member_timed_list();

	// Initialize array if it doesn't exist.
	if (timed_list == NULL())
	{
		// Create the array.
		timed_list = array(0);

		// Store pointer to array in a globalvar for
		// future access.
		dc_fidelity_set_member_timed_list(timed_list);
	}

	// Get the array size, we can use this as
	// the index since we want to add an element.
	size = size(timed_list);

	// Add new array element using and populate its
	// key with pointer to the timed sample array we
	// created earlier.
	add(timed_list, size, timed_sample);

	if (DC_FIDELITY_LOG_TIMED_SETUP)
	{
		// Output to the log.
		log("\n Timed sample loaded: ");
		log("\n");
		log("\t");
		log("List Index:\t" + size);
		log("\n");
		log("\t");
		log("Time:\t\t" + time);
		log("\n");
		log("\t");
		log("Sample ID:\t" + sample_id);
		log("\n");
	}
}


