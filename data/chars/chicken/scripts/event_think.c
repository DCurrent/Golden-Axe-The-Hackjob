
void main()
{
	void acting_entity = getlocalvar("self");

	dc_ai_escape(acting_entity);
}

/*
* Caskey, Damon V.
* 2021-03-31
* 
* Acting entity tries to find its way out of
* screen and then self kill. Turn back if a
* wall or hole in the way is too much for
* jumping onto or over.  
*/
void dc_ai_escape(void acting_entity)
{

	float pos_x = get_entity_property(acting_entity, "position_x");
	float pos_y = get_entity_property(acting_entity, "position_y");
	float pos_z = get_entity_property(acting_entity, "position_z");
	int pos_direction = get_entity_property(acting_entity, "position_direction");
	float velocity_x = get_entity_property(acting_entity, "velocity_x");
	float velocity_z = get_entity_property(acting_entity, "velocity_z");
	int scroll_x = openborvariant("xpos");
	int screen_size_x = openborvariant("hresolution");
	
	int screen_size_half = 0;
	int center_point_x = 0;
	int target_pos_x = 0;
	int target_pos_z = 0;
	int offscreen_left = 0;
	int offscreen_right = 0;
	int offscreen_kill = 0;
	float check_pos_x = 0.0;
	float check_pos_z = 0.0;
	int wall_height = 0;
	int wall_difference = 0;
	int walk_state = 0;
	int run_state = 0;
	int pedestrian_state = 0;	
	int wide_hole = 0;
	int range_max = 0;

	/* 
	* Get half current res, then we add that to
	* scroll position. This tells us the game world
	* position center of screen is at.
	*/

	screen_size_half  = screen_size_x / 2;
	center_point_x = screen_size_half + scroll_x;

	/*
	* Find positions offscreen. We're going to use 
	* them as destinations for the AI to move toward.
	* We copy the engine's logic of using half the
	* current resolution out of screen for being 
	* out of bounds in the game world.
	* 
	* We'll use a slightly smaller value for the
	* offscreen kill to ensure acting entity kills 
	* self as it moves out of the play area.
	*/

	offscreen_left = scroll_x - screen_size_half;
	offscreen_right = scroll_x + screen_size_x + screen_size_half;
	offscreen_kill = screen_size_half - 1;	
	
	/* Find Z center of walkable area. */

	target_pos_z = (openborvariant("player_min_z") + openborvariant("player_max_z")) / 2;

	/* 
	* If we don't have a target position or its
	* not off the current viewable area, set initial 
	* target position to nearest offscreen boundary. 
	*/

	target_pos_x = get_entity_property(acting_entity, "destination_x");
	
	if (target_pos_x > offscreen_left && target_pos_x < offscreen_right)
	{
		if (pos_x <= center_point_x)
		{
			target_pos_x = offscreen_left;
		}
		else
		{
			target_pos_x = offscreen_right;
		}
	}	

	/* Walking or running? */

	walk_state = get_entity_property(acting_entity, "walk_state");
	run_state = get_entity_property(acting_entity, "run_state");

	pedestrian_state = (walk_state || run_state);
	
	if (pedestrian_state)
	{
		/* 
		* If there's something in the way we can't 
		* jump, turn back. 
		* 
		* First get maximum range of running jump. 
		* We don't need to worry about anything
		* at or below that because the AI will 
		* attempt to jump over/onto it. 
		*
		* Note xmax is NOT a typo. The engine uses 
		* range X max for both horizontal and vertical 
		* jump checks.
		*/

		range_max = getentityproperty(acting_entity, "range", "xmax", openborconstant("ANI_RUNJUMP"));

		/* 
		* For walls, the check position is our
		* current X plus velocity, since velocity
		* is approximatly how many pixels per frame 
		* we move. This is identical to the engine's 
		* internal checks.
		*/
		
		check_pos_x = pos_x + velocity_x;
		check_pos_z = pos_z + velocity_z;

		wall_height = checkwall(check_pos_x, check_pos_z);
		wall_difference = wall_height - pos_y;		
		
		/*
		* For holes, use our max jump range. Obviously
		* we want to set up the jump range correctly
		* compared to distance entity does jump.Or
		* not, depending on how suicidal you want the
		* AI to be. :)
		*/

		if (pos_direction == openborconstant("DIRECTION_RIGHT"))
		{
			check_pos_x = pos_x + range_max;
		}
		else
		{
			check_pos_x = pos_x - range_max;
		}

		wide_hole = checkhole(check_pos_x, check_pos_z);
		
		/* Can't jump it? Turn around. */

		if (wall_difference > range_max || wide_hole)
		{			
			if (pos_direction == openborconstant("DIRECTION_RIGHT"))
			{
				target_pos_x = offscreen_left;				
			}
			else
			{
				target_pos_x = offscreen_right;				
			}
		}
		
		/*
		* Native AI likes to look back and forth. Let's keep
		* us pointing same direction we're moving.
		*/

		if (velocity_x > 0)
		{
			set_entity_property(acting_entity, "position_direction", openborconstant("DIRECTION_RIGHT"));
		}
		else if (velocity_x < 0)
		{
			set_entity_property(acting_entity, "position_direction", openborconstant("DIRECTION_LEFT"));
		}
		
	}
		

	/* Destination off screen and kill self once we get there. */

	set_entity_property(acting_entity, "destination_x", target_pos_x);
	set_entity_property(acting_entity, "destination_z", target_pos_z);
	changeentityproperty(acting_entity, "offscreenkill", offscreen_kill);	
}