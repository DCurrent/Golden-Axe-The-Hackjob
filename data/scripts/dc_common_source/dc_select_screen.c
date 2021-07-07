#include    "data/scripts/dc_eggball/main.c"
#include    "data/scripts/dc_gauntlet/main.c"

#ifndef DC_MODULE_SELECT_SCREEN_CONFIG
#define DC_MODULE_SELECT_SCREEN_CONFIG 1

#define WAIT_NAME_FONT		3
#define DC_UPDATED_KEY_SCREEN          "key_screen"
#define OG_SCREEN_SIZE_MAX_X			openborvariant("hresolution")
#define OG_SCREEN_SIZE_MAX_Y			openborvariant("vresolution")


#define SELECT_NAME_FONT	4
#define FONT_Y				18	// Vertical size of font (unavailable as of 2019-02-22). Includes margin.
#define SELECT_Y_BASE		100
#define SPACE_CHAR			"_"
#define	MAX_DRAW_SIZE		256 * 10
#define MAX_DRAW_SIZE_TIME	100

#define OG_SCREEN_BASE_POS_X openborvariant("hresolution") / 2
#define OG_SCREEN_BASE_POS_Y openborvariant("vresolution") / 2

#define OG_SCREEN_SCALE_MAX_X 256
#define OG_SCREEN_SCALE_MAX_Y 256

#define OG_SELECT_SCREEN_HIGHLIGHT_MODEL "select_waiting_flame"
#define OG_SELECT_SCREEN_HIGHLIGHT_ENTITY_KEY "dc_select_hl"

#endif

void dc_module_select_screen_initialize()
{
    void sprites_list = array(0);
    
    set(sprites_list, "column", loadsprite("data/bgs/select_column_0.png"));
    set(sprites_list, "floor", loadsprite("data/bgs/select_floor_0.png"));
    set(sprites_list, "select_text", loadsprite("data/bgs/select_text_0.png"));
    set(sprites_list, "skeleton", loadsprite("data/bgs/select_skeleton_0.png"));
    set(sprites_list, "wall", loadsprite("data/bgs/select_wall_0.png"));

    setlocalvar("dc_mssi_sprites", sprites_list);

    void screens_list = array(0);

    setlocalvar("dc_mssi_screens", screens_list);
}

void dc_module_select_screen_terminate()
{

    log("\n\n DC Module Select Screen - Freeing resources");

    dc_module_select_screen_unload_screens();
    dc_module_select_screen_unload_sprites();

    log("\n ...done. \n");
}

void dc_module_select_screen_unload_screens()
{
    void screens_list = getlocalvar("dc_mssi_screens");

    /*
    * Set cursor to first element of array.
    * Then iterate through all entries and
    * free each one.
    */

    log("\n\t Freeing screens");

    int size = size(screens_list);
    int i = 0;
    void screen = NULL();

    reset(screens_list);

    for (i = 0; i < size; i++)
    {
        screen = value(screens_list);

        log("\n\t\t" + key(screens_list) + ", " + screen);

        free(screen);

        next(screens_list);
    }

    /*
    * Now we free the array itself, and then
    * delete the variable that held its pointer.
    */

    log("\n\t Freeing screen list");

    free(screens_list);

    setlocalvar("dc_mssi_screens", NULL());
}

void dc_module_select_screen_unload_sprites()
{
    void sprites_list = getlocalvar("dc_mssi_sprites");

    /*
    * Set cursor to first element of array.
    * Then iterate through all entries and
    * free each one.
    */

    log("\n\t Freeing sprites");

    int size = size(sprites_list);
    int i = 0;
    void sprite = NULL();

    reset(sprites_list);

    for (i = 0; i < size; i++)
    {
        sprite = value(sprites_list);

        log("\n\t\t" + key(sprites_list) + ", " + sprite);

        free(sprite);

        next(sprites_list);
    }

    /*
    * Now we free the array itself, and then
    * delete the variable that held its pointer.
    */

    log("\n\t Freeing sprite list");

    free(sprites_list);

    setlocalvar("dc_mssi_sprites", NULL());
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

    void sprites_list = getlocalvar("dc_mssi_sprites");

    void wall_screen = dc_get_screen(0, 480, 84);
    void wall_sprite = get(sprites_list, "wall");
    int wall_sprite_offset_x = 0;

    dc_draw_sprite_to_screen_width(wall_screen, wall_sprite, wall_sprite_offset_x, 0);

    //drawspritetoscreen(wall_sprite, wall_screen, wall_sprite_offset_x, 0);
   // drawspritetoscreen(wall_sprite, wall_screen, wall_sprite_offset_x + wall_sprite_size_x, 0);

    void common_drawmethod = openborvariant("drawmethod_common");
    void default_drawmethod = openborvariant("drawmethod_default");


    //set_drawmethod_property(common_drawmethod, "enable", 1);

    drawscreen(wall_screen, 0, 94, openborconstant("PANEL_Z"));

    //copy_drawmethod(default_drawmethod, common_drawmethod);
    //set_drawmethod_property(common_drawmethod, "enable", 0);

    //drawsprite(wall_sprite, wall_sprite_offset_x, 112, openborconstant("PANEL_Z"), 0);
    //drawsprite(wall_sprite, wall_sprite_offset_x + wall_sprite_size_x, 112, openborconstant("PANEL_Z"), 0);

    void floor_screen = dc_get_screen(1, 480, 94);
    void floor_sprite = get(sprites_list, "floor");
    int floor_sprite_offset_x = 0;

    dc_draw_sprite_to_screen_width(floor_screen, floor_sprite, floor_sprite_offset_x, 0);

    set_drawmethod_property(common_drawmethod, "water_mode", openborconstant("WATER_MODE_SHEAR"));
    set_drawmethod_property(common_drawmethod, "water_size_begin", 1.0);
    set_drawmethod_property(common_drawmethod, "water_size_end", 2.0);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    drawscreen(floor_screen, 0, 178, openborconstant("PANEL_Z") + 1);

    copy_drawmethod(default_drawmethod, common_drawmethod);
    set_drawmethod_property(common_drawmethod, "enable", 0);

    //drawsprite(floor_sprite, floor_sprite_offset_x, 191, openborconstant("PANEL_Z"), 0);
    //drawsprite(floor_sprite, floor_sprite_offset_x + floor_sprite_size_x, 191, openborconstant("PANEL_Z"), 0);

    void ceiling_screen = dc_get_screen(1, 480, 94);

    dc_draw_sprite_to_screen_width(ceiling_screen, floor_sprite, floor_sprite_offset_x, 0);

    set_drawmethod_property(common_drawmethod, "water_mode", openborconstant("WATER_MODE_SHEAR"));
    set_drawmethod_property(common_drawmethod, "water_size_begin", 2.0);
    set_drawmethod_property(common_drawmethod, "water_size_end", 1.0);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    drawscreen(ceiling_screen, 0, 0, openborconstant("PANEL_Z") + 1);

    copy_drawmethod(default_drawmethod, common_drawmethod);
    set_drawmethod_property(common_drawmethod, "enable", 0);


    /* Seleton */

    void skeleton_sprite = get(sprites_list, "skeleton");

    drawsprite(skeleton_sprite, 80, 102, openborconstant("PANEL_Z") + 2, 1);

    /* Select Player text */

    void select_text_sprite = get(sprites_list, "select_text");

    drawsprite(select_text_sprite, 140, 25, openborconstant("PANEL_Z") + 2, 1);

    /* Columns */

    void select_column_sprite = get(sprites_list, "column");

    drawsprite(select_column_sprite, 0, 0, openborconstant("PANEL_Z") + 2, 1);
    drawsprite(select_column_sprite, 440, 0, openborconstant("PANEL_Z") + 2, 1);

    /* Ground fire loop entity. */
    dc_draw_select_waiting_highlight();
}

/*
* Caskey, Damon V.
* 2021-07-06
* 
* Remove highlight entity from select screen
* if it exists.
*/
void dc_draw_kill_inactive_select_highlight_entity(int player_index)
{
    void acting_entity = getlocalvar(OG_SELECT_SCREEN_HIGHLIGHT_ENTITY_KEY + player_index);

    if (!acting_entity)
    {
        return;
    }

    if (get_entity_property(acting_entity, "exists"))
    {
        killentity(acting_entity);
    }

}

void dc_draw_select_waiting_highlight()
{

    int max_players = openborvariant("maxplayers");
    int player_index = 0;
    void player_select_entity = NULL();
    void select_highlight_entity = NULL();
    void select_highlight_entity_old = NULL();
    int select_highlight_entity_exists = 0;
    float pos_x = 0.0;
    float pos_y = 0.0;
    float pos_z = 0.0;
    int sort_id = 0;

    int entity_count = openborvariant("count_entities");
    int entity_index = 0;
    int entity_cursor = NULL();
    int entity_exists = 0;
    char entity_model_name = "";
    char player_model_name = "";

    // log("\n\n dc_draw_ground_fire_loop_entity");

    /*
    * Before we can spawn the select highlight
    * entity we need to know if a player is
    * active and get some of the properties of
    * their selection entity. 
    * 
    * Unfortunatly The <entity> player property 
    * is not populated during selection screen. 
    * So to get the player#'s select entity, we'll 
    * have to first get the <name> property of 
    * player#. This is the model name player# is 
    * currently highlighting in selection screen.
    * 
    * Next, we loop through the collection of onscreen
    * entities and match the model name to player#'s
    * model name. 
    */

    /*
    * Loop each player index and get the player's 
    * model name.
    */

    for (player_index = 0; player_index < max_players; player_index++)
    {
        player_model_name = getplayerproperty(player_index, "name");

        // log("\n\t player_index: " + player_index);

        /* 
        * If there's no player model name at all
        * this isn't an active player. We'll make
        * sure any existing highlight entity for
        * this player is removed, and then exit.
        */

        if (!player_model_name)
        {
            dc_draw_kill_inactive_select_highlight_entity(player_index);

            continue;
        }

        // log("\n\t player_model_name: " + player_model_name);

        /*
        * We might already have a highlight entity spawned
        * for this player #. If so we can exit now.
        */

        select_highlight_entity_old = getlocalvar(OG_SELECT_SCREEN_HIGHLIGHT_ENTITY_KEY + player_index);

        if (select_highlight_entity_old)
        {
            select_highlight_entity_exists = get_entity_property(select_highlight_entity_old, "exists");

            if (select_highlight_entity_exists)
            {
                continue;
            }
        }                

        /*
        * Loop entity collection, and make sure the 
        * entity in loop iteration is valid before
        * trying to use it.
        */

        for (entity_index = 0; entity_index < entity_count; entity_index++)
        {
            entity_cursor = getentity(entity_index);

            entity_exists = get_entity_property(entity_cursor, "exists");

            // log("\n\t\t entity_index: " + entity_index);
            // log("\n\t\t entity_cursor: " + entity_cursor);
            // log("\n\t\t entity_exists: " + entity_exists);

            if (!entity_exists)
            {
                continue;
            }

            entity_model_name = getentityproperty(entity_cursor, "model");

            // log("\n\t\t entity_model_name: " + entity_model_name);

            /*
            * If the player# and entity model names
            * don't match, then we leave this entity 
            * loop iteration. Otherwise we can move 
            * on to the spawn logic.
            */

            if (entity_model_name != player_model_name)
            {
                continue;
            }

            select_highlight_entity = dc_gauntlet_quick_spawn(OG_SELECT_SCREEN_HIGHLIGHT_MODEL);

            pos_x = get_entity_property(entity_cursor, "position_x");
            pos_y = get_entity_property(entity_cursor, "position_y");
            pos_z = get_entity_property(entity_cursor, "position_z");
            sort_id = get_entity_property(entity_cursor, "sort_id");

            sort_id = sort_id - 5;

            set_entity_property(select_highlight_entity, "position_x", pos_x);
            set_entity_property(select_highlight_entity, "position_y", pos_y);
            set_entity_property(select_highlight_entity, "position_z", pos_z);
            set_entity_property(select_highlight_entity, "sort_id", sort_id);
            
            setlocalvar(OG_SELECT_SCREEN_HIGHLIGHT_ENTITY_KEY + player_index, select_highlight_entity);

            // log("\n\t\t pos_x: " + pos_x);
            // log("\n\t\t pos_y: " + pos_y);
            // log("\n\t\t pos_z: " + pos_z);
            // log("\n\t\t sort_id: " + sort_id);
        }
    }
}

/*
* Caskey, Damon V.
* 2021-07-02
*
* Draw sprites repeated as needed to
* fill width of screen object.
*/
void dc_draw_sprite_to_screen_width(void screen, void sprite, int offset_x, int offset_y)
{
    int screen_width = getgfxproperty(screen, "width");
    int sprite_width = getgfxproperty(sprite, "width");
    int offset_x_final = 0;
    int i = 0;
    int repeats = 2 + screen_width / sprite_width;
       
    /*
    * Get current scroll and increment. Reset
    * once we scroll the length of our sprite
    * to create an endless visual loop.
    */
    int scroll_x = getlocalvar("dc_dstsw_scroll_x" + screen);

    if (!scroll_x)
    {
        scroll_x = 0;
    }

    /* Time to incrment scroll position? */
    dc_eggball_set_instance(screen);
    dc_eggball_set_member_interval(5);

    if (dc_eggball_check_interval())
    {
        if (scroll_x > -sprite_width)
        {
            scroll_x = scroll_x - 1;
        }
        else
        {
            scroll_x = 0;
        }

        /*
        * Add current time and delay to
        * give us the time for for next
        * scroll increment.
        */
        //scroll_time = elapsed_time + scroll_delay;
    }

    setlocalvar("dc_dstsw_scroll_x" + screen, scroll_x);
    //setlocalvar("dc_dstsw_scroll_time" + screen, scroll_time);

    /* Add offset to scroll. */
    offset_x = scroll_x + offset_x;

    for (i = 0; i < repeats; i++)
    {
        offset_x_final = (sprite_width * i);
        offset_x_final = offset_x_final + offset_x;

        drawspritetoscreen(sprite, screen, offset_x_final, offset_y);
    }
}

void dc_get_screen(int index, int size_x, int size_y)
{
    char screen_key;
    char size_x_key;
    char size_y_key;

    char screen_key = "key_screen" + index;

    // Get current screen.
    void screen_list = getlocalvar("dc_mssi_screens");
    void screen = get(screen_list, screen_key);

    //screen = getlocalvar(screen_key);

    // If no screen is set up,
    // initialize it here.
    if (!screen)
    {
        // Allocate screen and use it to populate
        // the screen variable, then populate
        // background variable.
        screen = allocscreen(size_x, size_y);
        
        add(screen_list, screen_key, screen);
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
        name_last = strinfirst(name_full, "_");

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
