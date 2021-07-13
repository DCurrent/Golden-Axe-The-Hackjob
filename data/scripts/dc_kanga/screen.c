#include "data/scripts/dc_kanga/config.h"

/*
* Caskey, Damon V.
* 2021-06-30
*
* Get an existing screen by supplied index.
* If requested screen does not exist, allocate
* new one using supplied index and dimensions.
*/
void dc_kanga_get_screen(int index, int size_x, int size_y)
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