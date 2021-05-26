#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/soun0005.h"

//Projectile didhit script.
//Simple version for Golden Axe.

void main()
{    
    void    vSelf       = getlocalvar("self");                      //Caller
    void    vDef        = getlocalvar("damagetaker");               //Get defender.
    void	vOwn		= getentityproperty(vSelf, "owner");		//Get owner.
	int     iAggro      = getentityproperty(vSelf, "aggression");   //Get aggression.    
	
    if (iAggro)
    {
        if (iAggro == -1)
        {
            killentity(vSelf);
        }
        else
        {
            changeentityproperty(vSelf, "animation", iAggro);
        }
    }        
}



/*

#import "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants
#import "data/scripts/com/hit0002.h"
#import "data/scripts/com/host0001.h"

    void    vParent     = getentityproperty(vSelf, "parent");   //Parent.
    void    vTParent    = getentityproperty(vDef, "parent");    //Target Parent.
    int     iMP;                                                //Caller MP.
    int     iDMP;                                               //Defender MP.
    int     iHP;                                                //Caller HP.
    int     iDHP;                                               //Defender HP.    
    int     iAgg;                                               //Aggression setting.
    int     iX, iY, iZ;                                         //Locations.
    int     iRush;                                              //Rush count.

    First, let's see if the entity we just hit is a legitamite target.
    If not, we exit and do nothing. Since the projectile's attack box
    is configured to have no pause, no damage, and no flash, it will 
    appear in game as if the target was never hit at all.
    /*
    if (vParent == vDef)                                        //Defender is parent?
    {
        return;                                                 //Exit. This is where a boomerang "catch" can go.
    }
    
    if (vTParent)                                               //Target has a parent?
    {
        if(!host0001(vParent, vTParent))                        //Are the target's and caller's parents non hostile?                       
        {
            return;                                             //Exit.
        }
    }
    
    iMP     = getentityproperty(vSelf, "mp");                                               //Get MP.
    iHP     = getentityproperty(vSelf, "health");                                           //Get HP.
    iDMP    = getentityproperty(vDef, "mp");                                                //Get defender's MP.
    
    if (getentityproperty(vDef, "type") == openborconstant("TYPE_OBSTACLE") && iDMP)        //Target an obstacle and has MP?
    {   
        /*
        Since the defender is an obstacle with MP, then it must be another
        projectile. To simulate projectile priority, we'll use MP as a free variable.
        When two projectiles collide, both must have 2 or more MP, else they will
        both be unaffected. Otherwise the one with lower MP looses 1HP for each point 
        of difference. If MP is equal, both take the equal MP amount as HP damage. 
        
        0 MP = Only true obstacles have 0 MP. 
        1 MP = Intangible and has no effect/does not affect other projectiles.
        2+MP = Compare. If equal, both take the full MP as HP damage. Otherwise, looser
            takes the difference.

        Some examples of how to apply this system:

        1. Flame (I) vs. Knife (II):
            I   = 1MP, 2HP.
            II  = 1MP, 1HP.
            I & II collide. Both have 1MP, so neither takes any damage from the other.

            In Game: A light knife meets a wave of fire, but the fire is immaterial and 
            so they simply pass through each other.

        2. Hadouken (I) vs. Knife (II):
            I   = 2MP, 2HP.
            II  = 3MP, 3HP.
            I & II collide. II has 1 more MP, so I looses the difference (1HP) and is destroyed. II is unaffected.

            In Game: A light knife is no match for the Hadouken and gets
                knocked cleanly aside while the Hadouken continues unscathed.

        3. Hadouken (I) vs. Hadouken (II):
            I   = 3MP, 3HP.
            II  = 3MP, 3HP.
            I & II collide. MP is equal, so both loose 3HP and are destroyed.

            In Game: Classic projectile war. Hadoukens hit and negate each other.

        4. Hadouken (I) vs. Shinku Hadouken (II):
            I   = 3MP, 3HP.
            II  = 3MP, 15HP.
            I & II collide. MP is equal so both loose 3HP. I is destroyed, II continues
                and may withstand 4 more similar collisions.

            In Game: Ryu blasts through several enemy projectils with his Shinku Hadouken. It
                plows over 4 lesser projectiles and negates head to head with a 5th.

        5. Geki Hishoken (I) vs. Hadouken (II):
            I   = 20MP, 1000HP
            II  = 3MP,  3HP
            I & II collide. I has greater MP by 17, so II looses 17HP and is destroyed. I is unaffected.

            In Game: Andy's short range energy attack is effectivly non negatable and easily stops most normal
            projectiles while still hitting anyone nearby.

        6. Geki Hishoken (I) vs. Haohshokoken (II):
            I   = 15MP, 1000HP
            II  = 20MP, 20HP
            I & II collide. II has greater MP by 5, so I looses 5HP. I easily withstands the loss. II is unaffected.
        
            In Game: Ryo's Haohshoken and Andy's Geki Hishoken hit each other with almost no effect. Both
            continue unhindered; Andy is almost certain to be hit, but Ryo could be hit as well if he was 
            close enough to Andy.

        7. Haohshokoken (I) vs. Haohshokoken (II):
            I   = 20MP, 20HP
            II  = 20MP, 20MP
            I & II collide. MP is equal, so both loose 20HP. Both are destroyed.
        
            In Game: One Haohshokoken projectile meets another. While both are capable
            of overpowering and eliminating most other projectiles, they negate each other.
        *       

        iDHP    = getentityproperty(vDef, "health");                                        //Get defender's HP.       
        
        changeentityproperty(vParent, "opponent", vTParent);                                //Set parent's opponent to target's parent.
        changeentityproperty(vTParent, "opponent", vParent);                                //Set target's parent opponent to caller's parent.

        if (iMP == 1 || iDMP == 1)                                                          //Either have 1 MP? 
        {
            return;                                                                         //One or the other cannot be hit by a projectile at all. Exit entire script.
        }
        else if (iMP > 1 && iDMP > 1)                                                       //Both have MP > 1?
        {
            if (iMP == iDMP)                                                                //MP equal?
            {
                iHP = iHP - iDMP;                                                           //Caller looses MP amount from HP.
                iDHP = iDHP - iMP;                                                          //Defender looses MP amount from HP.
            }
            else if (iMP > iDMP)                                                            //Caller MP higher?
            {
                iDHP = iDHP - (iMP - iDMP);                                                 //Target looses difference.
            }
            else if (iMP < iDMP)                                                            //Target MP higher?
            {
                iHP = iHP - (iDMP - iMP);                                                   //Caller looses difference.
            }
        }
        
        if (iDHP < 2)                                                                       //Defender at less then 2 HP?
        { 
            iDHP = 1;                                                                       //Set to 1 HP.
            changeentityproperty(vDef, "animation", getentityvar(vDef, IDXE_NEXTANI2));          //Set animation.
            changeentityproperty(vDef, "velocity", 0, 0, 0);                                //Stop movement.
        }        
        if (iHP < 2)                                                                        //Caller HP set to less then 2HP?
        { 
            iHP = 1;                                                                        //Set to 1 HP.
            changeentityproperty(vSelf, "animation", getentityvar(vSelf, IDXE_NEXTANI2));        //Set animation.
            changeentityproperty(vSelf, "velocity", 0, 0, 0);                               //Stop movement.
            return;                                                                         //Exit. 
        }
        
        changeentityproperty(vDef, "health", iDHP);                                         //Apply final HP loss to defender.        
        changeentityproperty(vSelf, "health", iHP);                                         //Apply final HP loss to caller.        
    }
    else
    {
        /*
        The entity we just hit wasn't a projectile. So instead we need to know how much penetration 
        projectile will have (how many times it can hit before stopping). Since a projectile 
        does not actively attack, we'll use aggression setting as a "free" entity variable.    
        
        -1  = Projectile never stops until offscreen (or destroyed by outside action).
        0   = Standard setting. Projectile can hit one time.
        1+  = Number of extra hits projectile can perform before negating itself.       
        *
        
        iAgg = getentityproperty(vSelf, "aggression");
        changeentityproperty(vDef, "opponent", vParent);                                    //Set Defender's opponent to parent.
        changeentityproperty(vParent, "opponent", vDef);                                    //Set Parent's opponent to Defender.

        if (iAgg == 0)                                                                      //Aggression 0?
        {
            changeentityproperty(vSelf, "animation", getentityvar(vSelf, "dc_next_animation_id"));         //Set animation.
            changeentityproperty(vSelf, "velocity", 0, 0, 0);                               //Stop movement.
        }
        else if (iAgg > 0)                                                                  //Agression 1+?
        {
            changeentityproperty(vSelf, "aggression", --iAgg);                              //Decrement aggression.
        }

        /*
        On its own the projectile has no hit flash, so let's take care of that here.
        *
        iX = openborvariant("lasthitx") - openborvariant("xpos");                           //Last hit X - X pos.
        iY = openborvariant("lasthita");                                                    //Last hit Y.
        iZ = openborvariant("lasthitz");                                                    //Last hit Z.
        //summ0001("flash", "flash", 0, 1, iX, iY, iZ, 1, 0, 0, 1);                           //Spawn flash.    
    
        iRush = getentityproperty(vParent, "rush_count");
	    changeentityproperty(vParent, "rush_count", iRush + 1);                             //Increment parent's rush count.

        hit0002();                                                                          //Call primary hit function.
    }