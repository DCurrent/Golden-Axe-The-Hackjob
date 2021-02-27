#include "data/scripts/dc_fidelity/config.h"

// User config. These functions allow a module author to 
// temporarily override the default configuration as 
// needed. We use localvars, so any override is local 
// to the event that runs it and reset when the event
// is destroyed.

// Unless otherwise noted, any setting that does not 
// have a user value will fall back to its default 
// as defined in config.h

// Chance determines likelihood of sound function actually
// playing anything.
//
// 0.0 = Never
// 0.5 = 50%
// 1.0 = Always.
void dc_fidelity_set_member_sound_chance(float value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_CHANCE;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_CHANCE == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

void dc_fidelity_get_member_sound_chance()
{
	void result;
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_CHANCE;

	result = getlocalvar(id);

	if (!result)
	{
		result = DC_FIDELITY_DEFAULT_SOUND_CHANCE;
	}
	
	return result;
}

// Element is the target item in sound indexes array. 
// Defaults to random, which causes a random element
// to be selected from all indexes available for
// a selected sound type.
void dc_fidelity_set_member_sound_element(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_SPEED;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_SPEED == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_element()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_ELEMENT;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_INDEX_RANDOM;
	}

	return result;
}

// Enables auto fade. As a location moves lateraly
// in relation to screen position, volume is adjusted
// to create a distance based fade effect.
void dc_fidelity_set_member_sound_location_fade(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_LOCATION_FADE;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_LOCATION_FADE == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_location_fade()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_LOCATION_FADE;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_LOCATION_FADE;
	}

	return result;
}

// Sound looping on playback.
void dc_fidelity_set_member_sound_loop(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_LOOP;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_LOOP == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_loop()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_LOOP;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_LOOP;
	}

	return result;
}

// Priority of sound when played on same channel.
void dc_fidelity_set_member_sound_priority(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_PRIORITY;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_PRIORITY == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_priority()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_PRIORITY;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_PRIORITY;
	}

	return result;
}

// Speed is the playback speed for sounds before any auto
// adjustments are made. Generally, slower playback speeds
// result in a lower pitch. As an example of this effect, 
// OpenBOR’s native sound effect system plays hit impact 
// sounds at lower speeds as greater damage is inflicted. 
void dc_fidelity_set_member_sound_speed(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_SPEED;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_SPEED == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Get specified speed, or default if not available.
int dc_fidelity_get_member_sound_speed()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_SPEED;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_SPEED;
	}

	return result;
}

// Volume is the intitial left and right channel 
// playback volume before any auto adjustments
// are made. 
void dc_fidelity_set_member_sound_volume_main_left(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_VOLUME_MAIN_LEFT;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_volume_main_left()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_VOLUME_MAIN_LEFT;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_VOLUME_LEFT;
	}

	// Keep us level with engine limit. See config.c for details.
	if (result > DC_FIDELITY_ENGINE_MAX_VOLUME)
	{
		result = DC_FIDELITY_ENGINE_MAX_VOLUME;
	}

	return result;
}

void dc_fidelity_set_member_sound_volume_main_right(int value)
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_VOLUME_MAIN_RIGHT;

	// If requested value is the same as default, 
	// don't waste memory for a variable since we 
	// fall back to default on NULL() anyway.
	if (DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT == value)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_fidelity_get_member_sound_volume_main_right()
{
	char id;

	id = dc_fidelity_get_instance() + DC_FIDELITY_MEMBER_SOUND_VOLUME_MAIN_RIGHT;

	int result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_FIDELITY_DEFAULT_SOUND_VOLUME_RIGHT;
	}

	// Keep us level with engine limit. See config.c for details.
	if (result > DC_FIDELITY_ENGINE_MAX_VOLUME)
	{
		result = DC_FIDELITY_ENGINE_MAX_VOLUME;
	}

	return result;
}

