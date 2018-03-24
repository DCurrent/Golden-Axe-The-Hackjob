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
