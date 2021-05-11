#import "data/scripts/com/ani0009.h" //Verify and switch animation.

/*
* Caskey, Damon V.
* 2021-01-26 (Rewrite from bind0017, 2010-05-02)
* License - https://www.caskeys.com/dc/license/
*
* Accept an entity pointer and animation constant.
* Attempts to locate dead entity with same default 
* as supplied entity name. If a match is found 
* perform the following actions:
*
* - Move supplied entity to dead entity's location.
* - Supplied entity plays supplied animation.
* - Remove dead entity from play.
*/
void dc_respawn_body(void entity, int animation)
{
    int i = 0;
    void target = NULL();
    int entity_count = openborvariant("count_entities");
    char entity_default_name = getentityproperty(entity, "defaultname");
    int resolution_h = openborvariant("hresolution");
    int scroll_h = openborvariant("xpos");

    float target_direction = openborconstant("DIRECTION_LEFT");
    float target_pos_x = 0.0;
    float target_pos_y = 0.0;
    float target_pos_z = 0.0;

    /*
    * Loop through all entities in play. This works by
    * running a counter loop that goes from 0 to the
    * current number of entities in play. In OpenBOR
    * all entities have a number index, and you can get
    * the entity pointer using that index. So at each
    * loop we can use the current loop position as the
    * index to get an entity, allowing us to loop over
    * every single entity one at a time. I prefer to
    * call the current loop entity "target", so from
    * now on when you see "target", we're referring to
    * current entity our loop is on.
    *
    * For this function, we compare some properties of
    * the target to see if it's a "dead" match. If all
    * the conditions match we know we found the right
    * target. That means we can exit the entire loop
    * right away and perform our respawn actions. If
    * any one condition does not match, we know right
    * away the target entity is not what we're looking
    * for. In that case, it's pointless to waste CPU
    * time checking other properties, so we exit the
    * current loop iteration immediately and move on
    * to the next target.
    */

    for (i = 0; i < entity_count; i++)
    {
        /*
        * Use the current loop position as an index
        * to get target entity.
        */
        target = getentity(i);

        /*
        * Now we verify the following:
        *
        * - We got a valid entity pointer from getentity()
        * - Target entity exists in play.
        * - Target entity is dead.
        * - Target entity and acting entity default names (not alias) match.
        */

        if (target
            && getentityproperty(target, "exists")
            && getentityproperty(target, "dead")
            && getentityproperty(target, "defaultname") == entity_default_name)
        {
            /*
            * Get target's position, and verify it against
            * the following:
            *
            * - Not in a wall.
            * - Not in a hole.
            * - Greater than left screen position.
            * - Less than right screen position.
            *
            * Note - I haven't checked to be sure this code
            * handles left scrolling levels. If it doesn't
            * we just need to add a verify block for left/right
            * scrolling and invert the scroll math accordingly.
            */

            target_pos_x = getentityproperty(target, "x");
            target_pos_y = getentityproperty(target, "y");
            target_pos_z = getentityproperty(target, "z");

            if (!checkhole(target_pos_x, target_pos_z)
                && !checkwall(target_pos_x, target_pos_z)
                && target_pos_x > scroll_h
                && target_pos_x < scroll_h + resolution_h)
            {
                /*
                * At this point everything passed. We're able to
                * take the appropriate actions to simulate the
                * dead entity recovering.
                *
                * - Remove the target entity from play.
                * - Set acting entity direction to match target.
                * - Set acting entity position to match target.
                * - Acting entity plays requested animation.
                */

                target_direction = getentityproperty(target, "direction");

                killentity(target);

                changeentityproperty(entity, "direction", target_direction);
                changeentityproperty(entity, "position", target_pos_x, target_pos_z, target_pos_y);
                                
                /*
                * Make sure the acting entity has supplied animation.
                * If it does, then we play it.
                */
                if(getentityproperty(entity, "animvalid", animation))
                {
                    executeanimation(entity, animation);
                }

                /*
                * Exit the function - we're done, so there's
                * no reason to waste CPU time on more loops.
                */
                return;
            }
        }
    }
}

void bind0017(void vEnt, int iAni, int iType, int iRem, int A, int B, int C, int D, int E, int F)
{
    /*
    bind0017
    Damon Vaughn Caskey
    05202010
    2010_05_02
    ~2011_06_08
    Find pre existing ent with same default name, and warp to location. Primarly
    for spawning in location of corpse.

    vEnt:   Entity.
    iAni:   Animation.
    iType:  Animation set type (See ani0009).
    iRem:   Remove previous entity?
    A-F:    Expansion.
    */

    void    vSelf   = getlocalvar("self");                              //Caller.
    int     iMax    = openborvariant("ent_max");		                //Current # of entities.
	int		i;                                                          //Counter.
	int		iD;												            //Direction.
    float	fX, fY, fZ;										            //Location coords.
    int     iResH;                                                      //Horizontal resolution.
    int     iLoc;                                                       //Location.

	for(i=0; i<iMax; i++)												//Loop entity collection.
	{
		vEnt    = getentity(i);											//Get entity.
        iResH   = openborvariant("hresolution");                        //Get horizontal resolution.
        iLoc    = openborvariant("xpos");

        if(vEnt															//Valid handle?
			&& getentityproperty(vEnt, "exists")						//Valid entity?
			&& getentityproperty(vEnt, "health") < 1					//Dead?
			&& getentityproperty(vEnt, "defaultname")
			== getentityproperty(vSelf, "defaultname"))					//Same name as self?
		{
			fX = getentityproperty(vEnt, "x");							//Get X.
			fY = getentityproperty(vEnt, "a");							//Get Y.
			fZ = getentityproperty(vEnt, "z");							//Get Z.
			iD = getentityproperty(vEnt, "direction");				    //Get direction.

            if(iRem)
            {
                killentity(vEnt);                                       //Remove previous existing entity.
            }

            if(!checkhole(fX, fZ) && !checkwall(fX, fZ)                 //Location isn't in a hole or wall?
               && !(fX <= iLoc || fX >= iLoc+iResH))                    //Location isn't out of screen?
            {
			    changeentityproperty(vSelf, "direction", iD);			//Set direction to self.
			    changeentityproperty(vSelf, "position", fX, fZ, fY);    //Set location to self.
			    ani0009(vSelf, iAni, iType);                            //Set animation.
            }
		}
	}
}
