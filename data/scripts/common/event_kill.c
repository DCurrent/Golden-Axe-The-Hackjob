#include "data/scripts/dc_kanga/main.c"

void main()
{
	entity_kill();
}

// Caskey, Damon V
// 2018-11-04 (2007-05-13)
//
// Copy from kill0001.h (ugh). Meant as final cleanup and
// fataility effect spawn function. As of 2018-11-04 most 
// of this stuff is defunct. Needs to be cleaned out and
// reworked.
void entity_kill()
{
	/*
	kill0001
	Damon Vaughn Caskey
	05/13/2007
	Primary on kill function. Run for most entities when engine removes them from play.
	*/

	void    vSelf = getlocalvar("self");                      //Caller.
	void    vParent = getentityproperty(vSelf, "parent");       //Caller's parent.
	int     iAni = getentityproperty(vSelf, "animationid");  //Current animation.
	int     iMaxVar = openborvariant("maxentityvars");          //Module entity var max.
	void    vBindhe;                                            //Bound hit effect entity.
	int     iCount;                                             //Loop counter.
	void    vSpawn;                                             //Spawn entity.

	if (iAni == openborconstant("ANI_BURNDIE"))                 //Self in burning death?
	{
		if (getentityproperty(vSelf, "model") != "effe0001")    //Self not the fatality or effect model?
		{
			vBindhe = getentityvar(vSelf, "bound_hit_effect");              //Get any bound effect.

			if (getentityproperty(vBindhe, "exists"))           //Bound effect exists?
			{
				killentity(vBindhe);                            //Then kill it.
			}

			//vSpawn = bind0008("effe0001", "effe0001", MAPBURN, 0, 0, 0, 0, 1, openborconstant("ANI_FOLLOW14"), 0, 0);   //Spawn fatality model.

			dc_kanga_z_position_autoscale(vSpawn);                                   //Apply draw settings.
		}
	}
	else if (iAni == openborconstant("ANI_SHOCKDIE"))
	{
	}
	

	// Moved from kill0001.c so we could eliminate it.
	// Was used by boat in sound beach stage.
	// Check for entity bound to us and kill it here.



	if (getentityproperty(vParent, "exists"))                   //Parent exists?
	{
		vBindhe = getentityvar(vParent, "bound_hit_effect");               //Get parent's bound effect variant.
		if (vBindhe == vSelf)                                  //Was bound effect same as self?
		{
			dc_kanga_z_position_autoscale(vParent);                                  //Update parent's draw.
		}
	}
}