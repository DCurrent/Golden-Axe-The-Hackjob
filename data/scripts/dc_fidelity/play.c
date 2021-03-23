#include "data/scripts/dc_fidelity/config.h"

#import "data/scripts/dc_fidelity/adjustments.c"
#import "data/scripts/dc_fidelity/category.c"
#import "data/scripts/dc_fidelity/entity.c"
#import "data/scripts/dc_fidelity/global.c"
#import "data/scripts/dc_fidelity/model_name.c"
#import "data/scripts/dc_fidelity/sound_config.c"
#import "data/scripts/dc_fidelity/timed.c"

/* 
* Caskey, Damon V.
* 2018-10-23
*
* Get a sample ID from sound type and the current 
* target entity's model.
*/
int dc_fidelity_get_member_entity_sound(int type)
{
	void ent = NULL();
	char model = "";
	int sample_id = 0;

	/*
	* Get the starting model name of acting entity.
	*/

	ent = dc_fidelity_get_member_entity();

	/*
	* Get model name. If set to auto, get the entity's
	* default model name.
	*/

	model = dc_fidelity_get_member_model_name();

	if (model == DC_FIDELITY_MODEL_NAME_AUTO)
	{
		model = getentityproperty(ent, "defaultmodel");
	}

	/* 
	* Now that we have a model name, run model sound 
	* function to get a sample ID.
	*/
	
	sample_id = dc_fidelity_find_category_sound(model, type);

	/*
	* If we failed to find a sample, then check to see
	* if global category is enabled. if so, we'll look
	* for a sound in the global category.
	*/

	if (sample_id == DC_FIDELITY_SAMPLE_NONE)
	{
		if (dc_fidelity_get_member_global_fallback())
		{
			sample_id = dc_fidelity_find_category_sound(DC_FIDELITY_CATEGORY_GLOBAL, type);
		}		
	}

	return sample_id;
}

/* 
* Caskey, Damon V.
* 2018-10-23
*
* Calculate chance to perform action against current
* chance setting and return result. 
*
* 0 Fail (no).
* 1 Pass (yes).
*/
int dc_fidelity_sound_chance()
{
	float chance = 0.0;
	int percentage = 0;
	int random = 0;

	chance = dc_fidelity_get_member_sound_chance();

	/* Convert chance to whole number percentage. */
	percentage = chance * 100;

	/* 
	* Get random 0-100. If it is equal or
	* less than percentage value, then 
	* this is a "yes". Send true and return.
	*/

	dc_d20_set_instance(dc_instance_dependency_get(DC_FIDELITY_BASE_ID));
	
	dc_d20_set_range_max(100);
	random = dc_d20_random_int();
	
	if (percentage >= random)
	{
		return 1;
	}

	return 0;
}

/* 
* Caskey, Damon V.
* 2018-10-23
*
* Get a sample ID from sound type and a known category.
*/
int dc_fidelity_find_category_sound(char category, int type)
{
	void ent = NULL();				// Target entity.
	int result = 0;					// Sound index.
	void category_list = NULL();	// Array of categories (usually models) array.
	void type_list = NULL();		// Sound types array.
	void index_list  = NULL();		// Sound indexes array.
	int upper_bound = 0;			// Size of array.

	/* 
	* Get the cateogry list array.
	*
	* If we can't find a category list array, then
	* there's nothing else we can do, so exit.
	*/

	category_list = dc_fidelity_get_member_category_list();

	if (!category_list)
	{
		return DC_FIDELITY_SAMPLE_NONE;
	}

	/*
	* We use a blank category. If we try, the
	* native get() function fails and shuts down. 
	* Let's handle blanks here by falling back to 
	* a global default category.
	*/

	if (typeof(category) == openborconstant("VT_EMPTY"))
	{
		/* Logging */
		if (DC_FIDELITY_LOG_CATEGORY_MISSING)
		{
			log("\n\n");
			log("Error: " + DC_FIDELITY_BASE_ID);
			log("\n\t Missing category.");
			log("\n\t dc_fidelity_find_category_sound(category: " + category + ", type: " + type + ")");
			log("\n");
		}

		/* Fall back to global category. */
		if (DC_FIDELITY_DEFAULT_GLOBAL_FALLBACK)
		{
			category = DC_FIDELITY_CATEGORY_GLOBAL;
		}
	}	

	/*
	* Now use the category value as element key
	* to get an element value from category list. 
	* Each category list element is a pointer to 
	* an array of types. 
	* 
	* It's possible the category element we are 
	* looking for doesn't exist. If that's the 
	* case, the native get() function returns a 
	* NULL(). We'll exit and return no sample. 
	*/

	type_list = get(category_list, category);
		
	if (!type_list)
	{
		if (DC_FIDELITY_LOG_CATEGORY_TYPE_NOT_FOUND)
		{
			log("\n\n");
			log("Error: " + DC_FIDELITY_BASE_ID);
			log("\n\t Entry not found in category list.");
			log("\n\t dc_fidelity_find_category_sound(category: " + category + ", type: " + type + ")");
			log("\n");
		}

		return DC_FIDELITY_SAMPLE_NONE;
	}

	/* 
	* Use the type value as element key to get
	* an element value from type list. Each type
	* list element is a pointer to an array of
	* sound sample IDs.
	*
	* We'll send the sample list on to our sound
	* selection function. It will select a single 
	* item from the sample list and send us the 
	* sample ID, which we then return.
	*/

	index_list = get(type_list, type);

	result = dc_fidelity_select_sample_id(index_list);

	return result;
}


/* 
* Caskey, Damon V.
* 2018-10-23
*
* Get a sound index (sample ID) from a sound indexes array. 
*/
int dc_fidelity_select_sample_id(void index_list)
{
	int result;
	int size;
	int element;

	/* 
	* If there's no valid array of sound sample 
	* we can't do anything else.
	*/
	if (!index_list)
	{
		return DC_FIDELITY_SAMPLE_NONE;
	}

	/* 
	* If element is set to random, then get a 
	* random item from the available range of 
	* array elements.
	*/
	element = dc_fidelity_get_member_sound_element();
	
	if (element == DC_FIDELITY_INDEX_RANDOM)
	{
		/*
		* Set up the random library. 
		* 
		* Then we get the size of sound sample 
		* array. Then we subtract 1 to compensate 
		* for 0 indexing and use the result as the
		* upper bound for random range.
		* 
		* Afterward, we get a random number from 0 to
		* upper bound, and assign it to element key.
		*/

		dc_d20_set_instance(dc_instance_dependency_get(DC_FIDELITY_BASE_ID));

		size = size(index_list);
		size--;

		dc_d20_set_range_max(size);		

		element = dc_d20_random_int();
	}

	/*
	* Use the element key to get and return an index 
	* from the array of sound indexes.
	*/
	result = get(index_list, element);
	
	return result;
}

/*
* Caskey, Damon V.
* 2018-10-14
*
* Play requested sample on random chance 
* with X axis based stereo.
*
* Returns channel used or DC_FIDELITY_SAMPLE_NONE on failure.
*/
int dc_fidelity_quick_play(int type)
{
	int		sample_id;		// Sample ID to play.

	/* If random chance doesn't pass, exit now. */
	if (!dc_fidelity_sound_chance())
	{
		return;
	}

	/*
	* Get a sample ID, then send to auto balance 
	* playback function and return result.
	*/
	
	sample_id = dc_fidelity_get_member_entity_sound(type);

	return dc_fidelity_play_balanced(sample_id);
}

/* 
* Caskey, Damon V.
* 2019-04-20
*
* Similar to quick play, but play the selected sound
* with a delay by sending it to a timed list.
*/
void dc_fidelity_timed_play(int type, int delay)
{
	int		sample_id;		// Sample ID to play.

	/* If random chance doesn't pass, exit now. */
	if (!dc_fidelity_sound_chance())
	{
		return;
	}

	/*
	* Get a sample ID, then send it to timed
	* list set up for delayed playback.
	*/
	
	sample_id = dc_fidelity_get_member_entity_sound(type);
	
	dc_fidelity_timed_setup(sample_id, delay);
}

/*
* Caskey, Damon V.
* 2019-04-20 (offloading from quick_play)
*
* Play sample with auto balance.
* Returns channel used or DC_FIDELITY_SAMPLE_NONE on failure.
*/
int dc_fidelity_play_balanced(int sample_id)
{
	void ent;
	float pos_x;

	int volume_left;
	int volume_right;

	/* 
	* Get any volume adjustment settings.
	*/
	volume_left = dc_fidelity_get_member_sound_volume_main_left();
	volume_right = dc_fidelity_get_member_sound_volume_main_right();

	/*
	* Get entity X axis position. If there's no entity
	* we use a default value. 
	*/

	ent = dc_fidelity_get_member_entity();

	if (typeof(ent) == openborconstant("VT_PTR"))
	{
		pos_x = get_entity_property(ent, "position_x");
	}
	else
	{
		/* Logging */
		if (DC_FIDELITY_LOG_BALANCE_INVALID_ENTITY)
		{
			log("\n\n");
			log("Error: " + DC_FIDELITY_BASE_ID);
			log("\n\t Entry not found in category list.");
			log("\n\t dc_fidelity_play_balanced(sample_id: " + sample_id + ")");
			log("\n");
		}

		/* Apply default position. */
		pos_x = DC_FIDELITY_DEFAULT_SOUND_LOCATION_POS_X;
	}	

	/*
	* If auto balance is enabled, we run the left and right
	* auto balance functions to adjust volume of left/right
	* channels based on X axis position. 
	*/
	if (dc_fidelity_get_member_sound_location_balance())
	{
		volume_left = dc_fidelity_auto_balance_volume_left(pos_x, volume_left);
		volume_right = dc_fidelity_auto_balance_volume_right(pos_x, volume_right);	
	}

	/* 
	* Send final channel volumes and sample ID to the sound
	* player function. 
	*/
	return dc_fidelity_playsample(sample_id, volume_left, volume_right);
}

/*
* Caskey, Damon V.
* 2018-10-23
* 
* Wrapper for the native OpenBOR playsample() function. Gets any
* leftover config values before playing sound and attempts to
* validate the sample ID.
* 
* Returns channel if sample plays, DC_FIDELITY_SAMPLE_NONE otherwise.
*/
int dc_fidelity_playsample(int sample_id, int volume_left, int volume_right)
{
	int priority;
	int speed;
	int loop;

	/*  
	* Is sample ID a positive integer? Otherwise fail. There's no 
	* way to know for certain if a sample ID is valid, but all valid 
	* sample IDs are positive integers.
	*/

	if (typeof(sample_id) != openborconstant("VT_INTEGER"))
	{
		return DC_FIDELITY_SAMPLE_NONE;
	}

	if (sample_id < 0)
	{
		return DC_FIDELITY_SAMPLE_NONE;
	}

	/*
	* Run the native play function with required values and return
	* the result (channel ID used to play sound). 
	* 
	* - loop: If true the sound loops until stopped.
	* - priority: Higher priority wins if there is a channel 
	*	conflict. Normally not an issue since channels are delegated  as needed from
	*	a pool of (at time of writing) 256.
	* 
	* - Speed: Playing slightly slower or faster changes tone of sound.
	*/

	loop = dc_fidelity_get_member_sound_loop();
	priority = dc_fidelity_get_member_sound_priority();
	speed = dc_fidelity_get_member_sound_speed();
	
	return playsample(sample_id, priority, volume_left, volume_right, speed, loop);
}

/* Caskey, Damon V.
* 2018-10-23
*
* Check the timed sample que and play any samples
* with an expired time. Generally, you'll want to
* run in updated.c or another periodic event.
*/
void dc_fidelity_play_timed()
{
	void timed_list;
	void timed_sample;
	void ent;
	int time;
	int time_current;
	int sample_id;
	int size;
	int i;
	   
	/*
	* Get the timed que array. If there is no array 
	* then we don't have any timed sounds to worry 
	* about, so just exit.
	*/

	timed_list = dc_fidelity_get_member_timed_list();

	if (timed_list == NULL())
	{
		return;
	}

	/*
	* Get the size of timed que array. If the size
	* is 0, then que is empty. Delete the que array
	* to free memory and exit.
	*/

	size = size(timed_list);

	if (size == 0)
	{
		free(timed_list);
		dc_fidelity_set_member_timed_list(NULL());

		return;
	}

	/*
	* Now loop over the timed que array. Each element
	* of the time que array (timed_list) is a pointer 
	* to an array (timed_sample) that contains information 
	* we need to play the timed sample. 
	*/

	for (i = 0; i < size; i++)
	{
		/*
		* Use the loop cursor as element key to get an 
		* element value from time que array (timed_list). 
		* Each timed_list element is a pointer to an array 
		* of parameters (time_sample) that we need to play 
		* the timed sample.
		* 
		* If there's no valid time_sample pointer, then move 
		* on to next loop iteration.
		*/
		timed_sample = get(timed_list, i);

		if (timed_sample == NULL())
		{
			continue;
		}

		/*
		* Get time that timed_sample is set to play on. We compare 
		* this time to current elapsed time. If elapsed time is 
		* greater, we need to play the sample.
		*/

		time = get(timed_sample, DC_FIDELITY_TIMED_SAMPLE_TIME);

		time_current = openborvariant("elapsed_time");
		
		if (time < time_current)
		{
			/*
			* Get the sample ID and acting entity for the sample.
			* Once we have these values, destroy the timed_sample
			* array, and remove current element from the list
			* of timed samples.
			*/

			sample_id = get(timed_sample, DC_FIDELITY_TIMED_SAMPLE_SAMPLE_ID);
			ent = get(timed_sample, DC_FIDELITY_TIMED_SAMPLE_ENTITY);

			free(timed_sample);
			delete(timed_list, i);

			/*
			* It's possible the timed sample's intended acting 
			* entity is no longer valid. Make sure it's still 
			* alive and in play.
			*/ 

			if (!get_entity_property(ent, "exists"))
			{
				continue;
			}

			if (get_entity_property(ent, "dead"))
			{
				continue;
			}

			/*
			* If we made it this far, we know it's OK to play
			* the sample. Set acting entity to acting entity from
			* timed sample, and run the playing routine.
			*/

			dc_fidelity_set_member_entity(ent);
			dc_fidelity_play_balanced(sample_id);
		}
	}
}

