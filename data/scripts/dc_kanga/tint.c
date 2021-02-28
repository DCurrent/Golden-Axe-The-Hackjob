#include "data/scripts/dc_kanga/config.h"

// Set drawmethod tint color.
void dc_kanga_set_tint_color(void ent, int rgb_r, int rgb_g, int rgb_b)
{
	int rgb_final = 0;    // Final RGB result.

	// Catch bad arguments here.
	if (typeof(rgb_r) != openborconstant("VT_INTEGER") || rgb_r < DC_KANGA_RGB_MIN || rgb_r > DC_KANGA_RGB_MAX
		|| typeof(rgb_g) != openborconstant("VT_INTEGER") || rgb_g < DC_KANGA_RGB_MIN || rgb_g > DC_KANGA_RGB_MAX
		|| typeof(rgb_b) != openborconstant("VT_INTEGER") || rgb_b < DC_KANGA_RGB_MIN || rgb_b > DC_KANGA_RGB_MAX)
	{
		log("error: dc_kanga_set_tint_color(void ent, int rgb_r, int rgb_g, int_rgb_b): One or more {rgb} arguments are invalid.");
		return;
	}

	// Get RGB code needed for OpenBOR.
	rgb_final = rgbcolor(rgb_r, rgb_g, rgb_b);

	changedrawmethod(ent, "tintcolor", rgb_final);
}

void dc_kanga_auto_tint(void ent)
{
	// dc_kanga_auto_tint
	// License - http://www.caskeys.com/dc/?p=5067
	// Caskey, Damon V.
	// 2015-05-04
	//
	// Apply color tint for hit effects.

	float time_percentage = 0.0;  // Calculated time percentage.
	int time_effect = 0;    // The normal set time for an effect to expire.
	float time_remaining = 0.0;  // Actuall time in seconds before an effect will expire.
	float time_current = 0.0;  // The current engine time.
	float time_initial = 0.0;  // Time an effect was applied.
	int   map_default = 0;    // Remap entity was spawned into play with.
	int   animation = 0;    // Animation ID currently in use.
	int   debug = NULL();    // Debug mode.
	int   alpha = 0;

	int rgb_r = 0,  // RGB color settings.
		rgb_g = 0,
		rgb_b = 0,
		tint_mode = DC_KANGA_TRANSPARENCY_OFF;

	// Verify entity or exit.
	if (typeof(ent) != openborconstant("VT_PTR")) return;
	if (!getentityproperty(ent, "exists")) return;

	// First lets turn drawmethod on. If we don't, nothing below will
	// work at all.
	dc_kanga_set_enabled(ent, DC_KANGA_FLAG_ON);

	// For time controlled effects, we need to know
	// current time and the time an effect was first
	// applied.
	time_current += openborvariant("elapsed_time");
	time_initial += getlocalvar(ent + DC_KANGA_MEMBER_TIME_INITIAL);

	// If entity is frozen, apply a freeze tint.
	if (getentityproperty(ent, "aiflag", "frozen") == DC_KANGA_FLAG_ON)
	{
		// First we need to know how long the entity is meant to be frozen.
		time_effect = getentityproperty(ent, "freezetime");

		// Now let's see if we have a time when the freeze took place.
		// If not, this, entity was just frozen, so let's
		// record the time to an entity var.
		if (!time_initial)
		{
			time_initial = time_effect - time_current;
			setlocalvar(ent + DC_KANGA_MEMBER_TIME_INITIAL, time_initial);
		}

		// How much time is left before freeze effect is set to expire?
		time_remaining = time_effect - time_current;

		// Now let's find what % of the original
		// freeze time is left. Then we'll multiply that by
		// maximum intensity of color and apply it to blue
		// and green color setting.
		time_percentage = (time_remaining) / (time_initial);
		rgb_b = DC_KANGA_FREEZE * time_percentage;

		// Make green same intensity as blue - this makes a much
		// stronger looking freeze effect than blue alone.
		rgb_g = rgb_b;

		// Unless fmap is set to -1, OpenBOR ALWAYS applies an fmap on frozen entities.
		// Since the default fmap is 0, that means entities without an fmap revert
		// back to their default palette. Obviously we don't we don't want that since
		// the whole point is to use dynamic tinting instead of a remap. To fix the
		// problem we'll get the map that entity was spawned into play with (ie. was
		// using before being set to an fmap), and force the engine to use it here.
		map_default = getentityproperty(ent, "mapdefault");
		dc_kanga_set_map(ent, map_default);

		// Set transparency mode for tint, and apply blue intensity based
		// on % of initial freeze time is left.
		dc_kanga_set_tint_mode(ent, DC_KANGA_FREEZE_MODE);
		dc_kanga_set_tint_color(ent, DC_KANGA_RGB_MIN, rgb_g, rgb_b);

		// No reason to do anything else, so exit the function.
		return;
	}


	// For most effects checking the animations will work, so
	// let's grab the current animation here.
	animation = getentityproperty(ent, "animationid");

	// In a burning animation? Then we'll apply burn tint.
	if (animation == openborconstant("ANI_BURN")
		|| animation == openborconstant("ANI_BURNPAIN"))
	{
		// Set transparency mode for tint, and apply tint color.
		dc_kanga_set_tint_mode(ent, DC_KANGA_BURN_MODE);

		dc_kanga_set_tint_color(ent, DC_KANGA_BURN_RGB_R, DC_KANGA_BURN_RGB_G, DC_KANGA_BURN_RGB_B);

		// Nothing else to do, so exit the function.
		return;
	}

	// Wash out when entity is KO'd.
	// We just check to see if entity is
	// dead and is finished animating, then
	// give it a KO tint effect.

	//  Dead?
	if (getentityproperty(ent, "dead"))
	{
		// Finished with animation?
		if(!getentityproperty(ent, "animating"))
		{ 
			int tint_color;		

			// Get current tint color.
			tint_color = getdrawmethod(ent, "tintcolor");

			// Now we'll use the spinner library to increment 
			// RGB blue value. We only use blue because it's 
			// quickest to extract from current tint_color integer
			// and for KO map R, G, and B values are all identical.

			// Get the blue value.
			rgb_b = tint_color % 256;
			//rgb_g = tint_color / 256 % 256;
			//rgb_r = tint_color / 256 / 256 % 256;

			// Current value for spinner is current RGB. Upper
			// is the KO value. We don't care about lower value.
			dc_spinner_set_value(rgb_b);
			dc_spinner_set_range_max(DC_KANGA_KO_RGB_R);

			// Cap the value at upper.
			dc_spinner_set_range_bound_max(DC_SPINNER_RANGE_BOUND_CAP);

			// Set steps and build increment amount.
			dc_spinner_set_steps(DC_KANGA_KO_STEPS);

			// Run the increment and get resulting value for rgb_b.
			rgb_b = dc_spinner_increment_run();

			// Set transparency mode for tint, and apply tint color.
			dc_kanga_set_tint_mode(ent, DC_KANGA_KO_MODE);
			dc_kanga_set_tint_color(ent, rgb_b, rgb_b, rgb_b);

			// Nothing else to do, so exit the function.
			return;
		}
	}
	///////

	// If you want to add other tint effects, like shock, poison,
	// and so on, put them here. Use the burn example as a
	// template.

	///////

	// If we got this far without exiting, there was no effect to apply.
	// Clear any previous tints and entity vars.
	dc_kanga_set_tint_color(ent, 0, 0, 0);
	dc_kanga_set_tint_mode(ent, 0);

	setlocalvar(ent + DC_KANGA_MEMBER_TIME_INITIAL, NULL());
}




void dc_effect_tint_debug_control()
{
	int     player_index = getlocalvar("player");
	int     debug = DC_KANGA_FLAG_OFF;
	int     key_press = DC_KANGA_FLAG_OFF;
	int     key_hold = DC_KANGA_FLAG_OFF;
	int     value = 0;
	int     mode = 0;

	// Get current key press and any keys being held.
	key_hold = getplayerproperty(player_index, "keys");
	key_press = getplayerproperty(player_index, "newkeys");

	// Get stored debug flag.
	debug = getlocalvar(DC_KANGA_MEMBER_DEBUG_FLAG);

	// if holding escape, then use Up/Down presses
	// to toggle debugging mode.
	if (key_hold & openborconstant("FLAG_ESC"))
	{
		debug = getlocalvar(DC_KANGA_MEMBER_DEBUG_FLAG);

		debug = dc_effect_tint_spinner(debug, DC_KANGA_FLAG_OFF, DC_KANGA_FLAG_ON);

		setlocalvar(DC_KANGA_MEMBER_DEBUG_FLAG, debug);
	}

	// If debugging mode is on, then we're going to use Bitwise ANDs to
	// see if certain keys are held. If they are, then pressing Up/Down
	// key presses will adjust associated values. As coded, each item has
	// an independent evaluation. This is to allow more than one value to
	// be adjusted at once, depending on limits of the input device.
	if (debug == DC_KANGA_FLAG_ON)
	{
		// Tinting transparency mode.
		if (key_hold & openborconstant("FLAG_ATTACK"))
		{
			// Get orginal value.
			mode = getlocalvar(DC_KANGA_MEMBER_DEBUG_TINT_MODE);

			// Adjust value based on key press and limits.
			mode = dc_effect_tint_spinner(mode, 0, 6);

			// Save value.
			setlocalvar(DC_KANGA_MEMBER_DEBUG_TINT_MODE, mode);
		}

		// RGB Red value.
		if (key_hold & openborconstant("FLAG_ATTACK2"))
		{
			// Get orginal value.
			value = getlocalvar(DC_KANGA_MEMBER_DEBUG_RGB_RED);

			// Adjust value based on key press and limits.
			value = dc_effect_tint_spinner(value, 0, 255);

			// Save value.
			setlocalvar(DC_KANGA_MEMBER_DEBUG_RGB_RED, value);
		}

		// RGB Green value.
		if (key_hold & openborconstant("FLAG_ATTACK3"))
		{
			// Get orginal value.
			value = getlocalvar(DC_KANGA_MEMBER_DEBUG_RGB_GREEN);

			// Adjust value based on key press and limits.
			value = dc_effect_tint_spinner(value, 0, 255);

			// Save value.
			setlocalvar(DC_KANGA_MEMBER_DEBUG_RGB_GREEN, value);
		}

		// RGB Blue Value.
		if (key_hold &  openborconstant("FLAG_ATTACK4"))
		{
			// Get orginal value.
			value = getlocalvar(DC_KANGA_MEMBER_DEBUG_RGB_BLUE);

			// Adjust value based on key press and limits.
			value = dc_effect_tint_spinner(value, 0, 255);

			// Save value.
			setlocalvar(DC_KANGA_MEMBER_DEBUG_RGB_BLUE, value);
		}
	}
}

// Simulate spinner control increments with looping.
int dc_effect_tint_spinner(int value, int lower_limit, int upper_limit)
{
	int     player_index = NULL();   // Which player triggered key event.
	int     key_press = NULL();   // Keypress

	// Get player index and key press.
	player_index = getlocalvar("player");
	key_press = getplayerproperty(player_index, "newkeys");

	// Use a Bitwise AND to find out if the Up or Down key
	// is pressed and increment or decrement the value
	// accordingly.
	if (key_press & openborconstant("FLAG_MOVEUP"))
	{
		value++;
	}
	else if (key_press & openborconstant("FLAG_MOVEDOWN"))
	{
		value--;
	}

	// Now let's make sure the value is in bounds.
	// If not, we'll loop it.
	if (value > upper_limit)
	{
		value = lower_limit;
	}
	else if (value < lower_limit)
	{
		value = upper_limit;
	}

	// Return the final value.
	return value;
}