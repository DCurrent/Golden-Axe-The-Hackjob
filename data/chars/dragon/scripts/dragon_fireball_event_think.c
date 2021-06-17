void main()
{	
	dc_kill_on_wall_impact();
}

/*
* Caskey, Damon V.
* 2021-06-15
* 
* Simple wall kill function for bomb projectiles.
* Normally projectile follows up walls. By
* setting the projectile to ignore walls it
* can pass through them. We then check to
* see if projectile is inside wall and if
* so set it to detonate.
*/
void dc_kill_on_wall_impact()
{
	void acting_entity = getlocalvar("self");
		
	float pos_x_current = get_entity_property(acting_entity, "position_x");
	float pos_y_current = get_entity_property(acting_entity, "position_y");
	float pos_z_current = get_entity_property(acting_entity, "position_z");
	int pos_base_current = get_entity_property(acting_entity, "position_base");	

	changeentityproperty(acting_entity, "no_adjust_base", 1);

	if (checkwall(pos_x_current, pos_z_current) > pos_y_current)
	{
		set_entity_property(acting_entity, "speed_multiplier", 0.0);
				
		/* 
		* Play explode animation and then die.
		* 
		* If this was a bomb we could just set the 
		* explode property to "EXPLODE_DETONATE", but
		* we may need to spawn as a knife, in which 
		* case explode is ignored.
		*/
	
		executeanimation(acting_entity, openborconstant("ANI_ATTACK1"), 0);
		set_entity_property(acting_entity, "autokill", 1);
	}
}