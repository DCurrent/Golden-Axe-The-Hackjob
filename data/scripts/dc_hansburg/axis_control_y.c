#include "data/scripts/dc_hansburg/config_flags.c"

#import "data/scripts/dc_hansburg/entity.c"
#import "data/scripts/dc_hansburg/config_flags.c"
#import "data/scripts/dc_hansburg/check_jumping.c"

/*
* Caskey, Damon V.
* 2021-05-19 (extract of Y axis portion of jump005, 2010-05-12)
*
* Enable Y axis jump control. In other
* words, replicates the common platform
* game effect where height of jump is 
* controlled by how long player holds 
* the jump key.
* 
* Run this function in a key event script
* such as keyall. If Y axis control is
* enabled the function will detect release
* event of the jump key and slightly reduce 
* upward vertical velocity. This in turn 
* causes engine gravity to quickly overtake 
* the jumping momentum, creating a smooth
* transition from rising to falling as in
* games like Super Mario Brothers.
* 
* Note: When there are transitions or delays
* (such as a jump start animation) it is
* possible that player can release Jump before
* the jump actually begins. In that case, this 
* function will not take effect unless they 
* press and release Jump again. This results
* in a very quick Jump tap causing entity to 
* jump its full height. The previous workaround
* was to read keys during the movea event and
* stop upward momentum if player wasn't holding
* Jump. This method is simple but a bit wasteful.
* 
* The current method is a bit more complex but
* far less resouce intensive:
* 
* 1. Release Jump during jump - Reduce current
* vertical velocity as described above.
* 

Normal jumps: As OpenBOR Script now allows access to
* the prejump velocity properties, we can
* handle jump taps for nby pres
* 
* 
*/
void dc_hansburg_try_axis_control_y()
{
	/* 
	* Before doing anything else, verify
	* that Y axis control is enabled.
	*/
	if (!(dc_hansburg_get_member_config_flags() & DC_HANSBURG_CONFIG_ENABLE_CONTROL_Y))
	{
		return;
	}

	void acting_entity = dc_hansburg_get_member_entity();
	int player_index = get_entity_property(acting_entity, "player_index");
	int key_release = getplayerproperty(player_index, "releasekeys");
	float velocity_y = 0.0;

	/* 
	* Verify this is a jump key release 
	* event.
	*/
	if (!(key_release & openborconstant("FLAG_JUMP")))
	{
		return 0;
	}

	/* 
	* Now we need to know if player entity is
	* in a jumping state. If not, we need to
	* check their pre-jump state instead.
	*/
	if (dc_hansburg_check_normal_jump())
	{
		/* Jumping. */
		float velocity_y = get_entity_property(acting_entity, "velocity_y");
		velocity_y *= 0.9;

		set_entity_property(acting_entity, "velocity_y");
	}
	else
	{
		/* Not jumping. */
		get_entity_property(acting_entity, "jump_velocity_y");
		velocity_y *= 0.25;

		set_entity_property(acting_entity, "jump_velocity_y");
	}
}