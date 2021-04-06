#include "data/scripts/dc_eggball/config.h"

/*
* Caskey, Damon V.
* 2021-04-05
* 
* Accept a time value in seconds and outputs 
* closest value in OpenBOR time.
*/
int dc_eggball_seconds_to_time(int seconds)
{
	return seconds * DC_EGGBALL_GAME_SPEED;
}