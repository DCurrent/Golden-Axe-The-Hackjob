#include "data/scripts/vars/constants.h"	//http://www.caskeys.com/dc/?p=1314#constants

#import "data/scripts/com/draw0001.h"		//Drawing functions.
#import "data/scripts/com/name0001.h"		//Random name.
#import "data/scripts/com/soun0005.h"		//Random capable stereo sound player.
#import "data/scripts/com/path0002.h"		//Folder.

#import "data/scripts/com/dc_respawn_body.c"		// Find entity with same name and move to it.

void z_spawn(void vEnt)
{
    /*
	Damon V. Caskey
	z_spawn
	2011_03_14 (moved from z_spawn.c main)
	~2011_03_15

	Generic spawn functions for most level spawns.
	*/

	int     iMap;											//Caller's starting map.
    int     iKOMap;											//Caller's KO map.
    int     iAni;                                           //Animation ID.
	char	cDModel;										//Default model
	char	cModel;											//Current model.
	int		iSpr;
	void	vPEnt;
	int		iIndex;
	int		iSType;
    int     iType;
    int     iAggro;                                         //Aggression setting.
    int     iMaxHP;                                         //Maximum health.
    int     iMaxMP;                                         //Maximum MP.

	if (!vEnt){	vEnt = getlocalvar("self");	}				//Self default.

    iType   =   getentityproperty(vEnt, "type");            //Get caller type.
	iSType	=   getentityproperty(vEnt, "spawntype");		//Get caller exists property.
	iMap	=	getentityproperty(vEnt, "map");				//Caller's starting map.
	iKOMap	=	getentityproperty(vEnt, "komap", 0);		//Caller's KO map.
    iAggro  =   getentityproperty(vEnt, "aggression");      //Caller's Aggression setting.
    iMaxHP  =   getentityproperty(vEnt, "maxhealth");       //Caller's Maximum health.
    iMaxMP  =   getentityproperty(vEnt, "maxmp");           //Caller's Maximum MP.
	cDModel	=	getentityproperty(vEnt, "defaultmodel");	//Get default model.
	cModel	=	getentityproperty(vEnt, "model");			//Current model.
	iSpr    =   getentityproperty(vEnt, "icon", 0);         //Main icon.

    /*
	log("\n z_spawn, cDModel:" + cDModel);
	log("\n z_spawn, cModel:" + cModel);
	log("\n z_spawn, icon:" + iSpr);
	log("\n z_spawn, playerindex:" + iIndex);
	log("\n z_spawn, icon:" + getentityproperty(vEnt, "icon", 0));
	log("\n z_spawn, type:" + getentityproperty(vEnt, "type"));
	log("\n z_spawn, spawntype:" + getentityproperty(vEnt, "spawntype"));
    */

    /*
    Model type and think switch. Models are initially Player type and switched to Enemy here if they are actualy
    level spawns. This allows a single model text to serve as Player, Enemy, and NPC versions of a character.
    Memory and production time savings and from eliminating two redundant copies of the same model should be fairly obvious.
    
	~2011_07_27. Discovered small but so far insurmountable bug where playable and enemy versions of same cahracter interact.
	When scripted damage is applied, the damaging entity imediatly ceases performing animation certain scripts (inconsistent).

    if(iType == TYPE_PLAYER && iSType == 1)
    {
        iType = TYPE_ENEMY;                                        //Set ENEMY type.

		changeentityproperty(vEnt, "name", getentityproperty(vEnt, "defaultname")+"_e");
        changeentityproperty(vEnt, "type", iType);              //Apply type.
        changeentityproperty(vEnt, "think", "common_think");    //Apply common_think.
        changeentityproperty(vEnt, "hostile", "TYPE_PLAYER", "TYPE_NPC");
        changeentityproperty(vEnt, "candamage", "TYPE_PLAYER", "TYPE_NPC", "TYPE_OBSTACLE");
        changeentityproperty(vEnt, "projectilehit", "TYPE_ENEMY", "TYPE_OBSTACLE");
    }
	
    /*
    log("\n z_spawn, type:" + getentityproperty(vEnt, "type"));
    log("\n --------------------------------------------------------- \n");
    */

    //Golden Axe--------------------------------------------------------------------------------------------------------
    if(iType == TYPE_PLAYER)                                                       //Player type?
	{
       //bind0017(vEnt, A_RISE, -1, 1, 0, 0, 0, 0, 0, 0);							//Find old corpse and spawn there.
       
       dc_respawn_body(vEnt, A_RISE);

		if(getentityproperty(vEnt, "animvalid", A_SPECIAL))
        {
            changeentityproperty(vEnt, "energycost", "disable", A_SPECIAL, TYPE_PLAYER);
        }
		if(getentityproperty(vEnt, "animvalid", A_SPECIAL2))
        {
            changeentityproperty(vEnt, "energycost", "disable", A_SPECIAL2, TYPE_PLAYER);
        }
	}
    else
    {
        //Store some basic entity properties so we can reapply them after damage (bug workaround).
        setentityvar(vEnt, IDXE_MAXHP, iMaxHP);                                      //Store MaxHP.
        setentityvar(vEnt, IDXE_MAXMP, iMaxHP);                                      //Store MaxMP.
        setentityvar(vEnt, IDXE_AGGRO, iAggro);                                      //Store Aggro.

        if(getentityproperty(vEnt, "animvalid", A_FSPECIAL10))
        {
            changeentityproperty(vEnt, "energycost", "disable", A_FSPECIAL10, -2);
        }

        if(iKOMap && iMap == iKOMap-1)                                          //"Dark" map?
        {
            changeentityproperty(vEnt, "animation", A_RESPAWN);                 //Play respawn animation.

            if(getentityproperty(vEnt, "animvalid", A_FSPECIAL10))              //Has teleport move?
            {
                changeentityproperty(vEnt, "energycost", "disable", A_FSPECIAL10, 0);  //Enable teleport.
            }
        }
        /*
		else if(getglobalvar("sleep")==1)                                       //Global sleep var on?
        {
            changeentityproperty(vEnt, "stealth", 1);                           //Become invisible to AI.
            changeentityproperty(vEnt, "animation", A_SLEEP);                   //Go into sleep animation.
        }
		*/		
    }
    //------------------------------------------------------------------------------------------------------------------

    if (iKOMap && iMap == iKOMap)                                               //KO map?
    {
        //rema0002(vEnt,0,0,0,0,0);                                               //Apply random remap.
    }

	//soun0008(vEnt, 0,0,0,0,0,0);                                              //Set up sound counts.
    name0001(vEnt,0,0,0);                                                       //Assign random alias (if starting alias = "Random").
    draw0001(vEnt);                                                             //Apply draw settings.

}



