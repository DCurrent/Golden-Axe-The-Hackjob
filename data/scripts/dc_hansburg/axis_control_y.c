#include "data/scripts/dc_hansburg/config_flags.c"

#import "data/scripts/dc_hansburg/entity.c"
#import "data/scripts/dc_hansburg/config_flags.c"
#import "data/scripts/dc_hansburg/check_jumping.c"

/*
* Caskey, Damon V.
* 2021-05-19 (extract of Y axis portion of jump005, 2010-05-12)
*
* Run in a movea event to enable Y axis jump 
* control. In other words, replicates the 
* common platform game effect where height 
* of jump is controlled by how long player 
* holds the Jump key. 
* 
* Note: In theory, we could do this as part
* of a key script by checking for the Jump
* key release event. On the surface, it would 
* much more elegant, but there are a few reasons
* to keep it in movea event:
* 
* 1. With a key script, we have to handle 
* players releasing the Jump key before the
* jump delay animation is finished. Otherwise
* tapping Jump very quickly causes a full
* height jump. 
* 
* 2. We would need to handle our own scripted
* jumps with similar logic to dealing with
* delay animations. 
* 
* 3. Due to key mixing, if player releases 
* Jump key and then pauses game just before 
* liftoff, the entity jumps full height once
* the game is unpaused. 
* 
* 4. We may want different models to have
* differing jump capabilities.
* 
* It is possible to handle all the above,
* but doing so introduces a great deal of
* complexity to the script. Also, as key
* scripts constantly fire during any press
* of any key, there is arguably less resource
* use keeping Y axis control in movea even 
* before considering the added complexity.
*/
void dc_hansburg_try_axis_control_y()
{
	/* 
	* Before doing anything else, verify
	* that Y axis control is enabled.
	*/
	int config_flags = dc_hansburg_get_member_config_flags();

	if (!(config_flags & DC_HANSBURG_CONFIG_ENABLE_CONTROL_Y))
	{
		return;
	}
		
	void acting_entity = dc_hansburg_get_member_entity();
	int player_index = get_entity_property(acting_entity, "player_index");
	int key_hold = getplayerproperty(player_index, "keys");
	float velocity_y = 0.0;

	/* 
	* Verify this is a jump key release 
	* event.
	*/
	if (key_hold & openborconstant("FLAG_JUMP"))
	{
		return 0;
	}

	/* 
	* Now we need to know if player entity is
	* in a jumping state and moving upward.
	*
	* If so, we will reduce vertical velocity 
	* by a slight percentage. The combined 
	* effect of this occuring every engine 
	* update along with the engine's native 
	* gravity gravity will quickly but smoothly 
	* stop upward movement. 
	*/

	int normal_jump = get_entity_property(acting_entity, "jump_state");

	if (!normal_jump)
	{
		return;
	}
		
	
	velocity_y = get_entity_property(acting_entity, "velocity_y");
	
	if (velocity_y < 0)
	{
		return;
	}

	velocity_y *= 0.95;

	set_entity_property(acting_entity, "velocity_y", velocity_y);	
}