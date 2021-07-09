#include "data/scripts/dc_common_source/dc_hud/config.h"

// Run in the on create event. Preloads
// sprites that will be drawn to HUD.
void dc_preload_hud_sprites()
{
    // Magic jar
    setlocalvar(VAR_KEY_SPRITE_MAGIC_JAR, loadsprite("data/sprites/hud/mpicon.png"));

    /* Player icon frame */
    setlocalvar(VAR_KEY_SPRITE_PLAYER_ICON_FRAME, loadsprite("data/sprites/hud/player_icon_frame_0.png"));

    /* Life meter */
    setlocalvar(VAR_KEY_SPRITE_HP_HORIZONTAL_BASE, loadsprite("data/sprites/hud/hp_horizontal_0.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE, loadsprite("data/sprites/hud/life.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW, loadsprite("data/sprites/hud/life2.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE, loadsprite("data/sprites/hud/life3.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED, loadsprite("data/sprites/hud/life4.png"));

    /* Player HUD backgrounds when active. */
    setlocalvar(VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_0, loadsprite("data/sprites/hud/background_player_active_0.png"));
    setlocalvar(VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_1, loadsprite("data/sprites/hud/background_player_active_1.png"));
    setlocalvar(VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_2, loadsprite("data/sprites/hud/background_player_active_2.png"));

}

// Run in on destroy event. Removes HUD
// sprites loaded in the on create event.
void dc_unload_hud_sprites()
{
    // Magic jar
    free(getlocalvar(VAR_KEY_SPRITE_MAGIC_JAR));

    /* Player icon frame */
    free(getlocalvar(VAR_KEY_SPRITE_PLAYER_ICON_FRAME));

    /* Life meter */
    free(getlocalvar(VAR_KEY_SPRITE_HP_HORIZONTAL_BASE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED));

    /* Player HUD backgrounds when active. */
    free(getlocalvar(VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_0));
    free(getlocalvar(VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_1));
    free(getlocalvar(VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_2));
}
