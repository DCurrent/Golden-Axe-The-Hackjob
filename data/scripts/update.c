#include	"data/scripts/vars/constants.h"

#import	"data/scripts/traileru.c"		//Shadow trails.
//#import	"data/scripts/com/ani0013.h"	//Jump animation if steping off an edge.

#define VAR_KEY_SPRITE_MAGIC_JAR            "mp_block"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE    "hp_blue"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW  "hp_yellow"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE  "hp_orange"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_RED     "hp_red"

/*
var percentColors = [
    { pct: 0.0, color: { r: 0xff, g: 0x00, b: 0 } },
    { pct: 0.5, color: { r: 0xff, g: 0xff, b: 0 } },
    { pct: 1.0, color: { r: 0x00, g: 0xff, b: 0 } } ];

var getColorForPercentage = function(pct) {
    for (var i = 1; i < percentColors.length - 1; i++) {
        if (pct < percentColors[i].pct) {
            break;
        }
    }
    var lower = percentColors[i - 1];
    var upper = percentColors[i];
    var range = upper.pct - lower.pct;
    var rangePct = (pct - lower.pct) / range;
    var pctLower = 1 - rangePct;
    var pctUpper = rangePct;
    var color = {
        // Find largest integer value less than or equal to given.
        r: Math.floor(lower.color.r * pctLower + upper.color.r * pctUpper),
        g: Math.floor(lower.color.g * pctLower + upper.color.g * pctUpper),
        b: Math.floor(lower.color.b * pctLower + upper.color.b * pctUpper)
    };
    return 'rgb(' + [color.r, color.g, color.b].join(',') + ')';
    // or output as hex if preferred
}
*/

void oncreate()
{
    // Magic jar
    setlocalvar(VAR_KEY_SPRITE_MAGIC_JAR, loadsprite("data/sprites/mpicon.gif"));

    // Life blocks
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE, loadsprite("data/sprites/life.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW, loadsprite("data/sprites/life2.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE, loadsprite("data/sprites/life3.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED, loadsprite("data/sprites/life4.png"));
}

void ondestroy()
{
    // Free the sprites we loaded.

    // Magic jar
    free(getlocalvar(VAR_KEY_SPRITE_MAGIC_JAR));

    // Life blocks
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED));
}

void main()
{
    void    target;                                                                           //Entity placeholder.
    void    color_table;                                                                           //Color array placeholder.
    char    cName;                                                                          //Entity default name.
    int     iAni;                                                                           //Animations.
	int		enemy_living_cursor = -1;                                                                   //Living enemies.
	int		iKMap;                                                                          //KO map.
    int     iType;                                                                          //Entity type.
    int     iVRes   = openborvariant("vresolution");                                        //Current vertical resolution.
    int     entity_count;                                   //Current # of entities in play.
	int		player_index;                                                                         //Player index.
    int     entity_cursor;                                                                              //Entity counter.
    int     i;                                                                              //General purpose cursor.
    int     sprite_index;                                                                          //Sprite index.
    float   fJar;                                                                           //Mp Jar count.
    float   health;                                                                         //Current health
    float   health_fraction;                                                                          //HP % of max.
    float   fFron   = 0.0;                                                                  //Front percentage (top 1/4 of HP)
    int     is_hurt;                                                                          //Falling/Fallen AI flag.


	//Give Debug text a background.
	if (getglobalvar("debug_set"))
	{
		drawbox(0, 25, 480, 80, openborconstant("FRONTPANEL_Z"), RGB_BLACK, 6);
	}

	//tupdate();

	// Get number of entities in play and loop through
	// each of them.
	entity_count = openborvariant("count_entities");

	for(entity_cursor=0; entity_cursor<entity_count; entity_cursor++)                                                         //Loop entity collection.
	{

		target = getentity(entity_cursor);                                                             //Get entity handle.

		if(target                                                                             //Valid handle?
            && getentityproperty(target, "exists")                                            //Valid entity?
            && !getentityproperty(target, "dead"))                                            //Alive?
		{

            // Experiment to disable movement. Does not work.
			//changeplayerproperty(target, "playkeys", FLAG_NONE);

			iType   = getentityproperty(target, "type");                                      //Get type.
            iAni    = getentityproperty(target, "animationid");                               //Get current animation.

            // Apply stealth when knocked down, with some
            // custom exceptions.
            auto_stealth(target);

            // Draw player HUD.
            dc_golden_axe_player_hud(target);

		    if (iType == TYPE_PLAYER)												//Player type?
		    {
				// Exported to function.
		    }
			else
			{
			    // Target getting whipped? If so get a "hurt" icon sprite.
			    // Otherwise just get a normal icon sprite.
			    is_hurt = dc_get_is_hurt(target);

			    if(is_hurt)
			    {
                    sprite_index	= getentityproperty(target, "spritea", "sprite", AC_ICONS, ICON_AIPAIN);
			    }
                else
                {
                    sprite_index	= getentityproperty(target, "spritea", "sprite", AC_ICONS, ICON_AI);
                }

                // Did we find a valid icon sprite? Then let's display it along with
                // a health sprite.
                if(sprite_index)
                {
                    // Increment living enemy cursor.
                    enemy_living_cursor++;

                    health_fraction   = get_health_fraction(target);
                    color_table    = getentityproperty(target, "colourmap");

                    // Get color table in use by target and apply it to the
                    // global drawmethod, and draw the icon sprite. This
                    // causes the icon sprite to appear using same color
                    // as the target entity (assuming it and the target
                    // entity's other sprites all use the same default color
                    // table, and they should).
                    //
                    // To get the position, we use a preset value that is equal
                    // to the icon, life block, and any extra margin padding.
                    // We then multiply that value by the current cursor for
                    // living enemies. When there are multiple enemy entities
                    // on screen, this causes their icons and life blocks to
                    // appear in a row across the screen.
                    //
                    // When the icon sprite is drawn, we immediately reset the
                    // global drawmthod color table to null.

                    //, and then
                    // reset global drawmthod.
                    changedrawmethod(NULL(), "table", color_table);
                    drawsprite(sprite_index, (enemy_living_count*41), 4, openborconstant("FRONTPANEL_Z")+18000);
                    changedrawmethod(NULL(), "table", NULL());

                    // Get and draw the appropriate life block sprite
                    // for health remaining.
                    sprite_index   = lblock(health_fraction);
                    drawsprite(sprite_index, 16+(enemy_living_count*41), 8, openborconstant("FRONTPANEL_Z")+18000);
                }
			}
        }
	}
}

// Return true if target is currently
// receiving an attack, being grappled,
// or otherwise taking punishment.
int dc_get_is_hurt(void target)
{
    int drop;   // Falling flag.
    int pain;   // Pain flag.
    int frozen; // Frozen flag.
    int seal;   // Seal factor.

    // Falling?
    drop = getentityproperty(target, "aiflag", "drop");

    if(drop)
    {
        return 1;
    }

    // In pain (reeling from a hit)?
    pain = getentityproperty(target, "aiflag", "pain");

    if(pain)
    {
        return 1;
    }

    // Frozen?
    frozen = getentityproperty(target, "frozen");

    if(frozen)
    {
        return 1;
    }

    // Special moves disabled? This is done in a grapple,
    // so its a good way to tell if target is being
    // thrown around.
    seal = getentityproperty(target, "seal")

    if(seal)
    {
        return 1;
    }

    // Made it this far, then we can return
    // false and exit.
    return 0;
}

// Draw player HUD, with icons, magic jars, and
// life blocks for the target entity.
void dc_golden_axe_player_hud(void target)
{
    #define HEALTH_BLOCK_MAX    4  // Maximum number of health blocks that can be displayed for a single HUD entry.
    #define MAGIC_BLOCK_MAX     10 // Maximum number of magic blocks.

    int     i;                      // Loop cursor.
    int     resolution_vertical;    // Screens vertical size in pixels.
    int     entity_type;
    int     player_index;
    int     magic_count;            // How many symbols (jars, blocks, etc.) of magic to display.
    int     sprite_index;           // Placeholder for sprite reference.
    float   health_fraction;        // A sub-division of current health percentage.
    float   block_fraction;    //

    // Make sure a valid type was found,
    // and that it is a player.
    entity_type = getentityproperty(target, "type");

    if(entity_type == openborconstant("TYPE_PLAYER"))
    {
        resolution_vertical = openborvariant("vresolution");
        player_index        = getentityproperty(target, "playerindex");
        magic_count	        = getentityproperty(target, "mp") / MAGIC_BLOCK_MAX;
        sprite_index        = getlocalvar(VAR_KEY_SPRITE_MAGIC_JAR);

        // Magic is simple.
        for(i=0; i<magic_count; i++)
        {
            drawsprite(sprite_index, player_index*160+55+i*11, resolution_vertical-20, openborconstant("FRONTPANEL_Z")+18001);     //Draw magic jars
        }

        // Our goal here is to replicate the Golden Axe style life
        // blocks, but also add in the feature from Altered Beast
        // the right most block would change color as health depleted
        // until it was gone, then onto the next block and so on.

        // To do this, we need to go through a few steps.
        //
        // First we get a decimal value of current remaining health. For
        // example, if health is currently 80 of a max 100, then we get
        // a value of 0.8.
        //
        // Next, we multiply the decimal value of 0.8 by the maximum
        // number of blocks that can be displayed. This gives us a
        // value of 3.2. Just for labeling, we call it health fraction.
        //
        // Now we run a loop, with the cursor incrementing by 1, and
        // stopping when the cursor > our health fraction. Inside the
        // loop, we subject the current cursor value from health fraction
        // value to get a value we'll call block percentage.
        //
        // The loop is essentially getting a sub percentage value of
        // for each block. We then feed that to a function that will
        // determine which color of block to display. In our example,
        // the first three blocks will get a value of > 1. So they get
        // the 100% block. The forth block ends up with a value of 0.2.
        // That means the block is at 20% and the block sprite function
        // will choose accordingly.
        //
        // In our example, this is what the loop looks like:
        //
        // Health: 80 of 100
        // 4 * (80 / 100) = 3.2
        //
        // *loop starts*
        //
        // 3.2 - 0 = 3.2: Block 1 - 100%
        // 3.2 - 1 = 2.2: Block 2 - 100%
        // 3.2 - 2 = 1.2: Block 3 - 100%
        // 3.2 - 3 = 0.2: Block 4 - 20%
        //
        // *Loop stops, four blocks are displayed*
        //
        // If health drops to 35, it would then look like this:
        //
        // Health: 35 of 100
        // 4 * (80 / 100) = 1.4
        //
        // *loop starts*
        //
        // 1.4 - 0 = 1.4: Block 1 - 100%
        // 1.4 - 1 = 0.4: Block 2 - 40%
        //
        // Loop stops, two blocks are displayed.

        // Get health %, multiplied by number of displayable blocks.
        health_fraction = HEALTH_BLOCK_MAX * get_health_fraction(target);

        // Loop each quarter of health.
        for(i=0; i < health_fraction; i++)
        {
            block_fraction = health_fraction - i;
            sprite_index   = lblock(block_fraction);                                 //Get life block sprite.

            drawsprite(sprite_index, player_index*160+53+i*26, resolution_vertical-31, openborconstant("FRONTPANEL_Z")+18001);     //Draw life block.
        }
    }

    #undef HEALTH_BLOCK_MAX
    #undef MAGIC_BLOCK_MAX
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
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE);
    }
    else if (fPer >= 0.50)
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW);
    }
    else if (fPer >= 0.25)
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE);
    }
    else
    {
        sprite_index = getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED);
    }

    return sprite_index;
}
