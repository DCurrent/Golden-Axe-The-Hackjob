#include "data/scripts/dc_elmers/main.c"
#include "data/scripts/dc_gauntlet/main.c"
#include "data/scripts/dc_fidelity/main.c"

#include "data/scripts/dc_chain/main.c"

#ifndef DC_TAKEDAMAGE_CONFIG
#define DC_TAKEDAMAGE_CONFIG 1

#define DC_DAMAGE_HP_HIGH 0.75
#define DC_DAMAGE_HP_KO 0.0
#define DC_DAMAGE_HP_LOW 0.25
#define DC_DAMAGE_HP_MAX 1.0

#define DC_DAMAGE_TAKEDAMAGE_BURN_ADDITION			0 
#define DC_DAMAGE_TAKEDAMAGE_BURN_INITIAL			1
#define DC_DAMAGE_TAKEDAMAGE_HP_HIGH				2
#define DC_DAMAGE_TAKEDAMAGE_HP_MAX					4
#define DC_DAMAGE_TAKEDAMAGE_HP_KO					8
#define DC_DAMAGE_TAKEDAMAGE_HP_LOW					16
#define DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_ADDITION		32
#define DC_DAMAGE_TAKEDAMAGE_KNOCKDOWN_INITIAL		64
#define DC_DAMAGE_TAKEDAMAGE_LANDING				128	
#define DC_DAMAGE_TAKEDAMAGE_SHOCK_ADDITION			256
#define DC_DAMAGE_TAKEDAMAGE_SHOCK_INITIAL			512

#endif