#include	"data/scripts/vars/constants.h"

#include	"data/scripts/dc_hud/main.c"
#include    "data/scripts/dc_fidelity/main.c"
#include    "data/scripts/dc_kanga/main.c"

#define DC_UPDATED_KEY_SCREEN          "key_screen"
#define OG_SCREEN_SIZE_MAX_X			openborvariant("hresolution")
#define OG_SCREEN_SIZE_MAX_Y			openborvariant("vresolution")

#define WAIT_NAME_FONT		3
#define SELECT_NAME_FONT	4
#define FONT_Y				18	// Vertical size of font (unavailable as of 2019-02-22). Includes margin.
#define SELECT_Y_BASE		75
#define SPACE_CHAR			"_"
#define	MAX_DRAW_SIZE		256 * 10
#define MAX_DRAW_SIZE_TIME	100

#define OG_SCREEN_BASE_POS_X openborvariant("hresolution") / 2
#define OG_SCREEN_BASE_POS_Y openborvariant("vresolution") / 2

#define OG_SCREEN_SCALE_MAX_X 256
#define OG_SCREEN_SCALE_MAX_Y 256

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
    dc_draw_select_screen();
    dc_draw_select_names();

    /* Draw enemy HUD. */
    dc_golden_axe_enemy_hud();

    /* Draw player HUD. */
    dc_hud_player_master();

    /*
    * Play any timed delay sounds.
    */
    dc_fidelity_play_timed();

    /* Loop entity collection. */
    int i = 0;
    int ent_count = openborvariant("count_entities");
    void entity_cursor = NULL();

    for (i = 0; i < ent_count; i++)
    {
        entity_cursor = getentity(i);

        /* Execute tint effect on entity. */
        dc_kanga_auto_tint(entity_cursor);

        /* Invisible when knocked down. */
        dc_auto_stealth(entity_cursor);

    }
   
}

/*
* Draw layers and animation for select screen.
* OpenBOR select screens are highly optimised at
* the cost of being mostly hardcoded and very
* plain looking. We could code our own through
* model switching in a regular stage, but I'd
* rather try dressing up the native select 
* screen first. :)
*/
void dc_draw_select_screen()
{    
    /* Not in select screen? Exit now! */
    if (!openborvariant("in_selectscreen"))
    {
        return;
    }

    
   
    /* 
    * It's more optimal to put loadsprite()
    * in another location that only runs one
    * time (ex: oncreate), but we're only using
    * these in the select screen, so we can
    * afford to trade some CPU cycles to keep 
    * everything here and easy to find.
    */

    void wall_screen = dc_get_screen(0, 480, 79);
    void wall_sprite = loadsprite("data/bgs/select_wall_0.png");
    int wall_sprite_size_x = getgfxproperty(wall_sprite, "width");
    int wall_sprite_offset_x = 0;

    drawspritetoscreen(wall_sprite, wall_screen, wall_sprite_offset_x, 0);
    drawspritetoscreen(wall_sprite, wall_screen, wall_sprite_offset_x + wall_sprite_size_x, 0);

    void common_drawmethod = openborvariant("drawmethod_common");
    void default_drawmethod = openborvariant("drawmethod_default");

    
    //set_drawmethod_property(common_drawmethod, "enable", 1);

    drawscreen(wall_screen, 0, 112, openborconstant("PANEL_Z"));

    //copy_drawmethod(default_drawmethod, common_drawmethod);
    //set_drawmethod_property(common_drawmethod, "enable", 0);

    //drawsprite(wall_sprite, wall_sprite_offset_x, 112, openborconstant("PANEL_Z"), 0);
    //drawsprite(wall_sprite, wall_sprite_offset_x + wall_sprite_size_x, 112, openborconstant("PANEL_Z"), 0);
    
    void floor_screen = dc_get_screen(1, 480, 81);
    void floor_sprite = loadsprite("data/bgs/select_floor_0.png");
    
    int floor_sprite_size_x = getgfxproperty(floor_sprite, "width");
    int floor_sprite_offset_x = 0;

    drawspritetoscreen(floor_sprite, floor_screen, floor_sprite_offset_x, 0);
    drawspritetoscreen(floor_sprite, floor_screen, floor_sprite_offset_x + floor_sprite_size_x, 0);

    set_drawmethod_property(common_drawmethod, "water_mode", openborconstant("WATER_MODE_SHEAR"));
    set_drawmethod_property(common_drawmethod, "water_size_begin", 1.0);
    set_drawmethod_property(common_drawmethod, "water_size_end", 2.0);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    drawscreen(floor_screen, 0, 191, openborconstant("PANEL_Z")+1);

    copy_drawmethod(default_drawmethod, common_drawmethod);
    set_drawmethod_property(common_drawmethod, "enable", 0);

    //drawsprite(floor_sprite, floor_sprite_offset_x, 191, openborconstant("PANEL_Z"), 0);
    //drawsprite(floor_sprite, floor_sprite_offset_x + floor_sprite_size_x, 191, openborconstant("PANEL_Z"), 0);

    void skeleton_sprite = loadsprite("data/bgs/select_skeleton_0.png");
    
    drawsprite(skeleton_sprite, 80, 102, openborconstant("PANEL_Z")+2, 1);
}

void dc_get_screen(int index, int size_x, int size_y)
{
    void screen;
    char screen_key;
    char size_x_key;
    char size_y_key;

    screen_key = DC_UPDATED_KEY_SCREEN + index;

    // Get current screen.
    screen = getlocalvar(screen_key);

    // If no screen is set up,
    // initialize it here.
    if (!screen)
    {
        // Allocate screen and use it to populate
        // the screen variable, then populate
        // background variable.
        screen = allocscreen(size_x, size_y);
        setlocalvar(screen_key, screen);
    }

    return screen;
}

// Caskey, Damon V.
// 2019-02-22
//
// Draws names of characters during select screen.
void dc_draw_select_names()
{
    // Don't waste any more cycles if we aren't 
    // in select screen.
    if (!openborvariant("in_selectscreen"))
    {
        return;
    }

    int i;
    int maxplayers;
    char name_full;
    char name_last;
    char name_first;

    int font;
    int x_base;
    int x_pos;
    int y_pos;
    int string_width;

    int section_size;
    int section_half;

    int elapsed_time;
    int select_time;

    void screen;

    int screen_scale_x;
    int screen_scale_y;

    int scale_add;

    int screen_width;
    int screen_height;


    elapsed_time = openborvariant("elapsed_time");
    maxplayers = openborvariant("maxplayers");

    // Divide up the screen into even sections for each player.
    section_size = openborvariant("hresolution") / maxplayers;
    section_half = section_size / 2;

    for (i = 0; i < maxplayers; i++)
    {
        // Get to start of our section, and add half to find the center.
        x_base = (dc_player_multiplier(i) * section_size) + section_half;

        name_full = getplayerproperty(i, "name");
        name_last = strinfirst(name_full, SPACE_CHAR);

        // No last name?
        if (name_last == -1)
        {
            x_pos = dc_center_string_x(x_base, name_full, WAIT_NAME_FONT);
            y_pos = dc_center_string_y(SELECT_Y_BASE, name_full, FONT_Y);

            screen_width = strwidth(name_full, WAIT_NAME_FONT);
            screen_height = FONT_Y;

            drawstring(x_pos, y_pos, WAIT_NAME_FONT, name_full);
            //drawstringtoscreen(screen, x_pos, y_pos, WAIT_NAME_FONT, name_full);			
        }
        else
        {
            // Get a Y center based on two lines (first name, last name).
            y_pos = dc_center_string_y(SELECT_Y_BASE, name_last, FONT_Y * 2);

            // Get first name string and center x position.
            name_first = strleft(name_full, strlength(name_full) - strlength(name_last));
            x_pos = dc_center_string_x(x_base, name_first, WAIT_NAME_FONT);

            drawstring(x_pos, y_pos, WAIT_NAME_FONT, name_first);
            //drawstringtoscreen(screen, x_pos, y_pos, WAIT_NAME_FONT, name_first);

            // Remove sapce character from last name.
            name_last = strright(name_last, 1);

            x_pos = dc_center_string_x(x_base, name_last, WAIT_NAME_FONT);

            // Add vertical font space.
            y_pos += FONT_Y;

            drawstring(x_pos, y_pos, WAIT_NAME_FONT, name_last);
            //drawstringtoscreen(screen, x_pos, y_pos, WAIT_NAME_FONT, name_last);

            screen_width = strwidth(name_first, WAIT_NAME_FONT);
            screen_height = FONT_Y;
        }

        //string_width = 20;
        // log("\n str w(" + i +"): +" + screen_width);
        //screen = dc_get_screen(i, screen_width, screen_height);
        //dc_draw_text_screen(screen, screen_scale_x, screen_scale_y);
    }

#undef SELECT_NAME_FONT
#undef SELECT_NAME_FONT_Y
#undef SELECT_Y_BASE
}

// Caskey, Damon V.
// 2019-02-22
//
// Return position to horizontaly center a string.
int dc_center_string_x(int x_base, char string, int font)
{
    return x_base - (strwidth(string, font) / 2);
}

// Caskey, Damon V.
// 2019-02-22
//
// Return position to horizontaly center a string. At time of
// coding, font height is not available, so we have to use
// a known static font size.
int dc_center_string_y(int y_base, char string, int font_size)
{
    return y_base - (font_size / 2);
}

// Caskey, Damon V.
// 2019-02-22
//
// Dirty function to deal with first player being in 
// the middle when we want to use player number as a
// position multiplier.
int dc_player_multiplier(int player)
{
    switch (player)
    {
    case 0:

        return 1;
        break;

    case 1:

        return 0;
        break;

    default:

        return player;
        break;
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
void dc_auto_stealth(void target)
{
    #define STEALTH_DISABLE     0
    #define STEALTH_ENABLE      1
    #define STEALTH_NO_ACTION   2

    int     exists;             // Entity exists flag.
    int     dead;               // Entity dead flag.
    char    model_name;         // Name of the base model.
    void    owner;              // Entity that spawned the target.
    int     drop;               // Falling (drop) state.
    int     action;             // Stealth setting to apply.
    int     stealth_current;    // Entity's current stealth.
    int     animation;          // target's current animation.


        // Make sure we got a valid target pointer.
        if(!target)
        {
            return;
        }

        // Make sure the entity exists in play. We perform this
        // check because it's possible for an entity to be
        // removed but its pointer is still valid.
        exists  = getentityproperty(target, "exists");

        if(!exists)
        {
            return;
        }

        // We're leaving dead enemies on the screen but
        // don't want to draw their HUD any more. For
        // this purpose the dead flag will work well
        // as a filter.
        dead = getentityproperty(target, "dead");

        if(dead)
        {
            return;
        }

        // Does the entity have an owner? If not, in this module
        // that means it is a projectile or special effect.
        owner = getentityproperty(target, "owner");

        if(owner)
        {
            return;
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
    

    #undef STEALTH_DISABLE
    #undef STEALTH_ENABLE
    #undef STEALTH_NO_ACTION
}
