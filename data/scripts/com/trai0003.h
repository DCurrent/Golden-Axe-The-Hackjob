#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

void trai0003()
{
    /*
    trai0002
    Damon Caskey, based on shadow trail system by Utunnels 
    11152009
    Parses artificial array (created by numerically sequenced global vars) and applies stored 
    damage values to simulate shadows hitting.
    */

    //hit.c: Expire (Clear) time.
    //hit.t: Type
    //hit.d: Damage
    //hit.k: Drop (knockdown)
    //hit.o: Opponent (target)
    //hit.a: Attacker.
    
	int     i;                                                  //Counting placeholder.
    int     cd;                                                 //Expire time.
    void    iType;                                              //Attack type.
	int     iDamage;                                            //Damage.
    int     iDrop;                                              //Drop.
	void    vOpp;                                               //Opponent.
    void    vAtk;                                               //Attacker.
    int     iHP;                                                //Opponent HP.
    void    vBind;                                              //Bound entity.
    void    vGrab;                                              //Grabbed entity.
    float   fX, fY, fZ;                                         //Locations.
    int     iHt;                                                //Entity height.
    void    vSpawn;                                             //Spawn placeholder.
	int		iRush;												//Rush count.

	for(i=1; i<=15; i++)                                        //Loop hit slots.
	{
        vAtk    = getglobalvar("hit"+i+".a");                   //Get stored Attacker.		
		if(vAtk)                                                //Hit type found?
		{
			cd = getglobalvar("hit"+i+".c");                    //Get expire time.
			if(!cd)                                             //No expire time or decremented to 0?
			{   
                iType   = getglobalvar("hit"+i+".t");           //Get hit type.
				iDamage = getglobalvar("hit"+i+".d");           //Get stored Damage.
				iDrop   = getglobalvar("hit"+i+".k");           //Get stored Drop.
				vOpp    = getglobalvar("hit"+i+".o");           //Get stored Target.                
                
                iHP     = getentityproperty(vOpp, "health");    //Get opponent health.
                vBind   = getentityvar(vAtk, IDXE_BIND);             //Get bound entity.
                vGrab   = getentityproperty(vAtk, "grabbing");  //Held entity.

                if (iHP && !vBind && vOpp != vGrab)             //Target alive and not being held?
                {
                    if (getentityproperty(vOpp, "type") != openborconstant("TYPE_OBSTACLE")) //Target not an obstacle?
                    {
                        iHt = getentityproperty(vOpp, "height"); 
                        fX  = getentityproperty(vOpp, "x") - openborvariant("xpos");
                        fY  = getentityproperty(vOpp, "a") + (iHt * 0.5);
                        fZ  = getentityproperty(vOpp, "z") + 2;
                        
                        clearspawnentry();                          //Clear current spawn entry.
                        setspawnentry("name",   "flash");           //Aquire spawn entity by name.                       
	                    setspawnentry("coords", fX, fZ, fY);        //Spawn location.
                        vSpawn = spawn();                           //Spawn entity.
                        clearspawnentry();
                        changeentityproperty(vSpawn, "autokill", 1);

                        damageentity(vOpp, vAtk, iDamage * 0.1, iDrop, iType);  //Apply attack/damage. 
						iRush = getentityproperty(vAtk, "rush_count");
						changeentityproperty(vAtk, "rush_count", iRush + 1);
                    }
                }

				setglobalvar("hit"+i+".c", NULL());             //Clear expire time.
				setglobalvar("hit"+i+".t", NULL());             //Clear type.
				setglobalvar("hit"+i+".d", NULL());             //Clear damage.
				setglobalvar("hit"+i+".k", NULL());             //Clear drop.
                setglobalvar("hit"+i+".o", NULL());             //Clear target.
                setglobalvar("hit"+i+".a", NULL());             //Clear attacker.                
			}
			else
			{
				if(openborvariant("game_paused")==0)            //Game active (not paused)?
				{   
					setglobalvar("hit"+i+".c", cd-1);           //Decrement expire time.
				}
			}
		}
	}    
}