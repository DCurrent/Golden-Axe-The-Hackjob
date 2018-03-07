#include	"data/scripts/vars/constants.h"

#import	"data/scripts/traileru.c"		//Shadow trails.
//#import	"data/scripts/com/ani0013.h"	//Jump animation if steping off an edge.

void main()
{
    void    target;                                                                           //Entity placeholder.
    void    color_table;                                                                           //Color array placeholder.
    char    cName;                                                                          //Entity default name.
    int     iAni;                                                                           //Animations.
	int		iKMap;                                                                          //KO map.
    int     iType;                                                                          //Entity type.
    int     iVRes   = openborvariant("vresolution");                                        //Current vertical resolution.
    int     entity_count;                                   //Current # of entities in play.
	int		iIndex;                                                                         //Player index.
    int     i;                                                                           //Entity counter.
    int     sprite_index;                                                                          //Sprite index.
    float   fCnt    = 0.0;                                                                  //General counter.
    float   fJar;                                                                           //Mp Jar count.
    float   health;                                                                         //Current health
    float   health_fraction;                                                                          //HP % of max.
    float   fFron   = 0.0;                                                                  //Front percentage (top 1/4 of HP)
    int     iDrop;                                                                          //Falling/Fallen AI flag.


	//Give Debug text a background.
	if (getglobalvar("debug_set"))
	{
		drawbox(0, 25, 480, 80, openborconstant("FRONTPANEL_Z"), RGB_BLACK, 6);
	}

	//tupdate();

	// Get number of entities in play and loop through
	// each of them.
	entity_count = openborvariant("count_entities");

	for(i=0; i<entity_count; i++)                                                         //Loop entity collection.
	{

		target = getentity(i);                                                             //Get entity handle.

		if(target                                                                             //Valid handle?
            && getentityproperty(target, "exists")                                            //Valid entity?
            && !getentityproperty(target, "dead"))                                            //Alive?
		{

            // Experiment to disable movement. Does not work.
			//changeplayerproperty(target, "playkeys", FLAG_NONE);

			iDrop   = getentityproperty(target, "aiflag", "drop");                            //Drop status.
            iType   = getentityproperty(target, "type");                                      //Get type.
            iAni    = getentityproperty(target, "animationid");                               //Get current animation.

            // Apply stealth when knocked down, with some
            // custom exceptions.
            auto_stealth(target);

		    if ((iType && iType == TYPE_PLAYER))												//Player type?
		    {
				iIndex	= getentityproperty(target, "playerindex");                           //Get player index.
				fJar	= getentityproperty(target, "mp")/10;                                 //MP jar count.
				health_fraction   = 4 * get_health_fraction(target);                                        //Get life % in quarters.
				sprite_index   = getindexedvar(IDXG_ICOJAR);                                            //Get magic jar sprite.

				for(fCnt=0; fCnt<fJar; fCnt++)                                              //Loop jar count.
				{
					drawsprite(sprite_index, iIndex*160+55+fCnt*11, iVRes-20, openborconstant("FRONTPANEL_Z")+18001);     //Draw magic jars
				}

				for(fCnt=0.0; fCnt<health_fraction; fCnt++)                                           //Loop each quater of life.
				{
					fFron   = health_fraction - fCnt;
                    sprite_index   = getindexedvar(lblock(fFron));                                 //Get life block sprite.

					drawsprite(sprite_index, iIndex*160+53+fCnt*26, iVRes-31, openborconstant("FRONTPANEL_Z")+18001);     //Draw life block.
				}
		    }
			else
			{
			    if(iDrop || getentityproperty(target, "aiflag", "inpain") || iAni == AC_DEFPOSE) //Getting ass kicked?
			    {
                    sprite_index	= getentityproperty(target, "spritea", "sprite", AC_ICONS, ICON_AIPAIN);    //Get AI pain icon.
			    }
                else
                {
                    sprite_index	= getentityproperty(target, "spritea", "sprite", AC_ICONS, ICON_AI);    //Get AI normal icon.
                }

                if(sprite_index)																	//Sprite valid?
                {
                    // Increment living entity counter.

                    health_fraction   = get_health_fraction(target);                                                              //Get life block sprite.
                    color_table    = getentityproperty(target, "colourmap");

                    changedrawmethod(NULL(), "table", color_table);
                    drawsprite(sprite_index, (iLiv*41), 4, openborconstant("FRONTPANEL_Z")+18000);                        //Draw icon.
                    changedrawmethod(NULL(), "table", NULL());

                    sprite_index   = getindexedvar(lblock(health_fraction));                                 //Get life block sprite.
                    drawsprite(sprite_index, 16+(iLiv*41), 8, openborconstant("FRONTPANEL_Z")+18000);						//Draw life block.
                }
			}
        }
	}
}

// Auto apply stealth.

// Most AI controlled models are set to chase mode to
// emulate how they behaved in the original Golden Axe,
// but we want them to ignore opponents who are
// knocked down.
//
// We'll do this by applying a universal stealth, with
// a couple of exceptions for specific game-play situations.
void auto_stealth(void target)
{
    #define STEALTH_DISABLE     0
    #define STEALTH_ENABLE      1
    #define STEALTH_NO_ACTION   2

    char    model_name;         // Name of the base model.
    void    owner;              // Entity that spawned the target.
    int     drop;               // Falling (drop) state.
    int     action;             // Stealth setting to apply.
    int     stealth_current;    // Entity's current stealth.
    int     animation;          // target's current animation.

    // Does the entity have an owner? If not, in this module
    // that means it is a projectile or special effect.
    owner = getentityproperty(target, "owner");

    if(!owner)
    {
        // Is the entity in a falling state?
        drop = getentityproperty(target, "aiflag", "drop");

        if(drop)
        {
            // Set stealth so opponents will ignore.
            action = 1;
        }
        else
        {
            // If not in a falling state, then we will default to
            // disabling stealth.
            action = STEALTH_DISABLE;

            // Don't disable stealth if an of the following conditions
            // are met. They are controlling stealth with other
            // functions that we don't want to interfere with.

            // - Yamoto: Joe's dog is an invincible decoration
            // until he specifically becomes part of the action.
            // Therefore he defaults with stealth so opponents
            // won't stupidly attack him.
            if(model_name == "yamoto")
            {
                action = STEALTH_NO_ACTION;
            }

            // - Alex in Riseattack: Alex's rise attack is a feign
            // death move allowing him to gain some space and come
            // up with a delayed attack. It uses stealth to work.
            if(model_name == "alex")
            {
                if(animation == openborconstant("ANI_RISEATTACK"))
                {
                    action = STEALTH_NO_ACTION;
                }
            }

            // - SLEEP animation. This is used for entities that
            // are on screen but not in action yet - like
            // Longmoan stomping on a peasant.
            if(animation == openborconstant("ANI_SLEEP"))
            {
                action = STEALTH_NO_ACTION;
            }
        }

        stealth_current = getentityproperty(target, "stealth");

        // This is where we apply the results of our stealth
        // conditionals. We might want to use stealth for its
        // intended purpose too, so let's accommodate here by only
        // adjusting stealth if it is within 1 of the binary 0/1 range.
        //
        // IOW, if an entity has 5 stealth, then it is clearly
        // meant to be stealthy by design, so don't mess that up
        // here. But if its stealth is only 1, then we can assume
        // it only has stealth because of a temporary condition like
        // falling and we may safely disable.
        switch(action)
        {
            case STEALTH_DISABLE:

                // Only disable stealth if it is
                // enabled but not higher than 1.
                if(stealth_current <= 1 && stealth_current > 0)
                {
                    changeentityproperty(target, "stealth", 0);
                }

                break;

            case STEALTH_ENABLE:

                // Only enable stealth if it is
                // disabled but higher than -1.
                if(stealth_current <= 0 && stealth_current > -1)
                {
                    changeentityproperty(target, "stealth", 1);
                }

                break;

            default:
            case STEALTH_NO_ACTION:
                break;
        }
    }

    #undef STEALTH_DISABLE
    #undef STEALTH_ENABLE
    #undef STEALTH_NO_ACTION
}

// Return a decimal fraction of
// current HP vs. max HP.
float get_health_fraction(void target)
{
	float health_current;   // Current HP.
	float health_max;       // Maximum HP.
	float result;           // Output.

	health_current  = 0.0 + getentityproperty(target, "health");
	health_max      = 0.0 + getentityproperty(target, "maxhealth");

	// Don't divide by 0!
	if(health_current && health_max)
    {
        result = health_current / health_max;
    }
    else
    {
        result = 0.0;
    }

	return result;
}

int lblock(float fPer){

    int sprite_index;

    if (fPer >= 0.75)
    {
        sprite_index = IDXG_BLOCBLU;  //Blue
    }
    else if (fPer >= 0.50)
    {
        sprite_index = IDXG_BLOCYEL;  //Yellow
    }
    else if (fPer >= 0.25)
    {
        sprite_index = IDXG_BLOCORA;  //Orange
    }
    else
    {
        sprite_index = IDXG_BLOCRED;  //Red
    }

    return sprite_index;
}
