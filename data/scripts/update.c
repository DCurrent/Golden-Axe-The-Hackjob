#include	"data/scripts/vars/constants.h"

#include	"data/scripts/dc_hud/main.c"

#import	"data/scripts/traileru.c"		//Shadow trails.
//#import	"data/scripts/com/ani0013.h"	//Jump animation if steping off an edge.


void oncreate()
{
    dc_preload_hud_sprites();
}

void ondestroy()
{
    dc_unload_hud_sprites();
}

void main()
{
	//Give Debug text a background.
	if (getglobalvar("debug_set"))
	{
		drawbox(0, 25, 480, 80, openborconstant("FRONTPANEL_Z"), RGB_BLACK, 6);
	}

	//tupdate();

    // Run alignment text.
    dc_draw_grid();

    // Draw enemy HUD.
    dc_golden_axe_enemy_hud();

    // Draw player HUD.
    dc_golden_axe_player_hud();

    // Apply stealth when knocked down, with some
    // custom exceptions.
    auto_stealth();
}



// Draw player HUD, with icons, magic jars, and
// life blocks for the target entity.
void dc_golden_axe_player_hud()
{
    #define HEALTH_BLOCK_MAX        4   // Maximum number of health blocks that can be displayed for a single HUD entry.
    #define MAGIC_BLOCK_MAX         10  // Maximum number of magic blocks.

    #define PLAYER_HUD_WIDTH        160 // Total width of each player HUD (with padding).
    #define MP_AREA_MARGIN_LEFT     56  // Left of player HUD to first magic block.
    #define MP_BLOCK_MARGIN_LEFT    2
    #define MP_BLOCK_MARGIN_RIGHT   3

    void    target;                 // Target entity
    int     max_players;            // Number of available players.
    int     i;                      // Loop cursor.
    int     exists;                 // Entity exists flag.
    int     dead;                   // Entity dead flag.
    int     resolution_y;           // Screens vertical size in pixels.
    int     player_index;
    int     magic_count;            // How many symbols (jars, blocks, etc.) of magic to display.
    int     sprite_index;           // Placeholder for sprite reference.
    float   health_fraction;        // A sub-division of current health percentage.
    float   block_fraction;         //
    int     block_size_h;           // Size of mp block 9after OpenBOR auto trims).
    int     block_space;            // Size of mp block with margins included.
    int     block_position_left;    // Starting position of mp blocks in each player's HUD.
    int     block_position_x;       // X position of an individual mp block.
    int     block_position_Y;       // Y position of an individual mp block.

    // Get and loop through player collection.
    max_players = openborvariant("maxplayers");

    for(player_index=0; player_index<max_players; player_index++)
    {
        // Get target entity for this loop increment.
        target = getplayerproperty(player_index, "entity");

        // Make sure we got a valid target pointer.
        if(!target)
        {
            continue;
        }

        // Make sure the entity exists in play. We perform this
        // check because it's possible for an entity to be
        // removed but its pointer is still valid.
        exists  = getentityproperty(target, "exists");

        if(!exists)
        {
            continue;
        }

        // We're leaving dead enemies on the screen but
        // don't want to draw their HUD any more. For
        // this purpose the dead flag will work well
        // as a filter.
        dead = getentityproperty(target, "dead");

        if(dead)
        {
            continue;
        }

        resolution_y    = openborvariant("vresolution");
        magic_count     = getentityproperty(target, "mp") / MAGIC_BLOCK_MAX;
        sprite_index    = getlocalvar(VAR_KEY_SPRITE_MAGIC_JAR);

        // Magic meter.

        // We're drawing MP blocks in a row, so Y position
        // is always the same.
        block_position_Y = resolution_y-20;

        // X position will depend on several factors. Some
        // we can do here, and the rest will need to be
        // in a loop.
        //
        // Let's get the width of our meter block.
        // Remember that OpenBOR auto trims all sprites
        // as it loads them, so the size will reflect that.
        block_size_h = getgfxproperty(sprite_index, "srcwidth");

        // Now we add the block's margins, and that will get
        // total spacing for one block.
        block_space = block_size_h + MP_BLOCK_MARGIN_LEFT + MP_BLOCK_MARGIN_RIGHT;

        // Our starting position will be the leftmost of
        // current player's (in loop) HUD area. To get this,
        // we multiply current player index by total X size of
        // the player HUD.
        block_position_left = player_index * PLAYER_HUD_WIDTH;

        // Add the meter area's left margin to space it
        // out from the start of player HUD area.
        block_position_left += MP_AREA_MARGIN_LEFT;

        for(i=0; i<magic_count; i++)
        {
            // Multiply the total X space of a block
            // by the current cursor position. This places
            // each block in a row, left to right.
            block_position_x = i * block_space;

            // Now add the margin from player HUD to start
            // of block area to align blocks properly with
            // player HUD design.
            block_position_x += block_position_left;

            // Draw the MP sprite.
            drawsprite(sprite_index, block_position_x, block_position_Y, openborconstant("FRONTPANEL_Z")+18001);
        }

        // Health Meter
        //
        // Positioning works identically to MP meter. but health
        // meter also includes a color keying capability.

        // Color keying
        //
        // Our goal here is to replicate the Golden Axe style life
        // blocks, but also add in the feature from Altered Beast
        // the right most block would change color as health depleted
        // until it was gone, then onto the next block and so on.
        //
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

        // Get Y position.
        block_position_Y = resolution_y-31;

        #define HP_BLOCK_MARGIN_LEFT 2
        #define HP_BLOCK_MARGIN_RIGHT 2


        // Loop each quarter of health.
        for(i=0; i < health_fraction; i++)
        {
            block_fraction = health_fraction - i;
            sprite_index   = dc_get_block_large(block_fraction);

            // Positioning works same way as MP meter, but
            // all initial math work has to be in loop since
            // we don't know until in side the loop which
            // sprite is in use.
            block_size_h = getgfxproperty(sprite_index, "srcwidth");

            // Now we add the margins, and that will get total
            // spacing for one block.
            block_space = block_size_h + HP_BLOCK_MARGIN_LEFT + HP_BLOCK_MARGIN_RIGHT;

            // Our starting position will be the leftmost of
            // current player's (in loop) HUD area.
            block_position_left = player_index * PLAYER_HUD_WIDTH;

            // Multiply the total X space of an MP block
            // by the current cursor position. This places
            // each block in a row, left to right.
            block_position_x = i * block_space;

            // Now add the margin from player HUD to start
            // of magic area to align blocks properly with
            // player HUD design.
            block_position_x += MP_AREA_MARGIN_LEFT;

            drawsprite(sprite_index, player_index*160+53+i*26, block_position_Y, openborconstant("FRONTPANEL_Z")+18001);
        }
    }

    #undef HEALTH_BLOCK_MAX
    #undef MAGIC_BLOCK_MAX

    #undef PLAYER_HUD_WIDTH
    #undef MP_AREA_MARGIN_LEFT
    #undef MP_BLOCK_MARGIN_LEFT
    #undef MP_BLOCK_MARGIN_RIGHT
}

// Auto apply stealth.

// Most AI controlled models are set to chase mode to
// emulate how they behaved in the original Golden Axe,
// but we want them to ignore opponents who are
// knocked down.
//
// We'll do this by applying a universal stealth, with
// a couple of exceptions for specific game-play situations.
void auto_stealth()
{
    #define STEALTH_DISABLE     0
    #define STEALTH_ENABLE      1
    #define STEALTH_NO_ACTION   2

    int     i;                  // Loop cursor.
    int     entity_count;       // Entity counter.
    int     exists;             // Entity exists flag.
    int     dead;               // Entity dead flag.
    void    target;             // Target entity.
    char    model_name;         // Name of the base model.
    void    owner;              // Entity that spawned the target.
    int     drop;               // Falling (drop) state.
    int     action;             // Stealth setting to apply.
    int     stealth_current;    // Entity's current stealth.
    int     animation;          // target's current animation.


    entity_count    = openborvariant("count_entities");

    // Loop through entity collection.
    for(i=0; i<entity_count; i++)
    {
        // Get target entity for this loop increment.
        target = getentity(i);

        // Make sure we got a valid target pointer.
        if(!target)
        {
            continue;
        }

        // Make sure the entity exists in play. We perform this
        // check because it's possible for an entity to be
        // removed but its pointer is still valid.
        exists  = getentityproperty(target, "exists");

        if(!exists)
        {
            continue;
        }

        // We're leaving dead enemies on the screen but
        // don't want to draw their HUD any more. For
        // this purpose the dead flag will work well
        // as a filter.
        dead = getentityproperty(target, "dead");

        if(dead)
        {
            continue;
        }

        // Does the entity have an owner? If not, in this module
        // that means it is a projectile or special effect.
        owner = getentityproperty(target, "owner");

        if(owner)
        {
            continue;
        }

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

// Caskey, Damon V.
// 2018-03-21
//
// Draw a grid from top of screen to
// bottom in order to test alignment of
// screen and objects. Adjust constants
// for varying needs.
void dc_draw_grid()
{
    #define INCREMENT       10  // What line spaces to draw line and text. Ex: 10 = at every tenth line.
    #define TEXT_MODE       1   // Show text readout of line position. 1 = Text on.
    #define GRID_V_X        0   // Starting position of vertical scale grid lines.
    #define GRID_V_WIDTH    10  // Horizontal width of vertical scale grid lines.
    #define SPACING_X       5   // Space from end of line to X start of text.
    #define SPACING_Y       -5  // Space from end of line to top of text.
    #define FONT            2   // Font for text.
    #define COLOR           1   // Color index for line.
    #define ALPHA           0   // Alpha setting for line.

    int pos_x_end;      // End line here.
    int pos_y_start;    // Draw line from here (y axis).
    int pos_y_end;      // End line here.
    int text_pos_x;     // Draw text here (x axis).
    int text_pos_y;     // Draw text here (y axis).

    int pos_z;          // Depth position of drawn items.
    int i;              // Loop cursor.
    int screen_x;       // Screen size (x axis).
    int screen_y;       // Screen size (y axis).

    // get screen limits.
    screen_x = openborvariant("hresolution");
    screen_y = openborvariant("vresolution");

    // Z will need to be in front of everything.
    pos_z = openborconstant("FRONTPANEL_Z")+20000;

    pos_x_end = GRID_V_X + GRID_V_WIDTH;

    // Loop each line along vertical axis from top of
    // screen to bottom.
    for(i=0; i<screen_y; i++)
    {
        // We want to draw a line at 0 and every INCREMENT pixels after.
        // If we're past 0 and not divisible by INCREMENT, then
        // exit this increment of the loop to skip drawing.
        if(i > 0)
        {
            if(i%INCREMENT != 0)
            {
                continue;
            }
        }

        // Use cursor for y position.
        pos_y_start = i;
        pos_y_end = i;

        // Draw the line.
        drawline(GRID_V_X, pos_y_start, pos_x_end, pos_y_end, pos_z, COLOR, ALPHA);

        // Handle the text.
        if(TEXT_MODE == 1)
        {
            // Space the text out
            text_pos_x = pos_x_end + SPACING_X;
            text_pos_y = pos_y_end + SPACING_Y;

            // Draw the text.
            drawstring(text_pos_x, text_pos_y, FONT, i);
        }
    }

    #undef INCREMENT
    #undef TEXT_MODE
    #undef GRID_V_X
    #undef GRID_V_WIDTH
    #undef SPACING_X
    #undef SPACING_Y
    #undef FONT
    #undef COLOR
    #undef ALPHA
}
