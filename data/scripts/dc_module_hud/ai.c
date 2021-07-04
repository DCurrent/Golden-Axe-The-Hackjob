#include "data/scripts/dc_module_hud/config.h"

#import "data/scripts/dc_module_hud/block-sprites.c"
#import "data/scripts/dc_module_hud/health-fraction.c"
#import "data/scripts/dc_module_hud/is-hurt.c"

// Draw enemy icons and life in a row across screen.
void dc_golden_axe_enemy_hud()
{
    #define POS_Z       openborconstant("FRONTPANEL_Z")+18000   // Layer position on screen.
    #define POS_ICON_Y  4
    #define POS_LIFE_Y  8
    #define HUD_WIDTH   41                                      // Total X size of a single HUD item (icon + life + padding)
    #define ICON_WIDTH  16                                      // Total X size of HUD icon (icon + padding).
    #define	ANI_ICONS   openborconstant("ANI_FOLLOW100")        // Animation that is used for an icons placeholder.
    #define ICON_AI		0                                       // Frame holding icon for AI.
    #define ICON_AIPAIN	1                                       // Frame holding pain icon for AI.

    int     i;                  // Loop cursor.
    void    target;             // Target entity.
    int     row_cursor;         // Position in row.
    int     entity_count;       // Number of entities in play.
    int     entity_type;        // PLayer, enemy, npc, etc..
    int     exists;             // Entity exists flag.
    int     dead;               // Entity dead flag.
    int     is_hurt;            // Is in a pain, falling, or grappled state?
    int     icon_x;             // X position for icon.
    int     life_x;             // X position for life.
    float   health_fraction;    // Decimal percentage of remaining HP.
    void    sprite;             // Sprite pointer.
    void    dm_table;           // Drawmethod color table pointer.
    int     dm_tint_mode;       // Drawmethod tint mode.
    int     dm_tint_color;      // Drawmethod tint color.
    void    dm_old_table;       // Original drawmethod color table pointer.
    int     dm_old_tint_mode;   // Original drawmethod tint mode.
    int     dm_old_tint_color;  // Original Drawmethod tint color.


    // Get a fresh count of entities and
    // initialize row cursor.
    row_cursor      = 0;
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

        // We're targeting enemy types.
        entity_type = getentityproperty(target, "type");

        if(entity_type != openborconstant("TYPE_ENEMY"))
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

        // Target getting whipped? If so get a "hurt" icon sprite.
        // Otherwise just get a normal icon sprite.
        is_hurt = dc_get_is_hurt(target);

        if(is_hurt)
        {
            sprite = getentityproperty(target, "icon", "pain");
            //sprite = getentityproperty(target, "spritea", "sprite", ANI_ICONS, ICON_AIPAIN);
        }
        else
        {
            sprite = getentityproperty(target, "icon", "default");
            //sprite = getentityproperty(target, "spritea", "sprite", ANI_ICONS, ICON_AI);
        }

        // Did we find a valid icon sprite? Then let's display it along with
        // a health sprite.
        if(sprite != -1)
        {
            // To get the position, we use a preset value that is equal
            // to the icon, life block, and any extra margin padding.
            // We then multiply that value by the current row cursor.
            // When there are multiple enemy entities on screen, this
            // causes their icons and life blocks to appear in a row
            // across the screen.

            icon_x = row_cursor * HUD_WIDTH;
            life_x = icon_x + ICON_WIDTH;

            // We'll want to put the global drawmethods back
            // like we found them, so let's get the current
            // values here.
            dm_old_table        = getdrawmethod(NULL(), "table");
            dm_old_tint_color   = getdrawmethod(NULL(), "tintmode");
            dm_old_tint_mode    = getdrawmethod(NULL(), "tintcolor");

            // Now we'll get the color table and drawmethods used
            // by target.
            dm_table        = getentityproperty(target, "colourmap");
            dm_tint_color   = getdrawmethod(target, "tintcolor");
            dm_tint_mode    = getdrawmethod(target, "tintmode");

            // Apply the drawmethods from or target to the global
            // drawmethod, and then draw the icon sprite. As long
            // as the icon sprite's original color table is the
            // same as the target's sprite set color table, the
            // icon will color match target perfectly.
            changedrawmethod(NULL(), "table", dm_table);
            changedrawmethod(NULL(), "tintmode", dm_tint_mode);
            changedrawmethod(NULL(), "tintcolor", dm_tint_color);

            drawsprite(sprite, icon_x, POS_ICON_Y, POS_Z);

            // Now restore the global drawmethods to their
            // previous values. Things would look pretty
            // messy if we let everything on the screen
            // use values from our target!
            changedrawmethod(NULL(), "table", dm_old_table);
            changedrawmethod(NULL(), "tintmode", dm_old_tint_mode);
            changedrawmethod(NULL(), "tintcolor", dm_old_tint_color);

            // Get and draw the appropriate life block sprite
            // for health remaining. We'll first get a fraction
            // and then use that to choose an appropriate
            // colored block to display.
            health_fraction = get_health_fraction(target);

            sprite   = dc_get_block_large(health_fraction);
            drawsprite(sprite, life_x, POS_LIFE_Y, POS_Z);

            // Increment the row cursor for next
            // drawing iteration.
            row_cursor++;
        }
    }

    // Clean up our macros.
    #undef POS_Z
    #undef POS_ICON_Y
    #undef POS_LIFE_Y
    #undef HUD_WIDTH
    #undef ICON_WIDTH
    #undef ANI_ICONS
    #undef ICON_AI
    #undef ICON_AIPAIN

}
