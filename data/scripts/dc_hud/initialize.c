#include "data/scripts/dc_hud/config.h"

// Run in the on create event. Preloads
// sprites that will be drawn to HUD.
void dc_preload_hud_sprites()
{
    // Magic jar
    setlocalvar(VAR_KEY_SPRITE_MAGIC_JAR, loadsprite("data/sprites/mpicon.png"));

    /* Player icon frame */
    setlocalvar(VAR_KEY_SPRITE_PLAYER_ICON_FRAME, loadsprite("data/sprites/player_icon_frame.png"));

    // Life blocks
    setlocalvar(VAR_KEY_SPRITE_HP_HORIZONTAL_BASE, loadsprite("data/sprites/hp_horizontal_base.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE, loadsprite("data/sprites/life.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW, loadsprite("data/sprites/life2.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE, loadsprite("data/sprites/life3.png"));
	setlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED, loadsprite("data/sprites/life4.png"));
}

// Run in on destroy event. Removes HUD
// sprites loaded in the on create event.
void dc_unload_hud_sprites()
{
    // Magic jar
    free(getlocalvar(VAR_KEY_SPRITE_MAGIC_JAR));

    /* Player icon frame */
    free(getlocalvar(VAR_KEY_SPRITE_PLAYER_ICON_FRAME));

    // Life blocks
    free(getlocalvar(VAR_KEY_SPRITE_HP_HORIZONTAL_BASE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE));
    free(getlocalvar(VAR_KEY_SPRITE_HEALTH_BLOCK_RED));
}
