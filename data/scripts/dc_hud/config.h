#define VAR_KEY_SPRITE_MAGIC_JAR            "dc_hud_mp_block"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE    "dc_hud_hp_blue"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW  "dc_hud_hp_yellow"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE  "dc_hud_hp_orange"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_RED     "dc_hud_hp_red"
#define VAR_KEY_SPRITE_HP_HORIZONTAL_BASE	"dc_hud_hp_horizontal_base"
#define VAR_KEY_SPRITE_PLAYER_ICON_FRAME	"dc_hud_player_icon_frame"

/* Container for all players' HUDs. */
#define HUD_OUTER_CONTAINER_POS_X		0;
#define HUD_OUTER_CONTAINER_POS_Y		240;

/* Total width of one player's HUD container. */
#define PLAYER_HUD_WIDTH				160 

#define HEALTH_BLOCK_MAX        4   // Maximum number of health blocks that can be displayed for a single HUD entry.
#define MAGIC_BLOCK_MAX         10  // Maximum number of magic blocks.
#define HP_AREA_MARGIN_LEFT     53  // Left of player HUD to life meter.

/* 
* Frame around player icon. Positions relative 
* to each player's HUD container.
*/
#define HUD_PLAYER_ICON_FRAME_POS_X	4
#define HUD_PLAYER_ICON_FRAME_POS_Y	241


#define MP_AREA_MARGIN_LEFT     56  // Left of player HUD to first magic block.
#define MP_BLOCK_MARGIN_LEFT    2
#define MP_BLOCK_MARGIN_RIGHT   3

#define RGB_HP_BLOCK_AMBER_R 150
#define RGB_HP_BLOCK_AMBER_G 100
#define RGB_HP_BLOCK_AMBER_B 0

#define RGB_HP_BLOCK_BLUE_R 0
#define RGB_HP_BLOCK_BLUE_G 0
#define RGB_HP_BLOCK_BLUE_B 215

#define RGB_HP_BLOCK_RED_R 200
#define RGB_HP_BLOCK_RED_G 0
#define RGB_HP_BLOCK_RED_B 0

#define RGB_HP_BLOCK_YELLOW_R 170
#define RGB_HP_BLOCK_YELLOW_G 170
#define RGB_HP_BLOCK_YELLOW_B 0

#define RGB_HP_BLOCK_ADJUST_RANGE 25