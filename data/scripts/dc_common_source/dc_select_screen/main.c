#include    "data/scripts/dc_eggball/main.c"
#include    "data/scripts/dc_gauntlet/main.c"
#include    "data/scripts/dc_kanga/main.c"

#ifndef DC_select_screen_CONFIG
#define DC_select_screen_CONFIG 1

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

void dc_select_screen_initialize()
{
    void sprites_list = array(0);
    
    set(sprites_list, "ceiling", loadsprite("data/bgs/select/ceiling_0.png"));
    set(sprites_list, "column", loadsprite("data/bgs/select/column_0.png"));
    set(sprites_list, "column_far", loadsprite("data/bgs/select/column_far_0.png"));
    set(sprites_list, "floor", loadsprite("data/bgs/select/floor_0.png"));
    set(sprites_list, "select_text", loadsprite("data/bgs/select/text_0.png"));
    set(sprites_list, "skeleton", loadsprite("data/bgs/select/skeleton_0.png"));
    set(sprites_list, "throne", loadsprite("data/bgs/select/throne_0.png"));
    set(sprites_list, "wall", loadsprite("data/bgs/select/wall_0.png"));
    set(sprites_list, "wall_far", loadsprite("data/bgs/select/wall_far_0.png"));

    setlocalvar("dc_mssi_sprites", sprites_list);

    void screens_list = array(0);

    setlocalvar("dc_mssi_screens", screens_list);
}

void dc_select_screen_terminate()
{

    log("\n\n DC Module Select Screen - Freeing resources");

    dc_select_screen_unload_screens();
    dc_select_screen_unload_sprites();

    log("\n ...done. \n");
}

void dc_select_screen_unload_screens()
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

void dc_select_screen_unload_sprites()
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
* Caskey, Damon V.
* 2021-07-08
* 
* Draw the wall background in select screen.
*/
void dc_select_screen_draw_layer(int index, void sprite, int size_x, int size_y, int pos_x, int pos_y, int pos_z, int sprite_offset_x, int sprite_offset_y, int scroll_delay)
{   
    /* 
    * Get the sprite we need by key from an 
    * from array of preloaded select screen
    * sprites.
    */

    void screen = dc_kanga_get_screen(index, size_x, size_y);

    //log("\n sprite: " + sprite);
       
    /* Repeats the sprite enough to fill a screen seamlessly. */
    dc_select_screen_sprite_to_screen_width(screen, sprite, sprite_offset_x, sprite_offset_y, scroll_delay);
  
    /* Draws the screen to player's display. */
    drawscreen(screen, pos_x, pos_y, pos_z);
}

/*
* Caskey, Damon V.
* 2021-07-02
*
* Draw sprites repeated as needed to
* fill width of screen object.
*/
void dc_select_screen_sprite_to_screen_width(void screen, void sprite, int offset_x, int offset_y, int scroll_delay)
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
    dc_eggball_set_member_interval(scroll_delay);

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
    }

    setlocalvar("dc_dstsw_scroll_x" + screen, scroll_x);

    /* Add offset to scroll. */
    offset_x = scroll_x + offset_x;

    clearscreen(screen);

    for (i = 0; i < repeats; i++)
    {
        offset_x_final = (sprite_width * i);
        offset_x_final = offset_x_final + offset_x;

        drawspritetoscreen(sprite, screen, offset_x_final, offset_y);
    }

    //drawspritetoscreen(sprite, screen, offset_x, offset_y);
}

/*
* Caskey, Damon V.
* 2021-07-06
* 
* Controller for drawing layers and animation 
* to build a custom select screen.
* 
* The OpenBOR native select screen is highly 
* optimised at the cost of being mostly hardcoded 
* and very plain looking. We could code our own 
* through model switching in a regular stage, but 
* I'd rather try dressing up the native select
* screen first. :)
*/
void dc_select_screen_main()
{
    /* Not in select screen? Exit now! */
    if (!openborvariant("in_selectscreen"))
    {
        return;
    }

    int index = 0;
    int size_x = 0;
    int size_y = 0;
    int pos_x = 0;
    int pos_y = 0;
    int pos_z = 0;
    int sort_id = 0;
    void sprite = NULL();
    int sprite_offset_x = 0;
    int sprite_offset_y = 0;
    int scroll_delay = 5;

    void sprite_list = getlocalvar("dc_mssi_sprites");
    void common_drawmethod = openborvariant("drawmethod_common");
    void default_drawmethod = openborvariant("drawmethod_default");

    /* Wall (far) */

    index = 0;
    size_x = openborvariant("hresolution");
    size_y = 60;
    pos_x = 0;
    pos_y = 102;
    pos_z = openborconstant("PANEL_Z");
    sprite = get(sprite_list, "wall_far");
    sprite_offset_x = 0;
    sprite_offset_y = 0;
    scroll_delay = 9;

    dc_select_screen_draw_layer(index, sprite, size_x, size_y, pos_x, pos_y, pos_z, sprite_offset_x, sprite_offset_y, scroll_delay);

    /* Columns (far) */

    index = 1;
    size_x = openborvariant("hresolution");
    size_y = 62;
    pos_x = 0;
    pos_y = 102;
    pos_z = openborconstant("PANEL_Z")+1;
    sprite = get(sprite_list, "column_far");
    sprite_offset_x = 0;
    sprite_offset_y = 0;
    scroll_delay = 8;

    set_drawmethod_property(common_drawmethod, "background_transparency", 1);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    dc_select_screen_draw_layer(index, sprite, size_x, size_y, pos_x, pos_y, pos_z, sprite_offset_x, sprite_offset_y, scroll_delay);

    copy_drawmethod(default_drawmethod, common_drawmethod);

    /* Throne */

    index = 2;
    size_x = openborvariant("hresolution");
    size_y = 62;
    pos_x = 0;
    pos_y = 102;
    pos_z = openborconstant("PANEL_Z") + 4;
    sprite = get(sprite_list, "throne");
    sprite_offset_x = 0;
    sprite_offset_y = 0;
    scroll_delay = 7;

    set_drawmethod_property(common_drawmethod, "background_transparency", 1);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    dc_select_screen_draw_layer(index, sprite, size_x, size_y, pos_x, pos_y, pos_z, sprite_offset_x, sprite_offset_y, scroll_delay);

    copy_drawmethod(default_drawmethod, common_drawmethod);

    /* Temple wall. */

    index = 3;
    size_x = openborvariant("hresolution");
    size_y = 94;
    pos_x = 0;
    pos_y = 94;
    pos_z = openborconstant("PANEL_Z") + 5;
    sprite = get(sprite_list, "wall");
    sprite_offset_x = 0;
    sprite_offset_y = 0;
    scroll_delay = 6;

    set_drawmethod_property(common_drawmethod, "background_transparency", 1);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    dc_select_screen_draw_layer(index, sprite, size_x, size_y, pos_x, pos_y, pos_z, sprite_offset_x, sprite_offset_y, scroll_delay);    

    copy_drawmethod(default_drawmethod, common_drawmethod);

    /* Ceiling */        

    index = 4;
    size_x = openborvariant("hresolution") + 240;
    size_y = 102;
    pos_x = -240;
    pos_y = 0;
    pos_z = openborconstant("PANEL_Z") + 3;
    sprite = get(sprite_list, "ceiling");
    sprite_offset_x = 0;
    sprite_offset_y = 0;
    scroll_delay = 8;

    set_drawmethod_property(common_drawmethod, "water_perspective", openborconstant("WATER_PERSPECTIVE_NONE"));
    set_drawmethod_property(common_drawmethod, "water_mode", openborconstant("WATER_MODE_SHEAR"));
    set_drawmethod_property(common_drawmethod, "water_size_begin", 2.0);
    set_drawmethod_property(common_drawmethod, "water_size_end", 1.0);
    set_drawmethod_property(common_drawmethod, "flip_y", 1);
    set_drawmethod_property(common_drawmethod, "enable", 1);

    dc_select_screen_draw_layer(index, sprite, size_x, size_y, pos_x, pos_y, pos_z, sprite_offset_x, sprite_offset_y, scroll_delay);

    copy_drawmethod(default_drawmethod, common_drawmethod);   
    
    /* Floor */

    index = 5;
    size_x = 480;
    size_y = 109;
    pos_x = 0;
    pos_y = 163;
    pos_z = openborconstant("PANEL_Z") + 3;
    sprite = get(sprite_list, "floor");   
    sprite_offset_x = 0;
    sprite_offset_y = 0;
    scroll_delay = 8;
    
    set_drawmethod_property(common_drawmethod, "water_perspective", openborconstant("WATER_PERSPECTIVE_NONE"));
    set_drawmethod_property(common_drawmethod, "water_mode", openborconstant("WATER_MODE_SHEAR"));
    set_drawmethod_property(common_drawmethod, "water_size_begin", 1.0);
    set_drawmethod_property(common_drawmethod, "water_size_end", 2.0);    
    set_drawmethod_property(common_drawmethod, "enable", 1);

    dc_select_screen_draw_layer(index, sprite, size_x, size_y, pos_x, pos_y, pos_z, sprite_offset_x, sprite_offset_y, scroll_delay);

    copy_drawmethod(default_drawmethod, common_drawmethod);

    /* Seleton */

    pos_x = 80;
    pos_y = 102;
    pos_z = openborconstant("PANEL_Z") + 6;
    sprite = get(sprite_list, "skeleton");
    sort_id = 1;
    
    drawsprite(sprite, pos_x, pos_y, pos_z, sort_id);
    
    /* Select Player text */

    pos_x = 140;
    pos_y = 25;
    pos_z = openborconstant("PANEL_Z") + 6;
    sprite = get(sprite_list, "select_text");
    sort_id = 1;

    drawsprite(sprite, pos_x, pos_y, pos_z, sort_id);

    /* Columns */    

    pos_x = 0;
    pos_y = 0;
    pos_z = openborconstant("PANEL_Z") + 6;
    sprite = get(sprite_list, "column");
    sort_id = 1;

    /* -- left */

    drawsprite(sprite, pos_x, pos_y, pos_z, sort_id);
    
    /* -- right */
   
    pos_x = 440;

    drawsprite(sprite, pos_x, pos_y, pos_z, sort_id);

    /* Ground fire loop entity. */
    //dc_select_screen_select_waiting_highlight();

    dc_select_screen_player_control_loop();
}

/*
* Caskey, Damon V.
* 2021-07-06
* 
* Remove highlight entity from select screen
* if it exists.
*/
void dc_select_screen_kill_inactive_select_highlight_entity(int player_index)
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

/*
* check key.
*/
void dc_select_screen_button(int player_index)
{
    int key_press = getplayerproperty(player_index, "newkeys");

    if (key_press & openborconstant("FLAG_ANYBUTTON"))
    {
        log("\n " + key_press);

        changeplayerproperty(player_index, "newkeys", 0);
    }
}

/*
* Caskey, Damon V.
* 2021-07-12
* 
* Loop player collection and run the functions we 
* to act on player index or player entity.
*/
void dc_select_screen_player_control_loop()
{
    int max_players = openborvariant("maxplayers");
    int player_index = 0;
    void player_select_entity = NULL();
    char player_model_name = "";

    for (player_index = 0; player_index < max_players; player_index++)
    {
        player_model_name = getplayerproperty(player_index, "name");

        // log("\n\t player_index: " + player_index);

        /*
        * If there's no player model name at all
        * this isn't an active player. 
        *
        * Run any cleanup functions to get rid of 
        * items we need removed or reset on players
        * that are non-active.
        */

        if (!player_model_name)
        {
            /*
            * Actions we want to run on inactive players only.
            */

            /* Removes player highlight entity. */
            dc_select_screen_kill_inactive_select_highlight_entity(player_index);
        }
        else
        {
            /*
            *Actions we want to run on active players only.
            */

            /*
            * Run actions on player entity. This requires
            * a second loop that matches player model to
            * entity model name.
            */
            dc_select_screen_player_entity_control_loop(player_index, player_model_name);

            /* Kills button. */
            dc_select_screen_button(player_index);            
        }
        /*  */
        
    }
}

/*
* Caskey, Damon V.
* 2021-07-12
*
* Loop player example entities and run the functions
* to act on them. We run this function is run inside
* the player loop. The function then loops all entities
* on screen and compares player model name to the
* entity's model name.
*
* We have to use this nested loop technique to get
* player entities because the player property for
* entity is available outside of gameplay.
*
* It's also important to note this check is not 100%
* accurate, since more than one player may have the
* same model name. Any functions that rely on knowing
* the exact entity a player is using may need to
* record entity vars to ensure accuracy.
*/
void dc_select_screen_player_entity_control_loop(int player_index, char player_model_name)
{
    int entity_count = openborvariant("count_entities");
    int entity_index = 0;
    int entity_cursor = NULL();
    int entity_exists = 0;
    int entity_type = 0;
    char entity_model_name = "";

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

        /* Check type. We only want player entities. */

        entity_type = getentityproperty(entity_cursor, "type");

        // log("\n\t\t entity_type: " + entity_type);

        if (entity_type != openborconstant("TYPE_PLAYER"))
        {
            continue;
        }

        /*
        * If the player# and entity model names
        * don't match, then we leave this entity
        * loop iteration. If they DO match, we
        * found this player index's entity.
        */

        entity_model_name = getentityproperty(entity_cursor, "model");

        // log("\n\t\t entity_model_name: " + entity_model_name);

        if (entity_model_name != player_model_name)
        {
            continue;
        }

        /* Now run player entity actions. */
    
        /* Draws the name text for player's entity. */
        dc_select_screen_draw_name_text(player_index, entity_cursor);

        /*
        * Draws a highlight effect on player's
        * current entity.
        */
        dc_select_screen_select_waiting_highlight(player_index, entity_cursor);
    }
}

/*
* Caskey, Damon V.
* 2021-07-12
* 
* Draw highlights around player's current
* example entity in select screen.
*/
void dc_select_screen_select_waiting_highlight(int player_index, void entity_cursor)
{
    void select_highlight_entity = NULL();
    void select_highlight_entity_old = NULL();
    int select_highlight_entity_exists = 0;
    float pos_x = 0.0;
    float pos_y = 0.0;
    float pos_z = 0.0;
    int sort_id = 0;   
    
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
            return;
        }
    }                

    /*
    * We need to know if the entity we are looking at is
    * a player highlight entity. If we don't make this
    * check, we could double up highlight entities when
    * two players have the same model.
    * 
    * When highlight entities are spawned, we mark them 
    * with the variable we are evaluating here.
    */
    if (getentityvar(entity_cursor, "highlight_entity")==1)
    {
        return;
    }

    /*
    * Spawn the new highlight entity. Then we move it
    * to player entity's position and one step back
    * in the layer order (appears behind player entity).
    */
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

    /* 
    * Mark the highlight entity as a highlight entity.
    * See above for details.
    */
    setentityvar(entity_cursor, "highlight_entity", 1);

    // log("\n\t\t pos_x: " + pos_x);
    // log("\n\t\t pos_y: " + pos_y);
    // log("\n\t\t pos_z: " + pos_z);
    // log("\n\t\t sort_id: " + sort_id);
}

/* 
* Caskey, Damon V.
* 2019-02-22
*
* Draws names of characters during select screen.
*/
void dc_select_screen_draw_name_text(int player_index, int player_entity)
{
    int pos_x = 0;
    int pos_y = 0;
    int screen_width = 0;
    int screen_height = 0;

    /* X base is entity's X location. */
    int entity_pos_x = get_entity_property(player_entity, "position_x");
    int entity_pos_z = get_entity_property(player_entity, "position_z");

    char name_first = "";
    char name_full = getplayerproperty(player_index, "name");
    char name_last = strinfirst(name_full, "_");

    /* 
    * No last name? Then just center 
    * and draw text for first name.
    */
    if (name_last == -1)
    {
        pos_x = dc_center_string_x(entity_pos_x, name_full, WAIT_NAME_FONT);
        pos_y = dc_center_string_y(SELECT_Y_BASE, name_full, FONT_Y);

        screen_width = strwidth(name_full, WAIT_NAME_FONT);
        screen_height = FONT_Y;

        drawstring(pos_x, pos_y, WAIT_NAME_FONT, name_full);
    }
    else
    {
        /* Get a Y center based on two lines (first name, last name). */
        pos_y = dc_center_string_y(SELECT_Y_BASE, name_last, FONT_Y * 2);

        /* Get first name string and center x position. */
        name_first = strleft(name_full, strlength(name_full) - strlength(name_last));
        pos_x = dc_center_string_x(entity_pos_x, name_first, WAIT_NAME_FONT);

        drawstring(pos_x, pos_y, WAIT_NAME_FONT, name_first);
        
        /* Remove sapce character from last name. */
        name_last = strright(name_last, 1);

        pos_x = dc_center_string_x(entity_pos_x, name_last, WAIT_NAME_FONT);

        /* Add vertical font space. */
        pos_y += FONT_Y;

        drawstring(pos_x, pos_y, WAIT_NAME_FONT, name_last);

        screen_width = strwidth(name_first, WAIT_NAME_FONT);
        screen_height = FONT_Y;
    }
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
