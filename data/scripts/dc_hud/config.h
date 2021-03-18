#define VAR_KEY_SPRITE_MAGIC_JAR            "dc_hud_mp_block"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_BLUE    "dc_hud_hp_blue"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_YELLOW  "dc_hud_hp_yellow"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_ORANGE  "dc_hud_hp_orange"
#define VAR_KEY_SPRITE_HEALTH_BLOCK_RED     "dc_hud_hp_red"
#define VAR_KEY_SPRITE_HP_HORIZONTAL_BASE	"dc_hud_hp_horizontal_base"
#define VAR_KEY_SPRITE_PLAYER_ICON_FRAME	"dc_hud_player_icon_frame"
#define VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_0	"dc_hud_bg_p_active_0"
#define VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_1	"dc_hud_bg_p_active_1"
#define VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE_2	"dc_hud_bg_p_active_2"
#define VAR_KEY_SPRITE_BACKGROUND_PLAYER_ACTIVE		"dc_hud_bg_p_active_"	// Used so we can concatenate the index without if/switch statements.

#define DC_HUD_Z openborconstant("FRONTPANEL_Z") + 10000

/* Container for all players' HUDs. */
#define DC_HUD_OUTER_CONTAINER_POS_X		0;
#define DC_HUD_OUTER_CONTAINER_POS_Y		240;

/* Total width of one player's HUD container. */
#define DC_HUD_PLAYER_HUD_SIZE_X				160 

#define MAGIC_BLOCK_MAX         10  // Maximum number of magic blocks.
#define DC_HUD_HP_METER_BLOCK_MAX					5   // Maximum number of health blocks that can be displayed for a single HUD entry.

/* 
* Life/HP meter settings. Block refers to sections of a
* segmented HP meter. 
*/
#define DC_HUD_PLAYER_HP_METER_POS_X				37  
#define DC_HUD_PLAYER_HP_METER_POS_Y				242 
#define DC_HUD_PLAYER_HP_METER_POS_Z				DC_HUD_Z / 2 + 3
#define DC_HUD_PLAYER_HP_METER_OVERLAY_ALPHA_MODE	2
#define DC_HUD_PLAYER_HP_METER_BLOCK_MARGIN_LEFT	1
#define DC_HUD_PLAYER_HP_METER_BLOCK_MARGIN_RIGHT	1
#define DC_HUD_PLAYER_HP_METER_BLOCK_BORDER			1
#define DC_HUD_PLAYER_HP_METER_BLOCK_PADDDING		0

/* 
* Background for individual player's HUD when
* player is active.
*/

#define DC_HUD_BG_PLAYER_ACTIVE_POS_X 2
#define DC_HUD_BG_PLAYER_ACTIVE_POS_Y 240
#define DC_HUD_BG_PLAYER_ACTIVE_POS_Z DC_HUD_Z / 2 + 1

/* 
* Frame around player icon. Positions relative 
* to each player's HUD container.
*/
#define DC_HUD_PLAYER_ICON_FRAME_POS_X	4
#define DC_HUD_PLAYER_ICON_FRAME_POS_Y	241


#define MP_AREA_MARGIN_LEFT     56  // Left of player HUD to first magic block.
#define MP_BLOCK_MARGIN_LEFT    2
#define MP_BLOCK_MARGIN_RIGHT   3

/* Colors used as base overlay for life meter blocks. */
#define DC_HUD_RGB_HP_BLOCK_AMBER_R 150
#define DC_HUD_RGB_HP_BLOCK_AMBER_G 100
#define DC_HUD_RGB_HP_BLOCK_AMBER_B 0

#define DC_HUD_RGB_HP_BLOCK_BLUE_R 0
#define DC_HUD_RGB_HP_BLOCK_BLUE_G 0
#define DC_HUD_RGB_HP_BLOCK_BLUE_B 215

#define DC_HUD_RGB_HP_BLOCK_RED_R 200
#define DC_HUD_RGB_HP_BLOCK_RED_G 0
#define DC_HUD_RGB_HP_BLOCK_RED_B 0

#define DC_HUD_RGB_HP_BLOCK_YELLOW_R 170
#define DC_HUD_RGB_HP_BLOCK_YELLOW_G 170
#define DC_HUD_RGB_HP_BLOCK_YELLOW_B 0

#define DC_HUD_RGB_HP_BLOCK_ADJUST_RANGE 25