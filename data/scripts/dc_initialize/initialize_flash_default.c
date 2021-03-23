#include "data/scripts/dc_initialize/config.h"

#import "data/scripts/dc_initialize/config.c"

// Set up a generic flash spawn.
void dc_initialize_flash_default()
{
	void ent;
	int force;
	int	rotate;
	int drawsize;
	int intensity;
	int sound_speed;
	int size;
	void drawmethod;

	ent = getlocalvar("self");

	drawmethod = get_entity_property(ent, "drawmethod");

	// Get random numbers for rotation.
	dc_d20_set_range_min(0);
	dc_d20_set_range_max(359);

	rotate = dc_d20_random_int();

	// Get an intensity value. Think of this as a percentage of base hit
	// force. We start with a median force (DC_INITIALIZE_FLASH_INTENSITY_FORCE_MEDIAN) 
	// and subtract that from the real force. Then we mutiply the result by a factor 
	// of DC_INITIALIZE_FLASH_INTENSITY_FORCE_MUTIPLIER to give it more variance and 
	// subtract the total value from DC_INITIALIZE_FLASH_INTENSITY_BASE. 
	
	// As an example, assume DC_INITIALIZE_FLASH_INTENSITY_BASE is 100.
	//
	// If DC_INITIALIZE_FLASH_INTENSITY_FORCE_MEDIAN is 10, an attack damage 
	// of 10 is DC_INITIALIZE_FLASH_INTENSITY_BASE (i.e. 100% intensity), so
	// the final intensity value is 100. If the attack is 5 damage, and 
	// DC_INITIALIZE_FLASH_INTENSITY_FORCE_MUTIPLIER is 4, then intensity 
	// will be 120. Damage of 15 would produce an intensity of 80. 
	
	// Once we have an intensity value we can use it to control size of flash 
	// and speed of sound playback to create a dynamic experience. This is 
	// based on OpenBOR's native damage based hitfx playback speed. It's important 
	// to note, stronger attacks produce a LOWER intensity value. This is because
	// the formula is intended to work as playback speed for hit sounds. 
	
	force = get_attack_property(openborvariant("lasthit_attack"), openborconstant("ATTACK_PROP_DAMAGE_FORCE"));

	intensity = DC_INITIALIZE_FLASH_INTENSITY_BASE - ((force - DC_INITIALIZE_FLASH_INTENSITY_FORCE_MEDIAN) * DC_INITIALIZE_FLASH_INTENSITY_FORCE_MUTIPLIER);
	
	// For size, we'll start with a base size value and subtract intensity
	// to get the final size. Since we're using drawmethods, a final size 
	// value of 256 means the model sprites are displayed at 100% size.
	
	size = DC_INITIALIZE_FLASH_SIZE_BASE - intensity;

	if (size > DC_INITIALIZE_FLASH_SIZE_MAX)
	{
		size = DC_INITIALIZE_FLASH_SIZE_MAX;
	}

	if (size < DC_INITIALIZE_FLASH_SIZE_MIN)
	{
		size = DC_INITIALIZE_FLASH_SIZE_MIN;
	}

	// Apply the drawmethods for blending, rotation, and size.
	//dc_kanga_z_position_autoscale(ent);
	
	// set_drawmethod_property(drawmethod, "alpha", 1);
	set_drawmethod_property(drawmethod, "enable", 1);
		
	/*
	* Throwdamage toggles auto rotate.
	*/
	if(getentityproperty(ent, "throwdamage") == 2)
	{
		set_drawmethod_property(drawmethod, "rotate", rotate);
	}

	set_drawmethod_property(drawmethod, "scale_x", size);
	set_drawmethod_property(drawmethod, "scale_y", size);

	// We'll cap our intenstiy ranges here and then use it for sound playback speed.
	if (intensity > DC_INITIALIZE_FLASH_INTENSITY_SOUND_MAX)
	{
		intensity = DC_INITIALIZE_FLASH_INTENSITY_SOUND_MAX;
	}
	else if (intensity < DC_INITIALIZE_FLASH_INTENSITY_SOUND_MIN)
	{
		intensity = DC_INITIALIZE_FLASH_INTENSITY_SOUND_MIN;
	}

	// Set the sound speed and play.
	dc_fidelity_set_member_sound_speed(intensity);
	dc_fidelity_quick_play(DC_FIDELITY_TYPE_SOUND_SPAWN);
}
