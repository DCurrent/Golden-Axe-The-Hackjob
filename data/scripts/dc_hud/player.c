#include "data/scripts/dc_hud/config.h"
#include "data/scripts/dc_spinner/main.c"

#import "data/scripts/dc_hud/block-sprites.c"
#import "data/scripts/dc_hud/health-fraction.c"

/*
* Caskey, Damon V.
* 2021-03-16
* 
* Outputs a compisite color intended for overlay onto
* life meter blocks. Determines a base color from 
* received block fraction value, then varies brightness
* using a sine wave formula.
*/
int dc_hud_life_color(float block_fraction, float sine_value)
{
    int rgb_r = 0;
    int rgb_g = 0;
    int rgb_b = 0;

    /*
    * Use the block fraction provided by parent function
    * to decide which base color to use.
    */
    if (block_fraction >= 0.75)
    {
        rgb_r = RGB_HP_BLOCK_BLUE_R;
        rgb_g = RGB_HP_BLOCK_BLUE_G;
        rgb_b = RGB_HP_BLOCK_BLUE_B;
    }
    else if (block_fraction >= 0.50)
    {
        rgb_r = RGB_HP_BLOCK_YELLOW_R;
        rgb_g = RGB_HP_BLOCK_YELLOW_G;
        rgb_b = RGB_HP_BLOCK_YELLOW_B;
    }
    else if (block_fraction >= 0.25)
    {
        rgb_r = RGB_HP_BLOCK_AMBER_R;
        rgb_g = RGB_HP_BLOCK_AMBER_G;
        rgb_b = RGB_HP_BLOCK_AMBER_B;
    }
    else
    {
        rgb_r = RGB_HP_BLOCK_RED_R;
        rgb_g = RGB_HP_BLOCK_RED_G;
        rgb_b = RGB_HP_BLOCK_RED_B;
    }

    int rbg_composite = 0;
    int rgb_adjustment = RGB_HP_BLOCK_ADJUST_RANGE * sine_value;

    rgb_r += rgb_adjustment;
    rgb_g += rgb_adjustment;
    rgb_b += rgb_adjustment;

    /* Cap color range at 0 - 255.*/
    if (rgb_r > 255) { rgb_r = 255; }
    if (rgb_r < 0) { rgb_r = 0; }
    if (rgb_g > 255) { rgb_g = 255; }
    if (rgb_g < 0) { rgb_g = 0; }
    if (rgb_b > 255) { rgb_b = 255; }
    if (rgb_b < 0) { rgb_b = 0; }

    rbg_composite = rgbcolor(rgb_r, rgb_g, rgb_b);

    return rbg_composite;   
}

/*
* Caskey, Damon V.
* 2021-03-16
* 
* Draws the player icon frame.
*/
void dc_golden_axe_player_hud_icon(int player_index)
{    
    int sprite_index = getlocalvar(VAR_KEY_SPRITE_PLAYER_ICON_FRAME);
    int pos_x = player_index * DC_HUD_PLAYER_HUD_SIZE_X;
    int pos_y = HUD_PLAYER_ICON_FRAME_POS_Y;

    pos_x += HUD_PLAYER_ICON_FRAME_POS_X;

    drawsprite(sprite_index, pos_x, pos_y, openborconstant("FRONTPANEL_Z") + 18001);
}

/*
* Caskey, Damon V.
* 2021-03-17
* 
* Draw player HUD elements when player is 
* joining or continuing a game in progress.
* 
* 
*/
void dc_hud_player_join(int player_index)
{

}

// Draw player HUD, with icons, magic jars, and
// life blocks for the target entity.
void dc_golden_axe_player_hud()
{    

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
    int     block_size_h;           // Size of mp block (after OpenBOR auto trims).
    int     block_space_h;          // Size of mp block with margins included.
    int     block_position_left;    // Starting position of mp blocks in each player's HUD.
    int     block_position_x;       // X position of an individual mp block.
    int     block_position_Y;       // Y position of an individual mp block.

    int hp_horizontal_base = getlocalvar(VAR_KEY_SPRITE_HP_HORIZONTAL_BASE);
    
    /* 
    * Run the spinner function to get a sine 
    * wave adjustment. 
    */

    float sine_value = dc_spinner_sine(4.0, 1);

    // Get and loop through player collection.
    max_players = openborvariant("maxplayers");

    for(player_index=0; player_index<max_players; player_index++)
    {       

        if (player_index == 0)
        {
            settextobj(7, 10, 100, 1, 999999994, "Name: " + getplayerproperty(player_index, "name"));
        }

        // Get target entity for this loop increment.
        target = getplayerproperty(player_index, "entity");

        /*
        * If there's no entity, then check to see if player
        * is joining the game. If they are we want to draw
        * selection HUD. Otherwise just exit - there's
        * nothing else to do.
        */
        if(!target)
        {
            if(getplayerproperty(player_index, "joining"))
            {
                dc_golden_axe_player_hud_icon(player_index);
            }
           
            //settextobj(8, 10, 110, 1, 999999994, " Sine: " + result);

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

        dc_golden_axe_player_hud_icon(player_index);

        resolution_y    = openborvariant("vresolution");
        magic_count     = getentityproperty(target, "mp") / MAGIC_BLOCK_MAX;
        sprite_index    = getlocalvar(VAR_KEY_SPRITE_MAGIC_JAR);

        /* Magic meter. */

        /* We're drawing MP blocks in a row, so Y position
        * is always the same.
        */
        block_position_Y = resolution_y-20;

        /* 
        * X position will depend on several factors. Some
        * we can do here, and the rest will need to be
        * in a loop.
        *
        * Let's get the width of our meter block.
        * Remember that OpenBOR auto trims all sprites
        * as it loads them, so the size will reflect that.
        */
        block_size_h = getgfxproperty(sprite_index, "srcwidth");

        /* 
        * Now we add the block's margins, and that will get
        * total spacing for one block.
        */
        block_space_h = block_size_h + MP_BLOCK_MARGIN_LEFT + MP_BLOCK_MARGIN_RIGHT;

        /* 
        * Our starting position will be the leftmost of
        * current player's (in loop) HUD area. To get this,
        * we multiply current player index by total X size of
        * the player HUD.
        */
        block_position_left = player_index * DC_HUD_PLAYER_HUD_SIZE_X;

        /* 
        * Add the meter area's left margin to space it
        * out from the start of player HUD area.
        */
        block_position_left += MP_AREA_MARGIN_LEFT;

        for(i=0; i<magic_count; i++)
        {
            /* 
            * Multiply the total X space of a block
            * by the current cursor position. This places
            * each block in a row, left to right.
            * block_position_x = i * block_space;
            *
            * Now add the margin from player HUD to start
            * of block area to align blocks properly with
            * player HUD design.
            */
            block_position_x += block_position_left;

            /* Draw the MP sprite. */
            //drawsprite(sprite_index, block_position_x, block_position_Y, openborconstant("FRONTPANEL_Z")+18001);
        }

        /*
        * Health Meter
        * 
        * Positioning works identically to MP meter. but health meter 
        * also includes a color keying capability.
        * 
        * Our goal here is to replicate the arcade Golden Axe life meter, 
        * while combining the features from arcade Altered Beast life meter.
        * 
        * In arcade GA, life is represented by a small number of blocks that 
        * cycle continuously between daker and lighter blue while on screen. 
        * 
        * Altered Beast (a previous game by same developer) uses a very similar 
        * system of blocks for its HP meter. Altered Beast's meter lacks the 
        * shading cycle effect, but as HP depletes, the right most block changes 
        * color (blue->yellow->red) until that block's portion of health fully 
        * depletes and the block disappears.
        * 
        * -- Color Keying (Altered beast block colors) --
        *         
        * To add the color keying to right most block, we need to go through 
        * a few steps.
        * 
        * First we get a decimal value of current remaining health and mutiply 
        * it by the number of blocks we'd draw if health was at max. For example, 
        * if health is currently 80 of a max 100 then we get a value of 0.8.
        * 
        * Next, we multiply the decimal value of 0.8 by the number of blocks we
        * display at max health (in this example, four). This gives us a value 
        * of 3.2. Just for labeling, we call it Health Fraction.
        * 
        * Now we run a loop, with the cursor incrementing by 1 and stopping when 
        * the cursor > our Health Fraction. Inside the loop, we subtract the current 
        * cursor value from Health Fraction value to get a value we'll call Block 
        * Percentage.
        * 
        * The loop is essentially getting a sub percentage value of for each block. 
        * We then feed that to a function that will determine which color of block 
        * to display. In our example, the first three blocks will get a value that
        * is > 1. So they get the 100% block. The forth block ends up with a value 
        * of 0.2. That means the block's portion of HP is at 20% and the block color
        * select function will choose accordingly.  
        * 
        * In our example, this is what the loop looks like:
        * 
        * # of blocks at max health: 4
        * Max health: 100
        * Current health: 80
        * 4 * (80 / 100) = 3.2
        * 
        * *loop starts*
        * 
        * 3.2 - 0 = 3.2: Block 1 - 100%
        * 3.2 - 1 = 2.2: Block 2 - 100%
        * 3.2 - 2 = 1.2: Block 3 - 100%
        * 3.2 - 3 = 0.2: Block 4 - 20%
        * 
        * *Loop stops, four blocks are displayed*
        * 
        * If health drops to 35, it would then look like this:
        * 
        * Health: 35 of 100
        * 4 * (80 / 100) = 1.4
        * 
        * *loop starts*
        * 
        * 1.4 - 0 = 1.4: Block 1 - 100%
        * 1.4 - 1 = 0.4: Block 2 - 40%
        * 
        * Loop stops, two blocks are displayed.
        */

        /* Get health %, multiplied by number of displayable blocks. */
        health_fraction = DC_HUD_HP_METER_BLOCK_MAX * get_health_fraction(target);

        /* Get Y position. */
        block_position_Y = DC_HUD_PLAYER_HP_METER_POS_Y;

        #define DC_HUD_PLAYER_HP_METER_BLOCK_MARGIN_LEFT 1
        #define DC_HUD_PLAYER_HP_METER_BLOCK_MARGIN_RIGHT 1
       
        /*
        * Positioning works same way as MP meter, but
        * all initial math work has to be in loop since
        * we don't know until in side the loop which
        * sprite is in use.
        */
        block_size_h = getgfxproperty(hp_horizontal_base, "srcwidth");

        /*
        * Now we add the block margins, and that will get
        * total space for one block.
        */
        block_space_h = block_size_h + DC_HUD_PLAYER_HP_METER_BLOCK_MARGIN_LEFT + DC_HUD_PLAYER_HP_METER_BLOCK_MARGIN_RIGHT;

        /*
        * Our starting position will be the leftmost of
        * current player's (in loop) HUD area, plus the
        * health specific margin.
        */
        block_position_left = player_index * DC_HUD_PLAYER_HUD_SIZE_X;
        block_position_left += DC_HUD_PLAYER_HP_METER_POS_X;

        /* Loop over each whole portion of health_fraction. */
        
        for(i=0; i < health_fraction; i++)
        {
            /* 
            * This gives us the fraction for current
            * block (in loop) we want to draw. 
            */
            block_fraction = health_fraction - i;

            /* 
            * Multiply the total X space of a block
            * by the current cursor position. This places
            * each block in a row, left to right.
            */
            block_position_x = i * block_space_h;

            /* 
            * Now add the starting position.
            */
            block_position_x += block_position_left;

            drawsprite(hp_horizontal_base, block_position_x, block_position_Y, openborconstant("FRONTPANEL_Z")+18001);

            drawbox(block_position_x + 1, block_position_Y + 1, 20, 6, openborconstant("FRONTPANEL_Z") + 18002, dc_hud_life_color(block_fraction, sine_value), 2);
        }
    }
}
